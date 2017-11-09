/*
 ============================================================================
 Name        : Cpf.c
 Author      : Fernando
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char validarCpf(char *cpf);
void menu();
char verificarPriDig(char *cpf);
char verificarSegDig(char *cpf);
void validarDigiCpf(char *cpf, char *dv);

int main(void) {
	setbuf( stdout, NULL);
	menu();
	system("pause");
	return 0;
}

char validarCpf(char *cpf){
	char dv[2];
	int i = 0, tamanho = 0;

	for(i = 0; cpf[i]!='\0'; i++){
		tamanho++;
	}

	if(tamanho != 11){
		printf("\nTamanho do CPF inválido.\n");
		return 'F';
	}else {
		for (i = 0; i < strlen(cpf); i++){
			if (cpf[i]< '0' || cpf[i] > '9'){
				printf("\nCaracter Inválido.\n");
				return 'F';
			}
		}
	}

	*dv = strcat(verificarPriDig(cpf),verificarSegDig(cpf));
	return 'V';
}

char verificarPriDig(char *cpf){
	char dig1;
	int i, resul = 0, x = 10, calcResul;
	for(i = 0; i < 9 ; i--){
		resul += cpf[i] * x;
		x--;
	}
	calcResul = resul%11;

	if(calcResul < 2){
		dig1 = '0';
	}else{
		dig1 = 11 - calcResul;
	}

	return dig1;
}

char verificarSegDig(char *cpf){
	char dig2;
	int i, resul = 0, x = 11, calcResul;
	for(i = 0; i < 10 ; i--){
		resul += cpf[i] * x;
		x--;
	}
	calcResul = resul%11;

	if(calcResul < 2){
		dig2 = '0';
	}else{
		dig2 = 11 - calcResul;
	}

	return dig2;
}

void validarDigiCpf(char *cpf, char *dv){
	int tamanho, i;
	tamanho = strlen(cpf);
	for (i = (tamanho - 9); i < tamanho; i++){
		if(cpf[i] != dv[i]){
			printf("\nCPF Inválido.\n");
			break;
		}
	}
}

void menu(){
	char opcao, cpf[12], vali;
	do{
		printf("\n-----------Menu-----------\n");
			printf("I - Inserir CPF no arquivo\n");
			printf("S - Sair do programa\n");
			printf("\n\nEscolha uma opção:");
			fflush(stdin);
			scanf("%c", &opcao);
			switch(opcao){
			case 'I':
				do{
					printf("\nDigite o CPF. (Somente os números): ");
					fflush(stdin);
					gets(cpf);
					vali = validarCpf(cpf);
				}while (vali == 'F');
				break;
			case 'S':
				break;
			default:
				printf("\nEscolha uma opção válida!\n");
				break;
			}
	}while (opcao != ('s') || opcao != ('S'));

}

