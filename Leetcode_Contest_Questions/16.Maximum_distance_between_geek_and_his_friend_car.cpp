// Brute Force method
int Maxdistance (int A[], int N)
    {
        int maxi = INT_MIN;
        for(int i=0; i<N; i++){
            // left traversal
            int j = i;
            int leftDist=0 , rightDist=0;
            while(j>0){
                if(A[j-1] >= A[j]){
                    leftDist++;
                    j--;
                }else{
                    break;
                }
            }
            // right traversal
            j = i;
            while(j<N-1){
                if(A[j+1] >= A[j]){
                    rightDist++;
                    j++;
                }
                else{
                    break;
                }
            }
            maxi = max(maxi,leftDist+rightDist);
        }
        
        return maxi;
    }

    // O(n)
    class Solution
{
    public:
    int Maxdistance (int arr[], int n)
    {
        int ind=0,maxi=0;
        while(ind<n){
            int left=ind;
            int right=ind;
            while(right+1<n && arr[right]<=arr[right+1]){
                right++;
            }
            while(left-1>=0 && arr[left]<=arr[left-1]){
                left--;
            }
            maxi=max(maxi,right-left);
            ind=right+1;
            // cout<<right-left-1<<endl;
        }
        return maxi;
    }
    
};