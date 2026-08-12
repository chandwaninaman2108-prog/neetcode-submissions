class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size(),maxarea=0;
        stack<int> c;
        for(int i=0;i<n;i++){
            while(!c.empty() && heights[i]<heights[c.top()]){
                int h=heights[c.top()];
                c.pop();
                int left_bound=c.empty()? -1:c.top();
                int right_bound=i;
                int width=right_bound-left_bound-1;
                maxarea=max(width*h,maxarea);
            }
            c.push(i);
        }
        while(!c.empty()){
            int h=heights[c.top()];
            c.pop();
            int left_bound=c.empty()? -1:c.top();
            int right_bound=n;
            int width=right_bound-left_bound-1;
            maxarea=max(maxarea,width*h);
        }
        return maxarea;
    }
};
