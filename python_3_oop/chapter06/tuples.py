import datetime
from collections import namedtuple


def middle(stock, date):

    symbol, current, high, low = stock
    return ((high + low) / 2), date


tuple = ("GOOG", 613.30, 625.86, 610.50)
mid_value, date = middle(tuple, datetime.datetime.now())
print("middle value: {} at date {}".format(mid_value, date))
print("high value: {}".format(tuple[2]))
print(tuple[1:3])


# named tuples
Stock = namedtuple("Stock", "symbol current high low")
stock = Stock("GOOG", 613.30, high=625.86, low=610.50)
print("{}: current={}, high={}, low={}".format(stock.symbol, stock.current,
                                               stock.high, stock.low))
