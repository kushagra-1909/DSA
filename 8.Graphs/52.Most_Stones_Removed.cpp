// I can only remove a stone if it shares row and col with some other stone 
// Approach -> jo stones share kar rahe col aur row ko ek dusre ke saath unko connect kardo phir jitne bhi connect hue h unmein se 1 left hojayega 

// answer = total number of stones - no. of Connected components
// aur koi bhi 2 stones aapas mein connected tab honge jab vo same row ya column share kar rahe honge 

// There are n stones at some integer coordinate points on a 2D plane. Each coordinate point may have at most one stone.

// You need to remove some stones. 

// A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

// Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the maximum possible number of stones that you can remove.

 

// Example 1:

// Input:
// n=6
// [[0 0] ,[ 0 1], [1 0] ,[1 2] ,[2 1] ,[2 2]]

// Output:
// 5

// Example:
// One way to remove 5 stones are
// 1--[0,0]
// 2--[1,0]
// 3--[0,1]
// 4--[2,1]
// 5--[1,2]

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
    int maxRemove(vector<vector<int>>& stones, int n) {
        int maxRow = 0;
        int maxCol = 0;
        
        for(auto it : stones){
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        
        DisjointSet ds(maxRow + maxCol + 1);
        
        for(auto it : stones){
            int r = it[0];
            int c = maxRow + 1 + it[1];
            ds.unionBySize(r,c);
        }
        
        int cnt = 0;
        for(int i=0; i<= maxRow + maxCol + 1; i++){
            if(ds.findUPar(i) == i && ds.size[i] > 1){
                cnt++;
            }
        }
        
        return n-cnt;
    }
};