#include<stdio.h>
void fibonacci(int n){
    int a=1;
    int b=1;
    printf("fibonaci series:");
    for(int i=0;i<n;i++){
        printf(" %d",a);
        int c=a+b;
        a=b;
        b=c;
        
    }
}
int main(){
    int n;
    printf("Enter a number:");
    scanf("%d",&n);
    fibonacci(n);
}