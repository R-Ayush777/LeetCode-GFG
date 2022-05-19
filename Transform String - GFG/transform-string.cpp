// { Driver Code Starts
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
class Solution
{
    public:
    int transform (string A, string B)
    {
        int ans = 0;
        int i = B.size()-1;
        int j = A.size()-1;
        
        for(; j>=0 ; j--){
            if(A[j] != B[i])
                ans++;
            else
                i--;
        }
        
        sort(A.begin(),A.end());
        sort(B.begin(),B.end());
        
        if(A!=B)
            return -1;
        return ans;
    }
};


// { Driver Code Starts.

int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  // } Driver Code Ends