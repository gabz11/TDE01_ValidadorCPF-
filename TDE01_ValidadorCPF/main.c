#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void) {

  char cpf[12]; // vetor de char p/armazenar cpf
  int valido = 0; // valor para representar booleano 0 = válido | 1 = inválido

  // fgets para obter todo o input
  printf("Digite um CPF \n>>");
  fgets(cpf, 12, stdin);

  // verificador pt. 1
  valido = primeiroVer(cpf);

  // verificador pt. 2
  valido = segundoVer(cpf);

  // ver pt. esp
  valido = especialVer(cpf);

  //imprime resultado
  imprimirValidacao(valido);
}

int primeiroVer(char cpf[12]){

    int valido = 0, ver1 = 0, total = 0, j = 10;
    for(int i = 0; i < 9; i++){
    total += (cpf[i] - '0') * j;
    j--;
    }
    int resto1 = total % 11;
    int sub1 = 11 - resto1;
    if (sub1 >= 10){
    ver1 = 0;
    }
    else {
    ver1 = sub1;
    }
    if(ver1 != (cpf[9] - '0')){
    valido = 1;
    }
    return valido;
}

int segundoVer(char cpf[12]) {
    int valido = 0, ver2 = 0, total2 = 0, j2 = 11;
    for(int i = 0; i < 10; i++){
    total2 += (cpf[i] - '0') * j2;
    j2--;
   }

    int resto2 = total2 % 11;

    int sub2 = 11 - resto2;
    if (sub2 >= 10){
        ver2 = 0;
    }
    else {
        ver2 = sub2;
    }

    if(ver2 != (cpf[10] - '0')){
        valido = 1;
    }
    return valido;
}

int especialVer(char cpf[12]) {
    int valido = 0, valEsp = 0;
    for(int i = 1; i < 11; i++){
    if (cpf[i - 1] == cpf[i]){
      valEsp += 1;
    }
  }

  if(valEsp == 10){
    valido = 1;
  }
  return valido;
}

int imprimirValidacao(int valido){
    if (valido == 0){
        printf("CPF eh valido.");
    }
    else if (valido == 1){
        printf("CPF eh invalido.");
    }
    else{
        printf("ERRO: Algo deu errado");
    }
    printf("\n\nPor: Gabriel Antonio Gomes de Farias - PUC-PR - B.C.C 2022 - Prof. Henri/Eng. Comp");
    return 0;
}
