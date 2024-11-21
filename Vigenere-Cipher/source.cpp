#include <iostream>
#include <fstream>
#include <string.h>
#include <conio.h>
#include "HeaderDataOp.h"
#include "HeaderFileOP.h"

void printFirstTime();
void printChoice();
int main()
{
	Admin admin;
	std::string pass;
	std::cout << "Enter master password: ";
	std::cin >> pass;
	while (pass.compare(admin.getMasterpassword())!=0) {
		std::cout << "\nTry again: ";
		std::cin >> pass;
	}
		system("cls");
		char** abeceda;
		abeceda = cypherMatrix();
		//printMatrix(abeceda);


		if (exists("data.dat")) {
			std::ifstream dfread;
			std::ofstream txt;
			std::ofstream dfwrite;
			Data obj_read;
			Data obj_write;
			Data cypher_obj_write;
			Data decypher_obj_read;
			std::string buffer;
			char choice='\0';
			char choicetwo = '\0';
			printChoice();
			do {
				choice = _getch();
				switch (choice)
				{
				case '1':
					dfread.open("data.dat", std::ios::in | std::ios::binary);
					while (true) {
						if (!(dfread >> buffer))break;
						else obj_read.setLocation(buffer);
						dfread >> buffer;
						obj_read.setEmail(buffer);
						dfread >> buffer;
						obj_read.setUsername(buffer);
						dfread >> buffer;
						obj_read.setPassword(buffer);
						decypher_obj_read = decypherData(obj_read, admin, abeceda);


						decypher_obj_read.printData();
						
						std::cout << std::endl;
					}
					//printMatrix(abeceda);
					dfread.close();
					std::cout << "\n\nPress (x) to exit.\n";
					break;

				case '2':
					dfread.open("data.dat", std::ios::in | std::ios::binary);
					txt.open("classified.txt", std::ios::out);
					while (true) {
						if (!(dfread >> buffer))break;
						buffer = decypherMessage(abeceda, admin, buffer, static_cast<int>(buffer.size()));
						txt << "Location: ";
						txt << buffer;
						txt << "\n";
						dfread >> buffer;
						buffer = decypherMessage(abeceda, admin, buffer, static_cast<int>(buffer.size()));
						txt << "Email: ";
						txt << buffer;
						txt << "\n";
						dfread >> buffer;
						buffer = decypherMessage(abeceda, admin, buffer, static_cast<int>(buffer.size()));
						txt << "Username: ";
						txt << buffer;
						txt << "\n";
						dfread >> buffer;
						buffer = decypherMessage(abeceda, admin, buffer, static_cast<int>(buffer.size()));
						txt << "Password: ";
						txt << buffer;
						txt << "\n\n";

					}
					std::cout << "Successful.";
					dfread.close();
					txt.close();
					std::cout << "\n\nPress (x) to go exit.\n";
					break;

				case '3':
					do {
						dfwrite.open("data.dat", std::ios_base::app | std::ios::binary);
						obj_write.setData();
						cypher_obj_write = cypherData(obj_write, admin, abeceda);

						dfwrite << cypher_obj_write.getLocation();
						dfwrite << "\n";
						dfwrite << cypher_obj_write.getEmail();
						dfwrite << "\n";
						dfwrite << cypher_obj_write.getUsername();
						dfwrite << "\n";
						dfwrite << cypher_obj_write.getPassword();
						dfwrite << "\n";

						std::cout << "\nPress any key to continue." << std::endl;
						std::cout << "\nPress (x) to stop adding data." << std::endl;
						choicetwo = _getch();

					} while (choicetwo!= 'x' && choicetwo != 'X');
					std::cout << "\n\nPress (x) to go exit.\n";
					dfwrite.close();
					break;

				case'x':
				case 'X':
					deleteMatrix(abeceda);
					exit(EXIT_SUCCESS);
					
				default:
					std::cout << "Wrong choice, try again." << std::endl;
				}
				
			} while (choice != 'x' && choice != 'X');
			

			
			deleteMatrix(abeceda);
			system("pause");
			exit(EXIT_SUCCESS);
		}

		else {
			printFirstTime();
			std::ofstream dfwrite;
			dfwrite.open("data.dat", std::ios::out | std::ios::binary);

			Data obj_write;
			Data cypher_obj_write;
			char option = '\0';
			do {
				obj_write.setData();
				cypher_obj_write = cypherData(obj_write, admin, abeceda);

				dfwrite << cypher_obj_write.getLocation();
				dfwrite << "\n";
				dfwrite << cypher_obj_write.getEmail();
				dfwrite << "\n";
				dfwrite << cypher_obj_write.getUsername();
				dfwrite << "\n";
				dfwrite << cypher_obj_write.getPassword();
				dfwrite << "\n";

				std::cout << "\nPress any key to continue." << std::endl;
				std::cout << "\nPress (x) to stop adding data." << std::endl;
				option = _getch();

			} while (option != 'x' && option != 'X');

			dfwrite.close();
		}

		deleteMatrix(abeceda);
		system("pause");
		exit(EXIT_SUCCESS);
	}
	
	
void printFirstTime()
{
	std::cout << "Warning: special characters and numbers will not be encrypted!" << std::endl;
	std::cout << "You can't undo one, so if you mess up you will need to delete all.\n";
}

void printChoice()
{
	std::cout << "Press a number before which operation you would like.\n";
	std::cout << "1 --> Print the list on screen\n";
	std::cout << "2 --> Print the list to .txt file (warning: delete file after use)\n";
	std::cout << "3 --> Add new item\n\n";
}


