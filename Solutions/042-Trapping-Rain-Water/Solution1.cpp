class Solution {
public:
    int trap(vector<int>& height) {
        // Two pointers
        
        // for each bar9height[i]) in map, 
        // how much water it can contain depends on height[i] and the largest value before (left) and after height[i]) (right)
        // area i = min(left, right) - height[i] (second largest value - height[i])
        // So, we use two pointers to scan the map, one scan from left to right, one scan from right to left.
        // At each step:
        //     Update the second larget value(second) up to now;  
        //     Calculate arear i = second - height[i];
        //     Update the smaller one.
        
        int left = 0, right = height.size()-1, second= 0;
        int area = 0;
        while(left < right){
            if(height[left] < height[right]){
                second = max(second, height[left]);
                area += second - height[left];
                left++;
            }else{
                second = max(second, height[right]);
                area += second - height[right];
                right--;
            }
        }
        return area;
    }
};
