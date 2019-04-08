038.Count and Say

报数序列是一个整数序列，按照其中的整数的顺序进行报数，得到下一个数。其前五项如下：

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 被读作  "one 1"  ("一个一") , 即 11。
11 被读作 "two 1s" ("两个一"）, 即 21。
21 被读作 "one 2",  "one 1" （"一个二" ,  "一个一") , 即 1211。

给定一个正整数 n（1 ≤ n ≤ 30），输出报数序列的第 n 项。

注意：整数顺序将表示为一个字符串。

 

示例 1:

输入: 1
输出: "1"
示例 2:

输入: 4
输出: "1211"

my_own:
遍历字符串，统计每个字符出现的次数，依次push_back入string

solution：
我们起码要循环 n 次，才可以从 n==1 的时候演变而来。
每一次演变，我们需要迭代上一次的字符串，然后遇到重复项，要归纳总结。
str.replace(b, e, std::to_string(e-b) + *b);
这个 replace 基本展现了我对于演变的理解，这不过这个步骤需要反复迭代。而 replace 却会破坏 iterator，不得已我重新弄了个 string，来避免 iterator 的破坏。

 ps：运动迭代器相减得到重复个数，注意to_string的用法
 原型：
string to_string (int val);
string to_string (long val);
string to_string (long long val);
string to_string (unsigned val);
string to_string (unsigned long val);
string to_string (unsigned long long val);
string to_string (float val);
string to_string (double val);
string to_string (long double val);