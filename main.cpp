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
    return sourceCodeFile->eof();
}

void readNextLine()
{
    getline(*sourceCodeFile, line);

    currentCharIndex = 0;
}

void getChar()
{

    if (currentCharIndex == line.length()) {

        readNextLine();


    }
    //sort(line.begin(), line.end());

    currentChar =line.at(currentCharIndex);


    currentCharIndex++;




}

int main(int argc, char *argv[])
{
    if (argc < 2) {
        cout << "Please provide an input file." << endl;
        return 1;
    }
    currentChar = '\n';
    currentCharIndex = 0;
    line = "\n";
    sourceCodeFile = new ifstream();

    sourceCodeFile->open(argv[1], ifstream::in);

    if (sourceCodeFile->is_open())
    {
        //for(int i=0; i<= line.length();i++)
        while(!isEOF()) {
            for (int i = 0; i <= line.length(); i++) {
                getChar();
                if (currentChar != '\n') {
                    printf("%c\n", currentChar);
                }



            }
        }
    } else
    {
        printf("ERROR - cannot open input file \n");
    }
    return 0;
}
