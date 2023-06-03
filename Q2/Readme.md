### Discription
## Approach 1: Iterative
- Time complexity: O(n) per query
- Space complexity: O(1)
- Pros:
    - Easy to implement & understand
    - No memory required
- Cons:
    - It is very slow for large number
    - It is also slow for multiple queries as it don't store anything

## Approach 2: Dynamic Programming
- Time complexity: O(n) over all queries
- Space complexity: O(n)
- Pros:
    - Fast for multiple queries
    - Easy to implement & understand
    - Doesn't recalculate the same value again
- Cons:
    - Memory requirment is high
    - Can not process large number as it is limited by the size of the array

## Approach 3: Matrix Multiplication
- Time complexity: O(log(n)) per query
- Space complexity: O(1)
- Pros:
    - Fastest of all the approaches
    - Can process insanely large number
    - Doesn't consume much memory
- Cons:
    - Hard to implement & understand
    - Requires knowledge of matrix multiplication