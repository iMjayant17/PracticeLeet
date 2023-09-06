 #define ll long long

class Solution {
public:
   
    
    bool check(vector<int>& dist,ll val,double hrs){
        double time = 0;int n = dist.size()-1;
        for(int i =0;i<dist.size()-1;i++){
            time += (dist[i]+val-1)/val;
        }
        time+= (dist[n]*1.00)/(val*1.00);
        
        // cout<<time<<" "<<val<<endl;
        if(time<=hrs)  return true;
        
        return false;
        
    }
    
    
    int minSpeedOnTime(vector<int>& dist, double hrs) {
        ll s = 1;
        ll e = 1000000005;
        
        while(s<=e){
            ll mid = e - (e-s)/2;
            if(check(dist,mid,hrs)){
                e = mid-1;
            }
            else{
                s = mid+1;
            }
            
        }
        // cout<<s<<" "<<e<<endl;
        if(check(dist,s,hrs)){
            return s;
        }
        if(check(dist,e,hrs)){
            return e;
        }
        
        return -1;
    }
};