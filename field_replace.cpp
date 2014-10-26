//============================================================================
// Name        : field_substitution.cpp
// Author      : Marco Rocci
// Version     :
// Copyright   : Copyright 2014
// Description : Replace a string inside a separator, in C++
//============================================================================
#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;


class field_substitution{
private:
	int		position;
	string	separator;
	string	ReplaceWith;
	string	path;


public:

	field_substitution(int argc, char* argv[]) :  position( (int) argv[1][0] - '0'), separator(argv[2]), ReplaceWith(argv[3]), path(argv[4]){	}
	field_substitution() {}
	~field_substitution(){}

	int field_pos(int f_p){position = f_p; return position;}; // Add Position of field, starting with 0 to Max
	string field_sep(string f_s){separator = f_s; return separator;}; // Add separator, where the string is delimited 
	string field_replace(string f_r){ReplaceWith = f_r; return ReplaceWith;}; // The field will be replaced with this string
	string field_path(string f_p){path = f_p; return path;};  // Add the pathfile

	void field_go();  // Replace the field, delimited with separator, with my string
};

void field_substitution::field_go()
{
	string linea, linea2, path_2 = path;
	path_2 += "_replaced.txt";

	int count = 0, len_replace = 0;

	ifstream file;
	file.open(path.c_str(), ifstream::in);

	ofstream replace;

	replace.open(path_2.c_str(), std::ofstream::out);

	while ( getline (file,linea) )
	{

		for(unsigned int i = 0; i < linea.length(); i++)
		{

			if (linea.substr(i,1) == separator.c_str())
				count++;

			if (count == position)
			{
				for(unsigned int j=i+1; j<linea.length(); j++)
				{
					if((linea.substr(j,1) == "\n") or (linea.substr(j,1) == separator.c_str() ))
					{
						len_replace = j-1;
						break;
					}

					linea2 += linea.substr(j,1);
				}

				linea2 = "";

				linea.replace(i+1,len_replace-2,ReplaceWith);
			}

			if (count == position)
				break;

		}

		count = 0;

		replace<<linea<<endl;

	}
	file.close();
	replace.close();

}



int main(int argc, char** argv) {


if(argc >= 5)
	{

		field_substitution C = field_substitution(argc,argv);

		C.field_go();

		return 0;
	}
	else
		cout<<"Errore: parametri non sufficienti: \n\n esempio:\n 1,\"i,\"ciao\",\"C:\\Users\\Utente\\Desktop\\log.txt"<<endl;
}
