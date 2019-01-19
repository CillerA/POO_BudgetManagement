#include<iostream>
#include<time.h>
#include<fstream>
#include<list>
#include<vector>
#include<map>
using namespace std;

class User{

private:
	const int id;
	char* email;
	char* username;
	int noPasswords; 
	char** password;
	int yearOfBirth;
	char gender;
	bool employee;
static int noFemale;
static int noMen;
static int noUsers;

public:
	//CONSTRUCTOR IMPLICIT
	User():id(noUsers)
	{
		this->email = new char[strlen("alex_popescu21@yahoo.com")+1];
		strcpy(this->email, "alex_popescu21@yahoo.com");

		this->username = new char[strlen("alex21")+1];
		strcpy(this->username, "alex21");

		this->noPasswords = 1;
		this->password = new char*[noPasswords];
		this->password[0] = new char[strlen("password123")+1];
		strcpy(this->password[0], "password123");

		this->yearOfBirth = 1990;
		this->gender = 'M';

		this->employee = true;

		noMen++;
		noUsers++;
	}

	//CONSTRUCTOR EXPLICIT
	User(char* e, char* u, int noP, char** p, int y, char g, bool empl):id(noUsers)
	{
		this->email = new char[strlen(e)+1];
		strcpy(this->email, e);
		this->username = new char[strlen(u)+1];
		strcpy(this->username, u);
		this->noPasswords = noP;
		this->password = new char*[noPasswords];
		for(int i=0; i<noPasswords; i++)
		{
			this->password[i] = new char[strlen(p[i])+1];
			strcpy(this->password[i], p[i]);
		}
		this->yearOfBirth = y;
		this->gender = g;
		if(this->gender == 'F')
			noFemale++;
		else
			noMen++;
		this->employee = empl;
		noUsers++;
	}

	//CONSTRUCTOR CU CATIVA PARAM
	User(char* u, int noP, char** p) : id(noUsers)
	{
		this->email = new char[strlen("no email mentioned")+1];
		strcpy(this->email, "NO EMAIL MENTIONED");
		this->username = new char[strlen(u)+1];
		strcpy(this->username, u);
		this->noPasswords = noP;
		this->password = new char*[noPasswords];
		for(int i=0; i<noPasswords; i++)
		{
			this->password[i] = new char[strlen(p[i])+1];
			strcpy(this->password[i], p[i]);
		}
		this->employee = NULL;
		this->yearOfBirth = 0;
		this->gender = NULL;
		noUsers++;
	}

	//DESTRUCTOR
	~User()
	{
		if(email!=NULL)
		delete[]email;
		if(username!=NULL)
		delete[]username;
		for(int i=0; i<noPasswords; i++)
		{
			if(password[i]!=NULL)
			delete[]password[i];
		}
		if( password != NULL )
		delete[]password;
		if(this->gender == 'F')
			noFemale--;
		else
			noMen--;
		noUsers --; 
	}

	//GETTERI si SETTERI
	char* getEmail()
	{
		return email;
	}
	void setEmail(char* newEmail)
	{
		if(strlen(newEmail) > 2)
		{
			if(email != NULL)
				delete[]email;
			email = new char[strlen(newEmail)+1];
			strcpy(email, newEmail);
		}
		else
			throw "Ati introdus o adresa de mail gresita";
	}
	char* getUsername()
	{
		return username;
	}
	void setUsername(char* newUsername)
	{
		if(strlen(newUsername) > 2)
		{
			if(username != NULL)
				delete[]username;
			username = new char[strlen(newUsername)+1];
			strcpy(username, newUsername);
		}
		else
			throw "Ati introdus un username gresit";
	}
	int getNoPasswords()
	{
		return noPasswords;
	}
	void setNoPasswords(int newNr)
	{
		if(newNr >=1 )
			this->noPasswords = newNr;
		else
			throw "Numarul introdus nu este corect";
	}
	char** getPassword()
	{
		return password;
	}
	void setPassword(int nr, char** p)
	{ 
		if(nr>=0)
		{
		for(int i=0; i<noPasswords; i++)
			delete[]password[i];
		delete[]password;
		this->noPasswords = nr;
		this->password = new char*[noPasswords];
		for(int i=0; i<noPasswords; i++)
		{
		this->password[i] = new char[strlen(p[i])+1];
		strcpy(this->password[i], p[i]);
		}
		}	
		else
			throw "Introduceti un numar pozitiv";
	}
	int getYearOfBirth()
	{
		return yearOfBirth;
	}
	void setYearOfBirth(int newYearOfBirth)
	{
		if((newYearOfBirth > 1900) && (newYearOfBirth<2017)) //vreau sa pun conditie sa fie din 4 cifre
			yearOfBirth = newYearOfBirth;
		else
			throw "Introduceti anul nasterii in format YYYY";
	}
	char getGender()
	{
		return gender;
	}
	void setGender(char newGender)
	{
		if(newGender == 'F' || newGender == 'M')
			gender = newGender;
		else
			throw "Variantele posibile sunt F sau M";
			
	}
	bool getEmployee()
	{
		return employee;
	}
	void setEmployee(bool newValue)
	{
		if((newValue == true) || (newValue == false))
			employee = newValue;
		else
			throw "Variantele posibile sunt true si false";
	}
	int getId()
	{
		return id;
	}
	static int getNoUsers()
	{
		return noUsers;
	}
	static int getNoFemale()
	{
		return noFemale;
	}
	static int getNoMen()
	{
		return noMen;
	}

	//METODA AFISARE
	void afisare()
	{
		cout<<"Utilizatorul "<<this->username<<" este nascut in anul "<<this->yearOfBirth<<", are sexul "<<this->gender<<", este angajat "<<this->employee<<" si s-a inregistrat pe site cu adresa de mail: "
			<<this->email<<" avand id-ul "<<this->id<<endl;
		cout<<"Utilizatorul cu ID-ul "<<this->id<<" a avut "<<this->noPasswords<<" parole. Istoricul parolelor este: "<<endl;
		for(int i=0; i<noPasswords; i++)
			cout<<password[i]<<endl;

	}

	//METODA AFISARE2 - varsta
	void afisareVarsta()
	{
		int variabila = 2017;
		int varsta = 2017 - this->yearOfBirth;
		if(this->yearOfBirth!=0)
			cout<<"In anul 2017 utilizatorul "<<this->username<<" cu id-ul "<<this->id<<" implineste varsta de "<< varsta<<endl;
		else
			cout<<"Varsta utilizatorului "<<this->username<<" cu id-ul "<<this->id<<" nu poate fi calculata, deoarece nu a specificat anul nasterii "<<endl;
	}

	//CONSTRUCTOR COPIERE
	User(User& u) : id(noUsers)
	{
		this->email = new char[strlen(u.email)+1];
		strcpy(this->email, u.email);
		this->username = new char[strlen(u.username)+1];
		strcpy(this->username, u.username);
		this->noPasswords = u.noPasswords;
		this->password = new char*[noPasswords];
		for(int i=0; i<noPasswords; i++)
		{
			this->password[i] = new char[strlen(u.password[i])+1];
			strcpy(this->password[i], u.password[i]);
		}
		this->yearOfBirth = u.yearOfBirth;
		this->gender = u.gender;
		if(this->gender == 'F')
			noFemale++;
		else
			noMen++;
		this->employee = u.employee;
		noUsers++;
	
	}

	//SUPRAINCARCARE OPERATOR =  
	User operator=(const User &u)
	{
		if(this->email!=NULL)
			delete []this->email;
		this->email = new char[strlen(u.email)+1];
		strcpy(this->email, u.email);

		if(this->username!=NULL)
			delete []this->username;
		this->username = new char[strlen(u.username)+1];
		strcpy(this->username, u.username);

		for(int i=0; i<noPasswords; i++)
			if(password[i] != nullptr)
			delete password[i];
		delete [] password;
		this->noPasswords = u.noPasswords;
		this->password = new char*[noPasswords];
		for(int i=0; i<this->noPasswords; i++)
		{
			this->password[i] = new char[strlen(u.password[i])+1];
			strcpy(this->password[i], u.password[i]);
		}

		this->yearOfBirth = u.yearOfBirth;

		if(this->gender =='F')
			noFemale--;
		else
			noMen --;
		this->gender = u.gender;
		if(this->gender =='F')
			noFemale++;
		else
			noMen ++;

		this->employee = u.employee;
		return *this;
	
	}
	
	//SUPRAINCARCARE <<
	friend ostream& operator<<(ostream& iesire, User& u)
	{
		iesire<<"Utilizatorul "<<u.username<<" este nascut in anul "<<u.yearOfBirth<<", are sexul "<<u.gender<<", este angajat "<<u.employee<<" si s-a inregistrat pe site cu adresa de mail: "
			<<u.email<<" avand id-ul "<<u.id<<endl;
		iesire<<"Utilizatorul cu ID-ul "<<u.id<<" a avut "<<u.noPasswords<<" parole. Istoricul parolelor este: "<<endl;
		for(int i=0; i<u.noPasswords; i++)
			iesire<<u.password[i]<<endl;
		iesire<<endl;

		return iesire;
	}

	friend ofstream& operator<< (ofstream& iesire, User& u)
	{
		iesire<<u.email<<endl;
		iesire<<u.username<<endl;
		iesire<<u.noPasswords<<endl;
		for(int i=0; i<u.noPasswords; i++)
			iesire<<u.password[i]<<endl;
		iesire<<u.yearOfBirth<<endl;
		iesire<<u.gender<<endl;
		iesire<<u.employee<<endl;
		iesire<<endl;

		return iesire;
	}

	//SUPRAINCARCARE >>
	friend istream&operator >>(istream& intrare, User& u);

