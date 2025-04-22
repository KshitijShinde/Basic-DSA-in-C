#include<stdio.h>
int main(){
	int i,j,n,key;
	int count=0,swap=0;
	printf("Enter number of array:");
	scanf("%d",&n);
	int arr[n];
	printf("Enter Numbers :");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);

	}
	for(i=1;i<n;i++){
		key=arr[i];
		j=i-1;
		count++;
		while(j>=0&&key<arr[j]){
			arr[j+1]=arr[j];
			j=j-1;
			swap++;
		}
		arr[j+1]=key;
	}
	for(i=0;i<n;i++){
		printf("%d \n",arr[i]);

	}
	printf("Number of swap = %d\n",swap);
	printf("Number of comparison = %d\n",count);
}