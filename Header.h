/*  ---------------------------------------------------------------------------
    UNIVERSIDADE FEDERAL DO TOCANTINS - UFT
    Aplicação para manipulação de arquivos - BANCO DE DADOS 2022.1
    Aluno : João Pedro Silva Cunha.
    Palmas - TO
    Matricula: 2019214925.
----------------------------------------------------------------------------  */

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#define HEADER_H

/* ---------------------------------------------------------
    Definicao das estruturas:
 ---------------------------------------------------------*/

typedef struct disciplina      /* Tipo tDisciplina: */
{                              /* Dados relativos a tabela disciplina */
    char nomeDisciplina[40];   // Nome da disciplina, exe.: Estrutura de Dados 1
    char codigoDisciplina[15]; // Numero da disciplina, exe.: CCOMP3304
    int chDisciplina;          // Carga horaria da disciplina, exe.: 60h
} tDisciplina;

tDisciplina Disciplina[100];

typedef struct turma       /* Tipo tTurma: */
{                          /* Dados relativos a tabela turma */
    int idTurma;           // ID da disciplina, exe.: 120
    char turnoTurma[15];   // Turno da turma, exe.: Vespertino
    char docenteTurma[15]; // Docente da turma, exe.: Algusto
    char codigoDisciplina[15];
} tTurma;

tTurma Turma[100];

typedef struct historico /* Tipo tHistorico: */
{                        /* Dados relativos a tabela historico */
    int numeroAluno;     // Numero do aluno, exe.: 20
    float notaFinal;     // Nota final do aluno, exe.: 8.5
    int idTurma;
} tHistorico;

tHistorico Historico[100];

// VARIAVEIS GLOBAIS USADAS PARA FAZER CONTAGEM E USAR COMO INDICES PRINCIPALMENTE NO MOMENTO DO CADASTRO E REMOÇÃO DAS INFORMAÇÕES.
int tam = 100;
int quantDis = 1;
int quantTurma = 1;
int quantHist = 1;

/*Função responsavel por cadastrar(inserir dados coletados): Disciplinas, Turmas e Historicos por meio
de um Vetor Estatico e Estruturas de dados.*/

int cadastrar()
{

    int op;

    printf("\n\nDeseja Cadastrar:\n1 - Disciplina\n2 - Turma\n3 - Historico\n0 - Sair\n\n");
    scanf("%d", &op);
    switch (op)
    {
    case 1:

        if (quantDis < tam)
        {

            tDisciplina Dis;
            scanf("%*c");
            printf("Nome da Disciplina: ");
            fgets(Dis.nomeDisciplina, 50, stdin);
            printf("Digite o Codigo da Disciplina: ");
            scanf("%s", &Dis.codigoDisciplina);
            printf("Digite a carga horaria: ");
            scanf("%d", &Dis.chDisciplina);
            Disciplina[quantDis] = Dis;
            quantDis++;
            return 1;
        }
        else
        {
            printf("ERROR: Vetor Cheio...\n");
            return 0;
        }
        break;

    case 2:

        if (quantTurma < tam)
        {

            tTurma Tur;
            scanf("%*c");
            printf("Id da Turma: ");
            scanf("%d", &Tur.idTurma);
            printf("Turno da turma: ");
            scanf("%s", &Tur.turnoTurma);
            printf("Professor: ");
            scanf("%s", &Tur.docenteTurma);
            printf("Codigo da Disciplina: ");
            scanf("%s", &Tur.codigoDisciplina);
            Turma[quantTurma] = Tur;
            quantTurma++;
            return 1;
        }
        else
        {
            printf("ERROR: Vetor cheio...\n");
            return 0;
        }
        break;

    case 3:

        if (quantHist < tam)
        {

            tHistorico His;
            scanf("%*c");
            printf("Numero do estudante: ");
            scanf("%d", &His.numeroAluno);
            printf("Id da Turma: ");
            scanf("%d", &His.idTurma);
            printf("Nota final: ");
            scanf("%f", &His.notaFinal);
            Historico[quantHist] = His;
            quantHist++;
            return 1;
        }
        else
        {
            printf("ERROR: Vetor cheio...\n");
            return 0;
        }
        break;
    }
}
/*Função responsavel por abrir o arquivo *dat e alterar, fazendo assim uma atualização dos dados por
por meio de laços condicionais e ponteiros com indices quem se relacionam com as estrutura de dados*/

