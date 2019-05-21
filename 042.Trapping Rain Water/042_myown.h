// version 1
class Solution {
public:
int trap(vector<int>& height) 
{
	int n = height.size();
    if(n<2) return 0;
    //
	int sum = 0;
	//
	for (int i = 1; ; i++)
	{a
		vector<int> tag;
		for (int j = 0; j < n; j++)
		{
			if (height[j] >= i) tag.push_back(j);
		}
        if(tag.size()==0) return sum;
		for (int k = 1; k < tag.size(); k++)
			sum += tag[k] - tag[k - 1] - 1;
	}
	return sum;
}
};

//version 2
class Solution {
public:
int trap(vector<int>& height) 
{
	int n = height.size();
    if(n<2) return 0;
	int sum = 0;
	//find keng
	for (int i = 1; i < n-1;i++)
	{
		vector<int> vl, vr;
		//find left_max
		for (int l = i-1; l >= 0; l--)
			if (height[l] > height[i]) vl.push_back(height[l]);
        
        if(vl.empty()) continue;
		int left = *max_element(vl.begin(), vl.end());
        
		//find right_max
		for (int r = i+1; r < n; r++)
			if (height[r] > height[i]) vr.push_back(height[r]);
        if(vr.empty()) continue;
		int right = *max_element(vr.begin(), vr.end());
        
		if (left < height[i] ||right < height[i]) continue;
		else sum += min(left, right) - height[i];
	}
	return sum;
}
};

// 超出时间限制！！！

//version 3
class Solution {
public:
int trap(vector<int>& height)
{
    int ans = 0;
    int size = height.size();
    for (int i = 1; i < size - 1; i++) {
        int max_left = 0, max_right = 0;
        for (int j = i; j >= 0; j--) { //Search the left part for max bar size
            max_left = max(max_left, height[j]);
        }
        for (int j = i; j < size; j++) { //Search the right part for max bar size
            max_right = max(max_right, height[j]);
        }
        ans += min(max_left, max_right) - height[i];
    }
    return ans;
}
};