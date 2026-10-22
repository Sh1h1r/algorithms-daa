#include <stdio.h>
int melt_point;

int meltsAt(int temp){
	if(temp >= melt_point) return 1;
	else return 0;
}

int findMeltingPoint(int low, int high){
	if(low == high) return low;
	int mid = (low + high) / 2;
	if(meltsAt(mid)){
		return findMeltingPoint(low,mid);
	}
	else{
		return findMeltingPoint(mid + 1,high);
	}
}

int main(){
	printf("enter the temp at which choco melts:");
	scanf("%d",&melt_point);
	int final = findMeltingPoint(0,100);
	printf("%d",final);
}

