#include <stdio.h>
#include <string.h>

void inputMesAno(int *pMes, int *pAno){
    printf("Insira uma data no formato MM AAAA \n\nex: 01 1970\n\nMM AAAA:");
    while(1)
    {
        scanf("%d %d", &*pMes, &*pAno);
        if(*pMes < 1 || *pMes > 12){
            exit(1);
        }
        else if (*pAno < 1970 || *pAno > 2100){
            exit(1);
        }
        else{
            break;
        }
    }
}
int seBissexto(int ano)
{
   if (ano % 400 == 0){
    return 1;
   }
   else if (ano % 100 == 0){
    return 0;
   }
   else if (ano % 4 == 0) {
    return 1;
   }
   else {
    return 0;
   }
}
int semana(int mes, int ano){
    static int t[] = {0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4};
    ano -= mes < 3;
    return ( ano + ano / 4 - ano / 100 + ano / 400 + t[mes - 1] + 1) % 7;
}
char* mesNome(int mes){
    char* meses[] = {"Janeiro","Fevereiro","Marco","Abril","Maio","Junho",
    "Julho","Agosto","Setembro","Outubro","Novembro","Dezembro"};
    return meses[(mes - 1)];
}
void caledario(int diaSemana, int mes, char* nomeMes, int ano, int bissexto){
    int diasNoMes[]={31,28,31,30,31,30,31,31,30,31,30,31};\
    int dia;
    const char* semana = "do se te qu qu se sa";

    if (bissexto == 1) diasNoMes[1] = 29;
    else diasNoMes[1] = 28;

    int i = strlen(semana);
    int j = strlen(nomeMes) + 5;
    int k = i / 2 - j / 2;

    for(int a = 0; a < k; a++){
        printf(" ");
    } 
    printf("%s %d\n", nomeMes, ano);
	printf("%s\n", semana);
	for (dia = 1; dia <= diaSemana * 3; dia++){
		printf(" ");
	}
	for (dia = 1; dia <= diasNoMes[mes - 1]; dia++){
		printf("%2d", dia);
		if ((dia + diaSemana) % 7 > 0) printf(" ");
		else printf("\n");
	}
}
int main(){
    int ano, mes;
    int bissexto; 
    char* nomeMes; 
    int diaSemana; 

    inputMesAno(&mes, &ano);
    diaSemana = semana(mes, ano);
    bissexto = seBissexto(ano);
    nomeMes = mesNome(mes);
    caledario(diaSemana, mes, nomeMes, ano, bissexto);

    return 0;
} 