
#ifndef SORT_DEF
#define SORT_DEF

#include <cstdlib>

//BOGOSORT
template<class T>
bool is_correct(T* arr, int size){
	for(int i = 0; i < size - 1; i++)
		if(arr[i] > arr[i + 1])
			return false;
	return true;
}

template<class T>
T* shuffle(T* arr, int size){
	for(int i = 0; i < size; i++){
		int index = (i + rand()) % size;
		T tmp = arr[i];
		arr[i] = arr[index];
		arr[index] = tmp;
	}
	return arr;
}

template<class T>
T* bogo_sort(T* arr, int size){
	while(!is_correct(arr, size))
		shuffle(arr, size);
	return arr;
}

//NAIVE SORT



#endif