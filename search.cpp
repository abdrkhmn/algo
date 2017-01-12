#include <iostream>

using namespace std;

template<typename T>
bool bin_search(T arr[], T item){
	int size = sizeof(arr) / sizeof(T);
	cout << size << endl;

	int l = 0;
	int r = size;
	int m;
	while(r > l){
		m = (l + r) / 2;
		if(item < arr[m]) r = m;
		else l = m + 1;
	}
	
	return (arr[l] == item);
}