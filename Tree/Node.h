#pragma once
struct Node
{
	std::string _position;
	Node* _first;
	Node* _second;

	//��� ������ �Ű����� �Է� ����
	Node(std::string pos, Node* first, Node* second)
		: _position(pos), _first(first), _second(second) {}
};
