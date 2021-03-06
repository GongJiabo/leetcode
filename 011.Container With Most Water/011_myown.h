//暴力方法
class Solution {
public:
int LessOne(int& a, int& b)
{
	if (a < b) return a;
	else return b;
}
int maxArea(vector<int>& height)
{
	int max = 0;
	int size = height.size();
	for (int i = 0; i < size; i++)
	{
		for (int j = i + 1; j < size; j++)
		{
			if (i == j) continue;
			int area = (j - i)*LessOne(height[i], height[j]);
			if (area>max) max = area;
		}
	}
	return max;
}
};

//双指针
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0,r=height.size()-1;
        int maxs=0, s;
        while(l<r)
        {
            s=(r-l)*min(height[l],height[r]);
            maxs=max(maxs,s);
            if(height[l]<height[r])
                l++;
            else r--;
        }        
        return maxs;
    }
};