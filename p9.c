#include <stdio.h>
void main(){
    system cls;
    int n;
    printf("Enter a balue n:");
    scanf("%d",&n);
    int a[n];
    printf("Enter the %d elements to compare :",n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=1;j<n;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    for(int i=0;i<n;i++){
        printf("%d",a[n]);
    }
}