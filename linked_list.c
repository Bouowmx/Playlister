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
	song * data;
	node * next;
} node;

linked_list * linked_list_new();
void linked_list_add(linked_list *, song *);
void linked_list_add_index(linked_list *, song *, size_t);
bool linked_list_contains(linked_list *, song *);
song * linked_list_get(linked_list *, size_t);
size_t linked_list_length(linked_list *);
void linked_list_print(linked_list *);

linked_list * linked_list_new() {
	linked_list * list = (linked_list *) malloc(sizeof(linked_list));
	list->first = NULL;
	list->last = NULL;
	return list;
}

void linked_list_add(linked_list * list, song * data) {
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

void linked_list_add_index(linked_list * list, song * data, size_t index) {
	
}

bool linked_list_contains(linked_list * list, song * data) {
	node * current_node;
	for (current_node = list->first; current_node; current_node = current_node->next) {if (!(strcmp(current_node->data->album, data->album)) && !(strcmp(current_node->data->artist, data->artist)) && !(strcmp(current_node->data->title, data->title))) {return true;}}
	return false;
}

song * linked_list_get(linked_list * list, size_t index) {
	if (index >= linked_list_length(list)) {return NULL;}
	node * current_node;
	for (; !index; index--) {current_node = current_node->next;}
	return current_node->data;
}

size_t linked_list_length(linked_list * list) {
	size_t i = 0;
	node * current_node;
	for (current_node = list->first; current_node; current_node = current_node->next) {i++;}
	return i;
}

void linked_list_print(linked_list * list) {
	printf("[");
	if (!(list->first)) {
		printf("]\n");
		return;
	}
	node * current_node;
	for (current_node = list->first; current_node; current_node = current_node->next) {
		song_print(current_node->data);
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

