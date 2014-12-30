from collections import KeysView, ItemsView, ValuesView


class SillyInt(int):

    def __add__(self, num):
        return 0


a = SillyInt(1)
b = SillyInt(2)
print("{} + {} = {}".format(a, b, a+b))


class DictSorted(dict):

    def __new__(*args, **kwargs):
        new_dict = dict.__new__(*args, **kwargs)
        new_dict.ordered_keys = []
        return new_dict

    def __setitem__(self, key, value):
        """self[key] = value syntax"""
        if key not in self.ordered_keys:
            self.ordered_keys.append(key)
        super().__setitem__(key, value)

    def setdefault(self, key, value):
        if key not in self.ordered_keys:
            self.ordered_keys.append(key)
        return super().setdefault(key, value)

    def keys(self):
        return KeysView(self)

    def values(self):
        return ValuesView(self)

    def items(self):
        return ItemsView(self)

    def __iter__(self):
        """for x in self syntax"""
        return self.ordered_keys.__iter__()