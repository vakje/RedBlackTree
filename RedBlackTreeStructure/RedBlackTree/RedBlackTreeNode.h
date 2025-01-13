
#pragma once
#include "RedBlackTree.h"


//Red 0 Black 1
enum ColorType { RED, BLACK };
class RedBlackTreeNode
{
	friend class RedBlackTree;
private:
	int value;
	ColorType Color;
	RedBlackTreeNode* parent;
	RedBlackTreeNode* left;
	RedBlackTreeNode* right;
public:
	//Constructor
	RedBlackTreeNode()
		:value(0), Color(RED), left(nullptr), right(nullptr), parent(nullptr)
	{}
	//Explicit Value Constructor 
	RedBlackTreeNode(int inValue, ColorType color = RED)
		:value(inValue),Color(color), left(nullptr), right(nullptr), parent(nullptr)
	{}
	
	//Getter Function 
	
	inline int getValue() 
	{
		return value;
	}
	inline ColorType getColor() 
	{
		return Color;
	}	
	
	 RedBlackTreeNode* get_left()  {
		return left;
	}
	 RedBlackTreeNode* get_right()  {
		 return right;
	 }
	 RedBlackTreeNode* get_parr() {
		 return parent;
	 }


	
};