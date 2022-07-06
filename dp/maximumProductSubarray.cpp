int maximumProduct(vector<int> &nums, int n)
{
	// Write your code here
    int maxi = nums[0];
    int mini = nums[0];
    int res = nums[0];
    n = nums.size();
    for(int i =1;i<n;i++){
        if(nums[i]<0) swap(maxi,mini);
        maxi = max(maxi*nums[i], nums[i]);
        mini = min(mini*nums[i], nums[i]);
        res = max(res,maxi);
    }
    return res;
}
