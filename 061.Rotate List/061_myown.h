/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution 
{
public:
	ListNode* rotateRight(ListNode* head, int k) 
	{
        if (!head || !head->next)  return head;
		int n = 1,length=1;
        //统计链表长度
        ListNode *count=head;
        while(count->next)
        {
            count=count->next;
            length++;
        }
        k=k%length;
        //
		while (n <= k)
		{
			ListNode *tail = new ListNode(0);
			ListNode *tail2 = new ListNode(0);
			tail2 = head;
			//找到倒数第二个结点
			while (tail2->next->next)
				tail2 = tail2->next;	
			tail = tail2->next;
			//
			tail->next = head;
			tail2->next = NULL;
			head = tail;
			n++;
		}
		return head;
	}
};