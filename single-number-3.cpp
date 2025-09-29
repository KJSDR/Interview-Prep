// ============================================================================
// 260. Single Number III  (fixed: handle INT_MIN safely)
// ============================================================================
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int xorAll = 0;
        for (int x : nums) xorAll ^= x;   // xorAll = a ^ b (a != b)

        // Use unsigned to extract the lowest set bit safely (no signed overflow).
        unsigned ux = static_cast<unsigned>(xorAll);
        unsigned diffBit = ux & (~ux + 1u);   // == ux & -ux in unsigned arithmetic

        int a = 0, b = 0;
        for (int x : nums) {
            if (static_cast<unsigned>(x) & diffBit) a ^= x;
            else                                     b ^= x;
        }
        return {a, b};
    }
};
