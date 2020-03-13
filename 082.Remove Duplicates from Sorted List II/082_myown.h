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
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        while (prev->next && prev->next->next)
        {
            if (prev->next->val == prev->next->next->val)
            {
                ListNode* tmp = prev->next; //重复节点中的第一个

                while (tmp && tmp->next && tmp->val == tmp->next->val)
                {
                    ListNode* node = tmp;
                    tmp = tmp->next;
                    delete node;
                }

                prev->next = tmp->next; //tmp为重复节点中的最后一个
                delete tmp;
            }
            else
            {
                prev = prev->next;
            }
        }

        return dummy->next;
    }
};