// Lab7.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "Lab7.h"
#include <string>
#include <array>
#include <locale>
#include <stdio.h> 
#include <stdlib.h> 
#include <iostream>
#include <vector>

using namespace std;

Node::Node(): m_value(""), m_Rightptr(nullptr), m_Leftptr(nullptr)
{

}

Node::Node(std::string value): m_value(value), m_Rightptr(nullptr), m_Leftptr(nullptr)
{
}

Node::Node(std::string value, Node * Rightptr, Node * Leftptr): m_value(value), m_Rightptr(Rightptr), m_Leftptr(Leftptr)
{

}

void Node::SetItem(std::string value)
{
	m_value = value;
}

std::string Node::GetItem()
{
	return m_value;
}

void Node::SetRight(Node * Rightptr)
{
	m_Rightptr = Rightptr;
}

void Node::SetLeft(Node * Leftptr)
{
	m_Leftptr = Leftptr;
}

Node * Node::GetRight()
{
	return m_Rightptr;
}

Node * Node::GetLeft()
{
	return m_Leftptr;
}

bool Node::IsLeaf()
{
	if (m_Rightptr == nullptr && m_Leftptr == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

Node::~Node()
{

}

BinTree::BinTree()
{
	m_size = 0;
	m_root = NULL;
	count = 0;
	Went = false;
}

void BinTree::DisplayVector()
{
	for (int i = 0; i < StringVector.size(); i++)
	{
		cout << StringVector[i] << endl;
	}
}

bool BinTree::InsertNode(Node * NodeToInsert, Node * NodeRecur)
{
	count++;
	if (m_size == 0) 
	{
		m_root = NodeToInsert;
		m_size++;
		count = 0;
		return true;
	}
	else if (count <= 1)
	{
		NodeRecur = m_root;
	}

	std::string InsertedValue = NodeToInsert->GetItem();
	std::string RootValue = NodeRecur->GetItem();
	std::locale loc;

	for (int i = 0; i < InsertedValue.size(); i++)
	{
		if (std::isupper(InsertedValue[i], loc))
		{
			std::tolower(InsertedValue[i], loc);
		}
	}

	for (int i = 0; i < RootValue.size(); i++)
	{
		if (std::isupper(RootValue[i], loc))
		{
			std::tolower(RootValue[i], loc);
		}
	}

	bool InsertedGreater = false;
	bool InsertedLower = false;

	if (InsertedValue.size() < RootValue.size())
	{
		for (int i = 0; i < InsertedValue.size(); i++)
		{
			if (InsertedValue[i] > RootValue[i])
			{
				InsertedGreater = true;
				break;
			}
			else if (InsertedValue[i] < RootValue[i])
			{
				InsertedLower = true;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < RootValue.size(); i++)
		{
			if (InsertedValue[i] > RootValue[i])
			{
				InsertedGreater = true;
				break;
			}
			else if (InsertedValue[i] < RootValue[i])
			{
				InsertedLower = true;
				break;
			}
		}
	}

	if (InsertedGreater)
	{
		if (NodeRecur->IsLeaf() || NodeRecur->GetRight() == nullptr)
		{
			NodeRecur->SetRight(NodeToInsert);
			m_size++;
			count = 0;
			return true;
		}
		else
		{
			NodeRecur = NodeRecur->GetRight();
			InsertNode(NodeToInsert, NodeRecur);
		}
	}
	else if (InsertedLower)
	{
		if (NodeRecur->IsLeaf() || NodeRecur->GetLeft() == nullptr)
		{
			NodeRecur->SetLeft(NodeToInsert);
			m_size++;
			count = 0;
			return true;
		}
		else
		{
			NodeRecur = NodeRecur->GetLeft();
			InsertNode(NodeToInsert, NodeRecur);
		}
	}
}

Node * BinTree::FindNode(std::string value, Node * root)
{
	std::string RootValue = root->GetItem();
	std::locale loc;

	if (root->GetItem() == value)
	{
		return root;
	}

	for (int i = 0; i < value.size(); i++)
	{
		if (std::isupper(value[i], loc))
		{
			std::tolower(value[i], loc);
		}
	}

	for (int i = 0; i < RootValue.size(); i++)
	{
		if (std::isupper(RootValue[i], loc))
		{
			std::tolower(RootValue[i], loc);
		}
	}

	bool InsertedGreater = false;
	bool InsertedLower = false;

	if (value.size() < RootValue.size())
	{
		for (int i = 0; i < value.size(); i++)
		{
			if (value[i] > RootValue[i])
			{
				InsertedGreater = true;
				break;
			}
			else if (value[i] < RootValue[i])
			{
				InsertedLower = true;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < RootValue.size(); i++)
		{
			if (value[i] > RootValue[i])
			{
				InsertedGreater = true;
				break;
			}
			else if (value[i] < RootValue[i])
			{
				InsertedLower = true;
				break;
			}
		}
	}

	if (InsertedGreater)
	{
		root = root->GetRight();
		return FindNode(value, root);
	}
	else if (InsertedLower)
	{
		root = root->GetLeft();
		return FindNode(value, root);
	}
}

int BinTree::GetTreeSize()
{
	return m_size;
}

void BinTree::GetAllAscending(Node * root)
{
	if (root == NULL)
	{
		return;
	}

	GetAllAscending(root->GetLeft());

	StringVector.push_back(root->GetItem());

	GetAllAscending(root->GetRight());
}

void BinTree::ShowAscending()
{
	for (int i = 0; i < StringVector.size(); i++)
	{
		cout << StringVector[i] << endl;
	}
}

void BinTree::GetAllAscendingPostDelete(Node * root)
{
	if (root == NULL)
	{
		return;
	}

	GetAllAscendingPostDelete(root->GetLeft());

	StringVectorPostDelete.push_back(root->GetItem());

	GetAllAscendingPostDelete(root->GetRight());
}

void BinTree::ShowAscendingPostDelete()
{
	for (int i = 0; i < StringVectorPostDelete.size(); i++)
	{
		cout << StringVectorPostDelete[i] << endl;
	}
}

void BinTree::GetAllDescending()
{
	for (int i = StringVector.size() - 1; i >= 0; i--)
	{
		cout << StringVector[i] << endl;
	}
}

bool BinTree::EmptyTree(Node * TempNode, Node * Previous)
{
	Node * Root = GetRoot();
	Node * traversal;

	if (TempNode == nullptr)
	{ 
		traversal = Root;
	}
	else 
	{
		traversal = TempNode;
	}

	if (m_root->IsLeaf())
	{
		delete m_root;
		m_size--;
		return true;
	}
	else if (traversal->GetLeft() != NULL) 
	{
		Went = true;
		Previous = traversal;
		traversal = traversal->GetLeft();
		EmptyTree(traversal, Previous);
	}
	else if (traversal->GetRight() != NULL) 
	{
		Went = false;
		Previous = traversal;
		traversal = traversal->GetRight();
		EmptyTree(traversal, Previous);
	}
	else if (traversal->IsLeaf())
	{
		if (Went)
		{
			Previous->SetLeft(NULL);
		}
		else
		{
			Previous->SetRight(NULL);
		}
		free(traversal);
		m_size--;
		Node * top = Root;
		EmptyTree(top, nullptr);
	}
}

Node * BinTree::RemoveValue(std::string value, Node * root, Node * Previous)
{
	std::string RootValue = root->GetItem();
	std::locale loc;

	if (root->GetItem() == value)
	{
		if (root->IsLeaf())
		{
			Previous->SetLeft(nullptr);
			Previous->SetRight(nullptr);
			delete root;
			root->SetLeft(nullptr);
			root->SetRight(nullptr);
			m_size--;
			return root;
		} 
		else if (root->GetLeft() != NULL && root->GetRight() == NULL)
		{
			if (TestForRemove)
			{
				Previous->SetRight(root->GetLeft());
				delete root;
				root->SetLeft(nullptr);
				root->SetRight(nullptr);
				m_size--;
				return root;
			}
			else if (!TestForRemove)
			{
				Previous->SetLeft(root->GetLeft());
				delete root;
				root->SetLeft(nullptr);
				root->SetRight(nullptr);
				m_size--;
				return root;
			}
		}
		else if (root->GetLeft() == NULL && root->GetRight() != NULL)
		{
			if (TestForRemove)
			{
				Previous->SetRight(root->GetLeft());
				delete root;
				root->SetLeft(nullptr);
				root->SetRight(nullptr);
				m_size--;
				return root;
			}
			else if (!TestForRemove)
			{
				Previous->SetLeft(root->GetLeft());
				delete root;
				root->SetLeft(nullptr);
				root->SetRight(nullptr);
				m_size--;
				return root;
			}
		}
		else if (root->GetLeft() != NULL && root->GetRight() != NULL)
		{
			if (TestForRemove)
			{
				Previous->SetLeft(root->GetLeft());
				Node * TempNode = Previous->GetLeft();
				TempNode->SetRight(root->GetRight());
				delete root;
				root->SetLeft(nullptr);
				root->SetRight(nullptr);
				m_size--;
				return root;
			}
			else if (!TestForRemove)
			{
				Previous->SetRight(root->GetLeft());
				Node * TempNode = Previous->GetLeft();
				TempNode->SetRight(root->GetRight());
				delete root;
				root->SetLeft(nullptr);
				root->SetRight(nullptr);
				m_size--;
				return root;
			}
		}
	}

	for (int i = 0; i < value.size(); i++)
	{
		if (std::isupper(value[i], loc))
		{
			std::tolower(value[i], loc);
		}
	}

	for (int i = 0; i < RootValue.size(); i++)
	{
		if (std::isupper(RootValue[i], loc))
		{
			std::tolower(RootValue[i], loc);
		}
	}

	bool InsertedGreater = false;
	bool InsertedLower = false;

	if (value.size() < RootValue.size())
	{
		for (int i = 0; i < value.size(); i++)
		{
			if (value[i] > RootValue[i])
			{
				InsertedGreater = true;
				TestForRemove = InsertedGreater;
				break;
			}
			else if (value[i] < RootValue[i])
			{
				InsertedLower = true;
				TestForRemove = !InsertedLower;
				break;
			}
		}
	}
	else
	{
		for (int i = 0; i < RootValue.size(); i++)
		{
			if (value[i] > RootValue[i])
			{
				InsertedGreater = true;
				TestForRemove = InsertedGreater;
				break;
			}
			else if (value[i] < RootValue[i])
			{
				InsertedLower = true;
				TestForRemove = !InsertedLower;
				break;
			}
		}
	}

	if (InsertedGreater)
	{
		Previous = root;
		root = root->GetRight();
		return RemoveValue(value, root, Previous);
	}
	else if (InsertedLower)
	{
		Previous = root;
		root = root->GetLeft();
		return RemoveValue(value, root, Previous);
	}
}

Node * BinTree::GetRoot()
{
	return m_root;
}

void BinTree::SetRoot(Node * RootToSet)
{
	m_root = RootToSet;
}