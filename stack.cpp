

#ifndef STACK_DEF
#define STACK_DEF

#include <cstdlib>

template<class T>
struct Node{
	Node<T>* prev = NULL;
	T value;
	Node(Node<T>* p, T v){
		prev = p;
		value = v;
	}
};

template<class T>
class Stack{
private:
	Node<T>* last = NULL;
	size_t asize = 0;


public:
	void add(T elem){
		last = new Node<T>(last, elem);
	}

	T pop(){
		Node<T>* ret = last;
		last = last->prev;
		return ret->value;
	}

	T top(){
		return last->value;
	}

	size_t size(){
		return asize;
	}
};

#endif