class Solution {
public:
    int numRabbits(vector<int>& answers) {
        vector<int> freq(1000);

        for (int num : answers) {
            freq[num]++;
        }
        int count = 0;
        for (int i = 0; i < freq.size(); ++i) {
            if (freq[i] == 0)
                continue;
            int div = 0;
            div = ceil((double)freq[i] / (i + 1));
            count += div * (i + 1);
        }
        return count;
    }
};