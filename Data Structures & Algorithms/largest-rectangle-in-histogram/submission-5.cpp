class Solution {
public:
// solution with stacks
    int largestRectangleArea(vector<int>& heights) {
        int max_area=0;
        int n=heights.size();
        stack<int> c;
        for(int i=0;i<n;i++){
            while(!c.empty() && heights[i]<heights[c.top()]){
                int h=heights[c.top()];
                c.pop();
                int right_bound=i;
                int left_bound= c.empty()? -1 : c.top();
                int width=right_bound-left_bound-1;
                max_area=max(max_area,width*h);
            }
            c.push(i);
        }
        while(!c.empty()){
            int h=heights[c.top()];
            c.pop();
            int left_bound=c.empty()? -1:c.top();
            int right_bound=n;
            int width=right_bound-left_bound-1;
            max_area=max(max_area,width*h);

        }
        return max_area;
    }
};
