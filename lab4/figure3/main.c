#include <stdio.h>
#include <stdlib.h>

int main()
{
    //initialize a stack to the maze's entrance coordinates
    //and direction to north;
    while (stack is not empty){
        //move to position at top of stack
        <row,col,dir> = delete from top of stack;
        while(there are more moves from current position){
            <next_row,next_col> =coordinates of next move;
            dir = direction of move;
            if((next_row == EXIT_COL)&&(next-col == EXIT_COL))
                success;
            if(maze[next_row][next_col] == 0 && mark[next_row][next_col] == 0) {

                //legal move and haven't been there
                mark[next_row][next_col] = 1;
                //save current position and direction
                add <row,col,dir>to the top of the stack;
                row = next_row;
                col = next-col;
                dir = north;

            }



        }
    }
    printf{"No path found\n"};
        return 0;
}
