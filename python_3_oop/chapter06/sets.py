song_library = [("Phantom of the opera", "Sarah Brightman"),
                ("Knocking on heaven's door", "Guns N' Roses"),
                ("Captain Nemo", "Sarah Brightman"),
                ("Patterns in the ivy", "Opeth"),
                ("November rain", "Guns N' Roses"),
                ("Beautiful", "Sarah Brightman"),
                ("Mal's song", "Vixy and Tony")]

artists = set()

for song, artist in song_library:
    artists.add(artist)

print(artists)

for artist in artists:
    print("{} plays good music".format(artist))

alpabetical = list(artists)
alpabetical.sort()
print(alpabetical)

my_artists = artists
auburns_artists = {"Nickelback", "Guns N' Roses", "Savage Garden"}

print("All: {}".format(my_artists.union(auburns_artists)))
print("Both: {}".format(my_artists.intersection(auburns_artists)))
print("Either but not both: {}".format(my_artists.symmetric_difference(auburns_artists)))

bands = {"Guns N' Roses", "Opeth"}

print("my_artists is to bands:")
print("issuperset: {}".format(my_artists.issuperset(bands)))
print("issubset: {}".format(my_artists.issubset(bands)))
print("difference: {}".format(my_artists.difference(bands)))
print("*" * 20)
print("issuperset: {}".format(bands.issuperset(my_artists)))
print("issubset: {}".format(bands.issubset(my_artists)))
print("difference: {}".format(bands.difference(my_artists)))
