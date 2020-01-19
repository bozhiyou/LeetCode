class Solution {
	public:
		    vector<string> printVertically(string s) {
			            vector<string> ret;
				            int i = 0, j = 0;
					            for (auto c : s) {
							                if (c == ' ') {
										                i = 0;
												                j++;
														            }
									            else {
											                    if (i < ret.size()) {
														                        while (ret[i].size() < j)
																		                        ret[i] += ' ';
																	                }
													                    else
																                        ret.push_back(string(j, ' '));
															                    ret[i] += c;
																	                    i++;
																			                }
										            }
						            return ret;
							        }
};
