class Solution {
  public:
    struct Item{
        double ratio;
        int val;
        int wt;
    };                        //blueprint of the data
    static bool compare(const Item&a , const Item&b){
            return a.ratio > b.ratio;
        }
    
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        double ans=0;
        int n = val.size();
        vector<Item> items;       //items where data is being stored in the 
                                 //form of Item Struct.
        for(int i=0;i<n;i++){
            items.push_back({
                (double)val[i]/wt[i],
                val[i],
                wt[i]
            });
        }
        
        sort(items.begin(),items.end(),compare);
        
        for(int i=0;i<n;i++){
            if(items[i].wt<=capacity){
                ans = ans + items[i].val;    //ye sab ko items[i] ke saath use karna ha
                capacity-=items[i].wt;       //cz they all are sorted
            }else{
                ans = ans + ((double)capacity*items[i].val)/items[i].wt;
                break;
            }
        }
        return ans;
        
    }
};
