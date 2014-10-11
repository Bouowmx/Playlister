#include "linked_list.c"
#include <stdio.h>
#include <stdlib.h>

typedef struct music_library {linked_list * library[26];} music_library;

music_library * music_library_new() {
	linked_list * library_list[26];
	unsigned char i;
	for (i = 0; i < 26; i++) {library_list[i] = linked_list_new();}
	music_library * library = (music_library *) malloc(sizeof(music_library));
	library->library = library_list;
	return library;
}

unsigned char character(unsigned char i) {return i + 'A';}

void music_library_print(music_library * library) {
	unsigned char i;
	for (i = 0; i < 26; i++) {
		printf("%c: ", character(i));
		linked_list_print(library->library[i]);
	}
}

char ord(char c) { //This is like Python's ord, which takes a character and returns its ASCII value. Here, it maps A-Z and a-z to [0-25].
	if ((c >= 'A') && (c <= 'Z')) {return c - 'A';}
	else if ((c >= 'a') && (c <= 'z')) {return c - 'a';}
	else {return -1;}
}

int main() {
	printf("Success.\n");
	music_library * library = music_library_new();
	music_library_print(library);
	
	return EXIT_SUCCESS;
}

