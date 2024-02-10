#include "my_mat.h"
#include <stdio.h>
#include <limits.h>
#define True 1
#define False 0
#define SIZE 10


void initMatrix(int mat[SIZE][SIZE])
{
    int i=0;
    int j=0;
    for(i=0;i<SIZE;i++)
    {
        for(j=0;j<SIZE;j++)
        {
            scanf("%d", &mat[i][j]);
        }
    }
}

int thereIsPath(int mat[SIZE][SIZE], int i ,int j)
{
    //here we check if we are trying get to the same node
   if(i==j)
   {
       return False;
   }
   //we check if there is a directed path between the 2 nodes
   if(mat[i][j]!=0)
  {
      return True;
  }

    //declaring an array that will help us know which nodes we checked (init unvisited nodes to 0 like we init unvisited nodes to white in dfs)
    int check[SIZE] = {0};
  //calling recursive function that will help us know if there is a path between the 2 nodes
    return hasPath(mat,i,j,check);

}

int hasPath(int mat[SIZE][SIZE],int start ,int end, int check[SIZE])
{

    //check to see if we reached the final node
    if (start == end) {
        return True;
    }
    //we will make the current node visited (like changing it to black in dfs)
    *(check+start)=1;  //like we write check[start]=1;
    int i=0;
    //here we check all the nodes adjusted to our node
    for (i=0; i<SIZE; i++) {
        //check if we didn't already check the node and there is a path between the start node and the current one
        if (mat[start][i] != 0 && !check[i]) {
            //if the condition is true we keep on going from the current node till the end and return the answer
            if (hasPath(mat, i, end,check)) {
                return True;
            }
        }
    }
    return False;
}

//implemented with the help of using the Floyd-Warshall algorithm

int shortestPath(int mat[SIZE][SIZE], int i ,int j)
{
    //first we check if there is path between the 2 nodes
    int ans= thereIsPath(mat,i,j);
    if(ans==False)
    {
        return -1;
    }

    //now we will make a new matrix that holds shortest paths (init to infinity)
    int shotestMat[SIZE][SIZE];
    int x=0;
    int y=0;
    for (x=0; x<SIZE; x++) {
        for (y=0; y<SIZE; y++) {
            shotestMat[x][y] = INT_MAX;
        }
    }

    // every directed path should replace the infinity
    for (x=0; x<SIZE; x++) {
        for (y=0; y<SIZE; y++) {
            //if there is directed path
            if (mat[x][y]!=0) {
                shotestMat[x][y]=mat[x][y];
            }
        }
    }
    // Floyd-Warshall algorithm
    int k=0;
    for (x=0; x<SIZE; x++) {
        for (y=0; y<SIZE; y++) {
            for (k=0; k<SIZE; k++) {
                if ((shotestMat[x][y]!=INT_MAX) && (shotestMat[y][k]!=INT_MAX) && (shotestMat[x][y]+shotestMat[y][k]<shotestMat[x][k]))
                {
                    shotestMat[x][k]=shotestMat[x][y]+shotestMat[y][k];
                }
            }
        }
    }
    // return the shortest path we found
    if(shotestMat[i][j]<shotestMat[j][i]) {
        return shotestMat[i][j];
    }
    else
    {
        return shotestMat[j][i];
    }
}

