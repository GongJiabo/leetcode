/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head)
            return NULL;
        // 复制链表
        Node* dummy = new Node(-1);
        Node* p = new Node(head->val);
        dummy->next = p;
        Node* phead = head->next;
        while (phead)
        {
            Node* tmp = new Node(phead->val);
            p->next = tmp;
            p = p->next;
            phead = phead->next;
        }
        // 复制随机结点
        p = dummy->next;
        Node* q = head;
        Node* start1 = head;
        Node* start2 = dummy->next;
        while (start1 != NULL)
        {
            // 查找每个节点的随机节点
            if (start1->random == NULL)
            {
                start2->random = NULL;
                start1 = start1->next;
                start2 = start2->next;
                continue;
            }
            else
            {
                while (q != start1->random)
                {
                    q = q->next;
                    p = p->next;
                }
                start2->random = p;
                //
                start1 = start1->next;
                start2 = start2->next;
                q = head;
                p = dummy->next;
            }
        }
        return dummy->next;
    }
};
