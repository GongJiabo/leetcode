//from haoel
class Solution {
public:
    /** @param head The linked list's head.
        Note that the head is guaranteed to be not null, so it contains at least one node. */
    Solution(ListNode* head) {
        this->head = head;
        this->len = 0;
        for(ListNode*p = head; p!=NULL; p=p->next, len++);
        srand(time(NULL));
    }
    
    /** Returns a random node's value. */
    int getRandom() {
        int pos = rand() % len;
        ListNode *p = head;
        for (; pos > 0; pos--, p=p->next);
        return p->val;
    }
    ListNode* head;
    int len;
};
