#pragma once
struct Node;
class Tree;
class TreeTraversal
{
public:
	//전위 순회
	void PreOrder(const Node* start) const;
	//중위 순회
	void InOrder(const Node* start) const;
	//후위 순회
	void PostOrder(const Node* start) const;
	//레벨 순서 순회
	void LevelOrder(const Node* start) const;
};