#include <stdio.h>
#include <stdlib.h>

struct node{
	int val;
	struct node *next;
};
typedef struct node node;	
node *front=NULL, *rear=NULL;

void enqueue(int ele){   //function to insert a new node in the queue 
	node *ptr= (node*)malloc(sizeof(node));
	if(ptr==NULL){	
		printf("err: ran out of memory");
		return;
	}
	ptr->val=ele;
	ptr->next=front;
	if(front==NULL){	//Checking if queue is empty
		front=ptr;			
		rear=ptr;
		rear->next=front;
	}
	else{
		rear->next=ptr;
		rear=ptr;
		rear->next=front;
	}
}

int dequeue(){	//Function to delete element in the queue
	int ele;
	if(front==NULL){	//Checking if queue is empty;
		printf("queue is empty\n");
		return 0;	
		}		
	if(front==rear && front!=NULL){
		ele= front->val;
		front=NULL;
		rear=NULL;
		return ele;
	}
	else{
		ele= front->val;
		front=front->next;
		return ele;
	}

}


void display(){
	if(front==NULL){	//Checking if queue is empty;
		printf("queue is empty\n");
		return;
		}
	node*temp=front;
	printf("the elements are \n");
	do{
		printf("%d\n",temp->val);
		temp=temp->next;
		}
	while(temp!=front);
	
}

int main()		//Driver code
	{
	  	int choice;
	  	while(1)
	  	{
	   		printf("Select the operation:\n");			//code for the cli
				printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n"); 
				scanf("%d",&choice);
				switch(choice)
				{
		  		case 1:
		  			printf("Enter the element\n");
		  			int item=0; 
					scanf("%d",&item); 
			  		enqueue(item);
			  		break;
		  		case 2: 
		  			dequeue();
		          	break;
		  		case 3:
		  			display();
		          	break;
		  		case 4: 
		  			exit(0);
		  		default: 
		  			printf("Invalid choice\n");
		          	break;
		 	}   
	   	}
	  	return 0;
	} 
