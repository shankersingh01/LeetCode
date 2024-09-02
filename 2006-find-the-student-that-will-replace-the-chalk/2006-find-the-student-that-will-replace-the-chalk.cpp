class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long long totalChalkUsed = 0;
        
        for(int chalkReq : chalk){
            totalChalkUsed+=chalkReq;
        }
        int remChalk = k % totalChalkUsed;

        for(int i=0; i<chalk.size(); ++i){
            if(remChalk < chalk[i]){
                return i;
            }
            remChalk-=chalk[i];
        }
        return 0;
    }
};