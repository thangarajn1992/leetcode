# Leetcode 295 Find Median from Data Stream

## Problem Statement

[https://leetcode.com/problems/find-median-from-data-stream/](https://leetcode.com/problems/find-median-from-data-stream/)

The **median** is the middle value in an ordered integer list. If the size of the list is even, there is no middle value and the median is the mean of the two middle values.

* For example, for `arr = [2,3,4]`, the median is `3`.
* For example, for `arr = [2,3]`, the median is `(2 + 3) / 2 = 2.5`.

Implement the MedianFinder class:

* `MedianFinder()` initializes the `MedianFinder` object.
* `void addNum(int num)` adds the integer `num` from the data stream to the data structure.
* `double findMedian()` returns the median of all elements so far. Answers within `10-5` of the actual answer will be accepted.

**Example 1:**

```text
Input
["MedianFinder", "addNum", "addNum", "findMedian", "addNum", "findMedian"]
[[], [1], [2], [], [3], []]
Output
[null, null, null, 1.5, null, 2.0]

Explanation
MedianFinder medianFinder = new MedianFinder();
medianFinder.addNum(1);    // arr = [1]
medianFinder.addNum(2);    // arr = [1, 2]
medianFinder.findMedian(); // return 1.5 (i.e., (1 + 2) / 2)
medianFinder.addNum(3);    // arr[1, 2, 3]
medianFinder.findMedian(); // return 2.0
```

**Constraints:**

* `-10^5 <= num <= 10^5`
* There will be at least one element in the data structure before calling `findMedian`.
* At most `5 * 10^4` calls will be made to `addNum` and `findMedian`.

**Follow up:**

* If all integer numbers from the stream are in the range `[0, 100]`, how would you optimize your solution?
* If `99%` of all integer numbers from the stream are in the range `[0, 100]`, how would you optimize your solution?

## Solution

### Two Priority Queue Approach

```cpp
class MedianFinder {
private:
    int size = 0;
    priority_queue<int, vector<int>, less<int>> left;   // Max-heap
    priority_queue<int, vector<int>, greater<int>> right; // Min-heap
public: 
    /** initialize your data structure here. */
    MedianFinder() {
        ios_base::sync_with_stdio(false);    
        cin.tie(NULL);
        left.push(INT_MIN);
        right.push(INT_MAX);
    }
    
    void addNum(int num) {
        int a = left.top();
        int b = right.top();
        if (size % 2 == 0) { // If size is even, we will try to push to left pq
            if (num > b) {
                right.pop();
                right.push(num);
                left.push(b);
            }
            else left.push(num);
        }
        else { // If size is uneven, we will try to push to right pq
            if (num < a) {
                left.pop();
                left.push(num);
                right.push(a);
            }
            else right.push(num);
        }
        ++size;
    }
    
    double findMedian() {
        if (size % 2 == 0) return (double)(left.top() + right.top()) / 2;
        return left.top();
    }
};

```

### Vector + Binary search Approach \( My solution \)

```cpp
class MedianFinder {
public:
    vector<int> arr;
    MedianFinder() {     
    }
    
    void addNum(int num) {
        int left = 0, right = arr.size() - 1;
        while(left <= right)
        {
            int mid = left + (right - left)/2;
            if(arr[mid] <= num)
                left = mid+1;
            else
                right = mid-1;
        }
        arr.insert(arr.begin()+left, num);
    }
    
    double findMedian() {
        int size = arr.size();
        if(size % 2)
           return (double)arr[size/2];
        else
            return (double)(arr[(size/2) - 1] + arr[(size/2)])/2;    
    }
};
```

