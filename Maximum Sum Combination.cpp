class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        int n = a.size();
        
        //vector ans declare
        vector<int> ans;
        
        //sort
        sort(a.begin(),a.end(),greater<int>());
        sort(b.begin(),b.end(),greater<int>());
        
        //max heap and visited
        priority_queue<tuple<int,int,int>> pq;
        set<pair<int,int>> visited;
        
        pq.push({a[0]+b[0],0,0});
        visited.insert({0,0});
        while(k>0){
            auto [sum,i,j]=pq.top();
            pq.pop();
            ans.push_back(sum);
            k--;
            
            if(i+1<n && !visited.count({i+1,j})){
                pq.push({a[i+1]+b[j],i+1,j});
                visited.insert({i+1,j});
            }
            
            if(j+1<n && !visited.count({i,j+1})){
                pq.push({a[i]+b[j+1],i,j+1});
                visited.insert({i,j+1});
            }
        }
        return ans;
    }
};