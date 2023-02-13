#include <iostream>
using namespace std;


int main () {
	// Formatar a entrada de dados
	string input;
	getline (cin, input);
	
	int N,M,n;
	string swap;
	int info[2];
	int counter =0;
	int c,k;
	
	for(c=0;c<input.lenght();c++){
		if(input[c]!=" "){
			swap += input[c];	
		}
		else{
			info[counter] = swap;
			counter++;
		}
	}
	n = swap;
	N = info[0];
	M = info[1];

	
	string cameras[n][3];

	for(k=0;k<n;k++){
		string camera_info;
		cin.ignore();
		getline (cin,camera_info);
		
		swap = "";
		counter = 1;

		for(c=0;c<camera_info.lenght();c++){
			if(camera_info[c]!=" "){
				swap += camera_info[c];
			}else{
				cameras[k][counter] = swap;
				counter--;
			}
		cameras[k][2] = swap;
		}


	}

	// Gerar mapas
	bool map[M+2][N+2];
	int i,j;
	for(i=0;i<M+2;i++){
		for(j=0;j<N+2;j++){
 			if(i = 0 || j = 0 || i= M+1 || j=N+1){
				map[i][j]=false;;
			}else{
				map[i][j]=true;
			}
		}
	}

	// Popular mapas com as câmeras
	// Obs: converter strings para int camereas[k][x]
	
	for(k=0;k<n;k++){
		if(cameras[k][2]=="N"){
			for(c=cameras[k][0];c>0;c--){
				map[c][cameras[k][1]] = false;
			}
		}
		if(cameras[k][2]=="S"){
			for(c=cameras[k][0];c<N+2;c++){
				map[c][cameras[k][1]] = false;
			}
		}
		if(cameras[k][2]=="L"){
			for(c=cameras[k][1];c<M+2;c++){
				map[cameras[k][0]][c] = false;
			}
		}
		if(cameras[k][2]=="O"){
			for(c=cameras[k][1];c>0;c--){
				map[cameras[k][0]][c] = false;
			}
		}
	}
	
	// Mostre o mapa;
	for(i=0;i<M+2;i++){
		for(j=0;j<N+2;j++){
			cout << map[i][j] << " ";
		}
		cout << endl;
	}
	// Com os mapas, ver se é possível ou não criar um caminho saindo de 1x1 até MxN;
	// Sem passar por nenhuma câmera

}
