///Tatuadora
// Pode possuir alguns erros, mas esse foi o max que consegui

#include<stdio.h>
#include<math.h>
#include<locale.h>
#include <unistd.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
typedef struct{
	char cpf[12];
	char nome[60];
	char tel[13];
	int codigo;
	int status;
}Tcliente;

typedef struct{
    char tattoo[16];
	char nome[16];
	char tamanho[16];
	float valor;
	int status;
}Ttatuagem;

void menu_principal();
void menu_cliente();
void menu_tatuagem();
void carregando();
void cadastro_cliente();
void edit_cliente();
void search_cliente();
void delete_cliente();
void lixeira_cliente();
void cadastro_tatuagem();
void edit_tatuagem();
void search_tatuagem();
void delete_tatuagem();
void lixeira_tatuagem();
void sobre_tatuagem();
void cliente_excluido();
void tatuagem_excluido();
void restaurar_tatuagem();
void esvaziarLixeira();
void esvaziaLixeira(int posicao);
void restaurar_cliente();
void lestring(char *string, int tamanhostring);
void le_string(char *string, int tamanhostring);
void le_string(char *string, int tamanhostring);
void scan_tattoo(char *string, int tamanhostring);
void scan_string(char *string, int tamanhostring);
void long_int(long int *inteiro, int tamanhostring);
void long_int(long int *inteiro, int tamanhostring);
void editar_cliente(int posicao);
void restaura_cliente(int posicao);
void cliente_inativo(int posicao);
void esvazia_lixeira(int posicao);
void tatuagem_inativo(int posicao);
void restaura_tatuagem(int posicao);
void esvaziar_lixeira();
void editar_tatuagem(int posicao);
void data(char *data);
int verifica_cpf(char *cpf);
int busca_cpf(char *cpf);
int busca_cliente(int posicao);
int busca_tattoo (char *tattoo);
int busca_statustatuagem(int posicao);
float busca_valor(int posicao);


Tcliente cliente;
Ttatuagem tatuagem;


FILE *arq_cliente;
FILE *arq_tatuagem;


int resultadobuscacpf;
int resultadoverificacpf;
int resultadobuscacliente;
int resultadobuscatattoo;
int resultadobuscastatustatuagem;
float resultadobuscavalor;



int main(){
	menu_principal();
	return 0;


}



void menu_principal(){
    system("color f1"); // AZUL E BRANCO
	int menu;
	for(;;){
      printf(" %c----------------------------------------------------------------------------%c\n",201,187);
      printf(" | ");printf("\t\t\t     TATUADORA RACOSA");printf("\t\t\t              |\n");
      printf(" %c----------------------------------------------------------------------------%c\n",200,188);
      printf("\t       %c----------%c\t\t\t\t       ",201,187);
      printf("\t\t\t               |   MENU   ");printf("|\t\t\t\t      \n");
      printf("   %c-----------%c----------%c------------%c \n",201,200,188,187);
      printf("   | <1>  CLIENTE                      |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <2>  TATUAGEM                     |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <3>  Sair                         |\n");
      printf("   %c-----------------------------------%c",200,188);
      printf("\n\n\n\n");
      printf("\t\t\t      Qual op%c%co desejada:\t", 135, 198);
	scanf("%d", &menu);
	carregando();
	system("cls");
	switch(menu){
		case 1:
			menu_cliente(); break;

		case 2:
			menu_tatuagem(); break;

		case 3:
			exit(0);

		default:getchar(); system("cls"); menu_principal();
	}
	}
}
void carregando() {
	printf("\n\nCarregando sistema, por favor aguarde!\n--> ");
	int c;
	for (c = 0; c < 30; c++) {
		printf("Rafael");
		usleep(10000); // == 1ms
	}
}

void menu_cliente(){
    system("color f4");
	int menu = 0; inicio:
    printf(" %c----------------------------------------------------------------------------%c\n",201,187);
      printf(" | ");printf("\t\t\t     TATUADORA RACOSA");printf("\t\t\t              |\n");
      printf(" %c----------------------------------------------------------------------------%c\n",200,188);
      printf("\t     %c-------------%c\t\t\t\t       ",201,187);
      printf("\t\t\t             | MENU CLINTE");printf(" |\t\t\t\t      \n");
      printf("   %c---------%c-------------%c------------%c \n",201,200,188,187);
      printf("   | <1>  C A D A S T R A R            |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <2>  E D I T A R                  |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <3>  P E S Q U I Z A R            |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <4>  E X C L U I R                |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <5>  L I X E I R A                |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <6>  V O L T A R     M E N U      |\n");
      printf("   %c-----------------------------------%c",200,188);
      printf("\n\n\n\n");
      printf("\t\t\t      Qual op%c%co desejada:\t", 135, 198);
	scanf("%d", &menu);
	carregando();
	system("cls");
	switch (menu){
		case 1:
			cadastro_cliente(); break;

		case 2:
			edit_cliente(); break;

		case 3:
			search_cliente(); break;

		case 4:
			delete_cliente(); break;

		case 5:
			lixeira_cliente(); break;

		case 6:
			menu_principal();
			break;

		default: getchar(); goto inicio;
	}
}

void menu_tatuagem(){
    system("color f5");
	int menu = 0; inicio:
    printf(" %c----------------------------------------------------------------------------%c\n",201,187);
      printf(" | ");printf("\t\t\t     TATUADORA RACOSA");printf("\t\t\t              |\n");
      printf(" %c----------------------------------------------------------------------------%c\n",200,188);
      printf("\t     %c-------------%c\t\t\t\t       ",201,187);
      printf("\t\t\t             | MENU TATTOO");printf(" |\t\t\t\t      \n");
      printf("   %c---------%c-------------%c------------%c \n",201,200,188,187);
      printf("   | <1>  C A D A S T R A R            |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <2>  E D I T A R                  |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <3>  P E S Q U I Z A R            |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <4>  E X C L U I R                |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <5>  L I X E I R A                |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <6>  S O B R E  TATUAGEM          |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <7>  V O L T A R     M E N U      |\n");
      printf("   %c-----------------------------------%c",200,188);
      printf("\n\n\n\n");
      printf("\t\t\t      Qual op%c%co desejada:\t", 135, 198);
	scanf("%d", &menu);
	carregando();
	system("cls");
	switch (menu){
		case 1:
			cadastro_tatuagem(); break;

		case 2:
			edit_tatuagem(); break;

		case 3:
			search_tatuagem(); break;

		case 4:
			delete_tatuagem(); break;

		case 5:
			lixeira_tatuagem(); break;

		case 6:
			sobre_tatuagem(); break;

        case 7:
			menu_principal();
			break;

		default: getchar(); goto inicio;
	}
}



void cadastro_cliente(){
    system("color f4");
	inicio:
	printf("\n   ÚÄÄÄÄÄÄÄÄ C L I E N T EÄÄÄÄÄÄÄÄ¿\n");
   printf("   ³                              ³\n");
   printf("   ³ Î       C A D A S T R O      ³\n");
   printf("   ³                              ³\n");
   printf("   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
   printf("\n");

	printf("\tCPF: ");
	char esc;

	lestring(cliente.cpf, 12);
	resultadobuscacpf = busca_cpf(cliente.cpf);
	resultadoverificacpf = verifica_cpf(cliente.cpf);
	if(resultadobuscacpf != -1){
		printf("\n\n\tErro! O CPF digitado ja existe. Insira um novo CPF.\n");
		printf("\n\tAperte Enter para continuar.\n");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto inicio;
		}
	}

	else if(resultadoverificacpf != 1){
		printf("\n\n\tErro! O CPF digitado e invalido. Insira um CPF valido.\n");
		printf("\n\tAperte Enter para continuar.\n");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto inicio;
		}
	}

	else{
		printf("\n\tNome: ");
        scanf(" %[^\n]s", &cliente.nome);

		printf("\n\tTelefone com o (ddd)9XXXXXXXX: ");
		scanf("%s", &cliente.tel);

		printf("\n\tCodigo do cliente: ");
		scanf("%d", &cliente.codigo);

		cliente.status = 1;
		arq_cliente = fopen("arq_cliente.txt", "a+");
		fwrite(&cliente, sizeof(cliente), 1, arq_cliente);
		fclose(arq_cliente);
		printf("\n\n\tCadastro efetuado com sucesso!\n");
		printf("\n\tAperte Enter para continuar.\n");
		scanf("%c", &esc);
		if(esc != 0){
			system("cls");
		}
	}

}

