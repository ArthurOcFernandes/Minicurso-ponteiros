#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "adivinhacao.h"


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

    } while (tentativas < 3);
    
    printf(ganhou ? "Parabens, voce acertou o numero secreto em %d tentativas": "Que pena, dessa vez nao deu pra descobrir o numero secreto =[. Que tal jogar novamente?", tentativas);

    return 0;
}

void mostraMensagemInicial(){

    printf("------------------------------------\n");
    printf("Boas vindas ao jogo da adivinhacao\n");
    printf("------------------------------------\n\n");

}

int sorteiaNumero(){
    srand(time(0));
    return rand() % 10 + 1;
}

int chuta(){
    int chute;
    printf("Digite seu chute: ");
    scanf("%d", &chute);
    return chute;
}
