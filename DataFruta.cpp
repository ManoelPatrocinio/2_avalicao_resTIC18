#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

void bubbleSort(vector<string> &arr)
{
	int n = arr.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				swap(arr[j], arr[j + 1]);
			}
		}
	}
}

class Data {
private:
    int dia, mes, ano;

public:
    Data(int _dia, int _mes, int _ano) : dia(_dia), mes(_mes), ano(_ano) {}

    string toString() const {
        string ret = "";
        ret.append(to_string(dia));
        ret.append("/");
        ret.append(to_string(mes));
        ret.append("/");
        ret.append(to_string(ano));
        return ret;
    }

    bool operator<(const Data& outraData) const {
        if (ano < outraData.ano)
            return true;
        if (ano > outraData.ano)
            return false;
        if (mes < outraData.mes)
            return true;
        if (mes > outraData.mes)
            return false;
        return dia < outraData.dia;
    }

    bool operator>(const Data& outraData) const {
        return outraData < *this;
    }
};
class Lista
{
public:
	virtual void entradaDeDados() = 0;
	virtual void mostraMediana() = 0;
	virtual void mostraMenor() = 0;
	virtual void mostraMaior() = 0;
	virtual void listaN(int N) = 0;
	//virtual void listarEmOrdem();

	
};

class ListaNomes : public Lista
{
	vector<string> listaNomes;

public:
	int qtd;

	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/

	void entradaDeDados() override
	{

		cout << "Informe a quantidades de nomes : " << endl;
		cin >> qtd;
		cin.ignore();

		for (int i = 0; i < qtd; i++)
		{
			string nome;
			cout << "Informe o nome numero " << i + 1 << ": ";
			getline(cin, nome);
			listaNomes.push_back(nome);
			nome = "";
		}
	}

	void mostraMediana() override
	{

		if (listaNomes.size() % 2 == 0)
		{
			bubbleSort(listaNomes);
			vector<string>::iterator it;
			it = listaNomes.begin();
			advance(it, (listaNomes.size() / 2) - 1);

			cout << "A mediana da lista de strings: " << *it << endl;
		}
		else
		{
			bubbleSort(listaNomes);
			vector<string>::iterator it;
			it = listaNomes.begin();
			advance(it, (listaNomes.size() / 2));

			cout << "A mediana da lista de strings: " << *it << endl;
		}
	}

	void mostraMenor() override
	{
		bubbleSort(listaNomes);

		vector<string>::iterator it;
		it = listaNomes.begin();
		cout << "O primeiro nome da lista alfabeticamente: " << *it << endl;
	}
	void mostraMaior()
	{
		bubbleSort(listaNomes);
		vector<string>::iterator it;
		it = listaNomes.begin();
		advance(it, qtd - 1);
		cout << "O ultimo nome da lista alfabeticamente: " << *it << endl;
	}

	void listaN (int N) override{
		int count = 0;
		for (auto it= listaNomes.begin();it != listaNomes.end(); it++){
			count += 1;
			if (count <= N){
				cout << *it <<endl;

			}else{
				return;
			}
		}
		
	}
	void listaControlada (){
		qtd = 0;
		cout << "informe quantos itens deseja exibir: ";
		cin >> qtd;

		cout << endl << endl;
		listaN(qtd);
	
	}
};

class ListaDatas : public Lista
{
	vector<Data> listaDatas;

public:
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/
	void entradaDeDados()
	{
		int qtd, dia, mes, ano;
		cout << "Informe quantas datas deseja informar: " << endl;
		cin >> qtd;
		cin.ignore();
		for (int i = 0; i < qtd; ++i)
		{

			cout << "Informe o dia:";
			cin >> dia;
			cout << "Informe o mes: ";
			cin >> mes;
			cout << "Informe o ano: ";
			cin >> ano;

			Data novaData(dia, mes, ano);
			listaDatas.push_back(novaData);
		}

	}

	void mostraMediana() override {

		sort(listaDatas.begin(), listaDatas.end());

        int meio = listaDatas.size() / 2;
        if (listaDatas.size() % 2 == 0) {
        	cout << "A mediana da lista de datas: " << listaDatas[meio - 1].toString() << endl;
        } else {
            cout << "A mediana da lista de datas: " << listaDatas[meio - 1].toString() << endl;

        }
    }
	void mostraMenor()
	{
		sort(listaDatas.begin(), listaDatas.end());

       	cout << "A primeira data cronologicamente: " << listaDatas[0].toString() << endl;
	}
	void mostraMaior()
	{
		sort(listaDatas.begin(), listaDatas.end());
		cout << "aqui vai mostrar a ultima data cronologicamente: " << listaDatas[listaDatas.size() - 1].toString() << endl;
	}


