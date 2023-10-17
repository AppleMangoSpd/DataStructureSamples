#pragma once

struct Node
{
	int _data;
	Node* _left;
	Node* _right;
};

class BST
{
public:
	Node* _root = nullptr;

	//�˻�
	const Node* Find(const int target) const;
	//����
	void Insert(const int target);
	//���� ��ȸ (��������)
	void InOrder() const;
	//��������
	void DescendingOrder() const;
	//����
	void DeleteValue(const int target);

private:
	const Node* Find_impl(const Node* current, const int target) const;
	void Insert_impl(Node* current, const int target);
	void InOrder_impl(const Node* start) const;
	void DescendingOrder_impl(const Node* start) const;
	Node* Delete_impl(Node* start, const int target);
	//�ļӳ�� �˻�
	Node* Successor(Node* start) const;
};