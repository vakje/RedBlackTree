#pragma once
#include "RedBlackTree.h"//implementation
#include "RedBlackTreeNode.h"
#include <algorithm>

// copy constructori 
RedBlackTree::RedBlackTree(const RedBlackTree& orig)
{
	
	if (orig.root != nullptr) {

		
		root = new RedBlackTreeNode();
		
		root->value=orig.root->value;
		root->left= copyRedblackTree(orig.root->left);
		root->right= copyRedblackTree(orig.root->right);
		root->Color=orig.root->Color;
	}
	
	else {
		root = nullptr;
	}

}
RedBlackTreeNode* RedBlackTree::copyRedblackTree(RedBlackTreeNode* curr)
{
	if (curr == nullptr) {
		
		return nullptr;
	}
	
	RedBlackTreeNode* R = new RedBlackTreeNode();
	R->value=curr->value;
	R->left= copyRedblackTree(curr->left);
	R->right= copyRedblackTree(curr->right);
	R->Color = curr->Color;
	return R;

}
// default constructor 
RedBlackTree::RedBlackTree() : root(nullptr){}

// destructor with  function init to delete all nodes recursively  
RedBlackTree::~RedBlackTree()
{
	delete_all_nodes(root);
}


// preorder
void RedBlackTree::preorder(RedBlackTreeNode* curr) {
	if (curr != nullptr) {
		std::cout << curr->value << " " << curr->Color << " " << std::endl;
		preorder(curr->left);
		preorder(curr->right);
	}
}
// same function but for user (wrapper)
void RedBlackTree::display() {
	preorder(root);
}

// searcher function recursive
RedBlackTreeNode* RedBlackTree::searcher(RedBlackTreeNode* curr, int val) {
	if (curr == nullptr || curr->getValue() == val) {
		return curr;
		
	}
	
	if (curr->getValue() < val) {
		return searcher(curr->get_right(), val);
	}
	
	return searcher(curr->get_left(), val);

}


// left rotation valid
void RedBlackTree::leftRotate(RedBlackTreeNode* newnode)
{
	//  temp container for child node 
	RedBlackTreeNode* Sticker = newnode->right;

	// update node's right child it's pointer to newnode->right->left  
	newnode->right = Sticker->left;

	// update temp node's partents linker  
	if (Sticker->left != nullptr) Sticker->left->parent = newnode;

	// update temp's parent linker 
	Sticker->parent = newnode->parent;

	// update root if newnode was a root itself
	(newnode->parent == nullptr) ? (this->root = Sticker) :
		(newnode == newnode->parent->left ? newnode->parent->left = Sticker : newnode->parent->right = Sticker);

	// adjust linkers
	Sticker->left = newnode;
	newnode->parent = Sticker;
}

void RedBlackTree::rightRotate(RedBlackTreeNode* newnode)
{
	// temp to store left child 
	RedBlackTreeNode* sticker1 = newnode->left;

	// updating current node left linker 
	newnode->left = sticker1->right;

	// update the linker to parent 
	if (sticker1->right != nullptr) sticker1->right->parent = newnode;

    // linker to parent updating to newnodes parent 
	sticker1->parent = newnode->parent;

	// update root if newnode was a root itself
	(newnode->parent == nullptr) ? (this->root = sticker1) :
		(newnode == newnode->parent->right ? newnode->parent->right = sticker1 : newnode->parent->left = sticker1);

	// linker adjusting 
	sticker1->right = newnode;
	newnode->parent = sticker1;
}



//assignment operator 
RedBlackTree& RedBlackTree::operator=(const RedBlackTree& rbt)
{
	
	if (this != &rbt) {
		
		if (root != nullptr) {
		
		
			delete_all_nodes(root);
			
			root = copyRedblackTree(rbt.root);
		}
		
	}
	
	return *this;

}
void RedBlackTree::delete_all_nodes(RedBlackTreeNode* NODE) {
	if (NODE != nullptr) {
		delete_all_nodes(NODE->left);
		delete_all_nodes(NODE->right);
		delete NODE;

	}


}

