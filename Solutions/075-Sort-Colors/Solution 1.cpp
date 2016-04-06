class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Three Pointers
        int n = nums.size();
        // ptr0 : the rightmost index of 0
        // ptr1 : the rightmost index of 1
        // ptr2 : the leftmost  index of 2
        int ptr0 = -1, ptr1 = 0, ptr2 = n;
        
        while(ptr1 != ptr2){
            if(nums[ptr1] == 1)
                ptr1++;
            else if(nums[ptr1] == 2){
                swap(nums[ptr1], nums[--ptr2]);
            }else
                swap(nums[++ptr0], nums[ptr1++]);
        }
    }
private:
    void swap(int& x, int& y){
        int temp = x;
        x = y;
        y = temp;
    }
};
