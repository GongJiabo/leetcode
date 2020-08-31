struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
//前后指针元素相同则删除
class Solution {
public:
  ListNode *deleteDuplicates(ListNode *head) {
    for (ListNode *cur = head; cur && cur->next; )
    {
      if (cur->val == cur->next->val) 
      {
        ListNode *del = cur->next;
        cur->next = del->next;
        delete del;
      }
      else cur = cur->next;
    }    
    return head;
  }
};

//双指针(快慢指针法)
//没有考虑内存空间的释放
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL||head->next==NULL)
            return head;
        ListNode* p=head;//慢指针
        ListNode* q=head->next;//快指针
        while(p->next!=NULL)
        {
            if(p->val==q->val)//找到重复元素
            {
                if(q->next==NULL)//快指针后面若没有元素直接剔除
                    p->next=NULL;
                else//快指针后有元素
                {
                    p->next=q->next;
                    q=q->next;
                }
            }
            else //元素不相等
            {
                p=p->next;
                q=q->next;
            }
        }
        return head;
    }
};

//递归法
//找终止条件：当head指向链表只剩一个元素的时候，自然是不可能重复的，因此return
//想想应该返回什么值：应该返回的自然是已经去重的链表的头节点
//每一步要做什么：宏观上考虑，此时head.next已经指向一个去重的链表了，而根据第二步，我应该返回一个去重的链表的头节点。
//因此这一步应该做的是判断当前的head和head.next是否相等，如果相等则说明重了，返回head.next，否则返回head
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head||!head->next)
            return head;
        head->next=deleteDuplicates(head->next);
        if(head->val==head->next->val) head=head->next;
        return head;
    }
};

