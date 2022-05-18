// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution{
public:
    vector<string> ans;
    
    void backtrack(string s, int len)
    {
        if(len == 0)
        {
            ans.push_back(s);
            return;
        }
        backtrack(s.substr(0, s.size()-len)+" "+s.substr(s.size()-len), len-1);
        backtrack(s, len-1);
    }

    vector<string> permutation(string S){
        int len = S.size()-1;
        backtrack(S, len);
        return ans;
    }
};

// { Driver Code Starts.

int  main(){
    int t;
    cin>>t;
    while(t--){
        string S;
        cin>>S;
        vector<string> ans;
        Solution obj;
        ans = obj.permutation(S);
        for(int i=0;i<ans.size();i++){
            cout<<"("<<ans[i]<<")";
        }
        cout << endl;
    }
}
  // } Driver Code Ends