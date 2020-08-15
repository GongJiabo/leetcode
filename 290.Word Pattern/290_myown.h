class Solution {
public:
        bool wordPattern(string pattern, string str) 
    {
        int n = pattern.size();
        map<string,char> record;
        vector<string> vstr = split(str, " ");
        //
        if (vstr.size() != n)
            return false;
        //
        for (int i = 0; i < n; i++)
        {
            if (record.find(vstr[i]) == record.end())
                if (pattern.substr(0, i).find(pattern[i]) == string::npos)
                    record[vstr[i]] = pattern[i];
                else
                    return false;
            else
                if (record[vstr[i]] != pattern[i])
                    return false;
        }
        //
        return true;
    }

    
    vector<string> split(const string& s, const string& seperator) {
        vector<string> result;
        typedef string::size_type string_size;
        string_size i = 0;

        while (i != s.size()) {
            //找到字符串中首个不等于分隔符的字母；
            int flag = 0;
            while (i != s.size() && flag == 0) {
                flag = 1;
                for (string_size x = 0; x < seperator.size(); ++x)
                    if (s[i] == seperator[x]) {
                        ++i;
                        flag = 0;
                        break;
                    }
            }

            //找到又一个分隔符，将两个分隔符之间的字符串取出；
            flag = 0;
            string_size j = i;
            while (j != s.size() && flag == 0) {
                for (string_size x = 0; x < seperator.size(); ++x)
                    if (s[j] == seperator[x]) {
                        flag = 1;
                        break;
                    }
                if (flag == 0)
                    ++j;
            }
            if (i != j) {
                result.push_back(s.substr(i, j - i));
                i = j;
            }
        }
        return result;
    }
};