//Declara��o das bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> //para utilizar a setlocale()
#include <time.h>
#include <conio.h> //para utilizar o getch()
#include <ctype.h> //para utilizar o isdigit()
#include <string.h> //para utilizar strcpy(), strcmp()

typedef struct scelula
{
    char nome_elemento[50];
    char nome_da_turma[50];
    int prioridade; //a prioridade � o tempo gasto na impress�o do elemento
    struct scelula* prox;
} Celula;

typedef struct sfila
{
    Celula *inicio;
    Celula* fim;
} Fila;

//Prot�tipo das fun��es
void menu_inicial();
void menu_modo_alerta();
int escolha_do_menu_inicial();
int quantidade_de_alunos(char turma[]);
void altera_numero_da_turma();
void insere_na_fila(Fila* c, Fila* a, Fila* b, char nome[],char turma[], int tempo);
void inicializa(Fila *f);
int vazia(Fila *f);
Celula* criar_no();
void imprime (Fila* f);
//falta implementar
int contar_elementos_fila(Fila *f,Fila *g); //pode ser recursiva
void organizar_fila ();
void desenfileirar(Fila *fila);
void insere_fila_aux(Fila *a);
void enfileirar(Fila* f, char z[], char x[]);


int main()
{
    //setlocale(LC_ALL, "portuguese"); //Permite acentua��o no console
    //system("MODE con cols=70 lines=30"); //Ajusta a largura e altura da tela
    system("COLOR 0A");

    //Declra��o de vari�veis
    int retorno_menu_inicial;
    int nalunos,folhas,tamanho,i, tempo;
    char nome[100];
    char turma[100];
    Fila pc;
    Fila pa;
    Fila pb;
    Fila g;

    //inicializando as filas de impress�o
    inicializa(&pc);
    inicializa(&pa);
    inicializa(&pb);
    inicializa(&g);

    //la�o de repeti��o que chama o menu e possibilita a escolha das opera��es e chamadas de fun��o
    do
    {

        menu_inicial();
        retorno_menu_inicial = escolha_do_menu_inicial();

        if(retorno_menu_inicial==1)
        {
            printf("Quantos elementos ser%co o adicionados na fila?\n",198);
            scanf("%d",&tamanho);

            for(i=0; i<tamanho; i++)
            {
                fflush(stdin);
                printf("Nome: ");
                gets(nome); //alterar para o scanf com espa�o
                printf("Quantidade de folhas: ");
                scanf("%d",&folhas);
                fflush(stdin);
                printf("Turma: ");
                gets(turma);
                nalunos = quantidade_de_alunos(turma);
                if(nalunos==0)
                {

                    printf("Turma nao cadastrada.\nTente novamente");
                    main();
                }
                tempo=nalunos*folhas*15; //c�lculo do tempo gasto na impress�o de um elemento
                insere_na_fila(&pc,&pa,&pb,nome,turma,tempo);
            }
            system("cls");
        }

        // nas fun�oes de n�mero 2, 3 e 4 � preciso decicir se vai usar impress�o cl�ssica ou n�o cl�ssica
        if(retorno_menu_inicial==2)
        {
            system("cls");

            printf("Quantidade de elementos na fila A: %d\n",contar_elementos_fila(&pa,&g));
            printf("\n\nFila original:\n\n");
            imprime(&pa);
            printf("\n\nFila auxiliar\n\n");
            imprime(&g);

            pa = g;

            printf("\n\n\n\nFila original novamente\n\n");
            imprime(&pa);

        }

        if(retorno_menu_inicial==3)
        {
            system("cls");
            imprime(&pb);
        }

        if(retorno_menu_inicial==4)
        {
            system("cls");
            imprime(&pc);
        }

        if(retorno_menu_inicial==5)
        {
            system("cls");
            printf("Ainda n�o implementado.\n");
            exit(1);
        }

        if(retorno_menu_inicial==6)
        {
            altera_numero_da_turma();
            Sleep(1500);
            system("cls");
        }

        if(retorno_menu_inicial==7)
        {
            int esc;
            system("cls");
            do
            {
                system("cls");
                printf("\n   ----------------------------------------------------\n");
                printf("   |\t[1] - Imprimir a fila de impressora A.        |\n");
                printf("   |\t[2] - Imprimir a fila de impressora B.        |\n");
                printf("   |\t[3] - Imprimir ambas filas de impress%co.      |\n",198);
                printf("   |\t[4] - Voltar ao Menu anterior.                |");
                printf("\n   ----------------------------------------------------\n");

                printf("\n\n\t\t Op%c%co: ",135,198);


                scanf("%d",&esc);
            }
            while(esc<1 || esc>4);

            if(esc==1)
            {

                int i;
                char teste[120]=""; //limpa o espaco reservado na memoria

                int tempo = clock();

                int c=2;

                for(i=0; i<=100; i++)//laco de repeticao de zero a 100.
                {


                    if(i%2==0)
                    {

                        strcat(teste,"�");
                    }
                    system("CLS");//limpa a tela

                    printf("\t\t\t\t\t\t\tImpressora A\n\n");
                    printf("\t\t\t               �����������������������������������������������������Ŀ");
                    printf("\n  Imprindo Arquivos de A ");


                    printf("\t\t  %s ",teste);//exibe na tela a contagem de "i" e acumula os caracteres "�" na tela

                    printf("\n\t\t\t               �������������������������������������������������������");

                    printf("     %d%% ",i);

                    Sleep(115*c);


                }
                system("cls");

            }
            else if(esc==2)
            {


                int i;
                char teste[120]=""; //limpa o espaco reservado na memoria

                int tempo = clock();

                int c=2;

                for(i=0; i<=100; i++)//laco de repeticao de zero a 100.
                {


                    if(i%2==0)
                    {

                        strcat(teste,"�");
                    }
                    system("CLS");//limpa a tela

                    printf("\t\t\t\t\t\t\tImpressora B\n\n");
                    printf("\t\t\t               �����������������������������������������������������Ŀ");
                    printf("\n  Imprimindo Arquivos de B");


                    printf("\t\t  %s ",teste);//exibe na tela a contagem de "i" e acumula os caracteres "�" na tela

                    printf("\n\t\t\t               �������������������������������������������������������");

                    printf("     %d%% ",i);

                    Sleep(115*c);


                }
                system("cls");
            }
            else if(esc==3)
            {
                int i;
                char teste[120]=""; //limpa o espaco reservado na memoria

                int tempo = clock();

                int c=2; //AQUI � A QUANTIDADE DE FOLHAS QUE VAI SER MULTIPLICADA POR 15 SEGUNDOS

                //PENSEI EM COLOCAR S� IMPRIMINDO FILA DE IMPRESS�O DE A, A� MOSTRAR A FILA DE
                //IMPRESS�O DE A ANTES, UMA LISTA, S� CHAMAR O PRINTAR


                //ACHO QUE N�O PRECISA COLOCAR
                // POR EXEMPLO : IMPRIMINDO PROVA DE BIOLOGIA. ( OBS: ACHO QUE DARIA UM TRAMPO GRAND�O, PRA TROCAR
                //DE PROVA DE BIOLOGIA PARA GEOGRAFIA POR EXEMPLO)



                for(i=0; i<=100; i++)//laco de repeticao de zero a 100.
                {


                    if(i%2==0)
                    {

                        strcat(teste,"�");
                    }
                    system("CLS");//limpa a tela

                    printf("\t\t\t\t\t\t\tImpressora A\n\n");
                    printf("\t\t\t               �����������������������������������������������������Ŀ");
                    printf("\n  Imprindo Arquivos de A ");


                    printf("\t\t  %s ",teste);//exibe na tela a contagem de "i" e acumula os caracteres "�" na tela

                    printf("\n\t\t\t               �������������������������������������������������������");

                    printf("     %d%% ",i);


                    printf("\n\n\n\n");

                    printf("\t\t\t\t\t\t\tImpressora B\n\n");
                    printf("\t\t\t               �����������������������������������������������������Ŀ");
                    printf("\n  Imprimindo Arquivos de B");


                    printf("\t\t  %s ",teste);//exibe na tela a contagem de "i" e acumula os caracteres "�" na tela

                    printf("\n\t\t\t               �������������������������������������������������������");

                    printf("     %d%% ",i);

                    Sleep(115*c);


                }
            }
            else if(esc==4)
            {
                system("cls");
            }

        }




        else if(retorno_menu_inicial==8) //precisa de um do while s� pra ele, at� que clique no modo 6
        {
            system("cls");
            menu_modo_alerta();
        }

        if(retorno_menu_inicial==9)
        {
            int i =0;
            for(i=0; i<=100; i++)//laco de repeticao de zero a 100.
            {
                system("cls");
                printf("              	 ___________________________________________________");
                printf("\n \t\t|\t\t     Saindo do sistema              |");
                printf("\n            	|___________________________________________________|");
                printf("     %d%% ",i);

            }

            system("cls");	//limpa a tela
            Sleep(900);//espera de um segundo
            printf("Sistema deslogado.\n");

        }

    }
    while(retorno_menu_inicial!=9 && retorno_menu_inicial!=8);
    return 0;
}
void altera_numero_da_turma()
{

    int i=0,z=0,t=0,d,x,encontrou=0;

    char turma[100]; //vari�vel de entrada
    int turmanovo; //Vari�vel de entrada

    int tam; //Para ver o tamanho da palavra que foi inserida na entrada "turma", para posterior aloca��o na var�vel aux
    char* token; //Recebe o argumento que servir� de token para quebrar a string digitada na vari�vel "turma"

    //Vari�veis para ler do arquivo
    char nome_da_turma[100];
    int quantidade;
    int ano;

    //Vari�veis auxiliares para quebra da turma digitada
    char* aux; //C�pia da turma para aux, ou seja turma = aux
    char aux2[100];
    char aux3[10];


    //Cria��o de arquivos
    FILE *alunos_por_turma;
    FILE *alunos_por_turma_aux;



    alunos_por_turma = fopen("N�meros de alunos por turma.txt","r");
    alunos_por_turma_aux = fopen("Novo n�meros de alunos por turma.txt","w");
    if(alunos_por_turma==NULL)
    {
        printf("Arquivo inexistente.\n");
        exit(1);
    }
    if(alunos_por_turma_aux==NULL)
    {
        printf("Arquivo inexistente.\n");
        exit(1);
    }

    printf("Qual turma gostaria de alterar a quantidade de alunos?\n");
    gets(turma);


    tam = strlen(turma);
    aux = (char*)malloc(tam * sizeof(char));
    strcpy(aux,turma);


    token = strtok(aux, " ");
    while (token != NULL)
    {
        if(t==0)
        {
            strcpy(aux3,token);
        }
        strcpy(aux2,token);

        token = strtok(NULL, " ");
        t++;
    }

    x = atoi(aux3); //Converte o char armazenado na vari�vel aux3 em inteiro



    while( (fscanf(alunos_por_turma,"%d %s %d\n", &ano, nome_da_turma, &quantidade))!=EOF ) //L� o txt at� encontrar o fim do arquivo
    {
        if(ano==x)
        {
            if(strcmp(nome_da_turma,aux2)==0)
            {
                for(i=0; i<strlen(nome_da_turma); i++)
                {
                    nome_da_turma[i]  = toupper(nome_da_turma[i]); // Converte caracter min�sculo em mai�sculo para aparecer para o usu�rio destacado
                }

                printf("\nO tamanho atual da turma %s %c: %d alunos!\n",nome_da_turma,130,quantidade);
                printf("\nQual o novo n%cmero de alunos dessa turma?\n",163);
                scanf("%d",&turmanovo);

                for(i=0; i<strlen(nome_da_turma); i++)
                {
                    nome_da_turma[i]  = tolower(nome_da_turma[i]); // Converte caracter mai�sculo em min�sculo para gravar no arquivo
                }

                fprintf(alunos_por_turma_aux,"%d %s %d\n", ano,nome_da_turma,turmanovo);
                d = 1;
                encontrou = 1;
            }
            else
            {
                d=0;
            }
        }
        if(d==1)
        {
            d=0;
        }
        else
        {
            fprintf(alunos_por_turma_aux,"%d %s %d\n", ano,nome_da_turma,quantidade);
        }
    }

    if(!encontrou)
    {
        printf("A turma informada n�o se encontra no arquivo.\n");
    }
    else if(encontrou)
    {
        printf("Alterado com sucesso.\n");
    }

    fclose(alunos_por_turma);

    alunos_por_turma = fopen("N�meros de alunos por turma.txt","w");

    fclose(alunos_por_turma_aux);

    alunos_por_turma_aux = fopen("Novo n�meros de alunos por turma.txt","r");


    while( (fscanf(alunos_por_turma_aux,"%d %s %d\n", &ano, nome_da_turma, &quantidade))!=EOF ) //L� o txt at� encontrar o fim do arquivo
    {
        fprintf(alunos_por_turma,"%d %s %d\n", ano,nome_da_turma,quantidade);
    }
    fclose(alunos_por_turma_aux);
    remove("Novo n�meros de alunos por turma.txt"); //Remove o arquivo auxiliar
    fclose(alunos_por_turma);
}