void edit_cliente(){
    system("color f4");
	inicio:
	printf("\n   ÚÄÄÄÄÄÄÄÄ C L I E N T EÄÄÄÄÄÄÄÄ¿\n");
   printf("   ³                              ³\n");
   printf("   ³         E D I T A R          ³\n");
   printf("   ³                              ³\n");
   printf("   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
   printf("\n");
	printf("\tInsira o CPF: ");
	char esc;
	lestring(cliente.cpf, 12);

	resultadobuscacpf = busca_cpf(cliente.cpf);
	resultadoverificacpf = verifica_cpf(cliente.cpf);

	if(resultadoverificacpf != 1){
		printf("\n\n\tErro! O CPF digitado e invalido. Insira um CPF valido\n\n");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto inicio;
		}
	}

	else if(resultadobuscacpf == -1){
		printf("\n\n\tErro! O CPF digitado nao esta cadastrado. Insira um novo CPF\n\n");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto inicio;
		}
	}

	else if(resultadobuscacpf != -1){
		editar_cliente(resultadobuscacpf);
	}
}

void editar_cliente(int posicao){

	int resultado_busca_cpf, resultado_verifica_cpf;

	Tcliente reg;
	FILE *arq_cliente;
	char esc;


	arq_cliente = fopen("arq_cliente.txt", "r+");


	if(arq_cliente == NULL){
		arq_cliente = fopen("arq_cliente.txt", "w");
	}

	else{
		fseek(arq_cliente, sizeof(reg) * (posicao), SEEK_SET);
		fread(&reg, sizeof(reg), 1, arq_cliente);
		if(reg.status == 0){
			printf("\n\n\tErro! O CPF esta excluido. Acesse o menu Lixeira.\n\n");
			getchar();
			scanf("%c", &esc);
				if(esc != 0){
					system("cls");
			}
		}
		else{
			printf("\n\tNome: %s", reg.nome);
			printf("\n\tCPF: %s", reg.cpf);
			printf("\n\tTelefone: %s\n\n", reg.tel);
			printf("\n\tCodigo: %d\n\n", reg.codigo);

			printf("\tDigite os novos dados:\n");
			printf("\n\tNome: ");
          scanf(" %[^\n]s", &reg.nome);



			printf("\n\tCPF: ");
			lestring(reg.cpf, 12);
			resultado_verifica_cpf = verifica_cpf(reg.cpf);

			resultado_busca_cpf = busca_cpf(reg.cpf);

			if(resultado_verifica_cpf != 1){
				printf("\n\tErro! O CPF digitado e invalido. Edicao cancelada.");
				getchar();
				scanf("%c", &esc);
				if(esc != 0){
					system("cls");
				}
			}
			else if(resultado_busca_cpf != -1 && resultado_busca_cpf != posicao){
				printf("\n\tErro! O CPF digitado ja existe. Edicao cancelada.");
				getchar();
				scanf("%c", &esc);
				if(esc != 0){
					system("cls");
				}
			}

			else if(resultado_busca_cpf == -1 || resultado_busca_cpf == posicao){
				printf("\n\tCodigo: ");
				scanf("%d", &reg.codigo);
				printf("\n\tTelefone: ");
				scanf("%s", &reg.tel);

				fseek(arq_cliente, sizeof(reg) * (posicao), SEEK_SET);
				fwrite(&reg, sizeof(reg), 1, arq_cliente);
				fclose(arq_cliente);

				printf("\n\n\tCliente editado com sucesso! Pressione Enter pra continuar.\n");
				getchar(); system("cls");
			}
		}
	}
}

void search_cliente(){
    system("color f4");
	inicio:
	printf("\n   ÚÄÄÄÄÄÄÄÄ C L I E N T EÄÄÄÄÄÄÄÄ¿\n");
   printf("   ³                              ³\n");
   printf("   ³         P E S Q U I S A R    ³\n");
   printf("   ³                              ³\n");
   printf("   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
   printf("\n");
	printf("\tInsira o CPF: ");
	char esc;
	Tcliente reg;
	FILE *arq_cliente;
	lestring(cliente.cpf, 12);
	resultadobuscacpf = busca_cpf(cliente.cpf);

	resultadoverificacpf = verifica_cpf(cliente.cpf);

	if(resultadoverificacpf != 1){
		printf("\n\n\tErro! O CPF digitado e invalido. Insira um CPF valido\n\n");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto inicio;
		}
	}

	else if(resultadobuscacpf == -1){
		printf("\n\n\tErro! O CPF digitado nao esta cadastrado.\n\tAperte Enter e insira um novo CPF\n\n");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto inicio;
		}
	}

	else if(resultadobuscacpf != -1){

		arq_cliente = fopen("arq_cliente.txt", "r");

		if(arq_cliente == NULL){
			arq_cliente = fopen("arq_cliente.txt", "w");
		}

		else{
			fseek(arq_cliente, sizeof(reg) * (resultadobuscacpf), SEEK_SET);

			fread(&reg, sizeof(reg), 1, arq_cliente);

			if(reg.status == 0){
				printf("\n\n\tErro! O CPF esta excluido. Acesse o menu Lixeira.\n\n");
				getchar();
				scanf("%c", &esc);
				if(esc != 0){
					system("cls");
				}
			}
			else{
				printf("\n\tNome: %s", reg.nome);
				printf("\n\tCPF: %s", reg.cpf);
				printf("\n\tTelefone: %s\n\n", reg.tel);
				printf("\n\tCodigo: %d\n\n", reg.codigo);
				tab:
				printf("\n\tFazer outra pesquisa? (S/N) ");
				getchar();
				scanf("%c", &esc);
				if(esc == 'S' || esc == 's'){
					system("cls"); goto inicio;
				}
				else if(esc == 'N' || esc == 'n'){
					system("cls");
				}
				else
					goto tab;
			}
		}
	}
}

void cliente_inativo(int posicao){
	Tcliente reg;
	FILE *arq_cliente;

	arq_cliente = fopen("arq_cliente.txt", "r");

	if(arq_cliente == NULL){
		arq_cliente = fopen("arq_cliente.txt", "w");
	}

	else{
		fseek(arq_cliente, sizeof(reg) * (posicao), 0);

		fread(&reg, sizeof(reg), 1, arq_cliente);

		printf("\n\tNome: %s", reg.nome);
		printf("\n\tCPF: %s", reg.cpf);
		printf("\n\tTelefone: %s\n\n", reg.tel);
		printf("\n\tCodigo: %d\n\n", reg.codigo);
		fclose(arq_cliente);
	}
}

