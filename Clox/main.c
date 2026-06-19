#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node 
{
	char* data; 
	struct Node* previous;
	struct Node* next; 

}typedef Node; 

struct DoublyLinkedList
{
	Node* first; 
	Node* last; 
}typedef DoublyLinkedList; 

void insertAtHead(Node* node, DoublyLinkedList* list)
{
	//Insert a Node at the beginning
	
	if (!list->first) 
	{
		list->first = node; 
		list->last = node; 
		return;
	}
	
	if (list->first) 
	{
		node->next = list->first; 
		list->first->previous = node; 
		node->previous = NULL; 
		list->first = node; 
	} 

	Node* curr = list->first; 
	while (curr->next) 
	{
		curr = curr->next; 
	}
	list->last = curr; 
}

Node* createNode(char* data)
{
	Node* node = malloc(sizeof(Node)); 
	node->data = data; 
	node->next = NULL;
	node->previous = NULL; 

	return node; 
}

void traverse(DoublyLinkedList* list)
{
	if (list->first == NULL) 
	{
		printf("List is empty congratz!\n"); 
		return;
	}

	Node* curr = list->first; 
	while (curr->next) 
	{
		printf("Node: %s\n", curr->data); 
		curr = curr->next; 
	}
	printf("Node: %s\n", curr->data); 
}

Node* findNode(char* string, DoublyLinkedList* list)
{
	Node* curr = list->first; 
	while (curr->next) 
	{
		if (strcmp(curr->data, string)) 
		{
			printf("Node was found\n"); 
			return curr;
		}
		curr = curr->next; 
	}
	printf("Node could not be found"); 
	return NULL;
}

void deleteNode(Node* node, DoublyLinkedList* list)
{
	if (list->first == node) 
	{
		Node* nextNode = node->next; 
		if (nextNode == NULL) 
		{
			//This is the only Node Left
			node->previous = NULL;
			node->next = NULL;
			list->first = NULL;
			list->last = NULL;
			free(node); 
			return;
		}
		nextNode->previous = NULL; 
		node->next = NULL; 
		node->previous = NULL;
		list->first = nextNode;
		free(node); 
		return;
	}

	if (list->last == node) 
	{
		Node* previousNode = node->previous; 
		previousNode->next = NULL; 
		node->next = NULL;
		node->previous = NULL;
		list->last = previousNode; 
		free(node); 
		return;
	}
	Node* curr = list->first;
	while (curr->next) 
	{
		if (curr == node) 
		{
			Node* previousNode = node->previous; 
			Node* nextNode = node->next; 
			previousNode->next = nextNode;
			nextNode->previous = previousNode; 
			node->next = NULL;
			node->previous = NULL;
			free(node); 
			break;
		}
		curr = curr->next; 
	}
}

int main()
{
	DoublyLinkedList* list = malloc(sizeof(DoublyLinkedList)); 
	Node* node = createNode("Hello There"); 
	Node* node2 = createNode("Last Node Which is now First Node"); 
	Node* node3 = createNode("A"); 
	Node* node4 = createNode("B"); 
	insertAtHead(node, list);
	insertAtHead(node2, list);
	insertAtHead(node3, list);
	insertAtHead(node4, list);
	traverse(list); 
	findNode("A", list); 
	deleteNode(node3, list); 
	deleteNode(node2, list); 
	deleteNode(node, list); 
	deleteNode(node4, list); 
	traverse(list); 
}
