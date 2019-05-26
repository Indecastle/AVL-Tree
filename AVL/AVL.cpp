#include "pch.h"
#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
    cout << "Hello World!\n"; 

	AVLTree tree(1);
	tree.insert(5);
	for (int i = 10; i > 3; i--) {
		tree.insert(i);
		cout << endl << endl << endl;
		tree.printLKM();
		int azaz = i;
	}

	cout << (bool)tree.iscontain(5) << endl;
	tree.remove(5);
	cout << (bool)tree.iscontain(5) << endl;
	//tree.remove(5);
	cout << (bool)tree.iscontain(5) << endl;
	node* find1 = tree.iscontain(5);
	node* find2 = tree.find_before(find1);
	auto find3 = tree.find_after(find1);
	cout << endl;
	tree.printLKM();
	tree.remove(5);
	cout << endl << endl;
	tree.printLKM();

	return 0;
}