class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>> > pq;
        vector<int>vis(V,0);
        int sum = 0;
        vector<pair<int,int>>mst;
        pq.push({0,{0,-1}});  // {dist,{node,parent}}
        
        while(!pq.empty()){
            auto it = pq.top();
            int wt = it.first;
            int node = it.second.first;
            int parent = it.second.second;
            
            pq.pop();
            
            if(vis[node] == 0){
                vis[node] = 1;
                if(parent != -1){
                    mst.push_back({node,parent});
                }
                sum += wt;
                for(auto it : adj[node]){
                    int adjNode = it[0];
                    int w = it[1];
                    if(!vis[adjNode]){
                        pq.push({w,{adjNode,node}});
                    }
                }
            }
        }
        return sum;
    }
};

// Greedy is the intuition 
// Time complexity of prim's algo is E logE