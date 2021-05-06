// 加减法求值
// 只有小括号 加法 减法
// input: string
// exp: (2 + 3 - (5 - 2)) + 4 = ?
#include <iostream>
#include <stack>

using namespace std;

int addorminus(char c,int n1,int n2)
{
    switch (c)
    {
        case '+':
            return n1+n2;
        case '-':
            return n1-n2;
    }
    return 0;
}

// 如何保证输入合法？
int calculateExpr(string& str)
{
    int n = str.size();
    // 用栈保存符号，进行匹配
    stack<char> s;
    stack<int> sn;
    for(int i=0;i<n;++i)
    {   
        char c = str[i];
        // 遇到左括号，继续
        if(c=='(')
            s.push('(');

        // 遇到右括号，判断符号栈栈顶是否为左括号，为左括号则退栈
        if(c==')')
        {
            if(s.top()=='(')
            {
                s.pop();
                // 栈顶是运算符，继续运算
                if(!s.empty() && (s.top()=='+' || s.top()=='-'))
                {
                    char cal = s.top();
                    s.pop();
                    //
                    int n1=sn.top();
                    cout << "pop:  "<< n1 << endl;
                    sn.pop();

                    int n2=sn.top();
                    cout << "pop:  "<< n2 << endl;
                    sn.pop();

                    // 新元素入栈
                    cout << "push:  " << n2 << cal << n1 <<" = "<< addorminus(cal,n2,n1) << endl;
                    sn.push(addorminus(cal,n2,n1));
                }
            }
            // 括号不匹配
            else
                return -1;
        }

        // 如果是数字
        // 1. 符号栈上有符号(运算符)，且数字栈上有数字
        if('0'<=c && c<='9')
        {
            // 有数字，判断符号栈是否有加减符号 
            if(!s.empty() && s.top()!='(' && !sn.empty())   
            {
               // 取数 进行运算 新数字入栈
                char cal = s.top();
                // 符号退栈
                s.pop();

                int n1 = c - '0', n2=sn.top();
                
                cout << "pop:  " << n2 <<endl;
                cout << "push:  " << n2 << cal << n1 <<" = "<< addorminus(cal,n2,n1) << endl;
                
                // 旧数退栈，新数入栈
                sn.pop();
                sn.push(addorminus(cal,n2,n1));
            }
            // 符号栈栈顶是'(' 或者 数字栈是空
            // 数字直接入栈
            else
            {
                cout << "push:  "<< c - '0' << endl;
                sn.push(c - '0');
            }   
        }
        // 是符号，直接入栈
        if(c=='+' || c=='-')
            s.push(c);
    }
    // 最后数字栈只剩一个，返回
    return sn.top();
}


int main()
{
    string expr;
    cin >> expr;
    int res = calculateExpr(expr);
    cout << res << endl;
    return 0;
}

