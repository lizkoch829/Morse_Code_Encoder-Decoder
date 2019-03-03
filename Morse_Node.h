#pragma once
#include <string>


using namespace std;

class Morse_Node {
public:
    string morse_code;// the dot/dash code associated with the letter
    char letter;//the letter represented by the code
    Morse_Node* left;
    Morse_Node* right;
    Morse_Node::Morse_Node() {morse_code="?",letter='z', left = nullptr, right = nullptr; }
    Morse_Node::Morse_Node(string s, char c) { morse_code = s, letter = c, left=nullptr,right=nullptr; }

    void Morse_Node::operator = (Morse_Node& rhs)
    {
        rhs.morse_code = morse_code;
        rhs.letter = letter;
        rhs.left = left;
        rhs.right = right;
    }

    bool Morse_Node::operator ==(const Morse_Node& rhs)
    {
        return morse_code == rhs.morse_code;
    }

    bool Morse_Node::operator < (const Morse_Node& rhs)
    {
        
        return morse_code < rhs.morse_code;
    }
    bool Morse_Node::operator > (const Morse_Node& rhs)
    {
        return morse_code > rhs.morse_code;
    }
};
