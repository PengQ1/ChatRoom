#include "utils.h"

vector<string> SplitStringBySpecDelimeter(string str, char delim, bool skip_empty) {
    vector<string> result;
    istringstream iss(str);
    for (string item; getline(iss, item, delim); )
        if (skip_empty && item.empty()) continue;
        else result.push_back(item);
    return result;
}