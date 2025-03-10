class BIT{
    private : 
    int sum(int i){     //get prefix sum [1.....i]
        int ans=0;
        while(i>0){
            ans+=bit[i];
            i-=(i&-i);
        }
        return ans;
    }
    public:
    int size;
    vector<int> bit;
    BIT(int n){
        size=n+1;
        bit.resize(size,0);
    }
    void update(int i,int delta){
        while(i<size){
            bit[i]+=delta;
            i+=(i&-i);
        }
    }
    
    int rangeSum(int l,int r){      //range sum[l....r]
        return sum(r)-sum(l-1);
    }
};
