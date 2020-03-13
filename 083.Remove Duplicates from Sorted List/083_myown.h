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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *p=head;
        if(!head || !head->next) return head;
        while(p->next)
        {
            if(p->val != p->next->val)
                p=p->next;
            else
            {
                ListNode *q = p->next;
                while(p && q && p->val== q->val)
                {
                    ListNode *temp = q;
                    q=q->next;
                    delete temp;
                }
                p->next=q;
            }
        }
        return head;
    }
};