	friend ifstream& operator >> (ifstream& intrare, User& u) {
		char buffer[100];
	cout<<"Introduceti adresa de mail: ";
	intrare>>buffer;
	u.setEmail(buffer);

	cout<<"Introduceti username: ";
	intrare>>buffer;
	u.setUsername(buffer);
	

	cout<<"Introduceti parola. Exista deja una standard, pe care acum o puteti modifica : ";
	intrare>>buffer;
	u = u+buffer;
	
	cout<<"Introduceti anul nasterii: ";
	intrare>>u.yearOfBirth;

	cout<<"Introduceti genul F/M: ";
	intrare>>u.gender;

	cout<<"Sunteti angajat/a? Introduceti true-DA sau false-NU: ";
	intrare>>buffer;
	if(strcmp(buffer, "true")==0) u.setEmployee(true);
	else u.setEmployee(false);
	
	cout<<"S-au inregistrat datele dvs. Veti primi un mail de confirmare pe adresa de mail. "<<endl;
	return intrare;
		
	}

	//SUPRAINCARCARE [] pentru vectorul de parole 
	char* operator[](int index)
	{
		if((index>=0)&&(index<this->noPasswords))
			return this->password[index];
		else
			return NULL;
	}

	//SUPRAINCARCARE +
	User operator+ (char* p)
	{
		User temp = *this;
		char** aux = new char*[temp.noPasswords];

		for(int i=0; i<temp.noPasswords; i++)
		{
			aux[i] = new char[strlen(temp.password[i])+1];
			strcpy(aux[i], temp.password[i]);
		}
		if(temp.password!=nullptr) {
		for(int i=0; i<temp.noPasswords; i++)
		{
			if(temp.password[i]!=nullptr) 
			delete[]temp.password[i];
		}
		delete[]temp.password;
		}


		temp.noPasswords +=1;
		temp.password = new char*[temp.noPasswords];

		for(int i=0; i<temp.noPasswords-1; i++)
		{
			temp.password[i] = new char[strlen(aux[i])+1];
			strcpy(temp.password[i], aux[i]);
		}
		temp.password[temp.noPasswords-1]=new char[strlen(p)+1];
		strcpy(temp.password[temp.noPasswords-1], p);

		for(int i=0; i<temp.noPasswords-1; i++)
			delete[]aux[i];
		if(aux!=nullptr) delete[]aux;

		return temp;
	}

	//SUPRAINCARCARE ++
	//prefixata
	User operator++()
	{
		this->yearOfBirth+=1;
		return *this;
	}
	
	//postfixata
	 User operator++( int)
	{
		
		User temp = *this;
		this->yearOfBirth += 1;
		return temp;
		
	}
	
	////SUPRAINCARCARE CAST
	// explicit operator int() {
	//	 return this->yearOfBirth;
	//}
	 
	//SUPRAINCARCARE (<.>,=<,>=)
	bool operator<= (User u)
	{
		if(this->yearOfBirth <= u.yearOfBirth)
			return true;
		else
			return false;
	}

	//SUPRAINCARCARE OPERATOR ==
	bool operator ==(User u)
	{
		if (this->yearOfBirth == u.yearOfBirth) 
			return true;
		else
			return false;
	}

	//SUPRAINCARCARE !
	User operator!() {
		User u = *this;
		if (u.yearOfBirth > 2017)
			u.yearOfBirth = 0;
		else
			u.yearOfBirth = 2000;

		return u;
	}

	//Supraincarcare ()
	User operator()(int a) {
		User u = *this;
		u.yearOfBirth += a;
		return u;
}

	
};
int User::noUsers = 0;
int User::noFemale = 0;
int User::noMen = 0;

class Admin:public User{
private:
	int nrCreatedUsers;

public:
	//constructor implicit
	Admin(): User()
	{
		this->nrCreatedUsers = 0;
	}

	//constructor explicit
	Admin(char* e, char* u, int noP, char** p, int y, char g, bool empl, int noC):User(e, u, noP, p, y, g,empl)
	{
		this->nrCreatedUsers = noC;
	}

	//destructor
	~Admin()
	{
	
	}

	//constructor de copiere
	Admin(Admin& a):User(a)
	{
		this->nrCreatedUsers = a.nrCreatedUsers;
	}

	//supraincarcare operator = 
	Admin operator=(const Admin& a)
	{
		User::operator=(a);
		this->nrCreatedUsers = a.nrCreatedUsers;

		return* this;
	}

	//supraincarcare operator <<
	friend ostream& operator<<(ostream& iesire, Admin& a)
	{
		iesire<<(User&)a;
		iesire<<"Utilizatori creati de acest admin: "<<a.nrCreatedUsers;
		iesire<<endl;
		return iesire;
	}

	//supraincarcare operator >>
	friend istream& operator >>(istream& intrare, Admin& a)
	{
		intrare>>(User&)a;
		char buffer[100];
		cout<<"Utilizatori creati: ";
		intrare>>a.nrCreatedUsers;
		return intrare;
	}

	//supraincarcare operator ==
	 bool operator==(Admin a)
	{
		if(this->nrCreatedUsers == a.nrCreatedUsers)
			return true;
		else
			return false;
	}

	//getteri si setteri 
	 int getNrCreatedUsers()
	 {
		 return nrCreatedUsers;
	 }

	 void setNrCreatedUsers(int no)
	 {
		if(no > 0)
			this->nrCreatedUsers = no;
		else
			throw "Introduceti un numar pozitiv";

	 }
};

void generareRaport(User users, char* numeRaport) {
	ofstream raport;
	raport.open(numeRaport, ios::out | ios::trunc);
	if (raport.is_open()) {
		raport << "\t\t Raport useri"<<endl;
		raport<<"Email: "<<users.getEmail()<<endl;
		raport<<"Username: "<<users.getUsername()<<endl;
		raport<<"Gender: "<<users.getGender()<<endl;
		raport<<"Emplyoee: "<<users.getEmployee()<<endl;
	}
	raport.close();
}

//SUPRAINCARCARE OPERATOR >>
istream& operator >> (istream& intrare, User& u)
{
	char buffer[20];
	cout<<"Introduceti adresa de mail: ";
	intrare>>buffer;
	u.setEmail(buffer);

	cout<<"Introduceti username: ";
	intrare>>buffer;
	u.setUsername(buffer);
	

	cout<<"Introduceti parola. Exista deja una standard, pe care acum o puteti modifica : ";
	intrare>>buffer;
	u = u+buffer;
	
	cout<<"Introduceti anul nasterii: ";
	intrare>>u.yearOfBirth;

	cout<<"Introduceti genul F/M: ";
	intrare>>u.gender;

	cout<<"Sunteti angajat/a? Introduceti true-DA sau false-NU: ";
	intrare>>buffer;
	try{
		if(strcmp(buffer, "true")==0) 
				u.employee=true;
		else 
				u.employee=false;
	}
	catch(exception ex)
	{
		ex.what();
	}
	
	cout<<"S-au inregistrat datele dvs. Veti primi un mail de confirmare pe adresa de mail. "<<endl;

	return intrare;

}

enum CATEGORY_NAME{FOOD, UTILITIES, BANK, ENTERTAINMENT, OTHER};
	
class Costs{
private: 
	const int id;
	char name[50];
	float amountOfMoney;
	char* unit;
	char* date;
	CATEGORY_NAME category;
	static int noCosts;

public:
	//CONSTRUCTOR IMPLICIT
	Costs():id(noCosts)
	{
		strcpy(this->name, "default cost");
		this->amountOfMoney = 0.0f;
		this->unit = new char[strlen("default unit of measurement")+1];
		strcpy(this->unit, "default unit of measurement");
		this->date = new char[strlen("default date")+1];
		strcpy(this->date, "default date");
		this->category = BANK;
		noCosts++;
	}

	//CONSTRUCTOR EXPLICIT
	Costs(char n[50], float a, char* u, char* d, CATEGORY_NAME category):id(noCosts)
	{
		strcpy(this->name, n);
		this->amountOfMoney = a;
		this->unit = new char[strlen(u)+1];
		strcpy(this->unit, u);
		this->date = new char[strlen(d)+1];
		strcpy(this->date, d);
		this->category = category;
		noCosts++;

	}

	//CONSTRUCTOR CU CATIVA PARAM
	Costs(float a, CATEGORY_NAME category) : id(noCosts)
	{
		strcpy(this->name, "NO NAME MENTIONED");
		this->amountOfMoney = a;
		this->unit = new char[strlen("NO UNIT MENTIONED ")+1];
		strcpy(this->unit, "NO UNIT MENTIONED");
		this->date = new char[strlen("NO DATE MENTIONED ")+1];
		strcpy(this->date, "NO DATE MENTIONED");
		this->category = category;
		noCosts++;

	
	}

	//AFISARE
	void afisare()
	{
		cout<<"Cheltuiala cu id-ul "<<this->id<<" si denumirea "<<this->name<<" in suma de "
			<<this->amountOfMoney<<" "<<this->unit<<" face parte din categoria "<<this->category<<" si a fost realizata in data de "<<this->date<<endl;
	}

	void afisare2()
	{
		time_t t = time(0);
		struct tm* now = localtime(&t);
		cout<<"Pe data de "<<now->tm_mday<<"-"<<now->tm_mon+1<<"-"<<now->tm_year+1900<<" au fost inregistrate cheltuieli in categoria "<<this->category<<endl;
	}

	//GETTERI SI SETTERI
	int getId()
	{
		return id;
	}

	char* getName()
	{
		return name;
	}

	void setName(char* newName)
	{
		if(strlen(newName)>2)
		{
		strcpy(this->name, newName);
		}
		else
			throw "Introduceti o denumire mai mare de 2 caractere";
	}

	float getAmountOfMoney()
	{
		return amountOfMoney;
	}

	void setAmountOfMoney(float newValue)
	{
		if(newValue > 0 )
			this->amountOfMoney = newValue;
		else
			throw "Introduceti un numar pozitiv";
	}

	char* getUnit()
	{
		return unit;
	}

	void setUnit(char* newUnit)
	{
		if(strlen(newUnit)>1)
		{
			if(unit !=NULL)
				delete[] unit;
			unit = new char[strlen(newUnit)+1];
			strcpy(unit, newUnit);
		}
		else
			throw "Se accepta doar unitatile de masura formate din mai mult de un caracter";
	}

