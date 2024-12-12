class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        long long totalRemGifts = 0;

        priority_queue<int> pq(gifts.begin(), gifts.end());

        for (int i = 1; i <= k; ++i) {
            int remGifts = floor(sqrt(pq.top()));
            pq.pop();
            pq.push(remGifts);
        }
        
        while (!pq.empty()) {
            totalRemGifts += pq.top();
            pq.pop();
        }
        return totalRemGifts;
    }
};