void delete_cliente(){
    system("color f4");
	inicio:
printf("\n   ÚÄÄÄÄÄÄÄÄ C L I E N T EÄÄÄÄÄÄÄÄ¿\n");
   printf("   ³                              ³\n");
   printf("   ³         E X C L U I R        ³\n");
   printf("   ³                              ³\n");
   printf("   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
   printf("\n");
	printf("\tInsira o CPF: ");
	char esc;
	Tcliente reg;
	FILE *arq_cliente;
	lestring(cliente.cpf, 12);
	resultadobuscacpf = busca_cpf(cliente.cpf);
	resultadoverificacpf = verifica_cpf(cliente.cpf);
	if(resultadoverificacpf != 1){
		printf("\n\n\tErro! O CPF digitado e invalido. Insira um CPF valido\n\n");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto inicio;
		}
	}

	else if(resultadobuscacpf == -1){
		printf("\n\n\tErro! O CPF digitado nao esta cadastrado.\n\tAperte Enter e insira um novo CPF\n\n");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto inicio;
		}
	}

	else if(resultadobuscacpf != -1){

		arq_cliente = fopen("arq_cliente.txt", "r+");

		if(arq_cliente == NULL){
			arq_cliente = fopen("arq_cliente.txt", "w");
		}

		else{
			fseek(arq_cliente, sizeof(reg) * (resultadobuscacpf), SEEK_SET);
			fread(&reg, sizeof(reg), 1, arq_cliente);
			if(reg.status == 0){
				printf("\n\n\tErro! O CPF esta excluido. Acesse o menu Lixeira.\n\n");
				getchar();
				scanf("%c", &esc);
				if(esc != 0){
					system("cls");
				}
			}
			else{
				printf("\n\tNome: %s", reg.nome);
				printf("\n\tCPF: %s", reg.cpf);
				printf("\n\ttefone: %s\n\n", reg.tel);
				tab:
				printf("\n\tDeseja realmente excluir? (S/N) ");
				getchar();
				scanf("%c", &esc);

				if(esc == 'S' || esc == 's'){
					reg.status = 0;
					fseek(arq_cliente, sizeof(reg) * (resultadobuscacpf), SEEK_SET);
					fwrite(&reg, sizeof(reg), 1, arq_cliente);

					fclose(arq_cliente);
					printf("\n\tCliente excluido com sucesso!\n\n\tPressione Enter pra continuar.");
					getchar();
					scanf("%c", &esc);
					if(esc != 0){
						system("cls");
					}
				}

				else if(esc == 'N' || esc == 'n'){
					printf("\n\tExclusao cancelada!\n\n\tPressione Enter para retornar ao Menu Principal.");
					getchar();
					scanf("%c", &esc);
					if(esc != 0){
						system("cls");
					}
				}
				else
					goto tab;
			}
		}
	}

}

void restaurar_cliente(){
    system("color f4");
	inicio:
printf("\n   ÚÄÄÄÄÄÄÄÄ C L I E N T EÄÄÄÄÄÄÄÄ¿\n");
   printf("   ³                              ³\n");
   printf("   ³         R E S T A U R A R    ³\n");
   printf("   ³                              ³\n");
   printf("   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
   printf("\n");
	printf("\tDigite o CPF a ser restaurado: ");
	char esc;

	lestring(cliente.cpf, 12);

	resultadobuscacpf = busca_cpf(cliente.cpf);

	resultadoverificacpf = verifica_cpf(cliente.cpf);

	if(resultadoverificacpf != 1){
		printf("\n\n\tErro! O CPF digitado e invalido. Insira um CPF valido\n\n");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto inicio;
		}
	}
	else if(resultadobuscacpf == -1){
		printf("\n\n\tErro! O CPF digitado nao esta cadastrado. Insira um novo CPF\n\n");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto inicio;
		}
	}
	else if(resultadobuscacpf != -1){
		cliente_inativo(resultadobuscacpf);
		restaura_cliente(resultadobuscacpf);
	}
}

void restaura_cliente(int posicao){
	Tcliente reg;
	FILE *arq_cliente;
	char esc, sai;

	arq_cliente = fopen("arq_cliente.txt", "r+");

	if(arq_cliente == NULL){
		arq_cliente = fopen("arq_cliente.txt", "w");
	}

	else{
		fseek(arq_cliente, sizeof(reg) * (posicao), SEEK_SET);

		fread(&reg, sizeof(reg), 1, arq_cliente);

		printf("\n\tDeseja realmente restaurar este cliente? (S/N) ");
		getchar();
		scanf("%c", &esc);

		if((esc == 'S') || (esc == 's')){
			reg.status = 1;

			fseek(arq_cliente, sizeof(reg) * (posicao), SEEK_SET);
			fwrite(&reg, sizeof(reg), 1, arq_cliente);
			fclose(arq_cliente);
			printf("\n\tCliente restaurado com sucesso!\n\tPressione Enter pra continuar.");
			getchar();
			scanf("%c", &sai);
			if(sai != 0){
				system("cls");
			}
		}
		else if((esc == 'N') || (esc == 'n')){
			printf("\n\tRestauracao cancelada!\n\tPressione Enter pra continuar.");
			getchar();
			scanf("%c", &sai);
			if(sai != 0){
				system("cls");
			}
		}
		else{
			printf("\n\tErro! O cliente nao esta excluido.\n\tPressione Enter pra continuar.");
			getchar();
			scanf("%c", &sai);
			if(sai != 0){
				system("cls");
			}
		}
	}
}

void cliente_excluido(){
	int num = 1;
	char esc;
	Tcliente reg;
	FILE *arq_cliente;
	arq_cliente = fopen("arq_cliente.txt", "r");

	if(arq_cliente == NULL){
            system("color f4");
		printf("\n   ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
   printf("   ³                              ³\n");
   printf("   ³         CLENTES EXCLUIDOS    ³\n");
   printf("   ³                              ³\n");
   printf("   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		printf("\n\tNumero Nome\t\t\tCPF\t\tTelefone\tcodigon\n");
		arq_cliente = fopen("arq_cliente.txt", "w");

	}
	else{
	    system("color f4");
		printf("\n   ÚÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ¿\n");
   printf("   ³                              ³\n");
   printf("   ³         CLENTES EXCLUIDOS    ³\n");
   printf("   ³                              ³\n");
   printf("   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
		printf("\n\tNumero Nome\t\t\tCPF\t\tTelefone\tcodigon\n");

		fread(&reg, sizeof(reg), 1, arq_cliente);

		while(!feof(arq_cliente)){
			if(reg.status == 0){
				printf("\t %d", num);
				printf("   %s\t\t", reg.nome);
				printf("%s", reg.cpf);
				printf("\t%s\n", reg.tel);
				printf("\t%s\n", reg.codigo);
				num++;
			}
			fread(&reg, sizeof(reg), 1, arq_cliente);
		}
	}
	fclose(arq_cliente);
	system("color f4");
	printf("\n\n\n\t============= Fim! Pressione Enter para continuar ==============\n");
	getchar();
	scanf("%c", &esc);
	if(esc != 0){
		system("cls");
	}
}

void lixeira_cliente(){
    system("color f4");
	int menu = 0;
	printf("\n   ÚÄÄÄÄÄÄÄÄ C L I E N T EÄÄÄÄÄÄÄÄ¿\n");
    printf("   ³                              ³\n");
    printf("   ³         L I X E I R A        ³\n");
    printf("   ³                              ³\n");
	printf("   ³(1) Exibir lixeira            ³\n");
	printf("   ³(2) Restaurar Cliente         ³\n");
	printf("   ³(3) Esvaziar Lixeira          ³\n");
	printf("   ³(4) Voltar ao Menu Cliente    ³\n");
	printf("   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
	printf("\n\t Op%c%co: ", 135, 198);
	scanf("%d", &menu);
	system("cls");
	switch(menu){

		case 1:
			cliente_excluido(); break;

		case 2:
			restaurar_cliente(); break;

		case 3:
			esvaziar_lixeira(); break;

		case 4:
			menu_cliente(); break;
	}
}

void esvaziar_lixeira(){
    system("color f4");
	inicio:
	printf("\tÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀ\n");
	printf("\tÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀÀ Esvaziar Lixeira ÀÀÀÀÀÀÀÀÀÀÀÀ===========\n");
	printf("\t================================================================\n\n");
	printf("\tDigite o CPF a ser excluido: ");
	char esc;
	lestring(cliente.cpf, 12);

	resultadobuscacpf = busca_cpf(cliente.cpf);

	resultadoverificacpf = verifica_cpf(cliente.cpf);

	if(resultadoverificacpf != 1){
		printf("\n\n\tErro! O CPF digitado e invalido. Insira um CPF valido\n\n");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto inicio;
		}
	}

	else if(resultadobuscacpf == -1){
		printf("\n\n\tErro! O CPF digitado nao esta cadastrado. Insira um novo CPF\n\n");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto inicio;
		}
	}
	else if(resultadobuscacpf != -1){
		cliente_inativo(resultadobuscacpf);
		esvazia_lixeira(resultadobuscacpf);
	}
}

void esvazia_lixeira(int posicao){
	Tcliente reg;
	FILE *arq_cliente;
	char esc, excluido[30];

	arq_cliente = fopen("arq_cliente.txt", "r+");

	if(arq_cliente == NULL){
		arq_cliente = fopen("arq_cliente.txt", "w");
	}

	fseek(arq_cliente, sizeof(reg) * (posicao), SEEK_SET);

	fread(&reg, sizeof(reg), 1, arq_cliente);

	tab:
	printf("\n\tDeseja realmente excluir definitivamente? (S/N) ");
	getchar();
	scanf("%c", &esc);

	if((esc == 'S') || (esc == 's')){
		FILE *arq_temp;

		arq_temp = fopen("arq_temp.txt", "w");

		fseek(arq_cliente, sizeof(reg) * (posicao), SEEK_SET);

		fread(&reg, sizeof(reg), 1, arq_cliente);

		strcpy(excluido, reg.cpf);

		rewind(arq_cliente);

		fread(&reg, sizeof(reg), 1, arq_cliente);

		while(!feof(arq_cliente)){

			if(strcmp(reg.cpf, excluido) != 0){
				fwrite(&reg, sizeof(reg), 1, arq_temp);
			}
			fread(&reg, sizeof(reg), 1, arq_cliente);
		}


		fclose(arq_cliente); fclose(arq_temp);

		arq_cliente = fopen("arq_cliente.txt", "w");
		arq_temp = fopen("arq_temp.txt", "r+");

		fread(&reg, sizeof(reg), 1, arq_temp);
		while(!feof(arq_temp)){
			fwrite(&reg, sizeof(reg), 1, arq_cliente);
			fread(&reg, sizeof(reg), 1, arq_temp);
		}

		fclose(arq_cliente); fclose(arq_temp);
		remove("arq_temp.txt");

		printf("\n\tCliente excluido com sucesso!\n\tPressione Enter pra continuar.");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls");
		}
	}
	else if(esc == 'N' || esc == 'n'){
		printf("\n\tExclusao cancelada!\n\tPressione Enter para retornar ao Menu Principal.");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls");
		}
	}
	else{
		goto tab;
	}
}

