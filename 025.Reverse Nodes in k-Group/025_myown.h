#include<iostream>
#include<string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
	ListNode *reverseList(ListNode *&head, int k)
	{
		ListNode* pEnd = head;
		while (pEnd && k>0){
			pEnd = pEnd->next;
			k--;
		}
		if (k>0) return head;   //找到k个后面的结点，将翻转后的链表与其连接

		ListNode *pHead = pEnd, *p = head;
		while (p != pEnd){
			ListNode *q = p->next;
			p->next = pHead;
			pHead = p;
			p = q;
		}
		return pHead;
	}
	ListNode* reverseKGroup(ListNode* head, int k) 
	{
		if (k <= 0) return head;
		ListNode fake(0);
		fake.next = head;
		ListNode* p = &fake;

		while (p){
			p->next = reverseList(p->next, k);
			for (int i = 0; p && i<k; i++){
				p = p->next;
			}			//寻找下一个开始结点
		}

		return fake.next;
	}
};

int main()
{
	ListNode *p1 = new ListNode(1);
	p1->next = new ListNode(2);
	p1->next->next = new ListNode(3);
	p1->next->next->next = new ListNode(4);
	p1->next->next->next->next = new ListNode(5);
	//
	Solution res;
	ListNode *ans = res.reverseKGroup(p1, 3);
	//
	return 0;
}