string intToRoman(int num) 
{
	//1-3999	
	string result="";
	if (num > 3999 || num < 1) return result;
	//
	int value[] = { 1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1 };
	string mark[] = { "M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I" };
	//
	for (int i = 0; num != 0; i++)
	{
		while (num >= value[i])
		{
			result += mark[i];
			num -= value[i];
		}
	}
	return result;
}