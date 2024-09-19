// Explanation :- https://www.youtube.com/watch?v=zMakanHmcYQ
// There is a row of N houses, each house can be painted with one of the three colors: red, blue
// or green. The cost of painting each house with a certain color is different. You have to paint
// all the houses such that no two adjacent houses have the same color. Find the minimum
// cost to paint all houses.
// The cost of painting each house in red, blue or green colour is given in the array r[l,
// and respectivelv
// Example 1:
// Input:
// Output: 4
// Explanation:
// 1}
// We can color the houses


class Solution{   
public:
    long long int distinctColoring(int N, int r[], int g[], int b[]){
        vector<vector<long long int>>dp(N,vector<long long int>(3,0));
        dp[0][0] = r[0];
        dp[0][1] = g[0];
        dp[0][2] = b[0];
        
        for(int i=1; i<N; i++){
            dp[i][0] = r[i] + min(dp[i-1][1], dp[i-1][2]);
            dp[i][1] = g[i] + min(dp[i-1][0], dp[i-1][2]);
            dp[i][2] = b[i] + min(dp[i-1][0], dp[i-1][1]);
        }
        
        return min({dp[N-1][0], dp[N-1][1], dp[N-1][2]});
    }
};
