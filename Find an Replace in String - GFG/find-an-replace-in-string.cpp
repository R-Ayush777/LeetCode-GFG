// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    string findAndReplace(string S ,int Q, int index[], string sources[], string targets[]) {
        // code here
        string ans="";
        unordered_map<int,pair<string,int>>m;
        for(int i=0;i<Q;i++){
            string r = sources[i];
            int len =r.length();
            if(S.substr(index[i],len)==r){
                m[index[i]]={targets[i],len};
            }
        }
        for(int i=0;i<S.length();i++){
            if(m.find(i)==m.end()){
                ans+=S[i];
            }else{
                ans+=m[i].first;
                i+=(m[i].second-1);
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
        string S;
        cin>>S;
        
        int Q;
        cin>>Q;
        int index[Q];
        string sources[Q], targets[Q];
        
        for(int i=0; i<Q; i++)
            cin>>index[i];
        for(int i=0; i<Q; i++)
            cin>>sources[i];
        for(int i=0; i<Q; i++)
            cin>>targets[i];

        Solution ob;
        cout<<ob.findAndReplace(S,Q,index,sources,targets)<<endl;
    }
    return 0;
}  // } Driver Code Ends