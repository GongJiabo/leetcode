451. Sort Characters By Frequency

给定一个字符串，请将字符串里的字符按照出现的频率降序排列。

示例 1:
```
输入:
"tree"

输出:
"eert"

解释:
'e'出现两次，'r'和't'都只出现一次。
因此'e'必须出现在'r'和't'之前。此外，"eetr"也是一个有效的答案。
```
示例 2:
```
输入:
"cccaaa"

输出:
"cccaaa"

解释:
'c'和'a'都出现三次。此外，"aaaccc"也是有效的答案。
注意"cacaca"是不正确的，因为相同的字母必须放在一起。
```
示例 3:
```
输入:
"Aabb"

输出:
"bbAa"

解释:
此外，"bbaA"也是一个有效的答案，但"Aabb"是不正确的。
注意'A'和'a'被认为是两种不同的字符。
````

-----------

### my_own:

利用map存储每个字符及其出现的次数，其中key为char，value为int（次数）。

这里需要对value进行排序，需要自己写判断函数cmp，利用algorithm提供的sort函数进行排序。

注意sort无法直接对map排序，需要将map中的pair元素存入vector，对vector排序。


