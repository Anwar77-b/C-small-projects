#include <iostream>
#include <cstdlib>

using namespace std;

int calcDet(int mat2[], int size)
{
    int mat[size][size];
    int y = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mat[i][j] = mat2[y];
            y++;
        }
    }
    if (size == 2)
    {
        return (mat[0][0] * mat[1][1]) - (mat[1][0] * mat[0][1]);
    }
    else
    {
        int resault = 0;
        for (int j = 0; j < size; j++)
        {
            int mat1[size - 1][size - 1];
            for (int ii = 1; ii < size; ii++)
            {
                int k = 0;
                for (int jj = 0; jj < size; jj++)
                {
                    if (jj == j)
                    {
                        continue;
                    }
                    else
                    {
                        mat1[ii - 1][k] = mat[ii][jj];
                        k++;
                    }
                }
            }
            int mat11[(size - 1) * (size - 1)];
            int yyy = 0;
            for (int i = 0; i < size - 1; i++)
            {
                for (int j = 0; j < size - 1; j++)
                {
                    mat11[yyy] = mat1[i][j];
                    yyy++;
                }
            }
            int p = 1;
            if (j % 2 != 0)
            {
                p = -1;
            }
            resault += mat[0][j] * p * calcDet(mat11, size - 1);
        }
        return resault;
    }
}
void adjMat(int mat2[], int size)
{
    int mat[size][size];
    int y = 0;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            mat[i][j] = mat2[y];
            y++;
        }
    }
    int resault[size][size];
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            int smallerMat[(size - 1) * (size - 1)];
            int ii = 0;
            for (int iii = 0; iii < size; iii++)
            {
                for (int jjj = 0; jjj < size; jjj++)
                {
                    if (iii != i && jjj != j)
                    {
                        smallerMat[ii] = mat[iii][jjj];
                        ii++;
                    }
                }
            }


            int p = 1;
            if ((i + j) % 2 == 1)
            {
                p = -1;
            }
            resault[i][j] = p * calcDet(smallerMat, size - 1);
        }
    }
    cout << " ########### " << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << resault[i][j] << " ";
        }
        cout << "\n";
    }
    cout << " ########### " << endl;
}

int main()
{
    int mattt[]= {1,2,3,4,7,-1,2,0,4};
    adjMat(mattt, 3);
    return 0;
}