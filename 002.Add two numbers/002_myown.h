//后期查看，发现为错误版本！！！
//1.输入为[5] [5]时，输出没有进位的1
//2.为啥数组的大小为10，只能存储长度为10的链表!
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

//遍历两个链表，以此相加
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(-1);
        ListNode* h = head;           //移动指针
        int sum=0;
        bool carry=false;               //进位标志
        while(l1!=NULL || l2!=NULL)
        {
            sum = 0;
            if(l1!=NULL)
            {
                sum+=l1->val;
                l1=l1->next;
            }
            if(l2!=NULL)
            {
                sum+=l2->val;
                l2=l2->next;
            }
            if(carry)   sum++;
            h->next = new ListNode(sum%10);
            h =h->next;
            carry = sum>=10?true:false;
        }
        if(carry)
            h->next=new ListNode(1);
        return head->next;
    }
};