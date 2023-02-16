#include <fstream>
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

char currentChar;
int currentCharIndex;
ifstream *sourceCodeFile;
string line;

bool isEOF()
{
    return sourceCodeFile->eof() && currentCharIndex == line.size();
}

void readNextLine()
{
    getline(*sourceCodeFile, line);
    // line += '\n';
    currentCharIndex = 0;
}

void getChar()
{
    if (currentCharIndex == line.size())
    {
        readNextLine();
    }
    char currentChar = line[currentCharIndex] ;

    printf("%c\n", currentChar);
    //currentChar = printf("%c \n",currentChar1);
    currentCharIndex++;
}


int main(int argc, char *argv[])
{

    currentChar = '\n';
    currentCharIndex = 0;
    line = "\n";
    sourceCodeFile = new ifstream();

    sourceCodeFile->open(argv[1], ifstream::in);

    if (sourceCodeFile->is_open())
    {

        while(!isEOF()) {
            getChar();
            cout << currentChar ;


        }
    } else
    {
        printf("ERROR - cannot open input file \n");
    }
    return 0;
}
