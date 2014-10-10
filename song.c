#include <stdlib.h>

typedef struct song {
	char * artist;
	char * title;
	//album, artist, bit_rate, filename, genre, location, size, title, track, track_length, year;
} song;

song * song_new(char * title, char * artist) {
	song * new_song = (song *) malloc(sizeof(song));
	new_song->artist = artist;
	new_song->title = title;
	return new_song;
}

