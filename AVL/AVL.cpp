#include "pch.h"
#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
    cout << "Hello World!\n"; 

	AVLTree tree(1);
	tree.insert(5);
	cout << tree.iscontain(5) << endl;
	tree.remove(5);
	cout << tree.iscontain(5) << endl;

	return 0;
}