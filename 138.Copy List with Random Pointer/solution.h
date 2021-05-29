// 1. 哈希 + 递归
class Solution {
private:
    unordered_map<Node*, Node*> dic;
public:
    Node* copyRandomList(Node* head) {
        if (head == nullptr) return nullptr;
        if (dic.count(head)) return dic[head];
        Node* root = new Node(head->val);
        dic[head] = root;
        root->next = copyRandomList(head->next);
        root->random = copyRandomList(head->random);
        return root;
    }
};

// 2. 哈希
// 深度拷贝的标准操作在于使用一个map，将旧节点映射到对应的新节点
// 第一次遍历时不管random，创建一个newhead开头的新链表，这很简单。
// 然后再用it指针遍历旧链表，map[it]就随之遍历了新链表
// 我们要将map[it]->random指向it->random对应的新节点
// 即：
// map[it]->random = map[it->random];


class Solution {
public:
    Node* copyRandomList(Node* head) {
        //应是不难，只需要遍历旧的，同时生成新的,第二次遍历处理random即可
        //为了方便找到映射，建立一个hashmap
        if( head == NULL ){
            return head;
        }
        unordered_map< Node*,Node* > map;
        Node* newhead = new Node( head->val );
        map[head] = newhead;

        auto pre = newhead;
        for(auto it = head->next ; it!=NULL ; it = it->next ){
            Node* cur = new Node( it->val );
            map[it] = cur;
            pre->next = cur;
            pre = cur;
        }
        for(auto it = head ; it!=NULL ; it = it->next ){
            map[it]->random = map[it->random];
        }
        return newhead;
    }
};


// 3. 先在原链表挨个复制节点后拆分
// https://www.cnblogs.com/silentteller/p/11931355.html
class Solution {
public:
    RandomListNode* Clone(RandomListNode* pHead)
    {
        if(pHead == nullptr) return nullptr;
        RandomListNode* p = pHead;
        //在每个节点A后复制一个相同的节点A'，A->B->C->NULL, A->A'->B->B'->C->C'->NULL
        while(p != nullptr){
            RandomListNode* tempNode = new RandomListNode(p->label);
            tempNode->next = p->next;
            p->next = tempNode;
            p = tempNode->next;
        }
        //复制random指针，A'random指向的一定是Arandom指向的下一个元素。
        p = pHead;
        while(p != nullptr){
            if(p->random != nullptr)
                p->next->random = p->random->next;
            p = p->next->next;
        }
        //将链表拆分，A->A'->B->B'->C->C'->NULL，A->B->C->NULL and A'->B'->C'->NULL
        p = pHead;
        RandomListNode* myHead = pHead->next;
        RandomListNode* q = myHead;
        while(p != nullptr){
            p->next = q->next;
            //如果处理到最后一组节点时，q不用再做处理，因为其next已经指向nullptr
            if(q->next != nullptr)
                q->next = p->next->next;
            p = p->next;
            q = q->next;
        }
        return myHead;
    }
};
