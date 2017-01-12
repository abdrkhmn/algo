
const int DEFAULT_INIT_CAPACITY = 15;

template<class T>
class List{
private:
	T *arr;
	int current_capacity;

	int size;

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
		if(size == current_capacity){
			current_capacity *= 2;

			int *new_arr = new int[current_capacity];
			for(int i = 0; i < current_capacity / 2; i++){
				new_arr[i] = arr[i];
			}
			arr = new_arr;
		}

		arr[size++] = new_element;
	}

	int size(){
		return size;
	}

	void resize(int new_size){

	}
};