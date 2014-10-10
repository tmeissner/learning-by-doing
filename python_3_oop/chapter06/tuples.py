import datetime


def middle(stock, date):

    symbol, current, high, low = stock
    return ((high + low) / 2), date


tuple = ("GOOG", 613.30, 625.86, 610.50)
mid_value, date = middle(tuple, datetime.datetime.now())
print("middle value: {} at date {}".format(mid_value, date))
print("high value: {}".format(tuple[2]))
print(tuple[1:3])