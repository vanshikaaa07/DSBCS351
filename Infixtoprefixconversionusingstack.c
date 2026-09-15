#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

char stack[MAX];
int top = -1;

// Push
void push(char c)
{
    stack[++top] = c;
}

// Pop
char pop()
{
    return stack[top--];
}

// Precedence
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return 0;
}

// Reverse a string
void reverse(char str[])
{
    int i, j;
    char temp;

    for (i = 0, j = strlen(str) - 1; i < j; i++, j--)
    {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
    }
}

// Infix to Prefix
void infixToPrefix(char infix[], char prefix[])
{
    int i, j = 0;
    char c;

    // Step 1: Reverse infix expression
    reverse(infix);

    // Step 2: Replace '(' with ')' and vice versa
    for (i = 0; infix[i] != '\0'; i++)
    {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    // Step 3: Convert reversed expression to postfix
    for (i = 0; infix[i] != '\0'; i++)
    {
        c = infix[i];

        // Operand
        if (isalnum(c))
        {
            prefix[j++] = c;
        }

        // Opening bracket
        else if (c == '(')
        {
            push(c);
        }

        // Closing bracket
        else if (c == ')')
        {
            while (top != -1 && stack[top] != '(')
            {
                prefix[j++] = pop();
            }
            pop(); // Remove '('
        }

        // Operator
        else
        {
            while (top != -1 &&
                   stack[top] != '(' &&
                   precedence(stack[top]) > precedence(c))
            {
                prefix[j++] = pop();
            }

            push(c);
        }
    }

    // Pop remaining operators
    while (top != -1)
    {
        prefix[j++] = pop();
    }

    prefix[j] = '\0';

    // Step 4: Reverse postfix to get prefix
    reverse(prefix);
}

int main()
{
    char infix[MAX], prefix[MAX];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infixToPrefix(infix, prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
