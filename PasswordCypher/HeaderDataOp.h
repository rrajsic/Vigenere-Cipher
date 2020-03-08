#ifndef HEADERDATAOP_H
#define HEADERDATAOP_H
class Admin {
private: 
	std::string masterpassword = { "kundak" };
	std::string key = { "wishuponadeadstarisawishwasted" };
						
public:
	std::string getKey();
	std::string getMasterpassword();
};

class Data
{
private:
	std::string location;
	std::string email;
	std::string username;
	std::string password;

public:
	void setData();
	std::string getLocation();
	std::string getEmail();
	std::string getUsername();
	std::string getPassword();
	void setLocation(std::string location);
	void setEmail(std::string email);
	void setUsername(std::string username);
	void setPassword(std::string password);
	void printData();

};
Data decypherData(Data obj, Admin admin, char** cyphermatrix);
Data cypherData(Data obj, Admin admin, char** cyphermatrix);
std::string decypherMessage(char** cyphermatrix, Admin admin, std::string cyphermessage, int cyphermessagelength);
std::string cypherMessage(char** cyphermatrix, Admin admin, std::string message, int messagelength);

char** cypherMatrix();
char** initializeMatrix();
char** allocateCypherMatrix();
void printMatrix(char** matrix);
void deleteMatrix(char** matrix);
Data* allocateData(int x);


#endif