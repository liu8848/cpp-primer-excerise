#pragma once
#include"TreeNode.h"
class BinStrTree
{
public:
	BinStrTree():root(new TreeNode()){}
	BinStrTree(const BinStrTree&bst):root(new TreeNode(*bst.root)){}
	BinStrTree& operator=(const BinStrTree&);
	~BinStrTree() {
		delete root;
	}
private:
	TreeNode* root;
};

inline
BinStrTree& BinStrTree::operator=(const BinStrTree& bst) {
	TreeNode* new_root = new TreeNode(*bst.root);
	delete root;
	root = new_root;
	return*this;
}

