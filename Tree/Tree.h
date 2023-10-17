#pragma once
#include <iostream>

struct Node;

class Tree
{
public:
	//트리생성
	static Tree* CreateTree(const std::string& position);
	//검색
	Node* Find(Node* root, const std::string& target);
	//parent 노드에 child노드 내려서 추가
	bool AddSubordinate(const std::string& parent, const std::string& child);


	//최상위노드반환
	const Node* GetRoot() const;
	void SetRoot(Node* target);
private:
	//생성은 CreateTree를 이용해서만 가능
	Tree() {};
	Node* _root;
};