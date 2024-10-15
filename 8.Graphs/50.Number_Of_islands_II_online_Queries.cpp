// You are given a n,m which means the row and column of the 2D matrix and an array of  size k denoting the number of operations. Matrix elements is 0 if there is water or 1 if there is land. Originally, the 2D matrix is all 0 which means there is no land in the matrix. The array has k operator(s) and each operator has two integer A[i][0], A[i][1] means that you can change the cell matrix[A[i][0]][A[i][1]] from sea to island. Return how many island are there in the matrix after each operation.You need to return an array of size k.
// Note : An island means group of 1s such that they share a common side.

 

// Example 1:

// Input: n = 4
// m = 5
// k = 4
// A = {{1,1},{0,1},{3,3},{3,4}}

// Output: 1 1 2 2
// Explanation:
// 0.  00000
//     00000
//     00000
//     00000
// 1.  00000
//     01000
//     00000
//     00000
// 2.  01000
//     01000
//     00000
//     00000
// 3.  01000
//     01000
//     00000
//     00010
// 4.  01000
//     01000
//     00000
//     00011
 

 

// Example 2:

// Input: n = 4
// m = 5
// k = 4
// A = {{0,0},{1,1},{2,2},{3,3}}

// Output: 1 2 3 4
// Explanation:
// 0.  00000
//     00000
//     00000
//     00000
// 1.  10000
//     00000
//     00000
//     00000
// 2.  10000
//     01000
//     00000
//     00000
// 3.  10000
//     01000
//     00100
//     00000
// 4.  10000
//     01000
//     00100
//     00010

// 0-> sea and 1 -> island

class DisjointSet {
    vector<int>rank,parent,size;
    public:
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
    vector<int> numOfIslands(int n, int m, vector<vector<int>> &operators) {
        DisjointSet ds(n*m); // total number of nodes
        vector<vector<int>>vis(n, vector<int>(m,0));
        int cnt = 0;
        vector<int>ans;
        
        for(auto it : operators){
            int row = it[0];
            int col = it[1];
            
            if(vis[row][col] == 1){
                ans.push_back(cnt);
                continue;
            }
            
            vis[row][col] = 1;
            cnt++;
            
            int dr[4] = {-1,0,1,0};
            int dc[4] = {0,1,0,-1};
            
            for(int i=0; i<4; i++){
                int nr = row + dr[i];
                int nc = col + dc[i];
                
                if(nr >= 0 && nr < n && nc >=0 && nc < m){
                    if(vis[nr][nc] == 1){
                        int nodeNo = row*m + col;
                        int newNodeNo = nr*m + nc;
                        if(ds.findUPar(nodeNo) != ds.findUPar(newNodeNo)){
                            cnt--;
                            ds.unionBySize(nodeNo, newNodeNo);
                        }
                    }
                }
            }
            ans.push_back(cnt);
        }
        
        return ans;
    }
};