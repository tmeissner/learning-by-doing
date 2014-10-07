class Document:

    def __init__(self, filename):
        self.characters = []
        self.cursor = Cursor(self)
        if len(filename) == 0:
            raise FileNameInvalid("Invalid filename")
        else:
            self.filename = filename

    def insert(self, character):
        if not hasattr(character, 'character'):
            character = Character(character)
        self.characters.insert(self.cursor.position, character)
        self.cursor.forward()

    def delete(self):
        try:
            del self.characters[self.cursor.position]
        except IndexError:
            print("No character to delete")

    def save(self):
        try:
            f = open(self.filename, "w")
            f.write(self.string)
            f.close()
        except IOError:
            print("Could not safe file")

    @property
    def string(self):
        return "".join((str(c) for c in self.characters))


class Cursor:

    def __init__(self, document):
        self.document = document
        self.position = 0

    def forward(self):
        if self.position < len(self.document.characters):
            self.position += 1

    def back(self):
        if self.position > 0:
            self.position -= 1

    def home(self):
        while self.document.characters[self.position - 1].character != "\n":
            self.back()
            if self.position == 0:
                # got to beginning of file before newline
                break

    def end(self):
        while (self.position < len(self.document.characters) and
               self.document.characters[self.position].character != "\n"):
            self.forward()


class Character:

    def __init__(self, character, bold=False, italic=False, underline=False):
        if len(character) != 1:
            raise CharacterLength("Please insert a single character")
        self.character = character
        self.bold = bold
        self.italic = italic
        self.underline = underline

    def __str__(self):
        bold = "*" if self.bold else ''
        italic = "/" if self.italic else ''
        underline = "_" if self.underline else ''
        return bold + italic + underline + self.character


class FileNameInvalid(Exception):
    pass


class CharacterLength(Exception):
    pass