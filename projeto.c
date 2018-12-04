#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ALUGUEL 1
#define VENDA   0

struct Informacoes{
	int aluguelOuVenda;
	double valor;
};

struct Endereco{
	char rua[100];
	int numero;
	char bairro[100];
	char CEP[10];
	char cidade[100];
};
	
struct Casa{
	char tituloDoAnuncio[30];
	int numeroDePavimentos;
	int numeroDeQuartos;
	double areaDoTerreno;
	double areaConstruida;
	struct Endereco endereco;
	struct Informacoes informacoes;
};

struct Apartamento{
	char tituloDoAnuncio[30];
	double area;
	int numeroDeQuartos;
	char posicao[50];
	int andar;
	double valorDoCondominio;
	int numeroDeVagasDeGaragem;
	struct Endereco endereco;
	struct Informacoes informacoes;
};

struct Terreno{
	char tituloDoAnuncio[30];
	double area;
	struct Endereco endereco;
	struct Informacoes informacoes;
};


void menu();
void cadastrar();
int menuCadastro();
void inserirInformacoesGerais(struct Informacoes *informacoes, struct Endereco *endereco);
void inserirInformacoesCasa(struct Casa *casa);
int menuAluguelVenda();


int main(void){
	
	struct Casa casas[999];
	struct Apartamento apartamentos[999];
	struct Terreno terrenos[999];
	
	menu();	
	
	return 0;
}
void menu(){
	int escolha;
	
	
	printf("Escolha uma opcao: \n");
	printf("1 - Cadastrar Imovel\n");
	printf("2 - Consultar Imovel\n");
	printf("3 - Remover Imovel\n");
	printf("4 - Editar Imovel\n");
	printf("\Escolha: ");
	
	
	scanf("%d",&escolha);
	
	switch(escolha){
		case 1:
			cadastrar();
			break;
		case 2:
			//consultar();
			break;
		case 3:
			//remover();
			break;
		case 4:
			//editar();
			break;
		default:
			printf("\nOpcao invalida...\n");
			menu();
	}
}

void cadastrar(){
	int opcao = menuCadastro();
	
	switch(opcao){
		case 1:
			printf("=====CADASTRO DE CASA=====\n");
			struct Casa novaCasa;
			inserirInformacoesGerais(&novaCasa.informacoes,&novaCasa.endereco);
			inserirInformacoesCasa(&novaCasa);
			break;
		
			
			
			
	}
	
}
int menuCadastro(){
	int escolha;
	
	printf("O que voce deseja cadastrar?\n");
	printf("1 - Casa\n");
	printf("2 - Apartamento\n");
	printf("3 - Terreno\n");
	printf("4 - Voltar\n");
	printf("Escolha: ");
	
	scanf("%d",&escolha);
	if (escolha < 1 || escolha > 4){
		printf("\nOpcao invalida...\n");
		escolha = menuCadastro();
	}
	return escolha;
}


void inserirInformacoesCasa(struct Casa *casa){
	int numeroDePavimentos, numeroDeQuartos;
	double areaDoTerreno, areaConstruida;

	printf("Titulo do Anuncio: ");
	fgets((*casa).tituloDoAnuncio,30,stdin);
	fflush(stdin);
	
	printf("Numero de Pavimentos: ");
	scanf("%d",&numeroDePavimentos);
	fflush(stdin);
	
	printf("Numero de Quartos: ");
	scanf("%d",&numeroDeQuartos);
	fflush(stdin);
	
	printf("Area do Terreno: ");
	scanf("%lf",&areaDoTerreno);
	fflush(stdin);
	
	printf("Area Construida: ");
	scanf("%lf",&areaConstruida);
	fflush(stdin);
	
	(*casa).numeroDePavimentos = numeroDePavimentos;
	(*casa).numeroDeQuartos = numeroDeQuartos;
	(*casa).areaDoTerreno = areaDoTerreno;
	(*casa).areaConstruida = areaConstruida;	
}


void inserirInformacoesGerais(struct Informacoes *informacoes, struct Endereco *endereco){
	int aluguelOuVenda = menuAluguelVenda();
	double valor;
	int numero;
	aluguelOuVenda = (aluguelOuVenda==1)? ALUGUEL : ((aluguelOuVenda==2)? VENDA : 3);
	if(aluguelOuVenda == 3){
		menu();
	}else{
		
		printf("Valor: R$ ");
		scanf("%lf",&valor);
		fflush(stdin);
		
		printf("Rua: ");
		fgets((*endereco).rua,100,stdin);
		fflush(stdin);
		
		printf("Numero: ");
		scanf("%d",&numero);
		fflush(stdin);
		
		printf("Bairro: ");
		fgets((*endereco).bairro,100,stdin);
		fflush(stdin);
		
		printf("CEP: ");
		fgets((*endereco).CEP,10,stdin);
		fflush(stdin);
		
		printf("Cidade: ");
		fgets((*endereco).cidade,100,stdin);
		fflush(stdin);
		
		
		(*informacoes).aluguelOuVenda = aluguelOuVenda;
		(*informacoes).valor = valor;
		
		(*endereco).numero = numero;
		
		
	}
	
		
}
int menuAluguelVenda(){
	int escolha;
	printf("Voce quer: \n");
	printf("1 - Alugar\n");
	printf("2 - Vender\n");
	printf("3 - Cancelar\n");
	printf("Escolha: ");
	scanf("%d",&escolha);
	if(escolha < 1 || escolha > 3){
		escolha = menuAluguelVenda();
	}
	return escolha;
}
