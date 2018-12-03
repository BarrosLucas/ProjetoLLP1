#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
};

struct Terreno{
	char tituloDoAnuncio[30];
	double area;
	struct Endereco endereco;
};


int main(void){
	
	
	return 0;
}
