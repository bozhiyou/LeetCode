class Solution {
	public:
		    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
			            vector<vector<int>> answer(
						                                    (mat.size()),
										                                    *(new vector<int>(mat[0].size(), 0))
														                                    );
				            for (uint8_t i = 0; i < answer.size(); i++) {
						                for (uint8_t j = 0; j < answer[i].size(); j++) {
									                for (uint8_t r = (i - K < 0? 0 : i - K); r <= (i + K >= mat.size()? mat.size() - 1 : i + K); r++) {
												                    for (uint8_t c = (j - K < 0? 0 : j - K); c <= (j + K >= mat[0].size()? mat[0].size() - 1 : j + K); c++) {
															                            answer[i][j] += mat[r][c];
																		                        }
														                    }
											            }
								        }
					            return answer;
						        }
};
