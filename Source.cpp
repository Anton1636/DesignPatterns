#include <iostream>
#include<string>
#include<map>

using namespace std;

class Nbook
{
	string name;
	string value;
	string key;
	map <string, string> parts;


public:

	Nbook() = default;

	Nbook(string n) :name(n)
	{

	}

	const string getPart(const string & key)
	{
		return key;
		return value;
	}

	void setPart(string key, string value)
	{
		if (!checkPart(key))
		{
			parts[key] = value;
		}
	}

	void show()
	{
		for (auto el : parts)
		{
			cout << el.first << " " << el.second << endl;
		}
	}

	bool checkPart(string key)
	{
		return parts.find(key) != parts.end()?true:false;
	}
};

class NBBuilder:public Nbook 
{

protected:

	Nbook *devise;

public:

	NBBuilder() = default;

	NBBuilder(Nbook*d) :devise(d)
	{

	}

	void setMemory()
	{
		devise->setPart("memory", "16GB");
	}

	void setHDD()
	{
		devise->setPart("1HDD", "1TB");
	}

	void setMatrix()
	{
		devise->setPart("Matrix", "1900x1080");
	}

	void setProcessor()
	{
		devise->setPart("Processor", "i7750");
	}

	Nbook * get_devise()
	{
		return devise;
	}
};

class GameNB:public NBBuilder
{

public:
	
	GameNB()
	{
		devise = new  Nbook("Gamer");
	}

};

class HBook :public NBBuilder
{

public:

	HBook()
	{
		devise = new Nbook("Home");
	}

};

class OBook :public NBBuilder
{

public:

	OBook()
	{
		devise = new Nbook("Office");
	}

};

class Director
{

public:

	void createNbook(NBBuilder *builder)
	{
		builder->setMemory();
		builder->setHDD();
		builder->setMatrix();
		builder->setProcessor();
	}

};



int main()
{
	Director *Shop = new Director();
	NBBuilder *builder = new GameNB();
	Shop->createNbook(builder);
	builder->get_devise()->show();


	
	system("pause");
}