/**
 * Weekly Contest 170
 */
class Solution {
	public:
		    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
			            vector<int> ret;
				            for (auto q : queries) {
						              int _ret = arr[q[0]];
							                for (int l = q[0]+1, r = q[1]; l <= r; l++) {
										            _ret ^= arr[l];
											              }
									          ret.push_back(_ret);
										          }
					            return ret;
						        }
};
