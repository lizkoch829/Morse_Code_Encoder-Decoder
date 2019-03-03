#pragma once
#include "Morse_Node.h"
#include <string>

using namespace std;

class BSTree {
public:
    BSTree() { root = &root_node; };//a tree with one root node and a pointer to that node

    Morse_Node* root;
    Morse_Node root_node;//dummy node to act as root 



    void insert(Morse_Node& mn, int i)//takes in a node and an integer value of the length of that
        //node's code. This way nodes will be entered according to the code length 
    {

        string code = mn.morse_code;
        char l = mn.letter;
        Morse_Node* current;
        current = root;//start at root then branch right/left depending on dot or dash
        bool is_inserted = false;//sentinel
        for (int j = 1; j < (i + 1); j++)
        {
            if (is_inserted == true)
                return;
            else
            {
                if (j == i)//time to insert
                {
                    if (code[j-1] == '.') {//if char is . go left
                        current->left = new Morse_Node(code, l);
                        is_inserted = true;
                    }
                    else 
                    {
                        current->right = new Morse_Node(code, l);//otherwise go right
                        is_inserted = true;
                    }
                }
                else //continue branching left or right
                {
                    if (code[j-1] == '.')//go left
                        current = current->left;
                    else
                        current = current->right;
                }

            }
        }
    }

    char decode(string s) {
        //takes in a code string and finds it in the tree and returns the corresponding character
        Morse_Node* current;
        current = root;
        int i = s.size();//go to the level that the node is on (will match the size of code)
        for (int j = 0; j < i; j++)
        {
            if (s[j] == '.')//goes through the string branching left or right
                current = current->left;
            else
                current = current->right;
        }
        return current->letter;//once done iterating, return the letter
    }
    void encode_rec(char target, Morse_Node* p,string& s)
        //finds takes in a letter and finds the corresponding morse code, saves the code to 
        //a string, the wrapper function returns the string
    {
        if (p->letter == target)
            s= p->morse_code;
        
        else {
            if (p->left != nullptr) {
                encode_rec(target, p->left,s);
            }
            if (p->right != nullptr) {
                encode_rec(target, p->right,s);
            }


        }
    }
    string encode(char c)//wrapper
    {
        string s="";
        Morse_Node* current;
        current = root;
        encode_rec(c, current->right,s);//recursively search through tree
        encode_rec(c, current->left,s);
        return s;//return the code

    }
};
