#include <stdio.h>
#include <math.h>
int main() {
int n;
printf("Enter value of n (power of 2 recommended): ");
scanf("%d", &n);
FILE *file = fopen("recursion_tree_output.txt", "w");
if (file == NULL) {
printf("Error creating file!\n");
return 1;}
printf("\nRecursion Tree for T(n) = 2T(n/2) + n^2\n");
printf("------------------------------------------------------------\n");
printf("Level\tSubproblems\tSubproblem Size\tCost at Level\n");
printf("------------------------------------------------------------\n");
fprintf(file, "Recursion Tree for T(n) = 2T(n/2) + n^2\n");
fprintf(file, "------------------------------------------------------------\n");
fprintf(file, "Level\tSubproblems\tSubproblem Size\tCost at Level\n");
fprintf(file, "------------------------------------------------------------\n");
int level = 0;
int subproblems = 1;
int size = n;
double totalCost = 0;
while (size >= 1) {
double costAtLevel = subproblems * pow(size, 2);
printf("%d\t%d\t\t%d\t\t%.0lf\n", level, subproblems, size, costAtLevel);
fprintf(file, "%d\t%d\t\t%d\t\t%.0lf\n", level, subproblems, size, costAtLevel);
totalCost += costAtLevel;
level++;
subproblems *= 2;
size /= 2;}
printf("------------------------------------------------------------\n");
printf("Total Cost T(n) = %.0lf\n", totalCost);
fprintf(file, "------------------------------------------------------------\n");
fprintf(file, "Total Cost T(n) = %.0lf\n", totalCost);
fclose(file);
printf("\nOutput saved to recursion_tree_output.txt\n");
return 0;
}

