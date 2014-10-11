#include "linked_list.c"
#include <stdio.h>
#include <stdlib.h>

typedef struct music_library {linked_list * library[27];} music_library;

unsigned char ord(char);

music_library * music_library_new() {
	unsigned char i;
	music_library * library = (music_library *) malloc(sizeof(music_library));
	for (i = 0; i < 27; i++) {library->library[i] = linked_list_new();}
	return library;
}

unsigned char character(unsigned char i) {return i + 'A';}

void music_library_add(music_library * library, char * title, char * artist, char * album) {linked_list_add(library->library[ord(title[0])], song_new(title, artist, album));}

void music_library_add_song(music_library * library, song * song) {linked_list_add(library->library[ord(song->title[0])], song);}

void music_library_print(music_library * library) {
	unsigned char i;
	for (i = 0; i < 26; i++) {
		printf("%c: ", character(i));
		linked_list_print(library->library[i]);
	}
}

unsigned char ord(char c) { //This is like Python's ord, which takes a character and returns its ASCII value. Here, it maps A-Z and a-z to [0-25].
	if ((c >= 'A') && (c <= 'Z')) {return c - 'A';}
	else if ((c >= 'a') && (c <= 'z')) {return c - 'a';}
	else {return 26;}
}

int main() {
	printf("Success.\n");
	music_library * library = music_library_new();
	music_library_add(library, "Bad Apple!!", "Alstroemeria Records", "EXSERENS");
	music_library_print(library);
	
	return EXIT_SUCCESS;
}

