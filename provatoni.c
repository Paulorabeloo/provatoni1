#include<stdio.h>
#include<stdlib.h>
#include<string.h>

// Defini��o da estrutura do n� para uma lista duplamente encadeada
typedef struct no {
    int codigo;
    char nome[30];
    struct no *next;  // Apontador para o pr�ximo n�
    struct no *back;  // Apontador para o n� anterior
} no;

struct no *corrente, *inicio, *auxiliar, *auxiliar2, *fim; // Adicionado 'fim' para refer�ncia ao final da lista

// Fun��o para coletar dados do novo n�
void Enterdata() {
    printf("Informe o codigo: ");
    scanf("%d", &corrente->codigo);
    printf("Informe o nome: ");
    scanf("%s", corrente->nome);
}

// Fun��o para inserir elementos na lista de forma ordenada
void Classificar() {
    corrente = (no *)malloc(sizeof(no)); // Aloca mem�ria para o novo n�
    Enterdata(); // Coleta dados do n�

    auxiliar = inicio;

    if (inicio == NULL) { // Se a lista estiver vazia
        inicio = fim = corrente;
        corrente->next = corrente->back = NULL;
        printf("\nPrimeiro n� inserido na lista.\n");
    }
    else if (strcmp(corrente->nome, auxiliar->nome) < 0) { // Insere no in�cio
        corrente->next = auxiliar;
        corrente->back = NULL;
        auxiliar->back = corrente;
        inicio = corrente;
        printf("\nElemento inserido no in�cio da lista.\n");
    }
    else { // Insere no meio ou no final
        auxiliar2 = auxiliar->next;
        while (auxiliar2 != NULL && strcmp(corrente->nome, auxiliar2->nome) > 0) {
            auxiliar = auxiliar->next;
            auxiliar2 = auxiliar2->next;
        }

        corrente->next = auxiliar->next;
        corrente->back = auxiliar;
        auxiliar->next = corrente;

        if (corrente->next != NULL) {
            corrente->next->back = corrente; // Ajusta o anterior do pr�ximo n�
            printf("\nElemento inserido no meio da lista.\n");
        } else {
            fim = corrente; // Atualiza o fim da lista se for o �ltimo n�
            printf("\nElemento inserido no final da lista.\n");
        }
    }
}

// Fun��o para excluir elementos da lista
void Excluir() {
    char xnome[30];
    int achou = 0;

    if (inicio == NULL) { // Verifica se a lista est� vazia
        printf("\nLista vazia...\n");
    } else {
        printf("\nInforme o nome a ser exclu�do: ");
        scanf("%s", xnome);

        auxiliar = inicio;

        if (strcmp(xnome, auxiliar->nome) == 0) { // Excluir no in�cio
            inicio = inicio->next;
            if (inicio != NULL) {
                inicio->back = NULL;
            } else {
                fim = NULL; // Se a lista ficar vazia
            }
            free(auxiliar);
            printf("\nRegistro exclu�do no in�cio da lista.\n");
            achou = 1;
        } else {
            corrente = auxiliar->next;
            while (corrente != NULL) {
                if (strcmp(xnome, corrente->nome) == 0) { // Excluir no meio ou fim
                    auxiliar->next = corrente->next;
                    if (corrente->next != NULL) {
                        corrente->next->back = auxiliar;
                    } else {
                        fim = auxiliar; // Atualiza o fim se for o �ltimo n�
                    }
                    free(corrente);
                    printf("\nRegistro exclu�do com sucesso.\n");
                    achou = 1;
                    break;
                }
                auxiliar = auxiliar->next;
                corrente = corrente->next;
            }

            if (!achou) {
                printf("\nRegistro n�o encontrado na lista.\n");
            }
        }
    }
}

// Fun��o para exibir todos os elementos da lista
void Exibir() {
    if (inicio == NULL) {
        printf("\nLista vazia\n");
    } else {
        auxiliar = inicio;
        while (auxiliar != NULL) {
            printf("\nCodigo: %d", auxiliar->codigo);
            printf("\nNome: %s\n", auxiliar->nome);
            auxiliar = auxiliar->next;
        }
    }
    system("pause");
}

// Fun��o principal
int main() {
    inicio = fim = NULL;
    int op;
    do {
        system("cls");
        printf(" [1] Inserir elemento na lista\n");
        printf(" [2] Excluir elemento da lista\n");
        printf(" [3] Exibir elementos da lista\n");
        printf(" [4] Sair\n");
        printf("Digite a op��o desejada: ");
        scanf("%d", &op);

        switch (op) {
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
            printf("\nOp��o inv�lida, tente novamente.\n");
        }
    } while (op != 4);

    return 0;
}

