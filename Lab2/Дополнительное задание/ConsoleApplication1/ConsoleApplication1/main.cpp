#include "json.hpp"
#include <iostream>
using namespace std;
using json = nlohmann::json;
string NAME = "name";
string USER = "user";
string answer = "answer";
string everything = "everything";
void main()
{
	json j3;
	// создаём пустой JSON-объект
	json j;
	// добавляем строку, которая будет храниться как std::string
	j[NAME] = "Habrahabr";
	// добавляем пустой вложенный объект
	j["nothing"] = nullptr;
	// число внутри вложенного объекта
	j[answer][everything] = 42;
	// добавляем массив строк (будет храниться как std::vector<std::string>)
	// обратите внимание - используются списки инициализации
	j["companies"] = { "Infopulse", "TM" };
	// добавляем ещё один объект - на этот раз используем список инициализации с парами "ключ" - "значение"
	j[USER] = { { "name", "tangro" },{ "active", true } };
	//Аналог написанному выше
	json j2 =
	{
		{ "name", "Habrahabr" },
		{ "nothing", nullptr },
		{ "answer",{
			{ "everything", 42 }
		} },
		{ "companies",{ "Infopulse", "TM" } },
		{ "user",{
			{ "name", "tangro" },
			{ "active", true }
		} }
	};
	//string usrnAME = j.//j.get(USER);//j.get.(USER).get(NAME);
	string usrName = j[NAME];
//	string uUser = j[USER].get;
	//string answer1 = j[answer][everything];
	
	cout << usrName << endl;
	//cout << answer1 << endl;
	system("pause");
}