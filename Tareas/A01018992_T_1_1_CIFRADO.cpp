#include <iostream>
#include <string>

using namespace std;

//Methods:
void Caesar();
void Vigenere();
//Global variables:
string text;			//The text that will be encrypted
int keyCaesar;			//Key to encrypt or decrypt with Caesar method
string keyVigenere;		//Key to encrypt or decrypt with Vigenere method
int option;				//Encrypt or decrypt?

int main() {		
	int method;
	int op;

	//Enter text and select the optons: 
	do {
		do {
			cout << "Welcome to your encryption program.\n\nPlease select the wanted method:\n\t(1) Caesar\t(2) Vigenere\t: ";
			cin >> method;
		} while (method > 2 || method < 1);

		cout << "Enter the text: ";
		cin >> text;

		do {
			cout << "Options:\n\t(1) Encrypt\t(2) Decrypt\t: ";
			cin >> option;
		} while (option > 2 || option < 1);

		cout << "Enter key: ";
		(method == 1) ? (cin >> keyCaesar) : (cin >> keyVigenere);

		//Send the information to the 
		(method == 1) ? (Caesar()) : (Vigenere());
		//Print the result 
		do {
			cout << ((option == 1) ? ("Encrypted text: ") : ("Decrypted text: ")) << text << "\n\nOptions:\n (1) Use the program again\t(2) Exit\t: ";
			cin >> op;
		} while (op > 2 || op < 1);
	} while (op == 1);
		system("pause");
		return 0;
}

//Encryption and decryption with Caesar:
void Caesar() {
	string result;
	char aux;					//Auxiliary variable that saves the char in each iteration

	//Encryption and decryption in he same for:
	for (int i = 0; i < text.length(); i++) {
		aux = text[i];
		if (text[i] >= 'a' && text[i] <= 'z') {
			if (option == 1) {
				(text[i] + keyCaesar > 'z') ? (aux = aux + keyCaesar - 'z' + 'a' - 1) : (aux += keyCaesar);
			} 
			else {
				(text[i] - keyCaesar < 'a') ? (aux = aux - keyCaesar + 'z' - 'a' + 1) : (aux -= keyCaesar);
			}
		}
		else if (text[i] >= 'A' && text[i] <= 'Z') {
			if (option == 1) {
				(text[i] + keyCaesar > 'Z') ? (aux = aux + keyCaesar - 'Z' + 'A' - 1) : (aux += keyCaesar);
			}
			else {
				(text[i] - keyCaesar < 'A') ? (aux = aux - keyCaesar + 'Z' - 'A' + 1) : (aux -= keyCaesar);
			}
			
		}
		text[i] = aux;
	}
}

void Vigenere() {

	char aux;					//Auxiliary variable that saves the char in each iteration
	string temp;				//Auxiliary variable that saves the final text 

	//Encryption:
	if (option == 1) {
		for (int i = 0, j = 0; i < text.length(); ++i){
			aux = text[i];
			
			if (aux >= 'a' && aux <= 'z') {
				aux += 'A' - 'a';
			}
			else if (aux < 'A' || aux > 'Z') {
				continue;
			}
			temp += (aux + keyVigenere[j] - 2 * 'A') % 26 + 'A';
			j = (j + 1) % keyVigenere.length();
		}
	}
	//Decryption
	else {
		for (int i = 0, j = 0; i < text.length(); ++i){
			aux = text[i];
			
			if (aux >= 'a' && aux <= 'z') {
				aux += 'A' - 'a';
			}
			else if (aux < 'A' || aux > 'Z') {
				continue;
			}
			
			temp += (aux - keyVigenere[j] + 26) % 26 + 'A';

			j = (j + 1) % keyVigenere.length();
		}
	}

	text = temp;
}
