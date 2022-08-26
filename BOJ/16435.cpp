#include <stdio.h>
#include <stdlib.h>

void sort(int *arr, int n);

int main(){
	
	int l,n;
	scanf("%d %d",&n,&l);
	int* arr = (int*)malloc(sizeof(int)*n);
	for(int i=0; i<n;i++){
		scanf("%d",&arr[i]);
	}

	sort(arr,n);

	for(int i=0; i<n; i++){
		if(l>=arr[i])
			l++;
	}

	printf("%d",l);

	free(arr);
	return 0;
}

void sort(int *arr, int n){
	int tmp;
	int min;

	for(int i=0; i<n-1; i++){
		min = i;
		for(int j=i+1; j<n; j++){
			if(arr[j]<arr[min])
				min = j;

		}
		if(i != min ){
		tmp = arr[i];
		arr[i] = arr[min];
		arr[min] = tmp;
		}
	}
	return;


}
