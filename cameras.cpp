#include <bits/stdc++.h>
#define PB push_back

using namespace std;

void fill(vector<vector<int>> &matriz, int a, int b){
	if(a>=0 && b>=0 && a<matriz.size() && b<matriz[0].size() && matriz[a][b]==1){
		matriz[a][b]=2;
		fill(matriz,a-1,b);
		fill(matriz,a,b-1);
		fill(matriz,a+1,b);
		fill(matriz,a,b+1);
	}
}
int main () {
	// Formatar a entrada de dados
	int N,M,n;
	cin >> N >> M >> n;
	
	string cameras[n][3];
	// Counter variables
	int i,j,k,c;

	for(int k=0;k<n;k++){
		cin >> cameras[k][1] >> cameras[k][0] >> cameras[k][2];
		cameras[k][1]=to_string(stoi(cameras[k][1])-1);
		cameras[k][0]=to_string(stoi(cameras[k][0])-1);
		//cout << "As coordenadas dessa câmera são (" << cameras[k][0] << "," << cameras[k][1] << ") no sentido " << cameras[k][2] << endl; 
	}
	//cout<< "Gerando mapas";

	// Gerar mapas
	vector <vector<int>> map;
	for(i=0;i<M;i++){
		vector<int> v1;
		for(j=0;j<N;j++){
			v1.PB(1);
		}
		map.PB(v1);
	}
	

	// Popular mapas com as câmeras
	// Obs: converter strings para int camereas[k][x]
	//cout << "Populando cameras...";
	for(k=0;k<n;k++){
		if(cameras[k][2]=="N"){
			for(c=stoi(cameras[k][0]);c>=0;c--){
				map[c][stoi(cameras[k][1])] = 0;
			}
		}else if(cameras[k][2]=="S"){
			for(c=stoi(cameras[k][0]);c<M;c++){
				map[c][stoi(cameras[k][1])] = 0;
			}
		}else if(cameras[k][2]=="L"){
			for(c=stoi(cameras[k][1]);c<N;c++){
				map[stoi(cameras[k][0])][c] = 0;
			}
		}else if(cameras[k][2]=="O"){
			for(c=stoi(cameras[k][1]);c>=0;c--){
				map[stoi(cameras[k][0])][c] = 0;
			}
		}else {
			cout << "Orientação de câmera inválida";
			return 0;
		}
	}

	// Pulo do gato -> Recursão do algoritmo bucketfill
	fill(map,0,0);

	
	// Mostre o mapa;
	/*
	for(i=0;i<M;i++){
		for(j=0;j<N;j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	*/

	// Com os mapas, ver se é possível ou não criar um caminho saindo de 1x1 até MxN;
	// Sem passar por nenhuma câmera
	// Mostrar ao final se "S" sim é possível ou "N" não é possível.
	// Ideia: Bucket fill ou Maze algorithm
	// Bucket fill -> Modo mais fácil, porém é complicado retornar arrays em c++
	// Solução: Não precisa retornar as arrays, elas são modificadas automaticamente na memória.
	if(map[M-1][N-1]==2){
		cout << "S";
	}else{
		cout << "N";
	
	}
	return 0;
	
}
// Não deixe de dar uma olhada nesse site: https://neps.academy/br
// É gratuito e tem várias formas de aprender e testar os códigos por lá...
// Foi lá onde testei para ver se o código tava prestando mesmo
