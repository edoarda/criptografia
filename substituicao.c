// PROGRAMA DA ALEGRIA QUE SUBSTITUI COISAS

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

//funcao que pega um valor negativo e SOMA PRA CARAMBA até virar positivo porque funciona
int soma_pra_caramba (int numero) {
    while (numero < 0)
        numero += 26;
    return numero;
}

//funcao magica que decripta E encripta
char encryptifier(int *chave, char letra, int encriptar) {
    //CHAR DO ASCII DE 65 A 90
    char out;
    if (letra < 65 || letra > 90)
        return letra;
    else {
        // Se for pra encriptar o valor de encriptar eh 1 e se for pra decriptar o valor eh -1
        out = ((soma_pra_caramba((letra-64) + (*chave)*encriptar)) % 26)+64;
        if(out == 64) //arruma caso a letra seja Z
            out = 90;
    }

    //coisador da chave nova!
    if(encriptar==1)
        *chave = (*chave + (out-64)) % 26;
    else if (encriptar==-1)
        *chave = (*chave + (letra-64)) % 26;
    
    return out;
}

 int main () {
     
     char* para_a_musica = (char*) malloc (sizeof(char)); //nao tem utilidade funcional nenhuma nesse programa, mas ta ai pela piada.
     int* chave = (int*) malloc (sizeof(int));

     //printf("#### (DES)CRIPTOVADOR 3000 ####\n\n");

     char escolha;

     printf("Digite D para decriptar e E para encriptar\n");
     scanf("%c", &escolha);
     int encriptar;  
     if (escolha == 'e' || escolha == 'E') {
         encriptar = 1;
     } 
     else if (escolha == 'd' || escolha == 'D') {
         encriptar = -1;
     } 

    printf("Digite o valor da chave\n");
    scanf("%d", chave);

    *chave = soma_pra_caramba(*chave) % 26;

     printf("Digite o texto\n");
     fflush(stdin); //limpando o buffer pra não ter \n's alheios na saida
     char velha;
     while (scanf("%c", &velha) && velha != '#') {
         velha = encryptifier(chave, velha, encriptar);
         printf("%c", velha);
     }

     //I want to break
     free (para_a_musica);
     //I want to break
     free (chave);
 }