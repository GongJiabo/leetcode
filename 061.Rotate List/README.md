61. Rotate List

给定一个链表，旋转链表，将链表每个节点向右移动 k 个位置，其中 k 是非负数。

示例 1:

输入: 1->2->3->4->5->NULL, k = 2
输出: 4->5->1->2->3->NULL
解释:
向右旋转 1 步: 5->1->2->3->4->NULL
向右旋转 2 步: 4->5->1->2->3->NULL
示例 2:

输入: 0->1->2->NULL, k = 4
输出: 2->0->1->NULL
解释:
向右旋转 1 步: 2->0->1->NULL
向右旋转 2 步: 1->2->0->NULL
向右旋转 3 步: 0->1->2->NULL
向右旋转 4 步: 2->0->1->NULL


my_own:
对链表循环做插入删除操作，主要需要找到尾结点和尾结点前面一个结点。

提交过程中，发现k过大时间会超出限制，k大于列表长度时会导致旋转到初始状态，因此k的值只需取k%length。

solution:

1.pezy

```cpp
                        |
1->2->3->4->5->NULL     | ListNode *slow = head, *fast = head;
^     ^                 | while (k--) {
slow  fast --->         |      if (fast == NULL) fast = head; // [1]
 |_____|                |      fast = fast->next;
    k                   | }
                        | if (fast == NULL) return head;
1->2->3->4->5->NULL     | while (fast->next) {
^     ^     ^           |      fast = fast->next;
head  slow  fast        |      slow = slow->next;
       |_____|          | }
          k             | List *new_head = slow->next;
                        | slow->next = NULL;
                        | fast->next = head;
                        | return new_head;
```

2.leetcode

* 取得链表长度len

* 让它成环（即tail -> next = head)

* 向右移动k步相当于head顺着指针路线走len-k步

* 然后向右移动len-1步找到tail节点,让他指向nullptr

