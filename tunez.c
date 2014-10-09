#include "linked_list.c"
#include <stdio.h>
#include <stdlib.h>

int ord(char c) { //This is like Python's ord, which takes a character and returns its ASCII value. Here, it maps A-Z and a-z to [0-25].
	if ((c >= 'A') && (c <= 'Z')) {return c - 'A';}
	else if ((c >= 'a') && (c <= 'z')) {return c - 'a';}
	else {return -1;}
}

int main() {
	linked_list * music_library[26]
	return EXIT_SUCCESS;
}

