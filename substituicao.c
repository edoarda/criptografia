/* PROGRAMA DA ALEGRIA QUE SUBSTITUI COISAS
 * 
 *
 *
 *
 *
 */

 #include <stdio.h>
 #include <stdlib.h>
 #include <string.h>

 //definindo maior tamanho de texto porque eu desisti de fazer isso full dinamico.
 #define MAX_TEXTAO 256

int soma_pra_caramba (int numero) {
    while (numero < 0)
        numero += 26;
    return numero;
}

char encryptifier(int *chave, char letra) {
    //DE 65 A 90
    //espaço é 32
    //remover 64
    int chave_de_conta = soma_pra_caramba(*chave);
    char out;
    if (letra < 65 || letra > 90)
        return letra;
    else {
        out = (((letra-64) + chave_de_conta) % 26)+64; //se a letra resultado for Z vai dar 64 e nao 90, endireitar isso
        if(out == 64)
                 out = 90;
    }
    *chave = *chave + (out-64);
    
    return out;
}

 int main () {
     
     char* textao = (char*) calloc (MAX_TEXTAO, sizeof(char));
     int* chave = (int*) malloc (sizeof(int));

     printf("#### (DES)CRIPTOVADOR 3000 ####\n\n");

     char escolha;
     int chavinha;

    //  printf("Digite D para decriptar OU digite E para encriptar sua mensagem.\n");
    //  scanf("%c", &escolha);

    printf("Digite o valor da sua chave inicial.\n");
    scanf("%d", chave);
    printf("sua chave foi %d", *chave);

     printf("Digite vossa mensagem.\n ");

     char* velha;
     /*
     int bandeira = 1;
     
     while (bandeira) {
         fflush(stdin); //limpando o buffer pra não ter \n's alheios
         fgets (buffer, 256, stdin);

         //ve se tem a velha na linha de entrada
         velha = strchr(buffer,'#');
         
         //dá append no texto, enfia um \n e segue a vida
         strcat(textao, buffer);
         strcat(textao,"\n");
         
         if (velha != NULL)
             bandeira = 0;
     }

     printf("%s", textao);
     printf("%c", textao[0]);
     */
     char saida;
     while (scanf("%c", &velha) && velha != '#') {
         saida = encryptifier(chave, velha);
         printf("%d\n", *chave);
         printf("%c", saida);
     }
     if (escolha == 'e' || escolha == 'E') {
         //encripta o maluco
         //encryptifier(chavinha);
     } 
     else if (escolha == 'd' || escolha == 'D') {
         //decripta o maluco
     } 
     else {
         printf("Opcao invalida amigo. Tente novamente (Ou nao)");
     }

     //I want to break
     free (textao);
     //I want to break
     free (chave);
 }