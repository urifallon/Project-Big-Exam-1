#include<stdio.h>
#include<math.h>
#include <stdbool.h>

bool math(int a, int b, int c){
    if (a== 0 && b== 0 && c== 0) printf("INF");
    else
    {
        float delta = (float)b*b-4*a*c;
        float temp = (float)-b/2*a;
        float candelta = (float)sqrt(delta);
        float n = (float)((-b + sqrt(delta))/2*a);
        float m = (float)((-b - sqrt(delta))/2*a);

        if (delta < 0) printf("NO");
        else if (delta = 0) printf("%.2f %.2f",temp,temp);
        else printf("%.2f %.2f",n,m);
    }
    
}

int main(){
   int a,b,c; scanf("%ld%ld%ld",&a,&b,&c);
   math(a, b,c);
}