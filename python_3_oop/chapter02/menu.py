# python modules
import sys
import pickle
import base64
import getpass
import gzip
# own modules
from notebook import Notebook, Note
# cryptography module
from cryptography.fernet import Fernet, InvalidToken
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC
from cryptography.hazmat.backends import default_backend



class Menu:
    '''Display a menu and respond to choices when run.'''

    def __init__(self):
        self.salt = "a683c64de226677703f56e6b6ead94bbc3690ec5293c3de3ffdc"
        self.savefile = 'notebook.safe'
        self.notebook = Notebook()
        self.choices = {
            "1": self.show_notes,
            "2": self.search_notes,
            "3": self.add_note,
            "4": self.modify_note,
            "5": self.load_notes,
            "6": self.save_notes,
            "7": self.__init__,
            "8": self.quit
        }

    def display_menu(self):
        print("""
Notebook Menu
1. Show all Notes
2. Search Notes
3. Add Note
4. Modify Note
5. Load Notes
6. Save Notes
7. Reset Notes
8. Quit """)

    def run(self):
        '''Display the menu and respond to choices.'''
        while True:
            self.display_menu()
            choice = input("Enter an option: ")
            action = self.choices.get(choice)
            try:
                action()
            except TypeError:
                print("{0} is not a valid choice".format(choice))

    def show_notes(self, notes=None):
        '''Display all notes stored in notebook object'''
        if not notes:
            notes = self.notebook.notes
        for note in notes:
            print("{0}: {1}\n{2}".format(note.id, note.tags, note.memo))

    def search_notes(self):
        '''Search for a note containing given string'''
        filter = input("Search for: ")
        notes = self.notebook.search(filter)
        self.show_notes(notes)

    def add_note(self):
        '''Add a given not to notebook object'''
        memo = input("Enter a memo: ")
        self.notebook.new_note(memo)
        print("Your note has been added.")

    def modify_note(self):
        '''Modify tag and memo of note with given id'''
        id = input("Enter a note id: ")
        memo = input("Enter a memo: ")
        tags = input("Enter tags: ")
        if memo:
            if not self.notebook.modify_memo(id, memo):
                print("Note with id {0} doesn't exist.".format(id))
                return
        if tags:
            if not self.notebook.modify_tags(id, tags):
                print("Note with id {0} doesn't exist.".format(id))

    def load_notes(self):
        '''Decrypt notebook safe file and load it into notebook object'''
        try:
            f = open(self.savefile, 'rb')
        except IOError:
            print("Could not open file")
        else:
            cipher = f.read()
            f.close()
            notebook = self._decode_notefile(cipher)
            if notebook:
                self.notebook = notebook
                self.notebook._set_id()

    def save_notes(self):
        '''Encrypt notebook object and store it into notebook safe file'''
        cipher = self._encode_notefile()
        try:
            f = open(self.savefile, 'wb')
        except IOError:
            print("Could not open file")
        else:
            f.write(cipher)
            f.close()

    def _decode_notefile(self, cipher):
        crypt = Fernet(self._get_password())
        try:
            plain = crypt.decrypt(cipher)
        except InvalidToken:
            print("Wrong password")
        else:
            try:
                plain = gzip.decompress(plain)
            except OSError:
                print("File not valid")
            else:
                return pickle.loads(plain)

    def _encode_notefile(self):
        plain = pickle.dumps(self.notebook, pickle.HIGHEST_PROTOCOL)
        crypt = Fernet(self._get_password())
        plain = gzip.compress(plain)
        return crypt.encrypt(plain)

    def _get_password(self):
        '''Request passphrase and derive key from it'''
        passphrase = getpass.getpass()
        kdf = PBKDF2HMAC(
            algorithm = hashes.SHA256(),
            length = 32,
            salt = self.salt.encode('utf-8'),
            iterations = 10000,
            backend = default_backend()
        )
        return base64.urlsafe_b64encode(kdf.derive(passphrase.encode('utf-8')))

    def quit(self):
        '''Quit application'''
        print("Thank you for using your notebook today.")
        sys.exit(0)



if __name__ == "__main__":
    Menu().run()
