// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    vector<int> solve(vector<vector<int>> &a, int n, int type) {
        int r = (type == 1) ? n/2 : (n/2)-1;
        int c = (type == 1) ? (n/2)-1 : n/2;
        vector<int> res;
        res.push_back(a[r][c]);
    
        int state = 0;
        int stepCnt = 2;
        int turn = 1;
        int steps = 1;
        int total = (n*n)/2 - 1;
    
        while(total--) {
            
            if(type == 1){
                if(state == 0) r--;
                else if(state == 1) c++;
                else if(state == 2) r++;
                else if(state == 3) c--;
            }
            else {
                if(state == 0) r++;
                else if(state == 1) c--;
                else if(state == 2) r--;
                else if(state == 3) c++;
            }
    
            res.push_back(a[r][c]);
    
            if(steps == stepCnt) {
                if(turn%2 == 0) {
                    stepCnt += 2;
                }
                turn++;
                state = (state+1)%4;
                steps = 0;
            }
            steps++;
        }
        return res;
    }
    
    vector<vector<int>> formCoils(int n) {
        n = 4*n;
        
        vector<vector<int>> a(n, vector<int> (n));
        int cnt = 1;
    
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                a[i][j] = cnt;
                cnt++; 
            }
        }
        
        vector<vector<int>> ans;
        
        vector<int> t1 = solve(a,n,1);
        vector<int> t2 = solve(a,n,2);
        
        ans.push_back(t1);
        ans.push_back(t2);
        
        return ans;
    }    
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        
        cin>>n;

        Solution ob;
        vector<vector<int>> ptr = ob.formCoils(n);
        
        for(auto it: ptr)
        {
            for(int i: it)
                cout<<i<<" ";
            cout<<endl;
        }
    }
    return 0;
}  // } Driver Code Ends