	char* getDate()
	{
		return date;
	}

	void setDate(char* newDate)
	{
		if(strlen(newDate) > 8)
		{
			if(date!=NULL)
				delete[]date;
			date = new char[strlen(newDate)+1];
			strcpy(date, newDate);
		}
		else
			throw "Introduceti o data de forma DD/MM/YYYY";
	}

	static int getNoCosts()
	{
		return noCosts;
	}

	CATEGORY_NAME getCategory()
	{
		return category;
	}
	
	void setCategoryName(CATEGORY_NAME newCategory)
	{
		//nu stiu ce conditie sa pun la un atribut de tip enum
		this->category = newCategory;
		
	}
	
	//CONSTRUCTOR DE COPIERE
	Costs(Costs &c):id(noCosts)
	{
		strcpy(this->name, c.name);
		this->amountOfMoney = c.amountOfMoney;
		this->unit = new char[strlen(c.unit)+1];
		strcpy(this->unit, c.unit);
		this->date = new char[strlen(c.date)+1];
		strcpy(this->date, c.date);
		this->category = c.category;
		noCosts++;
	}

	//DESTRUCTOR
	~Costs()
	{
		delete[]unit;
		delete[]date;
		noCosts--;
	}

	//SUPRAINCARCARE = 
	Costs operator=(const Costs &c)
	{
		strcpy(this->name, c.name);
		this->amountOfMoney = c.amountOfMoney;
		if(this->unit !=NULL)
			delete[]this->unit;
		this->unit = new char[strlen(c.unit)+1];
		strcpy(this->unit, c.unit);

		if(this->date!=NULL)
			delete[]this->date;
		this->date = new char[strlen(c.date)+1];
		strcpy(this->date, c.date);

		this->category = c.category;

		return *this;
	}

	//SUPRAINCARCARE OPERATOR <<
	friend ostream& operator<<(ostream& iesire, Costs c)
	{
		iesire<<"Cheltuiala cu id-ul "<<c.id<<" si denumirea "<<c.name<<" in suma de "
			<<c.amountOfMoney<<" "<<c.unit<<" face parte din categoria "<<c.category<<" si a fost realizata in data de "<<c.date<<endl;
		return iesire;
	}

	friend ofstream& operator<<(ofstream& iesire, Costs c)
	{
		iesire<<c.name<<endl;
		iesire<<c.amountOfMoney<<endl;
		iesire<<c.unit<<endl;
		iesire<<c.date<<endl;
		iesire<<c.category<<endl;
		iesire<<endl;
		return iesire;
	}

	//SUPRAINCARCARE OPERATOR >>
	friend istream& operator>>(istream& intrare, Costs &c)
	{
		char buffer[50];
		cout<<"Introduceti denumirea cheltuielii: "<<endl;
		intrare>>buffer;
		strcpy(c.name, buffer);
		cout<<"Introduceti suma cheltuita: "<<endl;
		intrare>>c.amountOfMoney;
		char buffer2[5];
		cout<<"Introduceti unitatea de masura: "<<endl;
		intrare>>buffer2;
		delete[]c.unit;
		c.unit = new char[strlen(buffer2)+1];
		strcpy(c.unit, buffer2);

		char buffer3[20];
		cout<<"Introduceti data: "<<endl;
		intrare>>buffer3;
		delete[]c.date;
		c.date = new char[strlen(buffer3)+1];
		strcpy(c.date, buffer3);

		cout<<"Introduceti categoria: Food - 0 |Utilities - 1|Bank - 2|Entertainment - 3 |Other - 4|:"<<endl;
		int in;
		intrare>>in;
		switch(in)
		{
		case 0:
			c.category = FOOD;
			break;
		case 1: 
			c.category = UTILITIES;
			break;
		case 2:
			c.category = BANK;
			break;
		case 3: 
			c.category = ENTERTAINMENT;
			break;
		default : 
			c.category = OTHER;
			break;

		}
		return intrare;
	}


	friend ifstream& operator>>(ifstream& intrare, Costs &c)
	{
		char buffer[50];
		intrare>>buffer;
		strcpy(c.name, buffer);
		intrare>>c.amountOfMoney;
		char buffer2[5];
		intrare>>buffer2;
		delete[]c.unit;
		c.unit = new char[strlen(buffer2)+1];
		strcpy(c.unit, buffer2);
		char buffer3[20];
		intrare>>buffer3;
		delete[]c.date;
		c.date = new char[strlen(buffer3)+1];
		strcpy(c.date, buffer3);
		int in;
		intrare>>in;
		switch(in)
		{
		case 0:
			c.category = FOOD;
			break;
		case 1: 
			c.category = UTILITIES;
			break;
		case 2:
			c.category = BANK;
			break;
		case 3: 
			c.category = ENTERTAINMENT;
			break;
		default : 
			c.category = OTHER;
			break;
		}
		return intrare;
	}
	
	//SUPRAINCARCARE ++
	Costs operator++()
	{
		this->amountOfMoney = this->amountOfMoney+1;
		return* this;
	}

	//SUPRAINCARCARE ++ 
	Costs operator++(int)
	{
		Costs aux = *this;
		this->amountOfMoney += 1;
		return aux;
	}

	//SUPRAINCARCARE <
	bool operator>=(Costs c) 
	{
		if (this->amountOfMoney >= c.amountOfMoney) 
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	//OPERATOR INDEX
	char& operator[](int index)
	{
		if(index>=0 && index<strlen(this->name))
			return this->name[index];
		else
			throw "Index out of bounds";
	}

	//OPERATOR == 
	//2 cheltuieli sunt egale daca au aceeasi suma si aceeasi unitate de masura
	bool operator==(Costs c)
	{
		if((this->amountOfMoney == c.amountOfMoney) && (strcmp(this->unit, c.unit) == 0))
			return true;
		else
			return false;
	}

	////OPERATOR CAST
	//explicit operator int() {
	//	return strlen(this->date);
	//}

	//OPERATOR ! //modifica valorile cuprinse intre 0 si 100
	Costs operator!()
	{
		Costs c = *this;
		if(c.amountOfMoney > 0 && c.amountOfMoney < 100)
			c.amountOfMoney = 500;
		else
			c.amountOfMoney = 0;
		return c;

	}

	//OPERATOR FUNCTIE()
	Costs operator()(float value)
	{
		Costs c = *this;
		if(value > 0)
			c.amountOfMoney = c.amountOfMoney+ value;
		return c;
	}

	//OPERATOR +  adauga valoarea unei alte cheltuieli
	Costs operator+(Costs c)
	{
		this->amountOfMoney += c.amountOfMoney;
		return *this;
	}


};
int Costs::noCosts = 0; 

class Categories{
private:
	char* name;
	int noSum;
	float debtsPerCategory[5];
	float receivablesPerCategory[5];
	const char* unit;
	const int no2;
	bool* paid;
public:
	//CONSTRUCTOR IMPLICIT
	Categories():unit("lei"),no2(2)
	{
		this->name = new char[strlen("Default category")+1];
		strcpy(this->name, "Default category");
		this->noSum = 1;
		this->debtsPerCategory[0] = 0;
		this->receivablesPerCategory[0] = 0;
		this->paid = new bool[no2];
		for(int i=0; i<no2; i++)
			this->paid[i] = false;
	}

	//CONSTRUCTOR EXPLICIT
	Categories(char* n, int noS, float d[5], float r[5], bool* p):unit("lei"), no2(2)
	{
		this->name = new char[strlen(n)+1];
		strcpy(this->name, n);
		if (this->noSum <= 5)
		{
			this->noSum = noS;
			for (int i = 0; i < noSum; i++)
			{
				this->debtsPerCategory[i] = d[i];
				this->receivablesPerCategory[i] = r[i];
			}
		}
		else
		{
			throw "Numarul de categorii introdus este prea mare.";
		}
		this->paid = new bool[no2];
		for(int i=0; i<no2; i++)
			this->paid[i] = p[i];
	}

	//CONSTRUCTOR CU CATIVA PARAM
	Categories(char* n, bool* p):unit("lei"),no2(2)
	{
		this->name = new char[strlen(n)+1];
		strcpy(this->name, n);
		this->noSum = 1;
		for(int i=0; i<noSum; i++)
		{
			this->debtsPerCategory[i]= 0;
			this->receivablesPerCategory[i]=0;
		}
		this->paid = new bool[no2];
		for(int i=0; i<no2; i++)
			this->paid[i] = p[i];
	}

	//AFISARE 1
	void afisare()
	{
		cout<<"Categoria "<<this->name<<" prezinta urmatoarele sume "<<endl;
		cout<<"1.Datorii: "<<" - ";
		for(int i=0; i<noSum; i++)
		{
			cout<<this->debtsPerCategory[i]<<"lei"<<" ";
		}
		cout<<endl<<"2.Creante : "<<" - ";
		for(int i=0; i<noSum; i++)
		{
		cout<<this->receivablesPerCategory[i]<<"lei"<<" ";
		}

		time_t t = time(0);
		struct tm* now = localtime(&t);
		cout<<endl<<"Pe data de "<<now->tm_mday<<"-"<<now->tm_mon+1<<"-"<<now->tm_year+1900<<" au fost/n-au fost achitate datoriile |||| s-au incasat sau nu creantele din categoria "<<this->name<<" ";
		for(int i=0; i<no2; i++)
		{
			cout<<this->paid[i]<<" | ";
		}
		cout<<endl;
	}

	//AFISARE 2
	void afisare2()
	{
		cout<<"Sumele din categoria "<<this->name<<" au fost sau nu au fost achitate/primite in urmatoarea ordine: 1. Datorii 2. Creante"<<" ";
		for(int i=0; i<no2; i++)
			cout<<paid[i]<<" |";
		cout<<endl;
	}

	//DESTRUCTOR
	~Categories()
	{
		delete[]name;
		delete[]paid;
	}

