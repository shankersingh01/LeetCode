class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }
        vector<int> result;
        priority_queue<pair<int, int>> pq;

        for (auto it : freq) {
            pq.push(make_pair(it.second, it.first));
        };

        while (k--) {
            result.push_back(pq.top().second);
            pq.pop();
        }
        return result;
    }
};