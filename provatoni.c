#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct no
{
    int codigo;
    char nome[30];
    struct no *next;
} no;

struct no *corrente, *inicio, *auxiliar, *auxiliar2;

void Enterdata()
{
    printf("Informe o codigo: ");
    scanf("%d", &corrente->codigo);
    printf("Informe o nome: ");
    scanf("%s", corrente->nome);
}

void Classificar()
{
    corrente = (no *)malloc(sizeof(no));
    Enterdata();

    auxiliar = inicio;

    if (inicio == NULL)
    {
        inicio = corrente;
        corrente->next = NULL;
        printf("\nPrimeiro nó inserido na lista.\n");
    }
    else if (strcmp(corrente->nome, auxiliar->nome) < 0)
    {
        corrente->next = auxiliar;
        inicio = corrente;
        printf("\nElemento inserido no início da lista.\n");
    }
    else
    {
        auxiliar2 = auxiliar->next;
        while (auxiliar2 != NULL && strcmp(corrente->nome, auxiliar2->nome) > 0)
        {
            auxiliar = auxiliar->next;
            auxiliar2 = auxiliar2->next;
        }

        corrente->next = auxiliar->next;
        auxiliar->next = corrente;

        if (corrente->next == NULL)
        {
            printf("\nElemento inserido no final da lista.\n");
        }
        else
        {
            printf("\nElemento inserido no meio da lista.\n");
        }
    }
}

void Excluir()
{
    char xnome[30];
    int achou = 0;

    if (inicio == NULL)
    {
        printf("\nLista vazia...\n");
    }
    else
    {
        printf("\nInforme o nome a ser excluído: ");
        scanf("%s", xnome);

        auxiliar = inicio;

        if (strcmp(xnome, auxiliar->nome) == 0)
        {
            inicio = inicio->next;
            free(auxiliar);
            printf("\nRegistro excluído no início da lista.\n");
            achou = 1;
        }
        else
        {
            corrente = auxiliar->next;
            while (corrente != NULL)
            {
                if (strcmp(xnome, corrente->nome) == 0)
                {
                    auxiliar->next = corrente->next;
                    free(corrente);
                    printf("\nRegistro excluído com sucesso.\n");
                    achou = 1;
                    break;
                }
                auxiliar = auxiliar->next;
                corrente = corrente->next;
            }

            if (!achou)
            {
                printf("\nRegistro não encontrado na lista.\n");
            }
        }
    }
}

void Exibir()
{
    if (inicio == NULL)
    {
        printf("\nLista vazia");
        system("pause");
    }
    else
    {
        auxiliar = inicio;
        while (auxiliar != NULL)
        {
            printf("\nCodigo: %d", auxiliar->codigo);
            printf("\nNome: %s\n", auxiliar->nome);
            system("pause");
            auxiliar = auxiliar->next;
        }
    }
}

int main()
{
    inicio = NULL;
    int op;
    do
    {
        system("cls");
        printf(" [1] Inserir elemento na lista\n");
        printf(" [2] Excluir elemento da lista\n");
        printf(" [3] Exibir elementos da lista\n");
        printf(" [4] Sair\n");
        printf("Digite a opção desejada: ");
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            Classificar();
            break;

        case 2:
            Excluir();
            break;

        case 3:
            Exibir();
            break;

        case 4:
            printf("\nSaindo...\n");
            break;

        default:
            printf("\nOpção inválida, tente novamente.\n");
        }
    } while (op != 4);

    return 0;
}

