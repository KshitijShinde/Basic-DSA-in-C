#include <stdio.h>
int main(){
	int n;
	int minindex;
	int i,j;
	int swap=0,compare=0;
	printf("enter array size");
	scanf("%d",&n);
	int a[n];
	int temp=0;
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	
	for(int i=0;i<n-1;i++){
		minindex=i;
		for(int j=i+1;j<n;j++){
			compare++;
			if(a[minindex]>a[j]){
				minindex=j;
			}
		}
		if(minindex!=i){
			temp=a[i];
			a[i]=a[minindex];
			a[minindex]=temp;
			swap++;
		}
	}
	for(int i=0;i<n;i++){
		printf("%d  ",a[i]);
	}
	printf("\nswap=%d",swap);
	printf("\ncompare=%d",compare);
}