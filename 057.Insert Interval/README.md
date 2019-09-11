57. Insert Interval

给出一个无重叠的 ，按照区间起始端点排序的区间列表。

在列表中插入一个新的区间，你需要确保列表中的区间仍然有序且不重叠（如果有必要的话，可以合并区间）。

示例 1:

输入: intervals = [[1,3],[6,9]], newInterval = [2,5]
输出: [[1,5],[6,9]]
示例 2:

输入: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
输出: [[1,2],[3,10],[12,16]]
解释: 这是因为新的区间 [4,8] 与 [3,5],[6,7],[8,10] 重叠。

my_own：
在056题的基础上，将新的区间合并，然后进行融合，通过set容器进行排序。

solution:

这道题仍然考察的是特殊的数据结构。

这个 Interval 本质上就是一个 std::pair.

最初的序列保证有序，那么查找 newInterval 将会很快（类似二分查找即可）。找首部的时候，根据 start，找尾部的时候，根据 end.

若 newInterval 的 start 落在了某个 interval 之间，那么修改 start, 并从该 interval 处开始删除。

同理 end 落在了某个 interval 之间，那么修改 end, 并从上面开始处一直删除到该 interval.

修改好 start 和 end, 并删除重复区域后，直接插入即可。

若没有落在任何 interval 之间，那么也是直接插入。

思路很简单，我偷懒直接用了 std::lower_bound 算法。