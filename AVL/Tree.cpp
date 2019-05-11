#include "pch.h"
#include <iostream>
#include "Tree.h"
using namespace std;

AVLTree::AVLTree() {}
AVLTree::AVLTree(int k) { insert(k); }

unsigned char AVLTree::height(node* p)
{
	return p ? p->height : 0;
}

int AVLTree::bfactor(node* p)
{
	return height(p->right) - height(p->left);
}

void AVLTree::fixheight(node* p)
{
	unsigned char hl = height(p->left);
	unsigned char hr = height(p->right);
	p->height = (hl > hr ? hl : hr) + 1;
}

node* AVLTree::rotateright(node* p) // ������ ������� ������ p
{
	node* q = p->left;
	p->left = q->right;
	q->right = p;
	fixheight(p);
	fixheight(q);
	return q;
}

node* AVLTree::rotateleft(node* q) // ����� ������� ������ q
{
	node* p = q->right;
	q->right = p->left;
	p->left = q;
	fixheight(q);
	fixheight(p);
	return p;
}

node* AVLTree::balance(node* p) // ������������ ���� p
{
	fixheight(p);
	if (bfactor(p) == 2)
	{
		if (bfactor(p->right) < 0)
			p->right = rotateright(p->right);
		return rotateleft(p);
	}
	if (bfactor(p) == -2)
	{
		if (bfactor(p->left) > 0)
			p->left = rotateleft(p->left);
		return rotateright(p);
	}
	return p; // ������������ �� �����
}

node* AVLTree::_insert(node* p, int k) // ������� ����� k � ������ � ������ p
{
	if (!p) return new node(k);
	if (k < p->key)
		p->left = _insert(p->left, k);
	else
		p->right = _insert(p->right, k);
	return balance(p);
}

node* AVLTree::findmin(node* p) // ����� ���� � ����������� ������ � ������ p 
{
	return p->left ? findmin(p->left) : p;
}

node* AVLTree::removemin(node* p) // �������� ���� � ����������� ������ �� ������ p
{
	if (p->left == 0)
		return p->right;
	p->left = removemin(p->left);
	return balance(p);
}

node* AVLTree::_remove(node* p, int k) // �������� ����� k �� ������ p
{
	if (!p) return 0;
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
		node* min = findmin(r);
		min->right = removemin(r);
		min->left = q;
		return balance(min);
	}
	return balance(p);
}

bool AVLTree::_iscontain(node * p, int k) // �������� �� ���������� ����� k �� ������ p
{
	if (p == nullptr) return false;
	if (k < p->key)
		return _iscontain(p->left, k);
	else if (k > p->key)
		return _iscontain(p->right, k);
	else //  k == p->key 
	{
		return true;
	}
}


bool AVLTree::iscontain(int k) // �������� �� ���������� ����� k
{
	return _iscontain(root, k);
}

void AVLTree::insert(int k) // ������� ����� k � ������
{
	root = _insert(root, k);
}

void AVLTree::remove(int k) // �������� ����� k
{
	root = _remove(root, k);
}