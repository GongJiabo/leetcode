001.Two sum
给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的 两个 整数。
你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。

示例:
给定 nums = [2, 7, 11, 15], target = 9
因为 nums[0] + nums[1] = 2 + 7 = 9
所以返回 [0, 1]


myown：
使用两重循环遍历vetcor

solution：
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> record;             //record关联容器    
        for (int i = 0; i != nums.size(); ++i) {         //遍历所有的值
            auto found = record.find(nums[i]);           //find: Get iterator to element 查找存在的情况下返回，否者为"野指针"
            if (found != record.end()) 
                return {found->second, i};               //.first为键值 .second为映射值
            record.emplace(target - nums[i], i);         //emplace: Construct and insert element 
        } 
        return {-1, -1};
    }
};

将target-nums[i]的值与i存储在关联容器内，前者作为键，后者作为映射值
对nums后的值与关联容器内的差值比较是否有相同的（即和位target）


/////note/////
unordered_map：（类似于python里的字典？）
无序映射是关联容器，用于存储由键值和映射值组合而成的元素，并允许基于键快速检索各个元素。 
在unordered_map中，键值通常用于唯一标识元素，而映射值是与该键关联的内容的对象。键和映射值的类型可能不同。 
在内部，unordered_map中的元素没有按照它们的键值或映射值的任何顺序排序，而是根据它们的散列值组织成桶以允许通过它们的键值直接快速访问单个元素（具有常数平均时间复杂度）。
unordered_map容器比映射容器更快地通过它们的键来访问各个元素，尽管它们通过其元素的子集进行范围迭代通常效率较低。
无序映射实现直接访问操作符（operator []），该操作符允许使用其键值作为参数直接访问映射值。

优点： 因为内部实现了哈希表，因此其查找速度非常的快 
缺点： 哈希表的建立比较耗费时间 
适用处：对于查找问题，unordered_map会更加高效一些，因此遇到查找问题，常会考虑一下用unordered_map

http://www.cplusplus.com/reference/unordered_map/unordered_map/?kw=unordered_map
