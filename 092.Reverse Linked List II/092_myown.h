//Method 1 
//找到反转链表的前后节点，对所需的段进行翻转后连接
//bug，不通过，对初始点为1等特殊情况存在问题 ------>> 引入dummy结点(哑巴结点)
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        //寻找开始与结束翻转的点
        int count = 1;
        ListNode* begP = head;
        ListNode* endP = head;
		while (count < n + 1)
		{
			if (count < m - 1)
				begP = begP->next;
			endP = endP->next;
			count++;
		}
 
        ListNode* pre = begP->next;
        ListNode* cur = pre->next;
        ListNode* next = NULL;
        //连接
        pre->next = endP;
        for (int i = 0; i < n - m; i++)
        {
            next = cur->next;
            //reverse
            cur->next = pre;
            //update
            pre = cur;
            cur = next;
            //
        }
        //连接
        begP->next = pre;
 
        return head;
    }
}

// dummy head/**
class Solution {
public:
        ListNode* reverseBetween(ListNode* head, int m, int n) 
    {
        //寻找开始与结束翻转的点
        int count = 1;
        //dummy node
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        //
        ListNode* begP = dummy;
        ListNode* endP = dummy;
		while (count <= n + 1)
		{
			if (count <= m - 1)
				begP = begP->next;
			endP = endP->next;
			count++;
		}
 
        ListNode* pre = begP->next;
        ListNode* cur = pre->next;
        ListNode* next = NULL;
        //连接
        pre->next = endP;
        for (int i = 0; i < n - m; i++)
        {
            next = cur->next;
            //reverse
            cur->next = pre;
            //update
            pre = cur;
            cur = next;
            //
        }
        //连接
        begP->next = pre;
        //
        ListNode* resNode = dummy->next;
        delete dummy;
        return resNode;
    }
};
 
 