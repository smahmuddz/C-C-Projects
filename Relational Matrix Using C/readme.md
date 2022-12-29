# Relational Matrix Properties Problem

```c
**Problem Statement:**
1. Using C program, randomly generate a relational matrix with dimension n where n is the number of distinct element on a set
2. Verify the properties of the relation; such as symmetric, antisymmetric, transitive and equivalence etc. Determine computational time in this step
   (except printing time) in miliseconds.
```

# Explanation of the Code

 

This code generates a square matrix of size n x n and fills it with random 0s and 1s. It then checks if the matrix is reflexive, symmetric, transitive, and an equivalence relation. It also checks if the matrix is anti-symmetric.

The following is a brief explanation of each step in the code:

1. The necessary headers are included:
    - stdio.h: for input and output functions (e.g., printf, scanf)
    - stdlib.h: for rand and srand functions
    - time.h: for clock function
    - math.h: for pow function
2. A 2D array 'mat' is defined to store the matrix.
3. The main function starts. The variable n is declared and initialized by asking the user to input the column dimension of the matrix.
4. The variables 'total_time', 'start', and 'end' are declared to measure the execution time of the program. The variable 'start' is initialized with the current clock time.
5. A nested loop is used to fill the matrix 'mat' with random 0s and 1s.
6. Another nested loop is used to print the matrix.
7. The matrix is checked for reflexivity by using a loop to check if each element on the main diagonal (i.e., mat[i][i] for all i) is 1. If any element is 0, the matrix is not reflexive.
8. The matrix is checked for symmetry by using a nested loop to check if each element mat[i][j] is equal to its corresponding element mat[j][i]. If any element is not equal, the matrix is not symmetric.
9. The matrix is checked for transitivity by using a nested loop to check if the following condition holds for all i, j, and k: if mat[i][j] and mat[j][k] are both 1, then mat[k][i] must also be 1. If the condition is not satisfied for any i, j, and k, the matrix is not transitive.
10. If the matrix is not reflexive, symmetric, or transitive, it is not an equivalence relation.
11. The matrix is checked for anti-symmetry by using a nested loop to check if each element mat[i][j] is equal to -mat[j][i]. If any element is equal, the matrix is anti-symmetric.
12. The reflexivity, symmetry, transitivity, and equivalence of the matrix are printed.
13. The anti-symmetry of the matrix is printed.
14. The execution time of the program is measured and printed.
15. The main function ends and returns 0.

# Time Complexity Analysis

The time complexity of the code can be analyzed as follows:

1. The loop to fill the matrix with random values has a time complexity of O(n^2).
2. The loop to print the matrix has a time complexity of O(n^2).
3. The loop to check for reflexivity has a time complexity of O(n).
4. The nested loop to check for symmetry has a time complexity of O(n^2).
5. The nested loop to check for transitivity has a time complexity of O(n^3).
6. The nested loop to check for anti-symmetry has a time complexity of O(n^2).

Therefore, the overall time complexity of the code is O(n^3). This means that the time taken by the code increases cubically with the size of the matrix.

Note that this is a rough estimate of the time complexity and the actual time taken by the code may vary depending on various factors such as the hardware and software environment.

The time complexity of the code can be expressed as an equation as follows:

T(n) = O(n^3)

where T(n) is the time taken by the code for a matrix of size n x n, and O(n^3) is the time complexity of the code.