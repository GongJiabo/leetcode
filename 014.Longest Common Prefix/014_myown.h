class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
		string result = "";
	//
	if (strs.size() == 0) return result;
	else if (strs.size() == 1) return strs[0];
	//
	bool tag = true;
	int i;
	for (i = 0; i < strs[0].size(); i++)
	{
        if (!tag) break;
		char ch = strs[0][i];
		for (int j = 1; j < strs.size(); j++)
		{
			if (i < strs[j].size())
			{
				if (strs[j][i] == ch) continue;
				else
				{
					tag = false;
					break;
				}
			}
			else
			{
				tag = false;
				break;
			}
		}
	}
	if (tag) result = strs[0].substr(0, i);
	else result = strs[0].substr(0, i - 1);
	return result;
    }
};