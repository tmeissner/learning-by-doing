from collections import defaultdict


stocks = {"GOOG": (613.30, 625.86, 610.50),
          "MSFT": (30.25, 30.70, 30.19)}

# different possibilities to get values from the dictionary
print("GOOG: {}".format(stocks["GOOG"]))
print("RIM: {}".format(stocks.get("RIM", "NOT FOUND")))
stocks.setdefault("RIM", (67.38, 68.48, 67.28))
print("RIM: {}".format(stocks["RIM"]))

for stock, values in stocks.items():
    print("{} last value is {}".format(stock, values[0]))

random_keys = {}
random_keys["astring"] = "somestring"
random_keys[5] = "aninteger"
random_keys[25.2] = "floats work too"
random_keys[("abc", 123)] = "so do tuples"


class AnObject(object):

    def __init__(self, avalue):
        self.avalue = avalue


my_object = AnObject(14)
random_keys[my_object] = "We can even store objects"
my_object.avalue = 12

try:
    random_keys[[1, 2, 3]] = "We can't store lists though"
except:
    print("unable to store list \n")

for key, value in random_keys.items():
    print("{} has value {}".format(key, value))
    if hasattr(key, "avalue"):
        print("{}.avalue ={}".format(key, key.avalue))


def letter_frequency(sentence):
    frequencies = {}
    for letter in sentence:
        frequency = frequencies.setdefault(letter, 0)
        frequencies[letter] = frequency + 1
    return frequencies

print(letter_frequency("Hello world, what's going on?"))


# defaultdict using built-in function
def letter_frequency_defdict(sentence):
    frequencies = defaultdict(int)
    for letter in sentence:
        frequencies[letter] += 1
    return frequencies

print(letter_frequency_defdict("Hello world, what's going on?"))


# defaultdict using self defined function
num_items = 0


def tuple_counter():
    global num_items
    num_items += 1
    return num_items, []

d = defaultdict(tuple_counter)

d['a'][1].append("hello")
d['b'][1].append("world")

print(d)