int quantidade_de_alunos(char turma[]) //retorna a quantidade de alunos de uma turma, lendo no arquivo
{

    int i=0,j=0,tam;
    FILE *alunos_por_turma;
    int quantidade,ano;
    char nome_da_turma[100];
    char* aux;
    int teste;
    char aux2[100];
    char aux3[10];

    char* token;


    alunos_por_turma = fopen("N�meros de alunos por turma.txt","r");
    if(alunos_por_turma==NULL)
    {
        printf("Arquivo inexistente.\n");
        exit(1);
    }

    tam = strlen(turma); //Verifica o tamanho da string para posterior aloca��o na vari�vel auxiliar para busca no arquivo
    aux = (char*)malloc(tam * sizeof(char));
    strcpy(aux,turma); //faz a c�pia da turma digitada para vari�vel que servir� de compara��o para verificar a exist�ncia no arquivo


    token = strtok(aux, " ");
    int t=0;
    while (token != NULL)
    {

        if(t==0)
        {
            strcpy(aux3,token);
        }
        strcpy(aux2,token);

        token = strtok(NULL, " ");
        t++;

    }

    int x = atoi(aux3);
    int y=0;
    int z=0;



    while( (fscanf(alunos_por_turma,"%d %s %d\n", &ano, nome_da_turma, &quantidade))!=EOF ) //L� o txt at� encontrar o fim do arquivo
    {

        if(ano==x)
        {
            if(strcmp(nome_da_turma,aux2)==0)
            {
                z = quantidade;
                y--;
                return z;

            }
            else
            {
                y++;
            }
        }
        else
        {
            y++;
        }
        j++;
    }
    if(y==j)
    {
        z = 0;
        printf("N%co existe no arquivo.\n",198);
        return z;
    }
}

