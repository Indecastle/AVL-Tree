#pragma once

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
	unsigned char height(node* p);
	int bfactor(node* p);
	void fixheight(node* p);
	node* rotateright(node* p); // ������ ������� ������ p
	node* rotateleft(node* q); // ����� ������� ������ q
	node* balance(node* p); // ������������ ���� p
	node* findmin(node* p); // ����� ���� � ����������� ������ � ������ 
	node* removemin(node* p); // �������� ���� � ����������� ������ �� ������ p

public:
	node* insert(node* p, int k); // ������� ����� k � ������ � ������ p
	node* remove(node* p, int k); // �������� ����� k �� ������ p
};