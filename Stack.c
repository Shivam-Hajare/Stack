#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

int num;
struct node* top;

void push();
void pop();
void display();

void main()
{
	int ch;

	while (1)
	{
		display();

		printf("\n1.push \n2.pop\n3.display\n4.Exit ");

		printf("Enter choice : ");
		scanf("%d", &ch);

		switch (ch)
		{
		case 1:
			push();
			break;

		case 2:
			pop();
			break;

		case 3:
			display();
			break;

		case 4:
			exit(0);

		default:
			printf("\nInvalid choice...");
			break;
		}
	}
	
}
void push()
{
	struct node* r;
	r = (struct node*)malloc(sizeof(struct node));

	printf("Enter data : ");
	scanf("%d", &num);

	if (top == NULL)
	{
		r->data = num;
		r->next = NULL;
		top = r;
	}
	else
	{
		r->data = num;
		r->next = top;
		top = r;
	}

}
void pop()
{
	struct node* q;
	q = top;

	if (top == NULL)
	{
		printf("\nStack is under flow...");
		return;
	}
	else
	{
		top = top->next;
		free(q);
	}
}
void display()
{
	struct node* q;
	q = top;

	if (top == NULL)
	{
		printf("\nStack is under flow...");
		return;
	}
	else
	{
		printf("[ ");
		while (q != NULL)
		{

			printf("%d", q->data);
			if (q->next != NULL)
			{
				printf(", ");
			}
			q = q->next;
		}
		printf(" ]\n ");

	}
}