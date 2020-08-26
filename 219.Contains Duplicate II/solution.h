//使用哈希策略，map数据结构来记录数组元素和对应的元素所在下表
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> map; // key: 数组元素， value：元素所在下表
        for (int i = 0; i < nums.size(); i++) {
            // 找到了在索引i之前就出现过nums[i]这个元素
            if (map.find(nums[i]) != map.end()) { 
                int distance = i - map[nums[i]];
                if (distance <= k) {
                    return true;
                }
                map[nums[i]] = i; // 更新元素nums[i]所在的最新位置i
            } else { // 如果map里面没有，就把插入一条数据<元素，元素所在的下表>
                map[nums[i]] = i;
            }
        }
        return false;
    }
};

//
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st; // 设一个set为窗口
        for (int i = 0; i < nums.size(); ++i) {
			//set插入insert函数返回pair
            if (!st.insert(nums[i]).second) return true; // 插入失败说明重复 否则完成插入
            if (st.size() == k + 1) st.erase(nums[i-k]); // 保证窗口长度<=k+1
        }
        return false;
    }
};