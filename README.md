# dsa-c-final--2408101530007-
This is for the final assesment submission for the July Training for DSA Using C Programming Language in Greater Noida College Of Technology

# DSA-C Final Assessment - Ankit Jaiswal (2408101530007/College ID:24665119)

## Build
gcc -std=c11 -Wall -Wextra -O2 SectionB/01_evaluator.c -o q1
gcc -std=c11 -Wall -Wextra -O2 SectionB/Q2_history.c -o q2

## Question status
| Question | Complete / Partial / Not attempted | Known limitations |
|---|---|---|
| Q1 | Complete | None |
| Q2 | Complete | None |
| Q3 | not attempted | __ |
| C1 | Complete | None |
| C2 | Complete | None |

## Complexity analysis
| Question | Data structure used | Time | Space | Reason for the choice |
|---|---|---|---|---|
| Q1 | Stack (Array-based) | O(n) | O(n) | Handles operator precedence and evaluation efficiently via LIFO order. |
| Q2 | Doubly Linked List | O(1) | O(n) | Enables O(1) step-back and step-forward traversal between pages. |
| Q3 | Adjacency Matrix | O(n^2) | O(n^2) | Simple and efficient matrix representation for dense graphs up to 100 hubs. |
| C2 | Two Pointers (Sliding Window) | O(n) | O(1) | Left and right pointers advance monotonically across non-negative arrays. |

## Memory safety
All dynamic memory allocated across all completed questions (Q1, Q2, C1, C2) is completely freed prior to program termination. Zero memory leaks remain.

dsa-c-final-<ROLL>/
README.md
.gitignore
SectionA/
answers.txt
SectionB/
Q1_evaluator.c
Q2_history.c
SectionC/
review.md
C1_reverse.c
C2_window.
