#include <stdio.h>
void main(){
    int x1;
    int y1;
    int x2;
    int y2;
    int x3;
    int y3;
    printf("Enter x1 coordenate:");
    scanf("%d",&x1);
    printf("Enter y1 coordenate:");
    scanf("%d",&x1);
    printf("Enter x2 coordenate:");
    scanf("%d",&x1);
    printf("Enter y2 coordenate:");
    scanf("%d",&x1);
    printf("Enter x3 coordenate:");
    scanf("%d",&x1);
    printf("Enter y3 coordenate:");
    scanf("%d",&x1);
    if(x1==x2 && x2==x3){
        printf("All the three points are in same line");
    }
    else if(y1==y2 && y2==y3){
        printf("all the three points are in same line");
    }
    else{
        printf("not all points are in same line");
    }
}