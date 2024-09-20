// Given two strings A and B. Find the minimum number of steps required to transform string
// A into string B. The only allowed operation for the transformation is selecting a character
// from string A and inserting it in the beginning of string A.
// Example 1:
// Input:
// A = "abd"
// B = "bad"
// Output: 1
// Explanation: The conversion can take place in
// 1 operation: Pick 'b' and place it at the front.

// Transform string wale questions mein -> pehle length check karte h dono ki length same honi chhaiye aur phir no. of characters check karte h  -> ye map ki help se check kar sakte h

class Solution
{
    public:
    int transform (string A, string B)
    {
        if(A.size() != B.size()){
            return -1;
        }
        
        // for checking number of characters in string
        unordered_map<char,int>mpp;
        for(int i=0; i<A.size(); i++){
            mpp[A[i]]++;
            mpp[B[i]]--;
        }
        
        for(auto it : mpp){
            if(it.second != 0){
                return -1;
            }
        }
        
        int i = A.size()-1, j = B.size()-1;
        int cnt = 0;
        while(i>=0 && j>=0){
            if(A[i] == B[j]){
                i--;
                j--;
            }else{
                cnt++;
                i--;
            }
        }
        return cnt;
    }
};