	//GETTERI SI SETTERI
	char* getName()
	{
		return name;
	}
	void setName(char* newName)
	{
		if(strlen(newName) >= 4)
		{
			if(name != NULL)
				delete[]name;
			name = new char[strlen(newName)+1];
			strcpy(name, newName);
		}
		else
			throw "Ati introdus o categorie inexistenta";
	}
	int getNoSum()
	{
		return noSum;
	}
	void setNoSum(int newNoSum)
	{
		if (newNoSum > 0)
			noSum = newNoSum;
		else
			throw "Numarul introdus este gresit";
	}
	float* getDebtsPerCategory()
	{
		return debtsPerCategory;
	}
	void setDebtsPerCategory(int noDebts, float debts[5])
	{
		if(noSum <= 5)
		{
			noSum = noDebts;
		for(int i=0; i< noSum; i++)
			debtsPerCategory[i] = debts[i];
		}
		else
			throw "Introduceti o valoare mai mica sau egala cu 5";
	}
	float* getReceivablesPerCategory()
	{
		return receivablesPerCategory;
	}
	void setReceivablesPerCategory(int noReceivables, float receivables[5])
	{
		if(noReceivables <= 5)
		{
			noSum = noReceivables;
		for(int i=0; i<noSum; i++)
				receivablesPerCategory[i] = receivables[i];
		}
		else
			throw "Introduceti o valoare mai mica sau egala cu 5";
	}
	const char* getUnit()
	{
		return unit;
	}
	const int getNo2()
	{
		return no2;
	}
	bool* getPaid()
	{
		return paid;
	}
	void setPaid(int noPaid, bool* b)
	{
		if(noPaid == 2 )
		{
			delete[]paid;
			paid = new bool[noPaid];
			for(int i=0; i<noPaid; i++)
				paid[i] = b[i];
		}
		else
			throw "Numarul introdus trebuie sa fie 2, deoarece aplicatia calculeaza doar datoriile si creantele, deci 2";

	}

	//CONSTRUCTOR COPIERE
	Categories(Categories &c):unit(c.unit), no2(c.no2)
	{
		this->name = new char[strlen(c.name)+1];
		strcpy(this->name, c.name);
		this->noSum = c.noSum;
		for(int i=0; i<c.noSum; i++)
		{
			this->debtsPerCategory[i] = c.debtsPerCategory[i];
			this->receivablesPerCategory[i] = c.receivablesPerCategory[i];
		}
		this->paid = new bool[c.no2];
		for(int i=0; i<c.no2; i++)
		{
			this->paid[i] = c.paid[i];
		}
	}

	//SUPRAINCARCARE OPERATOR = 
	Categories operator=(const Categories &c)
	{
		if(this->name != NULL)
			delete[]this->name;
		this->name = new char[strlen(c.name)+1];
		strcpy(this->name, c.name);
		this->noSum = c.noSum;
		for(int i=0; i<c.noSum; i++)
		{
			this->debtsPerCategory[i] = c.debtsPerCategory[i];
			this->receivablesPerCategory[i] = c.receivablesPerCategory[i];
		}
		this->paid = new bool[c.no2];
		for(int i=0; i<c.no2; i++)
			this->paid[i] = c.paid[i];

		return* this;
	
	}

	//SUPRAINCARCARE OPERATOR<<
	friend ostream& operator<<(ostream&iesire, Categories c)
{
	iesire<<"Categoria "<<c.name<<" prezinta urmatoarele sume "<<endl;
		iesire<<"1.Datorii: "<<" - ";
		for(int i=0; i<c.noSum; i++)
		{
			iesire<<c.debtsPerCategory[i]<<"lei"<<",";
		}
		iesire<<endl<<"2.Creante : "<<" - ";
		for(int i=0; i<c.noSum; i++)
		{
		iesire<<c.receivablesPerCategory[i]<<"lei"<<",";
		}

		time_t t = time(0);
		struct tm* now = localtime(&t);
		iesire<<endl<<"Pe data de "<<now->tm_mday<<"-"<<now->tm_mon+1<<"-"<<now->tm_year+1900<<" au fost/n-au fost achitate datoriile |||| s-au incasat sau nu creantele din categoria "<<c.name<<" ";
		for(int i=0; i<c.no2; i++)
		{
			iesire<<c.paid[i]<<" | ";
		}
		return iesire;
}

	friend ofstream& operator<<(ofstream&iesire, Categories c)
{
	iesire<<c.name<<endl;
	iesire<<c.noSum<<endl;
	for(int i=0; i<c.noSum;i++)
		iesire<<c.debtsPerCategory[i]<<" ";
	iesire<<endl;
	for(int i=0; i<c.noSum;i++)
		iesire<<endl<<c.receivablesPerCategory[i]<<" ";
	for(int i=0; i<c.no2;i++)
		iesire<<endl<<c.paid[i]<<" ";

		return iesire;

}

	//SUPRAINCARCARE OPERATOR >>
	friend istream& operator>>(istream&intrare, Categories& c)
{
		
		cout<<endl<<"Introduceti numele categoriei: ";
		char buffer[20];
		intrare>>buffer;
		if(c.name)
			delete[]c.name;
	c.name = new char[strlen(buffer)+1];
	strcpy(c.name, buffer);

	cout<<"Introduceti numarul sumelor: ";
	intrare>>c.noSum;

	for(int i=0; i<c.noSum; i++)
	{
		cout<<"Introduceti datoriile: ";
		intrare>>c.debtsPerCategory[i];
	}

	
	for(int i=0; i<c.noSum; i++)
	{
		cout<<"Introduceti creantele: ";
		intrare>>c.receivablesPerCategory[i];
	}

	c.paid = new bool[c.no2];
	for(int i=0; i<c.no2; i++)
	{
		cout<<"Specificati daca datoriile au fost platite prin 1 sau 0 ||| creantele au fost primite prin 1 sau 0:  ";
		intrare>>c.paid[i];
	}

	return intrare;
}


	friend ifstream& operator>>(ifstream&intrare, Categories& c)
{
		
		char buffer[20];
		intrare>>buffer;
		if(c.name)
			delete[]c.name;
	c.name = new char[strlen(buffer)+1];
	strcpy(c.name, buffer);

	intrare>>c.noSum;

	for(int i=0; i<c.noSum; i++)
	{
		intrare>>c.debtsPerCategory[i];
	}

	
	for(int i=0; i<c.noSum; i++)
	{
		intrare>>c.receivablesPerCategory[i];
	}

	c.paid = new bool[c.no2];
	for(int i=0; i<c.no2; i++)
	{
		intrare>>c.paid[i];
	}

	return intrare;
}


	//OPERATOR INDEX
	float& operator[](int index)
	{
		if(index>=0 && index < this->noSum)
		{
			cout<<endl<<"Suma datoriei de pe pozitia "<<index<<" este";
			return debtsPerCategory[index];
		}
		else
			throw "RECEIVABLES: Index out of bounds";
	}

	//OPERATOR ==
	bool operator==(Categories c)
	{
		return strcmp(this->name, c.name) == 0 ? true:false;
	}

	//OPERATOR >=
	bool operator >= (Categories c)
	{
		if ((strlen(this->name)) >= (strlen(c.name)))
			return true;
		else
			return false;
	}

	//OPERATOR --
	Categories operator--() {
		this->noSum = this->noSum - 1;
		return *this;
	}

	Categories operator--(int) {
		Categories temp = *this;
		this->noSum = this->noSum-1;
		return temp;
	}

	////OPERATOR CAST
	// explicit operator float()
	//{
	//	float suma = 0;
	//	for(int i=0; i<this->noSum; i++)
	//		suma = suma + debtsPerCategory[i];
	//	return suma;
	//}

	  //OPERATOR ! 
	  Categories operator!()
	  {
		Categories c = *this;
		for(int i=0; i<no2; i++)
			c.paid[i] = !c.paid[i];
		return c;
	  }

	  //OPERATOR FUNCTIE()
	  Categories operator() (int newNoSum){
		Categories c = *this;
		c.noSum = c.noSum + newNoSum;
		return c;
	  }

	 //OPERATOR + 
	  Categories operator+(int newValue)
	  {
		if(noSum < 5)
		{
			debtsPerCategory[noSum] = newValue;
			receivablesPerCategory[noSum] = newValue;
			noSum++;
		}
		return *this;
	  }

		
};

class Income
{
private:
	const int id;
	static int noIncomes;
	char name[30];
	const int noSources;
	float* amount;
	char* unit;
	char* date;

public:
	//CONSTRUCTOR IMPLICIT
	Income():id(noIncomes), noSources(3)
	{
		strcpy(this->name, "DEFAULT INCOME");
		this->amount = new float[noSources];
		for(int i=0; i<noSources;i++)
			this->amount[i] = 0;
		this->unit = new char[strlen("DEFAULT UNIT")+1];
		strcpy(this->unit, "DEFAULT UNIT");
		this->date = new char[strlen("DEFAULT DATE")+1];
		strcpy(this->date, "DEFAULT DATE");
		noIncomes++;
	}

	//CONSTRUCTOR EXPLICIT
	Income(char n[30], float* a, char* u, char* d):id(noIncomes), noSources(3)
	{
		strcpy(this->name, n);
		this->amount = new float[noSources];
		for(int i=0; i<this->noSources; i++)
			this->amount[i] = a[i];
		this->unit = new char[strlen(u)+1];
		strcpy(this->unit, u);
		this->date = new char[strlen(d)+1];
		strcpy(this->date, d);
		noIncomes++;
	}

	//CONSTRUCTOR CU CATIVA PARAM
	Income(char n[30], float* a):id(noIncomes), noSources(3)
	{
		strcpy(this->name, n);
		this->amount = new float[noSources];
		for(int i=0; i<this->noSources; i++)
			this->amount[i] = a[i];
		this->unit = new char[strlen("lei")+1];
		strcpy(this->unit, "lei");
		this->date = new char[strlen("DEFAULT DATE")+1];
		strcpy(this->date, "DEFAULT DATE");
		noIncomes++;
	}

