class Solution {
public:
    int numberOfSubstrings(string s) {
        unordered_map<char,int> threeCharMap;
        int subCount = 0;
        
        for(int i=0, j=0; i<s.size(); ++i){
            threeCharMap[s[i]]++;
            
            while(threeCharMap.size() >= 3){
                subCount += s.size() - i;
                threeCharMap[s[j]]--;
                if(threeCharMap[s[j]] == 0) threeCharMap.erase(s[j]);
                j++;
            }
        }
        return subCount;
    }
};