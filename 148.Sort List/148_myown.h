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
	//148
	ListNode* sortList(ListNode* head) 
	{
		ListNode* dummy = new ListNode(-1);
		dummy->next = head;
		ListNode* cur = dummy;
		int length = 0;
		//求链表长度
		while (cur)
		{
			++length;
			cur = cur->next;
		}
		//
		for (int step = 1; step < length; step *= 2)
		{
			cur = dummy->next;
			ListNode* tail = dummy;
			//
			while (cur)
			{
				ListNode* left = cur;
				ListNode* right = cut(left, step);
				cur = cut(right, step);
				//拼接
				tail->next = merg(left, right);
				while (tail->next)
					tail = tail->next;
			}
		}
		ListNode* res = dummy->next;
		delete dummy;
		return res;
	
	}

	ListNode* merg(ListNode* l1, ListNode* l2)
	{
		ListNode* dummy = new ListNode(-1);
		ListNode* cur = dummy;
		//
		while (l1 && l2)
		{
			if (l1->val < l2->val)
			{
				cur->next = l1;
				cur = l1;
				l1 = l1->next;
			}
			else
			{
				cur->next = l2;
				cur = l2;
				l2 = l2->next;
			}
		}
		cur->next = l1 ? l1 : l2;
		//
		ListNode* res = dummy->next;
		delete dummy;
		return res;
	}

	//剪短链表
	//返回链表最后一个元素的next，同时置为NULL
	ListNode* cut(ListNode* head, int n)
	{
		ListNode* cur = head;
		while(--n && cur)
			cur = cur->next;
		//
		//到链表尾时
		if (!cur) 
			return NULL;
		//
		ListNode* next = cur->next;
		cur->next = NULL;
		return next;
	}
};