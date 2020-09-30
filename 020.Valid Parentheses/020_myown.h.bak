class Solution {
public:
bool isValid(string s) 
{
	vector<char> l_vc;
	//vector<char> r_vc;
	int n = s.size();
    if(n==0) return true;
	else if (n % 2 != 0) return false;
	for (int i = 0; i < n ; i++)
	{
        if(i==0)
        {
            if(s[0]==')' || s[0]==']' || s[0]=='}')
                return false;
        }
		if (s[i] == '(' || s[i] == '{' || s[i] == '[') l_vc.push_back(s[i]);
		else
		{
				if (s[i] == ')' && *(l_vc.end()-1) == '(') l_vc.pop_back();
			else if (s[i] == ']' && *(l_vc.end()-1) == '[') l_vc.pop_back();
			else if (s[i] == '}' && *(l_vc.end()-1) == '{') l_vc.pop_back();
			else return false;
		}
	}
	if (l_vc.size() == 0)  return true;
	else return false;
}
};