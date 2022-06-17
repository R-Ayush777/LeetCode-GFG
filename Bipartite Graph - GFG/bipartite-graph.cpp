// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution
{
public:
    bool isBipartite(int V, vector<int> adj[])
    {
        vector<int> color(V, -1);
        for (int u = 0; u < V; u++)
        {
            if (color[u] == -1)
                if (!DFS(u, adj, color, 1))
                    return false;
        }
        return true;
    }

    bool DFS(int u, vector<int> adj[], vector<int> &color, int col)
    {
        if (color[u] != -1)
            return color[u] == col;
        color[u] = col;
        for (int v : adj[u])
        {
            if (!DFS(v, adj, color, col ^ 1))
                return false;
        }
        return true;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isBipartite(V, adj);    
		if(ans)cout << "1\n";
		else cout << "0\n";  
	}
	return 0;
}  // } Driver Code Ends