
#ifndef BIT_ARRAY_H
#define BIT_ARRAY_H

string base64 = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
char nums[] = {1, 2, 4, 8, 16, 32, 64, 128};
char nnums[] = {255 - 1, 255 - 2, 255 - 4, 255 - 8, 255 - 16, 255 - 32, 255 - 64, 255 - 128};

class bit_array{
private:
	vector<char> arr;
	size_t size;

public:
	bit_array(int c){
		arr.resize(ceil(c / 8));
		size = 0;
	}

	bool get(int index){
		int n = index / 8;
		return (arr[n] >> index % 8) % 2;
	}

	void add(bool val){
		if(size == arr.size())
			arr.push_back(0);
		int n = size / 8;
		if(val)
			arr[n] |= nums[size % 8];
		else
			arr[n] &= nnums[size % 8];

		size++;
	}

	void set(int index, bool val){
		int n = index / 8;
		if(val)
			arr[n] |= nums[index % 8];
		else
			arr[n] &= nnums[index % 8];
	}

	void size(){
		return size;
	}

};

#endif