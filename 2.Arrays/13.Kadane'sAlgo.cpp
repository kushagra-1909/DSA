// Maximum Subarray Sum 
// kadane's Algorithm

// if(sum < 0) we don't need to take this sum because it will reduce the sum only in future

int sum = 0;
int maxi = INT_MIN;
int ansStart = -1, ansEnd = -1;
for(int i=0; i<n; i++){
    // for printing the subarray
    if(sum == 0){
        start = i;
    }
    sum += arr[i];
    if(sum > maxi){
        maxi = sum;
        ansStart = start ;
        ansEnd = i;
    }
    if(sum < 0){
        sum = 0;
    }
}