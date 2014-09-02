# duck typing example taken from wikipedia
# https://de.wikipedia.org/wiki/Duck-Typing


class Bird:
    "Birds have a name that they return in string represention"

    def __init__(self, name):
        self.name = name

    def __str__(self):
        return self.__class__.__name__+' '+self.name


class Duck(Bird):
    "Ducks are birds which can quak"

    def quak(self):
        print(str(self)+': quak')


class Frog:
    "Frogs also can quak"
    def quak(self):
        print(str(self)+': quak')


def main():

    ducks = [Bird('Gustav'), Duck('Donald'), object()]
    for duck in ducks:
        # exception handling when object hasn't quak method
        try:
            duck.quak()
        except AttributeError:
            print('No duck:', duck)

    ducks.append(Frog())
    for duck in ducks:
        # we also can use hasattr() function instead of exception handling
        if hasattr(duck, 'quak'):
            duck.quak()
        else:
            print('No duck:', duck)


if __name__ == "__main__":
    main()