	//AFISARE 1
	void afisare()
	{
		cout<<"Venitul "<<this->name<<" are id-ul "<<this->id<<" a fost inregistrat pe data de "<<this->date<<" si provine din "<<this->noSources<<" surse. Cantitatea de bani din fiecare sursa este prezentata mai jos:"<<endl;
		for(int i=0; i<this->noSources; i++)
			cout<<this->amount[i]<<" "<<this->unit<<" ";
	}

	//AFISARE 2
	void afisare2()
	{
		time_t t = time(0);
		struct tm* now = localtime(&t);
		cout<<endl<<"Pe data de "<<now->tm_mday<<"-"<<now->tm_mon+1<<"-"<<now->tm_year+1900<<" au fost inregistrate urmatoarele sume, reprezentand venituri din "<<this->noSources<<" surse diferite"<<endl;
		for(int i=0; i<this->noSources;i++)
			cout<<amount[i]<<" "<<this->unit<<" ";
	}

	//DESTRUCTOR
	~Income()
	{	
		delete[]amount;
		delete[]unit;
		delete[]date;
		noIncomes--;
	}

	//CONSTRUCTOR DE COPIERE
	Income(const Income& in):id(noIncomes), noSources(3)
	{
		strcpy(this->name, in.name);
		this->amount = new float [in.noSources];
		for(int i=0; i<in.noSources; i++)
		{
			this->amount[i] = in.amount[i];
		}
		this->unit = new char[strlen(in.unit)+1];
		strcpy(this->unit, in.unit);
		this->date = new char[strlen(in.date)+1];
		strcpy(this->date, in.date);
		
		noIncomes++;
	}

	//GETTERI SI SETTERI
	const int getId()
	{
		return id;
	}
	static int getNoIncomes()
	{
		return noIncomes;
	}
	char* getName()
	{
		return name;
	}
	void setName(char* newName)
	{
		if(strlen(newName)>3)
			strcpy(this->name, newName);
		else
			throw "Introduceti un cuvant mai lung";

	}
	const int getNoSources()
	{
		return noSources;
	}
	float* getAmount()
	{
		return amount;
	}
	void setAmount(int nr, float* a)
	{
		if(nr == 3)
		{
			if (amount!=NULL)
				delete []amount;
			this->amount = new float[nr];
			for(int i=0; i<nr; i++)
				this->amount[i] = a[i];
		}
		else
			throw "Numarul introdus trebuie sa fie 3, deoarece aplicatia furnizeaza doar 3 surse de venituri";
	}
	char* getUnit()
	{
		return unit;
	}
	void setUnit(char* newUnit)
	{
		if(strlen(newUnit)>2)
		{
			if(unit!=NULL)
				delete[]unit;
			this->unit = new char[strlen(newUnit)+1];
			strcpy(this->unit, newUnit);
		}
		else
			throw "Introduceti o unitate de masura formata din mai mult de 2 litere";
	}
	char* getDate()
	{
		return date;
	}
	void setDate(char* newDate)
	{
		if(strlen(newDate) > 8)
		{
			if(date!=NULL)
				delete[]date;
			date = new char[strlen(newDate)+1];
			strcpy(date, newDate);
		}
		else
			throw "Introduceti o data de forma DD/MM/YYYY";
		
	}

	//OPERATOR = 
	Income operator=(const Income& in)
	{
		strcpy(this->name, in.name);
		if(this->amount!=NULL)
			delete[]this->amount;
		this->amount = new float[in.noSources];
		for(int i=0; i<in.noSources; i++)
			this->amount[i] = in.amount[i];
		if (this->unit!=NULL)
			delete[]this->unit;
		this->unit = new char[strlen(in.unit)+1];
		strcpy(this->unit, in.unit);
		if(date!=NULL)
			delete[]date;
		this->date = new char[strlen(in.date)+1];
		strcpy(this->date, in.date);

		return *this;
	}

	//OPERATOR <<
	friend ostream& operator<<(ostream& iesire, Income& in)
	{
		iesire<<"Venitul "<<in.name<<" are id-ul "<<in.id<<" a fost inregistrat pe data de "<<in.date<<" si provine din "<<in.noSources<<" surse. Cantitatea de bani din fiecare sursa este prezentata mai jos:"<<endl;
		for(int i=0; i<in.noSources; i++)
			iesire<<in.amount[i]<<" "<<in.unit<<" ";
		return iesire;
	}

	friend ofstream& operator<<(ofstream& iesire, Income& in)
	{
		iesire<<in.name<<endl;
		for(int i=0; i<in.noSources; i++)
			iesire<<in.amount[i]<<" "<<endl;
		iesire<<endl<<in.unit<<endl;
		iesire<<in.date;
		iesire<<endl;
		return iesire;
	}


	//OPERATOR >>
	friend istream& operator>>(istream& intrare, Income& in)
	{
		char buffer[20];
		cout<<"Introduceti numele venitului ";
		intrare>>buffer;
		strcpy(in.name, buffer);

		
		if(in.amount!=NULL)
			delete[]in.amount;
		in.amount = new float[in.noSources];
		for(int i=0; i<in.noSources; i++)
		{
		cout<<"Introduceti cele 3 sume corespunzatoare celor 3 surse ";
		intrare>>in.amount[i];
		}

		cout<<"Introduceti unitatea de masura ";
		intrare>>buffer;
		if(in.unit!=NULL)
			delete[]in.unit;
		in.unit = new char[strlen(buffer)+1];
		strcpy(in.unit, buffer);

		cout<<"Introduceti data ";
		intrare>>buffer;
		if(in.date!=NULL)
			delete[]in.date;
		in.date = new char[strlen(buffer)+1];
		strcpy(in.date, buffer);

		cout<<"Datele introduse au fost salvate cu succes"<<endl;

		return intrare;
	}
	

	friend ifstream& operator>>(ifstream& intrare, Income& in)
	{
		char buffer[20];
		intrare>>buffer;
		strcpy(in.name, buffer);

		
		if(in.amount!=NULL)
			delete[]in.amount;
		in.amount = new float[in.noSources];
		for(int i=0; i<in.noSources; i++)
		{
		intrare>>in.amount[i];
		}

		intrare>>buffer;
		if(in.unit!=NULL)
			delete[]in.unit;
		in.unit = new char[strlen(buffer)+1];
		strcpy(in.unit, buffer);

		intrare>>buffer;
		if(in.date!=NULL)
			delete[]in.date;
		in.date = new char[strlen(buffer)+1];
		strcpy(in.date, buffer);

		cout<<"Datele introduse au fost salvate cu succes"<<endl;

		return intrare;
	}
	
	//OPERATOR INDEX
	float& operator[](int index) {
		if (index >= 0 && index < this->noSources) {
			return amount[index];
		}
		else
			throw new exception("Index out of bounds");
	}

	//OPERATOR ==
	bool operator==(Income in)
	{
		if(strcmp(this->name, in.name) == 0)
			return true;
		else
			return false;
	}

	//OPERATOR <
	bool operator< (Income in)
	{
		if((strlen(this->unit)) < (strlen(in.unit))) 
			return true;
		else
			return false;
	}

	//OPERATOR ++
	//postincrementare 
	Income operator--(int)
	{
		Income temp = *this;
		for (int i = 0; i < this->noSources; i++)
			this->amount[i] -=1;
		return temp;
	}

	//preincrementare
	Income operator--()
	{
		for (int i = 0; i < this->noSources; i++)
			this->amount[i] -=1;
		return *this;
	
	}

	//OPERATOR !
	bool operator!()
	{
		int sumOfIncomes = 0;
		for (int i = 0; i < this->noSources; i++)
			sumOfIncomes += this->amount[i];
		if (sumOfIncomes< 500)
			return false;
		else
			return true;
	}

	////OPERATOR CAST
	//explicit operator int() {
	//	return strlen(this->unit);
	//}

	//OPERATOR ()
	bool operator()()
	{
		int sumOfIncomes = 0;
		for (int i = 0; i < this->noSources; i++)
			sumOfIncomes += this->amount[i];
		if(sumOfIncomes >= 800)
			return true;
		else
			return false;
	}


	//OPERATOR + 
	Income operator+(float a)
	{
		Income copy = *this;
		for(int i=0; i<this->noSources; i++)
			copy.amount[i] = this->amount[i] + a;
		return copy;
	}

};

int Income::noIncomes = 0;

void generareRaport(Income inc, char* numeRaport) {
	ofstream raport;
	raport.open(numeRaport, ios::out | ios::trunc);
	if (raport.is_open()) {
		raport << "\t\t Raport venituri"<<endl;
		raport<<"Nume venit: "<<inc.getName()<<endl;
		raport<<"Numar surse: "<<inc.getNoSources()<<endl;
		for(int i=0; i<inc.getNoSources(); i++)
			raport<<"Venit "<<i+1<<inc.getAmount()[i]<<endl;
		raport<<"Unitate de masura "<<inc.getUnit();
	}
	raport.close();
}

class Debts{
private:
	const int id;
	char name[20];
	int noCategories;
	float amountPerCategory[5];
	char* deadline;
	char* unit;
	bool* paid;
	static int noDebts;

public:
	//CONSTRUCTOR IMPLICIT
	Debts():id(noDebts)
	{
		strcpy(this->name, "DEFAULT NAME");
		this->noCategories = 2;
		this->amountPerCategory[0] = 0;
		this->amountPerCategory[1] = 0;
		this->deadline = new char[strlen("DEFAULT DEADLINE")+1];
		strcpy(this->deadline, "DEFAULT DEADLINE");
		this->unit = new char[strlen("DEFAULT UNIT")+1];
		strcpy(this->unit, "DEFAULT UNIT");
		this->paid = new bool[this->noCategories];
		for(int i=0; i<this->noCategories; i++)
			this->paid[i] = false;
		noDebts++;
	}

