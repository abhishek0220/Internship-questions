/*
Solution for https://www.geeksforgeeks.org/segregate-even-and-odd-numbers-set-2/
*/
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
void print(int arr[], int n){
	for(int i=0; i<n; i++){
		cout<<arr[i]<<"\t";
	}
	cout<<"\n";
}
int main()
{
    int arr[] = {8, 22, 65, 70, 33, 60, 2, 34, 43, 21} ;
	int n = sizeof(arr)/sizeof(arr[0]);
	int even = 0;
	int odd = n-1;
	print(arr, n);
	while(even < odd){
		if(arr[even]%2 == 0) even++;
		else if(arr[odd]%2 == 1) odd--;
		else{
			int tem = arr[even];
			arr[even] = arr[odd];
			arr[odd] = tem;
			odd--;
			even++;
		}
	}
	print(arr, n);
    return 0;
    }