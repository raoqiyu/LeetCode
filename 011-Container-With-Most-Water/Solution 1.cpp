class Solution {
public:
    int maxArea(vector<int>& height) {
        auto start = height.begin();
        auto end = height.end();
        end--;
        int maxVal = 0;
        while(start != end){
            maxVal = max(maxVal, (int)(end - start)*min(*start, *end));
            if(*start < *end)
                start++;
            else
                end--;
        }
        return maxVal;
    }
};
