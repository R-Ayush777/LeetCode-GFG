// { Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    vector<int> numAndDen(int n, int d) {
       // code here
       double num = (double)n / (double)d;
       vector<int>ans;
       double mx = 0;
       for(int i=2 ; i<10000 ; i++)
       {
           int j = n * i / d;
           double num2 = (double)j / (double)i;
           if(num2 < num  && mx < num2 && __gcd(i , j) == 1)
           {
               mx = num2;
               ans = {j , i};
           }
       }
       return ans;
   }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,d;
        cin >> n >> d;
        Solution ob;
        vector<int>ans=ob.numAndDen(n,d);
        for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    }
    return 0;
}
  // } Driver Code Ends