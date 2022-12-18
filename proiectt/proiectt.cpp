
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;


class Eveniment
{
private:
	char* numeEveniment;
	static int nrEvenimente;
	string dataEveniment;
	string oraEveniment;
	float* pretBilet;
	int nrBilete;
	const int id_unic;
public:


	Eveniment() :id_unic(0)
	{
		cout << "\nCONSTRUCTOR FARA PARAMETRI";
		numeEveniment = nullptr;

		dataEveniment = "";
		oraEveniment = "";
		pretBilet = nullptr;


	}
	Eveniment(char* numeEveniment, float* pretBilet, int nrBilete, string dataEveniment, string oraEveniment) :id_unic(0)
	{
		cout << "\nCONSTRUCTOR CU TOTI PARAMETRI";
		this->numeEveniment = new char[strlen(numeEveniment) + 1];
		strcpy(this->numeEveniment, numeEveniment);
		if (nrBilete > 0 && pretBilet != nullptr)
		{
			this->nrBilete = nrBilete;
			for (int i = 0; i < this->nrBilete; i++)
			{
				this->pretBilet[i] = pretBilet[i];
			}
		}
		else
		{
			this->pretBilet = 0;
		}

		if (dataEveniment.length() > 0) this->dataEveniment = dataEveniment;
		if (oraEveniment.length() > 0) this->oraEveniment = oraEveniment;
	}

	char* getnumeEveniment()
	{
		return this->numeEveniment;
	}

	void setOraEveniment(string oraEveniment)
	{

		if (oraEveniment.length() > 0)
			this->oraEveniment = oraEveniment;
	}
	void setDataEveniment(string oraEveniment)
	{

		if (dataEveniment.length() > 0)
			this->dataEveniment = dataEveniment;
	}
	void setPretBilet(float* pretBilet)
	{

		if (nrBilete > 0 && pretBilet != nullptr)
		{
			for (int i = 0; i < nrBilete; i++)
				this->pretBilet[i] = pretBilet[i];
		}

	}

	string getoraEveniment()
	{
		return oraEveniment;
	}
	string getdataEveniment()
	{
		return dataEveniment;
	}

	Eveniment(const Eveniment& sursa) :id_unic(0)
	{

		cout << "\nCONSTRUCTOR DE COPIERE";
		this->numeEveniment = new char[strlen(sursa.numeEveniment) + 1];
		strcpy(this->numeEveniment, sursa.numeEveniment);
		if (sursa.nrBilete > 0 && sursa.pretBilet != nullptr)
		{
			this->nrBilete = sursa.nrBilete;
			for (int i = 0; i < this->nrBilete; i++)
			{
				this->pretBilet[i] = sursa.pretBilet[i];
			}
		}

		if (sursa.dataEveniment != "") this->dataEveniment = sursa.dataEveniment;
		if (sursa.oraEveniment != "") this->oraEveniment = sursa.oraEveniment;


	}
	Eveniment& operator =(const Eveniment& sursa)
	{
		cout << "\nSUPRAINCARCAREA OPERATORULUI egal:";
		if (this != &sursa)
		{
			delete[] this->numeEveniment;

			this->numeEveniment = new char[strlen(sursa.numeEveniment) + 1];
			strcpy(this->numeEveniment, sursa.numeEveniment);

			if (sursa.nrBilete > 0 && sursa.pretBilet != nullptr)
			{
				this->nrBilete = sursa.nrBilete;
				for (int i = 0; i < this->nrBilete; i++)
				{
					this->pretBilet[i] = sursa.pretBilet[i];
				}
			}

			if (sursa.dataEveniment != "") this->dataEveniment = sursa.dataEveniment;
			if (sursa.oraEveniment != "") this->oraEveniment = sursa.oraEveniment;
		}
		return *this;
	}


