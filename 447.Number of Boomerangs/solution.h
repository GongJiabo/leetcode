// from leetcode
//选定一个原点，hashmap记录其他所有点到这个点之间的距离。
//此处优化：A->B距离=B->A距离，可以减少一般的时间消耗，但是需要额外空间去储存。

class Solution {
public:
    int numberOfBoomerangs(vector<vector<int>>& points) {
        int size=points.size();
        if(size<3) return 0;
        vector<unordered_map<int,int>> tmp(size,unordered_map<int,int>{});
        int count=0;
        for(int i=0;i<size;++i){
			//从i+1开始循环，节省了空间
            for(int j=i+1;j<size;++j){
                int dis=pow(points[i][0]-points[j][0],2)+pow(points[i][1]-points[j][1],2);
				//保存第i、j个点距离为dis的点个数
                ++tmp[i][dis];
                ++tmp[j][dis];
                count+=((tmp[i][dis]-1)*2);
                count+=((tmp[j][dis]-1)*2);
            }
        }
        return count;
    }
};

