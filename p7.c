#include<stdio.h>
void sum_of_5_numbers(int n1,int n2,int n3,int n4,int n5){
    int sum=n1+n2+n3+n4+n5;
    printf("Sum of the given 5 numbers is:%d",sum);
}
int main(){
    int n1,n2,n3,n4,n5;
    int sum;
    printf("Enter 5 numbers to add");
    scanf("%d",&n1);
    scanf("%d",&n2);
    scanf("%d",&n3);
    scanf("%d",&n4);
    scanf("%d",&n5);
    sum_of_5_numbers(n1,n2,n3,n4,n5);
}