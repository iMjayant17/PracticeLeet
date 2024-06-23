class NumArray {
    public:
        vector<int> tree;
        int sizee;
public:
    void BuildTree(vector<int>& nums,int s,int e,int idx){

        if(e==s){
            tree[idx] = nums[e];
            return;
        }

        int mid = (s+e)/2;
        BuildTree(nums,s,mid,idx*2);
        BuildTree(nums,mid+1,e,(idx*2) + 1);
        tree[idx] = tree[idx*2] + tree[(idx*2)+1];
    }

    NumArray(vector<int>& nums) {
        
        int n = nums.size();
        sizee = n;
        tree.resize(4*n+2,0);
        BuildTree(nums,0,n-1,1);
    }
    
    void update(int index, int val,int s = 0,int e = -1,int idx = 1) {
        if(e== -1) e = sizee - 1;
        if(s==e){
            tree[idx] = val;
            return;
        }

        int mid = (s+e)/2;
        if(index>mid){
            update(index,val,mid+1,e,idx*2 + 1);
        }
        else{
            update(index,val,s,mid,idx*2);
        }

        tree[idx] = tree[idx*2] + tree[idx*2 +1];
    }
    
    int sumRange(int left, int right,int l=0,int r = -1,int idx = 1) {
        if(r== -1) r = sizee-1;
        if(left>r || right<l){
            return 0;
        }

        if(left<=l && right>=r){
            return tree[idx];
        }

        int mid = (l+r)/2;

        int val1 = sumRange(left,right,l,mid,idx*2);
        int val2 = sumRange(left,right,mid+1,r,idx*2 +1);

        return val1 + val2;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */