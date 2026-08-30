class Solution{
    public:
    int findPlatform(vector<int>& Arrival, vector<int>& Departure){
        //your code goes here
        int n = Arrival.size();
        int i=0,j=0,station=0,maxstation=0;
        while(i<n && j<n){
            if(Arrival[i]<Departure[j]){
                station++;
                maxstation=max(maxstation,station);
                i++;
            }
            else{
                station--;
                j++;
            }
        }
        return maxstation;
    }
};




//isme humlog departure aur arrival dono ko i and j 2 pointers type liye
//aab humlog traverse kar rhe the now agar arrival[i]<departure[j] toh fhir station++
//increase kar denge niii toh fhir agar diff aaya toh station-- kar denge
