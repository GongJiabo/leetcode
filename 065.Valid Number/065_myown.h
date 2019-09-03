class Solution {
public:
	bool isNumber(string s) {
		bool point = false;
		bool hasE = false;
		int n = s.size();
		int i = 0;
		//trim the space
		while (i < n && isspace(s[i])) i++;
		//check empty 
		if (i==n) return false;
		//check sign
		if (s[i] == '+' || s[i] == '-') i++;

		const char head = s[i];
		for (; i<n; i++) {
			// if meet point
			if (s[i] == '.') 
			{
				if (hasE == true || point == true) {
					return false;
				}
				if (s[i] == head && !isdigit(s[i + 1])) {
					return false;
				}
				point = true;
				continue;
			}
			//if meet "e"
			if (s[i] == 'e') 
			{
				if (hasE == true || s[i] == head) {
					return false;
				}
				i++;
				if (s[i] == '+' || s[i] == '-')  i++;
				if (!isdigit(s[i])) return false;

				hasE = true;
				continue;
			}
			//if meet space, check the rest chars are space or not
			if (isspace(s[i])) 
			{
				for (; s[i] != '\0'; i++) {
					if (!isspace(s[i])) return false;
				}
				return true;
			}

			if (!isdigit(s[i]))
			{
				return false;
			}

		}
		return true;
	}
};