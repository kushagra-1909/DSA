vector<int> rearrangeArray(vector<int>& nums){
    int n = nums.size();
    vector<int> ans(n ,0);
    int poslndex = 0, neglndex = 1;
    for(int i=0; i<n; i++){
        if(nums[i] < 0){
            ans[negIndex] = nums[i];
        }
    }
    return ans;
}
