class Solution {
  public:
  
    struct data{
      int profit;
      int deadline;
      int index;
    };
  
  
    static bool compare(const data&a,const data&b){
        return a.profit > b.profit;
    }
  
  
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        int n = deadline.size();
        int maxdeadline=-1;
        for(int x : deadline){
            maxdeadline=max(maxdeadline,x);
        }
        vector<int> answer;
        int max_profit=0,count=0;
        vector<int>total(maxdeadline+1,-1);
        vector<data>datas(n);
        for(int i=0;i<n;i++){
            datas[i].profit=profit[i];
            datas[i].deadline=deadline[i];
            datas[i].index=i+1;
        }
        sort(datas.begin(),datas.end(),compare);
        for(int i=0;i<n;i++){      //datas m traverse karne ke liye
                                   // {profit,deadline,index}
            for(int j=datas[i].deadline;j>=1;j--){     //abb filling time
            if(total[j]==-1){
                total[j]=datas[i].index;
                max_profit+=datas[i].profit;
                count++;
                break;
                }
            }  
        }
        answer.push_back(count);
        answer.push_back(max_profit);
        return answer;
    }
};



//issue is time complexity(N^2) but code is correct.