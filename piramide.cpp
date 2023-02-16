#include <iostream>
using namespace std;

int main(){
// Receba os valores do input
    int n;
    cin >> n;

// Inicialize as variáveis
    int i,j,k, matriz[n][n];

// Zere a matriz gerada, em c++ se você não definir os valores ficam os requícios da memória
    for(i=0;i<n;i++){
	    for(j=0;j<n;j++){
		    matriz[i][j] = 0;
	    }
    }


// Ideia! Atenção ao encadeamento de "for's", a variável k serve apenas para afunilar as somas para o centro da matriz
    for(k = 0;k<n;k++){
    	// É somar as camadas da matriz, exemplo no final do arquivo
	for(i=k;i<n-k;i++){
		for(j=k;j<n-k;j++){
			matriz[i][j]++;
		}
    	}
    }


// Printa cada elemento da matriz
    for(i=0;i<n;i++){
	for(j=0;j<n;j++){
		cout << matriz[i][j] << " ";
	}
	cout << endl;
    }    
    
    return 0;
}
/*	1 1 1 1               1 1 1 1
 *      1 1 1 1  +   1 1  =   1 2 2 1
 *      1 1 1 1      1 1      1 2 2 1
 *      1 1 1 1               1 1 1 1
 *      k = 0        k=1
 */
// Note que em metade dos casos os dois loops for dentro do loop for(k), não acontecem, sabe explicar por que ?

// Compilando com o gcc, lembrar de inserir a biblioteca do c++
//
// ex: gcc piramide.cpp -o piramide -lstdc++
// -o -> diz o output
// -lstdc++ -> usa a biblioteca do c++
