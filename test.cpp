#include "sort.cpp"
#include <bits/stdc++.h>
using namespace std;

int main(int argc, char **argv){
	srand(time(0));

	int n = 15;
	int* arr = new int[n];

	for(int i = 0; i < n; i++)
		arr[i] = n - i;

	int *ans = bogo_sort(arr, n);

	for(int i = 0; i < n; i++)
		cout << ans[i] << endl;
	return 0;
}