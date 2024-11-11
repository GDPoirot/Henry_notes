#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// Given an array of integers temperatures represents the daily temperatures, 
// return an array answer such that answer[i] is the number of days you have to wait -  
// after the ith day to get a warmer temperature. If there is no future day for which this is possible, 
// keep answer[i] == 0 instead.

// Example 1:
// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]

// Example 2:
// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]

// Example 3:
// Input: temperatures = [30,60,90]
// Output: [1,1,0]

// 亲测 暴力解法超时

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> res(temperatures.size(), 0);
        stack<int> st;
        st.push(0);

        for (int i = 1; i < temperatures.size(); i++) {
            if (temperatures[i] <= temperatures[st.top()]) {
                st.push(i);
            }
            else {
                while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                    res[st.top()] = i - st.top();
                    st.pop();
                }
                st.push(i);
            }
        }
        return res;
    }
};

int main() {
    Solution s;
    vector<int> temperatures;
    int input;
    while (cin >> input) {
        temperatures.push_back(input);
    }

    for (int i = 0; i < temperatures.size(); ++i) {
        cout << temperatures[i] << " ";
    }
    cout << endl;

    vector<int>res = s.dailyTemperatures(temperatures);

    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }

    return 0;
}