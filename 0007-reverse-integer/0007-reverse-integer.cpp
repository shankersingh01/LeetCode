class Solution {
public:
    int reverse(int x) {
        int Maxi = INT32_MAX;
        int Mini = INT32_MIN;
        
        int revnum=0;
        while(x!=0){
            int lastd = x%10;
            if(revnum > Maxi/10 || (revnum == Maxi/10 && lastd>7)){
                return 0;
            }
            if(revnum < Mini/10 || (revnum == Mini/10 && lastd<-8)){
                return 0;
            }
            revnum = (revnum*10)+lastd;
            x=x/10;
        }
            return revnum;
    }
};