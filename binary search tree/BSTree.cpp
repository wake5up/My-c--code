#include <iostream>
using namespace std;

template<class T>
struct BSTNode 
{
    BSTNode(const T& data=T())
        :_pLeft(nullptr)
        ,_pRight(nullptr)
        ,_data(data)
    {}
    BSTNode<T> *_pLeft;
    BSTNode<T> *_pRight;
    T _data;
};
template<class T>
class BSTree
{
    typedef BSTNode<T> Node;
public:
    BSTree()
        :_pRoot(nullptr)
    {}
    bool Insert(const T& data)
    {
        if(nullptr==_pRoot)
        {
            _pRoot=new Node(data);
            return true;
        }
        Node *pCur=_pRoot;
        Node *pParent=nullptr;
        while(pCur)
        {
            pParent=pCur;
            if(data<pCur->_data)
                pCur=pCur->_pLeft;
            else if(data>pCur->_data)
                pCur=pCur->_pRight;
            else 
                return false;
        }
        pCur=new Node(data);
        if(data<pParent->_data)
            pParent->_pLeft=pCur;
        else
            pParent->_pRight=pCur;
        return true;
    }
    bool Delete(const T& data)
    {
        if(nullptr==_pRoot)
            return false;
        Node *pParent=nullptr;
        Node *pCur=_pRoot;
        while(pCur)
        {
            if(data==pCur->_data)
                break;
            else if(data<pCur->_data)
            {
                pParent=pCur;
                pCur=pCur->_pLeft;
            }
            else
            {
                pParent=pCur;
                pCur=pCur->_pRight;
            }
        }
        if(nullptr==pCur)
            return false;
        Node *pDelNode=pCur;
        if(nullptr==pCur->_pLeft)
        {
            if(nullptr==pParent)
                _pRoot=pCur->_pRight;
            else
            {
                if(pCur==pParent->_pLeft)
                    pParent->_pLeft=pCur->_pRight;
                else
                    pParent->_pRight=pCur->_pRight;
            }
        }
        else if(nullptr==pCur->_pRight)
        {
            if(nullptr==pParent)
                _pRoot=pCur->_pLeft;
            else
            {
                if(pCur==pParent->_pLeft)
                    pParent->_pLeft=pCur->_pLeft;
                else
                    pParent->_pRight=pCur->_pLeft;
            }
        }
        else
        {
            Node *pDelNode=pCur->_pRight;
            pParent=pCur;
            while(pDelNode->_pLeft)
            {
                pParent=pDelNode;
                pDelNode=pDelNode->_pLeft;
            }
            pCur->_data=pDelNode->_data;
            if(pParent->_pLeft==pDelNode)
                pParent->_pLeft=pDelNode->_pRight;
            else
                pParent->_pRight=pDelNode->_pRight;
        }
        delete pDelNode;
        return true;
    }
    Node* Find(const T& data)
    {
        Node *pCur=_pRoot;
        while(pCur)
        {
            if(data==pCur->data)
                return pCur;
            else if(data<pCur->_data)
                pCur=pCur->_pLeft;
            else
                pCur=pCur->_pRight;
        }
        return nullptr;
    }
    Node* LeftMost()
    {
        if(nullptr==_pRoot)
            return nullptr;
        Node *pCur=_pRoot;
        while(pCur->_pLeft)
        {
            pCur=pCur->_pLeft;
        }
        return pCur;
    }
    Node* RightMost()
    {
        if(nullptr==_pRoot)
            return nullptr;
        Node *pCur=_pRoot;
        while(pCur->_pRight)
        {
            pCur=pCur->_pRight;
        }
        return pCur;
    }
    void InOrder()
    {
        _InOrder(_pRoot);
    }
private:
    void _InOrder(Node* pRoot)
    {
        if(pRoot)
        {
            _InOrder(pRoot->_pLeft);
            cout<<pRoot->_data<<" ";
            _InOrder(pRoot->_pRight);
        }
    }
private:
    Node *_pRoot;
};
void TestBSTree()
{
    BSTree<int> t;
    int a[]={5,3,4,1,7,8,2,6,0,9};
    for(auto e:a)
        t.Insert(e);
    t.InOrder();
    cout<<endl;
    cout<<t.LeftMost()->_data<<endl;
    cout<<t.RightMost()->_data<<endl;
    t.Delete(6);
    t.InOrder();
    cout<<endl;
}
int main()
{
    TestBSTree();
    return 0;
}
