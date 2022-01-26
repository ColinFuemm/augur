from Song import Song
import operator

def get_file_text(filename):
    with open(filename, 'r', encoding="utf-16")as file:
        next(file)
        lines = file.readlines()
    return lines
        
    
def interpret_text(lines):
    songs = []
    for line in lines:
        fields = line.split('	')
        #if len(fields) != 31:
        #    raise Exception('Expected 31 fields but found %s' % len(fields))
        name = fields[0]
        artist = fields[1]
        releaseYear = fields[16]
        try:
            playtime = int(fields[11])
        except:
            playtime = 0
        genre = fields[9]
        if fields[25]== 0:
            isPlayed = False
        else:
            isPlayed = True
        songs.append(Song(name, artist, releaseYear, playtime, genre, isPlayed))     
    return songs

def get_report(songs):
    playCount = 0
    songsByTime = sorted(songs, key = operator.attrgetter('playtime'))
    shortest = songsByTime[0]         
    longest = songsByTime[-1]
    yearFrequencies = {}
    genreFrequencies = {}
    for song in songs:
        boolean = song.playStatus()
        year = song.get_releaseYear()
        genre = song.get_genre()
        if year in yearFrequencies:
            yearFrequencies[year] += 1
        else:
            yearFrequencies[year] = 1
        if genre in genreFrequencies:
            genreFrequencies[genre] += 1
        else:
            genreFrequencies[genre] = 1
        if boolean is True:
            playCount += 1
    print("Number of Songs: " + str(len(songs)))
    print("Number of Songs by Year: ")
    print(yearFrequencies)
    print("Shortest Song: " + shortest.get_name() + " by " + shortest.get_artist())
    print("PlayTime: " + str(shortest.playtime) + "sec")
    print("Longest Song: " + longest.get_name() + " by " + longest.get_artist())
    print("PlayTime: " + str(longest.playtime) + "sec")
    print("Genre Stats: ")
    for key in genreFrequencies:
        print("Genre: " + key + ", " + str(genreFrequencies[key]) + " songs")
    print("Songs that have been played: " + str(playCount))
    print("Songs that have not: " + str(len(songs) - playCount))
    
        
    
    
def main():
    while (True):
        filename = input("Please enter your music text file: ")
        lines = get_file_text(filename)
        playlist = interpret_text(lines)
        get_report(playlist)
        calculate_again = input("Would you like to check another file? y/n:" )
        if (calculate_again != "y"):
            print("Have a nice day!")
            break  
        else:
            print('') # separator between inputs
main()

'''0Name 1Artist 2Composer 3Album 4Grouping 5Work 6Movement Number
7Movement Count 8Movement Name 9Genre 10Size 11Time 12Disc Number 13Disc 
Count 14Track Number 15Track Count 16Year 17Date Modified 18Date Added 19Bit 
Rate 20Sample Rate 21Volume Adjustment 22Kind 23Equalizer 24Comments 25Plays 26Last 
Played 27Skips 28Last Skipped 29My Rating 30Location'''
