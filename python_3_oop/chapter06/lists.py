import string


# list with all valid characters
CHARACTERS = list(string.ascii_letters) + [" ", ",", "'", "?", "Ä", "ö"]


def letter_frequency(sentence):
    # init a list of tuples for all valid characters
    frequencies = [(c, 0) for c in CHARACTERS]
    for letter in sentence:
        # find index of selected character
        index = CHARACTERS.index(letter)
        # increment counter of selected character
        frequencies[index] = (letter, frequencies[index][1] + 1)
    return frequencies

print(letter_frequency("Hello world, what's going on? Äötsch"))


# sorting self constructed classes by overriding their __lt__ method

class WeirdSortee:
    def __init__(self, string, number, sort_num):
        self.string = string
        self.number = number
        self.sort_num = sort_num

    def __lt__(self, object):
        if self.sort_num:
            return self.number < object.number
        return self.string < object.string

    def __repr__(self):
        return "{}:{}".format(self.string, self.number)


a = WeirdSortee('a', 4, True)
b = WeirdSortee('b', 3, True)
c = WeirdSortee('c', 2, True)
d = WeirdSortee('d', 1, True)
l = [a, d, c, b]
print(str(l) + " unsorted")
l.sort()
print(str(l) + " sorted by number")
for i in l:
    i.sort_num = False
l.sort()
print(str(l) + " sorted by character")


# using the 'key' argument of the sort() method
x = [(1, 'c'), (2, 'a'), (3, 'b')]
x.sort()
print(str(x) + " sorted by 1st item")
x.sort(key=lambda i: i[1])
print(str(x) + " sorted by 2nd item")