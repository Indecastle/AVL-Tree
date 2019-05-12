#include "pch.h"
#include "Tree.h"
using namespace std;

AVLTree::AVLTree() {}
AVLTree::AVLTree(int k) { insert(k); }

unsigned char AVLTree::height(node* p)
{
	return p ? p->height : 0;
}

int AVLTree::diff(node* p)
{
	return height(p->right) - height(p->left);
}

void AVLTree::fix_height(node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

node* AVLTree::rotateright(node* p) // правый поворот вокруг p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fix_height(p);
	fix_height(q);
	return q;
}

node* AVLTree::rotateleft(node* q) // левый поворот вокруг q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fix_height(q);
	fix_height(p);
	return p;
}

node* AVLTree::balance(node* p) // балансировка узла p
{
	fix_height(p);
	if (diff(p) == 2)
	{
		if (diff(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (diff(p) == -2)
	{
		if (diff(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p;
}

node* AVLTree::_insert(node* p, int k) // вставка ключа k в дерево с корнем p
{
	if (!p) return new node(k);
	if (k < p->key)
		p->left = _insert(p->left, k);
	else
		p->right = _insert(p->right, k);
	return balance(p);
}

pair<node*, node*> AVLTree::removemin(node* p) // удаление узла с минимальным ключом из дерева p
{
	if (p->left == nullptr)
		return { p->right, p };
	auto tuple = removemin(p->left);
	p->left = tuple.first;
	return { balance(p), tuple.second };
}

node* AVLTree::_remove(node* p, int k) // удаление ключа k из дерева p
{
	if (!p) return nullptr;
	if (k < p->key)
		p->left = _remove(p->left, k);
	else if (k > p->key)
		p->right = _remove(p->right, k);
	else //  k == p->key 
	{
		node* q = p->left;
		node* r = p->right;
		delete p;
		if (!r) return q;
		auto tuple = removemin(r);
		node* min = tuple.second;
		min->right = tuple.first;
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

node* AVLTree::_iscontain(node * p, int k) // проверка на содержимое ключа k из дерева p
{
	if (p == nullptr) return nullptr;
	if (k < p->key)
		return _iscontain(p->left, k);
	else if (k > p->key)
		return _iscontain(p->right, k);
	else //  k == p->key 
	{
		return p;
	}
}


node* AVLTree::iscontain(int k) // проверка на содержимое ключа k
{
	return _iscontain(root, k);
}

void AVLTree::insert(int k) // вставка ключа k в дерево
{
	root = _insert(root, k);
}

void AVLTree::remove(int k) // удаление ключа k
{
	root = _remove(root, k);
}