/// ////////////////////////////////////////// /////////////////////////////////// TATUAGEM
void cadastro_tatuagem(){
    system("color f5");
	tab:
	printf("\n   ÚÄÄÄÄÄÄÄÄT A T U A G E MÄÄÄÄÄÄÄ¿\n");
   printf("   ³                              ³\n");
   printf("   ³         C A D A S T R O      ³\n");
   printf("   ³                              ³\n");
   printf("   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
   printf("\n");
	printf("\tTatuagem: ");
	char esc;
	scan_tattoo(tatuagem.tattoo, 16);

	resultadobuscatattoo = busca_tattoo(tatuagem.tattoo);

	if(strcmp(tatuagem.tattoo,"") == 1){
		printf("\n\tErro! O campo tattoo nao pode ser vazio. Insira uma nova tattoo.\n\tPressione Enter para continuar!");
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto tab;
		}
	}
	else if(resultadobuscatattoo != -1){
		printf("\n\n\tErro! A tattoo ja esta cadastrada.\n\tInsira uma nova tattoo.");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto tab;
		}
	}
	else if(resultadobuscatattoo == -1){
		printf("\n\tRepete novamente o Nome da tatuagem: ");
		scanf (" %[^\n]s",&tatuagem.nome);

		printf("\n\tTamanho: ");
		scanf (" %[^\n]s", &tatuagem.tamanho);

		printf("\n\tValor da tatuagem R$: ");
		scanf("%f", &tatuagem.valor);
		arq_tatuagem = fopen("arq_tatuagem.txt", "a+");
		fwrite(&tatuagem, sizeof(tatuagem), 1, arq_tatuagem);

		printf("\n\n\tCadastro efetuado com sucesso!");
		printf("\n\tAperte Enter para continuar.\n");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls");
		}
		fclose(arq_tatuagem);
	}
}

void edit_tatuagem(){
    system("color f5");
	tab:
	printf("\n   ÚÄÄÄÄÄÄÄÄT A T U A G E MÄÄÄÄÄÄÄ¿\n");
   printf("   ³                              ³\n");
   printf("   ³         E D I T A R          ³\n");
   printf("   ³                              ³\n");
   printf("   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
   printf("\n");
	printf("\tDigite a tattoo: ");
	char esc;


	scan_tattoo(tatuagem.tattoo, 8);
	resultadobuscatattoo = busca_tattoo(tatuagem.tattoo);

	if(resultadobuscatattoo != -1){
		editar_tatuagem(resultadobuscatattoo);
	}

	else if(strcmp(tatuagem.tattoo,"") == 0){
		printf("\n\tErro! O campo tattoo nao pode ser vazio. Insira uma nova tattoo.\n");
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto tab;
		}
	}
	else if(resultadobuscatattoo == -1){
		printf("\n\n\tErro! A tattoo nao esta cadastrada.\n\tInsira uma nova tattoo.\n");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); fflush(stdin); goto tab;
		}
	}
}

void editar_tatuagem(int posicao){
	int resultado_busca_tattoo;
	char esc;
	Ttatuagem reg;
	FILE *arq_tatuagem;
	tab:
	arq_tatuagem = fopen("arq_tatuagem.txt", "r+");
	if(arq_tatuagem == NULL){
		arq_tatuagem = fopen("arq_tatuagem.txt", "w");
	}

	else{
		fseek(arq_tatuagem, sizeof(reg) * (posicao), SEEK_SET);
		fread(&reg, sizeof(reg), 1, arq_tatuagem);
		if(reg.status == 0){
			printf("\t\n\nErro! O tatuagem esta excluido. Acesse o menu Lixeira.\n\n");
			getchar();
			scanf("%c", &esc);
			if(esc != 0){
				system("cls");
			}
		}
		else{
			printf("\n\ttattoo: %s", reg.tattoo);
			printf("\n\tnome: %s", reg.nome);
			printf("\n\ttamanho: %s", reg.tamanho);
			printf("\n\tValor valor R$: %.2f", reg.valor);
			printf("\n\n\tDigite os novos dados:\n");

			printf("\n\ttattoo: ");
			scan_string(reg.tattoo, 8);

			resultado_busca_tattoo = busca_tattoo(reg.tattoo);

			if(strcmp(reg.tattoo,"") == 0){
				printf("\n\tErro! O campo tattoo nao pode ser vazio. Insira uma nova tattoo.\n\tPressione Enter para continuar!");
				getchar();
				scanf("%c", &esc);
				if(esc != 0){
					system("cls"); goto tab;
				}
			}

			else if(resultado_busca_tattoo != -1 && resultado_busca_tattoo != posicao){
				printf("\n\tErro! A tattoo digitada ja existe. Edicao cancelada.\n\tPressione Enter para continuar.");
				getchar();
				scanf("%c", &esc);
				if(esc != 0){
					system("cls");
				}
			}
			else if(resultado_busca_tattoo == -1 || resultado_busca_tattoo == posicao){
				printf("\n\tNome: ");
		scanf (" %[^\n]s",tatuagem.nome);

		printf("\n\tTamanho: ");
		scanf (" %[^\n]s", &tatuagem.tamanho);

		printf("\n\tValor da tatuagem R$: ");
		scanf("%f", &tatuagem.valor);
				fseek(arq_tatuagem, sizeof(reg) * (posicao), SEEK_SET);
				fwrite(&reg, sizeof(reg), 1, arq_tatuagem);
				fclose(arq_tatuagem);

				printf("\n\n\ttatuagem editado com sucesso!");
				printf("\n\tAperte Enter para continuar.\n");
				getchar();
				scanf("%c", &esc);
				if(esc != 0){
					system("cls");
				}
			}
		}
	}
}

