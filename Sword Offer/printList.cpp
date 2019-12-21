#include <iostream>
#include <stack>
using namespace std;
typedef struct ListNode
{
    int value;
    struct ListNode *pnext;
}ListNode;

void PrintList(ListNode *phead)
{
    stack<ListNode*> s;
    ListNode *pNode=phead;
    while(pNode!=nullptr)
    {
        s.push(pNode);
        cout<<pNode->value<<" ";
        pNode=pNode->pnext;
    }
    cout<<endl;
    while(!s.empty())
    {
        pNode=s.top();
        cout<<pNode->value<<" ";
        s.pop();
    }
}

int main()
{
    ListNode* pHead = new ListNode();
    ListNode *pNew, *pTemp;
    pTemp = pHead;
    int a[5] = { 1, 4, 2, 5, 6  };
    for (int i = 0; i < 5; i++)
    {
        pNew = new ListNode;
        pNew->value = a[i];
        pNew->pnext = NULL;
        pTemp->pnext = pNew;
        pTemp = pNew;
    }
    ListNode *temp = pHead->pnext;//去掉初始头结点
    cout << "利用栈方法从尾到头反过来打印链表的值如下：" << endl;
    PrintList(temp);
    cout << endl;
    return 0;
}
