#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <conio.h>
#include <stdlib.h>

int le_valida_idade();

void bubble_sort(struct Estudante estudante[14], int n);

struct Professor {
    char nome[50];
    int funcional;
    int titulacao;
};

struct Disciplina {
    char nome[50];
    char codigo[20];
    int carga_horaria;
    char professor_responsavel[50];
};

struct Estudante {
    char nome[50];
    char matricula[20];
    int idade;
    char disciplina[50];
};

int main() {
    setlocale(LC_ALL,"Portuguese");

    int i = 0;
    int aux = 0;
    int j = 0;
    int p = 0;

    struct Professor professor[2];
    struct Disciplina disciplina[1];
    struct Estudante estudante[14];

    for(i = 0; i < 3; i++) {
        system("cls");
        printf("\n|=CADASTRO PROFESSOR=|\n");
        printf("|======== %d =========|\n\n", i+1);

        printf("|--------Nome--------|\n\n> ");
        fflush(stdin);
        fgets(professor[i].nome, 50, stdin);
        system("cls");

        do {
            printf("\n|=CADASTRO PROFESSOR=|\n");
            printf("|======== %d =========|\n\n", i+1);
            printf("|------Funcional-----|\n|-Selecione a opção--|\n");
            printf("\n\n(1)-Ativo\n(2)-Desligado\n(3)-Afastado\n\n>");
            fflush(stdin);
            scanf("%d", &professor[i].funcional);
            if(professor[i].funcional < 1 || professor[i].funcional > 3) {
                printf("\n|---Opção inválida!--|");
            }
        } while(professor[i].funcional < 1 || professor[i].funcional > 3);
        system("cls");

        do {
            printf("\n|=CADASTRO PROFESSOR=|\n");
            printf("|======== %d =========|\n\n", i+1);
            printf("|-----Titulacao------|\n|-Selecione a opção--|\n");
            printf("\n\n(1)-Doutor\n(2)-Especialista\n(3)-Mestre\n\n>");
            fflush(stdin);
            scanf("%d", &professor[i].titulacao);
            if(professor[i].titulacao < 1 || professor[i].titulacao > 3) {
                printf("\n|---Opção inválida!--|");
            }
        } while(professor[i].titulacao < 1 || professor[i].titulacao > 3);
    }

    for(j = 0; j < 2; j++) {
        system("cls");
        printf("|=CADASTRO DISCIPLINA=|\n");
        printf("|======== %d ==========|\n\n", j+1);
        printf("|--------Nome---------|\n\n> ");
        fflush(stdin);
        fgets(disciplina[j].nome, 50, stdin);
        system("cls");

        printf("\n|=CADASTRO DISCIPLINA=|\n");
        printf("|======== %d ==========|\n\n", j+1);
        printf("|-------Código--------|\n\n> ");
        fflush(stdin);
        fgets(disciplina[j].codigo, 20, stdin);
        system("cls");

        printf("\n|=CADASTRO DISCIPLINA=|\n");
        printf("|======== %d ==========|\n\n", j+1);
        printf("|----Carga horaria----|\n\n> ");
        fflush(stdin);
        scanf("%d", &disciplina[j].carga_horaria);
        system("cls");

        int opcaoP = 0;
        do {
            printf("\n|=CADASTRO DISCIPLINA=|\n");
            printf("|======== %d ==========|\n\n", j+1);
            printf("|--Prof. responsavel--|\n\n");
            fflush(stdin);
            for(p = 0; p < i; p++) {
                fflush(stdin);
                printf("(%d) %s", p+1, professor[p].nome);
            }
            printf(">");
            scanf("%d", &opcaoP);
            if(opcaoP < 1 || opcaoP > 3) {
                printf("\n|---Opção inválida!--|\n");
            } else {
                strcpy(disciplina[j].professor_responsavel, professor[opcaoP - 1].nome);
            }
        } while(opcaoP < 1 || opcaoP > 3);
        system("cls");
    }
    
    for(j = 0; j < 15; j++) {
        printf("---Cadastro de Estudante---\n");
        printf("Nome do aluno:");
        fflush(stdin);
        fgets(estudante[j].nome, 50, stdin);

        printf("Matricula:");
        fflush(stdin);
        fgets(estudante[j].matricula, 20, stdin);

        le_valida_idade();
    }
    
    bubble_sort(estudante, 15);
    
    return 0;
}

int le_valida_idade() {
    int idade = 0;

    do {
        printf("Digite a idade do estudante: ");
        scanf("%d", &idade);
        if(idade <= 16 || idade >= 26) {
            printf("\n\nIdade inválida!\n\n");
        }
    } while(idade <= 16 || idade >= 26);
    
    return idade;
}

void bubble_sort(struct Estudante estudante[], int n) {
    int i, j;
    struct Estudante temp;

    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(estudante[j].idade > estudante[j+1].idade) {
                temp = estudante[j];
                estudante[j] = estudante[j+1];
                estudante[j+1] = temp;
            }
        }
    }
}
