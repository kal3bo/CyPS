#include <iostream>
#include <string>

using namespace std;

class Cifrados{
    public: 
    string text;
    int option;

    void setText(string s){text = s;}
    void setOp(int o){option = o;}
    void print_text(){cout << text << endl;}
    virtual void cifra() = 0;
};

class Caesar : public Cifrados{
    public:
    int keyCaesar;

    void setKey(int k){keyCaesar = k;}
    void cifra(){
        char aux;
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
};

class Vigenere : public Cifrados{
    public:
    string keyVigenere;
    char aux;					//Auxiliary variable that saves the char in each iteration
	string temp;				//Auxiliary variable that saves the final text 

    void setKey(string k){keyVigenere = k;}
    void cifra(){
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
};
