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
	// ������ ������ JSON-������
	json j;
	// ��������� ������, ������� ����� ��������� ��� std::string
	j[NAME] = "Habrahabr";
	// ��������� ������ ��������� ������
	j["nothing"] = nullptr;
	// ����� ������ ���������� �������
	j[answer][everything] = 42;
	// ��������� ������ ����� (����� ��������� ��� std::vector<std::string>)
	// �������� �������� - ������������ ������ �������������
	j["companies"] = { "Infopulse", "TM" };
	// ��������� ��� ���� ������ - �� ���� ��� ���������� ������ ������������� � ������ "����" - "��������"
	j[USER] = { { "name", "tangro" },{ "active", true } };
	//������ ����������� ����
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