//fun�oes essenciais de fila

void inicializa(Fila *f)
{
    f->fim=NULL;
    f->inicio=NULL;
}
int vazia(Fila *f)
{
    if(f->inicio==NULL)
        return 1; //se estiver vazia
    return 0; //se n�o estiver vazia
}

Celula* criar_no()
{
    Celula* q;
    q=(Celula*) malloc (sizeof(Celula));
    return q;
}

void insere_na_fila(Fila* c, Fila* a, Fila* b, char nome[],char turma[], int tempo)  //insere o elemento nas filas certas
{
    Celula* q;
    Celula* r;
    Celula* aux;
    int soma_a=0, soma_b=0;
    q=criar_no();

    if(q!=NULL)  //se criou o no
    {
        //inicializa o no na fila completa
        strcpy(q->nome_elemento,nome);
        strcpy(q->nome_da_turma,turma);
        q->prioridade=tempo;
        q->prox=NULL;

        // verifica se a fila completa est� vazia e insere o n� nela
        if(vazia(c))
        {
            c->inicio=q;

            c->fim=q;
        }
        else
        {
            (c->fim)->prox=q;
            c->fim=q;
        }

    }
    else
        printf("Erro ao criar o no");

    r=criar_no();
    if(r!=NULL)
    {

        //inicializa outro no na fila da impressora
        strcpy(r->nome_elemento,nome);
        strcpy(r->nome_da_turma,turma);
        r->prioridade=tempo;
        r->prox=NULL;

        if(vazia(a)) //se a fila de a estiver vazia, insere em a
        {
            a->inicio=r;

            a->fim=r;
        }
        else if(vazia(b)) // se a fila de a n�o estiver vazia e a flia de b estiver, insere em b
        {
            b->inicio=r;

            b->fim=r;
        }
        else   // se nenhuma das filas estiver vazia

        {
            //calcula o tempo de espera de a e b
            aux=a->inicio;
            while(aux!=NULL)
            {
                soma_a+=aux->prioridade;
                aux=aux->prox;
            }

            aux=b->inicio;
            while(aux!=NULL)
            {
                soma_b+=aux->prioridade;
                aux=aux->prox;
            }
            // printf("soma a:%d soma b: %d\n",soma_a,soma_b);
            if(soma_a<=soma_b)
            {
                (a->fim)->prox=r;
                a->fim=r;

            }
            else
            {

                (b->fim)->prox=r;
                b->fim=r;
            }
        }

    }
    else
        printf("Erro na criacao do no\n");
}


