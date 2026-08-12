class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temp) {
        int n=temp.size();
        vector<int> ans(n);
        stack<int> c;
        for(int i=0;i<n;i++){
            while(!c.empty() && temp[i]>temp[c.top()]){
                int idx=c.top();
                ans[idx]=i-idx;
                c.pop();
            }
            c.push(i);
        }
        return ans;
    }
};
