## C1 Defect Report

| No | Line | Defect 									    | Consequence 										  |
|---|---|---										    |---     											  |  
| 1 | 4 | Variable `prev` is used uninitialized on the first iteration 			    | Assigns garbage memory address to `curr->next`, causing memory corruption/dangling pointer. |
| 2 | 6 | Loop condition `while (curr->next != NULL)` stops before processing the last node | The original tail node is never re-linked to point to the preceding node. 		  |
| 3 | 12| Function returns `head` (the original head pointer) instead of the new head|Returns a pointer to the original first node (now the end of the list) instead of the new head (prev)|

Corrected function: SectionC/C1_reverse.c
Complexity: Time O(n), Space O(1)

## C2 Optimisation

| Metric | Details |
|---|---|
| Current Time Complexity| O(n^2) |
| Failure Reason | At n = 1,000,000, O(n^2) performs \approx 5 \times 10^{11} operations, far exceeding standard 1-second time limits (\approx 10^8 ops). |
| Valid Input Condition | All array elements must be non-negative so that expanding the right boundary strictly increases the sum, allowing the left boundary to move forward monotonically without backtracking. |

Corrected function: SectionC/C2_window.c
Complexity: Time O(n), Space O(1)