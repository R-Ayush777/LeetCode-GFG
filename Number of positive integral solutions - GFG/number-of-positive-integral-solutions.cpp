// { Driver Code Starts
#include <iostream>
using namespace std;


 // } Driver Code Ends


class Solution{
public:
    long posIntSol(string s)
    {
        int n = 0, r = 0;

        for (int i = 0; i < s.size(); i++)
        {
            if (s[i] == '+')
                r++;
            if (s[i] == '=')
                n = stoll(s.substr(i + 1));
        
        }
        n = n - 1;
        long long val1 = 1, val2 = 1;

        for (long long i = n; i > n - r; i--)
            val1 *= i;
        for (long long i = 1; i <= r; i++)
            val2 *= i;

        return val1 / val2;
    }
};




// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    for(int i=0;i<t;i++)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.posIntSol(s)<<endl;
    }
    return 0;
}
  // } Driver Code Ends