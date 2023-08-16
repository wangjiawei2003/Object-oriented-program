#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
int main()
{
	ifstream infile;
	char str[500];
	infile.open("1.txt",ios::in||ios::binary);

	ofstream outfile;
	outfile.open("2.txt", ios::out||ios::binary);
	if (!infile.eof())
	{
		infile >> str;
		outfile << str;
		outfile.close();
		infile.close();
	}

}