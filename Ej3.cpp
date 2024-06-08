#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
class Persona
{
protected:
	friend class Sistema;
	int limite;
    string cod;
	string nombre;
public:
    void llenar_data();
    void mostrar_data();
};
void Persona::llenar_data()
{
	fflush(stdin);
	cout<<"Nombre :  ";getline(cin,nombre);
	cout<<"Codigo :  ";getline(cin,cod);
}
void Persona::mostrar_data()
{
	cout<<"Nombre : "<<nombre<<endl;
	cout<<"Codigo : "<<cod<<endl;
}
//ALUMNO///////////////////////////////////////////////////////////////////
class Alumno:public Persona
{
	string creditos;
public:
	void llenar_data();
	void mostrar_data();
	string getcod();
	string getnombre();
};
void Alumno::llenar_data()
{
	fflush(stdin);
	Persona::llenar_data();
	cout<<"Creditos: ";cin>>creditos;
	limite = 2;
}
void Alumno::mostrar_data()
{
	Persona::mostrar_data();
	cout<<"Creditos: "<<creditos<<endl;
	cout<<"---------------------------------------------------------------------"<<endl;
}
string Alumno::getcod()
{
	return cod;
}
string Alumno::getnombre()
{
	return nombre;
}
//PROFESOR///////////////////////////////////////////////////////////////////////////////
class Profesor:public Persona
{
	string especialidad;
public:
	void llenar_data();
	void mostrar_data();
	string getcod();
	string getnombre();
};
void Profesor::llenar_data()
{
	fflush(stdin);
	Persona::llenar_data();
	cout<<"Especialidad : ";cin>>especialidad;
	limite = 3;
}
void Profesor::mostrar_data()
{
	Persona::mostrar_data();
	cout<<"Especialidad: "<<especialidad<<endl;
	cout<<"\n--------------------------------------------\n";
}
string Profesor::getcod()
{
	return cod;
}
string Profesor::getnombre()
{
	return nombre;
}
//Administrativo///////////////////////////////////////////////////////////////////////////////
class Administrativo:public Persona
{
	string especialidad;
public:
	void llenar_data();
	void mostrar_data();
	string getcod();
	string getnombre();
};
void Administrativo::llenar_data()
{
	fflush(stdin);
	Persona::llenar_data();
	cout<<"Especialidad : ";cin>>especialidad;
	limite = 3;
}
void Administrativo::mostrar_data()
{
	Persona::mostrar_data();
	cout<<"Especialidad: "<<especialidad<<endl;
	cout<<"\n--------------------------------------------\n";
}
string Administrativo::getcod()
{
	return cod;
}
string Administrativo::getnombre()
{
	return nombre;
}
///////Documentos///////////////////////////
class Documentos
{
protected:
	friend class Sistema;
	bool disponible;
    string cod,nombre;
public:
    void llenar_data();
    void mostrar_data();
};
void Documentos::llenar_data()
{
	fflush(stdin);
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
	cout<<"Nombre: ";getline(cin,nombre);
	cout<<"Codigo: ";getline(cin,cod);
	disponible = true;
}
void Documentos::mostrar_data()
{
   	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
	cout<<"Nombre: "<<nombre<<endl;
	cout<<"Codigo: "<<cod<<endl;
}
////////libros////
class Libros :public Documentos
{
    string autor;
public:
    void llenar_data();
	void mostrar_data();
	string getcod();
	string getnombre();
};
void Libros::llenar_data()
{
	Documentos::llenar_data();
	fflush(stdin);
	cout<<"Autor: ";getline(cin,autor);
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}
void Libros::mostrar_data()
{
	Documentos::mostrar_data();
	cout<<"Autor : "<<autor<<endl;
	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
}
string Libros::getcod()
{
	return cod;
}
string Libros::getnombre()
{
	return nombre;
}
//////tesis//////
class tesis :public Documentos
{
    string temadeinvestigacion;
public:
    void llenar_data();
	void mostrar_data();
	string getcod();
	string getnombre();
};
void tesis::llenar_data()
{
	fflush(stdin);
	Documentos::llenar_data();
	cout<<"Tema de Investigacion: ";
	getline(cin,temadeinvestigacion);
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}
void tesis::mostrar_data()
{
	Documentos::mostrar_data();
	cout<<"Tema de Investigacion: "<<temadeinvestigacion<<endl;
	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
}
string tesis::getcod()
{
	return cod;
}
string tesis::getnombre()
{
	return nombre;
}
///////revistas//////
class revistas:public Documentos
{
    string editorial;
public:
    void llenar_data();
	void mostrar_data();
	string getcod();
	string getnombre();
};
void revistas::llenar_data()
{
	Documentos::llenar_data();
	cout<<"Editorial: ";
	getline(cin,editorial);
	cout<<"++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"<<endl;
}
void revistas::mostrar_data()
{
	Documentos::mostrar_data();
	cout<<"Editorial: "<<editorial<<endl;
	cout<<"^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^"<<endl;
}
string revistas::getcod()
{
	return cod;
}
string revistas::getnombre()
{
	return nombre;
}

