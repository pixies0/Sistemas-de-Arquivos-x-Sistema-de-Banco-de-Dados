#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Header.h"

int main(void)
{
    int op;
    do
    {
        puts("\n0 - Sair\n1 - Cadastrar\n2 - Imprimir\n3 - Salvar em Arquivo\n4 - Alterar Registro\n5 - Remover Registro");
        scanf("%d", &op);
        switch (op)
        {
        case 0:
            puts("Tchau...\n");
            break;
        case 1:
            cadastrar();
            break;
        case 2:
            imprimiVetor();
            break;
        case 3:
            salvarArq();
            break;
        case 4:
            altera();
            break;
        case 5:
            remover();
            break;
        default:
            puts("Opção Invalida.\n\n");
        }
    } while (op != 0);

    return 0;
}
