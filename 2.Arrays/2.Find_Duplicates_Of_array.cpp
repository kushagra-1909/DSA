// O(N) approach for finding duplicates in array
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int size = nums.size();
        vector<int>ans;
        for(int i=0; i<size; i++){
            int el = abs(nums[i]);
            if(nums[el-1] < 0){
                ans.push_back(el);
            }
            nums[el-1] = - nums[el-1];
        }
        return ans;
    }
};