#include "BinaryTree.h"

namespace DataStructures
{
	BinaryTreeNode::BinaryTreeNode()
	{
	}

	BinaryTreeNode::BinaryTreeNode(const int& i_value) : m_data(i_value), m_leftChild(nullptr), m_rightChild(nullptr)
	{
	}

	BinaryTreeNode::~BinaryTreeNode()
	{
		m_leftChild = nullptr;
		m_rightChild = nullptr;
	}

	BinaryTree::BinaryTree() : m_numNodes(0)
	{
	}

	BinaryTree::~BinaryTree()
	{
		//TODO SHMANE destroy all child nodes
	}

	BinaryTreeNode* const BinaryTree::Search(const int& i_searchValue)
	{
		BinaryTreeNode* pCurr = m_rootNode;
		while (pCurr != nullptr)
		{
			if (pCurr->m_data == i_searchValue)
			{
				break;
			}
			else if (i_searchValue < pCurr->m_data)
			{
				pCurr = pCurr->m_leftChild;
			}
			else
			{
				pCurr = pCurr->m_rightChild;
			}
		}
		return pCurr;
	}

	void BinaryTree::Insert(const int & i_insertValue)
	{
		if (m_rootNode == nullptr)
		{
			m_rootNode = new BinaryTreeNode(i_insertValue);
			++m_numNodes;
			return;
		}

		BinaryTreeNode* pCurr = m_rootNode;
		while (true)
		{
			if (i_insertValue < pCurr->m_data)
			{
				if (pCurr->m_leftChild == nullptr)
				{
					pCurr->m_leftChild = new BinaryTreeNode(i_insertValue);
					++m_numNodes;
					return;
				}
				else
				{
					pCurr = pCurr->m_leftChild;
				}
			}
			else
			{
				if (pCurr->m_rightChild == nullptr)
				{
					pCurr->m_rightChild = new BinaryTreeNode(i_insertValue);
					++m_numNodes;
					return;
				}
				else
				{
					pCurr = pCurr->m_rightChild;
				}
			}
		}
	}
}
