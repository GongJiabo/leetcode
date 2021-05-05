//1.数组存储元素，利用diff标记不同的个数
//循环内每次都要判断 字符串或者数组是否相等，可以用一个变量记录字母不匹配的个数，然后每次只需判断这个变量是否为0即可，相比上两种，节约了常数时间。
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int len_s = s.length(), len_p = p.length();
        if(len_s < len_p ) return ans;
        vector<int> freq_s(26, 0), freq_p(26, 0);
        for(int i=0; i<len_p; i++){
            freq_p[p[i] - 'a']++;
            freq_s[s[i] - 'a']++;
        }
        int dif = 0;
        for(int i=0; i<26; i++){
            if(freq_s[i] != freq_p[i])
                dif++;
        }
        if(dif == 0) ans.push_back(0);
        for(int l = 0, r = len_p; r < len_s; r++, l++){
            freq_s[s[l] - 'a']--;
            freq_s[s[r] - 'a']++;
            if(s[l] != s[r]){
                if(freq_s[s[l] - 'a'] == freq_p[s[l] - 'a']) dif--;
                else if(freq_s[s[l] - 'a']+1 == freq_p[s[l] - 'a']) dif++;
                if(freq_s[s[r] - 'a'] == freq_p[s[r] - 'a']) dif--;
                else if(freq_s[s[r] - 'a']-1 == freq_p[s[r] - 'a']) dif++;
            }
            if(dif == 0) ans.push_back(l+1);
        }
        return ans;
    }
};

//2.hash table
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        int lenS = (int)s.size(), lenP = (int)p.size();
        if(lenP > lenS) return ans;
        vector<int> hashtableP(256, 0);
        vector<int> hashtableS(256, 0);
        for(auto ch : p) ++hashtableP[ch];
        int l = 0, r = -1; // 滑动窗口初始化为一个不存在的区间[0, -1]
        while(r < lenS-1) // r == lenS-1时退出循环
        {
            if (r+1 < lenS) ++hashtableS[s[++r]]; // 窗口右边界右移一位 并标记访问到的值
            if(r < lenP-1) continue; // 符合条件的r一定 >= p.length - 1
            if(hashtableP == hashtableS) ans.push_back(l);
            --hashtableS[s[l++]]; // 窗口左边界右移一位 并删除曾经访问的值的标记
        }
        return ans;
    }
};
