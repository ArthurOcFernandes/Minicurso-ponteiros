#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "adivinhacao.h"

int MAX_TENTATIVAS;


int main(){

    int tentativas = 0, numeroSecreto, ganhou = 0;

    numeroSecreto = sorteiaNumero();

    mostraMensagemInicial();

    do
    {
        int chute = chuta();
        tentativas++;
        if (chute == numeroSecreto){
            ganhou = 1;
            break;
        }

        printf(chute > numeroSecreto ? "O numero secreto eh menor que o chute.\n" : "O numero secreto eh maior que o chute.\n");

    } while (tentativas < MAX_TENTATIVAS);
    
    printf(ganhou ? "Parabens, voce acertou o numero secreto em %d tentativas": "Que pena, dessa vez nao deu pra descobrir o numero secreto =[. Que tal jogar novamente?", tentativas);

    return 0;
}

void mostraMensagemInicial(){

    printf("------------------------------------\n");
    printf("Boas vindas ao jogo da adivinhacao\n");
    printf("------------------------------------\n\n");
    printf("Deseja jogar em qual nivel de dificuldade?\n");
    printf("1 - FACIL\n");
    printf("2 - MEDIO\n");
    printf("3 - DIFICIL\n\n");

    defineDificuldade();
}

int sorteiaNumero(){
    srand(time(0));
    return rand() % 100 + 1;
}

int chuta(){
    int chute;
    printf("Digite seu chute: ");
    scanf("%d", &chute);
    return chute;
}


void defineDificuldade(){

    int nivelDificuldade;

    scanf("%d", &nivelDificuldade);

    if(nivelValido(nivelDificuldade)){
        switch (nivelDificuldade)
        {
        case 1:
            MAX_TENTATIVAS = 10;
            break;
        case 2:
            MAX_TENTATIVAS  = 5;
            break;
        case 3:
            MAX_TENTATIVAS = 3;
            break;
        }
    }
    
}

int nivelValido(int nivel){
    return nivel > 0 && nivel <= 3;
}

