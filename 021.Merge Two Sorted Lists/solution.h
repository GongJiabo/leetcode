/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <cstddef> 

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *header = NULL, **p;						//二级指针？？
        for (p = &header; l1 && l2; p = &(*p)->next)
        {
            if (l1->val <= l2->val)
            {
                *p = new ListNode(l1->val);
                l1 = l1->next;
            }
            else
            {
                *p = new ListNode(l2->val);
                l2 = l2->next;
            }
        }
        for (ListNode *leave = l1 ? l1 : l2; leave; leave = leave->next, p = &(*p)->next)  //判断条件卸载循环语句内！！
            *p = new ListNode(leave->val);
        return header;
    }
};