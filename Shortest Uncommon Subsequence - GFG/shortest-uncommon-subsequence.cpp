// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution {
  public:
  int dp[500][500];
  int helper(string& S,string& T,int i,int j){
      if(i>=S.size()) return 500;
      if(j>=T.size()) return 1;
      if(dp[i][j] !=-1) return dp[i][j];
      int k=j;
      for(;k<T.size();k++){
          if(S[i]==T[k])break;
      }
      if(k==T.size())return 1;
      return dp[i][j] = min(helper(S,T,i+1,j),1+helper(S,T,i+1,k+1));
  }
    int shortestUnSub(string S, string T) {
        memset(dp,-1,sizeof(dp));
        int res =helper(S,T,0,0);
        if(res>=500) return -1;
        return res;
    }
};




// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string S,T;
        cin>>S>>T;

        Solution ob;
        cout << ob.shortestUnSub(S,T) << endl;
    }
    return 0;
}  // } Driver Code Ends