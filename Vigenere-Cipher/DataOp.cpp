#include <iostream>
#include <string.h>
#include "HeaderDataOp.h"

void Data::setData()
{
	std::cout << std::endl;
	std::cout << "Enter location: ";
	std::cin >> location;
	std::cout << "Enter email: ";
	std::cin >> email;
	std::cout << "Enter username: ";
	std::cin >> username;
	std::cout << "Enter password: ";
	std::cin >> password;
}

std::string Data::getLocation()
{
	return location;
}

std::string Data::getEmail()
{
	return email;
}
std::string Data::getUsername()
{
	return username;
}
std::string Data::getPassword()
{
	return password;
}
void Data::setLocation(std::string location)
{
	this->location = location;
}
void Data::setEmail(std::string email)
{
	this->email = email;
}
void Data::setUsername(std::string username)
{
	this->username = username;
}
void Data::setPassword(std::string password)
{
	this->password = password;
}
void Data::printData()
{
	std::cout << "Location: " << location << std::endl;
	std::cout << "e-mail: "	  << email	  << std::endl;
	std::cout << "Username: " << username << std::endl;
	std::cout << "Password: " << password << std::endl;
}
std::string Admin::getMasterpassword()
{
	return masterpassword;
}

std::string Admin::getKey()
{
	return key;
}
Data decypherData(Data obj, Admin admin, char** cyphermatrix)
{
	Data decrypted_obj;
	std::string  buffer;
	buffer = obj.getLocation();
	decrypted_obj.setLocation(decypherMessage(cyphermatrix, admin, buffer, static_cast<int>(buffer.size())));
	buffer = obj.getEmail();
	decrypted_obj.setEmail(decypherMessage(cyphermatrix, admin, buffer, static_cast<int>(buffer.size())));
	buffer = obj.getUsername();
	decrypted_obj.setUsername(decypherMessage(cyphermatrix, admin, buffer, static_cast<int>(buffer.size())));
	buffer = obj.getPassword();
	decrypted_obj.setPassword(decypherMessage(cyphermatrix, admin, buffer, static_cast<int>(buffer.size())));

	return decrypted_obj;
}
Data cypherData(Data obj,Admin admin,char **cyphermatrix)
{
	Data crypted_obj;
	std::string  buffer;
	buffer = obj.getLocation();
	crypted_obj.setLocation(cypherMessage(cyphermatrix, admin, buffer, static_cast<int>(buffer.size())));
	buffer = obj.getEmail();
	crypted_obj.setEmail(cypherMessage(cyphermatrix, admin, buffer, static_cast<int>(buffer.size())));
	buffer = obj.getUsername();
	crypted_obj.setUsername(cypherMessage(cyphermatrix, admin, buffer, static_cast<int>(buffer.size())));
	buffer = obj.getPassword();
	crypted_obj.setPassword(cypherMessage(cyphermatrix, admin, buffer, static_cast<int>(buffer.size())));

	return crypted_obj;
}
std::string decypherMessage(char** cyphermatrix, Admin admin, std::string cyphermessage, int cyphermessagelength)
{
	std::string decryptedmessage;
	decryptedmessage.resize(cyphermessagelength);
	char row[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y' };
	std::string orgkey = admin.getKey();
	orgkey.resize(cyphermessagelength);

	int index_i = 0;
	int index_j = 0;
	for (int i = 0; i < cyphermessagelength; i++)
	{
		if (cyphermessage[i] == '@' || cyphermessage[i] == '.' || cyphermessage[i] == ',' || cyphermessage[i] == ':' || cyphermessage[i] == ';' || cyphermessage[i] == '\"') {
			decryptedmessage[i] = cyphermessage[i];
			continue;
		}
		if (cyphermessage[i] >= 48 && cyphermessage[i] <= 57) {
			decryptedmessage[i] = cyphermessage[i];
			continue;
		}

		else {
			for (int k = 0; k < 26; k++)
			{
				if (orgkey[i] == row[k])index_i = k;
			}

			for (int l = 0; l < 26; l++)
			{
				if (cyphermatrix[index_i][l] == cyphermessage[i])decryptedmessage[i] = row[l];
			}

		}
	}
	
	return decryptedmessage;
}


std::string cypherMessage(char** cyphermatrix,Admin admin, std::string message,int messagelength)
{
	std::string cryptedmessage;
	cryptedmessage.resize(messagelength);
	char row[26] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y' };
	std::string orgkey = admin.getKey();
	orgkey.resize(messagelength);

	int index_i = 0;
	int index_j = 0;
	for (int i = 0; i < messagelength; i++)
	{
		if (message[i] == '@' || message[i] == '.' || message[i] == ',' || message[i] == ':' || message[i] == ';' || message[i] == '\"') {
			cryptedmessage[i] = message[i];
			continue;
		}
		if (message[i] >= 48 && message[i] <= 57) {
			cryptedmessage[i] = message[i];
			continue;
		}

		else {
			for (int k = 0; k < 26; k++)
			{
				if (orgkey[i] == row[k])index_i = k;
				if (message[i] == row[k])index_j = k;
			}
			cryptedmessage[i] = cyphermatrix[index_i][index_j];

		}
	}
	return cryptedmessage;
}

char** cypherMatrix()
{
	char** matrix;
	matrix = initializeMatrix();
	
	for (int i = 0; i < 26; i++)
	{

	if ((26 - 25 - i) >= 0)matrix[i][26 - 25 - i] = 'b';
			if ((26 - 24 - i) >= 0)matrix[i][26 - 24 - i] = 'c';
			if ((26 - 23 - i) >= 0)matrix[i][26 - 23 - i] = 'd';
			if ((26 - 22 - i) >= 0)matrix[i][26 - 22 - i] = 'e';
			if ((26 - 21 - i) >= 0)matrix[i][26 - 21 - i] = 'f';
			if ((26 - 20 - i) >= 0)matrix[i][26 - 20 - i] = 'g';
			if ((26 - 19 - i) >= 0)matrix[i][26 - 19 - i] = 'h';
			if ((26 - 18 - i) >= 0)matrix[i][26 - 18 - i] = 'i';
			if ((26 - 17 - i) >= 0)matrix[i][26 - 17 - i] = 'j';
			if ((26 - 16 - i) >= 0)matrix[i][26 - 16 - i] = 'k';
			if ((26 - 15 - i) >= 0)matrix[i][26 - 15 - i] = 'l';
			if ((26 - 14 - i) >= 0)matrix[i][26 - 14 - i] = 'm';
			if ((26 - 13 - i) >= 0)matrix[i][26 - 13 - i] = 'n';
			if ((26 - 12 - i) >= 0)matrix[i][26 - 12 - i] = 'o';
			if ((26 - 11 - i) >= 0)matrix[i][26 - 11 - i] = 'p';
			if ((26 - 10 - i) >= 0)matrix[i][26 - 10 - i] = 'q';
			if ((26 - 9 - i) >= 0)matrix[i][26 - 9 - i] = 'r';
			if ((26 - 8 - i) >= 0)matrix[i][26 - 8 - i] = 's';
			if ((26 - 7 - i) >= 0)matrix[i][26 - 7 - i] = 't';
			if ((26 - 6 - i) >= 0)matrix[i][26 - 6 - i] = 'u';
			if ((26 - 5 - i) >= 0)matrix[i][26 - 5 - i] = 'v';
			if ((26 - 4 - i) >= 0)matrix[i][26 - 4 - i] = 'w';
			if ((26 - 3 - i) >= 0)matrix[i][26 - 3 - i] = 'x';
			if ((26 - 2 - i) >= 0)matrix[i][26 - 2 - i] = 'y';
			if ((26 - 1 - i) >= 0)matrix[i][26 - 1 - i] = 'z';
			if ((26 + 1 - i) >= 0&& (26 + 1 - i) <26 )matrix[i][26 + 1 - i] = 'b';
			if ((26 + 2 - i) >= 0 && (26 + 2 - i) < 26)matrix[i][26 + 2 - i] = 'c';
			if ((26 + 3 - i) >= 0 && (26 + 3 - i) < 26)matrix[i][26 + 3 - i] = 'd';
			if ((26 + 4 - i) >= 0 && (26 + 4 - i) < 26)matrix[i][26 + 4 - i] = 'e';
			if ((26 + 5 - i) >= 0 && (26 + 5 - i) < 26)matrix[i][26 + 5 - i] = 'f';
			if ((26 + 6 - i) >= 0 && (26 + 6 - i) < 26)matrix[i][26 + 6 - i] = 'g';
			if ((26 + 7 - i) >= 0 && (26 + 7 - i) < 26)matrix[i][26 + 7 - i] = 'h';
			if ((26 + 8 - i) >= 0 && (26 + 8 - i) < 26)matrix[i][26 + 8 - i] = 'i';
			if ((26 + 9 - i) >= 0 && (26 + 9 - i) < 26)matrix[i][26 + 9 - i] = 'j';
			if ((26 + 10 - i) >= 0 && (26 + 10 - i) < 26)matrix[i][26 + 10 - i] = 'k';
			if ((26 + 11 - i) >= 0 && (26 + 11 - i) < 26)matrix[i][26 + 11 - i] = 'l';
			if ((26 + 12 - i) >= 0 && (26 + 12 - i) < 26)matrix[i][26 + 12 - i] = 'm';
			if ((26 + 13 - i) >= 0 && (26 + 13 - i) < 26)matrix[i][26 + 13 - i] = 'n';
			if ((26 + 14 - i) >= 0 && (26 + 14 - i) < 26)matrix[i][26 + 14 - i] = 'o';
			if ((26 + 15 - i) >= 0 && (26 + 15 - i) < 26)matrix[i][26 + 15 - i] = 'p';
			if ((26 + 16 - i) >= 0 && (26 + 16 - i) < 26)matrix[i][26 + 16 - i] = 'q';
			if ((26 + 17 - i) >= 0 && (26 + 17 - i) < 26)matrix[i][26 + 17 - i] = 'r';
			if ((26 + 18 - i) >= 0 && (26 + 18 - i) < 26)matrix[i][26 + 18 - i] = 's';
			if ((26 + 19 - i) >= 0 && (26 + 19 - i) < 26)matrix[i][26  +19 - i] = 't';
			if ((26 + 20 - i) >= 0 && (26 + 20 - i) < 26)matrix[i][26 + 20 - i] = 'u';
			if ((26 + 21 - i) >= 0 && (26 + 21 - i) < 26)matrix[i][26 + 21 - i] = 'v';
			if ((26 + 22 - i) >= 0 && (26 + 22 - i) < 26)matrix[i][26 + 22 - i] = 'w';
			if ((26 + 23 - i) >= 0 && (26 + 23 - i) < 26)matrix[i][26 + 23 - i] = 'x';
			if ((26 + 24 - i) >= 0 && (26 + 24 - i) < 26)matrix[i][26 + 24 - i] = 'y';
			if ((26 + 25 - i) >= 0 && (26 + 25 - i) < 26)matrix[i][26  +25 - i] = 'z';
		}

	return matrix;
}

char** initializeMatrix(){
	char** matrix = allocateCypherMatrix();
	
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			matrix[i][j] = 'a';
		}
	}
	return matrix;
}
char** allocateCypherMatrix()
{
	char** matrix = new char*[26];
	for (int i = 0; i < 26; i++)
	{
		matrix[i] = new char[26];
	}
	return matrix;
}

void printMatrix(char** matrix)
{
	for (int i = 0; i < 26; i++)
	{
		for (int j = 0; j < 26; j++)
		{
			std::cout << matrix[i][j]<<" ";
		}
		std::cout << std::endl;
	}
	
}

void deleteMatrix(char** matrix)
{
	for (int i = 0; i < 26; i++)
	{
		delete matrix[i];
	}
	delete matrix;
}

Data* allocateData(int x)
{
	Data* data = nullptr;
	data = new Data[x];

	return data;
}