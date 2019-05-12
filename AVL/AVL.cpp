#include "pch.h"
#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
    cout << "Hello World!\n"; 

	AVLTree tree(1);
	tree.insert(5);
	for (int i = 0; i < 100000; i++) {
		tree.insert(i);
	}
	cout << (bool)tree.iscontain(5) << endl;
	tree.remove(5);
	cout << (bool)tree.iscontain(5) << endl;
	tree.remove(5);
	cout << (bool)tree.iscontain(5) << endl;

	return 0;
}