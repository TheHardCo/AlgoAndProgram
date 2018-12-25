#include <stdio.h>
#include <stdlib.h>

const int n = 5;

typedef struct
{
    char name[20];
    char director[20];
    char country[20];
    char profit[20];
}FILM;

void Input(void)
{
    FILM buffer;
    FILE* f = fopen("Film.txt", "w");
    if (f == NULL)
    {
        printf("Error while reading1!\n");
        exit(2);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter the title of the film: \n");
        scanf("%s", buffer.name);
        printf("Enter the director's surname (without spaces): \n");
        scanf("%s", buffer.director);
        printf("Enter the country of production: \n");
        scanf("%s", buffer.country);
        printf("Enter the profit: \n");
        scanf("%s", buffer.profit);

        fwrite(&buffer, sizeof(FILM), 1, f);

    
        if (ferror(f))
        {
            printf("Cannot write!\n");
            exit(1);
        }
  }
  
  
  fclose(f);
  
};

void Print(void)
{
  FILM buffer;
  FILE* f = fopen("Film.txt", "r");
  if (f == NULL)
  {
    printf("Error while reading1!\n");
    exit(2);
  }
  for (int i = 0; i < n; i++)
  {
    fread(&buffer, sizeof(FILM), 1, f);
    if (feof(f)) break;
    printf("\n");
    printf("| Film title: %s | Director's surname %s | Country of production: %s | Profit: %s |\n", buffer.name, buffer.director, buffer.country, buffer.profit);
    printf("\n");
  };
  fclose(f);
  
}
void Read(FILM* buffer)
{

  FILE* f = fopen("Film.txt", "r");
  if (f == NULL)
  {
    printf("Error while reading1!\n");
    exit(2);
  }
  for (int i = 0; i < n; i++)
  {
    fread(&buffer[i], sizeof(FILM), 1, f);
    if (feof(f)) break;
    
  };
  fclose(f);
}

void Erase(int m)
{
  FILM* buffer = (FILM*)malloc(sizeof(FILM) * n);
  Read(buffer);
  
  FILE* f = fopen("Film.txt", "w");
  if (!f)
  {
    printf("Error while reading1!\n");
    exit(2);
  }

  for (int i = 0; i < n - m; ++i)
  {
    fwrite(&buffer[i], sizeof(FILM), 1, f);
  }  
  fclose(f);
  free(buffer);
};
void AddStruct()
{

  FILE* f = fopen("Film.txt", "a");
  if (f == NULL)
  {
    printf("Error while reading1!\n");
    exit(2);
  }

  FILM add;
  printf("Enter the title of the film TO ADD: \n");
  scanf("%s", add.name);
  printf("Enter the director's surname (without spaces) TO ADD: \n");
  scanf("%s", add.director);
  printf("Enter the country of production TO ADD: \n");
  scanf("%s", add.country);
  printf("Enter the profit TO ADD: \n");
  scanf("%s", add.profit);

  fwrite(&add, sizeof(FILM), 1, f);
  

  if (ferror(f))
  {
    printf("Cannot write!\n");
    exit(1);
  }
  
  fclose(f);
}


int main(void)
{
    
    Input();
     Print();
     printf("\n _________________________________________________\n");
     Erase(2);
     Print();
     AddStruct();
     Print();    
    return 0;
}
