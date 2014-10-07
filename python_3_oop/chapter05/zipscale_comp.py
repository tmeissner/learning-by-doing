from zipprocessor import ZipProcessorComp
import sys
import os
from pygame import image
from pygame.transform import scale


class ZipScale():

    def process(self, zipprocessor):
        """Scale each image in the directory to 640x480"""
        for filename in os.listdir(zipprocessor.temp_directory):
            im = image.load(zipprocessor._full_filename(filename))
            scaled = scale(im, (640, 480))
            image.save(scaled, zipprocessor._full_filename(filename))


if __name__ == "__main__":
    ZipProcessorComp(sys.argv[1], ZipScale()).process_zip()
