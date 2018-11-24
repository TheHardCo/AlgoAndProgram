#include <stdio.h>

void SortMatrix(int array[][10], int n);
void PrintMatrix(int array[][10], int n);

int main()
{
    int arr[10][10];
    int n;
    
    do
    {
    printf("Enter the size of matrix: \n");
    scanf("%d", &n);
    }
    while((n < 0)||(n > 10));
    
    printf("Enter your string of numbers: ");

        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                scanf("%d", &arr[i][j]);           //scan string as an elements
            }
        }

    printf("Entered matrix:\t\n");
    PrintMatrix(arr, n);                      //function call 

    SortMatrix(arr, n);
    printf("Sorted matrix:\t\n");
    PrintMatrix(arr, n);
  
    return 0;
}

void SortMatrix(int array[][10], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n-1; ++j)
        {
            if (array[j][0] > array[j + 1][0])
            {
                for (int k = 0; k < n; ++k)        
                {
                    int tmp = array[j][k];
                    array[j][k] = array[j + 1][k];        //sort by 1 column
                    array[j + 1][k] = tmp;
                }
            }
        }
    }
}

void PrintMatrix(int array[][10], int n)
{
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            printf(" %d  ", array[i][j]);     //print matrix
        }
        
        printf("\t\n");
   }
}
