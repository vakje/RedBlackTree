
#pragma once
#include "RedBlackTreeNode.h"
#include <iostream>

using Node = RedBlackTreeNode;
class  RedBlackTree {
	RedBlackTreeNode* root;	
public:	
	RedBlackTreeNode* get_root() { return root; }
	RedBlackTree(const RedBlackTree&);
	RedBlackTree();
	~RedBlackTree();
	RedBlackTree& operator=(const RedBlackTree&);
	RedBlackTreeNode* searcher(RedBlackTreeNode*,int);
	RedBlackTreeNode* searcher_preorder(RedBlackTreeNode*,int);
	RedBlackTreeNode* searcher_postorder(RedBlackTreeNode*,int);
	void preorder(RedBlackTreeNode *);//  preorder print root then left then right
	void add_inRBT(int);// for user to input node (wrapper)	
	void display();// display 
private:
	void delete_all_nodes(RedBlackTreeNode*);// for destructor to delete tree with recursion 
	RedBlackTreeNode* copyRedblackTree(RedBlackTreeNode*);// deepcopy with recursion to use in copy constructor 
	void  add_fix( RedBlackTreeNode* );	// fix add to validate tree
   //rotations 
	void leftRotate(RedBlackTreeNode*);
	void rightRotate(RedBlackTreeNode*);	
};

