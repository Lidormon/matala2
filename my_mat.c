#define SIZE 10
#include <stdio.h>
int a_func(int x);
int b_func(int col, int row);
int c_func(int col, int row);
int save_mat[SIZE][SIZE]; // 
//------------------------------------
int min(int left, int right)
{
    if (left == 0 && right != 0)  // becuse is say that not have path in left side and in the right side have, so take the weight of the right side
        return right;
    if (left != 0 && right == 0)  
        return left;

    if (left <= right)
        return left;
    else
        return right;
}
int a_func(int x)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            scanf("%d", &save_mat[i][j]);
        }
    }
    // for (int i = 0; i < SIZE; i++)
    // {
    //     for (int j = 0; j < SIZE; j++)
    //     {
    //         printf("%d\t", save_mat[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}

int b_func(int col, int row)
{
    int mat[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            mat[i][j] = save_mat[i][j]; // mat[i][j] represent the weight min path from i to j
        }
    }
    for (int k = 0; k < SIZE; k++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {
                int a, b, c;
                // a < > =  b+c
                a = mat[i][j];
                b = mat[i][k];
                c = mat[k][j];
                int flag = 1;
                if (b == 0 || c == 0)
                {
                    if (a == 0) 
                    {
                        mat[i][j] = 0; // because this mean that no path (when the mi path equal to 0)
                        flag = 0;
                    }
                    else               // a != 0 and (b==0 or c==0)  because is dont sence that have path from i to j and not from i to k or k to j because they part of the path i to j
                    {

                        flag = 0;     
                    }
                }
                if (i == j)         
                    mat[i][j] = 0;   // because have not path with weight from node to himself
                else if (flag == 1)
                {
                    mat[i][j] = min(a, b + c);
                }
            }
        }
    }
    if (mat[col][row] != 0)
        return printf("True\n");
    else
        return printf("False\n");
}

int c_func(int col, int row)
{
    int mat[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            mat[i][j] = save_mat[i][j];
        }
    }

    for (int k = 0; k < SIZE; k++)
    {
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++)
            {

                int a, b, c;
                // a < > =  b+c
                a = mat[i][j];
                b = mat[i][k];
                c = mat[k][j];
                int flag = 1;
                if (b == 0 || c == 0)
                {
                    if (a == 0)
                    {
                        mat[i][j] = 0;
                        flag = 0;
                    }
                    else
                    {
                        flag = 0;
                    }
                }
                if (i == j)
                    mat[i][j] = 0;
                else if (flag == 1)
                {
                    mat[i][j] = min(a, b + c);
                }
            }
        }
    }

    if (mat[col][row] != 0)
        return mat[col][row];
    else
        return -1;
}
