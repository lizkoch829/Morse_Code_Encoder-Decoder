//Program 2b
//Elizabeth Koch and Niloofar Oliaei
//11/30/2017




#include "Morse_Node.h"
#include "BSTree.h"
#include <string>
#include <iostream>
#include <fstream>
#include <map>



using namespace std;

int main() {

    BSTree  morse_tree;
    ifstream fin("morse.txt");
    ofstream fout("encodeoutput.txt");//this will have the output for the morse code
    map <string, char> Morse_Map;//map to keep track of codes and their letters



    while (fin.good())//read in letters
    {
        string line;
        getline(fin, line);
        char c = line[0];//gets the letter
        string s = line.substr(1);//gets the morse code
        Morse_Node temp(s, c);
        Morse_Map.insert(pair <string, char>(s, c));


    }
    for (int i = 1; i < 5; i++)//inserts nodes in order of length so tree matches the example
    {
        for (map<string, char>::iterator it = Morse_Map.begin(); it != Morse_Map.end(); ++it)
        {
            string code = it->first;
            char c = it->second;
            if (code.size() == i) {//if code is this length time to insert in tree
                Morse_Node mn(code, c);
                morse_tree.insert(mn,i);
            }
        }
    }
    string test = "helloworld";
    int j = test.size();
    for (int i = 0; i < j; i++)//iterates through string and encodes each letter
    {
        fout << morse_tree.encode(test[i])<<"   ";
    }
    fout << endl;
    ifstream fin2("encodeoutput.txt");//uses the previously encoded message to decode
    ofstream fout2("decodeoutput.txt");//the decoded result 

    string code;
    while (fin2.good())
    {
        
        if (fin2 >> code)
        fout2<< morse_tree.decode(code);//decode and send to file
    }
    



    return 0;
}