///解题思路
//双指针，一次遍历
//判断快指针与其next的值是否相等，相等则q = q->next;反正，分情况讨论：
//快慢指针相邻：说明没有重复区域，两者向下一位位移；
//快慢指针不相邻：说明出现重复区域，越过重复区域。

//有两种特殊情况要考虑：
//链表头部出现重复：申请一个头前结点，并且更新头节点
//链表尾部出现重复：循环结束，判断下快慢指针是否不相邻，若不相邻，慢指针的下一位置空

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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* p = new ListNode(-1);
        p->next = head;
        head = p;
        ListNode* q = p->next;

        while(q->next != NULL){
            if(q->val == q->next->val){
                q = q->next;
            }else{
                if(p->next == q){
                    p = p->next;
                    q = q->next;
                }else{
                    q = q->next;
                    p->next = q;
                }
            }
        }
        if(p->next != q) p->next = NULL;
        return head->next;
    }
};
