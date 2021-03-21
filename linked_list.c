#include<stdio.h>
#include<stdlib.h>

#define MAX 10
typedef struct node* Node;

struct node{
	int data;
	Node next;
};
Node my_list;

// For any data structure or ADT we need atleast some operation namely: insert, delete, traverse, search 

//insert
void insertEnd(int data);
void insertStart(int data);
void insertAt(int data,int index);

//delete
void deleteStart(struct node **list);
void deleteEnd();
void deleteAt(struct node **list,int index);


//traverse
void traverse();

//search retrurns the index of the element (first occurence)
int search(Node *list, int data);

//allocate Memory
Node allocateMemory(void);





int main(){
	insertEnd(11);
	insertEnd(21);
	insertEnd(102);
	insertEnd(135);
	insertEnd(14);
	insertEnd(17);
	insertEnd(133);
	insertEnd(711);
	insertEnd(786);
	insertStart(0);
	insertAt(777,2);
	deleteStart(&my_list);
	deleteEnd(&my_list);
	deleteAt(&my_list,3);
	search(&my_list,133);
	return 0;
}


int search(Node *list, int data){
	Node head;
	head = *list;
	int indexCount=0;
	while(head->data != data){
		head=head->next;
		indexCount++;
	}
	printf("\n%d is found at index %d\n",data,indexCount);
	return indexCount;
}

void deleteStart(struct node **list){
	
	if(*list==NULL){
		printf("\nList is empty\n");
		return;
	}
	Node temp = *list;
	*list=(*list)->next;
	free(temp);
	traverse();
}

void deleteEnd(struct node **list){
	if(*list==NULL){
		printf("\nList is empty\n");
		return;
	}
	Node temp=*list;
	Node penultimate;
	while(temp->next){
		penultimate=temp;
		temp=temp->next;
	}
	penultimate->next = NULL;
	free(temp);
	traverse();
	
}

void deleteAt(Node *list,int index){
	if(*list==NULL){
		printf("\nList is empty\n");
		return;
	}
	int indexCount=0;
	Node temp = *list;
	Node prev;
	Node next;
	while(temp && indexCount!=index-1){
		prev=temp;
		temp=temp->next;
		next=temp->next;
		indexCount++;
	}
	prev->next = next;
	free(temp);
	traverse();
}
void insertEnd(int data){
 	Node temp;
	Node new_node = allocateMemory();
		new_node->data=data;
		new_node->next = NULL;
	
	if(!my_list){
		my_list = new_node;
	}
	else{
		temp = my_list;
		while(temp->next){
//			printf("%d",temp->data);
			temp = temp->next;
		}
		temp->next = new_node;
	}
	traverse();
}

void insertStart(int data){
      	Node new_node = allocateMemory();
      	new_node->data = data;
      	new_node->next = NULL;
      	if(!my_list){
      		my_list=new_node;
		  }
		  else{
		  	new_node->next=my_list;
		  	my_list=new_node;
		  }
		  traverse();
}

void insertAt(int data,int index){
	Node new_node = allocateMemory();
	new_node->data = data;
	
	Node headRef = my_list;
	Node prevNode;
	int indexCount=0;
	while(headRef){
		prevNode = headRef;
		headRef = headRef->next;
		if(indexCount==index-1){
			break;
		}
		indexCount++;
	}
	prevNode->next = new_node;
	new_node->next = headRef;
	traverse();
}


	void traverse(){
		printf("\n");
		Node temp = my_list;
		while(temp){
			printf("%d  ",temp->data);
			temp = temp->next;
		}
	}
	
	Node allocateMemory(){
		Node newNode;
		newNode = malloc(sizeof(struct node));
		if(!newNode){
				printf("could not allocate memory");
				exit(1);
		}		
		return newNode;	
	}


