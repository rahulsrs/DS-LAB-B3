#include<stdio.h>
#include<stdlib.h>

struct node 
{
	int data;
	struct node *next;
};
struct node *head;

void beginsert()//function to insert element at the begining
{
	struct node *ptr;
	int item;
	ptr=(struct node *)malloc(sizeof(struct node *));
	if(ptr==NULL)
	{
		printf("Overflow\n");
	}
	else
	{
		printf("Enter Value:");
		scanf("%d",&item);
		ptr->data=item;
		ptr->next=head;
		head=ptr;
		printf("Node Inserted\n");
	}
}

void lstinsert()//function to insert element at the last
{
	struct node *ptr,*temp;
	int item;
	ptr=(struct node *)malloc(sizeof(struct node *));
	if(ptr==NULL)
	{
		printf("OverFlow\n");
	}
	else
	{
		printf("Enter Value:");
		scanf("%d",&item);
		ptr->data=item;
		if(head==NULL)
		{
			ptr->next=NULL;
			head=ptr;
			printf("Node Inserted\n");
		}
		else
		{
			temp=head;
			while(temp->next!=NULL)
			{
				temp=temp->next;
			}
			temp->next=ptr;
			ptr->next=NULL;
			printf("Node Inserted\n");
		}  
	}
}
     
void randinsert()//function to insert element at the desired location
{
	struct node *ptr,*temp;
	int item,loc,i;
	ptr=(struct node *)malloc(sizeof(struct node *));  
	if(ptr==NULL)
	{
		printf("Overflow");
	}
	else
	{
		printf("Enter Value:");
		scanf("%d",&item);
		ptr->data=item;
		printf("\nEnter the location after which you want to insert\n");
		scanf("%d",&loc);
		temp=head;
		for(i=0;i<loc;i++)
		{
			temp=temp->next;
			if(temp==NULL)
			{
				printf("Cant Insert\n");
				return;
			}    
		}
		ptr->next=temp->next;
		temp->next=ptr;
		printf("Node inserted\n");
	}     
}

void begdelete()//function to delete element at the begining
{
	struct node *ptr,*ptr1;
	if(head==NULL)
	{
		printf("List is Empty\n");
	}
	else
	{
		ptr=head;
		head=ptr->next;
		free(ptr);
		printf("Node Deleted from beginning\n");
	}
}

void lstdelete()//function to delete element at the last
{
	struct node *ptr,*ptr1;
	if(head==NULL)
	{
		printf("List is Empty\n");
	}
	else if(head->next==NULL)
	{
		head=NULL;
		free(head);
		printf("Node deleted\n");
	}
	else
	{
		ptr=head;
		while(ptr->next!=NULL)
		{
			ptr1=ptr;
			ptr=ptr->next;
		}
		ptr1->next=NULL;
		free(ptr);
		printf("Deleted node from the last\n");
	}       
}    

void randdelete()//function to delete element at the desired location
{
	struct node *ptr,*ptr1;
	int loc,i;
	printf("Enter the location of the node after which it has to be deleted\n");
	scanf("%d",&loc);
	ptr=head;
	for(i=0;i<loc;i++)
	{
		ptr1=ptr;
		ptr=ptr->next;
		if(ptr==NULL)
		{
			printf("deletion isn't possible \n");
			return;
		}
	}
	ptr1->next=ptr->next;
	free(ptr);
	printf("Delete Node %d ",loc+1);
}

void display()//function to display elements of the ll
{
	if(head==NULL)
	{
		printf("Linked List is Empty\n");
		return;
	}
	printf("LinkedList: ");
	struct node* ptr = head;
	while(ptr!=NULL)    
	{
		printf("%d ",ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int main()//main function
{
	int choice;
	while(1)
	{
		printf("Operation performed by Linked Lists:\n");
		printf("1.Insert at Begin\n2.Insert at Last\n3.Insert at Random\n4.Delete at Begin\n5.Delete at Last\n6.Delete at random\n7.Display\n8.Exit\n");
		printf("Enter Your Choice\n");
		scanf("%d",&choice);//to take operation input from user
		switch(choice)
		{
			case 1: beginsert();
			break;
			case 2: lstinsert();
			break;
			case 3: randinsert();
			break;                
			case 4: begdelete();
			break;
			case 5: lstdelete();
			break;
			case 6: randdelete();
			break;                
			case 7: display();
			break;
			case 8: exit(0);
			default: printf("Invalid Choice\n");
		}
	}                             
}