
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_map<ListNode*, bool> mp;
        while(head)
        {
            if(mp[head] == false)
            {
                mp[head] = true;
                head = head->next;
            }
            else
                return head;
        }
        return NULL;
    }
};

