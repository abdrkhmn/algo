#include "segment_tree.cpp"
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <cstdio>
using namespace std;

Segment_tree *t;

int main(int argc, char **argv){
	int arr[] = {1, 2, 3, 4, 5, 6, 7};

	t = new Segment_tree(arr, 7);

	cout << t->get(2, 2) << endl;

	return 0;
}