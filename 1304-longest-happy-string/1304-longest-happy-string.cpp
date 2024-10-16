class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxHeap;
        maxHeap.push({a, 'a'});
        maxHeap.push({b, 'b'});
        maxHeap.push({c, 'c'});

        string result = "";

        while (maxHeap.top().first > 0) {
            auto [freq1, char1] = maxHeap.top();
            maxHeap.pop();

            if (result.size() >= 2 && result[result.size() - 1] == char1 &&
                result[result.size() - 2] == char1) {
                if (maxHeap.empty())
                    break;

                auto [freq2, char2] = maxHeap.top();
                maxHeap.pop();
                if(freq2 > 0){
                    result += char2;
                    freq2--;
                    maxHeap.push({freq2, char2});
                    maxHeap.push({freq1, char1});
                }
            } else {
                if(freq1 > 0){
                    result += char1;
                    freq1--;
                    maxHeap.push({freq1, char1});
                }
            }
        }
        return result;
    }
};