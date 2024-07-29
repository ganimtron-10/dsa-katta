// https://www.naukri.com/code360/problems/maximum-subarray-sum_10297899

long long maxSubarraySum(vector<int> arr, int n)
{
    // Write your code here.
    long long maxVal = 0;
    long long curVal = 0;
    for (int val : arr)
    {
        curVal += val;
        if (curVal > maxVal)
        {
            maxVal = curVal;
        }
        if (curVal < 0)
        {
            curVal = 0;
        }
    }
    return maxVal;
}
s