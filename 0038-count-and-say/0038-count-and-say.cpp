class Solution {
public:
    string helper(int n, string& compress){
        if(n == 1){
            return compress;
        }

        helper(n-1, compress);
        int count = 1;
        string compressCpy = "";
        for(int i=1; i<compress.size(); ++i){
            if(compress[i-1] == compress[i]){
                count++;
            }
            else {
                compressCpy += to_string(count) + compress[i-1];
                count = 1;
            }
        }
        compressCpy += to_string(count) + compress[compress.size() - 1];
        return compress = compressCpy;
    }

    string countAndSay(int n) {
        string s = "1"; 
        return helper(n, s);    
    }
};
