# python modules
import sys
import pickle
import base64
import getpass
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
            "7": self.quit
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
7. Quit """)

    def run(self):
        '''Display the menu and respond to choices.'''
        while True:
            self.display_menu()
            choice = input("Enter an option: ")
            action = self.choices.get(choice)
            if action:
                action()
            else:
                print("{0} is not a valid choice".format(choice))

    def show_notes(self, notes=None):
        if not notes:
            notes = self.notebook.notes
        for note in notes:
            print("{0}: {1}\n{2}".format(note.id, note.tags, note.memo))

    def search_notes(self):
        filter = input("Search for: ")
        notes = self.notebook.search(filter)
        self.show_notes(notes)

    def add_note(self):
        memo = input("Enter a memo: ")
        self.notebook.new_note(memo)
        print("Your note has been added.")

    def modify_note(self):
        id = input("Enter a note id: ")
        memo = input("Enter a memo: ")
        tags = input("Enter tags: ")
        if memo:
            if not self.notebook.modify_memo(id, memo):
                print("Note with id {0} doesn't exist.".format(id))
        if tags:
            if not self.notebook.modify_tags(id, tags):
                print("Note with id {0} doesn't exist.".format(id))

    def load_notes(self):
        try:
            f = open(self.savefile, 'rb')
        except IOError:
            print("Could not open file")
        else:
            cipher = f.read()
            f.close()
            crypt = Fernet(self._get_password())
            try:
                plain = crypt.decrypt(cipher)
            except InvalidToken:
                print("Wrong password")
            else:
                self.notebook = pickle.loads(plain)

    def save_notes(self):
        plain = pickle.dumps(self.notebook, pickle.HIGHEST_PROTOCOL)
        crypt = Fernet(self._get_password())
        cipher = crypt.encrypt(plain)
        try:
            f = open(self.savefile, 'wb')
        except IOError:
            print("Could not open file")
        else:
            f.write(cipher)
            f.close()

    def _get_password(self):
        passphrase = getpass.getpass()
        kdf = PBKDF2HMAC(
            algorithm = hashes.SHA256(),
            length = 32,
            salt = self.salt.encode('utf-8'),
            iterations = 1000,
            backend = default_backend()
        )
        return base64.urlsafe_b64encode(kdf.derive(passphrase.encode('utf-8')))

    def quit(self):
        print("Thank you for using your notebook today.")
        sys.exit(0)



if __name__ == "__main__":
    Menu().run()
