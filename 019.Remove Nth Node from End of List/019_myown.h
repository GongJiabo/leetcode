//1.
class Solution {
public:
ListNode* removeNthFromEnd(ListNode* head, int n) 
{
	if (head == NULL || n <= 0) return NULL;
	int len = 1;
	ListNode *p = head;
	ListNode *temp = head;
	while (temp->next != NULL)
	{
		len++;
		temp = temp->next;
	}
	if (n>len) return NULL;
	else if (n == len) return head->next;
	//
	for (int i = 0; i<len - n - 1; i++)
	{
		p = p->next;
	}
	temp = p->next;
	p->next = p->next->next;
	return head;
}
};


//2.
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        assert(n>0);
        //
        ListNode* dummy = new ListNode(-1);
        dummy->next=head;
        ListNode* fast = dummy;
        ListNode* slow = dummy;
        //将slow指针滞后n+1个位置 
        for(int i=0;i<n+1;i++)
        {
            assert(fast);
            fast=fast->next;
        }
        //移动指针，使快指针指向链表末尾的空
        //此时slow指针对应所需删除节点的前驱
        while(fast!=NULL)
        {
            fast=fast->next;
            slow=slow->next;
        }
        ListNode* temp=slow->next;
        slow->next=temp->next;
        delete temp;
        //删除dummy
        ListNode* ret=dummy->next;
        delete dummy;
        return ret;
    }
};