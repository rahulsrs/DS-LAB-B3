#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node node;
node *front=NULL;
node *rear=NULL;
void enqueue(int x){ //To insert elements into the circular queue
	node* ptr;
	ptr=(node*)malloc(sizeof(node));
    if(ptr==NULL){
        printf("ran out of memory");
        return;
    }
	ptr->data=x;
	ptr->next=NULL;//0
	if(rear==NULL && front==NULL)
	{
		front=rear=ptr;
		rear->next=front;
	}
	else
	{
		rear->next=ptr;
		rear=ptr; 
		rear->next=front;
	}
}

void dequeue() //Deletes an element from the queue
{
	node* temp;
	temp=front;
	if(front==NULL && rear==NULL)
	{
		printf("Queue is empty\n");   //checking if queue is empty
	}
	else if(front==rear)
	{
		front=rear=NULL;
		free(temp);
	}
	else
	{
		front=front->next;
		rear->next=front;              
		free(temp);
	}
}

void display() //to print the elements of queue
{
	node* temp;
	temp=front;
	if(front==NULL && rear==NULL)
	{
		printf("\nQueue is empty");
	}
	else
	{
		do
		{
			printf("\n%d",temp->data); //printing all the values
			temp=temp->next;
		}while(temp!=front);
	}
}

int main() //main function
{
	int choice,n;
	
	do             
	{
		printf("\n1.Insertion\n2.deletion\n3.display\n4.exit\n");
		printf("enter your choice\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter your data:\n");
				scanf("%d",&n);
				enqueue(n);
				break;
			case 3:
				display();
				break;
			case 2: dequeue();
				break;
			case 4: exit(0);                
			default:printf("\n invalid");
		}
	}while(choice!=0);
	return 0;
}