void search_tatuagem(){
    system("color f5");
	inicio:
	printf("\n   ÚÄÄÄÄÄÄÄÄT A T U A G E MÄÄÄÄÄÄÄ¿\n");
   printf("   ³                              ³\n");
   printf("   ³         P E S Q U I S A R    ³\n");
   printf("   ³                              ³\n");
   printf("   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
   printf("\n");
	printf("\tDigite a tattoo: ");
	char esc;
	Ttatuagem reg;
	FILE *arq_tatuagem;
	scan_tattoo(tatuagem.tattoo, 8);

	resultadobuscatattoo = busca_tattoo(tatuagem.tattoo);

	if(strcmp(tatuagem.tattoo,"") == 0){
		printf("\n\tErro! O campo tattoo nao pode ser vazio. Insira uma nova tattoo.\n\t");
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto inicio;
		}
	}
	else if(resultadobuscatattoo == -1){
		printf("\n\n\tErro! A tattoo nao esta cadastrada.\n\tInsira uma nova tattoo.");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto inicio;
		}
	}
	else if(resultadobuscatattoo != -1){

		arq_tatuagem = fopen("arq_tatuagem.txt", "r");

		if(arq_tatuagem == NULL){
			arq_tatuagem = fopen("arq_tatuagem.txt", "w");
		}

		else{

			fseek(arq_tatuagem, sizeof(reg) * (resultadobuscatattoo), 0);

			fread(&reg, sizeof(reg), 1, arq_tatuagem);

			if(reg.status == 0){
				printf("\n\n\tErro! O tatuagem esta excluido. Acesse o menu Lixeira.\n\n");
				getchar();
				scanf("%c", &esc);
				if(esc != 0){
					system("cls");
				}
			}
			else{
				printf("\n\ttattoo: %s", reg.tattoo);
				printf("\n\tnome: %s", reg.nome);
				printf("\n\ttamanho: %s", reg.tamanho);
				printf("\n\tValor valor R$: %.2f", reg.valor);
				tab:
				printf("\n\n\tFazer outra pesquisa? (S/N) ");
				getchar();
				scanf("%c", &esc);
				if(esc == 'S' || esc == 's'){
					system("cls"); goto inicio;
				}
				else if(esc == 'N' || esc == 'n'){
					system("cls");
				}
				else
					goto tab;
			}
		}
	}
}

void delete_tatuagem(){
    system("color f5");
	inicio:
	printf("\n   ÚÄÄÄÄÄÄÄÄT A T U A G E MÄÄÄÄÄÄÄ¿\n");
   printf("   ³                              ³\n");
   printf("   ³         E X C L U I R        ³\n");
   printf("   ³                              ³\n");
   printf("   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
   printf("\n");
	printf("\tDigite a tattoo: ");
	char esc;
	Ttatuagem reg;
	FILE *arq_tatuagem;
	scan_tattoo(tatuagem.tattoo, 8);

	resultadobuscatattoo = busca_tattoo(tatuagem.tattoo);

	if(strcmp(tatuagem.tattoo,"") == 0){
		printf("\n\tErro! O campo tattoo nao pode ser vazio. Insira uma nova tattoo.\n\t");
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto inicio;
		}
	}
	else if(resultadobuscatattoo == -1){
		printf("\n\n\tErro! A tattoo nao esta cadastrada.\n\tInsira uma nova tattoo.");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto inicio;
		}
	}

	else if(resultadobuscatattoo != -1){

		arq_tatuagem = fopen("arq_tatuagem.txt", "r+");
		if(arq_tatuagem == NULL){
			arq_tatuagem = fopen("arq_tatuagem.txt", "w");
		}

		else{

			fseek(arq_tatuagem, sizeof(reg) * (resultadobuscatattoo), SEEK_SET);
			fread(&reg, sizeof(reg), 1, arq_tatuagem);
			printf("\n\ttattoo: %s", reg.tattoo);
			printf("\n\tnome: %s", reg.nome);
			printf("\n\ttamanho: %s", reg.tamanho);
			printf("\n\tValor valor R$: %.2f", reg.valor);
			tab:
			printf("\n\n\tDeseja realmente excluir? (S/N) ");
			getchar();
			scanf("%c", &esc);
			if(esc == 'S' || esc == 's'){

				reg.status = 0;

				fseek(arq_tatuagem, sizeof(reg) * (resultadobuscatattoo), SEEK_SET);

				fwrite(&reg, sizeof(reg), 1, arq_tatuagem);

				fclose(arq_tatuagem);

				printf("\n\ttatuagem excluido com sucesso!\n\n\tPressione Enter pra continuar.");
				getchar();
				scanf("%c", &esc);
				if(esc != 0){
					system("cls");
				}
			}
			else if(esc == 'N' || esc == 'n'){
				printf("\n\tExclusao cancelada!\n\n\tPressione Enter para retornar ao Menu Principal.");
				getchar();
				scanf("%c", &esc);
				if(esc != 0){
					system("cls");
				}
			}
			else{
				goto tab;
			}
		}
	}
}

