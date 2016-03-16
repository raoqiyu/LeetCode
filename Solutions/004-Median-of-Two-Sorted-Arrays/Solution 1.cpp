class Solution {
public:
    // Calculate midean of two numbers
    inline double Median_2(int a, int b){
        return (a+b)/2.0;
    }
    // Calculate midean of three numbers
    inline double Median_3(int a, int b, int c){
        return a+b+c - max(a, max(b,c)) - min(a, min(b,c));
    }
    // Calculate midean of four numbers
    inline double Median_4(int a, int b, int c, int d){
        int max_one = max(a, max(b, max(c, d)));
        int min_one = min(a, min(b, min(c, d)));
        return (a+b+c+d - max_one - min_one)/2.0;
    }
    
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    /*  Basic Ideal: Compare the medians of two arrays to discard most half numbers of the two arrays
        Base case: odd and even cases
                    The smaller array only has 1 or 2 elements
                    So, we need to konw which one is the smaller array in advance
                    Use a util function.
        Recursive Solution: To simplify the problem to the base cases.
    */
        // arr1: the smaller array
        vector<int> arr1, arr2;
        if(nums1.size() <= nums2.size() ){
            arr1 = nums1; arr2 = nums2;
        }else{
            arr1 = nums2; arr2 = nums1;
        }
        double median1, median2;
        int begin1 = 0, end1 = arr1.size() - 1;
        int begin2 = 0, end2 = arr2.size() - 1;
        int N, N_mid, M, M_mid;
        
        N = end1 - begin1 + 1; N_mid = (end1 + begin1)/2;
        M = end2 - begin2 + 1; M_mid = (end2 + begin2)/2;
        // If the smaller array is empty, return the median of the larger array
        if( N == 0)
            if( M & 1)
                return arr2[M/2];
            else
                return Median_2(arr2[M/2-1], arr2[M/2]);
        // Iterative implementation: Simplify the problem to the base case.
        while(N > 2){
            // N : size of arr1;  M size of arr2
            median1 = arr1[N_mid];
            median2 = arr2[M_mid];
            // The median exists in arr1[N_mid...] and B[....M_mid]
            if(median1 <= median2){
                end2 -= (N_mid - begin1);
                begin1 = N_mid;
            }else{// The median exists in arr1[...N_mid] and B[M_mid...]
                begin2 += (N_mid - begin1);
                end1 = begin1 + N/2;               
            }
            N = end1 - begin1 + 1; N_mid = (end1 + begin1)/2;
            M = end2 - begin2 + 1; M_mid = (end2 + begin2)/2;
        }
        // Solve the base cases
        if( N == 1){
            // Case 1: N==1, M == 1
            if( M == 1)
                return (arr1[begin1] + arr2[begin2])/2.0;
            // Case 2: N==1, M : odd
            if( M & 1)
                return Median_2(arr2[M_mid], Median_3(arr1[N_mid], arr2[M_mid-1], arr2[M_mid+1]));
            // Case 3: N==1, M : even
            return Median_3(arr1[N_mid], arr2[M_mid], arr2[M_mid+1]);
        }else if( N==2 ){
            // Case 4: N==2, M==2
            if(M==2)
                return Median_4(arr1[begin1], arr1[end1], arr2[begin2], arr2[end2]);
            // Case 5: N==2, M : odd
            if(M & 1)
                return Median_3(arr2[M_mid], max(arr1[begin1], arr2[M_mid-1]), min(arr1[end1], arr2[M_mid+1]));
            // case 6: N==2, M : even
            return Median_4(max(arr1[begin1], arr2[M_mid-1]), min(arr1[end1], arr2[M_mid+2]), arr2[M_mid], arr2[M_mid+1]);
        }
    }
};
