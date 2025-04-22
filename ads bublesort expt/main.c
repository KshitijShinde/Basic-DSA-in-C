/******************************************************************************

Welcome to GDB Online.
  GDB online is an online compiler and debugger tool for C, C++, Python, PHP, Ruby, 
  C#, OCaml, VB, Perl, Swift, Prolog, Javascript, Pascal, COBOL, HTML, CSS, JS
  Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

int main()
{
int n;
int sortcount=0,comparisoncount=0;
printf("enter size of array");
scanf("%d",&n);
int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int temp;
    for(int i=0;i<n-1;i++){
    	
        for(int j=0;j<n-1-i;j++){
        comparisoncount++;
        
            if(a[j]>a[j+1]){
                temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
                
                sortcount++;     
            }
        }
    }
    
    for(int i=0;i<n;i++){
        printf("%d  ",a[i]);
    }
    printf("\nswaps=%d",sortcount);
    printf("\ncomparison=%d",comparisoncount);
    
    return 0;
}