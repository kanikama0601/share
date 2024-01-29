//例のプログラム

#define M_PI 3.14159265358979323846
#include <stdio.h>
#include <math.h>

double entyu(int r,int h)
{
    return (r*r)*M_PI*h;
}
double tyuku(int h,int r1,int r2)
{
    return ((entyu(r1,h)) - (entyu(r2,h)));
}

int main(void)

{
    int h,r1,r2;
    scanf("%d %d %d",&h,&r1,&r2);
    
    double out=tyuku(h,r1,r2);
    printf("%.2lf\n",out);
    return 0;
}

/*実行結果1
8 4 2
301.59
*/

/*実行結果2
100 3 2
1570.80
*/