class Solution {
public:
    int numberOfSteps (int num) {
		if(!num) return 0;
        int res = 0;
        while(num) {
            res += (num & 1) ? 2 : 1;
            num >>= 1;
        }
        return res - 1;
    }
    
    // int numberOfSteps (int num) {
    //     return num == 0 ? 0 : log2(num) + bitset<32>(num).count();
    // }
};