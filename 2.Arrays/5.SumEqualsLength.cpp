// find the length of longest subarray such that sum of all elements of subarray is equal to the length of subarray

unordered_map<int,int>mpp; // sum -> index
int sum = 0;
int len = 0;
mpp[0] = -1;
for(int i=0; i<n; i++){
    sum += arr[i];

    if(sum == i+1){
        len = max(len,i+1);
    }

    int rem = sum-(i+1);

    if(mpp.find(rem) != mpp.end()){
        len = max(len,i-m[rem]);
    }

    mpp[rem] = i;
}

if(len != 0){
    return len;
}
return -1;