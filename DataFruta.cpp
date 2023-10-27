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

class Data
{
	int dia, mes, ano;

public:
	/*
	O m�todo abaixo retornar� -1 se d1 � anterior a d2
	Retornar� 0 se d1 = d2
	Retornar� +1 se d1 � posterior a d2
	*/
	static int compara(Data d1, Data d2)
	{

		if (d1.ano < d2.ano)
		{
			return -1;
		}
		else if (d1.ano == d2.ano)
		{
			if (d1.mes < d2.mes)
			{
				return -1;
			}
			else if (d1.mes == d2.mes)
			{
				if (d1.dia < d2.dia)
				{
					return -1;
				}
				else if (d1.dia == d2.dia)
				{
					return 0;
				}
				else
				{
					return 1;
				}
			}
			else
			{
				return 1;
			}
		}
		else
		{
			return 1;
		}
	}

	Data(int _dia, int _mes, int _ano)
	{
		dia = _dia;
		mes = _mes;
		ano = _ano;
	}
	string toString()
	{
		string ret = "";
		ret.append(to_string(dia));
		ret.append("/");
		ret.append(to_string(mes));
		ret.append("/");
		ret.append(to_string(ano));
		return ret;
	}
};

class Lista
{
public:
	virtual void entradaDeDados() = 0;
	virtual void mostraMediana() = 0;
	virtual void mostraMenor() = 0;
	virtual void mostraMaior() = 0;


    virtual ~Lista() {}
	
    Data encontraMediana(vector<Data> valores) {
       sort(valores.begin(), valores.end());

        int meio = valores.size() / 2;
        if (valores.size() % 2 == 0) {
            return valores[meio - 1];
        } else {
            return valores[meio];
        }
    }
	
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
        cout << "A mediana da lista de datas e: " << encontraMediana(listaDatas).toString() << endl;
    }
	void mostraMenor()
	{
		cout << "Aqui vai mostrar a primeira data cronologicamente" << endl;
	}
	void mostraMaior()
	{
		cout << "aqui vai mostrar a ultima data cronologicamente" << endl;
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
		l->mostraMediana();
		l->mostraMenor();
		l->mostraMaior();
	}
}
