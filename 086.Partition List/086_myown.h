//建立两个新的链表(头结点)
//分别将小于x的元素与大于等于x的元素插入到新链表中
//合并链表即可
//注意！合并后将尾元素的指针next置为NULL，否则为循环链表
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
ListNode* partition(ListNode* head, int x)
	{
		int count = 0;
		//小于x的链表hat1
		ListNode* hat1 = new ListNode(-1);
		ListNode* cur1 = hat1;
		//大于等于x的链表hat2
		ListNode* hat2 = new ListNode(-1);
		ListNode* cur2 = hat2;
 
		//
		//divide
		while (head != NULL)
		{
			if (head->val < x)
			{
				cur1->next = head;
				cur1 = head;
			}
			else
			{
				cur2->next = head;
				cur2 = head;
			}
			head = head->next;
		}
		//merge

		cur1->next = hat2->next;
		cur2->next = NULL;
		//
		return hat1->next;
	}

};