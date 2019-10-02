#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#pragma pack(1)

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

int comparador(const void *e1, const void *e2)
{
	return strncmp(((Endereco*)e1)->cep,((Endereco*)e2)->cep,8); //compara se uma string é maior que a outra. 
}

int main(int argc, char**argv)
{
	FILE *file, *saida;
	Endereco *end;
	long posicao, qtd, parte1;

//Divisão do arquivo em 8 partes

	file = fopen("cep.dat","r");
	fseek(file,0,SEEK_END);
	posicao = ftell(file);
	qtd = posicao/sizeof(Endereco); //faz o quantidade de registros no arquivo
	parte1 = qtd/8; 
	end = (Endereco*) malloc(parte1*sizeof(Endereco));  // aloca o primeira parte do arquivo na memoria
	rewind(file); //joga a cabeça de leitura para o inicio
	printf("1 de 8\n");
	if(fread(end,sizeof(Endereco),parte1,file) == parte1)
	{
		printf("Lido = OK\n");
	}
	qsort(end,parte1,sizeof(Endereco),comparador); //ordena pelo metodo quicksort (vetor, numero_de_elementos, sizeof(vetor), comparador)
	printf("Parte 1 ordenada = OK\n");
	saida = fopen("cep_a.dat","w");
	fwrite(end,sizeof(Endereco),parte1,saida);
	fclose(saida);
	printf("Primeira parte escrita = OK\n");
	free(end); //libera espaço em memória

//Parte 2

	long parte2, qtd2; 
	qtd2 = qtd - parte1; 
	parte2 = qtd2/7; 

	printf("2 de 8\n");
	end = (Endereco*) malloc((parte2*sizeof(Endereco)));
	if(fread(end,sizeof(Endereco),parte2,file) == parte2)
	{
		printf("Lido = OK\n");
	}
	qsort(end,parte2,sizeof(Endereco),comparador);
	printf("Parte 2 ordenada = OK\n = OK\n");
	saida = fopen("cep_b.dat","w");
	fwrite(end,sizeof(Endereco),parte2,saida);
	fclose(saida);
	printf("Segunda parte escrita = OK\n");
	free(end);

//Parte 3

	long parte3, qtd3; 
	qtd3 = qtd2 - parte2; 
	parte3 = qtd3/6;
	printf("3 de 8\n");
	end = (Endereco*) malloc((parte3*sizeof(Endereco)));
	if(fread(end,sizeof(Endereco),parte3,file) == parte3)
	{
		printf("Lido = OK\n");
	}
	qsort(end,parte3,sizeof(Endereco),comparador);
	printf("Parte 3 ordenada = OK\n = OK\n");
	saida = fopen("cep_c.dat","w");
	fwrite(end,sizeof(Endereco),parte3,saida);
	fclose(saida);
	printf("Terceira parte escrita = OK\n");
	free(end);

//Parte 4

	long parte4, qtd4; 
	qtd4 = qtd3 - parte3; 
	parte4 = qtd4/5;
	printf("4 de 8\n");
	end = (Endereco*) malloc((parte4*sizeof(Endereco)));
	if(fread(end,sizeof(Endereco),parte4,file) == parte4)
	{
		printf("Lido = OK\n");
	}
	qsort(end,parte4,sizeof(Endereco),comparador);
	printf("Parte 4 ordenada = OK\n = OK\n");
	saida = fopen("cep_d.dat","w");
	fwrite(end,sizeof(Endereco),parte4,saida);
	fclose(saida);
	printf("Quarta parte escrita = OK\n");
	free(end);

//Parte 5

	long parte5, qtd5; 
	qtd5 = qtd4 - parte4; 
	parte5 = qtd5/4; 
	printf("5 de 8\n");
	end = (Endereco*) malloc((parte5*sizeof(Endereco)));
	if(fread(end,sizeof(Endereco),parte5,file) == parte5)
	{
		printf("Lido = OK\n");
	}
	qsort(end,parte5,sizeof(Endereco),comparador);
	printf("Parte 5 ordenada = OK\n = OK\n");
	saida = fopen("cep_e.dat","w");
	fwrite(end,sizeof(Endereco),parte5,saida);
	fclose(saida);
	printf("Quinta parte escrita = OK\n");
	free(end);

//Parte 6

	long parte6, qtd6; 
	qtd6 = qtd5 - parte5; 
	parte6 = qtd6/3; 
	printf("6 de 8\n");
	end = (Endereco*) malloc((parte6*sizeof(Endereco)));
	if(fread(end,sizeof(Endereco),parte6,file) == parte6)
	{
		printf("Lido = OK\n");
	}
	qsort(end,parte6,sizeof(Endereco),comparador);
	printf("Parte 6 ordenada = OK\n = OK\n");
	saida = fopen("cep_f.dat","w");
	fwrite(end,sizeof(Endereco),parte6,saida);
	fclose(saida);
	printf("Sexta parte escrita = OK\n");
	free(end);

//Parte 7

	long parte7, qtd7; 
	qtd7 = qtd6 - parte6; 
	parte7 = qtd7/2;  
	printf("7 de 8\n");
	end = (Endereco*) malloc((parte7*sizeof(Endereco)));
	if(fread(end,sizeof(Endereco),parte7,file) == parte7)
	{
		printf("Lido = OK\n");
	}
	qsort(end,parte7,sizeof(Endereco),comparador);
	printf("Parte 7 ordenada = OK\n = OK\n");
	saida = fopen("cep_g.dat","w");
	fwrite(end,sizeof(Endereco),parte7,saida);
	fclose(saida);
	printf("Sétima parte escrita = OK\n");
	free(end);

//Parte 8

	long parte8, qtd8; 
	qtd8 = qtd7 - parte7; 
	parte8 = qtd8/2;   
	printf("8 de 8\n");
	end = (Endereco*) malloc((parte8*sizeof(Endereco)));
	if(fread(end,sizeof(Endereco),parte8,file) == parte8)
	{
		printf("Lido = OK\n");
	}
	qsort(end,parte8,sizeof(Endereco),comparador);
	printf("Parte 8 ordenada = OK\n = OK\n");
	saida = fopen("cep_h.dat","w");
	fwrite(end,sizeof(Endereco),parte8,saida);
	fclose(saida);
	printf("Oitava parte escrita = OK\n");
	free(end);
	

	fclose(file);

//intercalação

	FILE *a, *b, *c, *d, *e, *f, *g, *h;    // variaveis de divisao do arquivo
    	FILE *saida1, *saida2, *saida3, *saida4;  // saidas dois a dois
	Endereco ea, eb, ec, ed, ee, ef,eg, eh;

	a = fopen("cep_a.dat","r");
	b = fopen("cep_b.dat","r");
    	c = fopen("cep_c.dat","r");
    	d = fopen("cep_d.dat","r");
	e = fopen("cep_e.dat","r");
	f = fopen("cep_f.dat","r"); 
	g = fopen("cep_g.dat","r"); 
	h = fopen("cep_h.dat","r");
	

	saida1 = fopen("saida1.dat","w");
    	saida2 = fopen("saida2.dat","w");
    	saida3 = fopen("saida3.dat","w");
	saida4 = fopen("saida4.dat","w"); 

	fread(&ea,sizeof(Endereco),1,a); 
	fread(&eb,sizeof(Endereco),1,b);
    	fread(&ec,sizeof(Endereco),1,c);
   	fread(&ed,sizeof(Endereco),1,d);
    	fread(&ee,sizeof(Endereco),1,e);
    	fread(&ef,sizeof(Endereco),1,f);
    	fread(&eg,sizeof(Endereco),1,g);
    	fread(&eh,sizeof(Endereco),1,h);

	


    //Intercala Parte 1 e Parte 2

	while(!feof(a) && !feof(b))  //enquanto não chegar ao fim do arquivo a e b
	{
		if(comparador(&ea,&eb)<0) 
		{
			fwrite(&ea,sizeof(Endereco),1,saida1);
			fread(&ea,sizeof(Endereco),1,a);  
		}
		else
		{
			fwrite(&eb,sizeof(Endereco),1,saida1);
			fread(&eb,sizeof(Endereco),1,b);
		}
	}

	while(!feof(a))
	{
		fwrite(&ea,sizeof(Endereco),1,saida1);
		fread(&ea,sizeof(Endereco),1,a);		
	}
	while(!feof(b))
	{
		fwrite(&eb,sizeof(Endereco),1,saida1);
		fread(&eb,sizeof(Endereco),1,b);		
	}

	fclose(a);
	fclose(b);
	fclose(saida1);

    //Intercala Parte 3 e Parte 4

	while(!feof(c) && !feof(d))  
	{
		if(comparador(&ec,&ed)<0) 
		{
			fwrite(&ec,sizeof(Endereco),1,saida2);
			fread(&ec,sizeof(Endereco),1,c);  
		}
		else
		{
			fwrite(&ed,sizeof(Endereco),1,saida2);
			fread(&ed,sizeof(Endereco),1,d);
		}
	}

	while(!feof(c))
	{
		fwrite(&ec,sizeof(Endereco),1,saida2);
		fread(&ec,sizeof(Endereco),1,c);		
	}
	while(!feof(d))
	{
		fwrite(&ed,sizeof(Endereco),1,saida2);
		fread(&ed,sizeof(Endereco),1,d);		
	}

	fclose(c);
	fclose(d);
	fclose(saida2); 

	//Intercala Parte 5 e Parte 6
	
	while(!feof(e) && !feof(f))  
	{
		if(comparador(&ee,&ef)<0) 
		{
			fwrite(&ee,sizeof(Endereco),1,saida3);
			fread(&ee,sizeof(Endereco),1,e);  
		}
		else
		{
			fwrite(&ef,sizeof(Endereco),1,saida3);
			fread(&ef,sizeof(Endereco),1,f);
		}
	}

	while(!feof(e))
	{
		fwrite(&ee,sizeof(Endereco),1,saida3);
		fread(&ee,sizeof(Endereco),1,e);		
	}
	while(!feof(f))
	{
		fwrite(&ef,sizeof(Endereco),1,saida3);
		fread(&ef,sizeof(Endereco),1,f);		
	}

	fclose(e);
	fclose(f);
	fclose(saida3); 
	
    //Intercala Parte 7 e Parte 8
	
	while(!feof(g) && !feof(h))  
	{
		if(comparador(&eg,&eh)<0) 
		{
			fwrite(&eg,sizeof(Endereco),1,saida4);
			fread(&eg,sizeof(Endereco),1,g);  
		}
		else
		{
			fwrite(&eh,sizeof(Endereco),1,saida4);
			fread(&eh,sizeof(Endereco),1,h);
		}
	}

	while(!feof(g))
	{
		fwrite(&eg,sizeof(Endereco),1,saida4);
		fread(&eg,sizeof(Endereco),1,g);		
	}
	while(!feof(h))
	{
		fwrite(&eh,sizeof(Endereco),1,saida4);
		fread(&eh,sizeof(Endereco),1,h);		
	}

	fclose(g);
	fclose(h);
	fclose(saida4); 

// Segunda Intercalação

	
    FILE *saida5, *saida6;  
	Endereco esaida1, esaida2, esaida3, esaida4;

	saida1 = fopen("saida1.dat","r");  // saida1 e saida2 foram abertas outras vez pois fechei no ultimo uso
	saida2 = fopen("saida2.dat","r");
   	saida3 = fopen("saida3.dat","r");
	saida4 = fopen("saida4.dat","r");

	
	// abrindo aquivos para escrita	
	saida5 = fopen("saida5.dat","w"); 
	saida6 = fopen("saida6.dat","w");

	fread(&esaida1,sizeof(Endereco),1,saida1); 
	fread(&esaida2,sizeof(Endereco),1,saida2);
	fread(&esaida3,sizeof(Endereco),1,saida3);
	fread(&esaida4,sizeof(Endereco),1,saida4);


//Intercala Saida 1 e Saida 2

	while(!feof(saida1) && !feof(saida2))  
	{
		if(comparador(&esaida1,&esaida2)<0) 
		{
			fwrite(&esaida1,sizeof(Endereco),1,saida5);
			fread(&esaida1,sizeof(Endereco),1,saida1);  
		}
		else
		{
			fwrite(&esaida2,sizeof(Endereco),1,saida5);
			fread(&esaida2,sizeof(Endereco),1,saida2);
		}
	}

	while(!feof(saida1))
	{
		fwrite(&esaida1,sizeof(Endereco),1,saida5);
		fread(&esaida1,sizeof(Endereco),1,saida1);		
	}
	while(!feof(saida2))
	{
		fwrite(&esaida2,sizeof(Endereco),1,saida5);
		fread(&esaida2,sizeof(Endereco),1,saida2);		
	}

	
	fclose(saida5); 


//Intercala Saida 3 e Saida 4

	while(!feof(saida3) && !feof(saida4))  
	{
		if(comparador(&esaida3,&esaida4)<0) 
		{
			fwrite(&esaida3,sizeof(Endereco),1,saida6);
			fread(&esaida3,sizeof(Endereco),1,saida3);  
		}
		else
		{
			fwrite(&esaida4,sizeof(Endereco),1,saida6);
			fread(&esaida4,sizeof(Endereco),1,saida4);
		}
	}

	while(!feof(saida3))
	{
		fwrite(&esaida3,sizeof(Endereco),1,saida6);
		fread(&esaida3,sizeof(Endereco),1,saida3);		
	}
	while(!feof(saida4))
	{
		fwrite(&esaida4,sizeof(Endereco),1,saida6);
		fread(&esaida4,sizeof(Endereco),1,saida4);		
	}

	
	fclose(saida6); 

// Terceira Intercalação

	FILE *saidaEnd;
	Endereco esaida5, esaida6;

	saida5 = fopen("saida5.dat","r");  
	saida6 = fopen("saida6.dat","r");
	
	// abrindo aquivos para escrita	
	saidaEnd = fopen("saida.dat","w"); 
	
	fread(&esaida5,sizeof(Endereco),1,saida5); 
	fread(&esaida6,sizeof(Endereco),1,saida6);

	
	while(!feof(saida5) && !feof(saida6))  
	{
		if(comparador(&esaida5,&esaida6)<0) 
		{
			fwrite(&esaida5,sizeof(Endereco),1,saidaEnd);
			fread(&esaida5,sizeof(Endereco),1,saida5);  
		}
		else
		{
			fwrite(&esaida6,sizeof(Endereco),1,saidaEnd);
			fread(&esaida6,sizeof(Endereco),1,saida6);
		}
	}

	while(!feof(saida5))
	{
		fwrite(&esaida5,sizeof(Endereco),1,saidaEnd);
		fread(&esaida5,sizeof(Endereco),1,saida5);		
	}
	while(!feof(saida6))
	{
		fwrite(&esaida6,sizeof(Endereco),1,saidaEnd);
		fread(&esaida6,sizeof(Endereco),1,saida6);		
	}

	fclose(saida6); 
	fclose(saida5); 
	fclose(saidaEnd); 
	

	return 0; 
}
