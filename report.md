
# ALGORITHM BATTLE – WHICH DATA STRUCTURE WINS?

## Student Details
Name: Bompalli Sai Siddartha
Registration Number: RA2511026050157
Department: CSE (AI & ML)
College: SRM Institute of Science and Technology, Tiruchirappalli

## Part A – Problem Selection

### Application: Student Record Management System

Problem:
A college stores many student records. Searching for a student using their unique ID can take time if records are not organised properly.

Why efficient searching is required:
Efficient searching helps retrieve student information quickly and reduces the time required to find records.

Why BST, AVL and Hashing?
BST stores records in sorted order.
AVL maintains a balanced tree for faster searching.
Hashing uses a hash function to locate records quickly. Linear probing handles collisions.

## Part B – Implementation

The application is implemented using C++.

### 1. Binary Search Tree (BST)
- Each node stores a student ID.
- Smaller IDs are inserted on the left.
- Larger IDs are inserted on the right.
- Searching compares the key with each node.
- Inorder, Preorder and Postorder traversals are implemented.

### 2. AVL Tree
- AVL is a self-balancing Binary Search Tree.
- It maintains balance using rotations.
- Four rotations are implemented:
  - LL Rotation
  - RR Rotation
  - LR Rotation
  - RL Rotation
- Insertion and searching operations are implemented.
- Inorder traversal is implemented.

### 3. Hashing with Linear Probing
- A hash function calculates the initial index.
- If the position is occupied, the next position is checked.
- This process continues until an empty position is found.
- Searching follows the same probing sequence.

## Part C – Mini Experiment

Dataset: 40 unique student IDs (1001–1040).

Successful Search Key: 1020

Unsuccessful Search Key: 9999

Additional Insertion Key: 1050

### Experimental Observations

The same 40 records were inserted into all three data structures.

Successful Search:
- BST: 20 comparisons
- AVL: 4 comparisons
- Hashing: 20 comparisons

Unsuccessful Search:
- BST: 40 comparisons
- AVL: 6 comparisons
- Hashing: 37 comparisons

Insertion:
- A new student ID, 1050, was inserted successfully into all three structures.

## Part D – Algorithm Battle

| Parameter | BST | AVL | Hashing |
|---|---|---|---|
| Successful search comparisons | 20 | 4 | 20 |
| Unsuccessful search comparisons | 40 | 6 | 37 |
| Height | 40 | 6 | N/A |
| Collisions | N/A | N/A | 471 |
| Traversal | Supported | Supported | Not applicable |

### Overall Observation

BST became skewed because the records were inserted in sorted order.

AVL maintained a balanced structure and required fewer comparisons.

Hashing experienced a large number of collisions due to the selected hash function and dataset.

## Part E – Final Verdict

The AVL Tree is the winner for this experiment.

Reasons:
1. It required only 4 comparisons for successful searching.
2. It required only 6 comparisons for unsuccessful searching.
3. Its height was only 6 compared to BST height of 40.
4. It automatically maintains balance through rotations.

Therefore, AVL Tree is recommended for this student record application when predictable search performance and ordered traversal are important.

## Conclusion

Based on the experiment, Hashing performed the best for searching in our dataset because it required fewer comparisons. AVL Tree maintained a balanced structure with a height of 6, while BST became skewed with a height of 40. Therefore, Hashing is the winner for search efficiency in this experiment, while AVL is useful when ordered data traversal is required.