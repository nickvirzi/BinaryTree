// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the LAB7_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// LAB7_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LAB7_EXPORTS
#define LAB7_API __declspec(dllexport)
#else
#define LAB7_API __declspec(dllimport)
#endif

#include <string>
#include <array>
#include <vector>

class LAB7_API Node
{
private:
	std::string m_value;
	Node * m_Leftptr;
	Node * m_Rightptr;
public:
	Node();
	Node(std::string value);
	Node(std::string value, Node * Rightptr, Node * Leftptr);
	void SetItem(std::string value);
	std::string GetItem();
	void SetRight(Node * Rightptr);
	void SetLeft(Node * Leftptr);
	Node * GetRight();
	Node * GetLeft();
	bool IsLeaf();
	virtual ~Node();

};

class LAB7_API BinTree
{
private:
	Node * m_root;
public:
	BinTree();
	int m_size;
	int count;
	bool Went;
	bool TestForRemove;
	std::vector <std::string> StringVector;
	std::vector <std::string> StringVectorPostDelete;
	void DisplayVector();
	bool InsertNode(Node * NodeToInsert, Node * NodeRecur);
	Node * FindNode(std::string value, Node * root);
	int GetTreeSize();
	void GetAllAscending(Node * root);
	void ShowAscending();
	void GetAllAscendingPostDelete(Node * root);
	void ShowAscendingPostDelete();
	void GetAllDescending();
	bool EmptyTree(Node * ToEmpty, Node * Previous);
	Node * RemoveValue(std::string value, Node * root, Node * Previous);
	Node * GetRoot();
	void SetRoot(Node * RootToSet);
};