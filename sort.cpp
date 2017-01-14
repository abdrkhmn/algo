
#ifndef SORT_DEF
#define SORT_DEF

#include <cstdlib>
#include <cmath>

template<class T>
bool is_correct(T* arr, int size){
	for(int i = 0; i < size - 1; i++)
		if(arr[i] > arr[i + 1])
			return false;
	return true;
}

//BOGOSORT
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

//MERGESORT

template <class T>
T* merge(T* arr, int begin, int end){

	if(begin == end)
		return arr;

	T* ret = new T[end - begin + 1];
	int a = begin;
	int b = (begin + end) / 2;
	for (int i = 0; i < end - begin - + 1; i++){
		if(arr[a] < arr[b]) ret = arr[a++];
		else ret = arr[b++];
	}
	for(int i = begin; i < end; i++){
		arr[i] = ret[i - begin];
	}

	delete ret;
	return arr;
}

template<class T>
T*	merge_rec(T* arr, int begin, int end){

}

template <class T>
T* merge_sort(T* arr, int size){

}

#endif