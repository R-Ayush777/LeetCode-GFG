class Solution {
public:
    int memo[31] = {0};
    int fib(int n) 
    {
        if(n <= 1)
            return n;
        if(memo[n])
            return memo[n];
        return memo[n] = fib(n - 1) + fib(n - 2);
    }
};