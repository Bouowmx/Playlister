#include "song.c"
#include <stdbool.h>

typedef struct linked_list linked_list;
typedef struct node node;

typedef struct linked_list {node * first;} linked_list;

typedef struct node {
	song * data;
	node * next;
} node;

linked_list * linked_list_new();
void linked_list_add(linked_list *, song *);
void linked_list_add_sorted(linked_list *, song *);
bool linked_list_contains(linked_list *, song *);
bool linked_list_is_empty(linked_list *);
song * linked_list_get(linked_list *, size_t);
size_t linked_list_length(linked_list *);
void linked_list_print(linked_list *);