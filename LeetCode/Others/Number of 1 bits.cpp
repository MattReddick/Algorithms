class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ones = 0;
        for(int i = 0; i < 32; i++){
            if(n&1){
                ones++;
            }
            n = n >> 1;
        }
        return ones;
    }
};
