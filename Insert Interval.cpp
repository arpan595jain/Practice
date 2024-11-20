class Solution {
  public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        auto intervalBefore = intervals.end();
        auto intervalAfter = intervals.end();

        for (auto it = intervals.begin(); it != intervals.end(); ++it) {
          if ((*it)[START] <= newInterval[START]) {
            intervalBefore = it;
          }
          if (intervalAfter == intervals.end() &&
              (*it)[END] >= newInterval[END]) {
            intervalAfter = it;
          }
        }

        vector<vector<int>> result;
        vector<int> toInsert = newInterval;

        if (intervalBefore != intervals.end()) {
          if ((*intervalBefore)[END] < newInterval[START]) {
            ++intervalBefore;
          } else {
            toInsert[START] = (*intervalBefore)[START];
          }
        } else {
          intervalBefore = intervals.begin();
        }

        if (intervalAfter != intervals.end() &&
            (*intervalAfter)[START] <= newInterval[END]) {
            toInsert[END] = (*intervalAfter)[END];
            ++intervalAfter;
        }

        result.insert(result.begin(), intervals.begin(), intervalBefore);
        result.push_back(toInsert);
        result.insert(result.end(), intervalAfter, intervals.end());

        return result;
    }

  private:
    static constexpr int START = 0;
    static constexpr int END = 1;
};
