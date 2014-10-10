#include "linked_list.c"
#include <stdio.h>
#include <stdlib.h>

unsigned char character(unsigned char i) {return i + 'A';}

char ord(char c) { //This is like Python's ord, which takes a character and returns its ASCII value. Here, it maps A-Z and a-z to [0-25].
	if ((c >= 'A') && (c <= 'Z')) {return c - 'A';}
	else if ((c >= 'a') && (c <= 'z')) {return c - 'a';}
	else {return -1;}
}

int main() {
	linked_list * music_library[26];
	unsigned int i;
	for (i = 0; i < 26; i++) {music_library[i] = linked_list_new();}
	for (i = 0; i < 26; i++) {
		printf("%c: ", character(i));
		print_list(music_library[i]);
	}
	
	/*linked_list * l = linked_list_new();
	song * s = song_new("Marisa Stole the Precious Thing", "IOSYS");
	linked_list_add(l, s);
	print_list(l);*/
	return EXIT_SUCCESS;
}

