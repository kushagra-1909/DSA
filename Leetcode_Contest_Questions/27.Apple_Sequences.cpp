// There is an array of A's and O's. A stands for Apple, O stands for Orange. We have m number
// of spells, each spell allows us to convert an orange into an apple.
// Find the longest sequence of apples you can make, given an array and the value of m.
// Example 1:
// Input: N = 5 , M = 1, str[] = 'AAOAO'
// Output: 4
// Explanation: Changing the
// 3rd position into an apple
// us the maximum possible
// orange at
// gives
// answer.

class Solution{   
public:
    int appleSequences(int N, int M, string arr){
        int r=0, l=0;
        int cnt = 0;
        int ans = 0;
        while(r<N){
            if(arr[r] == 'O'){
                cnt++;
            }
            while(cnt > M){
                if(arr[l] == 'O'){
                    cnt--;
                }
                l++;
            }
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};