#pragma once
#include <string>

class Node;

class NTree
{
public:
	NTree() : _root(nullptr) {}

	//»ðÀÔ
	void insert(const std::string name,const std::string parentName);
	void insert(Node* target, Node* parent);
	//°Ë»ö
	Node* find(std::string name) const;

	Node* getRoot() const;
private:
	Node* startFind(Node* current, std::string target) const;
	Node* _root;
};