void imprime (Fila* f)  //impress�o n�o classica, s� pra verificar como os elementos s�o distribuidos
{
    Celula* aux;
    if(vazia(f))
    {
        printf("Erro -- Lista vazia\n");
        //exit(1);
    }
    else
    {
        aux=f->inicio;
        while(aux!=NULL)
        {
            printf("\nTurma:%s\nImpress%co:%s\n",aux->nome_da_turma, 198,aux->nome_elemento);
            aux=aux->prox;
        }
    }
}




void menu_inicial()
{

    char dateStr[9];
    char timeStr[9];

    _strdate(dateStr);
    _strtime(timeStr);
    printf("\n\t FILA DE IMPRESS%cO ESCOLA ADIRON GON%cALVES BOAVENTURA \n",199,128);
    printf("\t\t  Hor%crio do sistema: %s\n",160,timeStr);
    printf("\t\t\t    ");
    system("date /t");
    printf("\n   --------------------------------------------------------------\n");
    printf("   |\t[1] - Adicionar elementos a fila de impress%co.          |\n",198);
    printf("   |\t[2] - Verificar fila de impress%co da impressora A.      |\n",198);
    printf("   |\t[3] - Verificar fila de impress%co da impresora B.       |\n",198);
    printf("   |\t[4] - Verificar toda fila de impress%co.                 |\n",198);
    printf("   |\t[5] - Remover algum elemento da fila de impress%co.      |\n",198);
    printf("   |\t[6] - Alterar n%cmero de alunos de uma turma.            |\n",163);
    printf("   |\t[7] - Imprimir                                          |\n");
    printf("   |\t[8] - Modo alerta.                                      |\n");
    printf("   |\t[9] - Sair.                                             |");
    printf("\n   --------------------------------------------------------------\n");
}
int escolha_do_menu_inicial()
{

    char digitado[50];
    char c;//armazena cada caractere digitado pelo usu�rio
    int i=0;
    int escolha=0;//vari�vel para armazenar a convers�o do que foi digitado pelo usu�rio
    int cont=0;


    do
    {
        if(cont==0)
        {

            printf("\t\t       Op%c%co desejada: ",135,198);
            c=getch();//captura o caractere digitado pelo usu�rio
            printf("%c\n",c);

            //isdigit verifica se o que foi digitado � um n�mero ou n�o, retornando qualquer n�mero diferente de 0, se for um n�mero

            if (isdigit(c)!=0)	//se for um n�mero
            {
                digitado[i] = c;//armazena no vetor de caracteres
                i++;
            }
            else if(c==8 && i)//se for pressionada a tecla BACKSPACE e houver caracteres j� digitados, ou seja, i!=0
            {
                digitado[i]='\0';//o �ndice atual do vetor de caracteres recebe a termina��o da string
                i--;
                printf("\b \b");//o caractere digitado � apagado da tela, primeiro \b apaga o caracter da tela e o segundo \b tira o caracter da tela
            }
        }
        else
        {

            printf("\t\t       Digite uma op%c%co v�lida: ",135,198);
            c=getch();//captura o caractere digitado pelo usu�rio
            printf("%c\n",c);

            //isdigit verifica se o que foi digitado � um n�mero ou n�o, retornando qualquer n�mero diferente de 0, se for um n�mero

            if (isdigit(c)!=0)	//se for um n�mero
            {
                digitado[i] = c;//armazena no vetor de caracteres
                i++;
            }
            else if(c==8 && i)//se for pressionada a tecla BACKSPACE e houver caracteres j� digitados, ou seja, i!=0
            {
                digitado[i]='\0';//o �ndice atual do vetor de caracteres recebe a termina��o da string
                i--;
                printf("\b \b");//o caractere digitado � apagado da tela, primeiro \b apaga o caracter da tela e o segundo \b tira o caracter da tela
            }
        }
        cont ++;
    }
    while(c<'1' || c>'9');


    digitado[i]='\0';	//o �ndice atual do vetor de caracteres recebe a termina��o da string

    int tam = strlen(digitado);

    //atoi converte char para int
    escolha = atoi(&digitado[tam-1]); //atoi() tem como um par�metro um ponteiro para caracteres, por isso, pra usar com vetor tem que usar o &

    return escolha;
}
/*int contar_elementos_fila(){ //T�O BONITINHO, MAS NAO PODE USAR GRRRRRRRRR

    if(aux==NULL)
    {
        return 0;
    }
    else
    {
    	return (contar_elementos_fila(aux->prox)+1);
    }

}*/

