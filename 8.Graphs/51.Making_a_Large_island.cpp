// Maximum Connected Group
// You are given a square binary grid. A grid is considered binary if every value in the grid is either 1 or 0. You can change at most one cell in the grid from 0 to 1. You need to find the largest group of connected  1's. Two cells are said to be connected if both are adjacent(top, bottom, left, right) to each other and both have the same value.

// Examples :

// Input: grid = [1, 1]
//              [0, 1]
// Output: 4
// Explanation: By changing cell (2,1), we can obtain a connected group of 4 1's
// [1, 1]
// [1, 1]
// Input: grid = [1, 0, 1]
//              [1, 0, 1]
//              [1, 0, 1]
// Output: 7
// Explanation: By changing cell (3,2), we can obtain a connected group of 7 1's
// [1, 0, 1]
// [1, 0, 1]
// [1, 1, 1]

class DisjointSet {
    public:
    vector<int>rank,parent,size;
        DisjointSet(int n){
            rank.resize(n+1,0);
            parent.resize(n+1);
            size.resize(n+1);
            for(int i=0; i<=n; i++){
                parent[i] = i;
                size[i] = 1;
            }
        }

        // Path compression
        int findUPar(int node){
            if(node == parent[node]){
                return node;
            }

            return parent[node] = findUPar(parent[node]);
        }

        void unionByRank(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;
            if(rank[ulp_u] < rank[ulp_v]){
                parent[ulp_u] = ulp_v;
            }
            else if(rank[ulp_u] > rank[ulp_v]){
                parent[ulp_v] = ulp_u;
            }
            else{
                parent[ulp_v] = ulp_u;
                rank[ulp_u]++;
            }  
        }

        void unionBySize(int u, int v){
            int ulp_u = findUPar(u);
            int ulp_v = findUPar(v);
            if(ulp_u == ulp_v) return;
            if(size[ulp_u] < size[ulp_v]){
                parent[ulp_u] = ulp_v;
                size[ulp_v] += size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u] += size[ulp_v];
            }
        }
};

class Solution {
  public:
    int MaxConnection(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        
        // step 1 -> jitne bhi 1 h un sab ko connect karna, component find karna 
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    int dr[] = {-1,0,1,0};
                    int dc[] = {0,1,0,-1};
                    
                    for(int ind = 0; ind<4; ind++){
                        int nr = i + dr[ind];
                        int nc = j + dc[ind];
                        
                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 1){
                            int nodeNo = i*n + j;
                            int newNodeNo = nr*n + nc;
                            if(ds.findUPar(nodeNo) != ds.findUPar(newNodeNo)){
                                ds.unionBySize(nodeNo, newNodeNo);
                            }
                        }
                    }
                }
            }
        }
        
        // ab mera disjoint data structure ready h
        // step 2 -> har zero par jaakar mein check karunga ki vo kis component se connected h
        int finalAns = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    int dr[] = {-1,0,1,0};
                    int dc[] = {0,1,0,-1};
                    set<int>st;
                    for(int ind = 0; ind<4; ind++){
                        int nr = i + dr[ind];
                        int nc = j + dc[ind];
                        
                        if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc] == 1){
                            int newNodeNo = nr*n + nc;
                            int parent = ds.findUPar(newNodeNo);
                            st.insert(parent);
                        }
                    }
                    int ans  = 0;
                    for(auto it : st){
                        ans += ds.size[it];
                    }
                    ans++;
                    finalAns = max(ans,finalAns);
                }
            }
        }
        
        for(int cellno = 0; cellno < n*n; cellno++){
            finalAns = max(finalAns, ds.size[ds.findUPar(cellno)]);
        }
        
        return finalAns;
    }
};