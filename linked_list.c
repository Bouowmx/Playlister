#include "song.c"
#include <stdlib.h>

typedef struct node {
	struct song * data;
	struct node * next;
} node;

typedef struct linked_list {
	struct node * first;
} linked_list;

linked_list * new_linked_list(song * song) {
	node * first = (node *) malloc(sizeof(node));
	first->data = song;
	first->next = NULL;
	linked_list * list = (linked_list *) malloc(sizeof(linked_list));
	list->first = first;
	return list;
}

