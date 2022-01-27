#include <iostream>

#include <vector>

#include <fstream>

#include <string>

#include <time.h> 

using namespace std;

void Print(string message)
{
	cout << ' ' << endl;
	bool front = true;
	for (int i = message.length(); i < 33; i++)
	{
		if (front)
			message = " " + message;
		else
			message = message + " ";
		front = !front;
	}
	cout << message.c_str();
	cout << ' ' << endl;
	cout << ' ' << endl;
	cout << ' ' << endl;
}

void Spanzuratul(int incercari = 0)
{
	if (incercari == 0)
	{
		cout << "            -----" << endl;
		cout << "           |     |" << endl;
		cout << "           |" << endl;
		cout << "           |" << endl;
		cout << "           |" << endl;
		cout << "           |" << endl;
		cout << "        -------" << endl;
	}
	if (incercari == 1)
	{
		cout << "            -----" << endl;
		cout << "           |     |" << endl;
		cout << "           |     O" << endl;
		cout << "           |" << endl;
		cout << "           |" << endl;
		cout << "           |" << endl;
		cout << "        -------" << endl;
	}
	if (incercari == 2)
	{
		cout << "            -----" << endl;
		cout << "           |     |" << endl;
		cout << "           |     O" << endl;
		cout << "           |     |" << endl;
		cout << "           |" << endl;
		cout << "           |" << endl;
		cout << "        -------" << endl;
	}
	if (incercari == 3)
	{
		cout << "            -----" << endl;
		cout << "           |     |" << endl;
		cout << "           |     O" << endl;
		cout << "           |    /|" << endl;
		cout << "           |" << endl;
		cout << "           |" << endl;
		cout << "        -------" << endl;
	}
	if (incercari == 4)
	{
		cout << "            -----" << endl;
		cout << "           |     |" << endl;
		cout << "           |     O" << endl;
		cout << "           |    /|\\" << endl;
		cout << "           |" << endl;
		cout << "           |" << endl;
		cout << "        -------" << endl;
	}
	if (incercari == 5)
	{
		cout << "            -----" << endl;
		cout << "           |     |" << endl;
		cout << "           |     O" << endl;
		cout << "           |    /|\\" << endl;
		cout << "           |    /" << endl;
		cout << "           |" << endl;
		cout << "        -------" << endl;
	}
	if (incercari >= 6)
	{
		cout << "            -----" << endl;
		cout << "           |     |" << endl;
		cout << "           |     O" << endl;
		cout << "           |    /|\\" << endl;
		cout << "           |    / \\" << endl;
		cout << "           |" << endl;
		cout << "        -------" << endl;
	}
}

bool LitereCorecte(string cuvant, string corect)
{
	bool verifica = true;
	string s;
	for (int i = 0; i < cuvant.length(); i++)
	{
		if (corect.find(cuvant[i]) == string::npos)
		{
				verifica = false;
				s += "_ ";
		}
		else
		{
			s += cuvant[i];
			s += " ";
		}
	}
	Print(s);
	return verifica;
}

string CuvantRandom(string path)
{
	string cuvant;
	vector<string> v;
	ifstream citit(path);
	if (citit.is_open())
	{
		while (std::getline(citit, cuvant))
		{
			v.push_back(cuvant);
		}
		int LinieRandom = rand() % v.size();
		cuvant = v.at(LinieRandom);
		citit.close();
	}
	return cuvant;
}

int Incercari(string cuvant, string corect)
{
	int NumarIncercari = 0;
	for (int i = 0; i < corect.length(); i++)
	{
		if (cuvant.find(corect[i]) == string::npos)
		{
			NumarIncercari++;
		}

	}
	return NumarIncercari;
}

int main()
{
srand(time(0));
string ghiciri;
string CuvDeAflat;
CuvDeAflat = CuvantRandom("cuvinte.txt");
int incercari = 0;
bool verifica = false;
while (incercari <= 6)
{
	system("cls");
	Print("Spanazuratoarea");
	Spanzuratul(incercari);
	if (incercari == 6)
		break;
	verifica = LitereCorecte(CuvDeAflat, ghiciri);
	if (verifica)
		break;
	char x;
	cout << ">";
	cout << "Incearca o litera!!  : ";
	cin >> x;
	if (ghiciri.find(x) == string::npos)
		ghiciri += x;
	incercari = Incercari(CuvDeAflat, ghiciri);
}
if (verifica)
{
	cout << "          AI CASTIGAT!!!";
}
else
{
	cout << "AI PIERDUT!!!  CUVANTUL ERA: " << CuvDeAflat;
}
return 0;
}