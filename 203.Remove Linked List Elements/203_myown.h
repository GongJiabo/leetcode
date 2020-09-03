//新增一个dummy头结点(虚拟头指针)
//当删除结点为头结点时，存在陷阱，需要一直判断需要删除的结点是否为NULL，代码冗余。
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        //
        ListNode* cur = dummy;
        while( cur->next != NULL)
        {
            if(cur->next->val == val)
            {
                //删除cur->next
                ListNode* delNode = cur->next;
                cur->next = delNode->next;
                delete delNode;
            }
            else
                cur=cur->next;  
        }
        ListNode* resNode = dummy->next;
        delete dummy;
        return resNode;
    }
};