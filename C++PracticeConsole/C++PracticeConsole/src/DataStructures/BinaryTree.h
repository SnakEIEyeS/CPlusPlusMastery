#pragma once

namespace DataStructures
{
	class BinaryTreeNode
	{
	public:
		BinaryTreeNode();
		BinaryTreeNode(const int& i_value);
		~BinaryTreeNode();

		int m_data;
		BinaryTreeNode* m_leftChild;
		BinaryTreeNode* m_rightChild;
	};

	class BinaryTree
	{
	public:
		BinaryTree();
		~BinaryTree();

		BinaryTreeNode* const Search(const int& i_searchValue);
		void Insert(const int& i_insertValue);

		inline int const GetNumNodes() { return m_numNodes; }
		inline BinaryTreeNode* const GetTreeRoot() { return m_rootNode; }

	private:
		int m_numNodes;
		BinaryTreeNode* m_rootNode;
	};
}
