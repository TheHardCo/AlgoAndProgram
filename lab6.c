#include<stdio.h>
#include<string.h>

int main(void)
{

  char string[255];
  char arr[20][20];
  printf("Enter your string (less than 255 characters): ");
  fgets(string, 250,stdin);

  char* p = strtok(string, " ");
  int k = 0;
  while (p != NULL)
  {
      char temp = p[0];
    
      if ((temp<='9')&&(temp>='1')) 
      {
          strcpy(arr[k], p);
          ++k;
      }    
      p = strtok(NULL, " ");
  }
  
  for (int i = 0; i < k - 1; ++i)
  {
      for (int j = 0; j < k - i - 1; ++j)
      {
          if (arr[j][0] > arr[j+1][0])
          {
              char temp[20];
              strcpy(temp, arr[j]);
              strcpy(arr[j], arr[j + 1]);
              strcpy(arr[j + 1], temp);
          }
      }
  }
  
  for (int i = 0; i < k; ++i)
  {
      printf("\n%s", arr[i]);
  }
  printf("\n");
}

