#pragma once
#include <string>
#include <vector>

class Node
{
public:
	Node(std::string name) :_name(name){}
	const std::string _name;
	std::vector<Node*> _children;
};