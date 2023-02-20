#include<stdio.h>
#include<stdlib.h>
#define max 100
int front=-1,rear=-1;
int queue[max];          
void enqueue()          
{
	int item;
	printf("Enter the element\n"); //Inserting an element
	scanf("%d",&item);
	if(rear==max-1) 
	{
		printf("overflow\n");
		return;
	}
	if(front==-1&&rear==-1) 
	{
		front=0;
		rear=0;
	}
	else  
	{
		rear=rear+1; 
	}
	queue[rear]=item;
	printf("Value inserted\n"); 
}
void dequeue() // to delete an element from the queue
{
	int item;
	if(front==-1||front>rear) 
	{
		printf("underflow\n");
		return;
	}
	else
	{
		item=queue[front];
		if(front==rear) 
		{
			front=-1; 
			rear=-1;
		}
		else 
		{
			front=front+1; 
		}
		printf("Value deleted\n");
	}
}
void display()//displays all the elements
{
	int i;
	if(rear==-1)
	{
		printf("Empty queue\n");
	}
	else
	{
		printf("The values are:\n");
		for(i=front;i<=rear;i++)
		{
			printf("%d\n",queue[i]);
		}
	}
}
int main()//main function
{
  	int choice;
  	while(1)
  	{
   		printf("Select the operation:\n");
    		printf("1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\n"); 
    		scanf("%d",&choice);
    		switch(choice)
    		{
      		case 1: enqueue();
      		break;
      		case 2: dequeue();
              	break;
      		case 3: display();
              	break;
      		case 4: exit(0);
      		default: printf("Invalid choice\n");
              	break;
     	}   
   	}
  	return 0;
} 