	void listaN (int N) override{
		int count = 0;
		for (auto it= listaDatas.begin();it != listaDatas.end(); it++){
			count += 1;
			if (count <= N){
				cout << it->toString() <<endl;

			}else{
				return;
			}

		}
		
	}
	void listaControlada (){
		int qtd = 0;
		cout << "informe quantos itens deseja exibir: ";
		cin >> qtd;
		cout << endl << endl;

		listaN(qtd);
	
	}
};

class ListaSalarios : public Lista {
	vector<float> lista;
	
	public:
	int qtd;
	
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados() override {
		cout << "Informe a quantidades de salarios : " << endl;
		cin >> qtd;
		cin.ignore();

		for (int i = 0; i < qtd; i++)
		{
			float salario;
			cout << "Informe o salario numero: " << i + 1 << ": ";
			cin >> salario;
			lista.push_back(salario);
			
		}

	}
			
	void mostraMediana()override {
		
		if (lista.size() % 2 == 0)
		{
			sort(lista.begin(), lista.end());

			vector<float>::iterator it;
			it = lista.begin();
			advance(it, (lista.size() / 2) - 1);

			cout << "A mediana da lista dos salarios é: " << *it << endl;
		}
		else
		{
			sort(lista.begin(), lista.end());
			vector<float>::iterator it;
			it = lista.begin();
			advance(it, (lista.size() / 2));

			cout << "A mediana da lista de salarios é: " << *it << endl;
		}

	}
	
	void mostraMenor()override {
	
		sort(lista.begin(), lista.end());

       	cout << "O primeiro Salário cronologicamente: " << lista[0] << endl;
	}


	
	void mostraMaior()override {
		
		sort(lista.begin(), lista.end());

		cout << "O ultimo Salário cronologicamente: " << lista[lista.size() - 1]<< endl;
	}

	void listaN (int N) override{
		int count = 0;
		for (auto it= lista.begin();it != lista.end(); it++){
			count += 1;
			if (count <= N){
				cout << *it <<endl;

			}else{
				return;
			}

		}
		
	}
	void listaControlada (){
		int qtd = 0;
		cout << "informe quantos salarios deseja exibir: ";
		cin >> qtd;
		cout << endl << endl;

		listaN(qtd);
	
	}
};


class ListaIdades  : public Lista{
	vector<int> lista;
	
	public:
	int qtd;
	
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/	
	void entradaDeDados()override {
		cout << "Informe a quantidades de idades : " << endl;
		cin >> qtd;
		cin.ignore();

		for (int i = 0; i < qtd; i++)
		{
			int idade;
			cout << "Informe a idade  numero: " << i + 1 << ": ";
			cin >> idade;
			lista.push_back(idade);
			
		}

	}
			
	void mostraMediana() override{
		
		if (lista.size() % 2 == 0)
		{
			sort(lista.begin(), lista.end());

			vector<int>::iterator it;
			it = lista.begin();
			advance(it, (lista.size() / 2) - 1);

			cout << "A mediana da lista de idades é : " << *it << endl;
		}
		else
		{
			sort(lista.begin(), lista.end());
			vector<int>::iterator it;
			it = lista.begin();
			advance(it, (lista.size() / 2));

			cout << "A mediana da lista de idades é: " << *it << endl;
		}

	}
	
	void mostraMenor()override {
	
		sort(lista.begin(), lista.end());

       	cout << "A primeira idade cronologicamente: " << lista[0] << endl;
	}


	
	void mostraMaior()override {
		
		sort(lista.begin(), lista.end());

		cout << "A primeira idade cronologicamente: " << lista[lista.size() - 1]<< endl;
	}

	void listaN (int N) override{
		int count = 0;
		for (auto it= lista.begin();it != lista.end(); it++){
			count += 1;
			if (count <= N){
				cout << *it <<endl;

			}else{
				return;
			}

		}
		
	}
	void listaControlada (){
		int qtd = 0;
		cout << "informe quantas idades deseja exibir: ";
		cin >> qtd;
		cout << endl << endl;

		listaN(qtd);
	
	}
};
int main()
{
	vector<Lista *> listaDeListas;

	ListaNomes listaNomes;
	listaNomes.entradaDeDados();
	listaDeListas.push_back(&listaNomes);
	listaNomes.listaControlada();

	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);
	listaDatas.listaControlada();


	ListaSalarios listaSalarios;
	listaSalarios.entradaDeDados();
	listaDeListas.push_back(&listaSalarios);
	listaSalarios.listaControlada();

	ListaIdades listaIdades;
	listaIdades.entradaDeDados();
	listaDeListas.push_back(&listaIdades);
	listaIdades.listaControlada();


	cout << endl << "--- Listagem geral ---" <<endl;

	for (Lista *l : listaDeListas)
	{
		cout << endl ;
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
		
	}
}
