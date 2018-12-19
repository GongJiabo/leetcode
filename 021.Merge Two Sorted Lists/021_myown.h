#include<iostream>

 struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
{
	ListNode *res = new ListNode(0);
	ListNode *ret = res;
	while (l1 != NULL && l2 != NULL)
	{
		int temp = 0;
		if (l1->val < l2->val)
		{
			temp = l1->val;
			l1 = l1->next;
			res->next = new ListNode(temp);
		}
		else
		{
			temp = l2->val;
			l2 = l2->next;
			res->next = new ListNode(temp);
		}
		res = res->next;
	}
	while (l1 != NULL)
	{
		res->next = new ListNode(l1->val);
		l1 = l1->next;
		res = res->next;
	}
	while (l2 != NULL)
	{
		res->next = new ListNode(l2->val);
		l2 = l2->next;
		res = res->next;
	}
	return ret->next;

}

int main()
{
	ListNode *l1 = new ListNode(-9);
	l1->next = new ListNode(3);
//	l1->next->next = new ListNode(4);
	//
	ListNode *l2 = new ListNode(5);
	l2->next = new ListNode(7);
//	l2->next->next = new ListNode(4);
	//
	ListNode *ans = mergeTwoLists(l1, l2);
	return 0;
}