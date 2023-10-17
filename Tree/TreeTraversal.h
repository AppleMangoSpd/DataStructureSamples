#pragma once
struct Node;
class Tree;
class TreeTraversal
{
public:
	//���� ��ȸ
	void PreOrder(const Node* start) const;
	//���� ��ȸ
	void InOrder(const Node* start) const;
	//���� ��ȸ
	void PostOrder(const Node* start) const;
	//���� ���� ��ȸ
	void LevelOrder(const Node* start) const;
};