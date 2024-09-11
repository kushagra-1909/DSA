// Brute force approach
class Solution{   
  public:
    vector<int> farNumber(int N,vector<int> Arr){
        vector<int>ans;
        for(int i=0; i<N; i++){
            int fl = 0;
            for(int j=N-1; j>i; j--){
                if(Arr[j] < Arr[i]){
                    ans.push_back(j);
                    fl = 1;
                    break;
                }
            }
            if(fl == 0){
                ans.push_back(-1);
            }
        }
        return ans;
    }
};

// O(NlogN) approach
// first create a suffix array which contains min elements from right side and then apply binary search from index (i+1) to N-1


