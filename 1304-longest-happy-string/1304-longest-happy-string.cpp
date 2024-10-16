class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxHeap;
        if (a > 0)
            maxHeap.push({a, 'a'});
        if (b > 0)
            maxHeap.push({b, 'b'});
        if (c > 0)
            maxHeap.push({c, 'c'});

        string result = "";

        while (!maxHeap.empty()) {
            auto [freq1, char1] = maxHeap.top();
            maxHeap.pop();

            if (result.size() >= 2 && result[result.size() - 1] == char1 &&
                result[result.size() - 2] == char1) {
                if (maxHeap.empty())
                    break;

                auto [freq2, char2] = maxHeap.top();
                maxHeap.pop();

                result += char2;
                freq2--;
                if (freq2 > 0)
                    maxHeap.push({freq2, char2});
                maxHeap.push({freq1, char1});

            } else {

                result += char1;
                freq1--;
                if (freq1 > 0)
                    maxHeap.push({freq1, char1});
            }
        }
        return result;
    }
};