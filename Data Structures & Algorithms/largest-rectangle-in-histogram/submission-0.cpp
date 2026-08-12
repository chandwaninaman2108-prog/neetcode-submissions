class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int maxel=*max_element(heights.begin(),heights.end());
        int maxarea=maxel;
        for(int i=1;i<=maxel;i++){
            int width=0,maxwidth=0;
            for(int j=0;j<n;j++){
                if(heights[j]>=i){width+=1;}else{width=0;}
                maxwidth=max(width,maxwidth);
            }
            maxarea=max(maxwidth*i,maxarea);
        }
        return maxarea;
    }
};
