#include<iostream>
#include<fstream>
#include<cstdlib>
using namespace std;

void menu();
void input();
void read();

int main(){
	menu();
}
void menu(){
	int option=0;
	do{
		system("CLS");
		cout<<"Men� principal"<<endl;	
		cout<<"1. Registrar venta"<<endl;
		cout<<"2. Generar reporte de venta"<<endl;
		cout<<"3. Salir"<<endl;
		cin>>option;
		if(option==1){
			int n,i=0;
			system("CLS");
			cout<<"Cuantas entradas adquirir�? "<<endl;
			cin>>n;
			for(i;i<n;i++){
				system("CLS");
				input();
			}
		}
		if(option==2){
			system("CLS");
			read();
		}
	}while(option!=3);
	
}
void input(){
	float suma;
	int spot=0;
	float price;
	int n=0;
	system("CLS");
	cout<<"Seleccionar la localidad"<<endl;
	cout<<"1. VIP		Q 350.00"<<endl;
	cout<<"2. Platea	Q 130.00"<<endl;
	cout<<"3. Popular	Q  50.00"<<endl;
	cin>>spot;
	if(spot==1){
		price=350.00;
	}
	else if(spot==2){
		price=130.00;
	}
	else if(spot==3){
		price=50;
}
	else{
		system("CLS");
		cout<<"Ingresar un dato v�lido"<<endl;
		system("PAUSE");
	}
	suma=suma+price;
	n=n+1;
	cout<<"La suma hasta el momento es de: Q "<<suma<<endl;
	cout<<"Cantidad: "<<n<<endl;
	system("PAUSE");
	ofstream archivo;
	archivo.open("ejercicio2.txt",ios::app);
	if(archivo.fail()){
		system("CLS");
		cout<<"No se puede abrir el archivo"<<endl;
		exit(1);
	}
	archivo<<spot<<"\t"<<price<<endl;
	archivo.close();
}
void read(){
	system("CLS");
	int p;
	float s;
	int n=0;
	int t=0;
	float vip=0;
	float platea=0;
	float popular=0;
	ifstream archivo;
	int socio;
	cout<<"El comprador es socio?"<<endl;
	cout<<"1. Si"<<endl;
	cout<<"2. No"<<endl;
	cin>>socio;
	system("CLS");
	try{
		archivo.open("ejercicio2.txt",ios::in);
		while(archivo>>t>>p){
			cout<<"Tipo de entrada \t"<<t<<"Precio: \t"<<p<<endl;
			s+=p;
			n+=1;
			if(t==1)
				vip+=p;
			else if(t==2)
				platea+=p;
			else if(t==3)
				popular+=p;
		}
		cout<<"Suma total: "<<s<<endl;
		cout<<"Cantidad total: "<<n<<endl;
		if(n>=3 && n<=6){
			s=s*0.95;
			popular*=0.95;
			vip*=0.95;
			platea*=0.95;
		}
		else if(n>=7 && n<=9){
			
		}
		else if(n>=10){
			s=s*0.90;
			popular*=0.90;
			vip*=0.90;
			platea*=0.90;
		}
		if(socio==1){
			s=s*0.92;
			popular*=0.92;
			vip*=0.92;
			platea*=0.92;
		}
		cout<<"Precio con descuento "<<s<<endl;
		cout<<"Total vendido VIP: "<<vip<<endl;
		cout<<"Total vendido Platea: "<<platea<<endl;
		cout<<"Total vendido Popular: "<<popular<<endl;
		archivo.close();
		cout<<"Porcentaje respecto al total"<<endl; 
		cout<<"VIP: "<<(vip * 100)/s<<endl;
		cout<<"Platea "<<(platea*100)/s<<endl;
		cout<<"Popular "<<(popular*100)/s<<endl;
	}
	catch(exception){
		system("CLS");
		cout<<"No se pudo abrir el archivo"<<endl;
		exit(1);
	}
	system("PAUSE");
}
