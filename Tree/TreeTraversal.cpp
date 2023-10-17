#include "TreeTraversal.h"

#include <iostream>
#include <queue>
#include "Tree.h"
#include "Node.h"
void TreeTraversal::PreOrder(const Node* start) const
{
	if (!start)
	{
		return;
	}
	std::cout << start->_position << ", ";
	PreOrder(start->_first);
	PreOrder(start->_second);
}

void TreeTraversal::InOrder(const Node* start) const
{
	if (!start)
	{
		return;
	}
	InOrder(start->_first);
	std::cout << start->_position << ", ";
	InOrder(start->_second);
}

void TreeTraversal::PostOrder(const Node* start) const
{
	if (!start)
	{
		return;
	}
	PostOrder(start->_first);
	PostOrder(start->_second);
	std::cout << start->_position << ", ";
}

void TreeTraversal::LevelOrder(const Node* start) const
{
	if (!start)
	{
		return;
	}
	std::queue<const Node*> nodeQueue;
	nodeQueue.push(start);

	while (!nodeQueue.empty())
	{
		int size = nodeQueue.size();
		for (int i = 0; i < size; i++)
		{
			const Node* current = nodeQueue.front();
			nodeQueue.pop();

			std::cout << current->_position << ", ";
			if(current->_first)
			{
				nodeQueue.push(current->_first);
			}
			if (current->_second)
			{
				nodeQueue.push(current->_second);
			}
		}
		std::cout << std::endl;
	}
}
