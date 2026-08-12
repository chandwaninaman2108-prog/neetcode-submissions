class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxarea=0,right=heights.size()-1,left=0;
        while(left<right){
            int area=(right-left)*min(heights[right],heights[left]);
            maxarea=max(area,maxarea);
            int diff=heights[left]-heights[right];
            diff<0 ? left++ : right--;
        }
        return maxarea;
    }
};
