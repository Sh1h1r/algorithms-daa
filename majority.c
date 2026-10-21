#include <stdio.h>

int majority(int arr[],int n){
	int candidate = -1;
	count = 0;

	for(int i = 0; i < n; i++){
		if(count == 0){
			candidate = arr[i];
			count = 1;
		}
		else if(arr[i] == candidate){
			count++;
		}
		else{
			count--;
		}
	}
	//canddidates are gonna vote eo out so the most appearign one remains pretty self explainable loking at the code
// we just gonna check the freq
	int freq = 0;
	for(int i = 0; i <n; i++){
		if(arr[i] == candidate){
			freq++;
		}
	}

	if(freq > n/2){
		return candidate;
	}
}
