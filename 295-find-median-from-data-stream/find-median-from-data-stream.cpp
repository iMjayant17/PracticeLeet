class MedianFinder {
public:
    priority_queue<int> lefty;
        priority_queue<int,vector<int>,greater<int>> right;
    MedianFinder() {
        
    
    }
    
    void addNum(int num) {
        if(lefty.size()==0 || lefty.top()>=num){
            lefty.push(num);
        }
        else{
            right.push(num);
        }

        if(lefty.size()-1>right.size()){
            right.push(lefty.top());
            lefty.pop();
        }
        else if(right.size()>lefty.size()){
            lefty.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {
        if((lefty.size()+right.size())&1){
            return (double) lefty.top();
        }
        double ans = (lefty.top() + right.top())/2.0;
        return ans;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */