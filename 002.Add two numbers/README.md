002.Add two numbers
给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储单位数字。
如果，我们将这两个数起来相加起来，则会返回出一个新的链表来表示它们的和。
可以假设除了数字 0 之外，这两个数都不会以 0 开头。

示例：
输入：(2 -> 4 -> 3) + (5 -> 6 -> 4)
输出：7 -> 0 -> 8
原因：342 + 465 = 807

难点在于进位

my own:
遍历链表，将计算结果保存至数组（保存结果及进位数）
用结果数组创建返回的链表
////
函数内部可以 new 指针？？但是一定要初始化？？那内存如何释放？？
先声明定义对象，然后定义指向该对象的指针？

solution：
class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        ListNode dummy(0), *tail = &dummy;                           
        for (div_t sum{0, 0}; sum.quot || l1 || l2; tail = tail->next) {    //初始化sum quto=0,rem=0
            if (l1) { sum.quot += l1->val; l1 = l1->next; }
            if (l2) { sum.quot += l2->val; l2 = l2->next; }
            sum = div(sum.quot, 10);
            tail->next = new ListNode(sum.rem);
        }
        return dummy.next;
    }
};

STL 有一个专门的结构体叫做 div_t, 其包含两个成员，分别是 quot(quotient) 与 rem(remainder).
    用来做什么，从命名上是否可以看出一点端倪呢？

举例说明.
 38 / 5 == 7 remainder 3
用 C++ 来描述，便是：
 div_t result = div(38, 5);
 cout << result.quot << result.rem;
前者为被除后的结果，后者为余数。
与这道题的关系是？
本题的进位是基于十进制的，故两个节点相加之后的值，应判断是否超出了10，超出需要进位，留下的是余数。
即，做了 div 操作后。sum.rem 是新链表的当前节点，sum.quot 是下一次加法运算的进位。