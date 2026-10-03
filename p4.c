#include <stdio.h>
#include <stdlib.h>
int main(){
    system ("cls");
    char g;
    int years,qualification;
    printf("Enter your gender(M/F) , years of service , Qualification(0=UG,1=PG):");
    scanf(" %c%d%d", &g, &years, &qualification);
    if(g=='M'){
        if (years<10){
            if (qualification=0){
                printf("Salary=7000");
            }
            else{
                printf("salary=10000");
            }
        }
        else{
            if(qualification=1){
                printf("Salary=15000");
            }
            else{
                printf("salary=10000");
            }
        }
    }
    else{
        if(years<10){
            if(qualification=0){
                printf("salary=6000");
            }
            else{
                printf("Salary=10000");
            }
        }
        else{
            if(qualification=0){
                printf("Salary=9000");
            }
            else{
                printf("Salary=12000");
            }
        }
    }
    return 0;
}