class Solution {
public:
    bool isHappy(int n) 
    {
        vector<int> num;
        set<int> record;
        int sum = n;
        //如何判断死循环？set判断n是否重复
        while (sum != 1)
        {
            num.clear();
            record.insert(n);
            while (n != 0)
            {
                num.push_back(n % 10);
                n = n / 10;
            }
            //
            sum = 0;
            for (int i = 0; i < num.size();i++)
                sum += num[i] * num[i];
            n = sum;
            if (record.find(n) != record.end()) 
                return false;
        }
        return true;
    }
};