class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> pq;
        vector<vector<int>> ans;
        for(int i=0;i<points.size();i++){
            int dist=0;
            for(int j=0;j<2;j++){
                dist+=(points[i][j]*points[i][j]);
            }
            pq.push({dist,points[i]});
            if(pq.size()>k) pq.pop();
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};
