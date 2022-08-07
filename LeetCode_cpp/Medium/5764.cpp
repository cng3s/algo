class Solution {
public:
    int ndist; 

    bool check(const vector<int>& dist, double hour, int mi) {
        //cout << mi << ", ";
        double sum = 0.0;
        for (int i = 0; i < ndist-1; ++i) {
            sum += ceil(double(dist[i]) / double(mi));
        }
        sum += double(dist[ndist-1]) / double(mi);
        return hour >= sum;
    }

    int minSpeedOnTime(vector<int>& dist, double hour) {

        int lo = 1, hi = INT_MAX;
        ndist = dist.size();

        if (ndist > ceil(hour)) { return -1; }

        while (lo < hi) {
            int mi = lo + (hi - lo) / 2;
            if (check(dist, hour, mi)) { hi = mi; }
            else { lo = mi+1; }
        }
        return lo;
    }
};