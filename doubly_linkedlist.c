/*
Purpose: implement a doubly linked list which 
stores only abs value of items.
*/

#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) (a) < (b) ? (b) : (a)

#define ABS(a) (a)<0 ? -(a):(a)

#define SQR(a) a*a

#define print(a) printf("%d",a);
typedef struct node* Node;

struct node{
	int data;
	Node prev;
	Node next;
};

//insert
void insertAt(Node *list,int data,int index);

//remove
void delete(Node *list,int index);

//search

int search(Node *list,int data);

//traverse

void traverse(Node list);

Node getNewNode(int data){
		Node newNode;
		newNode = malloc(sizeof(struct node));
		if(!newNode){
				printf("could not allocate memory");
				exit(1);
		}	
		newNode->data = data;
		newNode->next = NULL;
		newNode->prev = NULL;
		return newNode;	
	}



int main(){
	Node myList=NULL;
	insertAt(&myList,2,1);
	insertAt(&myList,3,2);
	insertAt(&myList,4,3);
	insertAt(&myList,5,4);
	insertAt(&myList,6,5);
	insertAt(&myList,7,6);	
	insertAt(&myList,8,2);
	deleteAt(&myList,4);
	deleteAt(&myList,1);
	return 0;	
}

void insertAt(Node *list,int data,int index){
	Node newNode = getNewNode(data); 
	Node prev,current,next;
	int indexCount=1;
	printf("\nInsert %d at %d",data,index);
	if(!*list){
		Node newNode=getNewNode(data);
		*list=newNode;
		traverse(*list);
		return;
	}
	
	else{
		current=*list;
		if(index==1){
			current->prev=newNode;
			newNode->next = current;
			newNode->next = NULL;
			current = newNode;
		}
		else{
			while(current->next && indexCount!=index-1){
			current = current->next;
			indexCount++;
			}
			newNode->prev = current;
			newNode->next = current->next;
			current->next=newNode;
		}
}
	traverse(*list);
}

void deleteAt(Node *list,int index){
	int indexCount;
	Node head=*list;
	Node prev,next;
	printf("\nDelete at %d",index);
	
	if(index==1){
		next = head->next;
		next->prev=NULL;
		free(head);
		*list=next;
	}
	else{
	while(head->next && indexCount!=index-1){
		head=head->next;
		indexCount++;
	}
	if(indexCount!=index-1){
		printf("\nIndex Not Found\n");
		return;
	}
	else{
		prev = head->prev;
		next=head->next;
		
		prev->next = next;
		next->prev = prev;
		free(head);
	}
}
	traverse(*list);
	
}

void traverse(Node ref){
	printf("\n");
	while(ref){
	printf("|  %d  ",ref->data);
	ref=ref->next;
	}
}

