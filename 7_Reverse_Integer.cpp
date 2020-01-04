/**
 * Given a 32-bit signed integer, reverse digits of an integer.
 */
class Solution {
	public:
		    int reverse(int x) {
			          try {
					          if (-10 < x && x < 10) return x;
						          std::string s = std::to_string(x);
							          std::reverse(s.begin()+(x<0), s.end());
								          return std::stoi(s) | (x & 0x80000000);
									        } catch (std::exception) {
											        return 0;
												      }
				      }
};

int stringToInteger(string input) {
	    return stoi(input);
}

int main() {
	    string line;
	        while (getline(cin, line)) {
			        int x = stringToInteger(line);
				        
				        int ret = Solution().reverse(x);

					        string out = to_string(ret);
						        cout << out << endl;
							    }
		    return 0;
}
