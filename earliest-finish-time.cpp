class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int minTime = INT_MAX;
        int n = landStartTime.size();
        int m = waterStartTime.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {

              int landFirstTotal = landStartTime[i] + landDuration[i] +
              max(0, waterStartTime[j] - landStartTime[i] - landDuration[i]) +  waterDuration[j];

              int waterFirstTotal = waterStartTime[j] +  waterDuration[j] +
              max(0, landStartTime[i] - waterStartTime[j] - waterDuration[j]) + landDuration[i];

              minTime = min(minTime, min(landFirstTotal, waterFirstTotal));
                }
            }

        return minTime;

    }
};

