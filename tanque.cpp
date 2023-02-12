#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int consumo, distancia, tanque;
	cin >> consumo;
	cin >> distancia;
	cin >> tanque;

	if(tanque*consumo<distancia){
		float distancia_restante = (distancia - tanque*consumo);
		cout << setprecision(2) << distancia_restante/consumo;
	}else{
		cout << "0.0";
	}
}
