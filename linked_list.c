#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

linked_list * linked_list_new() {
	linked_list * list = (linked_list *) malloc(sizeof(linked_list));
	list->first = NULL;
	return list;
}

void linked_list_add(linked_list * list, song * data) {
	node * new_node = (node *) malloc(sizeof(node));
	new_node->data = data;
	new_node->next = NULL;
	if (linked_list_is_empty(list)) {
		list->first = new_node;
		return;
	}
	node * current_node;
	for (current_node = list->first; current_node->next; current_node = current_node->next) {}
	current_node->next = new_node;
}

void linked_list_add_sorted(linked_list * list, song * data) {
	node * new_node = (node *) malloc(sizeof(node));
	new_node->data = data;
	new_node->next = NULL;
	node * current_node;
	if (linked_list_is_empty(list)) {
		list->first = new_node;
		return;
	}
	for (current_node = list->first; current_node; current_node = current_node->next) {
		if (strcmp(data->title, current_node->data->title) >= 0) {
			new_node->next = current_node->next;
			current_node->next = new_node;
			return;
		}
	}
	//If the above is not run, then the song to add will go first.
	new_node->next = list->first;
	list->first = new_node;
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

bool linked_list_is_empty(linked_list * list) {return !(list->first);}

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

void linked_list_remove(linked_list * list, song * data) {
	node * current_node;
	node * previous_node;
	for (current_node = previous_node = list->first; current_node; current_node = current_node->next) {
		if (current_node != list->first) {previous_node = previous_node->next;}
		if (!(strcmp(data->album, current_node->data->album)) && !(strcmp(data->artist, current_node->data->artist)) && !(strcmp(data->title, current_node->data->title))) {
			previous_node->next = current_node->next;
			free(current_node);
			return;
		}
	}
}

