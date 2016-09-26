// PROGRAMA DA ALEGRIA QUE SUBSTITUI COISAS

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

int soma_pra_caramba (int numero) {
    while (numero < 0)
        numero += 26;
    return numero;
}

char encryptifier(int *chave, char letra, int encriptar) {
    //DE 65 A 90
    //espaço é 32
    //remover 64
    int chave_de_conta = soma_pra_caramba(*chave);
    char out;
    if (letra < 65 || letra > 90)
        return letra;
    else {
        out = ((soma_pra_caramba((letra-64) + chave_de_conta*encriptar)) % 26)+64; //se a letra resultado for Z vai dar 64 e nao 90, endireitar isso
        if(out == 64)
                 out = 90;
    }
    if(encriptar==1)
        *chave = *chave + (out-64);
    else if (encriptar==-1)
        *chave = *chave + (letra-64);
    
    return out;
}

 int main () {
     
     char* para_a_musica = (char*) malloc (sizeof(char));//nao tem utilidade funcional nenhuma nesse programa, mas ta ai pela piada.
     int* chave = (int*) malloc (sizeof(int));

     printf("#### (DES)CRIPTOVADOR 3000 ####\n\n");

     char escolha;
     int chavinha;

     printf("Digite D para decriptar OU digite E para encriptar sua mensagem.\n");
     scanf("%c", &escolha);
     int encriptar;
     if (escolha == 'e' || escolha == 'E') {
         encriptar = 1;
     } 
     else if (escolha == 'd' || escolha == 'D') {
         encriptar = -1;
     } 

    printf("Digite o valor da sua chave inicial.\n");
    scanf("%d", chave);
    printf("sua chave foi %d", *chave);

     printf("Digite vossa mensagem.\n ");

     char velha;

     char saida;
     while (scanf("%c", &velha) && velha != '#') {
         saida = encryptifier(chave, velha, encriptar);
         printf("%c", saida);
     }
     /*if (escolha == 'e' || escolha == 'E') {
         //encripta o maluco
         //encryptifier(chavinha);
     } 
     else if (escolha == 'd' || escolha == 'D') {
         //decripta o maluco
     } 
     else {
         printf("Opcao invalida amigo. Tente novamente (Ou nao)");
     }*/

     //I want to break
     free (para_a_musica);
     //I want to break
     free (chave);
 }