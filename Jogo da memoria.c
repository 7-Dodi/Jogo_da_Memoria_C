//O jogo consiste em informar um numero aleatorio para o jogador, chamado de numero da sorte. O que o jogador deve fazer é informar as posições em uma matriz, e verificar se posição ind=formada aramzena
//o numero da sorte. O jagador ganhar ao acertar um numero defindo de pontos ou perder ao zerar todas as suas vidas;
#include <stdio.h>
#include <conio.h>
#include <time.h>
const int LIN=4;
const int COL=4;
void criarMAT(int mat[LIN][COL]){ //Criando uma matriz de tamanho quadrado, aplicando valores aleatorios as posições
	int k, x;
	srand(time(NULL));
	for(k=0;k<LIN;k++){
		for(x=0;x<COL;x++){
			mat[k][x]= rand() %10;
		}
	}
}

void imprimir (int mat[LIN][COL]){ //Garantia de impressão dos valores destribuidos aleatoriamente na matriz
	int k, x;
	for(k=0;k<LIN;k++){
		for(x=0;x<COL;x++){
			if(x<COL-1){
				printf("%d\t", mat[k][x]);
			}
			else{
				printf("%d\n", mat[k][x]);
			}
		}
	}
}
void tabuleiro (char mat[LIN][COL]){ //Criando uma segunda matriz, com a posições com valor '*', para servir de tabuleiro para o jogador
	int k, x;
	for(k=0;k<LIN;k++){
		for(x=0;x<COL;x++){
		mat[k][x]='*';
		}
	}
}
void imprimirTab (char mat[LIN][COL]){ //Imprimindo o tabuleiro na tela do jogador
	int k, x;
	for(k=0;k<LIN;k++){
		for(x=0;x<COL;x++){
			if(x<COL-1){
				printf("%c\t", mat[k][x]);
			}
			else{
				printf("%c\n", mat[k][x]);
			}
		}
	}
}
void procurar (int mat[LIN][COL], int col, int lin, int numero, int *vidas, int *pontos){ //Ira aramzenar as posições informadas pelo o jogador;
	printf("\n\n############# RESULTADOS #############");
	if(mat[lin][col]==numero){ //Caso o valor da posição informada for igual ao numero da sorte
		*pontos=*pontos+1;
		printf("\n\nVOCE ACERTOU!!!! VOCE GANHOU MAIS UM PONTO, AGORA TEM %d PONTOS\n\nO valor da matriz na linha %d coluna %d eh %d",*pontos, lin+1, col+1, mat[lin][col]);
	}
	else{ //Caso o valor da posição informada for duferente do numero da sorte
		*vidas=*vidas-1;
		printf("\n\nVOCE ERROU!!! LHE RESTAM SOMENTE %d VIDAS\n\nO valor da matriz na linha %d coluna %d eh %d\n",*vidas, lin+1, col+1, mat[lin][col]);
	}
	printf("\nClique em qualquer tecla para continuar...\n\n");
	getch();
}
void main(){
	int mat[LIN][COL]; //Criando matriz de tipo inteiro, a qual ira armazenar os valores aleatorios
	char mat2[LIN][COL]; //Criando matriz de tipo char, a qual ira armazernar apresentar o tabuleiro ao usuario
	tabuleiro(mat2); 
	criarMAT(mat);
	int vidas=5, pontos=0; //Quantidade de vidas e pontos do jogador
	printf("\n\n################ Jogo da Memoria #################\n\n");
	printf("------------------ REGRAS ---------------\n");
	printf("\n1-O jogador, ao iniciar o jogo, recebera um NUMERO DA SORTE.\nA tarefa do jodador eh encontrar esse numero dentro do Tabuleiro.\n2-Caso o Jagador encoontre o numero, ele ganhara um ponto, com tres pontos, o Jogador vence a partida.\n");
	printf("3-Caso o jogador nao encontre o numero, sera informado outro NUMERO DA SORTE, bem como o jogador perdera uma vida.\n4-Sao ao total 3 vidas, caso perca todas o jogo encerra e o jogador perde.\n");
	printf("\nTudo certo?!... Clique em qualquer tecla para iniciar");
	getch();
	do{
		int linha, coluna; //Para informar a posição da linha e da coluna
		int numero=  rand()%10; //Para escolher um numero da sorte aleatorio
		printf("\n\n############# TABULEIRO ################\n\n");
		imprimirTab(mat2); //Imprimir o tabuleiro
		printf("\n");
		printf("\n\n############# DADOS: ################\n\n");
		printf("\nNUMERO DA SORTE: %d", numero); //Apresentar os dados: certo ou errado, ponto e vidas
		printf("\n\n\nInforme a linha e a coluna desejada:");
		scanf("%d%d", & linha, & coluna);
		procurar(mat, coluna-1, linha-1, numero, &vidas, &pontos);
		printf("\n");	
	}while(vidas!=0 && pontos!=3);//Encerrar quando o jagador atinge mais de tres acertos ou zera a vida
	printf("\n\n############ FIM DE JOGO ############\n");
	if(pontos>=3){
		printf("\n\nPARABENS!!!! VOCE GANHOU O JOGO!!!!");
	}
	else if(vidas==0){
		printf("\nDERROTA!!! VOCE PERDEU O JOGO, MAIS SORTE NA PROXIMA VEZ");
	}
	printf("\n\n IMPRINDO OS VALORES DO TABULARIO:\n\n");
	imprimir(mat); //Imprindo a tabela com os valores aleatorios
	printf("\n\nJOGO SENDO ENCERRADO.... clique em qualquer tecla para encerrar");
}
