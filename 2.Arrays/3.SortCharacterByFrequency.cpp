class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int>count;
        unordered_map<int,vector<char>>bucket;

        for(int i=0; i<s.size(); i++){
            count[s[i]]++;
        }

        for(auto pair : count){
            char charValue = pair.first;
            int cnt = pair.second;
            bucket[cnt].push_back(charValue);
        }

        string res = "";
        for(int i=s.size(); i>0; i--){
            if(bucket.find(i) != bucket.end()){
                for(auto c : bucket[i]){
                    res.append(i,c);
                }
            }
        }
        return res;
    }
};