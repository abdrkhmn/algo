

#ifndef LINKED_LIST_DEF
#define LINKED_LIST_DEF

#include <cstdlib>

template <class T>
class Node{
public:
	Node<T>* left;
	Node<T>* right;
	T value;

	Node(Node<T>* lleft, Node<T>* lright, T lvalue){
		left = lleft;
		right = lright;
		value = lvalue;
	}

	Node<T>* next(){
		return right;
	}

	Node<T>* prev(){
		return left;
	}
};


template <class T>
class Linked_list{
private:
	Node<T>* first;
	Node<T>* last;

	int asize;
public:
	Linked_list(){}

	Node<T>* getFirst(){
		return first;
	}

	void add_back(T item){
		if(last != NULL){
			last->right = new Node<T>(last, NULL, item);
			last = last->right;
		}else last = new Node<T>(NULL, NULL, item);
		if(first == NULL)
			first = last;
		asize++;
	}

	void add_forward(T item){
		if(first != NULL){
			first->left = new Node<T>(NULL, first, item);
			first = first->left;
		}else first = new Node<T>(NULL, NULL, item);
		if(last == NULL){
			last = first;
		}
		asize++;
	}

	int size(){
		return asize;
	}
};


#endif