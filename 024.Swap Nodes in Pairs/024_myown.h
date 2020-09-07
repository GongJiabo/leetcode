//1.
class Solution {
public:
	ListNode *swapPairs(ListNode *head) {
		ListNode *h = NULL;
		//using `*p` to traverse the linked list
		for (ListNode *p = head; p && p->next; p = p->next) {
			//`n` is `p`'s next node, and swap `p` and `n` physcially
			ListNode *n = p->next;
			p->next = n->next;
			n->next = p;
			//using `h` as `p`'s previous node
			if (h){
				h->next = n;
			}
			h = p;

			//determin the really 'head' pointer
			if (head == p){
				head = n;
			}
		}

		return head;
	}
};

//2.
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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL) return NULL;
        ListNode* dummy=new ListNode(-1);
        dummy->next=head;
        ListNode* pre=dummy;
        //
        while(pre->next && pre->next->next)
        {
            ListNode* p=pre->next;
            ListNode* q=p->next;
            //inverse
            p->next=q->next;
            q->next=p;
            pre->next=q;
            pre=p;
        }
        ListNode* res=dummy->next;
        delete dummy;
        return res;
    }
};