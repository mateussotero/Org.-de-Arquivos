/* Aluno: Mateus de Brito Sotero */


#include <stdio.h>
#include <string.h>


typedef struct _Endereco Endereco;

struct _Endereco
{
	char logradouro[72];
	char bairro[72];
	char cidade[72];
	char uf[72];
	char sigla[2];
	char cep[8];
	char lixo[2];
};


void buscaBinCep(long ultimo, FILE *f, char *cep){ //(Tam. do arquivo, ponteiro para o arquivo de CEPS, o CEP que deseja)   
int qtd=0;
int i=0;
long inicio=0;
long meio;	
Endereco end;
	
	while(inicio<=ultimo){
		//i++;
		meio=(inicio+ultimo)/2;
		fseek(f, meio*sizeof(Endereco), SEEK_SET);
		qtd= fread(&end, sizeof(Endereco), 1, f);
		
		if(strncmp(cep, end.cep, 8) == 0){
			printf("%.72s\n%.72s\n%72s\n%.72s\n%.2s\n%.8s\n", end.logradouro, end.bairro, end.cidade, end.uf, end.sigla, end.cep);
			break;
		} else{
			if(strncmp(cep, end.cep, 8) < 0){
				ultimo = meio - 1;
			}else{
				inicio = meio + 1;
			}
		}
	}
	printf("foram feitas %d interações para encontrar o cep", i);
}




int main(int argc, char**argv){
Endereco end;
long posicao;
long ultimo;	
FILE *file;
file = fopen("cep_ordenado.dat", "r");

if(argc != 2){
	fprintf(stderr, "Executado com êxito: ./buscabin [CEP] %s", argv[0]);
	return 1;
}

	fseek(file, 0, SEEK_END);
	posicao=ftell(file);
	rewind(file); //coloca a cabeça de leitura na posição inicial do arquivo
	
	ultimo= (posicao/sizeof(Endereco)) - 1;
	buscaBinCep(ultimo, file, argv[1]);
	fclose(file);
	return 0;
}
