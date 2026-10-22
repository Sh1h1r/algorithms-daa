#include <stdio.h>

int power(int a,int n){
	if(n == 1) return a; 
	if(n == 0) return 1;	// base cases
	int half = power(a,n/2);	
	if(n % 2 == 0){
		return half * half;
	}
	else{
		return half * half * a;
	}
}

// recurrence relation is T(n/2);
