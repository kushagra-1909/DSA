// Brute force Approach 
class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        int rows = lines.size();
        int cols = lines[0].size();
        
        int mini = INT_MAX;
        int maxi = INT_MIN;
        
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                if(lines[i][j] < mini){
                    mini = min(mini,lines[i][j]);
                }
                
                if(lines[i][j] > maxi){
                    maxi = max(maxi,lines[i][j]);
                }
            }
        }
        
        int ans = 0;
        for(int i=mini; i<=maxi; i++){
            int cnt = 0;
            for(int j=0; j<rows; j++){
                if(i >= lines[j][0] && i <= lines[j][1]){
                    cnt ++;
                }
            }
            ans = max(ans,cnt);
        }
        return ans;
    }
};

// Optimized Approach
class Solution {
  public:
    int maxIntersections(vector<vector<int>> lines, int N) {
        map<int,int>m;
        int r = lines.size();
        for(int i=0; i<r; i++){
            m[lines[i][0]]++;
            m[lines[i][1] + 1]--;
        }
        
        int sum  = 0;
        int ans = 0;
        for(auto it: m){
            sum += it.second;
            ans = max(ans,sum);
        }
        return ans; 
    }
};