#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
	int value;
	struct ListNode *pnext;
};

void PrintList1(ListNode *phead)
{
	if (phead != nullptr)
	{
		if (phead->pnext != nullptr)
		{
			PrintList1(phead->pnext);
		}
		cout << phead->value<<" ";
	}
}
void PrintList2(ListNode *phead)
{
	stack<ListNode*> s;
	ListNode *pNode = phead;
	while (pNode != nullptr)
	{
		s.push(pNode);
		pNode = pNode->pnext;
	}
	while (!s.empty())
	{
		pNode = s.top();
		cout << pNode->value << " ";
		s.pop();
	}
}

int main()
{
	ListNode* pHead = new ListNode();
	ListNode *pNew,*pTemp;
	int a[5] = { 1, 4, 2, 5, 6 };
	pHead->value = a[0];
	pTemp = pHead;
	for (int i = 1; i < 5; i++)
	{
		pNew = new ListNode;
		pNew->value = a[i];
		pNew->pnext = NULL;
		pTemp->pnext = pNew;
		pTemp = pNew;
	}
	cout << "递归方法:" << endl;
	PrintList1(pHead);
	cout << endl;
	cout << "栈方法:" << endl;
	PrintList2(pHead);
	cout << endl;
	return 0;
}