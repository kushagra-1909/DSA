// sort the arrray according to the end time then declare a variable called free time

int freeTime = arr[0].endTime;
int cnt = 1;
for(int i=1; i<n; i++){
    if(arr[i].startTime > freeTime){
        cnt++;
        freeTime = arr[i].endTime;
    }
}

return cnt;