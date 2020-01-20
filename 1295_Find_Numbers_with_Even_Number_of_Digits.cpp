class Solution {
	    /**
	     *      * @Author: Bozhi You (游博智)
	     *           */
	    template <class InputIt, class UnaryPredicate>
		        constexpr int count_if(InputIt first, InputIt last, UnaryPredicate q) {
				        while (first != last)
						            if (q(*(first++)))
								                    return 1 + count_if(first, last, q);
					        return 0;
						    }
	public:
	        int findNumbers(vector<int>& nums) {
			        return count_if(nums.begin(), nums.end(), [](int n){ return (n < 1e4 && (n > 999 || (n < 100 && n > 9))); });
				    }
};
