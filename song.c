#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct song {
	char * album;
	char * artist;
	char * title;
	//album, artist, bit_rate, filename, genre, location, size, title, track, track_length, year;
} song;

song * song_new(char * title, char * artist, char * album) {
	song * new_song = (song *) malloc(sizeof(song));
	new_song->album = (char *) malloc(strlen(album) + 1);
	strcpy(new_song->album, album);
	new_song->artist = (char *) malloc(strlen(artist) + 1);
	strcpy(new_song->artist, artist);
	new_song->title = (char *) malloc(strlen(title) + 1);
	strcpy(new_song->title, title);
	return new_song;
}

song * song_new_empty() {return song_new("", "", "");}

void song_print(song * s) {
	printf("[Title: %s, Artist: %s, Album: %s]", s->title, s->artist, s->album);
	/*char song_info[strlen("Album: ") + strlen(s->album) + strlen("Artist: ") + strlen(s->artist) + strlen("Title: ") + strlen(s->title) + 2 * strlen(", ") + 1];
	strcat(song_info, "Title: ");
	strcat(song_info, s->title);
	strcat(song_info, ", ");
	strcat(song_info, "Artist: ");
	strcat(song_info, s->artist);
	strcat(song_info, ", ");
	strcat(song_info, "Album: ");
	strcat(song_info, s->album);
	return song_info;*/
}

/*int main() {
	song * s = song_new("Bad Apple!!", "Alstroemeria Records", "EXSERENS");
	song_print(s);
	return EXIT_SUCCESS;
}*/