//  ------------------------------------- prestamos
class Prestamo{
    protected:
		friend class Sistema;
		bool activo;
		string codPrestamo;
		string codPrestamista;
		string codProceso;
		string nombre;
		string fechaInicio;
		string fechaFin;
    private:
		Prestamo();
		void llenar_data();
		void mostrar_data();
		string getcod();
		string getnombre();
		string getcodP();
		string getcodPro();
		bool isActivo();
};
Prestamo::Prestamo(){
	activo=true;
}
void Prestamo::llenar_data(){
	fflush(stdin);
	cout<<"Nombre del articulo a prestarse: ";
	getline(cin,nombre);
	cout << "Codigo del documento de prestamo: ";
    getline(cin, codPrestamo);
	cout << "Codigo de quien realiza el prestamo: ";
    getline(cin, codPrestamista);
	cout << "Codigo del proceso de Prestamo: ";
	getline(cin, codProceso);
    cout << "Fecha de inicio: ";
    getline(cin, fechaInicio);
    cout << "Fecha de fin: ";
    getline(cin, fechaFin);
}
void Prestamo::mostrar_data()
{
    cout << "Nombre del prestamo: " << nombre << endl;
    cout << "Codigo del documento de prestamo: " << codPrestamo << endl;
	cout << "Codigo de quien realizo el prestamo: "<< codPrestamista << endl;
    cout << "Fecha de inicio: " << fechaInicio << endl;
    cout << "Fecha de fin: " << fechaFin << endl;
    cout << "Activo: " << (activo ? "Si" : "No") << endl;
    cout << "--------------------------------------------" << endl;
}
string Prestamo::getcod()
{
    return codPrestamo;
}
string Prestamo::getnombre()
{
    return nombre;
}
string Prestamo::getcodP(){
	return codPrestamista;
}
string Prestamo::getcodPro(){
	return  codProceso;
}
bool Prestamo::isActivo()
{
    return activo;
}

