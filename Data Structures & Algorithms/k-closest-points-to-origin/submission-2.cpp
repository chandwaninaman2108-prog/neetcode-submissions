class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,vector<int>>> pq;
        // Note that pairs and cpp vectors feature lexicographic comparison which elimnates the need to declare a custom comparator.
        vector<vector<int>> ans;
        for(int i=0;i<points.size();i++){
            int dist=points[i][0]*points[i][0]+points[i][1]*points[i][1];
            pq.push({dist,points[i]});
            if(pq.size()>k){pq.pop();}
        }
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;

    }
};
