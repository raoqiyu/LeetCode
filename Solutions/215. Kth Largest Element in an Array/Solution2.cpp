class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // QuickSort, but when we meet the Kth largest number, we stop
        unsigned seed = 1;
        shuffle (nums.begin(), nums.end(), std::default_random_engine(seed));
        return findK(nums, nums.size()-k, 0, nums.size()-1);
    }
private:
    int findK(vector<int>& nums, int k, int i, int j){
        if(i >= j)   return nums[i];
        
        int mid = partition(nums, i, j);
        if(mid == k)
            return nums[mid];
        else if(mid < k)
            return findK(nums, k, mid+1, j);
        else
            return findK(nums, k, i, mid-1);
    }
    
    int partition(vector<int>& nums, int i, int j){
        int val = nums[j];
        int end1 = i, begin2 = i;
    
        while(begin2 <= j){
            if(nums[begin2] < val){
                swap(nums, end1++, begin2);
            }
            begin2++;
                
        }
        swap(nums, j, end1);
        return end1;
    }
    void swap(vector<int> &nums, int i, int j){
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }
};
