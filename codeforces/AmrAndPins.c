#include <stdio.h>
#include <math.h>
int main(){
    int r,x,y,x1,y1;
    scanf("%d %d %d %d %d",&r,&x,&y,&x1,&y1);
    double d=sqrt((x1-x)*(x1-x)+(y1-y)*(y1-y));
    int final = ceil(d/(2*r));
    printf("%d\n",final);
    return 0;
}