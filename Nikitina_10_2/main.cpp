#include <iostream>//��� cin cout
#include <fstream>//��� ifstream/ofstream
#include <string>//��� getline � �������� �����

using namespace std;

void remove_longest(string& line)
{
	//������ ������ ����
	string* words = new string[line.length()];
	int count = 0;//���������� ���� ���� 0
	words[count] = string();//�������������� 0 �����
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == ' ' || line[i] == '.')//���� ��������� ������ ��� ����� - ����� ���������
		{
			count++;//����������� ����������
			words[count] = string();//�������������� ����� �����
			continue;//�� ������������ ������
		}
		words[count] += line[i];//������������ 1 ������ �� ������ � �����
	}
	
	//����� ������������ ����� �����
	int max_length = words[0].length();
	int max_index = 0;
	for (int i = 1; i < count; i++)
	{
		if (words[i].length() > max_length)
		{
			max_length = words[i].length();
			max_index = i;
		}
	}

	//������� ������
	line.clear();

	//��������� � �� ������� ��� �����, ����� �����������
	for (int i = 0; i < max_index; i++)
	{
		line += words[i] + " ";
	}
	for (int i = max_index + 1; i < count; i++)
	{
		line += words[i] + " ";
	}
	delete[] words;//������� ������ ��� ��������� ������ ����
}

int main()
{
	setlocale(LC_ALL, "russian");
	cout << "�����: �������� ����� ���������\n";

	ifstream f1("f1.txt");
	ofstream f2("f2.txt");

	while (!f1.eof())
	{
		string line;
		std::getline(f1, line);//������� ������
		remove_longest(line);//������� ������������� �����
		f2 << line + "\n";//������� ������ � ����
	}

	f1.close();
	f2.close();

	system("pause");
	return 0;
}
