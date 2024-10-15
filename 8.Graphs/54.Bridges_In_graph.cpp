// There are n servers numbered from 0 to n - 1 connected by undirected server-to-server connections forming a network where connections[i] = [ai, bi] represents a connection between servers ai and bi. Any server can reach other servers directly or indirectly through the network.

// A critical connection is a connection that, if removed, will make some servers unable to reach some other server.

// Return all critical connections in the network in any order.

// Tarjan's Algorithm
// Bridges-> Any edge on whose removal graph is broken down into two or more components

class Solution {
private:
    int timer = 1;
private:
    void dfs(int node, int parent, vector<int> &vis, vector<int>adj[], int tin[], int low[], vector<vector<int>>&bridges){
        vis[node] = 1;
        tin[node] = low[node] = timer;
        timer ++;
        for(auto it : adj[node]){
            if(it == parent) continue;
            if(vis[it] == 0){
                dfs(it,node,vis,adj,tin,low,bridges);
                low[node] = min(low[node], low[it]);
                if(low[it] > tin[node]){
                    bridges.push_back({it,node});
                }
            }
            else {
                low[node] = min(low[node], low[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>&connections){
        // No of extra edges which i can delete can use disjoint data structure 
        // ans = total number of edges - extra Edges
        vector<int>adj[n];
        for(auto it : connections){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int>vis(n,0);
        int tin[n];
        int low[n];
        vector<vector<int>>bridges;
        dfs(0,-1,vis,adj,tin,low,bridges);
        return bridges;
    }
};

// basic intuition is that parent(node) -> it toh check kar rahe ki kya mein parent ke alawa kisi aur node tak pahuch sakta hun kya

// time complexity -> O(V+2E)
