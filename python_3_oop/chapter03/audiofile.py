# small example for inhiterance with polymorphism

class AudioFile:

    def __init__(self, filename):
        if not filename.endswith(self.ext):
            raise Exception("Invalid file format")
        self.filename = filename


class MP3File(AudioFile):

    ext = "mp3"

    def play(self):
        print("Playing {} as mp3".format(self.filename))


class WavFile(AudioFile):

    ext = "wav"

    def play(self):
        print("Playing {} as wav".format(self.filename))


class OggFile(AudioFile):

    ext = "ogg"

    def play(self):
        print("Playing {} as ogg".format(self.filename))