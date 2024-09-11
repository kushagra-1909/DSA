int i=0;
int j = n-1;
sort(arr.begin(),arr.end());
vector<pair<int,int>>ans;
while(i<j){
    sum = arr[i] + arr[j];
    if(sum > target){
        j--;
    }
    else if(sum < target){
        i++;
    }
    else{
        ans.push_back({arr[i],arr[j]});
    }
    return ans; 
}