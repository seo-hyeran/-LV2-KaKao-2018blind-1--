#include <string>
#include<vector>
#include<algorithm>
using namespace std;

int solution(string str1, string str2) {
    int answer = 0;
    int s_max = 0;
    int s_min = 0;
    vector<string>st1;
    vector<string> st2;

    transform(str1.begin(), str1.end(), str1.begin(), ::tolower);
    transform(str2.begin(), str2.end(), str2.begin(), ::tolower);

    for (int i = 0; i < str1.size() - 1; i++) {
        string tmp = str1.substr(i, 2);
        if (tmp[0] >= 'a' && tmp[1] <= 'z' && tmp[1] >= 'a' && tmp[1] <= 'z') {
            st1.push_back(tmp);
        }
    }
    for (int i = 0; i < str2.size() - 1; i++) {
        string tmp = str2.substr(i, 2);
        if (tmp[0] >= 'a' && tmp[1] <= 'z' && tmp[1] >= 'a' && tmp[1] <= 'z') {
            st2.push_back(tmp);
        }
    }

    if (st1.empty() && st2.empty()) {
        return 65536;
    }
    s_max = st1.size() + st2.size();

    if (st1.size() > st2.size()) {
        for (int i = 0; i < st2.size(); i++) {
            auto iter = find(st1.begin(), st1.end(), st2[i]);
            if (iter != st1.end()) {
                s_min++;
                st1.erase(iter);
            }
        }
    }
    else {
        for (int i = 0; i < st1.size(); i++) {
            auto iter = find(st2.begin(), st2.end(), st1[i]);
            if (iter != st2.end()) {
                s_min++;
                st2.erase(iter);
            }
        }
    }
    s_max -= s_min;

    if (s_max == 0) {
        return 65536;
    }
    double result = double(s_min) / double(s_max);
    answer = result * 65536;

    return answer;
}