/*Diego Kaleb Valenzuela Carrillo
                       A010189992
Notes: 
    The program doesn't accept ASCII images with " or ^ simbols. Neither numbers
    The first one has issues printing and the second one is used as a token for the next line.
    - Coca Cola logo has problems on purpose
*/

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class AsciiArt{
    public:
    string compressResult;
    string Compress(string imageName);
    string Decompress();
    int isNumber(char c);
};

string AsciiArt::Compress(string imageName){
    char token = '^';
    //string compressResult; 
    string line;
    ifstream file_(imageName);
    if(file_.is_open()){
        while(getline(file_, line)){
            compressResult.push_back(token);
            char thisChar = line[0];
            int counter = 1;
            for(int i = 1; i <= line.length(); i++){
                if(line[i] == thisChar){
                    counter++;
                }
                else{
                    compressResult += to_string(counter);
                    compressResult.push_back(thisChar);
                    thisChar = line[i];
                    counter = 1;
                }
            }
        }
        file_.close();
    }
    else{
        cout << "The image is not on the library";
    }
    return compressResult;
}
string AsciiArt::Decompress(){
    string compressedText = compressResult;
    string result = "";
    int counter;
    char thisChar;
    string aux;

    for (int i = 1; i <= compressedText.length(); i++){
        if (compressedText[i] == '^'){
            result += "\n";
        }
        else{
            //Is the next char a number too?
            if(isNumber(compressedText[i + 1]) == 1){
                aux = "";
                aux.push_back(compressedText[i]);
                aux.push_back(compressedText[i + 1]);
                counter = stoi(aux);
                i += 2;
            }
            else{
                counter = int(compressedText[i]);
                counter -= 48;
                i++;
            }
            thisChar = compressedText[i];
            for (int j = 0; j < counter; j++){
                result.push_back(thisChar);
            }
        }
    }
    return result;
}
int AsciiArt::isNumber(char c){
    if (c == '0' || c == '1' || c == '2' || c == '3' || c == '4' || c == '5' || c == '6' || c == '7' || c == '8' || c == '9'){
        return 1;
    }
    else{
        return 0;
    }
}
