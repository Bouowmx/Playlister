#include "song.c"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linked_list linked_list;
typedef struct node node;

typedef struct linked_list {
	node * first;
	node * last;
} linked_list;

typedef struct node {
	song * data; //Type-specific
	node * next;
} node;

linked_list * linked_list_new() {
	linked_list * list = (linked_list *) malloc(sizeof(linked_list));
	list->first = NULL;
	list->last = NULL;
	return list;
}

void linked_list_add(linked_list * list, song * data) { //Type-specific
	node * new_node = (node *) malloc(sizeof(node));
	new_node->data = data;
	new_node->next = NULL;
	if (!(list->last)) {
		list->first = new_node;
		list->last = new_node;
		return;
	}
	list->last->next = new_node;
	list->last = new_node;
}

bool linked_list_contains(linked_list * list, song * data) { //Type-specific
	node * current_node;
	for (current_node = list->first; current_node; current_node = current_node->next) {if (!(strcmp(current_node->data->album, data->album)) && !(strcmp(current_node->data->artist, data->artist)) && !(strcmp(current_node->data->title, data->title))) {return true;}}
	return false;
}

void linked_list_print(linked_list * list) {
	printf("[");
	if (!(list->first)) {
		printf("]\n");
		return;
	}
	node * current_node;
	for (current_node = list->first; current_node; current_node = current_node->next) {
		song_print(current_node->data); //Type-specific
		if (current_node->next) {printf(", ");}
		else {printf("]\n");}
	}
}

/*int main() {
	linked_list * list = linked_list_new();
	
	linked_list_add(list, song_new("Bad Apple!!", "Alstroemeria Records", "EXSERENS"));
	linked_list_add(list, song_new("Bad Apple!!", "Alstroemeria Records", "EXSERENS"));
	linked_list_print(list);
	return EXIT_SUCCESS;
}*/
