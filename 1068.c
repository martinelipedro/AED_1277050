/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Pedro Martineli
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1068
Data        : 11/10/2026
Objetivo    : Verificar o balanceamento de parenteses via stack
Dificuldade : -
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct NODE_STRUCT
{
    struct NODE_STRUCT *next;
    char value;
} Node;

#define BUFFER 1002

Node *head = NULL;
int size = 0;

void stack_push(char x)
{
    Node *node = (Node *)malloc(sizeof(Node));
    node->value = x;
    node->next = head;
    head = node;
    size++;
}

char stack_pop()
{
    if (size == 0)
        return -1;

    Node *node = head;
    head = head->next;

    char x = node->value;
    free(node);
    size--;

    return x;
}

char stack_front()
{
    if (size == 0)
        return -1;

    return head->value;
}

void stack_clear()
{
    while (size > 0) stack_pop();
}

int main()
{
    char buffer[BUFFER];
    while (fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        stack_clear();
        if (strcmp(buffer, "\n") == 0)
            break;

        int valid = 1;
        for (int i = 0; buffer[i] != '\0'; ++i)
        {
            int c = buffer[i];
            if (c != '(' && c != ')')
                continue;

            if (c == '(')
                stack_push('(');
            else
            {
                int front = stack_front();
                if (front == -1 || front != '(')
                {
                    printf("incorrect\n");
                    valid = 0;
                    break;
                }
                else
                {
                    stack_pop();
                }
            }
        }
        if (size != 0)
        {
            printf("incorrect\n");
        }
        else if (valid)
            printf("correct\n");
    }
}