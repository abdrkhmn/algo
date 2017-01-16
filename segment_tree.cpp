#ifndef SEGMENT_TREE_DEF
#define SEGMENT_TREE_DEF

#include <cmath>
#include <cstdio>
#include "math.cpp"

class Segment_tree{
private:
    int *arr;
    int asize;
    int begin;
    int end;

    int get(int l, int r, int L, int R, int index){

        if(r < L || R < l)
            return 0;
        else if(l <= L && R <= r)
            return arr[index];
        else
            return get(l, r, L, (L + R) / 2, index * 2) + get(l, r, (L + R) / 2 + 1, R, index * 2 + 1);
    }
public:
    Segment_tree(int *init, int s){
        arr = new int[(int)pow(2, ceil(log2(s)) + 1)];
        begin = pow(2, ceil(log2(s)));
        end = pow(2, ceil(log2(s)) + 1) - 1;
        asize = s;

        for(int i = 0; i < end - begin + 1; i++)
            if(i < s)
                arr[begin + i] = init[i];
            else
                arr[begin + i] = 0;

        for(int i = begin - 1; i > 0; i--)
            arr[i] = arr[2 * i] + arr[2 * i + 1];
    }

    int get(int l, int r){
        return get(l, r, 1, end - begin + 1, 1);
    }

    void set(int index, int value){
    	int current = begin + index;
    	int delta = value - arr[current];
    	while(current > 0){
    		arr[current] += delta;
    		current /= 2;
    	}
    }

    int size(){ return asize; }
};

#endif