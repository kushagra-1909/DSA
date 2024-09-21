// Minimum Removals of interval such that no overlapping interval will be present in the array

// sort the arrray according to the end time then declare a variable called free time

int freeTime = arr[0].endTime;
int cnt = 1;
for(int i=1; i<n; i++){
    if(arr[i].startTime > freeTime){
        cnt++;
        freeTime = arr[i].endTime;
    }
}

return N-cnt;