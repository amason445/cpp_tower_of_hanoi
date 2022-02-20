# Read Me
## Tower of Hanoi from Knuth's Concrete Mathematics

The purpose of this repository is to implement the solutions of Knuth's Tower of Hanoi problem from his Concrete Mathematics in C++. Knuth describes a puzzle in which different discs ordered by size are stacked on a peg and then moved, one at a time between three pegs, including the original, to a new peg. The discs can only be moved one at a time and must be stacked in order from smallest to largest.

Rules:
1. You must move one at a time
2. You must never move a larger onto a smaller

There are two solutions to this problem:
1. Recurrence Solution, which takes the form of a recursive solution:
``` 
T(0) = 0;
T(n) = 2(T(n-1)) + 1, for n > 0;
```
2. Closed form solution, which is a function:
```
T(n) = 2^n - 1;
```

Notes:
1. The program cannot take any inputs lower than zero, as that would imply no discs exist
2. The program cannot safely take any inputs larger than 62, as that would exceed the storage capacity of a 64-bit system
