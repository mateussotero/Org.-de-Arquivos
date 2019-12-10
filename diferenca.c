// Aluno Mateus de Brito Sotero

void diferenca(ArvoreB* a, FILE *f){
    FILE *saida = fopen("diferenca_bolsa.csv", "w");
    char linha[2048];
	char nis[15];
	int coluna = 0;
	char* campo;
    char chave[TAM_CHAVE+1];
    long posArq;
    fgets(linha, 2048, f);
	
	fgets(linha, 2048, f);
    
        while(!feof(f))
        {
            coluna = 0;
            char linhaArq[2048];
		    strcpy(linhaArq, linha);
            campo = strtok(linha,";");
            while(campo)
            {
                if(coluna == 5)
                {
                    strcpy(nis, campo);
                    posArq = ArvoreB_Busca_Recursiva(a, a->cabecalho->raiz, nis);
                    if(posArq<0){
                        fputs(linhaArq, saida);
                    }
                }
                coluna++;
                campo = strtok(NULL,";");
            }
            fgets(linha, 2048, f);

        }
    fclose(saida);
     
}
int main(int argc, char **argv)
{
    
    if(argc != 3)
    {
        fprintf(stderr, "Erro.\n");
        fprintf(stderr, "Uso: %s [ARQUIVO DE ÍNDICE] [ARQUIVO BOLSA FAMILIA]", argv[0]);
        return 1;
    }   
    ArvoreB* a = ArvoreB_Abre(argv[1]);
    FILE *f;
    f= fopen(argv[2], "r");
    if(!f) {
        fprintf(stderr,"O Arquivo nao pode ser aberto\n");
        return 1;
    }
    diferenca(a, f); 
    ArvoreB_Fecha(a);
    fclose(f);
   
    return 0;
}
