023.Merge k Sorted Lists

合并 k 个排序链表，返回合并后的排序链表。请分析和描述算法的复杂度。

示例:

输入:
[
  1->4->5,
  1->3->4,
  2->6
]
输出: 1->1->2->3->4->4->5->6

myown:
将所有链表保存的元素存入int类型的容器中，运用algorithm中的sort函数排序，重新构造新链表

solution:
拿到问题，合并多个链表。而此刻，我们已经掌握了合并两个链表的方法。于是我们很自然的列出以下几种情况：

lists.empty() : 返回 NULL
lists.size() == 1 : 返回该链表
lists.size() == 2 : 正好碰枪口，mergeTwoLists.
lists.size() == 3 : 先合并后两个，在将其结果与第三个合并。
lists.size() == 4 : 先两两合并，然后再将结果合并。
...
就没必要一直列下去了吧。

分而治之，是非常自然而然的思路，我们如果会造枪，但要的却是炮，我们将枪捆在一起，捆的无限多，便成了炮。

注意，为了更方便分治，我们将原题目的接口扩展为更通用的迭代器接口。

然后核心的语句是：

return mergeTwoLists(mergeKLists(beg, beg + std::distance(beg, end)/2), mergeKLists(beg + std::distance(beg, end)/2, end));
提交，AC，离最快差了不过 4 ms.