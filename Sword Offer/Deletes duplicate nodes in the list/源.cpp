/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
//删除链表中重复的结点
class Solution {
public:
	ListNode* deleteDuplication(ListNode* pHead)
	{
		if (pHead == nullptr)
			return pHead;
		ListNode *pCur = pHead;
		ListNode *pPre = nullptr;
		ListNode *pNext = nullptr;
		while (pCur)
		{
			if (pCur->next&&pCur->next->val == pCur->val)
			{
				pNext = pCur->next;
				while (pNext->next&&pCur->val == pNext->next->val)
				{
					pNext = pNext->next;
				}
				if (pCur == pHead)
				{
					pHead = pNext->next;
				}
				else
				{
					pPre->next = pNext->next;
				}
				pCur = pNext->next;
			}
			else
			{
				pPre = pCur;
				pCur = pCur->next;
			}
		}
		return pHead;
	}
};