//sistema/////////////////////////////////////////////////////////////////////////////
class Sistema
{
	Alumno *listaAlumno[100];
    Administrativo *listaAdministrativo[100];
	Profesor *listaProfesor[100];
	Libros *listaLibros[100];
    tesis *listaTesis[100];
    revistas *listaRevistas[100];
	Prestamo *listaPrestamos[100];
	int actualAlumno,actualAdministrativo,actualProfesor,actualLibros,actualTesis,actualRevistas,actualprestamo;
public:
	Sistema();
	void ingresar(int);
	void listar(int);
	void buscar(int);
	void eliminar(int);
	~Sistema(){
		for(int i=0; i<100; i++){
			delete listaAlumno[i];
			delete listaAdministrativo[i];
			delete listaLibros[i];
			delete listaProfesor[i];
			delete listaTesis[i];
			delete listaPrestamos[i];
			delete listaRevistas[i];
		}
	};
};
Sistema::Sistema()
{
	for (int i=0;i<100;i++)
	{
		listaAlumno[i]= new Alumno;
        listaAdministrativo[i]= new Administrativo;
		listaProfesor[i]= new Profesor;
		listaLibros[i]=new Libros;
        listaTesis[i]=new tesis;
        listaRevistas[i]=new revistas;
		listaPrestamos[i]=new Prestamo;
	}
	actualAlumno=actualAdministrativo=actualProfesor=actualLibros=actualTesis=actualRevistas=actualprestamo=0;
}
/////////////////////////////SISTEMA-ingresar/////////////////////////////////////////////77777777777777777
void Sistema::ingresar(int tipo)
{
	switch(tipo){
        case 1:
        	listaAlumno[actualAlumno++]->llenar_data();
            break;
        case 2:
        	listaAdministrativo[actualAdministrativo++]->llenar_data();
            break;
        case 3:
            listaProfesor[actualProfesor++]->llenar_data();
            break;
        case 4:
            listaLibros[actualLibros++]->llenar_data();
            break;
        case 5:
            listaTesis[actualTesis++]->llenar_data();
            break;
        case 6:
            listaRevistas[actualRevistas++]->llenar_data();
            break;
        case 7:
            listaPrestamos[actualprestamo++]->llenar_data();
            break;
        default:
            break;
    }


}
//////////////////////////////////SISTEMA-listar/////////////////////////////////////////////////////
void Sistema::listar(int tipo)
{
    switch(tipo){
        case 1:
        for(int i=0;i<actualAlumno;i++)
		{
			listaAlumno[i]->mostrar_data();
		}
            break;
        case 2:
        for(int i=0;i<actualAdministrativo;i++)
		{
			listaAdministrativo[i]->mostrar_data();
		}
            break;
        case 3:
        for(int i=0;i<actualProfesor;i++)
		{
			listaProfesor[i]->mostrar_data();
		}
            break;
        case 4:
        for(int i=0;i<actualLibros;i++)
		{
			listaLibros[i]->mostrar_data();
		}
            break;
        case 5:
        for(int i=0;i<actualTesis;i++)
		{
			listaTesis[i]->mostrar_data();
		}
            break;
        case 6:
        for(int i=0;i<actualRevistas;i++)
		{
			listaRevistas[i]->mostrar_data();
		}
            break;
        case 7:
        for(int i=0;i<actualprestamo;i++)
		{
			listaPrestamos[i]->mostrar_data();
		}
            break;
        default:
            break;
    }

}
///////////////////SISTEMA-buscar/////////////////////////////////////////////////////////////////
void Sistema::buscar(int tipo)
{
	if(tipo==1)
	{
		int x;
		cout<<"Buscar por"<<endl;
		cout<<"(1) Codigo"<<endl;
		cout<<"(2) Nombre"<<endl;
		cout<<"Opcion: ";cin>>x;
		if (x==1)
		{
			string codex;
			cout<<"Codigo de Alumno: ";cin>>codex;
			for(int i=0;i<actualAlumno;i++)
			{
				if(codex==listaAlumno[i]->getcod()){
					listaAlumno[i]->mostrar_data();
					cout<<"Documentos prestados: "<<endl<<endl;
					for(int j=0; j<actualprestamo; j++){
					if(listaAlumno[i]->getcod()==listaPrestamos[j]->getcodP()){
						listaPrestamos[j]->mostrar_data();
						cout<<"-----------------------------------------------"<<endl;
					}
				}
				}
            }
		}
		else if (x==2)
		{
			string name;
			cout<<"Nombre de Alumno: ";cin>>name;
			for(int i=0;i<actualAlumno;i++)
			{
				if(name==listaAlumno[i]->getnombre()){
					listaAlumno[i]->mostrar_data();
					cout<<"Documentos prestados: "<<endl<<endl;
					for(int j=0; j<actualprestamo; j++){
					if(listaAlumno[i]->getcod()==listaPrestamos[j]->getcodP()){
						listaPrestamos[j]->mostrar_data();
						cout<<"-----------------------------------------------"<<endl;
					}
				}	
				}
			}
		}
	}
	else if(tipo==2)
	{
		int x;
		cout<<"Buscar por"<<endl;
		cout<<"(1) Codigo"<<endl;
		cout<<"(2) Nombre"<<endl;
		cout<<"Opcion: ";cin>>x;
		if (x==1)
		{
			string codex;
			cout<<"Codigo del Profesor: ";cin>>codex;
			for(int i=0;i<actualProfesor;i++)
			{
				if(codex==listaProfesor[i]->getcod()){
					listaProfesor[i]->mostrar_data();
					cout<<"Documentos prestados: "<<endl<<endl;
					for(int j=0; j<actualprestamo; j++){
					if(listaProfesor[i]->getcod()==listaPrestamos[j]->getcodP()){
						listaPrestamos[j]->mostrar_data();
						cout<<"-----------------------------------------------"<<endl;
					}
				}
				}
            }
		}
		else if (x==2)
		{
			string name;
			cout<<"Nombre de Profesor: ";cin>>name;
			for(int i=0;i<actualProfesor;i++)
			{
				if(name==listaProfesor[i]->getnombre()){
					listaProfesor[i]->mostrar_data();
					cout<<"Documentos prestados: "<<endl<<endl;
					for(int j=0; j<actualprestamo; j++){
					if(listaProfesor[i]->getcod()==listaPrestamos[j]->getcodP()){
						listaPrestamos[j]->mostrar_data();
						cout<<"-----------------------------------------------"<<endl;
					}
				}	
			}
			}
		}
	}
	else if(tipo==3)
	{
		int x;
		cout<<"Buscar por"<<endl;
		cout<<"(1) Codigo"<<endl;
		cout<<"(2) Nombre"<<endl;
		cout<<"Opcion: ";cin>>x;
		if (x==1)
		{
			string codex;
			cout<<"Codigo de Administrativo: ";cin>>codex;
			for(int i=0;i<actualAdministrativo;i++)
			{
				if(codex==listaAdministrativo[i]->getcod()){
					listaAdministrativo[i]->mostrar_data();
					cout<<"Documentos prestados: "<<endl<<endl;
					for(int j=0; j<actualprestamo; j++){
					if(listaAdministrativo[i]->getcod()==listaPrestamos[j]->getcodP()){
						listaPrestamos[j]->mostrar_data();
						cout<<"-----------------------------------------------"<<endl;
					}
					}
				}
            }
		}
		else if (x==2)
		{
			string name;
			cout<<"Nombre de Alumno: ";cin>>name;
			for(int i=0;i<actualAdministrativo;i++)
			{
				if(name==listaAdministrativo[i]->getnombre()){
					listaAdministrativo[i]->mostrar_data();
					cout<<"Documentos prestados: "<<endl<<endl;
					for(int j=0; j<actualprestamo; j++){
					if(listaAdministrativo[i]->getcod()==listaPrestamos[j]->getcodP()){
						listaPrestamos[j]->mostrar_data();
						cout<<"-----------------------------------------------"<<endl;
					}
					}
				}
			}
		}
	}
	else if(tipo==4)
	{
		int x;
		cout<<"Buscar por"<<endl;
		cout<<"(1) Codigo"<<endl;
		cout<<"(2) Nombre"<<endl;
		cout<<"Opcion: ";cin>>x;
		if (x==1)
		{
			string codex;
			cout<<"Codigo de Libro: ";cin>>codex;
			for(int i=0;i<actualLibros;i++)
			{
				if(codex==listaLibros[i]->getcod()){
					listaLibros[i]->mostrar_data();
					cout<<"Procesos de prestamo de este libro: "<<endl<<endl;
					for(int j=0; j<actualprestamo; j++){
						if(listaLibros[i]->getcod()==listaPrestamos[j]->getcod()){
							listaPrestamos[j]->mostrar_data();
							cout<<"-----------------------------------------------"<<endl;
						}
					}
				}
            }
		}
		else if (x==2)
		{
			string name;
			cout<<"Nombre de Libro: ";cin>>name;
			for(int i=0;i<actualLibros;i++)
			{
				if(name==listaLibros[i]->getnombre()){
					listaLibros[i]->mostrar_data();
					cout<<"Procesos de prestamo de este libro: "<<endl<<endl;
					for(int j=0; j<actualprestamo; j++){
						if(listaLibros[i]->getcod()==listaPrestamos[j]->getcod()){
							listaPrestamos[j]->mostrar_data();
							cout<<"-----------------------------------------------"<<endl;
						}
					}
				}
			}
		}
	}
	else if(tipo==5)
	{
		int x;
		cout<<"Buscar por"<<endl;
		cout<<"(1) Codigo"<<endl;
		cout<<"(2) Nombre"<<endl;
		cout<<"Opcion: ";cin>>x;
		if (x==1)
		{
			string codex;
			cout<<"Codigo de Tesis: ";cin>>codex;
			for(int i=0;i<actualTesis;i++)
			{
				if(codex==listaTesis[i]->getcod()){
					listaTesis[i]->mostrar_data();
					cout<<"Procesos de prestamo de esta tesis: "<<endl<<endl;
					for(int j=0; j<actualprestamo; j++){
						if(listaTesis[i]->getcod()==listaPrestamos[j]->getcod()){
							listaPrestamos[j]->mostrar_data();
							cout<<"-----------------------------------------------"<<endl;
						}
					}
				}
            }
		}
		else if (x==2)
		{
			string name;
			cout<<"Nombre de la Tesis: ";cin>>name;
			for(int i=0;i<actualTesis;i++)
			{
				if(name==listaTesis[i]->getnombre()){
					listaTesis[i]->mostrar_data();
					cout<<"Procesos de prestamo de esta tesis: "<<endl<<endl;
					for(int j=0; j<actualprestamo; j++){
						if(listaTesis[i]->getcod()==listaPrestamos[j]->getcod()){
							listaPrestamos[j]->mostrar_data();
							cout<<"-----------------------------------------------"<<endl;
						}
					}
				}
			}
		}
	}
	else if(tipo==6)
	{
		int x;
		cout<<"Buscar por"<<endl;
		cout<<"(1) Codigo"<<endl;
		cout<<"(2) Nombre"<<endl;
		cout<<"Opcion: ";cin>>x;
		if (x==1)
		{
			string codex;
			cout<<"Codigo de Revista: ";cin>>codex;
			for(int i=0;i<actualRevistas;i++)
			{
				if(codex==listaRevistas[i]->getcod()){
					listaRevistas[i]->mostrar_data();
					cout<<"Procesos de prestamo de esta revista: "<<endl<<endl;
					for(int j=0; j<actualprestamo; j++){
						if(listaRevistas[i]->getcod()==listaPrestamos[j]->getcod()){
							listaPrestamos[j]->mostrar_data();
							cout<<"-----------------------------------------------"<<endl;
						}
					}
				}
            }
		}
		else if (x==2)
		{
			string name;
			cout<<"Nombre de la revista: ";cin>>name;
			for(int i=0;i<actualRevistas;i++)
			{
				if(name==listaRevistas[i]->getnombre()){
					listaRevistas[i]->mostrar_data();
					cout<<"Procesos de prestamo de esta revista: "<<endl<<endl;
					for(int j=0; j<actualprestamo; j++){
						if(listaRevistas[i]->getcod()==listaPrestamos[j]->getcod()){
							listaPrestamos[j]->mostrar_data();
							cout<<"-----------------------------------------------"<<endl;
						}
					}
				}
			}
		}
	}
	else if(tipo==7)
	{
		int x;
		cout<<"Buscar por"<<endl;
		cout<<"(1) Codigo"<<endl;
		cout<<"(2) Nombre"<<endl;
		cout<<"Opcion: ";cin>>x;
		if (x==1)
		{
			string codex;
			cout<<"Codigo del Proces: ";cin>>codex;
			for(int i=0;i<actualprestamo;i++)
			{
				if(codex==listaPrestamos[i]->getcodPro()){
					listaPrestamos[i]->mostrar_data();
				}
            }
		}
		else if (x==2)
		{
			string name;
			cout<<"Nombre del documento prestado: ";cin>>name;
			for(int i=0;i<actualprestamo;i++)
			{
				if(name==listaPrestamos[i]->getnombre())
					listaPrestamos[i]->mostrar_data();
			}
		}
	}


}
///////////////////////SISTEMA-eliminar///////////////////////////////////////////////////////////
void Sistema::eliminar(int tipo)
{
	string codigo;
	cout<<"Ingrese el codigo de lo que desea eliminar: "; 
	cin>>codigo;
	switch (tipo)
	{
	case 1:
		for(int i=0; i<actualAlumno; i++){
			if(listaAlumno[i]->getcod()==codigo){
				delete listaAlumno[i];
				for(int j=i; j<actualAlumno-1; i++){
					listaAlumno[j]=listaAlumno[j+1];
				}
				actualAlumno--;
				for(int j=0; j<actualprestamo; j++){
					if(listaPrestamos[j]->getcodP()==codigo){
						delete listaPrestamos[j];
						for(int k=j; k<actualprestamo-1; k++){
							listaPrestamos[k]=listaPrestamos[k+1];
						}
						actualprestamo--;
						j--;
					}
				}
				cout<<"Alumno eliminado exitosamente"<<endl;
			}
		}
		break;
	case 2:
		for(int i=0; i<actualProfesor; i++){
			if(listaProfesor[i]->getcod()==codigo){
				delete listaProfesor[i];
				for(int j=i; j<actualProfesor-1; j++){
					listaProfesor[j]=listaProfesor[j+1];
				}
				actualProfesor--;
				for(int j=0; j<actualprestamo; j++){
					if(listaPrestamos[j]->getcodP()==codigo){
						delete listaPrestamos[j];
						for(int k=j; k<actualprestamo-1; k++){
							listaPrestamos[k]=listaPrestamos[k+1];
						}
						actualprestamo--;
						j--;
					}
				}
				cout<<"Profesor eliminado exitosamente"<<endl;
			}
		}
		break;
	case 3:
		for(int i=0; i<actualAdministrativo; i++){
			if(listaAdministrativo[i]->getcod()==codigo){
				delete listaAdministrativo[i];
				for(int j=i; j<actualAdministrativo-1; i++){
					listaAdministrativo[j]=listaAdministrativo[j+1];
				}
				actualAdministrativo--;
				for(int j=0; j<actualprestamo; j++){
					if(listaPrestamos[j]->getcodP()==codigo){
						delete listaPrestamos[j];
						for(int k=j; k<actualprestamo-1; k++){
							listaPrestamos[k]=listaPrestamos[k+1];
						}
						actualprestamo--;
						j--;
					}
				}
				cout<<"Administrativo eliminado exitosamente"<<endl;
			}
		}
		break;
	case 4:
		for(int i=0; i<actualLibros; i++){
			if(listaLibros[i]->getcod()==codigo){
				delete listaLibros[i];
				for(int j=i; j<actualLibros-1; j++){
					listaLibros[j]=listaLibros[j+1];
				}
				actualLibros--;
				for(int j=0; j<actualprestamo; j++){
					if(listaPrestamos[j]->getcod()==codigo){
						delete listaPrestamos[j];
						for(int k=j; k<actualprestamo-1; k++){
							listaPrestamos[k]=listaPrestamos[k+1];
						}
						actualprestamo--;
						j--;
					}
				}
				cout<<"Libro eliminado exitosamente"<<endl;
			}
		}
		break;
	case 5:
		for(int i=0; i<actualTesis; i++){
			if(listaTesis[i]->getcod()==codigo){
				delete listaTesis[i];
				for(int j=i; j<actualTesis-1; j++){
					listaTesis[j]=listaTesis[j+1];
				}
				actualTesis--;
				for(int j=0; j<actualprestamo; j++){
					if(listaPrestamos[j]->getcod()==codigo){
						delete listaPrestamos[j];
						for(int k=j; k<actualprestamo-1; k++){
							listaPrestamos[k]=listaPrestamos[k+1];
						}
						actualprestamo--;
						j--;
					}
				}
				cout<<"Tesis eliminada exitosamente"<<endl;
			}
		}
		break;
	case 6:
		for(int i=0; i<actualRevistas; i++){
			if(listaRevistas[i]->getcod()==codigo){
				delete listaRevistas[i];
				for(int j=i; j<actualRevistas-1; j++){
					listaRevistas[j]=listaRevistas[j+1];
				}
				actualRevistas--;
				for(int j=0; j<actualprestamo; j++){
					if(listaPrestamos[j]->getcod()==codigo){
						delete listaPrestamos[j];
						for(int k=j; k<actualprestamo-1; k++){
							listaPrestamos[k]=listaPrestamos[k+1];
						}
						actualprestamo--;
						j--;
					}
				}
				cout<<"Rvista eliminada exitosamente"<<endl;
			}
		}
		break;
	default:
		break;
	}
}

