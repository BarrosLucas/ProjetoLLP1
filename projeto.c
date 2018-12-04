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
void mostrarInformacoes(struct Informacoes *informacoes);
void mostrarEndereco(struct Endereco *endereco);
void mostrarCasa(struct Casa *casa);

struct Casa casas[999];
struct Apartamento apartamentos[999];
struct Terreno terrenos[999];
int ultimoIndiceCasas = 0, ultimoIndiceApartamentos = 0, ultimoIndiceTerrenos = 0;


int main(void){
	int i;
	
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
	printf("Escolha: ");
	
	
	scanf("%d",&escolha);
	system("cls");
	switch(escolha){
		case 1:
			cadastrar();
			break;
		case 2:
			consultar();
			break;
		case 3:
			//remover();
			break;
		case 4:
			//editar();
			break;
		default:
			printf("Opcao invalida...\n");
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
			
			casas[ultimoIndiceCasas] = novaCasa;
			ultimoIndiceCasas ++;
			
			printf("CADASTRO REALIZADO COM SUCESSO!");
			
			sleep(3);
			
			system("cls");
			
			menu();
			//mostrarCasa(&casas[ultimoIndiceCasas-1]);
			break;
		case 2:
			printf("=====CADASTRO DE APARTAMENTO=====\n");
			struct Apartamento novoApartamento;
			inserirInformacoesGerais(&novoApartamento.informacoes,&novoApartamento.endereco);
			inserirInformacoesApartamento(&novoApartamento);
			
			apartamentos[ultimoIndiceApartamentos] = novoApartamento;
			ultimoIndiceApartamentos ++;
			
			printf("CADASTRO REALIZADO COM SUCESSO!");
			
			sleep(3);
			
			system("cls");
			
			menu();
			//mostrarApartamento(&apartamentos[ultimoIndiceApartamentos-1]);
			break;
		case 3:
			printf("=====CADASTRO DE TERRENO=====\n");
			struct Terreno novoTerreno;
			inserirInformacoesGerais(&novoTerreno.informacoes,&novoTerreno.endereco);
			inserirInformacoesTerreno(&novoTerreno);
			
			terrenos[ultimoIndiceTerrenos] = novoTerreno;
			ultimoIndiceTerrenos ++;
			
			printf("CADASTRO REALIZADO COM SUCESSO!");
			
			sleep(3);
			
			system("cls");
			
			menu();
			//mostrarTerreno(&terrenos[ultimoIndiceTerrenos-1]);
			break;
		case 4:
			system("cls");
			menu();
			
			
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
	system("cls");
	if (escolha < 1 || escolha > 4){
		printf("Opcao invalida...\n");
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

void inserirInformacoesApartamento(struct Apartamento *apartamento){
	double area, valorDoCondominio;
	int numeroDeQuartos,andar,numeroDeVagasDeGaragem;
	

	printf("Titulo do Anuncio: ");
	fgets((*apartamento).tituloDoAnuncio,30,stdin);
	fflush(stdin);
	
	printf("Area: ");
	scanf("%lf",&area);
	fflush(stdin);
	
	printf("Numero de Quartos: ");
	scanf("%d",&numeroDeQuartos);
	fflush(stdin);
	
	printf("Posicao: ");
	fgets((*apartamento).posicao,50,stdin);
	fflush(stdin);
	
	printf("Andar: ");
	scanf("%d",&andar);
	fflush(stdin);
	
	printf("Valor do Condominio: R$ ");
	scanf("%lf",&valorDoCondominio);
	fflush(stdin);
	
	
	printf("Numero de Vagas de Garagem: ");
	scanf("%d",&numeroDeVagasDeGaragem);
	fflush(stdin);
	
	
	(*apartamento).area = area;
	(*apartamento).numeroDeQuartos = numeroDeQuartos;
	(*apartamento).andar = andar;
	(*apartamento).valorDoCondominio = valorDoCondominio;
	(*apartamento).numeroDeVagasDeGaragem = numeroDeVagasDeGaragem;
}

void inserirInformacoesTerreno(struct Terreno *terreno){
	double area;
	printf("Titulo do Anuncio: ");
	fgets((*terreno).tituloDoAnuncio,30,stdin);
	fflush(stdin);
	
	printf("Area: ");
	scanf("%lf",&area);
	fflush(stdin);
	
	(*terreno).area = area;	
}

void inserirInformacoesGerais(struct Informacoes *informacoes, struct Endereco *endereco){
	int aluguelOuVenda = menuAluguelVenda();
	double valor;
	int numero;
	aluguelOuVenda = (aluguelOuVenda==1)? ALUGUEL : ((aluguelOuVenda==2)? VENDA : 3);
	if(aluguelOuVenda == 3){
		system("cls");
		fflush(stdin);
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


void consultar(){
	int consulta = menuConsulta();
	int i;
	char letra;
	fflush(stdin);
	switch(consulta){
		case 1:
			mostrarTudo();
			printf("Digite enter para voltar...");
			scanf("%c",&letra);
			system("cls");
			menu();
			break;
		case 2:
			fflush(stdin);
			buscarPorTitulo();
			printf("Digite enter para voltar...");
			scanf("%c",&letra);
			system("cls");
			menu();
			break;	
		case 3:
			fflush(stdin);
			buscarPorBairro();
			printf("Digite enter para voltar...");
			scanf("%c",&letra);
			system("cls");
			menu();
			break;
		case 4:
			fflush(stdin);
			buscarPorValor();
			printf("Digite enter para voltar...");
			scanf("%c",&letra);
			system("cls");
			menu();
			break;
		case 5:
			fflush(stdin);
			buscarVendaPorTipo();
			printf("Digite enter para voltar...");
			scanf("%c",&letra);
			system("cls");
			menu();
			break;
		case 6:
			fflush(stdin);
			buscarAluguelPorTipo();
			printf("Digite enter para voltar...");
			scanf("%c",&letra);
			system("cls");
			menu();
		case 7:
			fflush(stdin);
			system("cls");
			menu();
	}
}
int menuConsulta(){
	fflush(stdin);
	int escolha;
	printf("Que tipo de consulta deseja fazer?\n");
	printf("1 - Mostrar todos os imoveis\n");
	printf("2 - Buscar imovel por titulo\n");
	printf("3 - Buscar imovel por bairro\n");
	printf("4 - Buscar imovel acima de um valor\n");
	printf("5 - Buscar os imoveis a venda por tipo de imovel\n");
	printf("6 - Butuscar os imoveis a aluguel por tipo de imovel\n");
	printf("7 - Voltar\n");
	printf("Sua escolha: ");
	scanf("%d",&escolha);
	fflush(stdin);
	system("cls");
	if(escolha < 1 || escolha > 7){
		printf("Opcao invalida...\n");
		escolha = menuConsulta();
	}
	return escolha;
}

void mostrarTudo(){
	printf("=====CASAS=====\n");
	int i;
	for(i = 0;i<ultimoIndiceCasas;i++){
		printf("\n");
		mostrarCasa(&casas[i]);
		printf("\n");
	}
	printf("=====APARTAMENTOS=====\n");
	for(i = 0;i<ultimoIndiceApartamentos;i++){
		printf("\n");
		mostrarApartamento(&apartamentos[i]);
		printf("\n");
	}
	printf("=====TERRENOS=====\n");
	for(i = 0;i<ultimoIndiceTerrenos;i++){
		printf("\n");
		mostrarTerreno(&terrenos[i]);
		printf("\n");
	}
}

void buscarPorTitulo(){
	fflush(stdin);
	char titulo[30];
	int i,qnt=0;
	printf("=====BUSCA POR TITULO=====\n");
	printf("Titulo: ");
	fgets(titulo,30,stdin);
	fflush(stdin);
	
	for(i=0;i<ultimoIndiceCasas;i++){
		if(stricmp(titulo,casas[i].tituloDoAnuncio)==0){
			mostrarCasa(&casas[i]);
			qnt=1;
		}
	}
	
	for(i=0;i<ultimoIndiceApartamentos;i++){
		if(stricmp(titulo,apartamentos[i].tituloDoAnuncio)==0){
			mostrarApartamento(&apartamentos[i]);
			qnt = 1;
		}
	}
	
	for(i=0;i<ultimoIndiceTerrenos;i++){
		if(stricmp(titulo,terrenos[i].tituloDoAnuncio)==0){
			mostrarTerreno(&terrenos[i]);
			qnt = 1;
		}
	}	
	
	if(qnt == 0){
		fflush(stdin);
		char escolha;
		system("cls");
		printf("Nenhum item identificado...\n");
		printf("Deseja realizar novamente a busca?\n");
		printf("1 - Sim\n");
		printf("Qualquer outra tecla - Nao\n");
		printf("Sua escolha: ");
		scanf("%c",&escolha);
		if(escolha == '1'){
			system("cls");
			buscarPorTitulo();
		}else{
			system("cls");
			menu();
		}
	}
}

void buscarPorBairro(){
	fflush(stdin);
	char bairro[100];
	int i,qnt=0;
	printf("=====BUSCA POR BAIRRO=====\n");
	printf("Bairro: ");
	fgets(bairro,100,stdin);
	fflush(stdin);
	
	for(i=0;i<ultimoIndiceCasas;i++){
		if(stricmp(bairro,casas[i].endereco.bairro)==0){
			mostrarCasa(&casas[i]);
			qnt=1;
		}
	}
	
	for(i=0;i<ultimoIndiceApartamentos;i++){
		if(stricmp(bairro,apartamentos[i].endereco.bairro)==0){
			mostrarApartamento(&apartamentos[i]);
			qnt = 1;
		}
	}
	
	for(i=0;i<ultimoIndiceTerrenos;i++){
		if(stricmp(bairro,terrenos[i].endereco.bairro)==0){
			mostrarTerreno(&terrenos[i]);
			qnt = 1;
		}
	}	
	
	if(qnt == 0){
		fflush(stdin);
		char escolha;
		system("cls");
		printf("Nenhum item identificado...\n");
		printf("Deseja realizar novamente a busca?\n");
		printf("1 - Sim\n");
		printf("Qualquer outra tecla - Nao\n");
		printf("Sua escolha: ");
		scanf("%c",&escolha);
		if(escolha == '1'){
			system("cls");
			buscarPorBairro();
		}else{
			system("cls");
			menu();
		}
	}
}

void buscarPorValor(){
	fflush(stdin);
	double valorMinimo;
	int i,qnt=0;
	printf("=====BUSCA POR VALOR MINIMO=====\n");
	printf("Imoveis a partir de R$ ");
	scanf("%lf",&valorMinimo);
	fflush(stdin);
	
	for(i=0;i<ultimoIndiceCasas;i++){
		if(casas[i].informacoes.valor >= valorMinimo){
			mostrarCasa(&casas[i]);
			qnt=1;
		}
	}
	for(i=0;i<ultimoIndiceApartamentos;i++){
		if(apartamentos[i].informacoes.valor >= valorMinimo){
			mostrarApartamento(&apartamentos[i]);
			qnt = 1;
		}
	}
	for(i=0;i<ultimoIndiceTerrenos;i++){
		if(terrenos[i].informacoes.valor >= valorMinimo){
			mostrarTerreno(&terrenos[i]);
			qnt = 1;
		}
	}	
		
	if(qnt == 0){
		fflush(stdin);
		char escolha;
		system("cls");
		printf("Nenhum item identificado...\n");
		printf("Deseja realizar novamente a busca?\n");
		printf("1 - Sim\n");
		printf("Qualquer outra tecla - Nao\n");
		printf("Sua escolha: ");
		scanf("%c",&escolha);
		if(escolha == '1'){
			system("cls");
			buscarPorBairro();
		}else{
			system("cls");
			menu();
		}
	}
}
void buscarAluguelPorTipo(){
	int tipo = menuBuscaAluguelTipo();
	fflush(stdin);
	switch(tipo){
		case 1:
			mostrarCasasPorTipo(ALUGUEL);
			break;
		case 2:
			mostrarApartamentosPorTipo(ALUGUEL);
			break;
		case 3:
			mostrarTerrenosPorTipo(ALUGUEL);
			break;
		case 4:
			menu();
	}
}

void buscarVendaPorTipo(){
	int tipo = menuBuscaVendaTipo();
	fflush(stdin);
	switch(tipo){
		case 1:
			mostrarCasasPorTipo(VENDA);
			break;
		case 2:
			mostrarApartamentosPorTipo(VENDA);
			break;
		case 3:
			mostrarTerrenosPorTipo(VENDA);
			break;
		case 4:
			menu();
	}
}
int menuBuscaAluguelTipo(){
	int escolha;
	fflush(stdin);
	system("cls");
	printf("Buscar por que tipo de imovel a aluguel?\n");
	printf("1 - Casa\n");
	printf("2 - Apartamento\n");
	printf("3 - Terreno\n");
	printf("4 - Cancelar\n");
	printf("Escolha: ");
	scanf("%d",&escolha);
	fflush(stdin);
	system("cls");
	if(escolha < 1 || escolha > 4){
		printf("Opcao invalida...\n");
		escolha = menuBuscaAluguelTipo();
	}
	return escolha;
}
int menuBuscaVendaTipo(){
	int escolha;
	fflush(stdin);
	system("cls");
	printf("Buscar por que tipo de imovel a venda?\n");
	printf("1 - Casa\n");
	printf("2 - Apartamento\n");
	printf("3 - Terreno\n");
	printf("4 - Cancelar\n");
	printf("Escolha: ");
	scanf("%d",&escolha);
	fflush(stdin);
	system("cls");
	if(escolha < 1 || escolha > 4){
		printf("Opcao invalida...\n");
		escolha = menuBuscaVendaTipo();
	}
	return escolha;
}

void mostrarCasasPorTipo(int tipo){
	int i;
	for(i=0;i<ultimoIndiceCasas;i++){
		if(casas[i].informacoes.aluguelOuVenda==tipo){
			mostrarCasa(&casas[i]);
		}
	}
}
void mostrarApartamentosPorTipo(int tipo){
	int i;
	for(i=0;i<ultimoIndiceApartamentos;i++){
		if(apartamentos[i].informacoes.aluguelOuVenda==tipo){
			mostrarApartamento(&apartamentos[i]);
		}
	}	
}
void mostrarTerrenosPorTipo(int tipo){
	int i;
	for(i=0;i<ultimoIndiceTerrenos;i++){
		if(terrenos[i].informacoes.aluguelOuVenda==tipo){
			mostrarTerreno(&terrenos[i]);
		}
	}
}

void mostrarInformacoes(struct Informacoes *informacoes){
	if((*informacoes).aluguelOuVenda == ALUGUEL){
		printf("Aluga-se\n");	
	}else{
		printf("Vende-se\n");
	}
	printf("Valor: R$ %.2lf\n",(*informacoes).valor);
}

void mostrarEndereco(struct Endereco *endereco){
	printf("Rua: %s",(*endereco).rua);
	printf("Numero: %d\n",(*endereco).numero);
	printf("Bairro: %s",(*endereco).bairro);
	printf("CEP: %s\n",(*endereco).CEP);
	printf("Cidade: %s",(*endereco).cidade);
}

void mostrarCasa(struct Casa *casa){
	printf("=====CASA=====\n");
	
	
	printf("%s",(*casa).tituloDoAnuncio);
	printf("Numero de Pavimentos: %d\n",(*casa).numeroDePavimentos);
	printf("Numero de Quartos: %d\n",(*casa).numeroDeQuartos);
	printf("Area do Terreno: %.1lf metros quadrados\n",(*casa).areaDoTerreno);
	printf("Area Construida: %.1lf metros quadrados\n",(*casa).areaConstruida);
	mostrarEndereco(&((*casa).endereco));
	mostrarInformacoes(&((*casa).informacoes));
}

void mostrarApartamento(struct Apartamento *apartamento){
	printf("=====APARTAMENTO=====\n");
	
	
	printf("%s",(*apartamento).tituloDoAnuncio);
	printf("Area: %.1lf metros quadrados\n",(*apartamento).area);
	printf("Numero de quartos: %d\n",(*apartamento).numeroDeQuartos);
	printf("Posicao: %s",(*apartamento).posicao);
	printf("Andar: %d\n",(*apartamento).andar);
	printf("Valor do condominio: R$ %.2lf\n",(*apartamento).valorDoCondominio);
	printf("Numero de vagas de garagem: %d\n",(*apartamento).numeroDeVagasDeGaragem);
	mostrarEndereco(&((*apartamento).endereco));
	mostrarInformacoes(&((*apartamento).informacoes));
}

void mostrarTerreno(struct Terreno *terreno){
	printf("=====TERRENO=====\n");
	
	
	printf("%s",(*terreno).tituloDoAnuncio);
	printf("Area: %.1lf metros quadrados\n",(*terreno).area);
	mostrarEndereco(&((*terreno).endereco));
	mostrarInformacoes(&((*terreno).informacoes));
}
