#include "my_mat.h"
#include <stdio.h>

#define True 1
#define False 0
#define SIZE 10

int main() {
    int mat[SIZE][SIZE];

    //current option(A,B,C,D)
    char current;

    //keep going as long current is not D
    int keepGoing=True;

    while (keepGoing==True)
    {
        printf("select A,B,C,D");
        scanf(" %c", &current);
        //if the user pressed A we will init the matrix
        if(current=='A')
        {
            initMatrix(mat);
        }
        // if the user pressed B we will check if there is a path between 2 nodes
        else if(current=='B')
        {
            int i, j;
            scanf("%d %d", &i, &j);
            int ans= thereIsPath(mat,i,j);
            if(ans==True)
            {
                printf("True\n");
            }
            else
            {
                printf("False\n");
            }
        }
            // if the user pressed B we will check the shortest path between 2 nodes (if existing)
        else if(current=='C')
        {
            int i, j;
            scanf("%d %d", &i, &j);
            int ans= shortestPath(mat,i,j);
            printf("%d\n",ans);
        }
        // if the user pressed B we will exit
        else if(current=='D')
        {
            keepGoing=False;
        }

    }

    return 0;
}