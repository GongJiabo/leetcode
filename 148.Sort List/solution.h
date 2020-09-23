//1. 递归算法(不合题意)
//数组进行归并排序时，需要一个额外的数组记录归并结果，因此数组归并的空间复杂度是O(n)+O(logn)，而对于链表的话，直接交换引用即可，不用额外的空间保存，所以只需要O(logn)的递归空间复杂度即可
//使用快慢指针把链表分成两半，要断链，同时断了之后还要有两个链表的头节点，所以用快慢指针断链的时候需要一个结点pre记录slow的前驱结点，然后 pre->next==nullptr,那么两个链表即为[head,pre]和[slow,nullptr)
//合并分开的链表的时候，方法就是21题中的合并排序链表的递归的方法

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* pre = head, *slow = head, *fast = head;
        while(fast && fast->next) {
            pre = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        pre->next = nullptr;
        return mergeTwoList(sortList(head), sortList(slow));
    }
    ListNode* mergeTwoList(ListNode* h1, ListNode* h2) {
        if(!h1) return h2;
        if(!h2) return h1;
        if(h1->val < h2->val) {
            h1->next = mergeTwoList(h1->next, h2);
            return h1;
        }
        else {
            h2->next = mergeTwoList(h1, h2->next);
            return h2;
        }
    }
};


//2. 迭代合并
class Solution {
public:
    //cut n个节点，然后返回剩下的链表的头节点
    ListNode* cut(ListNode* head,int n)
    {
        ListNode* p=head;
        while(--n && p)
            p=p->next;

        if(p==nullptr)
            return nullptr;

        ListNode* suc=p->next;
        p->next=nullptr;
        return suc;
    }
    //迭代合并链表
    ListNode* merge(ListNode* l1,ListNode* l2)
    {
        ListNode* dummy=new ListNode(0);
        ListNode* p=dummy;
        while(l1 && l2)
        {
            if(l1->val < l2->val)
            {
                p->next=l1;
                l1=l1->next;
                p=p->next;
            }
            else
            {
                p->next=l2;
                l2=l2->next;
                p=p->next;
            }
        }
        p->next=l1 ? l1 : l2;
        return dummy->next;
    }
    ListNode* sortList(ListNode* head) 
    {
        if(head==nullptr || head->next==nullptr)
            return head;
        int length=0;
        ListNode* p=head;
        //先求得链表的长度，然后根据长度来cut
        while(p)
        {
            length++;
            p=p->next;
        }
        //第一次cut 1，然后根据归并的思路，cut的大小依次*2，边界条件位size<length，因为size==n表示的是链表的每个长度为n的段已经是有序的了，执行循环的目的就是把有序的长度为n的段连起来，因此当size>=length时，表示长度为size的段已经有序，即原链表已经归并完成，结束循环。只有当size<length时才表明没有归并完成，进入循环继续归并
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        for(int size=1;size<length;size*=2)
        {
            //cur表示待分割链表的第一个，tail表示已经合并好的链表的最后一个，类似于147题中的beign和tail
            ListNode* cur=dummy->next;
            ListNode* tail=dummy;
            while(cur)
            {
                ListNode* left=cur;
                ListNode* right=cut(left,size);
                cur=cut(right,size);
                tail->next=merge(left,right);
                while(tail->next)
                    tail=tail->next;
            }
        }
        return dummy->next;
    }
};


