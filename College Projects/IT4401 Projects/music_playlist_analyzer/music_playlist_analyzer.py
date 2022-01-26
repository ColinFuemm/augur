# Music Playlist Analyzer
# by Dale Mussser

# note: in the provided data, one file has all lines containing 30 items and in the other
# most lines contain 30 items but some contain 31
# only the first 30 will be used

def parse_data(lines):
    element_count = 30
    if (len(lines) < 2):
        return {"labels":[], "songs":[]}

    label_line = lines[0]
    labels = label_line.split("\t")
    if len(labels) < element_count:
        return {"labels":[], "songs":[]}

    songs = []
    for line in lines[1:]:
        elements = line.split("\t")
        if (len(elements) >= element_count):
            elements = elements[0:element_count:1]
            songs.append(get_typed_elements_list(elements))
        #else bad line is skipped

    return {"labels":labels, "songs":songs}


def load_data(filepath):
    with open(filepath, encoding="utf16") as file:
        lines = file.readlines()
    return lines

def get_typed_elements_list(elements):
    typed_elements = []
    for element in elements:
        typed_elements.append(make_type(element))
    return typed_elements

def make_type(element):
    try:
        value = int(element)
        return value
    except:
        try:
            value = float(element)
            return value
        except:
            return element

def get_number_of_songs(playlist_info):
    return len(playlist_info["songs"])

# Year is th year of the song
def get_songs_played_each_year(playlist_info):
    songs = playlist_info["songs"]
    year_info = dict()
    year_index = playlist_info["labels"].index("Year")

    for song in songs:
        song_year = song[year_index]
        if song_year in year_info:
            year_info[song_year] += 1
        else:
            year_info[song_year] = 1

    return year_info


def get_shortest_and_longest_from_songs(songs, time_index):
    if len(songs) < 1:
            return

    first_song = songs[0]
    longest_songs = [first_song]
    shortest_songs = [first_song]

    for song in songs[1:]:  # skip first
        song_time = song[time_index]
        if 'str' in str(type(song_time)): # skip any song with no time
            continue
        longest_time = longest_songs[0][time_index]
        shortest_time = shortest_songs[0][time_index]

        if (song_time > longest_time):
            longest_songs = [song]
        elif (song_time == longest_time):
            longest_songs.append(song)
        elif (song_time < shortest_time):
            shortest_songs = [song]
        elif (song_time == shortest_time):
            shortest_songs.append(song)

    return(shortest_songs, longest_songs)


# Time is length of song
def get_shortest_and_longest_songs_from_playlist(playlist_info):
    time_index = playlist_info["labels"].index("Time")
    songs = playlist_info["songs"]

    return get_shortest_and_longest_from_songs(songs, time_index)
    


def get_songs_by_genre(playlist_info):
    labels = playlist_info["labels"]
    genre_index = labels.index("Genre")
    songs = playlist_info["songs"]

    songs_by_genre = dict()

    for song in songs:
        genre = song[genre_index]
        if genre in songs_by_genre.keys():
            songs_by_genre[genre].append(song)
        else:
            songs_by_genre[genre] = [song]

    return songs_by_genre


def get_genre_info(playlist_info):
    time_index = playlist_info["labels"].index("Time")
    songs_by_genre = get_songs_by_genre(playlist_info)  # a dictionary with keys being the genre

    genre_info = dict()

    for genre in songs_by_genre.keys():
        songs = songs_by_genre[genre]
        number = len(songs)
        (shortest_songs, longest_songs) = get_shortest_and_longest_from_songs(songs, time_index)
        genre_info[genre] = {"genre": genre, "number": number, "shortest_songs": shortest_songs, "longest_songs": longest_songs}
    
    return genre_info

def get_number_of_played_and_unplayed_songs(playlist_info):
    num_played_songs = 0
    num_unplayed_songs = 0
    labels = playlist_info["labels"]
    plays_index = labels.index("Plays")
    songs = playlist_info["songs"]
    for song in songs:
        plays = song[plays_index]
        if ("str" in str(type(plays))):
            num_unplayed_songs += 1
        elif (song[plays_index] > 0):
            num_played_songs += 1
        else:
            num_unplayed_songs += 1
    return(num_played_songs, num_unplayed_songs)



def playlist_analyzer(filepath):
    playlist_info = parse_data(load_data(filepath))  
    number_of_songs = get_number_of_songs(playlist_info)
    year_info = get_songs_played_each_year(playlist_info)
    (shortest_songs, longest_songs) = get_shortest_and_longest_songs_from_playlist(playlist_info)
    (num_played_songs, num_unplayed_songs) = get_number_of_played_and_unplayed_songs(playlist_info)

    time_index = playlist_info["labels"].index("Time")
    artist_index = playlist_info["labels"].index("Artist")
    name_index = playlist_info["labels"].index("Name")

    print("Number of songs: {}\n".format(number_of_songs))

    print("Number of songs each year:")

    number = year_info[""]
    print("{} = {}".format("unknown", number))

    del(year_info[""])

    years = sorted(list(year_info.keys()))

    for year in years:
        number = year_info[year]
        print("{} = {}".format(year, number))
    
    print("\n")

    print("shortest song(s):")
    for song in shortest_songs:
        print("Name: {}\nArtist: {}\nTime: {}\n".format(song[name_index], song[artist_index], song[time_index]))
    print("longest song(s):")
    for song in longest_songs:
        print("Name: {}\nArtist: {}\nTime: {}\n".format(song[name_index], song[artist_index], song[time_index]))

    print("Num played: {}".format(num_played_songs))
    print("Num unplayed: {}\n".format(num_unplayed_songs))

    genre_info = get_genre_info(playlist_info)

    for genre_name in genre_info.keys():
        genre = genre_info[genre_name]
        number = genre["number"]
        print("Genre: {}\nsongs = {}".format(genre_name, number))
        print("longest song(s):")
        for song in genre["longest_songs"]:
            print("Name: {}, Artist: {}, Time: {} seconds".format(song[name_index], song[artist_index], song[time_index]))
        print("shortest song(s):")
        for song in genre["shortest_songs"]:
            print("Name: {}Artist: {}Time: {} seconds".format(song[name_index], song[artist_index], song[time_index]))
        print("\n")

def main():
    print("\nMusic Playlist Analyzer\n")
    while True:
        filepath = input("What is the path to the music playlist file? ")
        try:
            playlist_analyzer(filepath)
        except Exception as error:
            print(error)

        again = input("Would you like to analyzer another file? (y/n)")
        if (again != "y"):
            break
        print("\n")


main()
