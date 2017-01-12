
const int DEFAULT_INIT_CAPACITY = 15;

template<class T>
class List{
private:
	T *arr;
	int current_capacity;
	int asize;

	void extend(int new_capacity){
		int *new_arr = new int[new_capacity];
		for(int i = 0; i < asize; i++)
			new_arr[i] = arr[i];
		arr = new_arr;
	}

	int current_iteration = 0;
public:
	List(int init_capacity){
		arr = new T[init_capacity];
		current_capacity = init_capacity;
	}

	List(){
		arr = new T[DEFAULT_INIT_CAPACITY];
		current_capacity = DEFAULT_INIT_CAPACITY;
	}

	T operator[] (int index){
		return arr[index];
	}

	T add(T new_element){
		cout << "Current capacity " << current_capacity << endl;
		if(asize == current_capacity){
			current_capacity *= 2;

			extend(current_capacity);
		}

		arr[asize++] = new_element;
	}

	int size(){
		return asize;
	}

	void resize(int new_size){
		int *new_arr = new int[new_size];
		for(int i = 0; i < asize; i++)
			new_arr[i] = arr[i];
		arr = new_arr;
		asize = new_size;
	}

	T next(){
		return arr[current_iteration++];
	}

};