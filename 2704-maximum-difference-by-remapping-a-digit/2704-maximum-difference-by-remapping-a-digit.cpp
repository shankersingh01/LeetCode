class Solution {
public:
    int minMaxDifference(int num) {
        string val = to_string(num);
        char valToMap = '#';
        for (int i = 0; i < val.size(); ++i) {
            if (valToMap == '#' && val[i] != '9') {
                valToMap = val[i];
            }
            if (val[i] == valToMap) {
                val[i] = '9';
            }
        }
        int maxVal = stoi(val);
        val = to_string(num);

        valToMap = val[0];
        for (int i = 0; i < val.size(); ++i) {
            if (val[i] == valToMap) {
                val[i] = '0';
            }
        }
        int minVal = stoi(val);
        return maxVal - minVal;
    }
};