void desenfileirar(Fila *fila)
{
    Celula *aux;
    char c[100];
    char b[100];
    if(vazia(fila))
    {
        printf("Fila esta vazia.\n");
        //return 0;
    }
    aux = fila->inicio;
    strcpy(c, fila->inicio->nome_da_turma);
    strcpy(b, fila->inicio->nome_elemento);

    fila->inicio  = fila->inicio->prox; //fa�o o inicio receber o proximo;



    if(fila->inicio==NULL) //fila ficou vazia;
    {
        fila->fim = NULL;
    }
    printf("Removeu %s e %s.\n",c,b);
    free(aux);
}

void enfileirar(Fila* f, char z[], char x[])
{
    Celula* q;
    q=criar_no();
    if(q!=NULL)  //se criou o no
    {
        strcpy(q->nome_da_turma,z);
        strcpy(q->nome_elemento,x);
        q->prox=NULL;
        if(vazia(f))
        {
            f->inicio=q;
            f->fim=q;
        }
        else
        {
            (f->fim)->prox=q;
            f->fim=q;
        }
    }
    else
        printf("Erro ao criar o no");
}



int contar_elementos_fila(Fila *f, Fila *g)
{
    int cont=0;
    char c[100];
    char x[100];


    Celula* aux;
    if(vazia(f))
    {
        printf("Erro -- Lista vazia\n");
        //exit(1);
    }
    else
    {
        aux=f->inicio;

        while(aux!=NULL)
        {
            strcpy(c, aux->nome_da_turma);
            strcpy(x, aux->nome_elemento);
            enfileirar(g,c,x);
            cont ++;
            desenfileirar(f);
            aux=aux->prox;
        }
    }
    return cont;
}

void menu_modo_alerta()
{

    char dateStr[9];
    char timeStr[9];
    system("COLOR 17");
    Beep(1000,1700);
    sleep(0);
    system("COLOR 07");
    _strdate(dateStr);
    _strtime(timeStr);
    printf("\n\t FILA DE IMPRESS%cO ESCOLA ADIRON GON%cALVES BOAVENTURA \n",199,128);
    printf("\t\t  Hor%crio do sistema: %s\n",160,timeStr);
    printf("\t\t\t    ");
    system("date /t");
    printf("\n   --------------------------------------------------------------\n");
    printf("   |\t[1] - Adicionar elementos a fila de impress�o.          |\n");
    printf("   |\t[2] - Verificar toda fila de impress�o.                 |\n");
    printf("   |\t[3] - Remover algum elemento da fila de impress�o.      |\n");
    printf("   |\t[4] - Alterar n�mero de alunos de uma turma.            |\n");
    printf("   |\t[5] - Imprimir                                          |\n");
    printf("   |\t[6] - Modo normal.                                      |\n");
    printf("   |\t[7] - Sair.                                             |");
    printf("\n   --------------------------------------------------------------\n");

}
