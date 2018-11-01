#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100 /*maximum stack size*/
#define M 11
#define P 15
#define ROW M + 2
#define COL P + 2
#define MOVE_COUNT 8

int maze[ROW][COL] = {
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
    {1,0,1,0,0,0,1,1,0,0,0,1,1,1,1,1,1},
    {1,1,0,0,0,1,1,0,1,1,1,0,0,1,1,1,1},
    {1,0,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1},
    {1,1,1,0,1,1,1,1,0,1,1,0,1,1,0,0,1},
    {1,1,1,0,1,0,0,1,0,1,1,1,1,1,1,1,1},
    {1,0,0,1,1,0,1,1,1,0,1,0,0,1,0,1,1},
    {1,0,1,1,1,1,0,0,1,1,1,1,1,1,1,1,1},
    {1,0,0,1,1,0,1,1,0,1,1,1,1,1,0,1,1},
    {1,1,1,0,0,0,1,1,0,1,1,0,0,0,0,0,1},
    {1,0,0,1,1,1,1,1,0,0,0,1,1,1,1,0,1},
    {1,0,1,0,0,1,1,1,1,1,0,1,1,1,1,0,1},
    {1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
};

int mark[ROW][COL];
typedef struct {
    short int row;
    short int col;
    short int dir;
} element;

typedef struct {
    short int vert;
    short int horiz;
} offsets;
offsets moves[MOVE_COUNT] = {
    {-1, 0}, // N
    {-1, 1}, // NE
    {0, 1},  // E
    {1, 1},  // SE
    {1, 0},  // S
    {1, -1}  // SW
    {0, -1}  // W
    {-1, -1} // NW
}; /*array of moves for each direction*/



element *stack[MAX_STACK_SIZE];
int top = -1;
int isEmpty() {

   if(top == -1)
      return 1;
   else
      return 0;
}

int isFull() {

   if(top == MAX_STACK_SIZE)
      return 1;
   else
      return 0;
}

int peek() {
   return  stack[top];
}
int pop() {


   if(!isEmpty()) {

      top = top - 1;

   } else {
      printf("Could not retrieve data, Stack is empty.\n");
   }
}

void push(int row, int col, int dir) {

    if(!isFull()) {
        top = top + 1;
        stack[top].row = row;
        stack[top].col = col;
        stack[top].dir = dir;
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

void deepCopyMazeToMark() {
    int i,j;
    for(i = 0; i < ROW; i++) {
        for(j = 0; j < COL; j++) {
            mark[i][j] = maze[i][j];
        }
    }
}

int isExit(int currRow, int currCol) {
    return currRow == M && currCol == P;
}

int canMove(int currRow, int currCol) {
    return mave[currRow][currCol] == 0 && mark[currRow][currCol] == 0;
}

int solveMaze() {
    element current;
    offsets move;
    int dir, nextRow, nextCol;
    //initialize a stack to the maze's entrance coordinates
    //and direction to north;
    while (!isEmpty()) {
        //move to position at top of stack
        current = pop();

        for(dir = 0; dir < MOVE_COUNT; dir++) {
            move = moves[dir];

            nextRow = current.row + move.row;
            nextCol = current.col + move.col;

            if(isExit(nextRow, nextCol)) {
                return 1;
            } else if (canMove(nextRow, nextCol)) {
                //legal move and haven't been there
                mark[nextRow][nextCol] = 1;
                push(nextRow, nextCol, dir);
            }
        } 
    }
    printf("No path found\n");
    return 0;
}


int main()
{
    int result;

    deepCopyMazeToMark();
    result = solveMaze();
    if (result) {
        printf("Solved\n");
    }
    return 0;
}
