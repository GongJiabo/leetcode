class Solution {
public:
	vector<string> fullJustify(vector<string>& words, int maxWidth) 
	{
		int n = words.size();
		vector<string> res;
		vector<int> vn{0};
		//统计每行单词的个数(最少每个单词之间以一个空格计算)
		int len = 0;
		for (int i = 0; i < n;i++ )
		{
			if (len + words[i].size() + 1 <= maxWidth + 1)
				len += words[i].size() + 1;
			else
			{
				len = 0;
				len += words[i].size() + 1;
				vn.push_back(i);
			}
		}
		vn.push_back(n);
		//将统计的单词按行对齐
		for (auto it = vn.cbegin(); it != vn.cend()-1; it++)
		{
			int beg = *it, end = *(it + 1), num = end - beg, slen = 0;
			string temp("");
			//
			vector<string> vstr(words.begin() + beg, words.begin() + end);
			for (auto vit = vstr.begin(); vit != vstr.end(); vit++)
				slen += vit->size();

			//统计剩余空格的个数
			int nsp = maxWidth - slen;

			//如果是最后一行，左对齐
			if (it == vn.cend() - 2)
			{
				for (int i = 0; i < vstr.size(); i++)
                {
                    if(i == vstr.size()-1)
					    temp += vstr[i];
                    else 
                        temp += vstr[i] + " ";
                }
				string stsp(maxWidth - temp.size(), ' ');
				temp += stsp;
				res.push_back(temp);
				break;
			}

			//如果只有一个单词为左对齐
			if (num == 1)
			{
				string stsp(nsp, ' ');
				temp = vstr[0] + stsp;
                res.push_back(temp);
				continue;
			}
			//如果多个单词左右对齐
			else
			{
				while (nsp > 0)
				{
					for (int i = 0; i < vstr.size() - 1; i++)
					{
						vstr[i] += ' ';
						nsp--;
						if (nsp <= 0) break;
					}
				}
			}
			//构成该行的字符串
			for (int i = 0; i < vstr.size(); i++)
				temp += vstr[i];
			res.push_back(temp);
		}
		return res;
    }
};