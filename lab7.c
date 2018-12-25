#include <stdio.h>
#include <math.h>

static double R;

struct pair_x_y
{
    double x;
    double y;
};

int isInCircle(struct pair_x_y koord)
{
    if(sqrt(pow(koord.x,2) + pow(koord.y,2)) <= R)
    {
        return 1;
    }
    else
    {
        return 0;
    } 
}

int belong( unsigned int numbOfKoord, double R, ...) 
{
    va_list args;
    int result = 0;
    va_start(args, R);
    
    for (int i = 0; i < numbOfKoord; i++) 
    {
        if (isInCircle(va_arg(args,struct pair_x_y))) 
        {
            result++;
        }
    }
    va_end(args);
    return result;
}
int main(void)
{
    int point;
    
    printf("Enter the radius of circle: ");
    scanf("%lf",&R);

    printf("Enter the amount of points: ");
    scanf("%i",&point);
    
    for(int i = 0; i < point; i++)
    {
        struct pair_x_y koord;
        printf("Enter x = ");
        scanf("%lf",&koord.x);
        printf("Enter y = ");
        scanf("%lf",&koord.y);
        
        int res = belong(point, R, koord);
        printf("%i\n",res);
    }
     /***
    one.x = 2;
    one.y = 2;

    struct pair_x_y second;
    second.x = 5;
    second.y = 5;

    struct pair_x_y last;
    second.x = 4;
    second.y = 4;
***/
    
}
