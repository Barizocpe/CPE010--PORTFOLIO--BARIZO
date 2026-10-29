#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int getMinSteps(int n) {
    vector<int> dp(n + 1, 0);

    dp[1] = 0;

    for (int i = 2; i <= n; i++) {
        dp[i] = 1 + dp[i - 1];
 
        if (i % 2 == 0) {
            dp[i] = min(dp[i], 1 + dp[i / 2]);
        }

        if (i % 3 == 0) {
            dp[i] = min(dp[i], 1 + dp[i / 3]);
        }
    }

    return dp[n];
}

int main() {
    int testCases[] = {1, 4, 7, 10};

    cout << "=== Table 12-3. Bottom-Up Dynamic Programming Implementation ===" << endl;
    for (int n : testCases) {
        cout << "n = " << n << " -> Minimum Steps: " << getMinSteps(n) << endl;
    }

    return 0;
}