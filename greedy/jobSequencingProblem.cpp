#include<bits/stdc++.h>
bool comparision(vector<int> a, vector<int> b){
    return (a[1] > b[1]);
}

int jobScheduling(vector<vector<int>> &jobs)
{
    // Write your code here
    sort(jobs.begin(), jobs.end(), comparision);
    int maxi = jobs[0][0];
    for(int i = 1; i<jobs.size(); i++){
        maxi = max(maxi, jobs[i][0]);
    }
    
    vector<int> slot(maxi + 1, -1);
    
    int countJobs = 0, jobProfit = 0;
    for(int i =0; i<jobs.size(); i++){
        for(int j = jobs[i][0]; j>0; j--){
            if(slot[j] == -1){
                slot[j] = i;
                countJobs++;
                jobProfit += jobs[i][1];
                break;
            }
        }
    }
    return jobProfit;
//     return 0;
}
