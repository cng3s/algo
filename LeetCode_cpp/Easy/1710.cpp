class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(),
            [](const vector<int>& lhs, const vector<int>& rhs) {
                return lhs[1] > rhs[1];
            });

        int currentTruckSize = 0, res = 0;
        for (const auto &boxType : boxTypes) {

            if (boxType[0] > (truckSize - currentTruckSize)) {
                res += (truckSize - currentTruckSize) * boxType[1];
                currentTruckSize = truckSize;
            } else {
                res += boxType[0] * boxType[1];
                currentTruckSize += boxType[0];
            }

            if (currentTruckSize == truckSize) {
                break;
            }
        }

        return res;
    }
};