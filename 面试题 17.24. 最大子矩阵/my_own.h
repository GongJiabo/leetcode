```c++
class Solution {
public:
    vector<int> getMaxMatrix(vector<vector<int>>& matrix) 
    {
        //保存矩阵的左上角和右下角的坐标
        vector<int> res(4);  
        

        int m=matrix.size();
        int n=matrix[0].size();
        //保存每一列的和，即把二维矩阵压缩到一维数组    
        vector<int> num(n);
    
        //相当于53题最大子序和中的dp[i-1]
        int sum;
    
        //保存当前最大和矩阵的左上角的坐标
        int x,y;   
    
        //记录当前和最大的子矩阵的和
        int ans=INT_MIN;   
    
        //i是矩阵的上行边，j是矩阵的下行边
        for(int i=0;i<m;i++)
        {
            //上行边一但更换，num就得清0从新算，如果i不换而是换j的话那num每次只要每个对应对应位置加上新加入的这一行就行
            num.assign(n,0);
            for(int j=i;j<m;j++)
            {
                //每次更换下行边，sum都要置0，从新算
                sum=0;
                //计算每一列的值
                for(int k=0;k<n;k++)
                {
                    //添加新加入的行
                    num[k]+=matrix[j][k];
                    
                    //即dp[i-1]>0
                    if(sum>0)
                        sum+=num[k];
                    //dp[i-1]<=0,dp[i]=num[i],x和y重新记录新的矩形的左上角
                    else
                    {
                        sum=num[k];
                        //横坐标即为上行边i，纵坐标即为当前列k
                        x=i,y=k;
                    }
    
                    if(sum>ans)
                    {
                        ans=sum;
                        res={x,y,j,k};
                    }
                }        
            }
        }
        return res;
    }

};
```

