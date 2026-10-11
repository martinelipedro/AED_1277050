/* --------------------------------------------------------------------------
Disciplina  : Algortimo e Estrutura de Dados 2026S1
Nome        : Pedro Martineli
Linguagem   : C
Problema    : https://judge.beecrowd.com/pt/problems/view/1110
Data        : 11/10/2026
Objetivo    : Lista ligada utilizadas para o descarte
Dificuldade : Tranquilo.
-------------------------------------------------------------------------- */

#include <stdio.h>
#include <stdlib.h>

typedef struct NODE_STRUCT
{
    int card;
    struct NODE_STRUCT *next;
} Node;

int main()
{
    int n;

    while (scanf("%d", &n) == 1 && n != 0)
    {
        Node *head = NULL, *tail = NULL;
        int size = 0;

        for (int i = 1; i <= n; ++i)
        {
            Node *node = calloc(1, sizeof(Node));
            node->card = i;
            if (size == 0)
            {
                head = node, tail = node;
            }
            else
            {
                tail->next = node;
                tail = node;
            }
            size++;
        }

        int *discarded = malloc(n * sizeof(int));
        int idx = 0;
        while (size >= 2)
        {
            Node *discarded_node = head;
            discarded[idx++] = discarded_node->card;
            head = head->next;
            free(discarded_node);
            size--;

            if (size >= 2)
            {
                Node *move_node = head;
                head = head->next;
                tail->next = move_node;
                tail = move_node;
                tail->next = NULL;
            }
        }

        printf("Discarded cards:");
        for (int i = 0; i < idx; ++i)
        {
            if (i == 0)
                printf(" %d", discarded[i]);
            else
                printf(", %d", discarded[i]);
        }
        printf("\n");
        if (head != NULL)
        {
            printf("Remaining card: %d\n", head->card);
            free(head);
        }

        free(discarded);
    }

    return 0;
}