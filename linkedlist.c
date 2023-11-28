#include "linkedlist.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"


int LinkedList_remove_value(LinkedList* l, int value){
    /*
    Finds the first occurrence of value (int) in the LinkedList and removes it from the LinkedList.
    Returns the index of the the first occurance. If not found, returns -1.
    Indexing starts from 0 (as with arrays).
    E.g. let l contains [3,2,5,1] and value=2 then the content of l should be changed to [3,5,1] and return 1.
    DO NOT FORGET TO FREE THE UNUSED (REMOVED) SPACE SINCE IT IS DYNAMICALLY ALLOCATED.
    */
    //////////////////////////////////////////////////
    	int i = 0;
	
	if (l->root == NULL) {
		return -1;
	}
	
	Node* current = l->root;
	Node* previous = l->root;

	int len = LinkedList_length(l);

	if (len == 1) {
		if (current->content == value) {
			free(l->root);
			l->root = NULL;
			return i;
		} else {
			return -1;
		}
	} else if (len == 2) {
		if (current->content == value) {
			//previous = current;
			current = current->next;
			return i;
		} else {
			previous = current;
			current = current->next;
			if (current->content == value) {
				return 1;
			} else {
				return -1;
			}
		}
	}


	for (i = 0; i < len-2; i++) {
		if (current->content == value) {
			if (i == 0) {
				l->root = current->next;
				return i;
			}
			previous->next = current->next;
			return i;
		}
		if (i > 0) {
			previous = current;
		}
		current = current->next;
	}
	
	if (current->next->content == value) {
		current->next = NULL;
		return len-1;
	} else {
		return -1;
	}


    /////////////////////////////////////////////////
}


void LinkedList_init(LinkedList* l, int* arr, int len){
    // Initializes the LinkedList with a copy of array arr
    l->root = NULL; // initialize root node to NULL
    int i;
    for(i=0;i<len;i++){
        LinkedList_insert(l, arr[i]);
    }
} 


int LinkedList_length(LinkedList* l){
    // Calculates the length of the LinkedList.
    
    if(l->root == NULL){
        return 0;
    }else{
        int count = 1;
        Node* current = l->root;
        while(current->next != NULL){
            current = current->next;
            count++;
        }
        return count;
    }
}

int LinkedList_remove(LinkedList* l){
    // Deletes the last node and returns its value (content)
    // Note: return -1 when there is no value in the list.

    int value = -1;
    if(l->root == NULL){
        return value;
    }else if(l->root->next == NULL){
        // when there is only root node
        value = l->root->content;
        free(l->root);
        l->root = NULL;
        return value;
    }else{
        // when there multiple nodes
        Node* current = l->root;
        while(current->next->next != NULL){
            current = current->next;
        }
        value = current->next->content;
        free(current->next);
        current->next = NULL;
        return value;
    }
}

void LinkedList_insert(LinkedList* l, int value){
	/*
	Appends the value to the end of linked list as a new node.
	E.g. let l contains [3,2,5,1] and value=8 then the content of l should be changed to [3,2,5,1,8].
	*/
    //////////////////////////////////////////////////
    
	Node* new = (Node*)malloc(sizeof(Node));;
	new->content = value;
	new->next = NULL;
    
    // FILL HERE		
	if (l->root == NULL) {
		l->root = new;
	} else {
		Node* current = l->root;
		while (current->next != NULL) {
			current = current->next;
		}
		current->next = new;
	}
   		
    
    
    /////////////////////////////////////////////////
    
}

char* LinkedList_to_string(LinkedList* l, char* str){
    // Converts LinkedList to string and puts it into str
    strcat(str, "[ ");
    Node* current = l->root;
    if(current != NULL){
        do{
            char temp[10]  = "";
            sprintf(temp, "%d ", current->content);
            strcat(str, temp);
            current = current->next;
        }while(current != NULL);
    }
    strcat(str, "]");
    return str;
}



