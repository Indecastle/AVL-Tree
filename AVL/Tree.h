#include <iostream>
using namespace std;

struct node // ��������� ��� ������������� ����� ������
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
	int diff(node* p);
	void fix_height(node* p);
	node* rotateright(node* p); // ������ ������� ������ p
	node* rotateleft(node* q); // ����� ������� ������ q
	node* balance(node* p); // ������������ ���� p
	pair<node*, node*> removemin(node* p); // �������� ���� � ����������� ������ �� ������ p

	node* _iscontain(node* p, int k); // �������� �� ���������� ����� k �� ������ p
	node* _insert(node* p, int k); // ������� ����� k � ������ � ������ p
	node* _remove(node* p, int k); // �������� ����� k �� ������ p

public:
	AVLTree();
	AVLTree(int k);
	node* iscontain(int k); // �������� �� ���������� ����� k
	void insert(int k); // ������� ����� k � ������
	void remove(int k); // �������� ����� k
};