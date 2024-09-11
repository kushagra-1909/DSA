// return element which appear more than N/2 in an array
// Brute force solution

vector<int>ans;
for(int i=0; i<n; i++){
    int cnt = 0;
    for(int j=0; j<n; j++){
        if(arr[i] == arr[j]){
            cnt ++;
        }
    }
    if(cnt > N/2){
        ans.push_back(arr[i]);
    }
}

// using hashing

unordered_map<int,int>mpp; // el->cnt
for(int i=0; i<n; i++){
    mpp[arr[i]]++;
}

for(auto it : mpp){
    int el = it.first;
    int cnt = it.second;

    if(cnt > N/2){
        ans.push_back(el);
        break;
    }
}
return ans;

// Moore's Voting Algorithm

int cnt = 0, el;
for(int i=0; i<n; i++){
    if(cnt == 0){
        // starting a new section of array
        cnt = 1;
        el = arr[i];
    }
    else if(arr[i] == el){
        cnt++;
    }else{
        cnt--;
    }
}

int cnt1 = 0;
for(int i=0; i<n; i++){
    if(arr[i] == el){
        cnt1++;
    }
}
if(cnt1 > N/2){
    return el;
}
return -1;
