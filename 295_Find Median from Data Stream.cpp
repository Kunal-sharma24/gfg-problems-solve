class MedianFinder {
public:
    priority_queue<int> greaterpq;    
    priority_queue<int,vector<int>,greater<int>> smallerpq;   //2 priority queue taki humlog half half m split kar le
    MedianFinder() {
        return;
    }
    
    void addNum(int num) {
        //sabse se pehle greater m push karna ha kuch bhi and fhir uske top
        //ko compare karna ha (num) 
        //agar uss se chota hua toh push warna
        //left wala m dal do
        if(greaterpq.empty() || num<greaterpq.top()){
            greaterpq.push(num);
        }else{
            smallerpq.push(num);
        }
         
        

        //maintain the size
        //aab balanced split ka khela ha idhar
        //man lo sirf left m add ho rhe ha cz num<maxheap se
        //tab sirf left m push hote ja rhe ha
        //tab hi ye dalo ki jaise hi smaller se wo thoda bhi bada ho
        //tabhi turant right wala m dal do.
        
        if(greaterpq.size() < smallerpq.size()){
            greaterpq.push(smallerpq.top());
            smallerpq.pop();    //1 1 1 1 2 2 2 2 3 3
        }
        //
        else if(greaterpq.size() > smallerpq.size() > 1){
            smallerpq.push(greaterpq.top());
            greaterpq.pop();    // 1 2 2 3 3 3 3 3 3 3
        }
    }
    
    double findMedian() {
        if(greaterpq.size() == smallerpq.size()) {
            return (greaterpq.top() + smallerpq.top())/2.0;
        }else{
            return greaterpq.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */