#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt; 
    cin >> tt;
    while (tt--) {
        long long totalTime, endPoint;
        cin >> totalTime >> endPoint;

        long long totalSteps = 0, previousTime = 0;
        int previousSide = 0;

        for (int i = 0; i < totalTime; i++) {
            long long currentTime, targetSide;
            cin >> currentTime >> targetSide;
            long long timeDifference = currentTime - previousTime;
            int requiredChange = previousSide ^ targetSide;

            totalSteps += (timeDifference % 2 == requiredChange ? timeDifference : timeDifference - 1);

            previousTime = currentTime;
            previousSide = targetSide;
        }
        totalSteps += (endPoint - previousTime);

        cout << totalSteps << '\n';
    }
}
