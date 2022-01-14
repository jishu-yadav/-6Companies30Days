// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
    //Function to find if the given edge is a bridge in graph.
    void dfs(int node,vector<int>&vis,vector<int>adj[],int c, int d){
    vis[node]=1;
    for(auto e:adj[node]){
        if((node==c && e==d)||(node==d && e==c))
         continue;
     if(!vis[e])
         dfs(e,vis,adj,c,d);
    }
}

   int isBridge(int V, vector<int> adj[], int c, int d) 
   {
       vector<int>vis(V,0);
       dfs(c,vis,adj,c,d);
       if(!vis[d])return 1;
       return 0;
   }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        int i=0;
        while (i++<E) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back (v);
            adj[v].push_back (u);
        }
        
        int c,d;
        cin>>c>>d;
        
        Solution obj;
    	cout << obj.isBridge(V, adj, c, d) << "\n";
    }

    return 0;
}

  // } Driver Code Ends
