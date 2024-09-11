// There are N ropes of different lengths given in arr[ J, connect these ropes to form a
// single rope. The cost to connect two ropes is equal to sum of their lengths. Connect the
// ropes while minimising the cost.
// Example 1:
// Input:
// arro
// Output:
// 29
// Explanation:
// Given 4 ropes of lengths 4, 3, 2 and 6.
// First connect ropes of lengths 2 and 3.
// Now we have three ropes of lengths 4, 6
// and 5.
// Now connect ropes of lengths 4 and 5.
// Now we have two ropes of lenqths 6 and 9.

long long minCost(long long arr[], long long n) {
        
        priority_queue<long long, vector<long long>, greater<long long> > pq(
            arr, arr + n);
    
        long long res = 0;
    
        while (pq.size() > 1) {
            long long first = pq.top(); // storing first
            pq.pop();
            long long second = pq.top(); // storing second
            pq.pop();
    
            res += first + second;
            // push first and second back in priority queue
            pq.push(first + second);
        }
    
        return res;
    }