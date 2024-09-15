// A special compression mechanism can arbitrarily delete 0 or more characters and replace
// them with the deleted character count.
// Given two strings, S and T where S is a normal string and T is a
// compressed string, determine if the compressed string T is valid for the plaintext string S.
// Example 1:
// Input:
// S = "GEEKSFORGEEKS"
// T = "G7G3S"
// Output:
// 1
// Explanation:
// We can clearly see that T is a valid
// compressed string for S.


int checkCompressed(string S, string T) {
        int num=0, j=0;
        for(int i=0; i<T.size(); i++){
            if(isdigit(T[i])){
                num = num*10 + (T[i]-'0');
            }
            else{
                if(num){
                    j += num;
                }
                num = 0;
                if(j>=S.size() || S[j] != T[i]) return 0;
                j++;
            }
        }
        j += num;
        if(j != S.size()) return 0;
        return 1;
    }