#pragma once

#include <queue>
#include <vector>

template <class W>
//创建Huffman树节点
struct HTNode
{
	HTNode(const W& weight)
		:_pLeft(nullptr)
		, _pRight(nullptr)
		, _pParent(nullptr)
		, _weight(weight)
	{}
	HTNode<W>* _pLeft;
	HTNode<W>* _pRight;
	HTNode<W>* _pParent;
	W _weight;
};

template<class W>
class Compare
{
public:
	bool operator()(HTNode<W>* pLeft, HTNode<W>* pRight)
	{
		if (pLeft->_weight > pRight->_weight)
			return true;
		return false;
	}
};

template<class W>
class HuffmanTree
{
	typedef HTNode<W> Node;
public:
	HuffmanTree()
		:_pRoot(nullptr)
	{}
	~HuffmanTree()
	{
		Destroy(_pRoot);
	}
	void CreateHuffmanTree(const std::vector<W>& v, const W& invalid)
	{
		if (v.empty())
			return;
		std::priority_queue<Node*, std::vector<Node*>, Compare<W>> hp;
		for (size_t i = 0; i < v.size(); ++i)
		{
			if (v[i] != invalid)
				hp.push(new Node(v[i]));
		}
		while (hp.size()>1)
		{
			Node* pLeft = hp.top();
			hp.pop();
			Node* pRight = hp.top();
			hp.pop();
			Node* pParent = new Node(pLeft->_weight+pRight->_weight);
			pParent->_pLeft = pLeft;
			pLeft->_pParent = pParent;
			pParent->_pRight = pRight;
			pRight->_pParent = pParent;

			hp.push(pParent);
		}
		_pRoot = hp.top();
	}
	Node* GetpRoot()
	{
		return _pRoot;
	}
private:
	void Destroy(Node*& pRoot)
	{
		if (pRoot)
		{
			Destroy(pRoot->_pLeft);
			Destroy(pRoot->_pRight);
			delete pRoot;
			pRoot = nullptr;
		}
	}
private:
	Node* _pRoot;
};