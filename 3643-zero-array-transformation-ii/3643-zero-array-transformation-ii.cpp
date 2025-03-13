class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> diff(nums.size() + 1, 0);
        int sum = 0, k = 0;

        for(int i=0; i<nums.size(); ++i){

            while(sum + diff[i] < nums[i]){
                if(k == queries.size()) return -1;
                int left = queries[k][0];
                int right = queries[k][1];
                int val = queries[k][2];
                k++;
                if(right < i) continue;
                diff[max(i,left)] += val;
                diff[right + 1] -= val;
            }
            sum += diff[i];
        }
        return k;
    }
};