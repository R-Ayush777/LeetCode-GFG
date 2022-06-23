// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maxGold(int n, int m, vector<vector<int>> M)
    {
        int ans=0;
        for(int i=0;i<n;i++)
            ans=max(ans,M[i][0]);
        
        int x;
        for(int j=1;j<m;j++){
            for(int i=0;i<n;i++){
                x=M[i][j-1];
                if(i-1>=0)
                    x= max(x,M[i-1][j-1]);
                if(i+1<n)
                    x = max(x,M[i+1][j-1]);
                M[i][j]+=x;
                ans=max(ans,M[i][j]);
            }
        }
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  // } Driver Code Ends