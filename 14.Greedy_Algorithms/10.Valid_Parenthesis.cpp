int f(s,ind,cnt){
    if(cnt < 0){
        return false;
    }
    if(ind == n){
        return cnt == 0;
    }

    if(s[ind] == '('){
        return f(s,ind+1,cnt+1);
    }

    if(s[ind] == ')'){
        return f(s,ind+1,cnt-1);
    }

    return (f(s,ind+1,cnt+1) | f(s,ind+1,cnt-1) | f(s,ind+1,cnt));
}


// optimal approach
fun(s){
    min = 0, max=0;
    for(int i=0; i<N; i++){
        if(s[i] == '('){
            min++;
            max++;
        }
        else if(s[i] == ')'){
            min = min-1;
            max = max-1;   
        }
        else{
            min = min-1;
            max = max+1
        }

        if(min < 0) min = 0;
        if(max < 0) return false;
    }

    return (min==0);
}