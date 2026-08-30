class Solution{
    public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        //your code goes here
        int n = Arrival.size();
        int max_station=INT_MIN;
        for(int i=0;i<n;i++){
            int station=0;
            for(int j=i;j<n;j++){
                if(Arrival[j]<Departure[i]) station++;
                else break;
            }
            max_station=max(max_station,station);
        }
        return max_station;
    }
};


//double loop ith departure se and fhir sabko baar baar apne next arrival[] se compare
//karo and increase karte jao 

//TLE (n^2)   //10^5 constraints value tha