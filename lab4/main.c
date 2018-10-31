#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100 /*maximum stack size*/
typedef struct n{
short int row;
short int col;
short int dir;
} element;
element *stack[MAX_STACK_SIZE];
int top = -1;
int isempty() {

   if(top == -1)
      return 1;
   else
      return 0;
}

int isfull() {

   if(top == MAX_STACK_SIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return  stack[top];
}
int pop() {


   if(!isempty()) {

      top = top - 1;

   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

void push(int data) {

   if(!isfull()) {
      top = top + 1;
     stack[top] = data;
   } else {
      printf("Could not insert data, Stack is full.\n");
   }
}
void display ()
{
    int i;
    if (top == -1)
    {
        printf ("Stack is empty\n");
        return;
    }
    else
    {
        printf ("\n The status of the stack is \n");
        for (i = top; i >= 0; i--)
        {
            printf ("%d\n", stack[i]);
        }
    }
    printf ("\n");
}
int main()
{
push(1);
push(2);
display();
    return 0;
}
