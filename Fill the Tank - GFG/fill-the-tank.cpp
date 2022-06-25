// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
class Solution {

public:
long long minimum_amount(vector<vector<int>> &Edges, int num, int source, int *cap){
       vector<int> g[num+1];
      for(int i=0;i<num-1;i++)
      {
          g[Edges[i][0]].push_back(Edges[i][1]);
          g[Edges[i][1]].push_back(Edges[i][0]);
      }
       
       bool vis[num+1];
       
      function<bool(long,long)> dfs = [&](long node,long water){
           
          vis[node] = true;
          if(cap[node-1] > water)
              return false;
          water -= cap[node-1];
           
          int cnt = 0;
           
          for(auto &child : g[node])
          {
              if(!vis[child]) cnt++;
          }
           
          if(cnt == 0) return true;
           
          for(auto &child : g[node])
          {
              if(!vis[child])
              {
                  bool ok = dfs(child,water/cnt);
                  if(!ok) return false;
              }
          }
           
           
          return true;
      };
       
       long start = 0 , end = 1e18;
       long ans = 1e18 + 5;
      while(start <= end)
      {
          long mid = start + (end - start)/2;
          memset(vis,false,sizeof vis);
           
          bool ok = dfs(source,mid);
           
          if(ok)
          {
              ans = min(ans,mid);
              end = mid-1;
          }
          else start = mid+1;
      }
       
       return ans == 1e18+5 ? -1 : ans;
    }
};

// { Driver Code Starts.


int main()
 {
	int T;
	cin>> T;
	while (T--)
	{
	    int num, start;
	    cin>>num>>start;
	    int cap[num];
	    for(int i = 0; i<num; i++)
	        cin>>cap[i];
	    
	    vector<vector<int>> Edges(num-1);
	    for(int i=1;i < num;i++){
	        int u, v; cin >> u >> v;
	        Edges[i-1].push_back(u);
	        Edges[i-1].push_back(v);
	    }
	    
	    
    	Solution obj;
	    long long ans = obj.minimum_amount(Edges, num, start, cap);
	    cout << ans << endl;
	    
	}
	
	return 0;
}  // } Driver Code Ends