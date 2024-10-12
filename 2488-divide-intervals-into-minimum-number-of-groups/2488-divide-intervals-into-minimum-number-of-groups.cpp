class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> startInterval;
        vector<int> endInterval;

        for(const auto& interval : intervals){
            startInterval.push_back(interval[0]);
            endInterval.push_back(interval[1]);
        }

        sort(startInterval.begin(), startInterval.end());
        sort(endInterval.begin(), endInterval.end());

        int start = 0, end = 0;
        int count = 0, groupCount=0;
        while(start < startInterval.size()){
            if(startInterval[start]<=endInterval[end]){
                start++;
                count++;
            }
            else{
                end++;
                count--;
            }
            groupCount = max(groupCount, count);
        }
        return groupCount;
    }
};