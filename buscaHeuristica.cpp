//Coldong by: @guiquintero RA:2257904
#include<iostream>
#include<stdio.h>
#include <conio.h>

using namespace std;
                              //A B C D E F G H I J K L M N O P Q R S T U
int mapaSalas[21][21] = /*A*/ {{0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        /*B*/  {0,0,1,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        /*C*/  {1,1,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        /*D*/  {0,2,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        /*E*/  {0,0,0,1,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0},
                        /*F*/  {0,0,0,0,2,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0},
                        /*G*/  {0,0,1,0,0,0,0,1,0,0,1,0,0,0,0,0,0,0,0,0,0},
                        /*H*/  {0,0,0,0,0,0,1,0,1,0,1,1,0,0,0,0,0,0,0,0,0},
                        /*I*/  {0,0,0,0,0,0,0,1,0,2,0,0,0,0,0,0,0,0,0,0,0},
                        /*J*/  {0,0,0,0,0,2,0,0,2,0,0,0,1,0,0,0,0,0,0,0,0},
                        /*K*/  {0,0,0,0,0,0,1,1,0,0,0,0,0,1,0,0,0,0,0,0,0},
                        /*L*/  {0,0,0,0,0,0,0,1,0,0,0,0,2,0,0,0,0,0,0,0,0},
                        /*M*/  {0,0,0,0,0,0,0,0,0,1,0,2,0,0,0,1,0,0,0,0,0},
                        /*N*/  {0,0,0,0,0,0,0,0,0,0,1,0,0,0,2,0,2,0,0,0,0},
                        /*O*/  {0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,2,0,0,0,0,0},
                        /*P*/  {0,0,0,0,0,0,0,0,0,0,0,0,1,0,2,0,0,0,0,1,0},
                        /*Q*/  {0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,1,0,0,0},
                        /*R*/  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0,0},
                        /*S*/  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,1,0},
                        /*T*/  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,1,0,2},
                        /*U*/  {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0}};
                              //A B C D E F G H I J K L M N O P Q R S T U

int distLinhaReta[21] = {11,11,10,9,8,6,9,8,7,5,8,6,3,7,6,4,5,4,3,2,0};

void buscaA(int i){
    if(i<0||i>20){
        cout<<"Sala invalida\n";
        return;
    }
    else if(i==20){
        cout<<"Chegou ao destino\n";
    }
    else{
        //enquanto nao chegar ao destino
        while (true){
            int menor=-1, posicao, anterio=1000;
            for(int j=0;j<21;j++){
                //verifica quais salas tem ligacao com a sala atual
                if (mapaSalas[i][j]!=0){
                    //calcula a distancia da sala atual ate a sala destino, passando pela sala j
                    menor = distLinhaReta[j] + mapaSalas[i][j];
                    //encontrou uma sala com menor distancia
                    if(menor<anterio || menor==-1){
                        //atualiza a menor distancia
                        anterio = menor;
                        //atualiza a posicao da sala com menor distancia
                        posicao = j;
                    }
                }      
            }
            //imprime a sala atual e a proxima sala
            cout<<"Sala "<<static_cast<char>(i+97)<<" -> Sala "<<static_cast<char>(posicao+97)<<endl;
            //atualiza a sala atual
            i = posicao;
            //verifica se chegou ao destino
            if (posicao==20){
                cout<<"Chegou ao destino\n";
                break;
            }
        }     
    }
}

void buscaGulosa(int i){
    if(i<0||i>20){
        cout<<"Sala invalida\n";
        return;
    }
    else if(i==20){
        cout<<"Chegou ao destino\n";
    }
    else{
        //enquanto nao chegar ao destino
        while (true){
            int posicao, anterio=1000;
            for(int j=0;j<21;j++){
                //verifica quais salas tem ligacao com a sala atual
                if (mapaSalas[i][j]!=0){
                    //encontrou uma sala com menor distancia
                    if(distLinhaReta[j]<anterio){
                        //atualiza a menor distancia
                        anterio = distLinhaReta[j];
                        //atualiza a posicao da sala com menor distancia
                        posicao = j;
                    }
                }      
            }
            //imprime a sala atual e a proxima sala
            cout<<"Sala "<<static_cast<char>(i+97)<<" -> Sala "<<static_cast<char>(posicao+97)<<endl;
            //atualiza a sala atual
            i = posicao;
            //verifica se chegou ao destino
            if (posicao==20){
                cout<<"Chegou ao destino\n";
                break;
            }
        }
    }
    
}

int main(){
    int i=0;
    char j;
    while (i!=3){
        cout<<"Escolha um algoritmo de busca heuristica:\n";
        cout<<"1 - Busca Gulosa\n";
        cout<<"2 - Busca A*\n";
        cout<<"3 - Sair\n";
        cin>>i;
        if(i==1){
            do
            {
                cout<<"Digite uma sala, entre A e U, que deseja iniciar a busca: ";
                cin>>j;
                if(j>=65 && j<=85)
                    j=j+32;
                buscaGulosa(j-97);
            } while (!((j>=65 && j<=85) || (j>=97 && j<=117)));         
        }
        else if (i==2){
            do
            {
                cout<<"Digite uma sala, entre A e U, que deseja iniciar a busca: ";
                cin>>j;
                if(j>=65 && j<=85)
                    j=j+32;
                buscaA(j-97);
            } while (!((j>=65 && j<=85) || (j>=97 && j<=117)));
        }
        else if(i==3){
            break;
        }
        else{
            cout<<"Escolha uma opcao valida\n";
            cin>>i;
            
        }
    }
}