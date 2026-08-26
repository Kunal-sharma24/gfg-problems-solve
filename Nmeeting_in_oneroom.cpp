class Solution {
  public:
    struct Item{
        int order;
        int saar;
        int faar;
    };
    
    static bool compare(const Item&a,const Item&b){
        return a.faar < b.faar;
    }
    
    vector<int> maxMeetings(vector<int> &s, vector<int> &f) {
        // code here
        int n = s.size();
        vector<Item> items(n);
        for(int i=0;i<n;i++){
            items[i].order=i+1;
            items[i].saar=s[i];
            items[i].faar=f[i];
        }
        sort(items.begin(),items.end(),compare);  //yaha tak sorted ha
        vector<int> result;
        int end_time=0;
        for(int i=0;i<n;i++){
            if(items[i].saar>end_time){
                result.push_back(items[i].order);
                end_time=items[i].faar;
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};