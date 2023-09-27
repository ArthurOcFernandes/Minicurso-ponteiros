#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "adivinhacao.h"



int main(){

    int tentativas = 0, maxTentativas, numeroSecreto, ganhou = 0, pontuacao = 1000;

    numeroSecreto = sorteiaNumero();

    mostraMensagemInicial();
    defineDificuldade(&maxTentativas);

    do
    {
        int chute = chuta();
        tentativas++;
        if (chute == numeroSecreto){
            ganhou = 1;
            break;
        }

        printf(chute > numeroSecreto ? "O numero secreto eh menor que o chute.\n" : "O numero secreto eh maior que o chute.\n");

    } while (tentativas < maxTentativas);
    
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

    //*maxTentativas = 100;
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

int nivelValido(int nivel){
    return nivel > 0 && nivel <= 3;
}

void defineDificuldade(int* maxTentativas){

    int nivelDificuldade;

    scanf("%d", &nivelDificuldade);

    if(nivelValido(nivelDificuldade)){
        switch (nivelDificuldade)
        {
        case 1:
            *maxTentativas = 10;
            break;
        case 2:
            *maxTentativas  = 5;
            break;
        case 3:
            *maxTentativas = 3;
            break;
        }
    }
    
}

