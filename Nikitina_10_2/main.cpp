#include <iostream>//дл¤ cin cout
#include <fstream>//дл¤ ifstream/ofstream
#include <string>//дл¤ getline и сложени¤ строк

using namespace std;

void remove_longest(string& line)
{
	//создаЄм массив слов
	string* words = new string[line.length()];
	int count = 0;//количество слов пока 0
	words[count] = string();//инициализируем 0 слово
	for (int i = 0; i < line.length(); i++)
	{
		if (line[i] == ' ' || line[i] == '.')//если встретили пробел или точку - слово кончилось
		{
			count++;//увеличиваем количество
			words[count] = string();//инициализируем новое слово
			continue;//не переписываем символ
		}
		words[count] += line[i];//переписываем 1 символ из строки в слово
	}
	
	//ѕоиск максимальной длины слова
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

	//очищаем строку
	line.clear();

	//добавл¤ем в неЄ обратно все слова, кроме наибольшего
	for (int i = 0; i < max_index; i++)
	{
		line += words[i] + " ";
	}
	for (int i = max_index + 1; i < count; i++)
	{
		line += words[i] + " ";
	}
	delete[] words;//удал¤ем пам¤ть под временный массив слов
}

int main()
{
	setlocale(LC_ALL, "russian");
	cout << "јвтор: Ќикитина ƒарь¤ —ергеевна\n";

	ifstream f1("f1.txt");
	ofstream f2("f2.txt");

	while (!f1.eof())
	{
		string line;
		std::getline(f1, line);//считать строку
		remove_longest(line);//удалить наидлиннейшее слово
		f2 << line + "\n";//вывести строку в файл
	}

	f1.close();
	f2.close();

	system("pause");
	return 0;
}
