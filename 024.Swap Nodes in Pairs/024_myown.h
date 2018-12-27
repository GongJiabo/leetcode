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