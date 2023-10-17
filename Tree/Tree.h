#pragma once
#include <iostream>

struct Node;

class Tree
{
public:
	//Ʈ������
	static Tree* CreateTree(const std::string& position);
	//�˻�
	Node* Find(Node* root, const std::string& target);
	//parent ��忡 child��� ������ �߰�
	bool AddSubordinate(const std::string& parent, const std::string& child);


	//�ֻ�������ȯ
	const Node* GetRoot() const;
	void SetRoot(Node* target);
private:
	//������ CreateTree�� �̿��ؼ��� ����
	Tree() {};
	Node* _root;
};