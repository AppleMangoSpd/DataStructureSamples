#pragma once
#include<vector>
#include<string>

class SkillNode
{
public:
	std::vector<SkillNode*> _children;
	std::string _name;
	int _cost;
};

class NTree
{
public:
	NTree();

	//�˻�
	SkillNode* Find(const std::string name) const;
	//����
	void Insert(const std::string name, const std::string parentName);
	void Insert(const std::string name, std::vector<std::string>& parentNames);

	//�̹� �ִ� ���?
	const bool IsExist(const std::string name) const;

	SkillNode* GetRoot() const;

	void InOrder() const;
	void StartInOrder(const SkillNode* start) const;
private:
	SkillNode* StartFind(SkillNode* current, std::string target) const;

	SkillNode* _root;
};