void sobre_tatuagem(){
    system("color f5");
    setlocale(LC_ALL, "Portuguese");
    int menu = 0;
      printf("   |-----------------------------------|\n");
      printf("   |-----------------------------------|\n");
      printf("   | <1>      P o n t i l h i s m o    |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <2>      O l d   S c h o o l      |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <3>      T r í b a l              |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <4>      L e t t e r i n g        |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <5>      M a o r i                |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <6>      N e w   S c h o o l      |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <7>      A q u a r e l a          |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <8>      C é l t i c o            |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <9>      B l a c k w o r k        |\n");
      printf("   |-----------------------------------|\n");
      printf("   | <10>     C e l t a                |\n");
      printf("   $-----------------------------------$");
      printf("\n\n\n");
      printf("Qual das tatuagem deseja saber um pouco sobre, o preço e tamanho:");
      scanf("%d", &menu);
	system("cls");
	switch(menu){

case 3:
printf("*-----*--------*--------*-----*--------*--------*-----*--------*---------*\n");
printf("|                    .::T r í b a l ::.                         | TA     |\n");
printf("*-----*--------*--------*-----*--------*---------*-----*--------*        *\n");
printf("|Ele remete a desenhos feitos por tribos| PREÇO  |   TAMANHO    | TU     |\n");
printf("* e civilizações antigas como os maias  *--------|--------------*     RA *\n");
printf("| incas, nativos norte-americanos,      | R$ 300 |    Pequena   | A      |\n");
printf("* entre outros povos. Elas são          *--------|--------------*     CO *\n");
printf("| geralmente de cor preta e são         | R$ 870 |    Média     | DO     |\n");
printf("* compostas de sólidos desenhos         *--------|--------------*     SA *\n");
printf("| geométricos.                          | R$ 1600|    Grande    | RA     |\n");
printf("*-----*--------*--------*-----*--------*--------|--------------*---------*\n");
break;


case 4:
printf("*-----*--------*--------*-----*--------*--------*-----*--------*--------*\n");
printf("|                    .::L e t t e r i n g ::.                  | TA     |\n");
printf("*-----*--------*--------*-----*--------*--------*-----*--------*        *\n");
printf("|É a arte de desenhar e criar letras.  | PREÇO  |   TAMANHO    | TU     |\n");
printf("* Liberdade para criar e explorar, o   *--------|--------------*     RA *\n");
printf("| estilo tem origem tornando a tatuagem| R$ 50 |    Pequena   | A      |\n");
printf("* em uma ilustração original em forma  *--------|--------------*     CO *\n");
printf("| de escrita.                          | R$ 100 |    Média     | DO     |\n");
printf("*                                      *--------|--------------*     SA *\n");
printf("|                                      | R$ 125 |    Grande    | RA     |\n");
printf("*-----*--------*--------*-----*--------*--------|--------------*--------*\n");
break;

case 5:
printf("*-----*--------*--------*-----*--------*--------*-----*--------*--------*\n");
printf("|                    .::M a o r i::.                           | TA     |\n");
printf("*-----*--------*--------*-----*--------*--------*-----*--------*        *\n");
printf("|É a arte arte indígena da New Zelândia| PREÇO  |   TAMANHO    | TU     |\n");
printf("* e traz desenhos como flores, rostos, *--------|--------------*     RA *\n");
printf("| animais e formas abstratas. Antes    | R$ 300 |    Pequena   | A      |\n");
printf("* de fazer a tattoo Maori é importante *--------|--------------*     CO *\n");
printf("| se certificar do real significado do | R$ 850 |    Média     | DO     |\n");
printf("* símbolo a tatuar.                    *--------|--------------*     SA *\n");
printf("|                                      | R$ 1550|    Grande    | RA     |\n");
printf("*-----*--------*--------*-----*--------*--------|--------------*--------*\n");
break;

case 6:
printf("*-----*--------*--------*-----*--------*--------*-----*--------*--------*\n");
printf("|                    .::N e w   S c h o o l::.                 | TA     |\n");
printf("*-----*--------*--------*-----*--------*--------*-----*--------*        *\n");
printf("|Como o próprio nome nos leva a deduzir| PREÇO  |   TAMANHO    | TU     |\n");
printf("* trata-se de uma releitura do estilo  *--------|--------------*     RA *\n");
printf("| Old School, com muitas cores,        | R$ 300 |    Pequena   | A      |\n");
printf("* desenhos grandes e fortes contrastes *--------|--------------*     CO *\n");
printf("| e nem sempre em proporções certas.   | R$ 850 |    Média     | DO     |\n");
printf("*                                      *--------|--------------*     SA *\n");
printf("|                                      | R$ 1550|    Grande    | RA     |\n");
printf("*-----*--------*--------*-----*--------*--------|--------------*--------*\n");
break;

case 7:
printf("*-----*--------*--------*-----*--------*--------*-----*--------*--------*\n");
printf("|                    .::A q u a r e l a::.                     | TA     |\n");
printf("*-----*--------*--------*-----*--------*--------*-----*--------*        *\n");
printf("|Seus desenhos se assemelham ao traço  | PREÇO  |   TAMANHO    | TU     |\n");
printf("* fluido feito com tinta aquosa, dando *--------|--------------*     RA *\n");
printf("| o efeito de delicados borrões. É uma | R$ 470 |    Pequena   | A      |\n");
printf("* técnica de preenchimento, ou seja,   *--------|--------------*     CO *\n");
printf("| pintura de uma tatuagem.             | R$ 850 |    Média     | DO     |\n");
printf("*                                      *--------|--------------*     SA *\n");
printf("|                                      | R$ 1150|    Grande    | RA     |\n");
printf("*-----*--------*--------*-----*--------*--------|--------------*--------*\n");
break;
case 8:

printf("*-----*--------*--------*-----*--------*--------*-----*--------*--------*\n");
printf("|                    .::C é l t i c o ::.                      | TA     |\n");
printf("*-----*--------*--------*-----*--------*--------*-----*--------*        *\n");
printf("|Eles vêm em muitas formas,como cruzes,| PREÇO  |   TAMANHO    | TU     |\n");
printf("* espirais, animais e árvores da vida  *--------|--------------*     RA *\n");
printf("| o efeito de delicados borrões. É uma | R$ 470 |    Pequena   | A      |\n");
printf("* técnica de preenchimento, ou seja,   *--------|--------------*     CO *\n");
printf("| pintura de uma tatuagem.             | R$ 850 |    Média     | DO     |\n");
printf("* Este estilo é o preferido pelas      *--------|--------------*     SA *\n");
printf("| que se interessam pelo folclore galês| R$ 1150|    Grande    | RA     |\n");
printf("*-----*--------*--------*-----*--------*--------|--------------*--------*\n");
break;




case 9:
printf("*-----*--------*--------*-----*--------*--------*-----*--------*--------*\n");
printf("|                    .::B l a c k w o r k::.                   | TA     |\n");
printf("*-----*--------*--------*-----*--------*--------*-----*--------*        *\n");
printf("|A tinta preta é a protagonista        |  PREÇO |   TAMANHO    | TU     |\n");
printf("* principal e o desenho é contado      |*--------|--------------*     RA *\n");
printf("| a partir da presença ou da ausência  | R$ 470 |    Pequena   | A      |\n");
printf("* do pigmento. Diferente dos outros    *--------|--------------*     CO *\n");
printf("| estilos, conceitos e técnicas, o     | R$ 850 |    Média     | DO     |\n");
printf("* “trabalho em preto” não se concentra *--------|--------------*     SA *\n");
printf("| muito significados, mas sim no design| R$ 1150|    Grande    | RA     |\n");
printf("*-----*--------*--------*-----*--------*--------|--------------*--------*\n");
break;

case 10:
printf("*-----*--------*--------*-----*--------*--------*-----*--------*--------*\n");
printf("|                    .::O r i e n t a l::.                     | TA     |\n");
printf("*-----*--------*--------*-----*--------*--------*-----*--------*        *\n");
printf("|Em síntese, os desenhos mais comuns   |  PREÇO |   TAMANHO    | TU     |\n");
printf("* encontrados no estilo japonês são o  |*--------|--------------*     RA *\n");
printf("| Kanji (Alfabeto Japonês), princesas, | R$ 100 |    Pequena   | A      |\n");
printf("* guerreiros, seres religiosos, dragões*--------|--------------*     CO *\n");
printf("| e diversos animais. A história do    | R$ 250 |    Média     | DO     |\n");
printf("* Japão com as tatuagens  tem seus     *--------|--------------*     SA *\n");
printf("| primeiros contos em 10.000 A.C       | R$ 700 |    Grande    | RA     |\n");
printf("*-----*--------*--------*-----*--------*--------|--------------*--------*\n");

	        break;
}
}
void lixeira_tatuagem(){
    system("color f5");
	int menu = 0;
    printf("\n   ÚÄÄÄÄÄÄÄÄT A T U A G E MÄÄÄÄÄÄÄ¿\n");
    printf("   ³                              ³\n");
    printf("   ³         L I X E I R A        ³\n");
    printf("   ³                              ³\n");
	printf("   ³(1) Exibir lixeira            ³\n");
	printf("   ³(2) Restaurar Tatuagem         ³\n");
	printf("   ³(3) Esvaziar Lixeira          ³\n");
	printf("   ³(4) Voltar ao Menu Tatuagem    ³\n");
	printf("   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
	printf("\t\t\t      Qual op%c%co desejada:\t", 135, 198);
	scanf("%d", &menu);
	system("cls");
	switch(menu){

		case 1:
			tatuagem_excluido(); break;

		case 2:
			restaurar_tatuagem(); break;

		case 3:
			esvaziarLixeira(); break;

		case 4:
			menu_tatuagem(); break;
	}
}

void tatuagem_excluido(){
    system("color f5");
	int num = 1;
	char esc;

	Ttatuagem reg;
	FILE *arq_tatuagem;

	arq_tatuagem = fopen("arq_tatuagem.txt", "r");

	if(arq_tatuagem == NULL){
		printf("\t================================================================\n");
		printf("\t====================== tatuagems Excluidos ======================\n");
		printf("\t================================================================\n");
		printf("\n\tNumero    tattoo    \ttamanho\t   \tnome\t  \tAno \n");
		arq_tatuagem = fopen("arq_tatuagem.txt", "w");
	}
	else{
		printf("\t================================================================\n");
		printf("\t====================== tatuagems Excluidos ======================\n");
		printf("\t================================================================\n");
		printf("\n\tNumero    tattoo    \ttamanho\t   \tnome\t  \tAno \n");

		fread(&reg, sizeof(reg), 1, arq_tatuagem);

		while(!feof(arq_tatuagem)){
			if(reg.status == 0){
				printf("\t  %s", reg.tattoo);
				printf("\t%s", reg.tamanho);
				printf("\t\t%s", reg.nome);
				num++;
			}
			fread(&reg, sizeof(reg), 1, arq_tatuagem);
		}
	}
	fclose(arq_tatuagem);
	printf("\n\n\n\t============= Fim! Pressione Enter para continuar ==============\n");
	getchar();
	scanf("%c", &esc);
	if(esc != 0){
		system("cls");
	}
}

void restaurar_tatuagem(){
    system("color f5");
	inicio:
	printf("\n   ÚÄÄÄÄÄÄÄÄT A T U A G E MÄÄÄÄÄÄÄ¿\n");
   printf("   ³                              ³\n");
   printf("   ³         R E S T A U R A R    ³\n");
   printf("   ³                              ³\n");
   printf("   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
   printf("\n");
	printf("\tDigite a tattoo do tatuagem a ser restaurado: ");
	char esc;

	scan_tattoo(tatuagem.tattoo, 8);

	resultadobuscatattoo = busca_tattoo(tatuagem.tattoo);

	if(strcmp(tatuagem.tattoo,"") == 0){
		printf("\n\tErro! O campo tattoo nao pode ser vazio. Insira uma nova tattoo.\n");
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto inicio;
		}
	}
	else if(resultadobuscatattoo == -1){
		printf("\n\n\tErro! A tattoo nao esta cadastrada.\n\tInsira uma nova tattoo.\n");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); fflush(stdin); goto inicio;
		}
	}

	else if(resultadobuscatattoo != -1){
		tatuagem_inativo(resultadobuscatattoo);
		restaura_tatuagem(resultadobuscatattoo);
	}
}

