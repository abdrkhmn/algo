#include "list.cpp"
#include <iostream>

#ifndef SEARCH_DEF
#define SEARCH_DEF

template<class T>
int bin_search(List<T> arr, T item){
	std::cout << arr.size() << std::endl;
	int l = 0;
	int r = arr.size();
	int m;

	while(r > l){
		m = (l + r) / 2;
		if(item <= arr[m]) r = m;
		else l = m + 1;
	}
	
	if(arr[l] == item) return l;
	else return -1;
}

template<class T>
int line_seatch(List<T> arr, T item){
	for(int i = 0; i < arr.size(); i++){
		if(arr[i] == item)
			return i;
	}
	return -1;
}

#endif