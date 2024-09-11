// N Students of different heights are attending an assembly. The heights of the students are
// represented by an array HI]. The problem is that if a student has less or equal height than
// the student standing in front of him, then he/she cannot see the assembly. Find the minimum
// number of students to be removed such that maximum possible number of students can see
// the assembly.
// Example 1:
// Input:
// Output:
// 2
// Explanation:
// We can remove the
// students at 0 and 4th index.
// which will leave the students with heights
// and 5.


// remove minimum no of elements to make maximum number of elements of array sorted.
class Solution {
  public:
    int binarySearch(vector<int>&ans, int val, int size){
        int low = 0, high = size-1, index;
        while(low <= high){
            int mid = (low+high)/2;
            if(ans[mid] == val) return mid;
            else if(ans[mid] > val){
                index = mid;
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return index;
    }
    int removeStudents(int H[], int N) {
        vector<int>ans;
        ans.push_back(H[0]);
        int size;
        size = 1;
        for(int i=1; i<N; i++){
            if(H[i] > ans[size-1]){
                ans.push_back(H[i]);
                size++;
            }
            else{
                int index = binarySearch(ans,H[i],size);
                ans[index] = H[i];
            }
        }
        return N-size;
    }
};