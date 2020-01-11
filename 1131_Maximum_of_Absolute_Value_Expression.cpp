// Time out
class Solution {
public:
    /**
     * |arr1[i] - arr1[j]| + |arr2[i] - arr2[j]| + |i - j|
     * must equal to the maximum of the following cases:
     *   case 1: |arr1[i] - arr1[j] + arr2[i] - arr2[j] + i - j|
     *   case 2: |arr1[i] - arr1[j] + arr2[i] - arr2[j] - i + j|
     *   case 3: |arr1[i] - arr1[j] - arr2[i] + arr2[j] + i - j|
     *   case 4: |arr1[i] - arr1[j] - arr2[i] + arr2[j] - i + j|
     *   case 5: |- arr1[i] + arr1[j] - arr2[i] + arr2[j] - i + j|
     *   case 6: |- arr1[i] + arr1[j] - arr2[i] + arr2[j] + i - j|
     *   case 7: |- arr1[i] + arr1[j] + arr2[i] - arr2[j] - i + j|
     *   case 8: |- arr1[i] + arr1[j] + arr2[i] - arr2[j] + i - j|
     * while the first half is identical to the second half, so
     * there are only four cases to be considered:
     *   case 1: |(arr1[i] + arr2[i] + i) - (arr1[j] + arr2[j] + j)|
     *   case 2: |(arr1[i] + arr2[i] - i) - (arr1[j] + arr2[j] - j)|
     *   case 3: |(arr1[i] - arr2[i] + i) - (arr1[j] - arr2[j] + j)|
     *   case 4: |(arr1[i] - arr2[i] - i) - (arr1[j] - arr2[j] - j)|
     */
    int maxAbsValExpr(vector<int>& arr1, vector<int>& arr2) {
        int ret = 0;
        // Constraints: 40000 < 2^16
        for (uint16_t i = 0; i < arr1.size(); i++)
            for (uint16_t j = 0; j < arr1.size(); j++) {
                ret = std::max(ret,
                              std::max(
                                      std::max(
                                          std::abs( (arr1[i] + arr2[i] + i) - (arr1[j] + arr2[j] + j) ),
                                          std::abs( (arr1[i] + arr2[i] - i) - (arr1[j] + arr2[j] - j) )
                                          ),
                                      std::max(
                                          std::abs( (arr1[i] - arr2[i] + i) - (arr1[j] - arr2[j] + j) ),
                                          std::abs( (arr1[i] - arr2[i] - i) - (arr1[j] - arr2[j] - j) )
                                      )
                              ));
            }
        return ret;
        
    }
};