int altera()
{

    FILE *arq = fopen("Database.dat", "w");
    int op;

    if (arq)
    {
        printf("Deseja alterar:\n1 - Disciplina\n2 - Turma\n3 - Historico\n");
        scanf("%d", &op);

        switch (op)
        {

            int num, op2;
        case 1:
            printf("\n\nQual registro deseja alterar: ");
            scanf("%d", &num);
            printf("\nDeseja alterar qual campo:\n1 - Nome\n2 - Codigo\n3 - Carga horaria\n\n");
            scanf("%d", &op2);

            if (op2 == 1)
            {
                printf("Nome da Disciplina Atualizado: ");
                scanf("%s", &Disciplina[num].nomeDisciplina);
            }
            else if (op2 == 2)
            {
                printf("Codigo Atualizado: ");
                scanf("%s", &Disciplina[num].codigoDisciplina);
            }
            else if (op2 == 3)
            {
                printf("Carga Horaria Atualizada: ");
                scanf("%d", &Disciplina[num].chDisciplina);
            }
            break;
        case 2:

            printf("Qual registro deseja alterar: ");
            scanf("%d", &num);
            printf("Deseja alterar qual campo:\n1 - Id\n2 - Codigo\n3 - Turno\n4 - Docente\n\n");
            scanf("%d", &op2);

            if (op2 == 1)
            {
                printf("Id da Turma atualizado: ");
                scanf("%d", &Turma[num].idTurma);
            }
            else if (op2 == 2)
            {
                printf("Codigo da Turma atualizado: ");
                scanf("%s", &Turma[num].codigoDisciplina);
            }
            else if (op2 == 3)
            {
                printf("Turno da Turma atualizado: ");
                scanf("%s", &Turma[num].turnoTurma);
            }
            else if (op2 == 4)
            {
                printf("Docente da Turma atualizado: ");
                scanf("%s", &Turma[num].docenteTurma);
            }
            break;
        case 3:

            printf("Qual registro deseja alterar: ");
            scanf("%d", &num);
            printf("Deseja alterar qual campo:\n 1 - N° do aluno\n2 - Id\n3 - Nota final\n\n");
            scanf("%d", &op2);

            if (op2 == 1)
            {
                printf("Numero do aluno atualizado: ");
                scanf("%d", &Historico[num].numeroAluno);
            }
            else if (op2 == 2)
            {
                printf("Id da turma atualizado: ");
                scanf("%d", &Historico[num].idTurma);
            }
            else if (op2 == 3)
            {
                printf("Nota final atualiza: ");
                scanf("%f", &Historico[num].notaFinal);
            }
        }
        return 1;
    }
    else
    {
        puts("Arquivo com problemas!");
    }
    fclose(arq);
}
/*Função Responsavel por imprimir dentro do proprio programa os dados desejados por meio de acesso direto
com indice coletado pelo usuario com antecedencia por meio de alguns laços de repetiçoes e condicionais.*/

void imprimiVetor()
{

    int i, j, k;
    int op, op2, num;
    printf("Deseja Vizualizar:\n0 - Sair\n1 - Disciplinas\n2 - Turmas\n3 - Historicos\n\n");
    scanf("%d", &op);

    switch (op)
    {
        printf("--------------------------------------------------------------------------------------\n");
    case 0:
        puts("Saindo...");
        break;
    case 1:

        printf("Qual registro: ");
        scanf("%d", &num);
        do
        {
            printf("Qual atributo:\n0 - Sair\n1 - Nome\n2 - Codigo\n3 - Carga horaria\n");
            scanf("%d", &op2);
            printf("-------------------------------------------------------------------------------------");

            printf("\nNumero do Registro de Disciplina: %d\n", num);

            if (op2 == 1)
            {
                printf("Nome: %s  \n", Disciplina[num].nomeDisciplina);
                printf("---------------------------------------------------------------------------------\n");
            }
            else if (op2 == 2)
            {
                printf("Codigo: %s  \n", Disciplina[num].codigoDisciplina);
                printf("----------------------------------------------------------------------------------\n");
            }
            else if (op2 == 3)
            {
                printf("CargaHoraria: %d\n\n", Disciplina[num].chDisciplina);
                printf("----------------------------------------------------------------------------------\n");
            }
            else
                break;

        } while (op2 != 0);

        printf("-----------------------------------------------------------------------------------\n");
        break;

    case 2:

        printf("Qual registro: ");
        scanf("%d", &num);
        do
        {
            printf("Qual atributo:\n0 - Sair\n1 - Id\n2 - Turno\n3 - Docente\n4 - Codigo da turma\n");
            scanf("%d", &op2);
            printf("-----------------------------------------------------------------------------------------\n");

            printf("\nNumero do Registro de Turma: %d\n", num);

            if (op2 == 1)
            {
                printf("Id da Turma: %d\n", Turma[num].idTurma);
                printf("----------------------------------------------------------------------------------\n");
            }
            else if (op2 == 2)
            {
                printf("Turno: %s\n", Turma[num].turnoTurma);
                printf("----------------------------------------------------------------------------------\n");
            }
            else if (op2 == 3)
            {
                printf("Docente: %s\n", Turma[num].docenteTurma);
                printf("----------------------------------------------------------------------------------\n");
            }
            else if (op2 == 4)
            {
                printf("Codigo da Turma: %s\n\n", Turma[num].codigoDisciplina);
                printf("----------------------------------------------------------------------------------\n");
            }
            else
                break;

        } while (op2 != 0);

        printf("---------------------------------\n");
        break;

    case 3:

        printf("Qual registro: ");
        scanf("%d", &num);
        do
        {
            printf("Qual atributo:\n0 - Sair\n1 - Numero do aluno\n2 - Id da Turma\n3 - Nota final\n");
            scanf("%d", &op2);
            printf("-----------------------------------------------------------------------------\n");

            printf("Numero do Registro de Historico: %d\n", num);

            if (op2 == 1)
            {
                printf("Numero do aluno: %d\n", Historico[num].numeroAluno);
                printf("----------------------------------------------------------------------------------\n");
            }
            else if (op2 == 2)
            {
                printf("Id da Turma: %d\n", Historico[num].idTurma);
                printf("----------------------------------------------------------------------------------\n");
            }
            else if (op2 == 3)
            {
                printf("Nota final: %.2f\n\n", Historico[num].notaFinal);
                printf("----------------------------------------------------------------------------------\n");
            }
            else
                break;

        } while (op2 != 0);

        printf("----------------------------------------------------------------------------------\n");
        break;
    }
}

