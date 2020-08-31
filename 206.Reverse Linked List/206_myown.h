// 三个指针，pre cur next，保存当前指针及前后指针
// 反转操作即 cur->next = pre
// 反转后更新指针(滑动窗口)

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
    ListNode* reverseList(ListNode* head)
    {
        ListNode* pre = NULL;
        ListNode* cur = head;
        while (cur != NULL)
        {
            ListNode* next = cur->next;
            //reverse
            cur->next = pre;
            //update
            pre = cur;
            cur = next;
        }
        return pre;
    };
};