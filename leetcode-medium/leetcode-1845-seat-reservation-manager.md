# Leetcode 1845  Seat Reservation Manager

## Problem Statement

[https://leetcode.com/problems/seat-reservation-manager/](https://leetcode.com/problems/seat-reservation-manager/)

Design a system that manages the reservation state of `n` seats that are numbered from `1` to `n`.

Implement the `SeatManager` class:

* `SeatManager(int n)` Initializes a `SeatManager` object that will manage `n` seats numbered from `1` to `n`. All seats are initially available.
* `int reserve()` Fetches the **smallest-numbered** unreserved seat, reserves it, and returns its number.
* `void unreserve(int seatNumber)` Unreserves the seat with the given `seatNumber`.

**Example 1:**

```text
Input
["SeatManager", "reserve", "reserve", "unreserve", "reserve", "reserve", "reserve", "reserve", "unreserve"]
[[5], [], [], [2], [], [], [], [], [5]]
Output
[null, 1, 2, null, 2, 3, 4, 5, null]

Explanation:
// Initializes a SeatManager with 5 seats.
SeatManager seatManager = new SeatManager(5); 

// All seats are available, so return the lowest numbered seat, which is 1.
seatManager.reserve();

// The available seats are [2,3,4,5],so return the lowest of them, which is 2.  
seatManager.reserve();  

// Unreserve seat 2, so now the available seats are [2,3,4,5].  
seatManager.unreserve(2); 

// The available seats are [2,3,4,5], so return the lowest of them, which is 2.
seatManager.reserve();

// The available seats are [3,4,5], so return the lowest of them, which is 3.   
seatManager.reserve();

// The available seats are [4,5], so return the lowest of them, which is 4.    
seatManager.reserve(); 

// The only available seat is seat 5, so return 5.   
seatManager.reserve(); 

// Unreserve seat 5, so now the available seats are [5].   
seatManager.unreserve(5); 
```

**Constraints:**

* `1 <= n <= 10^5`
* `1 <= seatNumber <= n`
* For each call to `reserve`, it is guaranteed that there will be at least one unreserved seat.
* For each call to `unreserve`, it is guaranteed that `seatNumber` will be reserved.
* At most `10^5` calls **in total** will be made to `reserve` and `unreserve`.

## Solution

### Min Heap with Priority Queue Approach

```cpp
class SeatManager {
public:
    int least_available;
    int total_seats;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    SeatManager(int n) {   
        for(int i = 1; i <= n; i++)
            minHeap.push(i);
    }
    
    int reserve() {
         int result = minHeap.top();
         minHeap.pop();
        return result;
    }
    
    void unreserve(int seatNumber) {
        minHeap.push(seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
```

