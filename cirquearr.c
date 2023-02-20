//implementation of circular queue using array
#include<stdio.h>
#include<stdlib.h>
#define size 5
int queue[size];
int front=-1;  
int rear=-1;
void enqueue(int x)  //Inserting value into queue
{
	if(front==-1 && rear==-1) 
	{
		front=rear=0;
		queue[rear]=x; 
	}
	else if((rear+1)%size==front)
	{
		printf("Queue overflow");	
	}
	else
	{
		rear=(rear+1)%size;
		queue[rear]=x;
	}
} 

int dequeue() //function to delete elenent from queue
{
	if(front==-1 && rear==-1) 
	{
		printf("Queue overflow");
	}
	else if(front==rear) 
	{
		printf("deleted element is%d\n",queue[front]);
		front=rear=-1; 
	}
	else
	{
		printf("deleted element is %d\n",queue[front]);
		front=(front+1)%size; 
	}
}

void display() //displays the queue
{
	int i=front;
	if(front==-1 && rear==-1)
	{
		printf("Queue is empty");
	}
	else
	{
		printf("elements in queue are:\n");
		while(i<=rear)
		{
			printf("%d\n",queue[i]);
			i=(i+1)%size;
		}
	}
}

int main() //main function
{
	int choice,data;
	while(1)
	{
		printf("enter your choice\n");
		printf("1.enqueue\n2.dequeue\n3.display\n4.exit\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
			        printf("Enter the value to be inserted\n");
			        scanf("%d",&data);
			        enqueue(data);
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
			        printf("invalid\n");							
		}		
	}
}