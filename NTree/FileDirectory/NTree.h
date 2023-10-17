#pragma once
#include <string>
#include <vector>

//개선방안)
//클래스, 상속을 이용해서 노드상속받는 모든 노드를 NTree로 관리 가능하도록?
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

	//삽입
	void Insert(std::string name, std::string parentName);
	//검색
	Node* Find(std::string name) const;

	//노드 내부의 데이터 추가
	void AddData(std::string data, std::string target);

	Node* GetRoot() const;
private:
	Node* StartFind(Node* current, std::string target) const;
	Node* _root;
};