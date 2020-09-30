//1. vector
class Solution {
public:
   	string simplifyPath(string path)
	{
		int n = path.size();
		vector<string> temp, temp2;
		string word(""), res("/");
		for (int i = 0; i < n; i++)
		{
			if (path[i] != '/')
				word += path[i];
			else
			{
				temp.push_back(word);
				word = "";
			}
		}
		if (path[n - 1] != '/') temp.push_back(word);

		
		for (int i = 0; i < temp.size(); i++)
		{
			if (temp[i] == "") continue;
			else if (temp[i] != ".." && temp[i] != ".")
				temp2.push_back(temp[i]);
			else if (temp[i] == ".")
				continue;
			else if (temp[i] == "..")
			{
				if (!temp2.empty())
					temp2.pop_back();
			}
		}
		for (int i = 0; i < temp2.size(); i++)
		{
            if(i != temp2.size()-1)
			    res += temp2[i] + "/";
            else
                res += temp2[i];
        }
		return res;
    }
};

//2. stack
class Solution {
public:
    string simplifyPath(string path) 
    {
        stack<string> st;
        //
        string word = "";
        for (int i = 0; i < path.size(); i++)
        {
            if (isalpha(path[i]))
                word += path[i];
            else if (path[i] == '/')
            {
                if (!word.empty())
                    st.push(word);
                word.clear();
            }
            else if (!st.empty() && path[i] == '.' && path[i + 1] == '.')
            {
                st.pop();
                i++;
            }
        }
        if (st.empty())
            return "/";
        string res;
        while (!st.empty())
        {
            res.insert(0, st.top());
            res.insert(0, "/");
            st.pop();
        }
        
        return res;
    }
};