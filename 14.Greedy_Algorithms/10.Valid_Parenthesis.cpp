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