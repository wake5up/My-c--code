//两个链表的第一个公共节点

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
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
        if(pHead1==nullptr||pHead2==nullptr)
            return nullptr;
        int len1=getLen(pHead1);
        int len2=getLen(pHead2);
        int num=0;
        if(len1>len2)
        {
            num=len1-len2;
            for(int i=0;i<num;i++)
                pHead1=pHead1->next;
        }
        else
        {
            num=len2-len1;
            for(int i=0;i<num;i++)
                pHead2=pHead2->next;
        }
        ListNode* pCur=nullptr;
        for(;pHead1!=nullptr&&pHead2!=nullptr;pHead1=pHead1->next,pHead2=pHead2->next)
        {
            if(pHead1==pHead2)
            {
                pCur=pHead1;
                break;
            }                
        }
        return pCur;
    }
    int getLen(ListNode* pHead)
    {
        int count=0;
        while(pHead!=nullptr)
        {
            ++count;
            pHead=pHead->next;
        }
        return count;
    }
};