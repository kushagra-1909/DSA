// Given an array where each element(arr[i]) represents the height of the tower at position i.For
// each i, we need to find the nearest index j(j > i or j < i) whose height is less than current
// towers height(arr[j] < arr[i]).lf there exist two such towers, one to the right and one to the
// left at the same distance choose the smaller one but if those two towers have the same
// height then choose the tower with a smaller index.
// Example 1:
// Input: 1 3 2
// Output: -1 0 0
// Explanation:
// There is no smaller tower on left or right
// of the tower at position O.The tower at position
// 0 is nearest smaller tower of the tower at position
// 1 and also of the tower at position 2.So the output


class Solution
{
public:
    vector<int> nearestSmallerTower(vector<int> arr){
	    int n = arr.size();
        stack<int>left;
        stack<int>right;
        vector<int>res(n,-1);

        for (int i = 0; i < n; i++)
        {
            while (!left.empty() && arr[left.top()] >= arr[i])
            {
                left.pop();
            }

            if (!left.empty())
            {
                res[i] = left.top();
            }

            left.push(i);
        }

        for (int i = n - 1; i >= 0; i--)
        {
            while (!right.empty() && arr[right.top()] >= arr[i])
            {
                right.pop();
            }

            if (!right.empty())
            {
                    // right.peek() is my ans here, do the comparison.
                if (res[i] != -1)
                {
                    //if dist equal, take the lower height
                    if (abs(res[i] - i) == abs(right.top() - i))
                    {
                        if (arr[res[i]] > arr[right.top()])
                            res[i] = right.top();
                    }
                    //take nearest towr.
                    else if (abs(res[i] - i) > abs(right.top() - i))
                        res[i] = right.top();
                }
                // if res[i]== -1 => no samller tower was found in left.
                else
                    res[i] = right.top();
            }

            right.push(i);
        }

        return res;
    }