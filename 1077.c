/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Pedro Martineli
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1077
Data        : 11/10/2026
Objetivo    : Usando pilha converter infixo pra posfixo
Dificuldade : -
-------------------------------------------------------------------------- */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    char value;
    struct Node *next;
} Node;

Node *head = NULL;

void push(char value)
{
    Node *node = malloc(sizeof(Node));
    node->value = value;
    node->next = head;
    head = node;
}

char pop()
{
    if (head == NULL)
        return '\0';

    Node *node = head;
    char value = node->value;
    head = node->next;
    free(node);
    return value;
}

char top() { return head ? head->value : '\0'; }

int prec(char op)
{
    switch (op)
    {
    case '^':
        return 3;
    case '*':
    case '/':
        return 2;
    case '+':
    case '-':
        return 1;
    default:
        return 0;
    }
}

void printPostfix(char *expr)
{
    for (int i = 0; expr[i] != '\0'; i++)
    {
        char c = expr[i];

        if (isalnum(c))
        {
            putchar(c);
        }
        else if (c == '(')
        {
            push(c);
        }
        else if (c == ')')
        {
            while (head != NULL && top() != '(')
            {
                putchar(pop());
            }
            pop();
        }
        else if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
        {
            while (head != NULL && top() != '(')
            {
                int priority = prec(top());
                if (priority < prec(c) || (c == '^' && priority == prec(c)))
                    break;

                putchar(pop());
            }
            push(c);
        }
    }

    while (head != NULL)
    {
        putchar(pop());
    }
    putchar('\n');
}

int main(void)
{
    int t;
    char expr[305];

    scanf("%d", &t);

    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    while (t--)
    {
        if (fgets(expr, sizeof(expr), stdin))
        {
            expr[strcspn(expr, "\r\n")] = '\0';
            printPostfix(expr);
        }
    }
    return 0;
}
