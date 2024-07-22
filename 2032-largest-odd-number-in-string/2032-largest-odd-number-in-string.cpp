class Solution {
public:
    string largestOddNumber(string num) {
        
        int n=num.size();
        
        while(n>0){
            if((num.back()-'0')%2==1){
                return num;
            }
            else{
                num.pop_back();
                n--;
            }
        }
        return "";
    }
};