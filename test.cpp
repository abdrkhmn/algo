#include "search.cpp"
#include "list.cpp"
#include <iostream>
#include <string>
using namespace std;


List<int> something;

int main(int argc, char **argv){
	for (int i = 0; i < 62; i++){
		something.add(i);
	}

	cout << endl;
	for(int i = 0; i < something.size(); i++)
		cout << i << "->" <<  something[i] << endl;
	return 0;
}