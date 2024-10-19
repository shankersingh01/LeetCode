class Solution {
public:
    string invertBinary(const string& binary) {
        string invert;

        for (char c : binary) {
            if (c == '0') {
                invert += '1';
            } else if(c=='1'){
                invert += '0';
            }
        }
        return invert;
    }

    char findKthBit(int n, int k) {

        string binary = "0";
        for (int i = 1; i < n; ++i) {
            string invert = invertBinary(binary);
            reverse(invert.begin(), invert.end());
            binary += '1' + invert;
        }
        return binary[k - 1];
    }
};