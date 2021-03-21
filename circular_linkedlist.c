/*
circular linked list (CLL): there is no node with NULL pointer in CLL. CLLs are used in algorithms like round robin
scheduling. 
In CLL the list is fully traversed when you start from head and come back to head
*/

#include<stdio.h>
#include<stdlib.h>

#define EMPTY_LIST "List is empty!"
#define print(a) printf("%d  ",a)
#define sprint(str) printf("%s",str)
typedef struct node* CLLNode;

struct node{
	int data;
	CLLNode next;
};

int listlen(CLLNode *list);
void traverse(CLLNode *list);

CLLNode createNode(int data);
//insert 
void insert(CLLNode *list,int data, int index);

//delete
int delete(CLLNode *list,int index);

//search

CLLNode createNode(int data){
	CLLNode newNode = malloc(sizeof(struct node));
	if(!newNode){
		printf("Out of Memory");
		return;
	}
	newNode->data = data;
	newNode->next = NULL;
	return newNode;
}


int main(){
	CLLNode list=NULL;
	insert(&list,10,1);
	insert(&list,11,2);
	insert(&list,12,3);
    insert(&list,13,4);
    insert(&list,17,5);
    sprint("\nCLL length: ");
	print(listlen(&list));
	delete(&list,1);
	delete(&list,1);
	delete(&list,1);
	delete(&list,1);
	delete(&list,1); //list should be null
	delete(&list,1);
	delete(&list,1);
	delete(&list,1);
	insert(&list,10,1);
	insert(&list,11,2);
	insert(&list,12,3);
    insert(&list,13,4);
	return 0;
}

int delete(CLLNode *list,int index){
    CLLNode prev,ref = *list;
    CLLNode tail,head;
    int data,indexCount,len;
    if(!ref){
        printf("\nEmptyListException\a");
        return -1;
    }
    if(index>listlen(list) || index <=0){
        sprint("\nOut Of Bound!");
        exit(1);
    }
    else if(index==1){
      head = *list;
        if(listlen(list)==1){        
            data = head->data;
            free(head)  ;
            *list = NULL;
            printf("\n%d deleted",data);
        }
        else{
              do{
                  tail = ref;
              }while((ref=ref->next)!=head);
              data = head->data;
              *list = head->next;
              tail->next = *list;
              free(head);
              printf("\n%d deleted",data);
        }
    }
    else{
        indexCount = 1;
        while(indexCount++!=index-1){
            prev=ref;
            ref=ref->next;
        }
        data = ref->data;
        prev->next = ref->next;
        free(ref);
        printf("\n%d deleted",data);
    }
    traverse(list);
    return data;
}


void insert(CLLNode *list,int data, int index){
	CLLNode newNode,ref,tail;
	int len,indexCount=1;;
	newNode = createNode(data);
	if(!*list){
	    sprint("\ncreating list");
		newNode->next=newNode;
		*list = newNode;
		printf("\n%d inserted",data);
	}
	else{
		if(index==1){
			ref = *list;
			newNode->next = ref;
			*list=newNode;
			printf("\n%d inserted",data);
		}
		else{
    		len = listlen(list);
    		if(index > len+1){
    			printf("\nInvalid Index\n");
    			exit(1);
    		}
    		else{
    			ref = *list;
    			while(indexCount!=index-1){
    				ref = ref->next;
    				indexCount++;
    		    }
    			newNode->next = ref->next;
    			ref->next = newNode;	
    			printf("\n%d inserted",data);
		    }
	    }
	}
	traverse(list);
}

int listlen(CLLNode *list){
	CLLNode ref = *list;
	CLLNode head = *list;
	
	int len=0;
	if(!ref){
		printf("list is empty");
		return 0;
	}
	else if(ref->next == ref){
		return 1;
	}
	else{
		do{
			++len;
			ref = ref->next;
		}while(ref!=head);
		return len;
	}
}

void traverse(CLLNode *list){
    sprint("\ntraverse\t");
    CLLNode head = *list;
    CLLNode ref = *list;
    if(*list){
        do{
            print(ref->data);
            ref=ref->next;
        }while(ref!=head);
    }
    else{
        sprint("\nList is empty!");
    } 
}
