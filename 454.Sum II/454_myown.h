//时间复杂度：O(max(m, n))O(max(m,n))，其中 mm 与 nn 分别为两个链表的长度。我们需要遍历每个链表。
//空间复杂度：O(m + n)O(m+n)，其中 mm 与 nn 分别为两个链表的长度。这是我们把链表内容放入栈中所用的空间。
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> s1,s2;
        while(l1)
        {
            s1.push(l1->val);
            l1=l1->next;
        }
        while(l2)
        {
            s2.push(l2->val);
            l2=l2->next;
        }
        //其次弹出栈，相加并保存进位
        int carry=0;
        ListNode* ans=NULL;
        while(!s1.empty() || !s2.empty() || carry!=0)
        {
            int a = s1.empty()? 0:s1.top();
            int b = s2.empty()? 0:s2.top();
            if (!s1.empty()) s1.pop();
            if (!s2.empty()) s2.pop();
            int cur = a + b + carry;
            carry = cur / 10;
            cur %= 10;
            ListNode* newNode = new ListNode(cur);
            newNode->next = ans;
            ans = newNode;
        }
        return ans;
    }
};