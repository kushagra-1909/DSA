// You are given a graph with n vertices (0 to n-1) and m edges. You can remove one edge from anywhere and add that edge between any two vertices in one operation. Find the minimum number of operations that will be required to connect the graph.
// If it is not possible to connect the graph, return -1.

// Example 1: 

// Input:
// n = 4
// m = 3
// Edges = [ [0, 1] , [0, 2] , [1, 2] ]
// Output:
// 1
// Explanation:
// Remove edge between vertices 1 and 2 and add between vertices 1 and 3.
 

// Example 2:

// Input:
// n = 6
// m = 5
// Edges = [ [0,1] , [0,2] , [0,3] , [1,2] , [1,3] ]
// Output:
// 2
// Explanation:
// Remove edge between (1,2) and(0,3) and add edge between (1,4) and (3,5)

// Approach -> sabse pehle saari edges ko likh lo phir disjoint set se saari edges ko jod do toh jin u,v ke liye ulimate parent barabar aajaye unko extra edges mein count kar lenge aur phir mein apni parent array mein traverse karunga aur jinke parent vo khud h vo ek alag component hoga phir agar 
// if(extraEdges >= noOfComponents){
//      return noOfComponents-1;
// }
// else{
//     return -1;
// }

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
            if(ulp_u == ulp_v);
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
            if(ulp_u == ulp_v){
                return;   
            }
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
    int Solve(int n, vector<vector<int>>& edge) {
        DisjointSet ds(n-1); // 0 based indexing h toh 6 nodes ki numbering 0 to 5 h toh mein 5 bhejunga jisse vo apne hissab se set krle
        int extraEdge = 0;
        for(auto it : edge){
            int u = it[0];
            int v = it[1];
            if(ds.findUPar(u) == ds.findUPar(v)){
                extraEdge++;
            }
            else{
                ds.unionBySize(u,v);
            }
        }
        
        int components = 0;
        for(int i=0; i<=n; i++){
            if(ds.parent[i] == i){
                components++;
            }
        }
        int ans = components-1;
        if(extraEdge >= ans){
            return ans;
        }
        return -1;
    }
};