//function to validate tree after adding new node
void RedBlackTree::add_fix(RedBlackTreeNode* pt)
{
	RedBlackTreeNode* parrrent = nullptr;
	RedBlackTreeNode* parrrentsp = nullptr;
	while ((pt != root) && (pt->Color != BLACK) &&
		(pt->parent->Color == RED)) {
		parrrent = pt->parent;
		parrrentsp = pt->parent->parent;
		
		if (parrrent == parrrentsp->left) {
			
			RedBlackTreeNode* auntofpt = parrrentsp->right;
						  
			if (auntofpt != nullptr && auntofpt->Color == RED) {
				parrrentsp->Color = RED;
				parrrent->Color = BLACK;
				auntofpt->Color = BLACK;
				pt = parrrentsp;
			}
			else {
				
				if (pt == parrrent->right) {
					leftRotate(parrrent);
					pt = parrrent;
					parrrent = pt->parent;
				}
				
				rightRotate(parrrentsp);
				std::swap(parrrent->Color, parrrentsp->Color);
				pt = parrrent;
			}
		}	
		else {
		 
			RedBlackTreeNode* auntofpt = parrrentsp->left;
			
			if ((auntofpt != nullptr) && (auntofpt->Color == RED)) {
				parrrentsp->Color = RED;
				parrrent->Color = BLACK;
				auntofpt->Color = BLACK;
				pt = parrrentsp;
			}
			else {
				
				if (pt == parrrent->left) {
					rightRotate(parrrent);
					pt = parrrent;
					parrrent = pt->parent;
				}
				
				leftRotate(parrrentsp);
				std::swap(parrrent->Color, parrrentsp->Color);
				pt = parrrent;
			}
		}
	}
	root->Color = BLACK;
}
//adding new node to tree
void RedBlackTree::add_inRBT(int val)
{
	
	RedBlackTreeNode* nnode = new RedBlackTreeNode(val);
    nnode->Color = RED;
	if (root == nullptr) {
		nnode->Color = BLACK;
		nnode->parent = nullptr;
		root = nnode; 
	}
	else {
		
		RedBlackTreeNode* temp = root;
		RedBlackTreeNode* parrrrent = nullptr;
		
		while (temp != nullptr) {
			
			parrrrent = temp;
			 if (nnode->value == temp->value) {
				delete nnode;
				std::cout << "ukve iyo shemotanili aseti\n";
				return;
			  }
			
			if (nnode->value < temp->value) {
				
				if (temp->left == nullptr) {
					temp->left = nnode;				
					nnode->parent = temp;					
					break;
				}
				
				else { temp = temp->left; }
			}
			else {
			
				if (temp->right == nullptr) {
					temp->right = nnode;				
					nnode->parent = temp;				
					break;
				}
				else { 
					temp = temp->right; 
				}
			}						
		}	
		
		add_fix(nnode);
	}
	

}
RedBlackTreeNode* RedBlackTree::searcher_preorder(RedBlackTreeNode* nmode,int val)
{
	
	if (nmode == nullptr) {
		return nullptr;
	}
	
	if (nmode->value == val) {
		return nmode;
	}
	
	RedBlackTreeNode* leftsearchings = searcher_preorder(nmode->left, val);
	if (leftsearchings != nullptr) {
		return leftsearchings;
	}
	
	
	return searcher_preorder(nmode->right, val);


}
RedBlackTreeNode* RedBlackTree::searcher_postorder(RedBlackTreeNode* nmode,int val)
{
	
	if (nmode == nullptr) {
		return nullptr;
	}
	
	RedBlackTreeNode* leftsearchings = searcher_postorder(nmode->left, val);
	if (leftsearchings != nullptr) {
		return leftsearchings;
	}
	
	RedBlackTreeNode* rightsearchings = searcher_postorder(nmode->right, val);
	if (rightsearchings != nullptr) {
		return rightsearchings;
	}
	
	if (nmode->value == val) {
		return nmode;
	}
	
	return nullptr;
}

 
