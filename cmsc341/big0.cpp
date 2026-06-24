/**
Asymptotic analysis

if you have 2 algorirhtms that solve the same probvlem you need to knwo which one is better without running experiments

asymptotic analysis is for theroetical analysis wehere you could opetations mathematically and express grwoth as a function of input size n

You don't cae about the exact time, rather how time grows as n grows.

Algirthm A: 6n+1 operations
Algorithm B: 2n^2 operations
n = 10:   A = 61,    B = 200     → A wins
n = 100:  A = 601,   B = 20,000  → A wins by a lot
n = 1000: A = 6001,  B = 2M      → A obliterates B

at large n, the SHAPE of growth matters, not the constants
*/

/**
Primitive operations

a primitive opeation = one basic step the CPU does in constant time
x = 5           ← assignment: 1 op
arr[i]          ← array index: 1 op
x + y           ← evaluate expression: 1 op
myFunc()        ← method call: 1 op
return x        ← return: 1 op
theexact count doesnt matter ebcasue the constants get dropped, what matters is how the COUNT SCALES wigth n

Counting ezample - arrayMax
Algorithm arrayMax(A, n):
currentMax = A[0] -> 3 ops, index, assign, read
for i = 1 to n-1:          → 2(n-1)+1 ops (loop overhead)
    if A[i] > currentMax:  → 2(n-1) ops
        currentMax = A[i]  → 2(n-1) ops (worst case)
return currentMax          → 1 op

Total: 6n - 1 ops

linear function
*/

/**
Big o the upper bound
f(n) is O(g(n)) if there exists constants c>0 and n0>=1 such that
f(n) ≤ c·g(n)   for all n ≥ n₀

after some point n initial, f never exceeds cg

big o is the worst case upper bound that says the algo will NEVER do worse than this

Sorting a list:
- Already sorted → best case (little work)
- Reverse sorted → WORST case (maximum work)

Big-O describes the WORST case.

Rule 1: Drop constants
        6n - 1 → O(n)         not O(6n)
        100n   → O(n)         not O(100n)
        5      → O(1)         constant is constant

Rule 2: Drop lower-order terms
        n² + 3n + 1 → O(n²)  the n² dominates
        n³ + n²     → O(n³)  the n³ dominates
        n log n + n → O(n log n)

Rule 3: Use the tightest (smallest) class
        2n is O(n), not O(n²)  ← say O(n)
        3n+5 is O(n), not O(3n) ← say O(n)
*/


/**
Big Omega: the lower bound

the lower bound, big omega is to dorp everything except the smallest meaningful term, what's left whent he algorithm is doing minimal work
*/

/**
Big-O:     f(n) ≤ c·g(n)          upper bound   worst case
Big-Omega: f(n) ≥ c·g(n)          lower bound   best case
Big-Theta: c'g(n) ≤ f(n) ≤ c''g(n) tight bound  exact growth rate
 */

 /**
 O(1)        constant      — array index access
O(log n)    logarithmic   — BST search (balanced)
O(n)        linear        — linked list traversal
O(n log n)  linearithmic  — merge sort
O(n²)       quadratic     — nested loops, insertion sort
O(n³)       cubic         — triple nested loops
O(2^n)      exponential   — brute force subsets
 */