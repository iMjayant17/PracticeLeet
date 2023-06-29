class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t i = 0;
        for(int j = 0;j<32;j++){
            int bit = n&1;
            i = i<<1;
            if(bit==1){
                i = i|1;
            }
            n= n>>1;
        
        }
        return i;
    }
};