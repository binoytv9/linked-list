/*	Write an InsertSort() function which given a list, rearranges its nodes so they are sorted in
 *	increasing order. It should use SortedInsert().
 */

#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *build(void);
void print(struct node *head);
struct node *createnode(int data);
void insertsort(struct node **headref);
struct node *copynode(struct node *source);
void sortedinsert(struct node **headref,struct node *newnode);

main()
{
	int data;
	struct node *newnode,*head;

	head=build();

	print(head);
	insertsort(&head);
	print(head);
}

void insertsort(struct node **headref)				/* accept a unsorted list and returns a sorted list in ascending order */
{
	struct node *current,*sortlist,*newnode;

	sortlist=NULL;
	current=*headref;

	while(current!=NULL){
		newnode=copynode(current);
		sortedinsert(&sortlist,newnode);
		current=current->next;
	}

	*headref=sortlist;
}

struct node *copynode(struct node *source)			/* to duplicate a node */
{
	struct node *newnode=malloc(sizeof(*newnode));

	newnode->data=source->data;
	newnode->next=NULL;

	return newnode;
}

void sortedinsert(struct node **headref,struct node *newnode)	/* to insert node in a ascending order */
{
	struct node *current,*prev_node;

	current=*headref;
	prev_node=NULL;

	while(current!=NULL){
		if(current->data > newnode->data)
			break;
		prev_node=current;
		current=current->next;
	}

	if(prev_node == NULL){					/* if at head position */
			newnode->next=*headref;
			*headref=newnode;
	}
	else{							/* else where */
		newnode->next = current;
		prev_node->next = newnode;
	}
}


struct node *build(void)
{
	struct node *head=malloc(sizeof(*head));

	head->data=3;
	head->next=malloc(sizeof(*head));
	head->next->data=2;
	head->next->next=malloc(sizeof(*head));
	head->next->next->data=4;
	head->next->next->next=malloc(sizeof(*head));
	head->next->next->next->data=1;
	head->next->next->next->next=NULL;

	return head;
}

struct node *createnode(int data)				/* to create a new node */
{
	struct node *new=malloc(sizeof(*new));

	new->data=data;
	new->next=NULL;

	return new;
}

void print(struct node *head)					/* print the list */
{
	struct node *current=head;

	if(current==NULL){
		printf("\n\t\t<empty>\n\n");
		return;
	}


	printf("\n\n");
	while(current!=NULL){
		printf("\t%d",current->data);
		current=current->next;
	}
	printf("\n\n");
}
