#pragma once

typedef struct node* p_node_t;
typedef struct list* p_list_t;

p_list_t linked_list_create();

int noOfItems(p_list_t list);

int addItem(p_list_t list, void* item);

p_node_t search(p_list_t list, p_node_t node, void* item);

p_node_t get_before(p_list_t list, const p_node_t node);

int removeItem(p_list_t list, void* item);

void linked_list_destroy(p_list_t self);

void* getElement(p_list_t self, int i);
