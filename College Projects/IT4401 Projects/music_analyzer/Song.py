class Song:
    def __init__(self, name, artist, releaseYear, playtime, genre, isPlayed):
        self.__name = name
        self.__artist = artist
        self.__releaseYear = releaseYear
        self.playtime = playtime
        self.__genre = genre
        self.__isPlayed = isPlayed

    def get_name(self):
        return self.__name
    def get_artist(self):
        return self.__artist
    def get_releaseYear(self):
        return self.__releaseYear
    def get_playtime(self):
        return self.playtime
    def get_genre(self):
        return self.__genre
    def playStatus(self):
        return self.__isPlayed
    
