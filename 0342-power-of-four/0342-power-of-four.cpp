class Solution {
public:
    bool isPowerOfFour(int n) {
        //using loops
        if(n < 0 ) return false;
        for(int i=0; i<=16; ++i){
            if(n == pow(4, i)){
                return true;
            }
        }
        return false;
    }
};