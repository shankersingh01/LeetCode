class Solution {
public:
    int convertToMin(string time) {
        int hours = stoi(time.substr(0, 2));
        int mins = stoi(time.substr(3, 2));
        return hours * 60 + mins;
    }

    int findMinDifference(vector<string>& timePoints) {
        vector<int> timeInMins;

        for (const string& time : timePoints) {
            timeInMins.push_back(convertToMin(time));
        }

        sort(timeInMins.begin(), timeInMins.end());

        int minDiff = INT_MAX;
        int totalMinsInDay = 24 * 60;

        for (int i = 1; i < timeInMins.size(); ++i) {
            minDiff = min(minDiff, timeInMins[i] - timeInMins[i - 1]);
        }

        int circularDiff =
            (totalMinsInDay + timeInMins[0] - timeInMins.back()) %
            totalMinsInDay;

        minDiff = min(minDiff, circularDiff);

        return minDiff;
    }
};