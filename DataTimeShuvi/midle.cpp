#include "Stdafx.h"
using namespace std;

struct TelephoneWEB
{
    string fio, telephone_num;

};

    void midle()
    {
        /*
        Телефонная сеть:
           - ФИО абонента;
           - номер телефона;
           - дата поломки;
           - время поломки;
           - дата устранения;
           - время устранения.
        Задача:
           - вывести сведения по всем заявкам на ремонт с указанием срока устранения неисправности в днях;
           - вывести все сведения о поломках за прошлый месяц.

        */
        cout << "\nСредний уровень: \n";
		string s1{ "19.01.2038" }, s2{ "26.05.1970" };
		stringstream ss1, ss2;
		ss1.str(s1);
		ss2.str(s2);
		tm stm1{}, stm2{};
		ss1 >> std::get_time(&stm1, "%d.%m.%Y");
		ss2 >> std::get_time(&stm2, "%d.%m.%Y");
		stm1.tm_isdst = -1;
		stm2.tm_isdst = -1;
		cout << stm1.tm_mday << '.' << stm1.tm_mon << '.' << stm1.tm_year << std::endl;
		cout << stm2.tm_mday << '.' << stm2.tm_mon << '.' << stm2.tm_year << std::endl;
		time_t t1 = std::mktime(&stm1);
		time_t t2 = std::mktime(&stm2);
		if (t1 != -1 && t2 != -1)
		{
			double dif = std::difftime(t1, t2);
			std::cout << (dif < 0. ? "first" : dif > 0. ? "second" : "equal") << std::endl;
		}
		else
		{
			std::cerr << "Ошибка\n";
		}   
		  time_t now = time(0);
	   char* dt = ctime(&now);
	   cout << "Местная дата и время: " << dt << endl;
	   tm *gmtm = gmtime(&now);
	   dt = asctime(gmtm);
	   cout << "UTC дата и время: "<< dt << endl;
		time_t now = time(0);
	   cout << "Number of sec since January 1,1970:" << now << endl;
	   tm *ltm = localtime(&now);
	   cout << "Год: " << 1970 + ltm->tm_year<<endl;
	   cout << "Месяц: "<< 1 + ltm->tm_mon<< endl;
	   cout << "День: "<<  ltm->tm_mday << endl;
	   cout << "Время: "<< 1 + ltm->tm_hour << ":";
	   cout << 1 + ltm->tm_min << ":";
	   cout << 1 + ltm->tm_sec << endl;
	
		cout << "\nНажмите <Enter> чтобы продолжить: ";
		while (getchar() != '\n')
			continue;
	}
struct Book;
struct Book
{
	string fio;
	string book_name;
	int    cost;
	int    count;
};
void CheckDigit(int& anydigit);

Book* FillStruct(Book* mas_book, int count)  //заполняем масив структур
{
	if (mas_book == nullptr)
		mas_book = new Book[count];
	for (size_t i = 0; i < count; i++)
	{
		mas_book[i].fio = "ФИО" + to_string(i + 1);
		mas_book[i].book_name = "BooksName" + to_string(i + 1);
		mas_book[i].cost = 100 + rand() % 1000;
		mas_book[i].count = 1 + rand() % 100;
	}
	return mas_book;
}
void ShowBooks(Book* mas_books, int count)
{
	cout << "\nИнформация о всех книах: \n";
	for (size_t i = 0; i < count; i++)
	{
		printf("\nИнформация о %d книге: \n\t", i + 1);
		cout << mas_books[i].fio << " ";
		cout << mas_books[i].book_name << " ";
		cout << mas_books[i].cost << " ";
		cout << mas_books[i].count << "\n";
	}
}
Book* LoadFile(int count)  //Считывание данные с файла
{
	ifstream f_in; f_in.open("database.bin", ios::binary | ios::in);
	Book* buffer = new Book[count];
	f_in.read((char*)buffer, count * sizeof(Book));
	f_in.close();
	return buffer;
}
void SaveFile(Book* mas_book, int count)
{
	ofstream f_out; f_out.open("database.bin", ios::binary | ios::out);
	int BufferSize = count * sizeof(Book);
	f_out.write((char*)mas_book, BufferSize);
	f_out.close();
}
int IsSetDiscount(int count) //Установление скидки
{
	ifstream f_in; f_in.open("database.bin", ios::binary | ios::in);
	Book* buffer = new Book[count];
	f_in.read((char*)buffer, count * sizeof(Book));
	f_in.close();
	bool flag = false;
	for (size_t i = 0; i < count; i++)
	{
		if (buffer[i].fio[i] == 'K')
		{
			flag = true;
			for (size_t i = 0; i < count; i++)
			{
				printf("\nИнформация о %d книге: \n\t", i + 1);
				cout << buffer[i].fio << " ";
				cout << buffer[i].book_name << " ";
				cout << buffer[i].cost << " ";
				cout << buffer[i].count << "\n";
			}
		}
	}
	if (!flag)
		cout << "\nНет не одного автора фамилия которого начинается на <K>!!!\n";
	return 0;
}
void CheckDigit(int& anydigit)
{
	while (true)
	{
		cin >> anydigit;
		if (!cin.good() || cin.fail())
		{
			cin.clear();
			cin.ignore(32567, '\n');
			cout << "\nВведите коректное числовое значение...\n";
			cout << "\nПовторите ввод: ";
		}
		break;
	}
}
