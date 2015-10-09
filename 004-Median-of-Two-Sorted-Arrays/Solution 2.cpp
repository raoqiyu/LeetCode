class Solution {
public:
    double findkth(vector<int>& arr1, vector<int>& arr2, int k)
    {
        int idx1, idx2;
        double target1,target2;
        int m = arr1.size(), n = arr2.size();
        vector<int>::iterator a = arr1.begin();
        vector<int>::iterator b = arr2.begin();
        while(k > 1 && m >0){
            idx1 = min(k/2,m); idx2 = k - idx1;
            target1 = a[idx1-1]; target2 = b[idx2-1]; 
            if(target1 < target2){
                k -= idx1; m -= idx1; 
                a += idx1;
            }else if (target1 > target2){
                k -= idx2; n -= idx2; 
                b += idx2;
            }else
                return target1;
            if(m > n){
                int temp1 = n; n = m; m = temp1;
                vector<int>::iterator temp2 = b; b = a; a = temp2;
            }
        }
        if(m == 0)
            return b[k-1];
        return min(a[0], b[0]);
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    /*  Basic Ideal: Compare the medians of two arrays to discard most half numbers of the two arrays
        Base case: odd and even cases
                    The smaller array only has 1 or 2 elements
                    So, we need to konw which one is the smaller array in advance
        Iterative Solution: Find the k-th element in two arrays.
    */
        // arr1: the smaller array
        vector<int> arr1, arr2;
        if(nums1.size() <= nums2.size() ){
            arr1 = nums1; arr2 = nums2;
        }else{
            arr1 = nums2; arr2 = nums1;
        }

        // If the smaller array is empty, return the median of the larger array
        int N = arr1.size(), M=arr2.size();
        if( N == 0)
            if( M & 1)
                return arr2[M/2];
            else
                return (arr2[M/2-1]+arr2[M/2])/2.0;
        // Iterative implementation: Find the k-th element in two arrays.
        int totalSize = N+M ;
        // 
        if (totalSize & 1)
            return findkth(arr1, arr2, totalSize/2+1);
        else
            return (findkth(arr1, arr2, totalSize/2) +
                    findkth(arr1, arr2, totalSize/2+1)
                    )/2.0;
    }
};
