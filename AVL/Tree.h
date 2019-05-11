struct node // структура для представления узлов дерева
{
	int key;
	unsigned char height;
	node* left;
	node* right;
	node(int k) { key = k; left = right = 0; height = 1; }
};

class AVLTree
{
private:
	node* root;

	unsigned char height(node* p);
	int bfactor(node* p);
	void fixheight(node* p);
	node* rotateright(node* p); // правый поворот вокруг p
	node* rotateleft(node* q); // левый поворот вокруг q
	node* balance(node* p); // балансировка узла p
	node* findmin(node* p); // поиск узла с минимальным ключом в дереве 
	node* removemin(node* p); // удаление узла с минимальным ключом из дерева p

	bool _iscontain(node* p, int k); // проверка на содержимое ключа k из дерева p
	node* _insert(node* p, int k); // вставка ключа k в дерево с корнем p
	node* _remove(node* p, int k); // удаление ключа k из дерева p

public:
	AVLTree();
	AVLTree(int k);
	bool iscontain(int k); // проверка на содержимое ключа k
	void insert(int k); // вставка ключа k в дерево
	void remove(int k); // удаление ключа k
};