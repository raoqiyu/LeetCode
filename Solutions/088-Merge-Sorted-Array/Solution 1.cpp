class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Two pointers
        int ptr1 = 0, ptr2 = 0;
        while(ptr1 < m && ptr2 < n){
            if(nums1[ptr1] < nums2[ptr2] ){
                ptr1++;
            }else{
                m++;
                for(int k = m-1; k > ptr1; k--)
                    nums1[k] = nums1[k-1];
                nums1[ptr1++] = nums2[ptr2++];
            }
        }
        while(ptr2 < n)
            nums1[ptr1++] = nums2[ptr2++];

    }
};
