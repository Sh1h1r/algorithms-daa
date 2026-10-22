#include <stdio.h>

void swap(int* a,int *b){
	int c = *a;
	*a = *b;
	*b = c;
}

int partition(int arr[],int low,int high){
	int pivot = arr[high];
	int i = low - 1;
	for(int j = low; j <= high;j++){ // O(n)
		if(arr[j] < pivot){
			i++;
			swap(&arr[j],&arr[i]);
		}
	}

	swap(&arr[i + 1],&pivot);
	return i + 1;
}

void quicksort(int arr[],int low,int high){
	if(low < high){
		int p = partition(arr,low,high);
		quicksort(arr,low,p - 1);
		quicksort(arr,p + 1,high);
	}
}

// reccurence 2T(n/2) + O(n) best case or average 
// worst when pivot is already at teh position so T(n - 1) + O(n)
