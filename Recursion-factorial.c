#include <stdio.h>

// Recursive function to calculate factorial
int factorial(int n)
{
    if (n == 0 || n == 1)
        return 1;
    else
        return n * factorial(n - 1);
}

int main()
{
    int n, result;

    printf("Enter a number: ");
    scanf("%d", &n);

    result = factorial(n);

    printf("Factorial of %d = %d\n", n, result);

    return 0;
}
