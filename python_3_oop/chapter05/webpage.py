from urllib.request import urlopen
import time


class WebPage:

    def __init__(self, url):
        self.url = url
        self.an_old_time = 0
        self._content = None

    @property
    def content(self):
        now = time.time()
        if not self._content or (now - self.an_old_time > 10):
            self.an_old_time = now
            print("Retrieving new page...")
            self._content = urlopen(self.url).read()
        print("Got page in {} seconds".format(time.time() - now))
        return self._content
