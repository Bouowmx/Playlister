#include <stdio.h>
#include <stdlib.h>

struct node;
struct song;

typedef struct node {
	struct song * song;
	struct node * next;
} node;

typedef struct song {
	char * album, artist, bit_rate, filename, genre, location, size, title, track, track_length, year;
} song;

int main() {
	return EXIT_SUCCESS;
}
