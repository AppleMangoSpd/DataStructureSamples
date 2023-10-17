#pragma once
struct Node
{
	std::string _position;
	Node* _first;
	Node* _second;

	//노드 생성시 매개변수 입력 강제
	Node(std::string pos, Node* first, Node* second)
		: _position(pos), _first(first), _second(second) {}
};
