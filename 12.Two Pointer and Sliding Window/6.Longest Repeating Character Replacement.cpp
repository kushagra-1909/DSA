// You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

// Return the length of the longest substring containing the same letter you can get after performing the above operations.

class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0, r=0, maxf = 0;
        int n = s.size();
        int hash[26] = {0};
        int maxlen = 0;
        while(r < n){
            hash[s[r]-'A']++;
            maxf = max(maxf,hash[s[r]-'A']);
            if((r-l+1)-maxf > k){
                hash[s[l]-'A']--;
                l++;
            }
            if((r-l+1)-maxf <= k){
                maxlen = max(maxlen,(r-l+1));
            }
            r++;
        }
        return maxlen;
    }
};