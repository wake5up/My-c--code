//·´×ªÁ´±í

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};*/
class Solution {
public:
	ListNode* ReverseList(ListNode* pHead) {
		ListNode* pReverNode = nullptr;
		ListNode* pNode = pHead;
		ListNode* pPre = nullptr;
		while (pNode != nullptr)
		{
			ListNode* pNext = pNode->next;
			if (pNext == nullptr)
			{
				pReverNode = pNode;
			}
			pNode->next = pPre;
			pPre = pNode;
			pNode = pNext;
		}
		return pReverNode;
	}
};