	friend ostream& operator << (ostream& out, Eveniment  sursa)
	{
		out << "\n====================";
		out << "\nNume Eveniment: " << sursa.numeEveniment;
		out << "\nNumar Bilete: " << sursa.nrBilete;
		out << "\nData Evenimentului " << sursa.dataEveniment;
		out << "\nOra Evenimentului " << sursa.oraEveniment;
		out << "\nPret Bilet: ";
		for (int i = 0; i < sursa.nrBilete; i++)
		{
			out << sursa.pretBilet[i] << " ";
		}

		out << "\n=======================";
		out << endl;


		return out;
	}
	friend istream& operator>> (istream& in, Eveniment& sursa)
	{



		cout << "Nume Eveniment: ";
		char* numeEveniment;
		numeEveniment = new char[strlen("Necunoscut") + 1];
		in >> numeEveniment;
		strcpy(sursa.numeEveniment, numeEveniment);




		cout << "\nNumar Evenimente: ";
		int nrEvenimente;
		in >> nrEvenimente;
		sursa.nrEvenimente = nrEvenimente;


		cout << "\nNumar Bilete: ";
		int nrBilete;
		in >> nrBilete;
		sursa.nrBilete = nrBilete;

		float pretBilet[100];
		cout << "\nPretul biletului:";

		for (int i = 0; i < sursa.nrBilete; i++)
		{
			in >> pretBilet[i];
			sursa.pretBilet[i] = pretBilet[i];
		}

		cout << "\nData Evenimentului:";
		in >> sursa.dataEveniment;

		cout << "\nOra Evenimentului:";
		in >> sursa.oraEveniment;

		return in;


	}
	float& operator[](int index)
	{
		if (index >= 0 && index < this->nrBilete)
		{
			return this->pretBilet[index];
		}

	}


	Eveniment& operator ++()
	{
		nrBilete++;
		return *this;
	}
	void afisare()
	{
		cout << "\n====================";
		cout << "\nNumar Evenimente: " << this->nrEvenimente;
		cout << "\nNume Eveniment: " << this->numeEveniment;
		cout << "\nNumar Bilete: " << this->nrBilete;
		cout << "\nData Evenimentului: " << this->dataEveniment;
		cout << "\nOra Evenimentului: " << this->oraEveniment;
		cout << "\nPret Bilet: ";
		for (int i = 0; i < this->nrBilete; i++)
		{
			cout << this->pretBilet[i] << " ";
		}

		cout << "\n=======================";
	}
	~
		Eveniment()
	{
		delete[] this->numeEveniment;
	}
};
class ZonaEveniment
{
private:
	int* Zona;
	int nrZone;
	int categorie[2];
	int* intrare;
	int nrintrare;
	int rand;
	int loc;


public:
	ZonaEveniment()
	{
		cout << "\nCONSTRUCTOR FARA PARAMETRI";
		Zona = nullptr;
		nrZone = 0;
		nrintrare = 0;
		rand = 0;
		loc = 0;
		intrare = nullptr;

	}
	ZonaEveniment(int* Zona, int nrZone, int categorie[], int* intrare, int nrintrare, int rand, int loc)
	{
		cout << "\nCONSTRUCTOR CU TOTI PARAMETRI";

		if (nrZone > 0 && Zona != nullptr)
		{
			this->nrZone = nrZone;
			for (int i = 0; i < this->nrZone; i++)
			{
				this->Zona[i] = Zona[i];
			}
		}
		else
		{
			this->Zona = nullptr;
		}
		if (nrintrare > 0 && intrare != nullptr)
		{
			this->nrintrare = nrintrare;
			for (int i = 0; i < this->nrintrare; i++)
			{
				this->intrare[i] = intrare[i];
			}
		}
		else
		{
			this->intrare = nullptr;
		}
		if (rand > 0) this->rand = rand;
		if (loc > 0) this->rand = rand;
	}