	//CONSTRUCTOR EXPLICIT
	Debts(char n[20], int noC, float a[5], char* d, char* u, bool* p):id(noDebts)
	{
		strcpy(this->name, n);
		this->noCategories = noC;
		for(int i=0; i<this->noCategories; i++)
			amountPerCategory[i] = a[i];
		this->deadline = new char[strlen(d)+1];
		strcpy(this->deadline, d);
		this->unit = new char[strlen(u)+1];
		strcpy(this->unit, u);
		this->paid = new bool[this->noCategories];
		for(int i=0; i<this->noCategories; i++)
			paid[i] = p[i];
		noDebts++;
	
	}

	//CONSTRUCTOR CU CATIVA PARAM
	Debts(char n[20], int noC, bool* p):id(noDebts)
	{
		strcpy(this->name, n);
		this->noCategories = noC;
		for(int i=0; i<this->noCategories; i++)
			this->amountPerCategory[i] = 0;
		this->deadline = new char[strlen("DEFAULT DEADLINE")+1];
		strcpy(this->deadline, "DEFAULT DEADLINE");
		this->unit = new char[strlen("DEFAULT UNIT")+1];
		strcpy(this->unit, "DEFAULT UNIT");
		this->paid = new bool[this->noCategories];
		for(int i=0; i<this->noCategories; i++)
			this->paid[i] = p[i];
		noDebts++;
	}
	
	//DESTRUCTOR
	~Debts()
	{
		if(deadline!=NULL)
			delete[]deadline;
		if(unit!=NULL)
			delete[]unit;
		if(paid!=NULL)
			delete[]paid;
		noDebts--;
	}
	
	//AFISARE 1
	void afisare()
	{
		cout<<"Datoria "<<this->name<<" cu id-ul "<<this->id<<" are ca si termen de plata "<<this->deadline<<" si se inregistreaza in "<<this->noCategories<<" categorii cu urmatoarele sume ";
		for(int i=0; i<this->noCategories; i++)
		{
			cout<<amountPerCategory[i]<<" ";
		}
		cout<<this->unit<<endl;
		cout<<"Se marcheaza cu 1 datoria platita si cu 0 datoria neplatita: ";
		for(int i=0; i<this->noCategories; i++)
			cout<<paid[i]<<" ";
	}
	
	//AFISARE 2
	void afisare2()
	{
		float suma = 0;
		for(int i=0; i<this->noCategories; i++)
			suma = suma +amountPerCategory[i];
		time_t t = time(0);
		struct tm* now = localtime(&t);
		cout<<"Datoria "<<this->name<<" cu sumele: ";
		for(int i=0; i<this->noCategories; i++)
			cout<<amountPerCategory[i]<<" ";
		cout<<this->unit;
		cout<<" a fost inregistrata pe data de "<<now->tm_mday<<"-"<<now->tm_mon+1<<"-"<<now->tm_year+1900<<" cu un total de "<<suma<<" "<<this->unit;
		cout<<endl;
	}

	//GETTERI SI SETTERI
	const int getId()
	{
		return id;
	}
	char* getName()
	{
		return name;
	}
	void setName(char* newName)
	{
		if(strlen(newName)>3)
			strcpy(this->name, newName);
		else
			throw "Cuvantul adaugat este prea mic";

		}
	char* getUnit()
	{
		return unit;
	}
	void setUnit(char* newUnit)
	{
		if(strlen(newUnit)>2)
		{
			if(unit!=NULL)
				delete[]unit;
			this->unit = new char[strlen(newUnit)+1];
			strcpy(this->unit, newUnit);
		}
		else
			throw "Introduceti o unitate de masura formata din mai mult de 2 litere";
	}
	char* getDeadline()
	{
		return deadline;
	}
	void setDeadline(char* newDeadline)
	{
		if(strlen(newDeadline) > 8)
		{
			if(deadline!=NULL)
				delete[]deadline;
			deadline = new char[strlen(newDeadline)+1];
			strcpy(deadline, newDeadline);
		}
		else
			throw "Introduceti o data de forma DD/MM/YYYY";
		
	}
	bool* getPaid()
	{
		return paid;
	}
	void setPaid(int noC, bool* b)
	{
		if(noC > 0)
		{
			if(paid!=NULL)
			delete[]paid;
			paid = new bool[noC];
			for(int i=0; i<noC; i++)
				paid[i] = b[i];
		}
		else
			throw "Introduceti un numar pozitiv, iar elementele vectorului trebuie sa fie true sau false";

	}
	static int getNoDebts()
	{
		return noDebts;
	}
	int getNoCategories()
	{
		return noCategories;
	}
	void setNoCategories(int newNr)
	{
		if(newNr>0)
			this->noCategories = newNr;
		else
			throw "Introduceti un numar pozitiv";
	}
	float* getAmountPerCategory()
	{
		return amountPerCategory;
	}
	void setDebtsPerCategory(int noDebts, float debts[5])
	{
		if(noCategories <= 5)
		{
			noCategories = noDebts;
			for(int i=0; i< noCategories; i++)
				amountPerCategory[i] = debts[i];
		}
		else
			throw "Introduceti o valoare mai mica sau egala cu 5";
	}
	
	//CONSTRUCTOR DE COPIERE
	Debts(const Debts &d):id(noDebts)
	{
		strcpy(this->name, d.name);
		this->noCategories = d.noCategories;
		for(int i=0; i<d.noCategories; i++)
			this->amountPerCategory[i] = d.amountPerCategory[i];
		this->deadline = new char[strlen(d.deadline)+1];
		strcpy(this->deadline, d.deadline);
		this->unit = new char[strlen(d.unit)+1];
		strcpy(this->unit, d.unit);
		this->paid = new bool[d.noCategories];
		for(int i=0; i<d.noCategories; i++)
			this->paid[i] = d.paid[i];
		noDebts++;
	}

	//OPERATOR =
	Debts operator=(const Debts& d)
	{
		strcpy(this->name, d.name);
		this->noCategories = d.noCategories;
		for(int i=0; i<d.noCategories; i++)
			this->amountPerCategory[i] = d.amountPerCategory[i];
		if(this->deadline!=NULL)
			delete[]deadline;
		this->deadline = new char[strlen(d.deadline)+1];
		strcpy(this->deadline, d.deadline);
		if(this->unit!=NULL)
			delete[]unit;
		this->unit = new char[strlen(d.unit)+1];
		strcpy(this->unit, d.unit);
		if(this->paid!=NULL)
			delete[]paid;
		this->paid = new bool[d.noCategories];
		for(int i=0; i<d.noCategories; i++)
			this->paid[i] = d.paid[i];
	return *this;
	}
	
	//OPERATOR >
	friend bool operator>(Debts& d1, Debts& d2)
	{
		float suma1 = 0;
		for(int i=0; i<d1.noCategories; i++)
			suma1 = suma1 + d1.amountPerCategory[i];
		float suma2 = 0;
		for(int i=0; i<d2.noCategories; i++)
			suma2 = suma2 + d2.amountPerCategory[i];
		if(suma1 > suma2)
			return true;
		else 
			return false;

	}

	//OPERATOR <<
	friend ostream& operator<<(ostream& iesire, Debts &d)
	{
		iesire<<"Datoria "<<d.name<<" cu id-ul "<<d.id<<" are ca si termen de plata "<<d.deadline<<" si se inregistreaza in "<<d.noCategories<<" categorii cu urmatoarele sume ";
		for(int i=0; i<d.noCategories; i++)
		{
			iesire<<d.amountPerCategory[i]<<" ";
			iesire<<endl;
		}
		iesire<<d.unit<<endl;
		iesire<<"Se marcheaza cu 1 datoria platita si cu 0 datoria neplatita: ";
		for(int i=0; i<d.noCategories; i++)
			iesire<<d.paid[i]<<" ";	
		return iesire;
	
	}



	//OPERATOR <<
	friend ofstream& operator<<(ofstream& iesire, Debts &d)
	{
		iesire<<d.name<<endl;
		iesire<<d.noCategories<<endl;
		for(int i=0; i<d.noDebts; i++)
			iesire<<d.amountPerCategory[i]<<" ";
		iesire<<endl<<d.deadline<<endl;
		iesire<<d.unit;
		for(int i=0; i<d.noDebts; i++)
			iesire<<d.paid[i]<<" ";
		iesire<<endl;

		return iesire;
	
	}

	//OPERATOR >>
	friend istream& operator>>(istream& intrare, Debts &d)
	{
		cout<<endl<<"Introduceti numele datoriei: ";
		char buffer[20];
		intrare>>buffer;
		strcpy(d.name, buffer);
		cout<<"Introduceti numarul de categorii: ";
		intrare>>d.noCategories;
		for(int i=0; i<d.noCategories; i++){
			cout<<"Introduceti sumele: ";
			intrare>>d.amountPerCategory[i];
		}
		cout<<endl<<"Introduceti deadline-ul ";
		intrare>>buffer;
		if(d.deadline!=NULL)
			delete[]d.deadline;
		d.deadline = new char[strlen(buffer)+1];
		strcpy(d.deadline, buffer);

		cout<<"Introduceti unitatea de masura: ";
		intrare>>buffer;
		if(d.unit!=NULL)
			delete[]d.unit;
		d.unit = new char[strlen(buffer)+1];
		strcpy(d.unit, buffer);

		if(d.paid!=NULL)
			delete[]d.paid;
		d.paid = new bool[d.noCategories];
		for(int i=0; i<d.noCategories; i++)
		{
			cout<<"Specificati daca datoria a fost platita sau nu prin introducerea urmatorilor valori: 1-achitata, 0-neachitata ";
			intrare>>d.paid[i];
		}
		cout<<"Datele au fost introduse cu succes";
		return intrare;

	}

