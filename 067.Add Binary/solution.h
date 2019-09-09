// 1. pezy
#include <string>
using std::string;

class Solution {
public:
    string addBinary(string a, string b) {
        string ret;
        bool carry{false};
        for (auto apos=a.size(), bpos=b.size(); apos || bpos || carry; ) {
            bool abit{apos && a[--apos] == '1'};
            bool bbit{bpos && b[--bpos] == '1'};
            ret = (abit ^ bbit ^ carry ? "1" : "0") + ret;
            carry = abit + bbit + carry >= 2;
        }
        return ret;
    }
};

// 2.
class Solution {
public:
    string addBinary(string a, string b) {
        string s;
		s.reserve(a.size() + b.size());
		int c = 0, i = a.size() - 1, j = b.size() - 1;
		while(i >= 0 || j >= 0 || c == 1)
		{
			c += i >= 0 ? a[i--] - '0' : 0;
			c += j >= 0 ? b[j--] - '0' : 0;
			s.push_back((c & 1) + '0');
			c >>= 1;
		}
		reverse(s.begin(), s.end());
		return s;
    }
};

