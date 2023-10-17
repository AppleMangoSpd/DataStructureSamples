#pragma once
#include <string>
#include <vector>

//�������)
//Ŭ����, ����� �̿��ؼ� ����ӹ޴� ��� ��带 NTree�� ���� �����ϵ���?
struct Node
{
	std::string _name;
	Node* _parent;
	std::vector<Node*> _children;
	std::vector<std::string> _data;
};

class NTree
{
public:
	NTree() : _root(nullptr) {}

	//����
	void Insert(std::string name, std::string parentName);
	//�˻�
	Node* Find(std::string name) const;

	//��� ������ ������ �߰�
	void AddData(std::string data, std::string target);

	Node* GetRoot() const;
private:
	Node* StartFind(Node* current, std::string target) const;
	Node* _root;
};