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
		cout << "A ultima data cronologicamente: " << listaDatas[listaDatas.size() - 1].toString() << endl;
	}
};

class ListaSalarios
{
	vector<float> lista;

public:
	/*
	O m�todo abaixo pergunta ao usu�rios quantos
	elementos v�o existir na lista e depois
	solicita a digita��o de cada um deles
	*/
	void entradaDeDados()
	{
	}

	void mostraMediana()
	{
		cout << "Aqui vai mostrar a mediana da lista de salarios" << endl;
	}

	void mostraMenor()
	{
		cout << "Aqui vai mostrar o menor dos salarios" << endl;
	}
	void mostraMaior()
	{
		cout << "aqui vai mostrar o maior dos salarios" << endl;
	}
};

class ListaIdades
{
	vector<int> lista;

public:
	/*
O m�todo abaixo pergunta ao usu�rios quantos
elementos v�o existir na lista e depois
solicita a digita��o de cada um deles
*/
	void entradaDeDados()
	{
	}

	void mostraMediana()
	{
		cout << "Aqui vai mostrar a mediana da lista de idades" << endl;
	}

	void mostraMenor()
	{
		cout << "Aqui vai mostrar a menor das idades" << endl;
	}
	void mostraMaior()
	{
		cout << "aqui vai mostrar a maior das idades" << endl;
	}
};

int main()
{
	vector<Lista *> listaDeListas;

	ListaNomes listaNomes;
	listaNomes.entradaDeDados();
	listaDeListas.push_back(&listaNomes);

	ListaDatas listaDatas;
	listaDatas.entradaDeDados();
	listaDeListas.push_back(&listaDatas);

	// ListaSalarios listaSalarios;
	// listaSalarios.entradaDeDados();
	// listaDeListas.push_back(&listaSalarios);

	// ListaIdades listaIdades;
	// listaIdades.entradaDeDados();
	// listaDeListas.push_back(&listaIdades);

	for (Lista *l : listaDeListas)
	{
		cout << endl << endl;
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
	}
}
