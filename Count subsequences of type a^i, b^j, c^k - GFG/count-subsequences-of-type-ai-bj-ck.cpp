// { Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends
//User function template 

class Solution{
  public:
    // s : given string
    // return the expected answer
    int fun(string &s) 
    {
        long mod = 1000000007, a = 0, ab = 0, abc = 0;
    
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == 'a')
                a = (2 * a + 1) % mod;
            else if (s[i] == 'b')
                ab = (2 * ab + a) % mod;
            else
                abc = (2 * abc + ab) % mod;
        }
        
        return abc;
    }
};

// { Driver Code Starts.
 
int main()
 {
    int t;
    cin>>t;
    while(t--) {
        string s;
        cin>>s;
        Solution obj;
        cout<<obj.fun(s)<<endl;
    }
	return 0;
}  // } Driver Code Ends