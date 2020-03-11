#include <iostream>
#include <iterator>
#include <string>
#include <sstream>
#include <vector>

using std::cout; using std::getline;
using std::ostream_iterator;
using std::string;
using std::istringstream;
using std::vector;

vector<string> SplitStringBySpecDelimeter(string str, char delim, bool skip_empty = true);