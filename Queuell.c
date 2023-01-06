	#include <stdio.h>
	#include <stdlib.h>
	struct node{
		int val;
		struct node *next;
	};
	typedef struct node node;
	node *front, *rear;


	void enqueue(int ele){
		node *ptr;
		ptr=(node*)malloc(sizeof(node));
		if(ptr==NULL)
			printf("overflow");
		else{
			ptr->val=ele;
			if(front==NULL){
				front=ptr;
				rear=ptr;
				front->next=NULL;
				rear->next=NULL;
			}
			else{
				rear->next=ptr;
				rear=ptr;
				rear->next=NULL;
			}
		}
	}
	int dequeue(){
		node *ptr;
		if(ptr==NULL){
			printf("underflow");
			return -1;
		 }
		else{
			int ele=front->val;
			ptr=front;
			front=front->next;
			free(front);
			return ele;
		}
		}
		
	void display(){
		node *temp;
		temp=front;
		if(temp==NULL){
			printf("underflow");
			return;
		 }
		else{
			while(temp!=NULL){
				printf("\n%d",temp->val);
				temp=temp->next;
				}
				printf("\n");
			}
		
	}
	int main(){
		int choice;
		while(1){
			printf("enter your choice \n1)enqueue \n2)dequeue \n3)Display \n4)Exit \n");
			scanf("%d",&choice);
			switch(choice){
				case 1:
					printf("enter the value you want to push ");
					int ele;
					scanf("%d",&ele);
					enqueue(ele);
					break;
				case 2:
					printf("the popped element was %d\n	",dequeue());
					break;
				case 3:
					display();
					break;
				case 4:
					exit(1);
					break;
				default:
					printf("invalid");
			}
		}	
	}



