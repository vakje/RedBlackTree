
#pragma once
#include "RedBlackTree.h"
#include "RedBlackTreeNode.h"



int main() {
	
	int value1 = 4;
	int value2 = 33;
	int value = 17;
	
	RedBlackTree tree;

	tree.add_inRBT(20);
	tree.add_inRBT(19);
	tree.add_inRBT(18);
	tree.add_inRBT(17);
	tree.add_inRBT(4);
	tree.add_inRBT(60);
	tree.add_inRBT(80); 
	tree.add_inRBT(1);
	tree.add_inRBT(22);
	tree.add_inRBT(44);
	tree.add_inRBT(29);
	tree.add_inRBT(120);
	tree.add_inRBT(23);
	tree.add_inRBT(4);
	
	
	tree.display();
	
	std::cout << "::::::: root:::::: " << tree.get_root()->getValue()<< "::::::: root:::::: " << std::endl;
	
	
	std::cout << "-----------------------------------copy constructor--------------------------------------" << std::endl;
	RedBlackTree tree1(tree);
	tree1.display();
	std::cout << "=========================postsearch===========================================" << std::endl;
	
	RedBlackTreeNode*node1=tree.searcher_postorder(tree.get_root(),value1);
	if (node1 != nullptr) {
		std::cout << "Node with value " << value1 << " found" << std::endl;
	}
	else {
		std::cout << "Node with value " << value1 << " not found" << std::endl;
	}

	std::cout << "=========================presearcher============================================" << std::endl;
	RedBlackTreeNode* node2=tree.searcher_preorder(tree.get_root(),value2);
	if (node2 != nullptr) {
		std::cout << "Node with value " << value2 << " found" << std::endl;
	}
	else {
		std::cout << "Node with value " << value2 << " not found" << std::endl;
	}
	
	
	RedBlackTreeNode* node = tree.searcher(tree.get_root(), value);

	std::cout << "=========================searchervalidation=====================================" << std::endl;
	if (node != nullptr) {
		std::cout << "Node with value " << value << " found" << std::endl;
	}
	else {
		std::cout << "Node with value " << value  << " not found" << std::endl;
	}
	
	
}
