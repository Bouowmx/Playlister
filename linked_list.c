#include "song.c"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct linked_list;
struct node;

typedef struct linked_list {
	struct node * first;
	struct node * last;
} linked_list;

typedef struct node {
	song * data; //Type-specific
	struct node * next;
} node;

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

bool linked_list_contains(linked_list * list, song * data) {
	node * current_node;
	for (current_node = list->first; current_node; current_node = current_node->next) {if (!(strcmp(current_node->data->artist, data->artist)) && !(strcmp(current_node->data->title, data->title))) {return true;}}
	return false;
}

void print_list(linked_list * list) {
	printf("[");
	if (!(list->first)) {
		printf("]\n");
		return;
	}
	node * current_node;
	for (current_node = list->first; current_node; current_node = current_node->next) {
		printf("[Title: %s, Artist: %s]", current_node->data->title, current_node->data->artist); //Type-specific
		if (current_node->next) {printf(", ");}
		else {printf("]\n");}
	}
}

