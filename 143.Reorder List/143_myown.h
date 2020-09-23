/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode* head) {
        //
        if(head==NULL ) return;
        //
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        //存放结点指针的栈
        stack<ListNode* > nodeStack;
        //
        ListNode* cur = head;
        while (cur != NULL)
        {
            nodeStack.push(cur);
            cur = cur->next;
        }
        //
        cur = head;
        ListNode* topNode = nodeStack.top();
        while (cur != topNode && cur->next!=topNode && cur!=NULL)
        {
            //将栈顶元素插入到cur元素后面
            topNode->next = cur->next;
            cur->next = topNode;

            //更新栈
            nodeStack.pop();
            topNode = nodeStack.top();
            //
            cur = cur->next->next;
        }
        topNode->next = NULL;
        return;
    }
};
