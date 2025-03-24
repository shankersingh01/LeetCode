class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {

        sort(meetings.begin(), meetings.end());
        int noMeetingCount = 0;
        int maxEnd = meetings[0][1];
        noMeetingCount += meetings[0][0] - 1;
        for (int i = 1; i < meetings.size(); ++i) {
            int start = meetings[i][0];
            int end = meetings[i][1];
            if (maxEnd - start < -1) {
                noMeetingCount += (start - maxEnd) - 1;
            }
            maxEnd = max(maxEnd, end);
        }
        if (maxEnd < days)
            noMeetingCount += days - maxEnd;
        return noMeetingCount;
    }
};