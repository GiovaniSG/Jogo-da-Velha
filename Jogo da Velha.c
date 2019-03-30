//Giovani Santos Gonçalves Araujo
//16.2.8149
//Sistemas de Informação
#include<stdio.h>
void imprimetab(char m[3][3]){
     printf("  0    1    2 \n");
     printf("0  %c | %c | %c \n",m[0][0],m[0][1],m[0][2]);
     printf(" ===============\n");
     printf("1  %c | %c | %c \n",m[1][0],m[1][1],m[1][2]);
     printf(" ===============\n");
     printf("2  %c | %c | %c \n",m[2][0],m[2][1],m[2][2]);
}
int testaposicao(int i,int j,char m[][3]){
    if(m[i][j]!=' '){
            return 0;
    }else{return 1;}
}
int testamatriz(int tam,char m[][tam]){
    if(m[0][0]=='X'&&m[0][1]=='X'&&m[0][2]=='X'||
       m[1][0]=='X'&&m[1][1]=='X'&&m[1][2]=='X'||
       m[2][0]=='X'&&m[2][1]=='X'&&m[2][2]=='X'||
       m[0][0]=='X'&&m[1][0]=='X'&&m[2][0]=='X'||
       m[0][1]=='X'&&m[1][1]=='X'&&m[2][1]=='X'||
       m[0][2]=='X'&&m[1][2]=='X'&&m[2][2]=='X'||
       m[0][0]=='X'&&m[1][1]=='X'&&m[2][2]=='X'||
       m[0][2]=='X'&&m[1][1]=='X'&&m[2][0]=='X')
       {
        return 1;
       }else if(m[0][0]=='O'&&m[0][1]=='O'&&m[0][2]=='O'||
       m[1][0]=='O'&&m[1][1]=='O'&&m[1][2]=='O'||
       m[2][0]=='O'&&m[2][1]=='O'&&m[2][2]=='O'||
       m[0][0]=='O'&&m[1][0]=='O'&&m[2][0]=='O'||
       m[0][1]=='O'&&m[1][1]=='O'&&m[2][1]=='O'||
       m[0][2]=='O'&&m[1][2]=='O'&&m[2][2]=='O'||
       m[0][0]=='O'&&m[1][1]=='O'&&m[2][2]=='O'||
       m[0][2]=='O'&&m[1][1]=='O'&&m[2][0]=='O'){
       return 2;
       }
}
int testaempate(char m[3][3]){
    int i,j;
    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            if(m[i][j]==' '){
                return 1;
            }
        }
    }
}
int main(){
    char jogo[3][3];
    char jogador1[50];
    char jogador2[50];
    int i,j,c;
     for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            jogo[i][j]=' ';
        }
     }
     printf("Jogador 1 informe seu nome\n");
     scanf("%s",jogador1);
     printf("Jogador 2 informe seu nome\n");
     scanf("%s",jogador2);
     while(testaempate(jogo)==1){
            imprimetab(jogo);
            printf("%s informe a posicao \n",jogador1);
            scanf("%d%d",&i,&j);
            while (testaposicao(i,j,jogo)==0){
                printf("posicao invalida!\nInforme outra posicao\n");
                scanf("%d%d",&i,&j);
            }
            jogo[i][j]='X';
            if(testamatriz(3,jogo)==1){
                printf("\n %s voce venceu!!\n",jogador1);
                imprimetab(jogo);
                return 1;
            }
            if(testaempate(jogo)!=1){
                printf("VELHA!\n");
                imprimetab(jogo);
                return 0;
            }
            imprimetab(jogo);
            printf("%s informe a posicao \n",jogador2);
            scanf("%d%d",&i,&j);
            while (testaposicao(i,j,jogo)==0){
                printf("posicao invalida!\nInforme outra posicao\n");
                scanf("%d%d",&i,&j);
            }
            jogo[i][j]='O';
            if(testamatriz(3,jogo)==2){
                printf("\n %s voce venceu!!\n",jogador2);
                imprimetab(jogo);
                return 2;
            }
            if(testaempate(jogo)!=1){
                printf("VELHA!\n");
                imprimetab(jogo);
                return 0;
            }
     }
     printf("VELHA!");
return 0;
}
