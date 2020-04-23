//
using namespace std;
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m=matrix.size();if(m==0)return 0;
        int n=matrix[0].size();
        int flag[m][n];
        memset(flag,0,sizeof(flag));
      
		//先计算一个flag数组，表示这个位置，同一列向上有多少个连续的1
        for(int i=m-1;i>=0;i--){
			for(int j=0;j<n;j++){
                if(matrix[i][j]=='1'){
                    int temp=0;
                    for(int t=i;t>=0;t--){
                        if(matrix[t][j]=='1')temp++; 
                        else if(matrix[t][j]=='0')break;
                    }   
                    flag[i][j]=temp;
                }
            }
        }
        //根据flag数组计算
        int res=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(flag[i][j]>0){//如果这里是1
                	int temp=0;
                    //向右找同一行，值不小于本元素的，说明他们可以连在一起
                    for(int t=j;t<n;t++){
                    	if(flag[i][t]>=flag[i][j])temp++;
                    	else break;
	                }
                    //向左找同一行，值不小于本元素的，说明他们可以连在一起
	                for(int t=j;t>=0;t--){
	                    if(flag[i][t]>=flag[i][j])temp++;
	                    else break;
	                }	
	                //temp需要-1，因为向左向右都是从本元素开始的，它被计算了两次
                    res=max(res,flag[i][j]*(temp-1));
				}
                else continue;
            }
        }
        return res;
    }
};


