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

	//검색
	const Node* Find(const int target) const;
	//삽입
	void Insert(const int target);
	//중위 순회 (오름차순)
	void InOrder() const;
	//내림차순
	void DescendingOrder() const;
	//삭제
	void DeleteValue(const int target);

private:
	const Node* Find_impl(const Node* current, const int target) const;
	void Insert_impl(Node* current, const int target);
	void InOrder_impl(const Node* start) const;
	void DescendingOrder_impl(const Node* start) const;
	Node* Delete_impl(Node* start, const int target);
	//후속노드 검색
	Node* Successor(Node* start) const;
};