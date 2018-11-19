//Declara��o das bibliotecas
#include <stdio.h>
#include <locale.h>
#include <time.h>

//Prot�tipo das fun��es
void menu_inicial();
void menu_modo_alerta();
int escolha_do_menu_inicial();

int main(int argc, char const *argv[])
{
	setlocale(LC_ALL, "portuguese"); //Permite acentua��o no console
	system("MODE con cols=70 lines=30"); //Ajusta a largura e altura da tela
	system("COLOR 0A");
	
	//Declra��o de vari�veis
	int retorno;
	
	menu_inicial();
	retorno = escolha_do_menu_inicial();
    
	if(retorno==7){
    	system("cls");
    	menu_modo_alerta();
	}
	
	return 0;
}

void menu_inicial(){
	
	char dateStr[9];
	char timeStr[9];
	
	_strdate(dateStr);
	_strtime(timeStr);
	printf("\n\t FILA DE IMPRESS�O ESCOLA ADIRON GON�ALVES BOAVENTURA \n");
	printf("\t\t  Hor�rio do sistema: %s\n",timeStr);
	printf("\t\t\t    ");system("date /t");
  	printf("\n   --------------------------------------------------------------\n");
	printf("   |\t[1] - Adicionar elementos a fila de impress�o.          |\n");
	printf("   |\t[2] - Verificar fila de impress�o da impressora A.      |\n");
	printf("   |\t[3] - Verificar fila de impress�o da impresora B.       |\n");
	printf("   |\t[4] - Verificar toda fila de impress�o.                 |\n");
	printf("   |\t[5] - Remover algum elemento da fila de impress�o.      |\n");
	printf("   |\t[6] - Alterar n�mero de alunos de uma turma.            |\n");
	printf("   |\t[7] - Modo alerta.                                      |\n");
	printf("   |\t[8] - Sair.                                             |");
  	printf("\n   --------------------------------------------------------------\n");
}
int escolha_do_menu_inicial(){
	
	int escolha;

	do{
		printf("\t\t       Opcao desejada: ");
		scanf("%d",&escolha);
	}while(escolha<1 || escolha>8);
	
	return escolha;	
}
void menu_modo_alerta(){

	char dateStr[9];
	char timeStr[9];
	system("COLOR E7");
	Beep(1000,1700);
	sleep(0);
	system("COLOR 07");
	_strdate(dateStr);
	_strtime(timeStr);
	printf("\n\t FILA DE IMPRESS�O ESCOLA ADIRON GON�ALVES BOAVENTURA \n");
	printf("\t\t  Hor�rio do sistema: %s\n",timeStr);
	printf("\t\t\t    ");system("date /t");
  	printf("\n   --------------------------------------------------------------\n");
	printf("   |\t[1] - Adicionar elementos a fila de impress�o.          |\n");
	printf("   |\t[2] - Verificar toda fila de impress�o.                 |\n");
	printf("   |\t[3] - Remover algum elemento da fila de impress�o.      |\n");
	printf("   |\t[4] - Alterar n�mero de alunos de uma turma.            |\n");
	printf("   |\t[5] - Modo normal.                                      |\n");
	printf("   |\t[6] - Sair.                                             |");
  	printf("\n   --------------------------------------------------------------\n");

}
