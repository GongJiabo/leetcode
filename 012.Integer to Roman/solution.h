#include <string>
#include <unordered_map>
using std::string;

class Solution {
public:
    string intToRoman(int num) {
        std::map<int, string> map = {{1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"}, {100, "C"}, 
                                     {90, "XC"}, {50, "L"}, {40, "XL"}, {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}};  //stl之map！
        string ret;
        for (auto iter = map.rbegin(); iter != map.rend(); ++iter)  //注意是反向迭代器？
            while (num >= iter->first)
            {
                ret += map[iter->first];
                num -= iter->first;
            }
        return ret;
    }
};

//map倒着放的？？
+		[0]	(1, "I")	std::pair<int const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >
+		[1]	(4, "IV")	std::pair<int const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >
+		[2]	(5, "V")	std::pair<int const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >
+		[3]	(9, "IX")	std::pair<int const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >
+		[4]	(10, "X")	std::pair<int const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >
+		[5]	(40, "XL")	std::pair<int const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >
+		[6]	(50, "L")	std::pair<int const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >
+		[7]	(90, "XC")	std::pair<int const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >
+		[8]	(100, "C")	std::pair<int const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >
+		[9]	(400, "CD")	std::pair<int const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >
+		[10]	(500, "D")	std::pair<int const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >
+		[11]	(900, "CM")	std::pair<int const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >
+		[12]	(1000, "M")	std::pair<int const ,std::basic_string<char,std::char_traits<char>,std::allocator<char> > >
