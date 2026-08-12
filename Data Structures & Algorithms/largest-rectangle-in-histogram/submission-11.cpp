class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int> c;
        int maxarea=0;
        for(int i=0;i<n;i++){
            while(!c.empty() && heights[i]<heights[c.top()]){
                int h=heights[c.top()];
                c.pop();
                int left_bound=c.empty()? -1:c.top();
                int right_bound=i;
                int width=right_bound-left_bound-1;
                maxarea=max(maxarea,width*h);
            }
            c.push(i);
        }
        while(!c.empty()){
            int h=heights[c.top()];
            c.pop();
            int lb=c.empty()? -1:c.top();
            int rb=n;
            int width=rb-lb-1;
            maxarea=max(maxarea,width*h);
        }
        return maxarea;
    }
};
