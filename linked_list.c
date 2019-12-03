#include "linked_list.h"
#include <stdio.h>
#include <stdbool.h>


p_node_t p_list; //Pointer to first node

//defining the struct of type node
typedef struct node {
	//the value/element that the node is holding
	void * element;
	//the pointer pointing at the node next to this node.
	p_node_t next;
} node_t;


//defining the struct of linked_list
typedef struct list {
	//size of the list
	int size;
	//top node/last node
	p_node_t top;
	//first node
	p_node_t first;
}list_t;


//works like a constructor
p_list_t linked_list_create()
{
	p_list_t new_list = malloc(sizeof(struct list));
	new_list->size = 0;
	new_list->top = NULL;
	new_list->first = NULL;
	return new_list;
}

//returns the size of the list if it's created, if not, it returns -1
int noOfItems(p_list_t list) {
	if (list != NULL) {
		return list->size;
	}
	else {
		return -1;
	}
}


//adds an item to the list - we need to check/modify the first-top-size-next of top and create the new node.
int addItem(p_list_t list, void* item) {
	// Return 0 if item added else -1
		//mallocatin the new node
		p_node_t p_new_node;
		p_new_node = malloc(sizeof(node_t));
		//setting the next of the top (last) node as the new node
		//only if the top node is not NULL
		if (list->top != NULL) {
			list->top->next = p_new_node;
		}
		//setting the top of the list as the new node.
		list->top = p_new_node;
		//setting the values of the new node.
		p_new_node->element = item;
		p_new_node->next = NULL;
		//Increasing the size of the list
		list->size++;
		//if we just added the first element to the list, the new node will be the first node.
		if (list->size == 1) {
			list->first = p_new_node;
		}
		//if succeed, return 0;
		return 0;
}

//recursive function to get the node contain the item
//current should be the first node in a list. (where the search will start)
p_node_t search(p_list_t list, p_node_t current, void*item) {
	//the node is the result of search, will have the refrence of the node containing the item in the list when returned.
	if (current != NULL) {
		if (current->element == item) {
			return current;
		}
		else {
			search(list, current->next, item);
		}
	} else {
		//will reach here when current->next is NULL
			return NULL;
	}
} 

//used to remove element in the later method
p_node_t get_before(p_list_t list, p_node_t current, const p_node_t next) {
	
	if (current->next != NULL) {
		if (current->next == next) {
			return current;
		}
		else {
			get_before(list, current->next, next);
		}
	}
	else {
		return NULL;
	}
}



//
int removeItem(p_list_t list, void* item) {
	// Return 0 if item removed else -1
	p_node_t node = NULL;
	//we search for the node containing the element
	node = search(list, list->first, item);
	//if found
	if (node != NULL ) {
		//if it's the first node, we don't modify the next of the previous node. so..
		if (list->first == node) {
			if (node->next == NULL) {
				//this case, the node is the only node in the list, so top and first are NULLs.
				list->top = NULL;
				list->first = NULL;
			}
			else {
				//if it's not the only node, the next node will be the new first.
				list->first = node->next;
			}
		}
		//if the node is not the first
		else {
			//we should modify the node's previous node's next to the node's next
			p_node_t previous_node = NULL;
			previous_node = get_before(list, list->first, node);
			//just to be sure, we check again
			if (previous_node != NULL) {
				previous_node->next = node->next;
				// if this node was the top node, the previous wil be the new top
				if (node->next == NULL) {
					list->top = previous_node;
				}
			}
		}
		//we free the node and set its value to NULL
		free(node);
		node = NULL;
		//decrease the size
		list-> size--;
		return 0;
	}
	else {
		//couldn't find the node
		return -1;
	}

}

//to destroy the list
void linked_list_destroy(p_list_t self)
{
	free(self);
	self = NULL;
}

//get Element by index
//returns the pointer to the element.
void* getElement(p_list_t self, int i)
{
	p_node_t current = self->first;
	for (int j = 0; j < noOfItems(self); j++) {
		if (i == j) {
			return current->element;
		}
		else {
			current = current->next;
		}
	}
}
