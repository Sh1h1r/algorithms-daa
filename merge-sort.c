#include <stdio.h>

void merge(int arr[],int low,int mid,int high){
	int i = low;
	int k = low;
	int j = high;
	int temp[100];

	while(i <= mid && j <= high){
		if(arr[i] < arr[j]){
			temp[k] = arr[i];
			i++;
			k++;
		}
		else{
			temp[k] = arr[j];
			j++;
			k++;
		}
	}

	while( i <= mid){
		temp[k] = arr[i];
		i++;
		k++;
	}

	while( j <= high){
		temp[k] = arr[j];
		j++;
		k++;
	}

	for(i = low; i <= high; i++){
		arr[i] = temp[i];
	}
}

void merge_sort(int arr[],int low, int high){
	if(low >= high) return;

	int mid = (low + high) / 2;
	merge_sort(arr,low,mid);
	merge_sort(arr,mid + 1,high);

	merge(arr,low,mid,high)
}
