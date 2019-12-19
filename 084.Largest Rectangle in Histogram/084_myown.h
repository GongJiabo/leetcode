//1. 找出0分段，思路偏了！！！跟0不0没关系！！超出时间限制！！
//改进：找最小的值，分为左右两段分治计算
class Solution {
public:
	int largestRectangleArea(vector<int>& heights)
	{	
		int n = heights.size();	
		if (n <= 0) return 0;
		int maxarea = 0;
		//find zero
		vector<int> cutzero;
		cutzero.push_back(-1);
		for (int i = 0; i < n; i++)
		{
			if (heights[i] == 0)
				cutzero.push_back(i);
		}
		cutzero.push_back(n);
		//
		for (int i = 0; i < cutzero.size() - 1; i++)
		{
			int temp = cutzeroarea(heights, cutzero[i] + 1, cutzero[i + 1] - 1);
			maxarea = maxarea > temp ? maxarea : temp;
		}
		return maxarea;
	}

	int cutzeroarea(vector<int> &heights,int s,int e)
	{
		int max = 0;
		int length = 0;
		int height = 0;
		if (s == e) return heights[e];
		for (int i = s; i <= e; i++)
		{
			for (int j = i; j <= e; j++)
			{
				length = j - i + 1;
				height = findLeastNum(heights, i, j);
				max = max > height*length ? max : height * length;
			}
		}
		return max;
	}
	int findLeastNum(vector<int>& num,int i,int j)
	{
		int min = num[i];
		for (; i <= j; i++)
			min = num[i] < min ? num[i] : min;
		return min;
	}
};

//2. 暴力解法，三次遍历，O(n^3)的时间复杂度，超出时间限制
class Solution {
public:
	int largestRectangleArea(vector<int>& heights)
	{	
		int n = heights.size();	
        if(n<=0) return 0;
        //
		int i, j;
		int max = 0;
		int length = 0;
		int height = 0;
		for (i = 0; i < n ; i++)
		{
           // height = heights[i];
			for (j = i; j < n; j++)
			{
				length = j - i + 1;
                //
                //for(int k = i; k <= j; k++)
                //   height=min(height,heights[k]);
				height = findLeastNum(heights, i, j);
				max = max > height*length ? max : height * length;
			}
		}
		return max;
	}
	int findLeastNum(vector<int>& num,int i,int j)
	{
		int min = num[i];
		for (; i <= j; i++)
			min = num[i] < min ? num[i] : min;
		return min;
	}

};

//3. 优化暴力解法仍然超出时间限制
class Solution {
public:
	int largestRectangleArea(vector<int>& heights)
	{	
		int n = heights.size();	
        if(n<=0) return 0;
        //
		int i, j;
		int maxarea = 0;
		int length = 0;
		int minheight = 0;
		for (i = 0; i < n ; i++)
		{
            minheight = heights[i];
			for (j = i; j < n; j++)
			{
				length = j - i + 1;
                //
                minheight =min(minheight, heights[j]);
				maxarea = max(minheight*length,maxarea);
			}
		}
		return maxarea;
	}
};

//4. 分治算法
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if(n<=0) return 0;
        if(n==0) return heights[0];
        return divided(heights, 0, n-1);
    }
    int divided(vector<int> &heights,int start, int end)
    {
            if(start > end)
                return 0;
            int mid = start;
            for(int i = start;i <= end; ++i)
            {
                if(heights[i] < heights[mid])
                    mid = i;
            }
            return max(((end-start+1)*heights[mid]),max(divided(heights,start,mid-1),divided(heights,mid+1,end)));
    }
};

//4. 维护栈，用来维护开始下降的阶梯的信息
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {        
        stack<int> st;
        heights.push_back(0);
        int size = heights.size();
        int res = 0;
        for (int i = 0; i < size; ++i) {
            while (!st.empty() && heights[st.top()] >= heights[i]) {
                int val = st.top();
                st.pop();
                res = max(res, heights[val] * (st.empty() ? i : (i - st.top() - 1)));
            }
            st.push(i);
        }
        return res;
    }
};
