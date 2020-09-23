//1. 利用数组保存每个数，然后从两头遍历数组是否相等
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
    bool isPalindrome(ListNode* head) {
        vector<int> vnum;
        while(head!=NULL)
        {
            vnum.push_back(head->val);
            head=head->next;
        }
        for(int i=0,j=vnum.size()-1;i<j;i++,j--)
            if(vnum[i]!=vnum[j])
                return false;
        return true;
    }
};

//2. 快慢指针，翻转后半部分链表
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
	bool isPalindrome(ListNode* head) {
        if (head == NULL ) return true;
        //
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        //
        while (fast->next)
        {
            slow = slow->next;
            fast = fast->next;
            if (fast->next)
                fast = fast->next;
        }
        //此时slow指针为链表中点
        //反转链表后部分
        ListNode* pre = NULL;
        ListNode* cur = slow->next;
        ListNode* next = NULL;
        while (cur != NULL)
        {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        //遍历两部分链表
        while (pre)
        {
            if (head->val != pre->val)
                return false;
            pre = pre->next;
            head = head->next;
        }
        return true;
	}
};