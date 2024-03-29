### 142. Linked List Cycle II

给定一个链表，判断链表中**是否有环**。

如果链表中有某个节点，可以通过连续跟踪 `next` 指针再次到达，则链表中存在环。 为了表示给定链表中的环，我们使用整数 pos 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是 -1，则在该链表中没有环。

**注意：** `pos` 不作为参数进行传递，仅仅是为了标识链表的实际情况。

如果链表中存在环，则返回 true 。 否则，返回 false 。

 

**进阶：**

你能用 *O(1)*（即，常量）内存解决此问题吗？

**示例 1：**

![circularlinkedlist1](.\circularlinkedlist1.png)

```
输入：head = [3,2,0,-4], pos = 1
输出：返回索引为 1 的链表节点
解释：链表中有一个环，其尾部连接到第二个节点。
```

**示例 2：**

![circularlinkedlist1](.\circularlinkedlist2.png)

```
输入：head = [1,2], pos = 0
输出：返回索引为 0 的链表节点
解释：链表中有一个环，其尾部连接到第一个节点。
```

**示例 3：**

![circularlinkedlist1](.\circularlinkedlist3.png)

```
输入：head = [1], pos = -1
输出：返回NULL
解释：链表中没有环。
```



-------



