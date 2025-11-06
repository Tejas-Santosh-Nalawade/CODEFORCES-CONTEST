#include <bits/stdc++.h>
using namespace std;
using int64 = long long;
const int64 NEG_INF = -(1LL << 60);


void debug_state(string tag, int64 dpLow, int64 lowMin, int64 lowMax,
                 int64 dpHigh, int64 highMin, int64 highMax) {
#ifdef DEBUG_MODE
    cerr << "---- " << tag << " ----\n";
    cerr << "LowState: dp=" << dpLow << " range=[" << lowMin << "," << lowMax << "]\n";
    cerr << "HighState: dp=" << dpHigh << " range=[" << highMin << "," << highMax << "]\n";
#endif
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tt;
    cin >> tt;
    while (tt--) {
        int64 R0, X, D;
        int n;
        cin >> R0 >> X >> D >> n;
        string s;
        cin >> s;
        int64 dpLow = NEG_INF, dpHigh = NEG_INF;
        int64 lowMin = 1e18, lowMax = -1;
        int64 highMin = 1e18, highMax = -1;

        if (R0 < X) {
            dpLow = 0;
            lowMin = lowMax = R0;
        } else {
            dpHigh = 0;
            highMin = highMax = R0;
        }

        debug_state("Initial", dpLow, lowMin, lowMax, dpHigh, highMin, highMax);

        for (int round = 0; round < n; ++round) {
            char c = s[round];

            int64 nextDpLow = NEG_INF, nextDpHigh = NEG_INF;
            int64 nextLowMin = 1e18, nextLowMax = -1;
            int64 nextHighMin = 1e18, nextHighMax = -1;

            if (dpLow > NEG_INF) {
                int add = 1;
                int64 newL = max<int64>(0, lowMin - D);
                int64 newH = lowMax + D;

            
                int64 llow = newL;
                int64 hlow = min<int64>(newH, X - 1);
                if (llow <= hlow) {
                    int64 cand = dpLow + add;
                    if (cand > nextDpLow) {
                        nextDpLow = cand;
                        nextLowMin = llow;
                        nextLowMax = hlow;
                    } else if (cand == nextDpLow) {
                        nextLowMin = min(nextLowMin, llow);
                        nextLowMax = max(nextLowMax, hlow);
                    }
                }
                int64 lhigh = max<int64>(newL, X);
                int64 hhigh = newH;
                if (lhigh <= hhigh) {
                    int64 cand = dpLow + add;
                    if (cand > nextDpHigh) {
                        nextDpHigh = cand;
                        nextHighMin = lhigh;
                        nextHighMax = hhigh;
                    } else if (cand == nextDpHigh) {
                        nextHighMin = min(nextHighMin, lhigh);
                        nextHighMax = max(nextHighMax, hhigh);
                    }
                }
            }

            if (dpHigh > NEG_INF) {
                if (c == '1') {
                    int add = 1;
                    int64 newL = max<int64>(0, highMin - D);
                    int64 newH = highMax + D;
                    int64 llow = newL;
                    int64 hlow = min<int64>(newH, X - 1);
                    if (llow <= hlow) {
                        int64 cand = dpHigh + add;
                        if (cand > nextDpLow) {
                            nextDpLow = cand;
                            nextLowMin = llow;
                            nextLowMax = hlow;
                        } else if (cand == nextDpLow) {
                            nextLowMin = min(nextLowMin, llow);
                            nextLowMax = max(nextLowMax, hlow);
                        }
                    }

                    int64 lhigh = max<int64>(newL, X);
                    int64 hhigh = newH;
                    if (lhigh <= hhigh) {
                        int64 cand = dpHigh + add;
                        if (cand > nextDpHigh) {
                            nextDpHigh = cand;
                            nextHighMin = lhigh;
                            nextHighMax = hhigh;
                        } else if (cand == nextDpHigh) {
                            nextHighMin = min(nextHighMin, lhigh);
                            nextHighMax = max(nextHighMax, hhigh);
                        }
                    }
                } else {
                    int64 cand = dpHigh;
                    int64 l = highMin, h = highMax;
                    if (cand > nextDpHigh) {
                        nextDpHigh = cand;
                        nextHighMin = l;
                        nextHighMax = h;
                    } else if (cand == nextDpHigh) {
                        nextHighMin = min(nextHighMin, l);
                        nextHighMax = max(nextHighMax, h);
                    }
                }
            }

            dpLow = nextDpLow;
            dpHigh = nextDpHigh;
            lowMin = (nextLowMax == -1 ? 1e18 : nextLowMin);
            lowMax = nextLowMax;
            highMin = (nextHighMax == -1 ? 1e18 : nextHighMin);
            highMax = nextHighMax;

            string tag = "After round " + to_string(round + 1) + " (" + c + ")";
            debug_state(tag, dpLow, lowMin, lowMax, dpHigh, highMin, highMax);
        }

        int64 ans = max(dpLow, dpHigh);
        if (ans < 0) ans = 0;
        cout << ans << "\n";
    }

    return 0;
}
