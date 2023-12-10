#include<stdio.h>
#define max 5
int q[max],f=-1,r=-1;
void input_restricted();
void output_restricted();
void insert_front();
void insert_rear();
void delete_front();
void delete_rear();
void display();

main()
{
		int ch;
	do
	{
	printf("\n---------Queue Index--------\n");
	printf("1. Input Restricted Queue.\n");
	printf("2. Output Restricted Queue.\n");
	printf("3. Exit\n");
	printf("Enter your choice: ");
	scanf("%d",&ch);
	switch(ch)
		{
		case 1:
			input_restricted();
			break;
		case 2:
			output_restricted();
			break;
		case 3:
			printf("Thank You, to use Ranadeb's Code.\n Have a nice Day..");
		default:
			printf("\nInvalid Choice! try again\n");
		}
	}while(ch!=3);
}

void input_restricted()
{
	int ch;
	do
	{
		printf("\n----Input Restricted Queue----\n");
		printf("1. Insert from Rear\n");
		printf("2. Delete from Front\n");
		printf("3. Delete from rear\n");
		printf("4. Display the Queue.\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_rear();
				break;
			case 2:
				delete_front();
				break;
			case 3:
				delete_rear();
				break;
			case 4:
				display();
				break;
			case 5:
				printf("Thank You, to use Ranadeb's Code.\n Have a nice Day..");
				break();
			default:
				printf("\nInvalid Choice! try again\n");
		}
	}while(ch!=5);
}

void output_restricted()
{
	int ch;
	do
	{
		printf("\n----Output Restricted Queue----\n");
		printf("1. Insert from Front\n");
		printf("2. Insert from Rear\n");
		printf("3. Delete from Front\n");
		printf("4. Display the Queue.\n");
		printf("5. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
				insert_front();
				break;
			case 2:
				insert_rear();
				break;
			case 3:
				delete_front();
				break;
			case 4:
				display();
				break;
			case 5:
				printf("Thank You, to use Ranadeb's Code.\n Have a nice Day..");
				break();
			default:
				printf("\nInvalid Choice! try again\n");
		}
	}while(ch!=5);
}


void insert_front()
{
	int x;
	if((f==0 && r==max-1) || f==r+1)
	{
	printf("Queue is full.\n");
	return;
	}
	printf("\nEnter a Element: ");
	scanf("%d",&x);
	if(f==-1 && r==-1)
	{
		f=0;
		r=0;
		q[f]=x;
		printf("\n%d -- This number is inserted.",x);
	}
	else 
	{
		if(f==0)
		f=max-1;
		else
		f=f-1;
		q[f]=x;		
		printf("\n%d -- This number is inserted.",x);
	}	
}


void insert_rear()
{
	int x;
	if((f==0 && r==max-1) || f==r+1)
	{
	printf("\nQueue is full.\n");
	return;
}
	printf("\nEnter a Element: ");
	scanf("%d",&x);
	if(f==-1 && r==-1)
	{
		f=0;
		r=0;
		q[r]=x;
		printf("\n%d -- This number is inserted.\n",x);
	}
	else 
	{
		if(r==max-1)
		r=0;
		else
		r++;
		q[r]=x;		
		printf("\n%d -- This number is inserted.\n",x);
	}
}


void delete_front()
{
	int x;
	if(f==-1 && r==-1)
	{
	printf("\nQueue is Empty.");
	return;
}
	if(f==max-1)
	{	
		x=q[f];
		f=0;
		printf("\n%d -- This number is Deleted.\n",x);
	}
	else
	{
		if(f==r)
		{
			x=q[f];
			f=-1;
			r=-1;
		}
		else
		{
			x=q[f];
			f++;
		}
		printf("\n%d -- This number is Deleted.\n",x);
	}
}


void delete_rear()
{
	int x;
	if(f==-1 && r==-1)
	{
	printf("\nQueue is Empty.\n");
	return;
}
	if(r==0)
	{	
		x=q[r];
		r=max-1;
		printf("\n%d -- This number is Deleted.\n",x);
	}
	else
	{
		if(f==r)
		{
			x=q[r];
			f=-1;
			r=-1;
		}
		else
		{
			x=q[r];
			r--;
		}
		printf("\n%d -- This number is Deleted.\n",x);
	}
}


void display()
{
	int i,j;
	if (f<=r)
	{
		printf("The Queue is: ");
		for(i=f;i<=r;i++)
		printf("%d  ",q[i]);
	}
	else
	{
		printf("The Queue is: ");
		for(i=f;i<max;i++)
		printf("%d  ",q[i]);
		for(j=0;j<=r;j++)
		printf("%d  ",q[j]);
	}
}
