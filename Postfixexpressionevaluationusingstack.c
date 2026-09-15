#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push an element
void push(int value)
{
    stack[++top] = value;
}

// Pop an element
int pop()
{
    return stack[top--];
}

// Evaluate postfix expression
int evaluatePostfix(char postfix[])
{
    int i;
    char c;
    int a, b, result;

    for (i = 0; postfix[i] != '\0'; i++)
    {
        c = postfix[i];

        // If operand, push it into stack
        if (isdigit(c))
        {
            push(c - '0');
        }

        // If operator, perform operation
        else
        {
            b = pop();
            a = pop();

            switch (c)
            {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                case '%':
                    result = a % b;
                    break;

                default:
                    printf("Invalid operator!\n");
                    return -1;
            }

            push(result);
        }
    }

    return pop();
}

int main()
{
    char postfix[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    printf("Result = %d\n", evaluatePostfix(postfix));

    return 0;
}
