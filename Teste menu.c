#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#include<unistd.h>
#include <string.h>


int main(){
	int i;
	char teste[120]=""; 
	
	int tempo = clock(); 
	
	int c=2;
	
	

	
	for(i=0; i<=100; i++)
    {
    	
		
	if(i%2==0){
	
	strcat(teste,"�"); }
    system("CLS");//limpa a tela
    
    printf("\t\t\t\t\tImpressora A\n\n");
    printf("\t\t               �����������������������������������������������������Ŀ");
    printf("\n  Imprindo Arquivo X ");
    
	
	printf("\t\t  %s ",teste);
    
	printf("\n\t\t               �������������������������������������������������������");

	printf("     %d%% ",i);
	

	printf("\n\n\n\n");
	
	printf("\t\t\t\t\tImpressora B\n\n");
	printf("\t\t               �����������������������������������������������������Ŀ");
    printf("\n  Imprimindo Arquivo Y");
    

	printf("\t\t  %s ",teste);
    
	printf("\n\t\t               �������������������������������������������������������");

	printf("    � %d%% ",i);
	
	Sleep(115*c); 
	
	
}
} 