void tatuagem_inativo(int posicao){
	Ttatuagem reg;
	FILE *arq_tatuagem;

	arq_tatuagem = fopen("arq_tatuagem.txt", "r");

	if(arq_tatuagem == NULL){
		arq_tatuagem = fopen("arq_tatuagem.txt", "w");
	}

	else{
		fseek(arq_tatuagem, sizeof(reg) * (posicao), 0);

		fread(&reg, sizeof(reg), 1, arq_tatuagem);

		printf("\n\ttattoo: %s", reg.tattoo);
		printf("\n\tnome: %s", reg.nome);
		printf("\n\ttamanho: %s", reg.tamanho);
		printf("\n\tValor valor R$: %.2f", reg.valor);
		fclose(arq_tatuagem);
	}
}

void restaura_tatuagem(int posicao){
	Ttatuagem reg;
	FILE *arq_tatuagem;
	char esc, sai;

	arq_tatuagem = fopen("arq_tatuagem.txt", "r+");

	if(arq_tatuagem == NULL){
		arq_tatuagem = fopen("arq_tatuagem.txt", "w");
	}

	else{
		fseek(arq_tatuagem, sizeof(reg) * (posicao), SEEK_SET);

		fread(&reg, sizeof(reg), 1, arq_tatuagem);

		printf("\n\n\tDeseja realmente restaurar este tatuagem? (S/N) ");
		getchar();
		scanf("%c", &esc);

		if((esc == 'S') || (esc == 's')){
			reg.status = 1;

			fseek(arq_tatuagem, sizeof(reg) * (posicao), SEEK_SET);

			fwrite(&reg, sizeof(reg), 1, arq_tatuagem);

			fclose(arq_tatuagem);
			printf("\n\ttatuagem restaurado com sucesso!\n\tPressione Enter pra continuar.");
			getchar();
			scanf("%c", &sai);
			if(sai != 0){
				system("cls");
			}
		}
		else if((esc == 'N') || (esc == 'n')){
			printf("\n\tRestauracao cancelada!\n\tPressione Enter pra continuar.");
			getchar();
			scanf("%c", &sai);
			if(sai != 0){
				system("cls");
			}
		}
		else{
			printf("\n\tErro! O tatuagem nao esta excluido.\n\tPressione Enter pra continuar.");
			getchar();
			scanf("%c", &sai);
			if(sai != 0){
				system("cls");
			}
		}
	}
}

void esvaziarLixeira(){
    system("color f5");
	inicio:
	printf("\n   ÚÄÄÄÄÄÄÄÄT A T U A G E MÄÄÄÄÄÄÄ¿\n");
   printf("   ³                              ³\n");
   printf("   ³         Esvaziar Lixo        ³\n");
   printf("   ³                              ³\n");
   printf("   ÀÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÙ");
   printf("\n");
	printf("\tDigite a tattoo do tatuagem a ser excluido: ");
	char esc;

	scan_tattoo(tatuagem.tattoo, 8);

	resultadobuscatattoo = busca_tattoo(tatuagem.tattoo);

	if(strcmp(tatuagem.tattoo,"") == 0){
		printf("\n\tErro! O campo tattoo nao pode ser vazio. Insira uma nova tattoo.\n");
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); goto inicio;
		}
	}
	else if(resultadobuscatattoo == -1){
		printf("\n\n\tErro! A tattoo nao esta cadastrada.\n\tInsira uma nova tattoo.\n");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls"); fflush(stdin); goto inicio;
		}
	}

	else if(resultadobuscatattoo != -1){
		tatuagem_inativo(resultadobuscatattoo);
		esvaziaLixeira(resultadobuscatattoo);
	}
}

void esvaziaLixeira(int posicao){
	Ttatuagem reg;
	FILE *arq_tatuagem;
	char esc, excluido[8];

	arq_tatuagem = fopen("arq_tatuagem.txt", "r+");

	if(arq_tatuagem == NULL){
		arq_tatuagem = fopen("arq_tatuagem.txt", "w");
	}

	fseek(arq_tatuagem, sizeof(reg) * (posicao), SEEK_SET);

	fread(&reg, sizeof(reg), 1, arq_tatuagem);

	tab:
	printf("\n\n\tDeseja realmente excluir definitivamente? (S/N) ");
	getchar();
	scanf("%c", &esc);

	if((esc == 'S') || (esc == 's')){
		FILE *arq_temp;

		arq_temp = fopen("arq_temp.txt", "w");

		fseek(arq_tatuagem, sizeof(reg) * (posicao), SEEK_SET);

		fread(&reg, sizeof(reg), 1, arq_tatuagem);

		strcpy(excluido, reg.tattoo);

		rewind(arq_tatuagem);

		fread(&reg, sizeof(reg), 1, arq_tatuagem);

		while(!feof(arq_tatuagem)){

			if(strcmp(reg.tattoo, excluido) != 0){
				fwrite(&reg, sizeof(reg), 1, arq_temp);
			}
			fread(&reg, sizeof(reg), 1, arq_tatuagem);
		}

		fclose(arq_tatuagem); fclose(arq_temp);

		arq_tatuagem = fopen("arq_tatuagem.txt", "w");
		arq_temp = fopen("arq_temp.txt", "r+");

		fread(&reg, sizeof(reg), 1, arq_temp);
		while(!feof(arq_temp)){
			fwrite(&reg, sizeof(reg), 1, arq_tatuagem);
			fread(&reg, sizeof(reg), 1, arq_temp);
		}

		fclose(arq_tatuagem); fclose(arq_temp);
		remove("arq_temp.txt");

		printf("\n\ttatuagem excluido com sucesso!\n\tPressione Enter pra continuar.");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls");
		}
	}
	else if(esc == 'N' || esc == 'n'){
		printf("\n\tExclusao cancelada!\n\tPressione Enter para retornar ao Menu Principal.");
		getchar();
		scanf("%c", &esc);
		if(esc != 0){
			system("cls");
		}
	}
	else{
		goto tab;
	}
}


