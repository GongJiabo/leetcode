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