//pezy
#include <cstddef>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *rotateRight(ListNode *head, int k) {
        if (head == NULL || k == 0) return head;
        ListNode *slow = head, *fast = head;
        while (k--) {
            if (fast == NULL) fast = head;
            fast = fast->next;
        }
        if (fast == NULL) return head;
        while (fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode *new_head = slow->next;
        slow->next = NULL;
        fast->next = head;
        return new_head;
    }
};

//leetcode
class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(k == 0 || !head || !(head -> next))  return head;
        ListNode *temp = head;
        int len = 0;
        while(temp){
            ++ len;
            temp = temp -> next;
        }
        k = k % len;
        temp = head;
        for(int i = len - 1; i > 0; -- i)   temp = temp -> next;
        temp -> next = head;
        temp = head;
        for(int j = len - k; j > 0; -- j)   temp = temp -> next;
        head = temp;
        for(int m = len - 1; m > 0; -- m)   temp = temp -> next;
        temp -> next = nullptr;
        return head;
    }
};
