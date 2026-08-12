class MinStack {
private:
    vector<pair<int,int>> v;
public:
    MinStack() {
        
    }
    
    void push(int val) {
        int Currmin=v.empty()? val: min(val,v.back().second);
        v.push_back({val,Currmin});
    }
    
    void pop() {
        v.pop_back();
    }
    
    int top() {
        return v[v.size()-1].first;
    }
    
    int getMin() {
        return v[v.size()-1].second;
    }
};
