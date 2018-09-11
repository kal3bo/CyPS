#include "AsciiArt.cc"

int main(){
    AsciiArt wolf, dog, coca, duck, lion, pig, bunny, rhino, sheep, snake;

    cout << wolf.Compress("cocaCola.art") << endl;
    cout << wolf.Decompress() << endl;
    return 0;
}