	int* getZona()
	{
		if (Zona != nullptr)
		{
			int* copy = new int[nrZone];
			for (int i = 0; i < nrZone; i++)
			{
				copy[i] = Zona[i];
			}
			return copy;
		}
		else return nullptr;
	}

	void setZona(int* Zona, int nrZone)
	{
		if (Zona != nullptr && nrZone > 0)
		{
			delete[]this->Zona;
			this->Zona = new int[nrZone];
			for (int i = 0; i < nrZone; i++)
			{
				this->Zona[i] = Zona[i];
			}
			this->nrZone = nrZone;
		}
	}
	void setIntrare(int* intrare, int nrintrare)
	{
		if (intrare != nullptr && nrintrare > 0)
		{
			delete[]this->intrare;
			this->intrare = new int[nrintrare];
			for (int i = 0; i < nrintrare; i++)
			{
				this->intrare[i] = intrare[i];
			}
			this->nrintrare = nrintrare;
		}
	}
	int setrand(int rand)
	{
		if (rand > 0) this->rand = rand;
	}
	int setloc(int loc)
	{
		if (loc > 0) this->loc = loc;
	}
	int getrand()
	{
		return rand;
	}
	int getloc()
	{
		return loc;
	}

	int* getintrare()
	{
		if (intrare != nullptr)
		{
			int* copy = new int[nrintrare];
			for (int i = 0; i < nrintrare; i++)
			{
				copy[i] = intrare[i];
			}
			return copy;
		}
		else return nullptr;
	}
	ZonaEveniment(const ZonaEveniment& sursa)
	{

		cout << "\nCONSTRUCTOR DE COPIERE";
		if (sursa.nrZone > 0 && sursa.Zona != nullptr)
		{
			this->nrZone = sursa.nrZone;
			for (int i = 0; i < this->nrZone; i++)
			{
				this->Zona[i] = sursa.Zona[i];
			}
		}
		if (sursa.nrintrare > 0 && sursa.intrare != nullptr)
		{
			this->nrintrare = sursa.nrintrare;
			for (int i = 0; i < this->nrintrare; i++)
			{
				this->intrare[i] = sursa.intrare[i];
			}
		}
		if (sursa.rand > 0) this->rand = sursa.rand;
		if (sursa.loc > 0) this->rand = sursa.rand;


	}
	ZonaEveniment& operator =(const ZonaEveniment& sursa)
	{
		cout << "\nSUPRAINCARCAREA OPERATORULUI egal:";
		if (this != &sursa)
		{
			delete[] this->Zona;
			delete[]this->intrare;

			if (sursa.nrZone > 0 && sursa.Zona != nullptr)
			{
				this->nrZone = sursa.nrZone;
				for (int i = 0; i < this->nrZone; i++)
				{
					this->Zona[i] = sursa.Zona[i];
				}
			}
			if (sursa.nrintrare > 0 && sursa.intrare != nullptr)
			{
				this->nrintrare = sursa.nrintrare;
				for (int i = 0; i < this->nrintrare; i++)
				{
					this->intrare[i] = sursa.intrare[i];
				}
			}
			if (sursa.rand > 0) this->rand = sursa.rand;
			if (sursa.loc > 0) this->rand = sursa.loc;
		}
		return *this;
	}


