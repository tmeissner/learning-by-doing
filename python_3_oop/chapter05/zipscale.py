from zipprocessor import ZipProcessorInh
import sys
import os
from pygame import image
from pygame.transform import scale


class ZipScale(ZipProcessorInh):

    def process_files(self):
        """Scale each image in the directory to 640x480"""
        for filename in os.listdir(self.temp_directory):
            im = image.load(self._full_filename(filename))
            scaled = scale(im, (640, 480))
            image.save(scaled, self._full_filename(filename))


if __name__ == "__main__":
    ZipScale(*sys.argv[1:2]).process_zip()