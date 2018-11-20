class Solution
{
public:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
	{
		ListNode *temp1 = l1, *temp2 = l2;
		ListNode result(0);
		ListNode *temp_r = &result;
		int i = 0, div = 0, n;
		int n__[10], div__[10];
		while (l1!= NULL && l2!= NULL)
		{
			n = (l1->val + l2->val) % 10;
			div = (l1->val + l2->val) / 10;
			if (i == 0)
			{
				n__[i] = n;
				div__[i] = div;
			}
			else
			{
				n__[i] = n + div__[i - 1];
				div__[i] = div;
			}
			i++;
			l1 = l1->next;
			l2 = l2->next;
		}
		for (int j = 0; j < i ; j++)
		{
			temp_r->next = new ListNode(n__[j]);
			temp_r = temp_r->next;
		}

		return result.next;
	}
};