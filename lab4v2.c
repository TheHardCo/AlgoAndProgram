#include <stdio.h>


int main()
{
  int arr[100], n;
  
  printf("enter n: ");
  scanf("%d", &n);        //початкова к-сть ел
  
  if( n < 2 || n > 100)
  {
     printf("INVALID INPUT !!!\n");
     return main();
  }
    printf("enter array: "); 
    
    for (int i = n-1; i > -1; --i) //задом наперед
    {
        scanf("%d", &arr[i]);    //скан поч мас
    }

  int k = n-1;
  
    for (int i = 0; i < n+1; ++i)
    {
        printf("%d element - %d \n", i+1, arr[k]); //виводить задом наперед перший елемент - останній насправді
        k--;
        if (k < 0)
        {
            k = n-1;       //закільцювання
        }
    }

  int arr2[102];     //доповнений першим і останнім
  
  printf("\nenter first: ");
  scanf("%d", arr2 + n + 1);
  printf("\n enter last: ");
  scanf("%d", arr2);
  
    for (int i = n; i > 0; --i)
    {
        arr2[i] = arr[i-1];    //копіюєм середину мас
    
    }
  int j = 0, arr3[100];     //мас без непарних
  
    for (int i = 0; i < n + 2; ++i)
    {
        if ((arr2[i] % 2) == 0)
        {
            arr3[j] = arr2[i];
            //printf("%d el3 = %d\n", j, arr3[j]);
            ++j;
      
        }
    }

  k = j - 1;
  
    for (int i = 0; i < j + 1; ++i)
    {
        printf("%d element - %d \n", i + 1, arr3[k]);
        k--;
            if (k < 0)
            {
                k = j - 1;
            }
    }
  getchar();
  getchar();
  return 0;
}
