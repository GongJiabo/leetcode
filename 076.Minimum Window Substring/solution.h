string minWindow(string s, string t) {
    int count[256] = { 0 };
    for (auto c : t) ++count[c];
    int len = 0, minLength = s.length();
    string res;
    for (int l = 0, r = 0; r < s.length(); ++r) {
        count[s[r]]--;
        if (count[s[r]] >= 0) ++len;
        while (len == t.length()) {
            if (r - l + 1 <= minLength) {
                minLength = r - l + 1;
                res = s.substr(l, r - l + 1);
            }
            count[s[l]]++;
            if (count[s[l]] > 0) --len;
            ++l;
        }
    }
    return res;
}

作者：ivan_allen
链接：https://leetcode-cn.com/problems/minimum-window-substring/solution/76-zui-xiao-fu-gai-zi-chuan-cshuang-zhi-zhen-mo-ba/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。