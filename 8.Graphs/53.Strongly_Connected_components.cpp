//  kosaraju's Algorithm
// Given a Directed Graph with V vertices (Numbered from 0 to V-1) and E edges, Find the number of strongly connected components in the graph.

// in strongly connected components every pair of vertices is reachable from each other


// Algorithm :- 
// Step 1-> sort the edges according to the finish time means do a dfs and then whoever finishes first put it into the stack
// Step 2 -> reverse all the edges of graph
// Step 3 -> Do a dfs of every node by popping out of stack

#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	void dfs(int node, vector<int>&vis, stack<int>&st, vector<vector<int>>& adj){
	    vis[node] = 1;
	    for(auto it : adj[node]){
	        if(!vis[it]){
	            dfs(it,vis,st,adj);
	        }
	    }
	    st.push(node);
	}
	
	void dfs2(int node, vector<int>&vis, vector<vector<int>>& b){
	    vis[node] = 1;
	    for(auto it : b[node]){
	        if(!vis[it]){
	            dfs2(it,vis,b);
	        }
	    }
	}
	
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        // Step 1 -> sort edges according to finish time and push in stack;
        vector<int>vis(V,0);
        stack<int>st;
        
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i,vis,st,adj);
            }
        }
        
        // Step 2 -> reverse the graph
        vector<vector<int>>b(V);
        for(int i=0; i<V; i++){
            for(auto it : adj[i]){
                b[it].push_back(i);
            }
        }
        
        // step 3 -> do a dfs from stack
        for(int i=0; i<V; i++){
            vis[i] = 0;
        }
        int cnt = 0;
        while(!st.empty()){
            int v = st.top();
            st.pop();
            if(!vis[v]){
                cnt++;
                dfs2(v,vis,b);
            }
        }
        
        return cnt;
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
    	int V, E;
    	cin >> V >> E;

    	vector<vector<int>> adj(V);

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    	}

    	Solution obj;
    	cout << obj.kosaraju(V, adj) << "\n";
    }

    return 0;
}

// Time Complexity -> 3*(V+E)
