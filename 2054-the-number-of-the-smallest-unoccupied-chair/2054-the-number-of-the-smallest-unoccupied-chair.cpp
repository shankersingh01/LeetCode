class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        vector<int> originalIndex(times.size());

        for (int i = 0; i < times.size(); ++i) {
            originalIndex[i] = i;
        }

        sort(originalIndex.begin(), originalIndex.end(),
             [&times](int a, int b) { return times[a][0] < times[b][0]; });

        priority_queue<int, vector<int>, greater<int>> emptySeats;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            occupiedSeats;

        for(int i=0; i<times.size(); ++i){
            emptySeats.push(i);
        }

        for (int i : originalIndex) {
            int arrivalTime = times[i][0];
            int leavingTime = times[i][1];

            while (!occupiedSeats.empty() &&
                   occupiedSeats.top().first <= arrivalTime) {
                emptySeats.push(occupiedSeats.top().second);
                occupiedSeats.pop();
            }

            int seat = emptySeats.top();
            emptySeats.pop();

            if (i == targetFriend)
                return seat;

            occupiedSeats.push({leavingTime, seat});
        }
        return -1;
    }
};