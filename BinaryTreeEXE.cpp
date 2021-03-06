// Lab7EXE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "header.h"
#include "Lab7.h"
#include <iostream>

using namespace std;

int main()
{
	Node * NewNode = new Node("Halloween");
	Node * NewNode2 = new Node("A Nightmare On Elm Street");
	Node * NewNode3 = new Node("Hocus Pocus");
	Node * NewNode4 = new Node("Beetlejuice");
	BinTree BinaryTree;
	BinaryTree.InsertNode(NewNode, NULL);
	BinaryTree.InsertNode(NewNode2, NULL);
	BinaryTree.InsertNode(NewNode3, NULL);
	BinaryTree.InsertNode(NewNode4, NULL);
	Node * Yeet = BinaryTree.FindNode("Beetlejuice", BinaryTree.GetRoot());
	int Size = BinaryTree.GetTreeSize();
	BinaryTree.GetAllAscending(BinaryTree.GetRoot());
	cout << "Getting ascending order." << endl;
	cout << endl;
	BinaryTree.ShowAscending();
	cout << endl;
	cout << "Getting descending order." << endl;
	cout << endl;
	BinaryTree.GetAllDescending();
	BinaryTree.RemoveValue("Beetlejuice", BinaryTree.GetRoot(), nullptr);
	cout << endl;
	cout << "Removing Value Beetlejuice" << endl;
	BinaryTree.GetAllAscendingPostDelete(BinaryTree.GetRoot());
	cout << "Getting ascending order." << endl;
	cout << endl;
	BinaryTree.ShowAscendingPostDelete();
	cout << endl;
	cout << "Emptying tree" << endl;
	BinaryTree.EmptyTree(nullptr, nullptr);
	cout << "Tree emptied" << endl;
}