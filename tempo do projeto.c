#include <time.h>
#include <stdio.h>
int main(){

int tempo = clock(); //come�a a contar o tempo

printf("Aguarde . . .");

while(clock() - tempo < 5000){ //enquanto n�o se passaram 5segundos

//printf("Mensagem para exibi��o enquanto repete ciclo");

}

printf("\n\nAguarde 5 segundos para o fechamento do programa");

tempo = clock();

while(clock() - tempo < 5000){ //enquanto n�o se passaram 5segundos

//printf("Mensagem para exibi��o enquanto repete ciclo");

}

}
