class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        vector<int> result(nums.begin(), nums.end());
        
        for(int i=0; i<nums.size(); ++i){
            pq.push({nums[i], i});
        }

        while(k--){
            int minEleIdx = pq.top().second;
            result[minEleIdx] *= multiplier;
            pq.pop();
            pq.push({result[minEleIdx], minEleIdx});
        }
        return result;
    }
};