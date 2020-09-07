//1. 将所有元素放入vector后排序，利用已排序的容器重新建立链表
//   没用利用到插入排序的性质！！
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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return NULL;
        vector<int> temp;
        while(head)
        {
            temp.push_back(head->val);
            head=head->next;
        }
        sort(temp.begin(),temp.end());
        ListNode* phead = new ListNode(temp[0]);
        ListNode* cur=phead;
        for(int i=1;i<temp.size();i++)
        {
            ListNode* node = new ListNode(temp[i]);
            cur->next=node;
            cur=cur->next; 
        }
        return phead;
    }
};

//2. 插入排序
//需要保存的cur结点的前后结点，用于拼接插入排序后的前后两个链表
//求pre指针写复杂了，分情况讨论是否发生插入排序即可求得pre
//发生插入：不变； 未发生插入：pre=pre->next;
 
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) return NULL;
        //
        ListNode* dummy = new ListNode(INT_MIN);
        dummy->next = head;
        //
        ListNode* cur = head->next;
        while (cur)
        {
            //保存当前结点的下一个结点
            ListNode* next = cur->next;
            //向前寻找需要插入的两边结点p，q，cur前的结点pre
            ListNode* p = dummy;
            ListNode* pre = dummy;
            bool swap = false;
            while (p != cur)
            {
                if (p->val <= cur->val && p->next->val > cur->val)
                {
                    swap = true;
                    break;
                }
                p = p->next;
            }
            if (swap)
            {
                //寻找pre结点
                while (pre && pre->next != cur)
                    pre = pre->next;
                //拼接
                pre->next = cur->next;
                //插入操作
                cur->next = p->next;
                p->next = cur;
            }
            //向后移动
            cur = next;
        }
        ListNode* retNode = dummy->next;
        delete dummy;
        return retNode;
    }
};