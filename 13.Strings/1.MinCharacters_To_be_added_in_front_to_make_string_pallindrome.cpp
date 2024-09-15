// Given a string str, find the minimum characters to be added at front of the string to make it a palindrome.
// Example 1:
// Input:
// str = ABCD
// Output: 3
// Explanation: The resultant string
// after adding 3 characters is DCBABCD.
// The minimum possible answer is 3.
// Example 2:
// Input:
// str = ABA
// Output: O

int addMinChar(string str){    
    int i=0, j=str.size()-1;
    int trim = j, res=0;

    while(i<j){
        if(s[i] == s[j]){
            i++;
            j--;
        }
        else{
            res++;
            i=0;
            j=trim-1;
            trim = j;
        }
    }
    
    return res;
}

