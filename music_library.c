#include "linked_list.c"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct music_library {linked_list * library[27];} music_library;

unsigned char ord(char);

music_library * music_library_new() {
	unsigned char i;
	music_library * library = (music_library *) malloc(sizeof(music_library));
	for (i = 0; i < 27; i++) {library->library[i] = linked_list_new();}
	return library;
}

unsigned char character(unsigned char i) {return i + 'A';}

void music_library_add(music_library * library, char * title, char * artist, char * album) {linked_list_add_sorted(library->library[ord(title[0])], song_new(title, artist, album));}

void music_library_print(music_library * library) {
	unsigned char i;
	for (i = 0; i < 26; i++) {
		printf("%c: ", character(i));
		linked_list_print(library->library[i]);
	}
	printf("Other: ");
	linked_list_print(library->library[26]);
}

void music_library_print_artist(music_library * library, char * artist) {
	unsigned char i;
	for (i = 0; i < 26; i++) {
		linked_list * list = library->library[i];
		node * current_node;
		for (current_node = list->first; current_node; current_node = current_node->next) {if (strstr(current_node->data->artist, artist)) {song_print(current_node->data);}}
	}
}

void music_library_print_letter(music_library * library, char letter) {linked_list_print(library->library[ord(letter)]);}

unsigned char ord(char c) { //This is like Python's ord, which takes a character and returns its ASCII value. Here, it maps A-Z and a-z to [0-25].
	if ((c >= 'A') && (c <= 'Z')) {return c - 'A';}
	else if ((c >= 'a') && (c <= 'z')) {return c - 'a';}
	else {return 26;}
}

