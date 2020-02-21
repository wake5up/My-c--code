//链表中入口环的结点

/*
struct ListNode {
int val;
struct ListNode *next;
ListNode(int x) :
val(x), next(NULL) {
}
};
*/
class Solution {
public:
	ListNode* MeetingNode(ListNode* pHead)
	{
		if (pHead == nullptr)
			return nullptr;
		ListNode* slow = pHead->next;
		if (slow == nullptr)
			return nullptr;
		ListNode* fast = slow->next;
		while (fast != nullptr&&fast->next->next != nullptr)
		{
			if (fast == slow)
				return fast;
			else
			{
				fast = fast->next->next;
				slow = slow->next;
			}
		}
		return nullptr;
	}
	ListNode* EntryNodeOfLoop(ListNode* pHead)
	{
		int count;
		ListNode* flag = MeetingNode(pHead);
		if (flag == nullptr)
			return nullptr;
		else
		{
			count = 1;
			ListNode* flag1 = flag->next;
			while (flag != flag1)
			{
				flag1 = flag1->next;
				++count;
			}
		}
		ListNode* AHead = pHead;
		while (count--)
		{
			AHead = AHead->next;
		}
		ListNode* BHead = pHead;
		while (AHead != BHead)
		{
			AHead = AHead->next;
			BHead = BHead->next;
		}
		return AHead;
	}
};