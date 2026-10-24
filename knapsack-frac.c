#include <stdio.h>

int main(){
	int n;
	float capacity,profit = 0;

	printf("enter number of items: ");
	scanf("%d",&n);
	float weight[n],value[n],ratio[n];

	printf("enter weights:\n");
	for(int i = 0; i < n; i++){
		scanf("%f",&weight[i]);
	}

	printf("enter profits:\n");
	for(int i = 0; i < n; i++){
		scanf("%f",&value[i]);
	}

	for(int i = 0; i < n; i++){
		ratio[i] = value[i] /  weight[i];
	}

	for(int i = 0; i < n - 1; i++){
		for(int j = i + 1;j < n; j++){
			if(ratio[i] < ratio[j]){
				float temp;

				temp = ratio[i];
				ratio[i] = ratio[j];
				ratio[j] = temp;

				temp = weight[i];
				weight[i] = weight[j];
				weight[j] = temp;

				temp = value[i];
				value[i] = value[j];
				value[j] = temp;
			}
		}
	}

	for(int i = 0; i < n; i++){
		if(weight[i] <= capacity){
			capacity = capacity - weight[i];
			profit = profit + value[i];
		}
		else{
			profit = profit + ratio[i] * capacity;
			capacity = 0;
			break;
		}
	}

	printf("max profit = %.2f\n",profit);
	return 0;
}
