class Solution
{
private:
	int ahour[4] = { 1,2,4,8 };
	int amin[6] = { 1,2,4,8,16,32 };
     bool visited[10] = {false, false, false, false, false, false, false, false, false};
	vector<string> res;

public:
	void dfs(int num,int hour,int min, int index, string s)
	{
		if (num == 0 )
		{
			if(min < 10) 
				s = to_string(hour) + ":" + "0" + to_string(min);
			else
				s = to_string(hour) + ":" + to_string(min);
			res.push_back(s);
			return;
		}
		else
		{
			for (int i = index; i < 10; i++)
			{
                if(!visited[i])
				{
                    visited[i]=true;
                    if (i < 4 && hour+ahour[i] < 12)
					    dfs(num - 1, hour + ahour[i], min, i + 1, s);
				    else if(i>=4 && min+amin[i-4] < 60)
					    dfs(num - 1, hour, min + amin[i - 4], i + 1, s);
                    visited[i]=false;
                }
			}
		}
	}
	vector<string> readBinaryWatch(int num)
	{
		res.clear();
		if (num <= 0) return { "0:00" };
		//
		string s("");
		dfs(num, 0, 0, 0, s);
		return res;
	}
};