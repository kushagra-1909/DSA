// A subarray is beautiful if sum of min and max elements of the subarray is divisible by the length of subarray
// constraints : 1 <= arr[i] <= 26

for(int i=0; i<n; i++){
    int mi = 27, ma = -1;
    for(int j=i; j<min(n,i+52); j++){
        mi = min(mi,arr[j]);
        ma = max(ma,arr[j]);

        if((mi + ma) % (j-i+1) == 0){
            ans++;
        }
    }
}
return ans;


