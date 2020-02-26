#include<iostream>
using namespace std;

cout<<"Este es un programa de ejemplo";

typedef struct Arreglo{
	float numero;
}vector;

int menuPrincipal();
vector escrituraDatos(vector);
void lecturaDatos(float a[],int);
float modificarDatos(float *);
void insertarDatos(float a[],int,int);
void eliminarDatos(float a[],int,int);

int menuPrincipal(){
	int opc;
	cout<<"\nOperaciones que se puden realizar: \n1.Escritura\n2.Lectura\n3.Actualizacion\n4.Busqueda secuencial\n5.Salir";
	cout<<"\nQue operacion desea realizar: "; cin>>opc; 
	return opc;
}

int main(){
	int opc,i=0,n,op,m,p,e;
	vector a[30], *ptr;
	cout<<"Cuantos elementos desea que tenga el arreglo: "; cin>>n;
	do{
	system("cls");
	opc=menuPrincipal();
	switch(opc){
		case 1: system("cls");
		    ptr=&a[0];
		    escrituraDatos(ptr,i);
		    i++;
		} break;
		case 2: system("cls"); lecturaDatos(a,i); cout<<"\n"; system("pause"); break;
		case 3: system("cls"); cout<<"Que desea hacer:\n1.Modificar\n2.Insertar\n3.Eliminar\nOpcion: "; cin>>op;
		        switch(op){
		        	case 1: system("cls"); cout<<"Que dato desea modificar: "<<endl; lecturaDatos(a,i);
		        	cout<<"Dato: "; cin>>m; a[m-1]=modificarDatos(a); break;
		        	case 2: system("cls"); if(i<n){
		        		    cout<<"En que posicion desea insertar elemento: "<<endl; lecturaDatos(a,i);
		        		    cout<<"Posicion: "; cin>>p; insertarDatos(a,p,i);
		        	       }
		        	       else{
		        	       	cout<<"No se puden insertar elementos porque el arreglo esta lleno"; system("pause");
						   } break;
		        	case 3: system("cls");
		        	cout<<"Que elemento desea eliminar"<<endl; lecturaDatos(a,i);
		        	cout<<"Elemento: "; cin>>e; eliminarDatos(a,e,i); break;
		        	default: cout<<"No selecciono una opcion valida";
				}
				break;
		case 4:
		break;
		default: exit(0);
	}
}while(opc!=5);
}

vector escrituraDatos(vector *ptr){
	if(i<n){
	cout<<"Ingrese un numero de tipo flotante: "; cin>>ptr->numero;
	ptr++;
	}
	else {
	cout<<"No se pueden ingresar mas elementos"<<endl; system("pause");	
}

void lecturaDatos(float a[],int i){ 
    for(int j=0;j<i;j++){
    	cout<<"Dato ["<<j+1<<"]: "<<a[j]<<endl;
	}
}

float modificarDatos(float *ptr){
	float numero;
	cout<<"Ingresar dato: "; cin>>numero;
	return numero;
}

void insertarDatos(float a[],int p,int i){
	int numero;
	for(int k=i;k>p-1;k++){
		a[k]=a[k-1];
	}
	cout<<"Ingrese el valor a insertar: ";  cin>>numero;
	a[p-1]=numero;
	i++;
}


void eliminarDatos(float a[],int e,int i){
    for(int j=e;j<i;j++){
    	a[j-1]=a[j];
	}
	i--;
}