	friend ostream& operator << (ostream& out, ZonaEveniment  sursa)
	{
		out << "\n====================";
		out << "\nloc: " << sursa.loc;
		out << "\nrand: " << sursa.rand;

		out << "\nNumar zone:" << sursa.nrZone;

		for (int i = 0; i < sursa.nrZone; i++)
		{
			out << sursa.Zona[i] << " ";
		}
		out << "\nNumar intrare:" << sursa.nrintrare;
		for (int i = 0; i < sursa.nrintrare; i++)
		{
			out << sursa.intrare[i] << " ";
		}
		out << "\n=======================";
		out << endl;


		return out;
	}
	friend istream& operator>> (istream& in, ZonaEveniment& sursa)
	{
		cout << "\nNumar intrare: ";
		int nrintrare;
		in >> nrintrare;
		sursa.nrintrare = nrintrare;


		cout << "\nNumar Zone: ";
		int nrZone;
		in >> nrZone;
		sursa.nrZone = nrZone;
		if (sursa.Zona != nullptr)
		{
			delete[] sursa.Zona;
			sursa.Zona = nullptr;
		}
		if (sursa.intrare != nullptr)
		{
			delete[] sursa.intrare;
			sursa.intrare = nullptr;
		}
		int categorie[2];
		cout << "\nCategoria:";
		for (int i = 1; i <= 2; i++)
			cout << "\n" << categorie[i];
		cout << "\nZona:";

		for (int i = 0; i < sursa.nrZone; i++)
		{
			in >> sursa.Zona[i];
		}
		cout << "\nIntrare:";

		for (int i = 0; i < sursa.nrintrare; i++)
		{
			in >> sursa.intrare[i];

		}

		return in;


	}

	bool operator!()
	{
		if (this->loc > 0)
		{
			return true;
		}
		return false;
	}


	void afisare()
	{
		cout << "\n====================";

		cout << "\nCategoria: " << this->categorie;
		cout << "\nNumar intrare: " << this->nrintrare;
		for (int i = 0; i < this->nrintrare; i++)
		{
			cout << this->intrare[i] << " ";
		}
		cout << "\nNumar Zona: " << this->nrZone;
		for (int i = 0; i < this->nrZone; i++)
		{
			cout << this->Zona[i] << " ";
		}

		cout << "\n=======================";
	}
	~
		ZonaEveniment()
	{
		delete[] this->Zona;

		delete[] this->intrare;
	}






};
class Locatie
{
private:
	char* adresa;
	int nrlocatii;

public:
	Locatie()
	{
		cout << "\nCONSTRUCTOR FARA PARAMETRI";
		adresa = nullptr;
		nrlocatii = 0;


	}
	Locatie(char* adresa)
	{
		cout << "\nCONSTRUCTOR CU TOTI PARAMETRI";
		this->adresa = new char[strlen(adresa) + 1];
		strcpy(this->adresa, adresa);
		if (nrlocatii > 0) this->nrlocatii = nrlocatii;
	}


	void setlocatie(char* adresa)
	{
		if (adresa != nullptr)
		{
			delete[]this->adresa;
			this->adresa = adresa;

		}
	}




	Locatie(const Locatie& sursa)
	{

		cout << "\nCONSTRUCTOR DE COPIERE";
		if (adresa != "") this->adresa = adresa;

	}
	Locatie& operator =(const Locatie& sursa)
	{
		cout << "\nSUPRAINCARCAREA OPERATORULUI egal:";
		if (this != &sursa)
		{

			if (sursa.adresa != "")
			{
				this->adresa = sursa.adresa;

			}
			{
				this->adresa = nullptr;
			}

		}
		return *this;
	}
	char* getadresa()
	{
		return adresa;
	}


	friend ostream& operator << (ostream& out, Locatie  sursa)
	{
		out << "\n====================";
		out << "\nadresa: " << sursa.adresa;

		out << "\n=======================";
		out << endl;


		return out;
	}
	friend istream& operator>> (istream& in, Locatie& sursa)
	{
		cout << "\nAdresa: ";
		char* adresa;
		in >> adresa;
		sursa.adresa = adresa;


		return in;


	}



	void afisare()
	{
		cout << "\n====================";

		cout << "\nAdresa: " << this->adresa;


		cout << "\n=======================";
	}
	~Locatie()
	{
		if (adresa != "")
			delete[] this->adresa;


	}



};
int Eveniment::nrEvenimente = 3;
int main()
{
	Eveniment e1;
	//Eveniment e2("Film", 20.00, 2, "2022", "14");




}

