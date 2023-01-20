	#include<stdio.h>
	#include<stdlib.h>
	#define max 50
	void insert();
	void delete();
	void display();
	int front=-1,rear=-1;
	int queue[max];         
	void enqueue(ele)          // function to insert element in the queue
	{
		if(rear==max-1) //Checking if queue is full
		{
			printf("overflow\n");
			return;
		}
		if(front==-1&&rear==-1) //Checking if queue is empty
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
	void dequeue() // Function to delete an element from the queue
	{
		int ele;
		if(front==-1) //Checking if the queue is empty
			printf("underflow\n");
			return;
		}
		else
		{
			ele=queue[front];  
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
	void display()  //Function to display all the elements in the queue
	{
		int i;
		if(rear==-1) //Checking if queue is empty
		{
			printf("Empty queue\n");
		}
		else
		{
			printf("Printing values:\n");
			for(i=front;i<=rear;i++) 
			{
				printf("%d\n",queue[i]);
			}
		}
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
		  			int item;
					printf("Enter the element\n"); 
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








