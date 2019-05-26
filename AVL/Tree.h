#include <iostream>
using namespace std;

struct node // структура для представления узлов дерева
{
	int key;
	unsigned char height;
	node* right;
	node* left;
	node(int k) { key = k; left = right = 0; height = 1; }
};

class AVLTree
{
private:
	node* root;

	unsigned char height(node* p);
	int diff(node* p);
	void fix_height(node* p);
	node* rotateright(node* p); // правый поворот вокруг p
	node* rotateleft(node* q); // левый поворот вокруг q
	node* balance(node* p); // балансировка узла p
	pair<node*, node*> remove_dop(node* p); // удаление узла с минимальным ключом из дерева p

	node* _iscontain(node* p, int k); // проверка на содержимое ключа k из дерева p
	node* _insert(node* p, int k); // вставка ключа k в дерево с корнем p
	node* _remove(node* p, int k); // удаление ключа k из дерева p
	void _printLKM(node* p, int height);
	node* _find_before(node* p, node* f);
	pair<node*, node*> _find_after(node* p, node* f);

public:
	AVLTree();
	AVLTree(int k);
	node* iscontain(int k); // проверка на содержимое ключа k
	void insert(int k); // вставка ключа k в дерево
	void remove(int k); // удаление ключа k
	void printLKM();
	node* find_before(node* f);
	pair<node*, node*> find_after(node* f);
};