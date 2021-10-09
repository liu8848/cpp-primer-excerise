#pragma once
#include<string>
class TreeNode
{
public:
	TreeNode():value(std::string()),count(new int(1)),left(nullptr),right(right) {}
	TreeNode(const TreeNode& tr) :value(tr.value), count(tr.count), left(tr.left), right(tr.right) { ++* count; }
	TreeNode& operator=(const TreeNode&);
	~TreeNode();
private:
	std::string value;
	int* count;
	TreeNode* left;
	TreeNode* right;
};

inline
TreeNode& TreeNode::operator=(const TreeNode& rhs) {
	++* rhs.count;
	if (-- * count == 0) {
		delete left;
		delete right;
		delete count;
	}
	value = rhs.value;
	left = rhs.left;
	right = rhs.right;
	count = rhs.count;
	return *this;
}

inline 
TreeNode::~TreeNode() {
	if (-- * count == 0) {
		delete left;
		delete right;
		delete count;
	}
}