/*Função responsavel por abrir o arquivo *dat e gravar os dados cadastros até o respectivo momento, se
for realizado alterações(inserir novos dados, remover ou alterar os ja existentes) é necessario
salvar novamente... por meio de um laço de repetição que percorre todas as tabelas e atributos existentes
com seus indices e ponteiros ela exerce sua função*/
void salvarArq()
{

    FILE *arq = fopen("Database.dat", "w");
    int i, j, k;
    if (arq)
    {

        fprintf(arq, "N° de Disciplinas: %d\n", quantDis - 1);
        fprintf(arq, "N° de Turmas: %d\n", quantTurma - 1);
        fprintf(arq, "N° de Historicos: %d\n\n", quantHist - 1);
        fprintf(arq, "----------------------\n");

        for (i = 1; i < quantDis; i++)
        {

            fprintf(arq, "Numero do Registro de Disciplina: %d\n\n", i);
            fprintf(arq, "Nome: %s", Disciplina[i].nomeDisciplina);
            fprintf(arq, "%s - Codigo\n", Disciplina[i].codigoDisciplina);
            fprintf(arq, "%d - CargaHoraria\n\n", Disciplina[i].chDisciplina);
            fprintf(arq, "----------------------\n");
        }
        for (j = 1; j < quantTurma; j++)
        {

            fprintf(arq, "Numero do Registro de Turma: %d\n\n", j);
            fprintf(arq, "Id da Turma: %d\n", Turma[j].idTurma);
            fprintf(arq, "Turno: %s\tDocente: %s\n", Turma[j].turnoTurma, Turma[j].docenteTurma);
            fprintf(arq, "Codigo da Turma: %s\n\n", Turma[j].codigoDisciplina);
            fprintf(arq, "----------------------\n");
        }
        for (k = 1; k < quantHist; k++)
        {

            fprintf(arq, "Numero do Registro de Alunos: %d\n\n", k);
            fprintf(arq, "Numero do aluno: %d\n", Historico[k].numeroAluno);
            fprintf(arq, "Id da Turma: %d\tNota final: %.2f\n\n", Historico[k].idTurma, Historico[k].notaFinal);
            fprintf(arq, "----------------------\n");
        }
        fclose(arq);
    }
    else
        printf("ERROR: nao foi possivel abrir o arquivo.\n\n");
}

/*Função responsavel por remover registros completos dos dados existentes a cerca de Disciplina, Turma ou
Historico... o seguinte algoritmo vai funcionar como uma transcrição de dados por meio de reposicionamento
das informações*/
int remover()
{
    FILE *arq = fopen("Database.dat", "w");
    int op, num, i, j;

    if (arq)
    {
        printf("Deseja remover:\n1 - Disciplina\n2 - Turma\n3 - Historico\n");
        scanf("%d", &op);

        switch (op)
        {
        case 1:

            printf("Qual registro deseja remover: ");
            scanf("%d", &num);
            for (i = 1; i < quantDis; i++)
            {
                if (i == num)
                {
                    for (j = i; j < quantDis; j++)
                    {
                        Disciplina[j] = Disciplina[j + 1];
                    }
                }
            }
            quantDis--;
            return 1;
            break;

        case 2:

            printf("Qual registro deseja remover: ");
            scanf("%d", &num);
            for (i = 1; i < quantTurma; i++)
            {
                if (i == num)
                {
                    for (j = i; j < quantTurma; j++)
                    {
                        Turma[j] = Turma[j + 1];
                    }
                }
            }
            quantTurma--;
            return 1;

        case 3:

            printf("Qual registro deseja remover: ");
            scanf("%d", &num);
            for (i = 1; i < quantHist; i++)
            {
                if (i == num)
                {
                    for (j = i; j < quantHist; j++)
                    {
                        Historico[j] = Historico[j + 1];
                    }
                }
            }
            quantTurma--;
            return 1;

        default:
            puts("Opcao invalida");
            break;
        }
    }
    else
    {
        puts("Problema ao abrir o arquivo");
        return 0;
    }
    fclose(arq);
}
