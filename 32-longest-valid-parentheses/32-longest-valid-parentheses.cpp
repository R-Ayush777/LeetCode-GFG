class Solution
{
public:
    int longestValidParentheses(string s)
    {
        stack<int> stk;
        stk.push(-1);
        int ans = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ')' and stk.top() != -1 and s[stk.top()] == '(')
            {
                stk.pop();
                ans = max(ans, i - stk.top());
            }
            else
                stk.push(i);
        }
        return ans;
    }
};