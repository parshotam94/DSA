In this i have tried to apply the basic knowledge of recursion.

Recursion :
  A function calls itself directly or indirectly to solve a problem.
  Problem is divided into smaller subproblems of the same type.

Key Components
  Base Case → Stops the recursion (prevents infinite loop).
  Recursive Case → Function calls itself with smaller/simpler input.

Advantages
  Simpler, cleaner code for problems like:
    Factorial
    Fibonacci
    Tower of Hanoi
    Tree traversals
  Naturally maps to problems defined recursively.

Disadvantages
  More memory usage (stack frames for each call).\
  Can be slower due to function call overhead.
  Risk of stack overflow if base case is missing or input is large.