int main()
{
    Sistema s;
    int menu;
    for ( ; ; )
    {

        	cout<<"\t(1) Ingresar datos "<<endl;
	        cout<<"\t(2) Mostrar  Datos "<<endl;
	        cout<<"\t(3) Buscar  datos "<<endl;
	        cout<<"\t(4) Eliminar datos "<<endl;
	        cout<<"\t(5) Salir "<<endl;
	        cout<<"Opcion : ";
	        cin>>menu;
	        cout<<"\n \n";
	        switch (menu)
	        {
	        case 1:
	            cout<<"(1) Ingresar Alumno "<<endl;
	            cout<<"(2) Ingresar Profesor "<<endl;
				cout<<"(3) Ingresar Administrativo"<<endl;
	            cout<<"(4) Ingresar Libro "<<endl;
	            cout<<"(5) Ingresar Tesis "<<endl;
	            cout<<"(6) Ingresar Revista "<<endl;
	            cout<<"(7) Realizar Prestamo "<<endl;
				cout<<"(8) Regresar "<<endl;
	            cout<<"Opcion : ";
	            cin>>menu;
	            s.ingresar(menu);
	            cout<<"\n";
	            break;
	        case 2:
	            cout<<"(1) Mostrar Alumno "<<endl;
	            cout<<"(2) Mostrar Profesor "<<endl;
				cout<<"(3) Mostrar Administrativo"<<endl;
	            cout<<"(4) Mostrar Libro "<<endl;
	            cout<<"(5) Mostrar Tesis "<<endl;;
	            cout<<"(6) Mostrar Revista "<<endl;
				cout<<"(7) Mostrar Prestamos "<<endl;
	            cout<<"(8) Regresar "<<endl;
	            cout<<"Opcion : ";
	            cin>>menu;
	            s.listar(menu);
	            break;
	            cout<<"\n";
	        case 3:
	            cout<<"(1) Buscar Alumno "<<endl;
	            cout<<"(2) Buscar Profesor "<<endl;
				cout<<"(3) Buscar Administrativo"<<endl;
	            cout<<"(4) Buscar Libro "<<endl;
	            cout<<"(5) Buscar Tesis "<<endl;
	            cout<<"(6) Buscar Revista "<<endl;
				cout<<"(7) Buscar Prestamo "<<endl;
	            cout<<"(8) Regresar "<<endl;
	            cout<<"Opcion : ";
	            cin>>menu;
	            s.buscar(menu);
	            break;
	            cout<<"\n";
	        case 4:
	            cout<<"(1) Eliminar Alumno "<<endl;
	            cout<<"(2) Eliminar Profesor "<<endl;
				cout<<"(3) Eliminar Administrativo"<<endl;
	            cout<<"(4) Eliminar Libro "<<endl;
	            cout<<"(5) Eliminar Tesis "<<endl;
	            cout<<"(6) Eliminar Revista "<<endl;
	            cout<<"(7) Regresar "<<endl;
	            cout<<"Opcion : ";
	            cin>>menu;
	            s.eliminar(menu);
	            break;
	            cout<<"\n";
	        case 5:
	            cout<<"Gracias por usar el Sistema"<<endl;
	            return 0;
	        }
    }
	s.~Sistema();
}