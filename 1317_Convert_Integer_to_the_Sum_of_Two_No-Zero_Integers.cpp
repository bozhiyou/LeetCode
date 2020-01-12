class Solution {
	public:
		    vector<int> getNoZeroIntegers(int n) {
			            int16_t a;
				            for (a = 1; a < n; a++) {
						                if (std::string::npos == std::to_string(a).find('0')
										                && std::string::npos == std::to_string(n-a).find('0'))
									                break;
								        }
					            return std::vector<int>({a, n-a});
						        }
};
