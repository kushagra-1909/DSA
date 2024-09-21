// There are N jobs and the start and finish time of the jobs are given in arrays start[] and end[]
// respectively. Each job requires one laptop and laptops can't be shared. Find the minimum
// number of laptops required given that you can give your laptop to someone else when you
// are not doing your job.
// Example 1:
// Input:
// start[]
// end[] = {4, 4, 6}
// Output:
// 3
// Explanation:
// We can clearly see that everyone's supposed to
// be doing their job at time 3. So, 3 laptops
// will be required at minimum.

class Solution {
  public:
    int minLaptops(int N, int start[], int end[]) {
        sort(start,start+N);
        sort(end,end+N);
        int ans=1, occu=1, i=1, j=0;
        while(i<N && j<N){
            if(start[i] >= end[j]){
                occu--;
                j++;
            }else{
                occu++;
                i++;
            }
            ans = max(ans,occu);
        }
        return ans;
    }
}; 