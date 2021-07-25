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
    bool hasCycle(ListNode *head) {
        unordered_map<ListNode*, bool> mp;
        while(head)
        {
            if(mp[head] == false)
            {
                mp[head] = true;
                head = head->next;
            }
            else
                return true;
        }
        return false;
    }
};