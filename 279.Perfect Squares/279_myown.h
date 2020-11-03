// 1. BFS
class Solution {
public:
    int numSquares(int n) 
    {
        queue<pair<int, int>> q;
        q.push(make_pair(n, 0));
        while (!q.empty())
        {
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            for (int i = 0; ; i++)
            {
                int a = num - i * i;
                if (a < 0)
                    break;
                else if (a == 0)
                    return step + 1;
                else
                {
                    q.push(make_pair(a, step + 1));
                }
            }
        }
        return n;
    }
};

// 2. 设置visited数组 
class Solution {
public:
    int numSquares(int n) 
    {
        queue<pair<int, int>> q;
        q.push(make_pair(n, 0));

        vector<bool> visited(n + 1, false);
        visited[n] = true;

        while (!q.empty())
        {
            int num = q.front().first;
            int step = q.front().second;
            q.pop();

            for (int i = 0; ; i++)
            {
                int a = num - i * i;
                if (a < 0)
                    break;
                else if (a == 0)
                    return step + 1;
                else
                {
                    q.push(make_pair(a, step + 1));
                    visited[a] = true;
                }
            }
        }
        return n;
    }
};