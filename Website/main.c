#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "Stacklink.h"

Stack createStack() // create stack
{
	Stack s;
	s = (Stack) malloc (sizeof(Stack_Head));
	s->count = 0;
	s->top = NULL; 
	return s;
}

nodeptr createNode(char item) // create node for link list
{
	nodeptr ptr;
	ptr = (nodeptr) malloc (sizeof(Stack_Node));
	ptr->data = item;
	ptr->next = NULL; 
	return ptr;
}

void push(Stack s,char item) // insert to the top of stack
{
	nodeptr temp = createNode(item);
	temp->next = s->top;
	s->top = temp;
	s->count++;	
}

void pop(Stack s) // delete the top of stack
{
	nodeptr temp;
	temp = s->top;
	s->top = temp->next;
	temp->next = NULL;
	free(temp);
	s->count--;	
}

char stackTop(Stack s) // returns the top of stack
{
	nodeptr temp;
	temp = s->top;
	return temp->data;
}

int isEmpty(Stack s) // returns 1 if empty else 0
{
	if(s->count==0)
		return 1;
	else
		return 0;
}

void display(Stack s) // display stack
{
	if(isEmpty(s)==1)
	{
		printf("\n-----[STACK IS EMPTY]-----\n");
		getch();
	}
	else{
		nodeptr ptr;
		ptr = s->top;
		printf("\nStack(Top-Bottom): \n");
		while(ptr!=NULL)
		{
			printf("%c ", ptr->data);
			ptr = ptr->next;
			printf("\n");
		}
	}
}

void push_or_pop(Stack s,char string[]) // determine if push or pop	
{		
	// also display stack & progress to track symbol matching
	for(int x =0 ; string[x]!='\0'; x++)
	{
		if(string[x] == '('||string[x] == '{'||string[x] == '[')
			push(s,string[x]);	
		else if(string[x] == ')')
		{
			display(s);
			printf("\nTop of the stack: %c vs string[%d]: %c\n",stackTop(s),x,string[x]);
			if(stackTop(s)=='(')
			{
				printf("%c matches %c so pop stack\n", stackTop(s), string[x]);
				printf("%c is popped\n", stackTop(s));
				pop(s);
			}
			else
				printf("%c is mismatched with %c\n", stackTop(s), string[x]);
		}
		else if(string[x] == '}')
		{
			display(s);
			printf("\nTop of the stack: %c vs string[%d]: %c\n",stackTop(s),x,string[x]);
			if(stackTop(s)=='{')
			{
				printf("%c matches %c so pop stack\n", stackTop(s), string[x]);
				printf("%c is popped\n", stackTop(s));
				pop(s);
			}
			else
				printf("%c is mismatched with %c\n", stackTop(s), string[x]);
		}
		else if(string[x] == ']')
		{
			display(s);
			printf("\nTop of the stack: %c vs string[%d]: %c\n",stackTop(s),x,string[x]);
			if(stackTop(s)=='[')
			{
				printf("%c matches %c so pop stack\n", stackTop(s), string[x]);
				printf("%c is popped\n", stackTop(s));
				pop(s);
			}
			else
				printf("%c is mismatched with %c\n", stackTop(s), string[x]);
		}
		else
		{
			printf("%c is not a balance symbol\n",string[x]);
		}
	}
}