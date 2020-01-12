class Solution {
	public:
		    int minFlips(int a, int b, int c) {
			            if ((a | b) == c)
					                return 0;
				            uint32_t ret = 0;
					            for (uint32_t mask = 1; mask <= std::max({a, b, c}); mask <<= 1) {
							                bool A = (a & mask) == mask;
									            bool B = (b & mask) == mask;
										                bool C = (c & mask) == mask;
												            if ((A or B) == C)
														                    continue;
													                else
																                switch (C) {
																			                    case true:
																						                            ret += 1;
																									                            break;
																												                        default:
																												                            ret += A? (B? 2 : 1) : 1;
																															                    }
															        }
						            return ret;
							        }
};
