#include <iostream>
#include <string>
#include <ctime>
#include <stdio.h>
#include <ctype.h>
#include <cstdlib>

using namespace std;

//encrypt
void caesar_sub(string orig, char alpha[], char *caesar);
void rndm(string orig, char alpha[], char *code);
void n_shift_caesar_sub(string orig, char alpha[], char *caesar);
void atbash(string orig, char alpha[], char *code);
//decrypt
void decode(string code, char alpha[], char *transcr);
void atbash_decode(string code, char alpha[], char *transcr);
void n_shift_decode(string code, char alpha[], char *transcr);

int main()
{
    string message,method;
    srand((unsigned int)time(0));
    char alpha[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    char choice, choice2;
    char * coded = new char[message.length()];
    char * transcr = new char[message.length()];
    
    cout << "Encrypt or decode a message? (e or d): ";
    getline(cin,method,'\n');
    if(method[0] == 'e' || method[0] == 'E')
    {
        cout << "\nEnter the message to encrypt: ";
        //cin >> original;
        getline(cin,message,'\n');
        cout << "Caesar, N-shift, Atbash, random, or all? (c, s, h, r, or a): ";
        cin >> choice;
        if(choice == 'c' || choice == 'C')
            caesar_sub(message,alpha,coded);
        else if(choice == 'r' || choice == 'R')
        {
            rndm(message,alpha,coded);
        }
        else if(choice == 's' || choice == 'S')
        {
            n_shift_caesar_sub(message,alpha,coded);
        }
        else if(choice == 'h' || choice == 'h')
        {
            atbash(message,alpha,coded);
        }
        else if(choice == 'a' || choice == 'A')
        {
            n_shift_caesar_sub(message,alpha,coded);
            caesar_sub(message,alpha,coded);
            rndm(message,alpha,coded);
            atbash(message,alpha,coded);
        }
    }
    else if(method[0] == 'd' || method[0] == 'D')
    {
        cout << "\nEnter the message to decode: ";
        getline(cin,message,'\n');
        cout << "Caesar, n_Caesar substition, or Atbash? (c, n, or h): ";
        cin >> choice2;
        if(choice2 == 'c' || choice == 'C')
            decode(message,alpha,transcr);
        else if(choice2 == 'n' || choice == 'N')
            n_shift_decode(message,alpha,transcr);
        else if(choice2 == 'h' || choice == 'H')
            atbash_decode(message,alpha,transcr);
    }
    else if(method[0] == '0')
        cout << "Exiting.";
    cout << endl;
    
    
    
    delete [] coded;
    delete [] transcr;
    
    return 0;
}

void atbash_decode(string code, char alpha[], char *transcr)
{
    char ciph[26],key;
    int j=25;
    
    for(int i=0;i<26;i++)
    {
        ciph[i] = alpha[j];
        j--;
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
    cout << "\n-------------ATBASH CIPHER--------------\n";
    for(int i=0;i<40;i++)
        cout << '-';
    cout << "\nEncrypted message: " << code << "\nDecoded message: " << transcr << endl;
}

void atbash(string orig, char alpha[], char *code)
{
    char ciph[26],key;
    int j=25;
    
    for(int i=0;i<26;i++)
    {
        ciph[i] = alpha[j];
        j--;
    }
    for(int i=0;i<orig.length();i++)
    {
        for(int j=0;j<26;j++)
        {
            if( orig[i] == alpha[j] )
                code[i] = ciph[j];
            else if(orig[i] == ' ')
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
    cout << "\n-------------ATBASH CIPHER--------------\n";
    for(int i=0;i<40;i++)
        cout << '-';
    cout << "\nMessage: " << orig << "\nEncrypted message: " << code << endl;
}

void n_shift_caesar_sub(string orig, char alpha[], char *caesar)
{
    char ciph[26],key;
    int n;
    cout << "Caesar cipher shifting how many places?\nn = ";
    cin >> n;
    
    for(int i=0;i<26;i++)
    {
        if(i+n<=25)
            ciph[i] = alpha[i+n];
        else if(i+n>25)
            ciph[i] = alpha[i-(26-n)];
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
    cout << "\n---------N SHIFT CAESAR CIPHER----------\n";
    for(int i=0;i<40;i++)
        cout << '-';
    cout << "\nMessage: " << orig << "\nEncrypted message: " << caesar << endl;
}

void n_shift_decode(string code, char alpha[], char *transcr)
{
    char ciph[26], key;
    int spaces;
    for(int i=0;i<40;i++)
        cout << '-';
    cout << "\n-------------CAESAR CIPHER--------------\n";
    for(int i=0;i<40;i++)
        cout << '-';
    cout << "\n\nEncrypted message: " << code << endl << endl;
    for(int n=0;n<26;n++)
    {
        for(int i=0;i<26;i++)
        {
            if(i+n<=25)
                ciph[i] = alpha[i+n];
            else if(i+n>25)
                ciph[i] = alpha[i-(26-n)];
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
        cout << "\nDecoded message shifted " << n << " spaces: " << transcr << endl;
    }
    cout << "Print out the key? (y or n): ";
    cin >> key;
    if(key == 'y' || key =='Y')
    {
        cout << "Print key for cipher shifted how many spaces?: ";
        cin >> spaces;
        for(int i=0;i<26;i++)
        {
            if(i+spaces<=25)
                ciph[i] = alpha[i+spaces];
            else if(i+spaces>25)
                ciph[i] = alpha[i-(26-spaces)];
        }
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
        cout << endl;
    }
}

void decode(string code, char alpha[], char *transcr)
{
    char ciph[26], key;
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










