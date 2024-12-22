class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> temp(nums1.begin(), nums1.end()-n);
        
        int ptr1 = 0, ptr2 = 0, i=0;

        while(ptr1<m && ptr2<n){
            if(temp[ptr1] <= nums2[ptr2]){
                nums1[i++] = temp[ptr1++];
            }else{
                nums1[i++] = nums2[ptr2++];
            }
        }
        if(ptr1 < m){
            while(ptr1 < m){
                nums1[i++] = temp[ptr1++];
            }
        }
        else{
            while(ptr2 < n){
                nums1[i++] = nums2[ptr2++];
            }
        }
    }
};