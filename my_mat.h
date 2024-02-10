
#ifndef UNTITLED2_MY_MAT_H
#define UNTITLED2_MY_MAT_H
#define SIZE 10

void initMatrix(int mat[SIZE][SIZE]);

int thereIsPath(int mat[SIZE][SIZE], int i ,int j);

int hasPath(int mat[SIZE][SIZE], int start ,int end, int check[SIZE]);

int shortestPath(int mat[SIZE][SIZE], int i ,int j);


#endif //UNTITLED2_MY_MAT_H
