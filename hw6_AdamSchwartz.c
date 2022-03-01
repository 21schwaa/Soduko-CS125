#include <stdio.h>
#include <math.h>

float QuaSolv(a,b,c);
int a, b, c, x;
float rootOne, rootTwo;
char answer;
int main(){
  while (x=1){
    printf("Would you like to solve a quadrtatic Equation:(Y=yes|N=No)::");
    scanf(" %c", &answer);
    if (answer=='Y'){
    printf("Please enter a Value for A:");
    scanf("%d", &a);
    printf("Please enter a Value for B:");
    scanf("%d", &b);
    printf("Please enter a Value for C:");
    scanf("%d", &c);
    QuaSolv(a,b,c);
    printf("RootOne is %0.2f\n", rootOne);
    printf("RootTwo is %0.2f\n", rootTwo);
    }
    else if(answer=='N'){
    printf("Thank You for Using the Quadratic Solver :)\n");
    x=0;
    break;
    }
    else{
    printf("Invalid Respnonse\n");
    }  
  }
}

float QuaSolv(a,b,c){
  rootOne=((b-(sqrt((b*b)-(4*(a*c)))))/(2*a));
  rootTwo=(((-b)-(sqrt((b*b)-(4*(a*c)))))/(2*a));
  return rootOne, rootTwo;
}