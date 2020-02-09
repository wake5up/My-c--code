//合并两个排序的链表

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
	ListNode* Merge(ListNode* pHead1, ListNode* pHead2)
	{
		if (pHead1 == nullptr)
			return pHead2;
		else if (pHead2 == nullptr)
			return pHead1;
		ListNode* pMergeNode = nullptr;
		if (pHead1->val<pHead2->val)
		{
			pMergeNode = pHead1;
			pMergeNode->next = Merge(pHead1->next, pHead2);
		}
		else
		{
			pMergeNode = pHead2;
			pMergeNode->next = Merge(pHead1, pHead2->next);
		}
		return pMergeNode;
	}
};