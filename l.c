#include <stdio.h>
void main(){
    int x;
    printf("Enter a vlue of x");
    scanf("%d",&x);
    int* n;
    int a[x];
    for(int i=0;i<x;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<x;i++){
        printf("Adress of %d element is :%p\n",i,&a[i]);
    }
}