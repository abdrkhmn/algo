
#ifndef HEAP_DEF
#define HEAP_DEF

#include "math.cpp"
#include <cstdlib>
#include <algorithm>

const int DEFAULT_INIT_CAPACITY = 16;

template<class T>
class Heap{
private:
	T* arr;
	size_t asize;
	int capacity;

	void siftup(int index){
		int current = index;
		while(arr[current] > arr[current / 2] && current != 1){
			T tmp = arr[current];
			arr[current] = arr[current / 2];
			arr[current / 2] = tmp;
		}
	}

	void siftdown(){
		int current = 1;

		double until = log2(asize);

		for(int i = 0; i < until; i++){
			if(arr[current] < arr[current * 2]){
				T tmp = arr[current];
				arr[current] = arr[current * 2];
				arr[current * 2] = tmp;
				current = current * 2;
			}else if(arr[current] < arr[current * 2 + 1]){
				T tmp = arr[current];
				arr[current] = arr[current * 2 + 1];
				arr[current * 2 + 1] = tmp;
				current = current * 2 + 1;
			}else{
				break;
			}
		}

	}

public:
	
	Heap(){
		asize = 0;
		extend(DEFAULT_INIT_CAPACITY);
		capacity = DEFAULT_INIT_CAPACITY;
	}

	Heap(int init_capacity){
		asize = 0;
		extend(init_capacity);
		capacity = init_capacity;
	}

	void extend(int new_size){
		T* new_arr = new T[new_size + 1];
		for(int i = 1; i <= asize; i++)
			new_arr[i] = arr[i];
		arr = new_arr;
		capacity = new_size;
		delete new_arr;
	}

	void add(T elem){
		if(asize == capacity - 1){
			extend(capacity * 2);
		}
		arr[asize++] = elem;
		siftup(asize - 1);
	}

	T pop(){
		T ret = arr[1];
		arr[1] = arr[asize - 1];
		asize--;

		siftdown();
		return ret;
	}

	T top(){
		return arr[1];
	}

	size_t size(){
		return asize;
	}

};


#endif