	friend ifstream& operator>>(ifstream& intrare, Debts &d)
	{
		cout<<endl<<"Introduceti numele datoriei: ";
		char buffer[20];
		intrare>>buffer;
		strcpy(d.name, buffer);
		cout<<"Introduceti numarul de categorii: ";
		intrare>>d.noCategories;
		for(int i=0; i<d.noCategories; i++){
			cout<<"Introduceti sumele: ";
			intrare>>d.amountPerCategory[i];
		}
		cout<<"Introduceti deadline-ul ";
		intrare>>buffer;
		if(d.deadline!=NULL)
			delete[]d.deadline;
		d.deadline = new char[strlen(buffer)+1];
		strcpy(d.deadline, buffer);

		cout<<"Introduceti unitatea de masura: ";
		intrare>>buffer;
		if(d.unit!=NULL)
			delete[]d.unit;
		d.unit = new char[strlen(buffer)+1];
		strcpy(d.unit, buffer);

		if(d.paid!=NULL)
			delete[]d.paid;
		d.paid = new bool[d.noCategories];
		for(int i=0; i<d.noCategories; i++)
		{
			cout<<"Specificati daca datoria a fost platita sau nu prin introducerea urmatorilor valori: 1-achitata, 0-neachitata ";
			intrare>>d.paid[i];
		}
		cout<<"Datele au fost introduse cu succes";
		return intrare;

	}

	//OPERATOR INDEX
	float& operator[](int index)
	{
		if(index>=0 && index < this->noCategories)
		{
			cout<<endl<<"Suma datoriei de pe pozitia "<<index<<" este";
			return amountPerCategory[index];
		}
		else
			throw "DEBTS: Index out of bounds";
	}

	//OPERATOR==
	bool operator==(Debts d) {
		return this->noCategories == d.noCategories;
	}

	//OPERATOR +
	  Debts operator+(Debts op)
	  {
		Debts op2 = *this;
		op2.noCategories = this->noCategories + op.noCategories;
		if(op2.paid!=NULL)
			delete[]op2.paid;
		op2.paid = new bool[op2.noCategories];
		for(int i=0; i<this->noCategories; i++)
		{
			op2.amountPerCategory[i] = this->amountPerCategory[i];
			op2.paid[i]  = this->paid[i];
		}
		for(int i= this->noCategories; i<op2.noCategories; i++)
			{
				op2.amountPerCategory[i] = op.amountPerCategory[i-this->noCategories];
				op2.paid[i] = op.paid[i-this->noCategories];
			}
				
		return op2;
		
	  }
	

	 //OPERATOR --
	  //preincrementare
	Debts operator--() {
		for(int i=0; i<this->noCategories; i++)
			this->amountPerCategory[i] -= 1;
		return *this;
	}

	//postincrementare
	Debts operator--(int) {
		Debts temp = *this;
		for(int i=0; i<this->noCategories; i++)
			this->amountPerCategory[i] -= 1;
		return temp;
	}


	////OPERATOR CAST
	//explicit operator double()
	//{
	//	float suma = 0;
	//	for(int i=0; i<this->noCategories; i++)
	//		suma = suma +amountPerCategory[i];
	//	return (double)suma/this->noCategories;
	//}

	//OPERATOR !
	Debts operator!() {
		Debts d = *this;
		for(int i=0; i<this->noCategories; i++)
			d.paid[i] = !paid[i];
		return d;
	}

	//OPERATOR FUNCTIE
	bool operator()(Debts& d)
	{
		if(strlen(this->unit) == strlen(d.unit))
			return true;
		else
			return false;
	}
};
int Debts::noDebts = 0;

class UrgentDebt : public Debts{
private:
	bool* emergency;
public:
	//constr implicit
	UrgentDebt():Debts()
	{
		this->emergency = new bool[this->getNoCategories()];
		for(int i=0; i<this->getNoCategories(); i++)
			emergency[i] = false;
	}

	//constr explicit
	UrgentDebt(char n[20], int noC, float a[5], char* d, char* u, bool* p, bool* e):Debts(n, noC, a, d, u, p)
	{
		this->emergency = new bool[this->getNoCategories()];
		for(int i=0; i<this->getNoCategories(); i++)
			this->emergency[i] = e[i];
	}

	//destructor
	~UrgentDebt()
	{
		if(this->emergency != NULL)
			delete[] this->emergency;
	}


	//constructor de copiere
	UrgentDebt(UrgentDebt& u) : Debts(u)
	{
		this->emergency = new bool[this->getNoCategories()];
		for(int i=0; i<this->getNoCategories(); i++)
			this->emergency[i] = u.emergency[i];
	}

	//supraincarcare operator =
	UrgentDebt operator=(const UrgentDebt& u)
	{
		UrgentDebt::operator=(u);
		if(this->emergency != NULL)
			delete[]this->emergency;
		this->emergency = new bool[this->getNoCategories()];
		for(int i=0; i<this->getNoCategories(); i++)
			this->emergency[i] = u.emergency[i];

		return *this;
	}

	//supraincarcare operator<<
	friend ostream& operator<<(ostream& iesire, UrgentDebt &u)
	{
		iesire<<(Debts&)u;
		iesire<<"Datorie urgenta: "<<endl;
		for(int i=0; i< u.getNoCategories(); i++)
			cout<<u.emergency[i]<<" ";
		iesire<<endl;
		return iesire;
	}

	//supraincarcare operator >>
	friend istream& operator>>(istream& intrare, UrgentDebt& u)
	{
		intrare>>(Debts&)u;
		char buffer[100];
		cout<<"Datorie urgenta: ";
		for(int i=0; i<u.getNoCategories(); i++)
			intrare>>u.emergency[i];
		return intrare;
	}

	//supraincarcare operator index
	bool& operator[](int index)
	{
		if(index >= 0 && index< this->getNoCategories())
		{
			return emergency[index];
		}
		else
			throw "Index out of bounds";
	}

	//getteri si setteri 
	bool* getEmergency()
	{
		return emergency;
	}

	void setEmergency(bool* vector, int nr)
	{
		if(nr == this->getNoCategories())
		{
			nr = this->getNoCategories();
			if(emergency != NULL)
				delete[]emergency;
			emergency = new bool[nr];
			for(int i=0; i<nr; i++)
				emergency[i] = vector[i];
		}
		else throw "Numarul introdus trebuie sa fie egal cu nr categoriilor ";
	
	}
};

void generareRaport(Debts debts, char* numeRaport) {
	ofstream raport;
	raport.open(numeRaport, ios::out | ios::trunc);
	if (raport.is_open()) {
		raport << "\t\t Raport datorii"<<endl;
		raport<<"Nume datorie: "<<debts.getName()<<endl;
		raport<<"Numar categorii: "<<debts.getNoCategories()<<endl;
		for(int i=0; i<debts.getNoCategories(); i++)
		raport<<"Suma "<<i+1<<" :"<<debts.getAmountPerCategory()[i]<<endl;
		raport<<endl<<"Unitate: "<<debts.getUnit()<<endl;
		for(int i=0; i<debts.getNoCategories();i++)
			raport<<endl<<"Status "<<i+1<<" :"<<debts.getPaid()[i];
		raport<<endl<<"---------------------------------------"<<endl;
		float s =0;
		for(int i=0; i<debts.getNoCategories(); i++)
			s = s + debts.getAmountPerCategory()[i];
		raport<<"Total datorii: "<<s<<endl;
	}
	raport.close();
}

class Database {
private:
	User* user;
	Costs* costs;
	Categories* categories;
	Income* income;
	Debts* debts;
	int noUsers;
	int noCosts;
	int noCategories;
	int noIncomes;
	int noDebts;

public:
	//CONSTRUCTOR IMPLICIT
	Database()
	{
		user = 0;
		costs = 0;
		categories = 0;
		income = 0;
		debts = 0;
		noUsers = 0;
		noCosts = 0;
		noCategories = 0;
		noIncomes = 0;
		noDebts = 0;
	}

	//CONSTRUCTOR EXPLICIT
	Database(User *u, Costs* c, Categories* cat, Income* in, Debts* d, int noU, int noC, int noCat, int noI, int noD)
	{
		this->noUsers = noU;
		this->user = new User[noUsers];
		for (int i = 0; i < noUsers; i++)
		{
			user[i] = u[i];
		}

		this->noCosts = noC;
		this->costs = new Costs[noCosts];
		for (int i = 0; i < noCosts; i++)
		{
			costs[i] = c[i];
		}

		this->noCategories = noCat;
		this->categories = new Categories[noCategories];
		for (int i = 0; i < noCategories; i++)
		{
			categories[i] = cat[i];
		}

	
		this->noIncomes = noI;
		this->income = new Income[noIncomes];
		for (int i = 0; i < noIncomes; i++)
		{
			income[i] = in[i];
		}

		
		this->noDebts = noD;
		this->debts = new Debts[noDebts];
		for (int i = 0; i < noDebts; i++)
		{
			debts[i] = d[i];
		}



	}

	//DESTRUCTOR
	~Database()
	{
		delete[]user;
		delete[]costs;
		delete[]categories;
		delete[]income;
		delete[]debts;
	}

	//GETTERI
	User* getUser() {
		return user;
	}

	Costs* getCosts()
	{
		return costs;
	}

	Categories* getCategories()
	{
		return categories;
	}

	Income* getIncomes()
	{
		return income;
	}

	Debts* getDebts()
	{
		return debts;
	}

	void adaugaUser(User userNou){
		//creez un vector 
		User* vector;
		vector = new User[noUsers];
		//copiez elementele din users in vector
		for (int i = 0; i < noUsers; i++)
			vector[i] = user[i];
		//dezalocare
		delete[] user;
		noUsers++;
		//alocare
		user = new User[noUsers];

		for (int i = 0; i < noUsers - 1; i++)
			user[i] = vector[i];
		user[noUsers - 1] = userNou;
		scriereUseri();
	}

	void adaugaDatorie(Debts datorieNoua){
		//creez un vector 
		Debts* vector;
		vector = new Debts[noDebts];
		//copiez elementele din users in vector
		for (int i = 0; i < noDebts; i++)
			vector[i] = debts[i];
		//dezalocare
		delete[] debts;
		noDebts++;;
		//alocare
		debts = new Debts[noDebts];

		for (int i = 0; i < noDebts - 1; i++)
			debts[i] = vector[i];
		debts[noDebts - 1] = datorieNoua;
		scriereDatorii();
	}
	
