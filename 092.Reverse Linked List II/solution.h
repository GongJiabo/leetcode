//from leetcode
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if(m==n) return head;
        auto dummy=new ListNode(-1);
        dummy->next=head;
        auto a=dummy,d=dummy;
        for(int i=0;i<m-1;i++) a=a->next;
        for(int i=0;i<n;i++) d=d->next;
        auto b=a->next,c=d->next;
        for(auto p=b,q=p->next;q!=c;){
            auto o=q->next;
            q->next=p;
            p=q;q=o;
        }
        a->next=d;
        b->next=c;
        return dummy->next;
    }
};

//
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* pre = NULL;
        ListNode* cur = head;
        ListNode* pre0,*cur0;
        unsigned int count = 1;
        while(cur != NULL && count <= n){
            //当cur为m时,记录一下当前cur和pre
            if(count == m)//在头节点,则记录当前pre和cur供后续连接使用
            {
                pre0 = pre;
                cur0 = cur;
            }
            //当cur在(m,n]之间时，反转链表
            if(count > m && count <= n)
            {
                ListNode* temp = cur->next;
                cur->next = pre;
                pre = cur;
                cur = temp;
            }
            else         //常规迭代处理
            {
                pre = cur;
                cur = cur->next;
            }
            //常规处理
            ++count; 
        }
        //最后的链接操作
        //将pre0的next指向第n元素,此时pre指向n，cur指向原始链表中n的下一个元素
        if(pre0 == NULL) head = pre;
        else pre0->next = pre;
        //将指向m的cur0的next指向n后第一个元素
        cur0->next = cur;

        return head;
    }
};
 