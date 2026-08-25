class Solution {
  public:
    int minCost(vector<int>& arr) {
        // code here
        priority_queue<
            int,                    //length
            vector<int>,            //vector type me storage
            greater<int>> mp;       //smallest wala Top m rahega
        for(int x : arr){
            mp.push(x);
        }
        int sum=0;
        while(mp.size()>1){           //size kab tak karenge jab tak 1 se jada elemenet rahe
            int first = mp.top();     //1st element lo
            mp.pop();                 //usko nikal do
            int second=mp.top();      //2nd element lo
            mp.pop();                 //usko nikal do
            int k = first + second;   //dono ka sum
            sum = sum + k;            //add
            mp.push(k);               //dal do min heap m
        }
        return sum;
    }
};