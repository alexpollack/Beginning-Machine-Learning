#include <iostream>
#include <string>
#include <ctime>
#include <stdio.h>
#include <ctype.h>
#include <cstdlib>

using namespace std;

void caesar_sub(string orig, char alpha[], char *caesar);
void rndm(string orig, char alpha[], char *code);
void decode(string code, char alpha[], char *transcr);

int main()
{
    string message,method;
    srand((unsigned int)time(0));
    char alpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char ciph[26], choice;
    char * coded = new char[message.length()];
    char * transcr = new char[message.length()];
    
    cout << "Encrypt or decode a message? (e or d): ";
    getline(cin,method,'\n');
    if(method[0] == 'e' || method[0] == 'E')
    {
        cout << "\nEnter the message to encrypt: ";
        //cin >> original;
        getline(cin,message,'\n');
        cout << "Caesar or random substition? (c or r): ";
        cin >> choice;
        if(choice == 'c' || choice == 'C')
            caesar_sub(message,alpha,coded);
        else if(choice == 'r' || choice == 'R')
        {
            rndm(message,alpha,coded);
        }
    }
    else if(method[0] == 'd' || method[0] == 'D')
    {
        cout << "\nEnter the message to decode: ";
        getline(cin,message,'\n');
        decode(message,alpha,transcr);
    }
    else if(method[0] == '0')
        cout << "Exiting.";
    cout << endl;
    
    
    
    delete [] coded;
    delete [] transcr;
    
    return 0;
}

void decode(string code, char alpha[], char *transcr)
{
    char ciph[26];
    for(int i=0;i<26;i++)
    {
        if(i+3<=25)
            ciph[i] = alpha[i+3];
        else if(i+3>25)
            ciph[i] = alpha[i-23];
    }
    for(int i=0;i<code.length();i++)
    {
        for(int j=0;j<26;j++)
        {
            if( code[i] == ciph[j] )
                transcr[i] = alpha[j];
            else if( code[i] == ' ' )
                transcr[i] = ' ';
            else if( ispunct(code[i]) )
                transcr[i] = code[i];
        }
    }
    for(int i=0;i<40;i++)
        cout << '-';
    cout << "\nEncrypted message: " << code << "\nDecoded message: " << transcr << endl;
}

void rndm(string orig, char alpha[], char *code)
{
    char ciph[26], key;
    for(int i=0;i<26;i++)
    {
        ciph[i] = alpha[i];
    }
    for (int i=25; i>0; --i)
    {
        //get swap index
        int j = rand()%i;
        //swap p[i] with p[j]
        int temp = ciph[i];
        ciph[i] = ciph[j];
        ciph[j] = temp;
    }
    for(int i=0;i<orig.length();i++)
    {
        for(int j=0;j<26;j++)
        {
            if( orig[i] == alpha[j] )
                code[i] = ciph[j];
            else if( orig[i] == ' ' )
                code[i] = ' ';
            else if( ispunct(orig[i]) )
                code[i] = orig[i];
        }
    }
    cout << "Print out the key? (y or n): ";
    cin >> key;
    if(key == 'y' || key =='Y')
    {
        for(int i=0;i<113;i++)
            cout << '-';
        cout << "\nAlpha : | ";
        for(int i=0;i<26;i++)
            cout << alpha[i] << " | ";
        cout << "\nCipher: | ";
        for(int i=0;i<26;i++)
            cout << ciph[i] << " | ";
        cout << endl;
        for(int i=0;i<113;i++)
            cout << '-';
    }
    else if(key == 'n' || key =='n')
    {
        for(int i=0;i<40;i++)
            cout << '-';
    }
    cout << "\n-------------RANDOM CIPHER--------------\n";
    for(int i=0;i<40;i++)
        cout << '-';
    cout << "\nMessage: " << orig << "\nEncrypted message: " << code << endl;
}

void caesar_sub(string orig, char alpha[], char *caesar)
{
    char ciph[26],key;
    for(int i=0;i<26;i++)
    {
        if(i+3<=25)
            ciph[i] = alpha[i+3];
        else if(i+3>25)
            ciph[i] = alpha[i-23];
    }
    for(int i=0;i<orig.length();i++)
    {
        for(int j=0;j<26;j++)
        {
            if( orig[i] == alpha[j] )
                caesar[i] = ciph[j];
            else if(orig[i] == ' ')
                caesar[i] = ' ';
            else if( ispunct(orig[i]) )
                caesar[i] = orig[i];
        }
    }
    cout << "Print out the key? (y or n): ";
    cin >> key;
    if(key == 'y' || key =='Y')
    {
        for(int i=0;i<113;i++)
            cout << '-';
        cout << "\nAlpha : | ";
        for(int i=0;i<26;i++)
            cout << alpha[i] << " | ";
        cout << "\nCipher: | ";
        for(int i=0;i<26;i++)
            cout << ciph[i] << " | ";
        cout << endl;
        for(int i=0;i<113;i++)
            cout << '-';
    }
    else if(key == 'n' || key =='n')
    {
        for(int i=0;i<40;i++)
            cout << '-';
    }
    cout << "\n-------------CAESAR CIPHER--------------\n";
    for(int i=0;i<40;i++)
        cout << '-';
    cout << "\nMessage: " << orig << "\nEncrypted message: " << caesar << endl;
}










