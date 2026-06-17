#include <bits/stdc++.h>
using namespace std;

/**
 * Prefix Sum Array
 *
 * Given an array arr, create prefix sum array where
 * prefix[i] = sum of arr[0] + arr[1] + ... + arr[i]
 *
 * Then, sum of subarray arr[l..r] = prefix[r] - prefix[l-1]
 *
 * Time: O(n) to build, O(1) per query
 * Space: O(n)
 */

vector<int> buildPrefixSum(vector<int> &arr)
{
    int n = arr.size();
    vector<int> prefix(n);
    prefix[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefix[i] = prefix[i - 1] + arr[i];
    }

    return prefix;
}

int rangeSum(vector<int> &prefix, int l, int r)
{
    if (l == 0)
        return prefix[r];
    return prefix[r] - prefix[l - 1];
}

int main()
{
    vector<int> arr = {2, 4, 1, 7, 3};

    vector<int> prefix = buildPrefixSum(arr);

    int l = 1, r = 3;
    int sum = rangeSum(prefix, l, r);

    cout << "Sum of arr[" << l << "] to arr[" << r << "] = " << sum << endl;
    // Output: 4 + 1 + 7 = 12

    return 0;
}