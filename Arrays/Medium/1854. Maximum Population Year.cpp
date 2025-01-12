class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> ab(101);
        for(int i = 0;i<logs.size();i++){
            int first = logs[i][0];
            int second = logs[i][1];
            ab[first-1950]++;
           if(second>1950){
            ab[second-1950]--;
           }
        }
        int maxval = -1000;
        int v = 0;
        int year = 0;
        for(int i = 0;i<101;i++){
            v +=ab[i];
            if(v>maxval){
                maxval = v;
                year = i;
            }
        }
        return year+1950;
    }
};