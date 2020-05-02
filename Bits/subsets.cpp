#include <iostream>
#include <vector>
using namespace std;

void subsets(vector<int> &arr, int idx, string ans)
{
    cout << ans << endl;
    for (int i = idx; i < arr.size(); i++)
    {
        subsets(arr, i + 1, ans + to_string(arr[i]));
    }
}

int main()
{
    vector<int> arr = {1, 2, 3};
    subsets(arr, 0, "");
    return 0;
}