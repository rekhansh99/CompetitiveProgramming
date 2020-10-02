#include <stdio.h>
#include <string.h>
#define max 50
int precedence(char sym)
{
    switch (sym)
    {
    case '$':return 0;
    case '(':return 1;
    case '+':return 2;
    case '-':return 2;
    case '*':return 3;
    case '/':return 3;
    case '^':return 4;
    default :return -1;
    }
}
void push(char op, char stack[], int *top)
{
    if (*top < max - 1)
        stack[++(*top)] = op;
}
char pop(char stack[], int *top)
{
    if (*top >= 0)
        return stack[(*top)--];
}
void postfixGenerator(char infix[], char postfix[])
{
    char stack[max];
    int top = -1;
    push('$', stack, &top);
    int i, j = 0;
    for (i = 0; i < strlen(infix); i++)
    {
        if (infix[i] >= 'a' && infix[i] <= 'z')
            postfix[j++] = infix[i];
        else if (infix[i] == '(')
            push('(', stack, &top);
        else if (infix[i] == ')')
        {
            char temp = pop(stack, &top);
            while (temp != '(')
            {
                postfix[j++] = temp;
                temp = pop(stack, &top);
            }
        }
        else
        {
            char temp2 = pop(stack, &top);
            if (precedence(infix[i]) > precedence(temp2))
            {
                push(temp2, stack, &top);
                push(infix[i], stack, &top);
            }
            else
            {
                while (precedence(temp2) >= precedence(infix[i]))
                {
                    postfix[j++] = temp2;
                    temp2 = pop(stack, &top);
                }
                push(temp2, stack, &top);
                push(infix[i], stack, &top);
            }
        }
    }
    char temp3 = pop(stack, &top);
    while (top >= 0 )
    {
        postfix[j++] = temp3;
        temp3 = pop(stack, &top);
    }
}

int main()
{
    char str[max];
    scanf("%s", str);
    char res[max];
    postfixGenerator(str, res);
    int i;
    
        printf("%s", res);
    return 0;
}
