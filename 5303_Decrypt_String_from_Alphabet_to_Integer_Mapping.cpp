/**
 * Weekly Contest 170
 */
class Solution {
	public:
		    char map(int i) {
			          return char('a' - 1 + i);
				      }
		        string freqAlphabets(string s) {
				      string ret("");
				            auto i = s.end();
					          for (i--; i >= s.begin(); i--) {
							          if ((*i) == '#') {
									            ret = string(1, map(std::stoi(string(i-2, i)))) + ret;
										              i -= 2;
											              }
								          else {
										            ret = string(1, map((*i) - '0')) + ret;
											            }
									        }
						        return ret;
							    }
};

string stringToString(string input) {
	    assert(input.length() >= 2);
	        string result;
		    for (int i = 1; i < input.length() -1; i++) {
			            char currentChar = input[i];
				            if (input[i] == '\\') {
						                char nextChar = input[i+1];
								            switch (nextChar) {
										                    case '\"': result.push_back('\"'); break;
													                       case '/' : result.push_back('/'); break;
																	                  case '\\': result.push_back('\\'); break;
																				                     case 'b' : result.push_back('\b'); break;
																								                case 'f' : result.push_back('\f'); break;
																											                   case 'r' : result.push_back('\r'); break;
																														                      case 'n' : result.push_back('\n'); break;
																																		                 case 't' : result.push_back('\t'); break;
																																					                    default: break;
																																								                 }
									                i++;
											        } else {
													          result.push_back(currentChar);
														          }
					        }
		        return result;
}

int main() {
	    string line;
	        while (getline(cin, line)) {
			        string s = stringToString(line);
				        
				        string ret = Solution().freqAlphabets(s);

					        string out = (ret);
						        cout << out << endl;
							    }
		    return 0;
}
