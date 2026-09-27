#include <stdio.h>
#include <stdlib.h>



typedef struct node {
	int value;
	struct node *next;
} node_t;




void push(node_t *head, node_t *new_node) {

	node_t *current = head;

	while(current->next != NULL) {
		current = current->next;
	}

	current->next = new_node;

}



void pop(node_t *head) {
	if(head==NULL) {
		return;
	}

	if(head->next==NULL) {
		free(head);
		return;
	}

	node_t *previous = NULL;

	while(head->next != NULL) {
		previous = head;
		head = head->next;
	}

	previous->next = NULL;
	free(head);


}


int listsize(node_t *head) {

	if (head == NULL) {
		return 0;
	}

	int size = 1;

	while(head->next != NULL) {
		head = head->next;
		size++;
	}

	return size;

}



void removefromlist(node_t *head, int index) {
	int size = listsize(head);
	if (index<0 || index>size-1) {
		printf("Error! index out of bounds! \n");
		return;
	}


	node_t *previous = NULL;
	node_t *current = head;
	node_t *next_node = head->next;

	if (index==0) {
		head = current->next;
		free(current);
		return;
	}



	for(int i=0; i<index; i++) {
		current = current->next;
	}

	node_t *removing_node = current->next;
	current->next = removing_node->next;
	free(removing_node);

}


int getbyIndex(node_t *head, int index) {
	
	int size = listsize(head);
	if (index<0 || index>size-1) {
		printf("Error! index out of bounds!");
		return -1;
	}

	if(index==0) {
		return head->value;
	}

	node_t *current = head->next;


	for(int i=1; i<index; i++) {
		current = current->next;
	}


	return current->value;

}


void modifylist(node_t *head, int index, int newValue) {

	
	int size = listsize(head);
	if (index<0 || index>size-1) {
		printf("Error! index out of bounds!");
	}

	if(index==0) {
		head->value = newValue;
	}

	node_t *current = head->next;

	for(int i=1; i<index; i++) {
		current = current->next;
	}

	current->value = newValue;

}


void clearlist(node_t *head) {

	if(head==NULL) {
		return;
	}

	node_t *current = head;

	while(current != NULL) {
		node_t *next_node = head->next;
		free(current);
		current = next_node;
	}


}




void printlist(node_t *head) {

	if(head == NULL) {
		return;
	}

	while(head != NULL) {
		printf("%d \n", head->value);
		head = head->next;
	}


}



int main() {

	// making the list
	node_t *listHead = malloc(sizeof(node_t));
	listHead->value = 5;
	listHead->next = NULL;


	// making two new nodes
	node_t *new_node = malloc(sizeof(node_t));
	new_node->value = 10;
	new_node->next = NULL;
	node_t *new_node2 = malloc(sizeof(node_t));
	new_node2->value = 20;
	new_node2->next = NULL;


	// adding two nodes and printing the list
	push(listHead, new_node);
	push(listHead, new_node2);
	printlist(listHead);


	// popping and printing
	//pop(listHead);
	//printlist(listHead);
	//printf("%d \n", listsize(listHead));

	// clearing and printing
	//clearlist(listHead);
	//printlist(listHead);

	// removing an element by index and printing the list
	//removefromlist(listHead,2);
	//printlist(listHead);

	// getting a list element by index and printing it
	//int value = getbyIndex(listHead, 1);
	//printf("%d \n", value);

	// modifying a list element and printing the list
	//modifylist(listHead, 1, 135);
	//printlist(listHead);

	return 0;

}
 
