#include<stdio.h>
int main(){
    int l,b,a,p;
    printf("ENter length and perimeter:");
    scanf("%d%d",&l,&b);
    a=l*b;
    p=2*(l+b);
    if(a>p){
        printf("Area is greater than Perimeter:");
    }
    else{
        printf("Area is less than perimeter");
    }
    return 0;
}