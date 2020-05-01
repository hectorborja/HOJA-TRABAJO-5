#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
using namespace std;

struct venta{
	int cat;
	int zona;
	int tipo;
	float mt2;
	float precio;
	float tprecio;
};
void venta();
//void reporte(); --- NO ME LO GENERO!!!
int main(){
	venta();
//	reporte();
}

void venta(){
	int cat;
	int zona;
	int tipo;
	float mt2;
	float precio;
	float tprecio;
	string s;
	
	cout<<"\n- - - - - - - - - - - - INMUEBLES Y MÁS HB - - - - - - - - - - - - "<<endl;
	cout<<"\nLos precios por metro cuadrado segun categoria, zona y tipo son los siguientes: "<<endl;
	cout<<"\n\t - - - Categoria Comercial -> Zona A: - - -\n\t\tTerreno: 2,200 x mt2\tCasa: 2,500 x mt2\tDepartamento: 2,100 x mt2 "<<endl;
	cout<<"\n\t - - - Categoria Comercial -> Zona B: - - -\n\t\tTerreno: 1,300 x mt2\tCasa: 1,500 x mt2\tDepartamento: 1,200 x mt2 "<<endl;
	cout<<"\n\t - - - Categoria Residencial -> Zona A: - - -\n\t\tTerreno: 2,100 x mt2\tCasa: 2,500 x mt2\tDepartamento: 2,100 x mt2 "<<endl;
	cout<<"\n\t - - - Categoria Residencial -> Zona B: - - -\n\t\tTerreno: 1,500 x mt2\tCasa: 1,600 x mt2\tDepartamento: 1,300 x mt2 "<<endl;
	cout<<"\n\t - - - Categoria Residencial -> Zona C: - - -\n\t\tTerreno: 1,100 x mt2\tCasa: 1,300 x mt2\tDepartamento: 1,000 x mt2 "<<endl;
	cout<<"\n\t Ingrese la categoria:\n\t\t1 -> Comercial\n\t\t2 -> Residencial"<<endl;
	cin>>cat;
	cout<<"\t Ingrese la zona:  A ->1  B ->2  C->3"<<endl;
	cin>>zona;
	cout<<"\t Ingrese el tipo:\n\t\t1 -> Terreno\n\t\t2 -> Casa\n\t\t3 -> Departamento"<<endl;
	cin>>tipo;
	cout<<"\t Ingrese los metros cuadrados del inmueble: "<<endl;
	cin>>mt2;
	if (cat==1 & zona==1 & tipo==1){
		precio = 2200;
		tprecio = (precio * mt2);
		cout<<"\nEl total a pagar por el inmueble es: "<<tprecio<<endl;
	}
	else if (cat==1 or cat==2 & zona==1 & tipo==2){
		precio = 2500;
		tprecio = (precio * mt2);
		cout<<"\nEl total a pagar por el inmueble es: "<<tprecio<<endl;
	}
	else if (cat==1 or cat==2 & zona==2 or zona==3 & tipo==1 or tipo==2 or tipo==3){
		precio = 1300;
		tprecio = (precio * mt2);
		cout<<"\nEl total a pagar por el inmueble es: "<<tprecio<<endl;
	}
	else if (cat==1 or cat==2 & zona==2 & tipo==1 or tipo==2){
		precio = 1500;
		tprecio = (precio * mt2);
		cout<<"\nEl total a pagar por el inmueble es: "<<tprecio<<endl;
	}
	else if (cat==1 & zona==2 & tipo==3){
		precio = 1200;
		tprecio = (precio * mt2);
		cout<<"\nEl total a pagar por el inmueble es: "<<tprecio<<endl;
	}
	else if (cat==2 or cat==1 & zona==1 & tipo==1 or tipo==3){
	precio = 2100;
	tprecio = (precio * mt2);
	cout<<"\nEl total a pagar por el inmueble es: "<<tprecio<<endl;
	}
	else if (cat==2 & zona==2 & tipo==2){
	precio = 1600;
	tprecio = (precio * mt2);
	cout<<"\nEl total a pagar por el inmueble es: "<<tprecio<<endl;
	}
	else if (cat==2 & zona==3 & tipo==1){
	precio = 1100;
	tprecio = (precio * mt2);
	cout<<"\nEl total a pagar por el inmueble es: "<<tprecio<<endl;
	}
	else if (cat==2 & zona==3 & tipo==3){
	precio = 1000;
	tprecio = (precio * mt2);
	cout<<"\nEl total a pagar por el inmueble es: "<<tprecio<<endl;
	}
	cout<<"\nCategoria: "<<cat<<"\tZona: "<<zona<<"\tTipo de Inmueble: "<<tipo<<"\tMetros Cuadrados: "<<mt2<<"\tPrecio: "<<precio<<"\tTotal a pagar: "<<tprecio;
	ofstream grabarc;
	try {
		grabarc.open("ejericio1.txt",ios::app);
		grabarc<<cat<<"\t"<<zona<<"\t"<<tipo<<"\t"<<mt2<<"\t"<<precio<<"\t"<<tprecio<<endl;
		grabarc.close();
	}
	catch(exception X){
		cout<<"Error con el archivo"<<endl;
	}
	cout<<"\n"<<"\nINMUEBLES COTIZADOS"<<endl;
	cout<<"\nCat --------	Zona --------------	Tipo ----------------  	m^2 -------------  	Precio -------------	Total Precio"<<endl;
	ifstream leerarc;
	try {
		leerarc.open("ejercicio1.txt",ios::in);
		while (getline(leerarc, s))
			cout<<s<<endl;
		leerarc.close();
	}
	catch(exception X){
		cout<<"Error en el archivo"<<endl;
	}
}

void reporte(){
	ifstream db;
	float c,z,t,m2,p,tp=0;
	float stotal=0;
	float c1=0;
	float c2=0;

	try {
		db.open("inmuebles.txt",ios::in);
		
		while (db >> c >> z >> t >> m2 >> p >> tp){
			stotal= tp + stotal;
			if (c==1)
				c1+=tp;
			else if (c==2)
				c2+=tp;
		}
		db.close();
		
		cout<<setprecision(5)<<"Total: 			"<<stotal<<endl;
		cout<<"Desgloce por inmueble:	"<<endl;
		cout<<setprecision(5)<<"Categoria 1"<<c1<<"Total:	"<<stotal<<endl;
		cout<<setprecision(5)<<"Categoria 2"<<c2<<"Total:	"<<stotal<<endl;
	}	
	catch (exception X){
		cout<<"Error en el archivo"<<endl;
		exit(1);
	}
}