void lestring(char *string, int tamanhostring){
    int i = 0;
    char letra;

    for (i = 0; i < (tamanhostring - 1); i++) {
		letra = fgetc(stdin);
		if ((letra == '\n') && (i == 0)) {
			i = i - 1;
			continue;
		}
		if((letra >= 48) && (letra <= 57)){
			string[i] = letra;
		}
		if(letra == 7 && i > 0){
			i = i - 1;
		}
		if (letra == '\n')
		break;
    }
    *(string + i) = '\0';
}

void le_string(char *string, int tamanhostring){
	int i;
	char letra = 0;
	*string = '\0';

	for (i = 0; i < (tamanhostring - 1); i++){
		letra = fgetc(stdin);

		if ((letra == '\n') && (i == 0)) {
			i = i - 1;
			continue;
		}
		if(((letra >= 65)&&(letra <= 90)) || (letra == 32)){
			string[i] = letra;
		}
		if(letra == 7 && i > 0){
			i = i - 1;
		}
		if (letra == '\n')
		break;
	}
	*(string + i) = '\0';
}

void scan_string(char *string, int tamanhostring){

	int i;
	char letra = 0;
	*string = '\0';

	for (i = 0; i < (tamanhostring - 1); i++){
		letra = fgetc(stdin);

		if ((letra == '\n') && (i == 0)) {
			i = i - 1;
			continue;
		}
		if(((letra >= 48)&&(letra <= 57))||((letra >= 65)&&(letra <= 90)) || (letra == 32) || (letra == 46)){
			string[i] = letra;
		}
		if(letra == 7 && i > 0){
			i = i - 1;
		}
		if (letra == '\n')
		break;
	}
	*(string + i) = '\0';
}

void scan_tattoo(char *string, int tamanhostring){
	int i = 0;
    char letra;

    for (i = 0; i < (tamanhostring - 1); i++) {
		letra = getc(stdin);
		if ((letra == '\n') && (i == 0)) {
			i = i - 1;
			continue;
		}
		if(((letra >= 48) && (letra <= 57))||((letra >= 65)&&(letra <= 90))){
			string[i] = letra;
		}
		if(letra == 7 && i > 0){
			i = i - 1;
		}
		if (letra == '\n')
		break;
    }
    *(string + i) = '\0';
}

void long_int(long int *inteiro, int tamanhostring){
	int i;
	char letra = 0, string[30];
	*inteiro = 0;

	for(i = 0; i < (tamanhostring - 1); i++){
		letra = fgetc(stdin);

		if ((letra == '\n') && (i == 0)) {
			i = i - 1;
			continue;
		}
		if((letra >= 48)&&(letra <= 57)){
			string[i] = letra;
		}
		if(letra == 7 && i > 0){
			i = i - 1;
		}
		if (letra == '\n')
		break;
	}
	*(string + i) = '\0';
	*inteiro = atol(string);
}




int busca_cpf(char *cpf){

	int cont = 0;
	Tcliente reg;
	FILE *arq_cliente;

	arq_cliente = fopen("arq_cliente.txt", "r");

	if(arq_cliente == NULL){
		arq_cliente = fopen("arq_cliente.txt", "w");
	}
	else{
		fread(&reg, sizeof(reg), 1, arq_cliente);
		while(!feof(arq_cliente) && (strcmp(reg.cpf, cpf) != 0)){
			cont++;
			fread(&reg,sizeof(reg), 1, arq_cliente);
		}
	}

	fclose(arq_cliente);

	if(strcmp(reg.cpf, cpf) == 0){
		return(cont);
	}

	else{
		return(-1);
	}
}

int verifica_cpf(char *cpf){

	int i, j, digito1 = 0, digito2 = 0;


	if(strlen(cpf) != 11){
		return 0;
	}


    if ((strcmp(cpf,"00000000000") == 0) || (strcmp(cpf,"11111111111") == 0) ||
		(strcmp(cpf,"22222222222") == 0) || (strcmp(cpf,"33333333333") == 0) || (strcmp(cpf,"44444444444") == 0) ||
		(strcmp(cpf,"55555555555") == 0) || (strcmp(cpf,"66666666666") == 0) || (strcmp(cpf,"77777777777") == 0) ||
		(strcmp(cpf,"88888888888") == 0) || (strcmp(cpf,"99999999999") == 0)){
		return 0;
	}
	else{
		for(i = 0, j = 10; i < strlen(cpf)-2; i++, j--){
			digito1 += (cpf[i]-48) * j;
		}
        digito1 %= 11;
        if(digito1 < 2){
			digito1 = 0;
		}
        else{
			digito1 = 11 - digito1;
		}
        if((cpf[9]-48) != digito1){
			return 0;
		}
	else{

		for(i = 0, j = 11; i < strlen(cpf)-1; i++, j--){
			digito2 += (cpf[i]-48) * j;
		}
		digito2 %= 11;
		if(digito2 < 2){
			digito2 = 0;
		}
		else{
			digito2 = 11 - digito2;
		}
		if((cpf[10]-48) != digito2){
			return 0;
		}
    }
	}
    return 1;
}

int busca_cliente(int posicao){

	Tcliente reg;
	FILE *arq_cliente;

	arq_cliente = fopen("arq_cliente.txt", "r");

	if(arq_cliente == NULL){
		arq_cliente = fopen("arq_cliente.txt", "w");
	}

	else{
		fseek(arq_cliente, sizeof(reg) * (posicao), 0);

		fread(&reg, sizeof(reg), 1, arq_cliente);

		fclose(arq_cliente);
	}

	if(reg.status == 0){
		return 0;
	}
	else{
		return 1;
	}
}

int busca_statustatuagem(int posicao){

	Ttatuagem reg;
	FILE *arq_tatuagem;


	arq_tatuagem = fopen("arq_tatuagem.txt", "r");

	if(arq_tatuagem == NULL){
		arq_tatuagem = fopen("arq_tatuagem.txt", "w");
	}
	else{

		fseek(arq_tatuagem, sizeof(reg) * (posicao), 0);


		fread(&reg, sizeof(reg), 1, arq_tatuagem);

		fclose(arq_tatuagem);
	}

	if(reg.status == 0){
		return 0;
	}
	else{
		return 1;
	}
}

int busca_tattoo (char *tattoo){

	int pos = 0;


	Ttatuagem reg;
	FILE *arq_tatuagem;

	arq_tatuagem = fopen("arq_tatuagem.txt", "r");

	if(arq_tatuagem == NULL){
		arq_tatuagem = fopen("arq_tatuagem.txt", "w");
	}
	else{
		rewind(arq_tatuagem);
		fread(&reg, sizeof(reg), 1, arq_tatuagem);

		while(!feof(arq_tatuagem) && (strcmp(reg.tattoo, tattoo) != 0)){
			pos++;
			fread(&reg, sizeof(reg), 1, arq_tatuagem);
		}
	}
	fclose(arq_tatuagem);
	if(strcmp(reg.tattoo, tattoo) == 0){
		return(pos);
	}
	else{
		return(-1);
	}
}


