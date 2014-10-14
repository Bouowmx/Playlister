#include <stdlib.h>
#include <string.h>

void linked_list_add_sorted(linked_list * list, song * data) {
	node * new_node = (node *) malloc(sizeof(node));
	new_node->data = data;
	new_node->next = NULL;
	node * current_node;
	if (linked_list_is_empty(list)) {
		list->first = new_node;
		list->last = new_node;
		return;
	}
	for (current_node = list->first; current_node; current_node = current_node->next) {
		if (strcmp(data->title, current_node->data->title) > 0) {
			new_node->next = current_node->next;
			current_node->next = new_node;
			return;
		}
	}
}

void linked_list_remove(linked_list * list, song * data) {
	node * current_node, previous_node;
	for (current_node = previous_node = list->first; current_node; current_node = current_node->next) {
		if (current_node != list->first) {previous_node = previous_node->next;}
		if (!(strcmp(data->album, current_node->data->album)) && !(strcmp(data->artist, current_node->data->artist)) && !(strcmp(data->title, current_node->data->title))) {
			previous_node->next = current_node->next;
			free(current_node);
			return;
		}
	}
}

