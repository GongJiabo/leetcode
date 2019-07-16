class Solution {
public:
	int lengthOfLastWord(string s) 
	{
		if (s.empty()) return 0;
		int rpos = s.find_last_of(' ');
		while (rpos == (s.size() - 1))
		{
			if (s.empty()) return 0;
			s.erase(rpos);
			rpos = s.find_last_of(' ');
		}
		return s.size() - rpos - 1;
    }
};