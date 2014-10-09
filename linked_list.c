#include "song.c"
#include <stdio.h>
#include <stdlib.h>

struct linked_list;
struct node;

typedef struct linked_list {
	struct node * first;
	struct node * last;
} linked_list;

typedef struct node {
	void * data;
	struct node * next;
} node;

linked_list * new_linked_list() {
	linked_list * list = (linked_list *) malloc(sizeof(linked_list));
	list->first = NULL;
	list->last = NULL;
	return list;
}

void add(linked_list * list, void * data) {
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

void print_list(linked_list * list) {
	printf("[");
	if (!list) {
		printf("]\n");
		return;
	}
	node * current_node;
	for (current_node = list->first; current_node; current_node = current_node->next) {
		printf("%i", *((int *) current_node->data)); //Type-specific
		if (current_node->next) {printf(", ");}
		else {printf("]\n");}
	}
}

/*int main() {
	linked_list * list = new_linked_list();
	int i[2] = {0, 1};
	add(list, &i[0]);
	add(list, &i[1]);
	print_list(list);
	return EXIT_SUCCESS;
}*/