	void adaugaCheltuiala(Costs cheltuialaNoua){
		//creez un vector 
		Costs* vector;
		vector = new Costs[noCosts];
		//copiez elementele din users in vector
		for (int i = 0; i < noCosts; i++)
			vector[i] = costs[i];
		//dezalocare
		delete[] costs;
		noCosts++;
		//alocare
		costs = new Costs[noCosts];

		for (int i = 0; i < noCosts - 1; i++)
			costs[i] = vector[i];
		costs[noCosts - 1] = cheltuialaNoua;
		scriereCheltuieli();
	}

	void adaugaVenit(Income venitNou){
		//creez un vector 
		Income* vector;
		vector = new Income[noIncomes];
		//copiez elementele din users in vector
		for (int i = 0; i < noIncomes; i++)
			vector[i] = income[i];
		//dezalocare
		delete[] income;
		noIncomes++;
		//alocare
		income = new Income[noIncomes];

		for (int i = 0; i < noIncomes - 1; i++)
			income[i] = vector[i];
		income[noIncomes - 1] = venitNou;
		scriereVenituri();
	}

	void adaugaCategorie(Categories categorieNoua){
		//creez un vector 
		Categories* vector;
		vector = new Categories[noCategories];
		//copiez elementele din users in vector
		for (int i = 0; i < noCategories; i++)
			vector[i] = categories[i];
		//dezalocare
		delete[] categories;
		noCategories++;
		//alocare
		categories = new Categories[noCategories];

		for (int i = 0; i < noCategories - 1; i++)
			categories[i] = vector[i];
		categories[noCategories - 1] = categorieNoua;
		scriereCategorii();
	}

	void scriereUseri() {
		ofstream g("useri.txt", fstream::app);
		g << noUsers << endl;
		for (int i = 0; i < noUsers; i++)
			g << user[i];
		g.close();
	}

	void scriereCheltuieli()
	{
		ofstream g("cheltuieli.txt", fstream::app);
		g<<noCosts<<endl;
		for(int i=0; i<noCosts; i++)
			g<<costs[i];
		g.close();
	}

	void scriereDatorii()
	{
		ofstream g("datorii.txt", fstream::app);
		g<<noDebts<<endl;
		for(int i=0; i<noDebts; i++)
			g<<debts[i];
		g.close();
	}

	void scriereCategorii()
	{
		ofstream g("categorii.txt", fstream::app);
		g<<noCategories<<endl;
		for(int i=0; i<noCategories; i++)
			g<<categories[i];
		g.close();
	}

	void scriereVenituri()
	{
		ofstream g("venituri.txt", fstream::app);
		g<<noIncomes<<endl;
		for(int i=0; i<noIncomes; i++)
			g<<income[i];
		g.close();
	}

	void citireUseri(){
		ifstream f("useri.txt");
		f >> noUsers;
		user = new User[noUsers];
		for (int i = 0; i < noUsers; i++)
			f >> user[i];
		f.close();

	}

	void citireDatorii(){
		ifstream f("datorii.txt");
		f >> noDebts;
		debts = new Debts[noDebts];
		for (int i = 0; i < noDebts; i++)
			f >> debts[i];
		f.close();
	}

	void citireCheltuieli(){
		ifstream f("cheltuieli.txt");
		f >> noCosts;
		costs = new Costs[noCosts];
		for (int i = 0; i < noCosts; i++)
			f >> costs[i];
		f.close();
	}

	void citireCategorii(){
		ifstream f("categorii.txt");
		f >> noCategories;
		categories = new Categories[noCategories];
		for (int i = 0; i < noCategories; i++)
			f >> categories[i];
		f.close();
	}

	void citireVenituri(){
		ifstream f("venituri.txt");
		f >> noIncomes;
		income = new Income[noIncomes];
		for (int i = 0; i < noIncomes; i++)
			f >> income[i];
		f.close();
	}
};

//clase abstracte
class Operatii
{
protected: 
	int id;
	char* numeOperatie;
public:
	//constructor implicit
	Operatii()
	{
		this->id = 0;
		this->numeOperatie = new char[strlen("DefaultOperation")+1];
		strcpy(this->numeOperatie, "Default Operation");
	}

	//constructor explicit
	Operatii(int i, char* nO)
	{
		this->id = i;
		this->numeOperatie = new char[strlen(nO)+1];
		strcpy(this->numeOperatie, nO);
	}

	//destructor
	~Operatii()
	{
		if(this->numeOperatie != NULL)
			delete[]this->numeOperatie;
	}

	int getId()
	{
		return this->id;
	}

	char* getNumeOperatie()
	{
		return this->numeOperatie;
	}

	virtual void scriereInFisier() = 0;
	 
};

class OperatiiDeScriereInFisier:public Operatii{
private: 
	char* numeFisier;

public:
	//constructor implicit
	OperatiiDeScriereInFisier():Operatii()
	{
		this->numeFisier = new char[strlen(" ")+1];
		strcpy(this->numeFisier, " ");
	}

	//constructor explicit
	OperatiiDeScriereInFisier(int i, char* nO, char* nF):Operatii(i, nO)
	{
		this->numeFisier = new char[strlen(nF)+1];
		strcpy(this->numeFisier, nF);
	}

	//destructor
	~OperatiiDeScriereInFisier()
	{
		if(this->numeFisier != NULL)
			delete[]this->numeFisier;
	}

	virtual void scriereInFisier()
	{
		ofstream g("operatie.txt", fstream::app);
		g<<"Id:"<<this->id<<endl;
		g<<endl<<"Nume Operatie: "<<this->numeOperatie<<endl;
		g<<endl<<"Nume fisier: "<<this->numeFisier<<endl;
		g.close();
	}

};

int main()
{
	vector<Debts>d;
	list<Income>incomess;
	map<string, Costs>costss;

	Database db;
	//data.citireUseri();
	int ok = 1;
	while(ok)
	{
		cout<<"Bine ai venit! Alege una dintre optiunile urmatoare: "<<endl;
		cout<<"1 - Creare cont "<<endl;
		cout<<"2 - Logare "<<endl;
		cout<<"3 - Iesire Aplicatie "<<endl;

		int optiune1;
		cin>>optiune1;
		switch(optiune1)
		{
		case 1:
			{
			cout<<"Ai ales optiunea de a iti crea un cont "<<endl;
			try{
			User temp;
			cin >> temp;
			db.adaugaUser(temp);
			ofstream fb("useri.bin", ios::out | ios::binary);
			fb.write((char*)&temp, sizeof(User));
			fb.close();
			ifstream gb("useri.bin", ios::in | ios::binary);
			gb.read((char*)&temp, sizeof(User));
			gb.close();
			cout << temp;

			}catch(char* exceptie)
			{
				cout<<exceptie;
			}
			}
			break;
		case 2:
			{
			cout<<"Bine ai revenit! Alege una dintre urmatoarele optiuni "<<endl;
			cout<<"1 - Datorii "<<endl;
			cout<<"2 - Venituri "<<endl;
			cout<<"3 - Cheltuieli "<<endl;
			int optiune2;
			cin>>optiune2;
			switch(optiune2)
			{
			case 1:
				{
					cout<<"1 - Adauga o datorie noua "<<endl;
					cout<<"2 - Sterge o datorie noua "<<endl;
					cout<<"3 - Vezi datorii existente "<<endl;
					cout<<"4 - Vezi raport "<<endl;
					int optiune3;
					cin>>optiune3;
					switch(optiune3)
					{
					case 1: {
						try{
							Debts d1;
							cin>>d1;
							db.adaugaDatorie(d1);
							d.push_back(d1);
							for(int i=0; i<d.size();i++)
								cout<<endl<<d[i]<<" "<<endl;
							ofstream fb("debts.bin", ios::out | ios::binary);
							fb.write((char*)&d1, sizeof(Debts));
							fb.close();
			
						}catch(char* mesaj)
						{
						cout<<mesaj;
						}
							}
							break;
					case 2: 
						{
							
						}
						break;
					case 3: 
						{
							db.citireDatorii();
						}
						break;
					case 4: 
						{
							cout<<"Introduceti toate datoriile pentru generarea unui raport "<<endl;
							Debts d1;
							cin>>d1;
							generareRaport(d1, "RaportDatorii.txt");
						}break;
							
					default: cout<<"Ati introdus o optiune inexistenta "<<endl;
					break;
					}
				}
				break;
			case 2:
				{
					cout<<"Adauga un venit nou "<<endl;
					Income in;
					try{
						cin>>in;
						db.adaugaVenit(in);
						incomess.push_back(in);
						for(list<Income>::iterator i = incomess.begin(); i!=incomess.end(); i++)
							cout<<*i;
						ofstream fb("incomes.bin", ios::out | ios::binary);
						fb.write((char*)&in, sizeof(Income));
							fb.close();
			
					}catch(char* mesaj)
					{
					cout<<mesaj;
					}
				}
				break;
				
			case 3: 
				{
				cout<<"Adauga o cheltuiala noua "<<endl;
				Costs temp;
					try{
						cin>>temp;
						db.adaugaCheltuiala(temp);
						ofstream fb("costs.bin", ios::out | ios::binary);
							fb.write((char*)&temp, sizeof(Costs));
							fb.close();
			
	
					}catch(char* mesaj)
					{
					cout<<mesaj;
					}
				}
				break;
			case 4:
				{
				cout<<"Iesire aplicatie"<<endl;
				ok =0;
				}
				break;

			default: cout<<"Ati introdus o optiune inexistenta "<<endl;
				break;
			}
			}

		case 3:
			{
				cout<<endl<<"Iesire aplicatie "<<endl;
				ok = 0;
			}
			break;
		
		default: cout<<"Ati introdus o optiune inexistenta "<<endl;
			break;
		}
		
}
		}
	
