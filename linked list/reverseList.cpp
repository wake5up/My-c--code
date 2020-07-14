//反转链表

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       if(head==nullptr)
            return nullptr;
        ListNode* pre=nullptr;
        ListNode* cur=head;
        ListNode* next=nullptr;
        while(cur)
        {
            next=cur->next;
            cur->next=pre;
            pre=cur;
            cur=next;
        }
        return pre;
    }
};


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
       
        if(head==nullptr||head->next==nullptr)
            return head;
        ListNode* cur=reverseList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return cur;
    }
};