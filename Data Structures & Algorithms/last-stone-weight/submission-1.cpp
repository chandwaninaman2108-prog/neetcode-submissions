class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        int ans=0;
        for(int x: stones){
            pq.push(x);
        }
        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();
            if(a!=b){pq.push(a-b);}
        }
        ans=pq.empty()?0:pq.top();
        return ans;

    }
};
