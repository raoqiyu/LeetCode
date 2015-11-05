class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // Scan the array with two pointers
        // ptr1 : the current position which's value is val
        // ptr2 : the first position after ptr1 which's value is not val 
        int ptr1 = 0, ptr2 = 0, cnt = 0;
        for(int i = 0; i < nums.size(); i++){
            if( nums[i] ==  val)
                ptr2++;
            else{
                nums[ptr1] = nums[ptr2];
                ptr1++;ptr2++;cnt++;
            }
        }
        return cnt;
    }
};
