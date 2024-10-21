class Solution {
public:

    int backtrack(int start, const string &s, unordered_set<string> &uniqueSubstr){
        if(start == s.size()) return 0;
        int uniqueSubstrCount = 0;

        for(int end=start+1; end<=s.size(); ++end){
            string uniqueSub = s.substr(start, end-start);
            if(uniqueSubstr.find(uniqueSub)== uniqueSubstr.end()){
                uniqueSubstr.insert(uniqueSub);
                uniqueSubstrCount = max(uniqueSubstrCount, 1 + backtrack(end, s, uniqueSubstr));
                uniqueSubstr.erase(uniqueSub);
            }
        }
        return uniqueSubstrCount;
    }

    int maxUniqueSplit(string s) {
        unordered_set<string> uniqueSubstr;
        return backtrack(0, s, uniqueSubstr);
    }
};