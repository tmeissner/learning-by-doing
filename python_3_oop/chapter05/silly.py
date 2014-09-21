#class Silly:
#
#    def _get_silly(self):
#        print("You're getting silly")
#        return self._silly
#
#    def _set_silly(self, value):
#        print("You're making silly {}".format(value))
#        self._silly = value
#
#    def _del_silly(self):
#        print("Whoa, you're killing silly!")
#        del self._silly
#
#    silly = property(_get_silly, _set_silly, _del_silly,
#        "This is a silly property")


# same as before but with decorators:

class Silly:

    @property
    def silly(self):
        "This is a silly property"
        print("You're getting silly")
        return self._silly

    @silly.setter
    def silly(self, value):
        print("You're making silly {}".format(value))
        self._silly = value

    @silly.deleter
    def silly(self):
        print("Whoa, you're killing silly!")
        del self._silly
