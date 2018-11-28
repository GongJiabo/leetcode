class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2)
    {
        vector<int> sum;
	    int i, j;
	    for ( i = 0, j = 0; i < nums1.size(), j < nums2.size();)
	    {
		    if (i < nums1.size() && j < nums2.size() && nums1[i] < nums2[j] )
		    {
		    	sum.push_back(nums1[i]);
		    	i++;
	    	}
	    	else if (i < nums1.size() && j < nums2.size() && nums1[i] >= nums2[j])
	    	{
		    	sum.push_back(nums2[j]);
		    	j++;
	    	}
	    	if (i == nums1.size() || j == nums2.size()) break;
	    }
	    if (i == nums1.size())
    	{
	    	while (j < nums2.size())
	    	{
		    	sum.push_back(nums2[j]);
		    	j++;
	    	}
	    }
	    if (j == nums2.size())
	    {
	    	while (i < nums1.size())
	    	{
		    	sum.push_back(nums1[i]);
		    	i++;
		    }
	    }
     	int n=nums1.size()+nums2.size();
        if(n%2==0) return double(sum[n/2-1]+sum[n/2])/2.0;
        else return double(sum[n/2]);      
    }
};