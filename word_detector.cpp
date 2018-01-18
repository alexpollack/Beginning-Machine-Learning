//
//  main.cpp
//  word_detection
//
//  Created by Alex Pollack on 7/18/17.
//  Copyright © 2017 Alex Pollack. All rights reserved.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cctype>
#include <string>
#include <cstdlib>
#include <fstream>
#include <ctype.h>
#include <stdio.h>

using namespace std;

int main()
{
    cout << "Reading files, training.\n";
    //character alphabet upper and lower
    char alpha[] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'},alphaUp[26];
    for( int i = 0; i < 26; i++ )
        alphaUp[i] = toupper(alpha[i]);
    
    //track the number of each alpha characters occurences, initialized
    int alphaOccur[26], alphaUpOccur[26],alphaLowOccur[26];
    double alphaProb[26], alphaProbOrder[26];
    for( int i=0; i < 26; i++ )
    {
        alphaOccur[i] = 0;
        alphaUpOccur[i] = 0;
        alphaLowOccur[i] = 0;
    }
    //alpha character neighbor tracking
    int alphaNeighbor[26][26], alphaNeighborLeft[26][26];
    string lineRead;
    for( int i = 0; i < 26; i++ )
    {
        for( int j = 0; j < 26; j++ )
        {
            alphaNeighbor[i][j] = 0;
            alphaNeighborLeft[i][j] = 0;
        }
    }
    
    //numeric digits 0-1 and their occurences
    int numeric[] = {0,1,2,3,4,5,6,7,8,9}, numOccur[10];
    for( int i=0; i < 10; i++ )
        numOccur[i] = 0;
    
    //punctuation characters and their occurences
    char punct[] = { '.',',','?','!',':',';','-','/','(',')','[',']','{','}','\"','\''};
    int punctOccur[16];
    for( int i=0; i < 16; i++ )
        punctOccur[i] = 0;
    
    //track the total alphanumeric and punctuation character count
    double totalChar = 0;
    
    ifstream fileIn;
    //access files for text reference
    for( int j = 0; j < 21; j++)
    {
        if( j == 0)
            fileIn.open("christmas_eve_day.txt");
        else if( j == 1)
            fileIn.open("the_bet.txt");
        else if( j == 2)
            fileIn.open("the_doll_house.txt");
        else if( j == 3)
            fileIn.open("the_dreamer.txt");
        else if( j == 4)
            fileIn.open("the_looking_glass.txt");
        else if( j == 5)
            fileIn.open("the_selfish_giant.txt");
        else if( j == 6)
            fileIn.open("the_tale_of_peter_rabbit.txt");
        else if( j == 7)
            fileIn.open("the_brave_tin_solider.txt");
        else if( j == 8)
            fileIn.open("a_dark_brown_dog.txt");
        else if( j == 9)
            fileIn.open("the_call_of_cthulhu.txt");
        else if( j == 10)
            fileIn.open("to_build_a_fire.txt");
        else if( j == 11)
            fileIn.open("a_respectable_woman.txt");
        else if( j == 12)
            fileIn.open("my_financial_career.txt");
        else if( j == 13)
            fileIn.open("a_blunder.txt");
        else if( j == 14)
            fileIn.open("one_summer_night.txt");
        else if( j == 15)
            fileIn.open("an_occurence_at_owl_creek_bridge.txt");
        else if( j == 16)
            fileIn.open("the_skylight_room.txt");
        else if( j == 17)
            fileIn.open("a_baby_tramp.txt");
        else if( j == 18)
            fileIn.open("the_death_of_a_government_clerk.txt");
        else if( j == 19)
            fileIn.open("fat_and_thin.txt");
        else if( j == 20)
            fileIn.open("the_aged_mother.txt");
        while( !fileIn.eof())
        {
            //check alphas
            if( isalpha(fileIn.peek()) )
            {
                if( isupper(fileIn.peek()) || islower(fileIn.peek()) )
                {
                    for( int i = 0; i < 26; i++ )
                    {
                        //collectively count upper and lower for simplicity purposes
                        if( fileIn.peek() == alpha[i] || fileIn.peek() == alphaUp[i] )
                            alphaOccur[i] = alphaOccur[i] + 1;
                        if( fileIn.peek() == alpha[i] )
                            alphaLowOccur[i] = alphaLowOccur[i] + 1;
                        if( fileIn.peek() == alphaUp[i] )
                            alphaUpOccur[i] = alphaUpOccur[i] + 1;
                    }
                }
                totalChar = totalChar + 1;
            }
            else if( isdigit(fileIn.peek()) )
            {
                //check numerics
                for( int i = 0; i < 10; i++ )
                {
                    if( fileIn.peek() == numeric[i] )
                        numOccur[i] = numOccur[i] + 1;
                }
                totalChar = totalChar + 1;
            }
            else if(ispunct(fileIn.peek()))
            {
                //check punctuations
                for(int i = 0; i < 16; i++)
                {
                    if( fileIn.peek() == punct[i] )
                        punctOccur[i] = punctOccur[i] + 1;
                }
                totalChar = totalChar + 1;
            }
            fileIn.ignore(1);
        }
        fileIn.close();
    }
    char alphaOrder[26], alphaTemp;
    
    //find the probability of each letter in a charactor libary of the input files size
    for( int i = 0; i < 26; i++)
    {
        alphaProb[i] = (alphaOccur[i] / totalChar) * 100;
    }
    for(int i = 0; i < 26; i++)
    {
        alphaProbOrder[i] = alphaProb[i];
        alphaOrder[i] = alpha[i];
    }
    double temp;
    for( int i = 0; i < 25; ++i )
    {
        for( int j = 0; j < 25; ++j)
        {
            if( alphaProbOrder[j] > alphaProbOrder[j+1] )
            {
                temp = alphaProbOrder[j+1];
                alphaProbOrder[j+1] = alphaProbOrder[j];
                alphaProbOrder[j] = temp;
                
                alphaTemp = alphaOrder[j+1];
                alphaOrder[j+1] = alphaOrder[j];
                alphaOrder[j] = alphaTemp;
                
            }
        }
    }
    cout << endl << "Probabilities greatest to least:\n";
    for(int i = 0;i < 26; i++)
    {
        cout << alphaProbOrder[i] << " | " << alphaOrder[i] << endl;
    }
    
    for( int j = 0; j < 21; j++)
    {
        if( j == 0)
            fileIn.open("christmas_eve_day.txt");
        else if( j == 1)
            fileIn.open("the_bet.txt");
        else if( j == 2)
            fileIn.open("the_doll_house.txt");
        else if( j == 3)
            fileIn.open("the_dreamer.txt");
        else if( j == 4)
            fileIn.open("the_looking_glass.txt");
        else if( j == 5)
            fileIn.open("the_selfish_giant.txt");
        else if( j == 6)
            fileIn.open("the_tale_of_peter_rabbit.txt");
        else if( j == 7)
            fileIn.open("the_brave_tin_solider.txt");
        else if( j == 8)
            fileIn.open("a_dark_brown_dog.txt");
        else if( j == 9)
            fileIn.open("the_call_of_cthulhu.txt");
        else if( j == 10)
            fileIn.open("to_build_a_fire.txt");
        else if( j == 11)
            fileIn.open("a_respectable_woman.txt");
        else if( j == 12)
            fileIn.open("my_financial_career.txt");
        else if( j == 13)
            fileIn.open("a_blunder.txt");
        else if( j == 14)
            fileIn.open("one_summer_night.txt");
        else if( j == 15)
            fileIn.open("an_occurence_at_owl_creek_bridge.txt");
        else if( j == 16)
            fileIn.open("the_skylight_room.txt");
        else if( j == 17)
            fileIn.open("a_baby_tramp.txt");
        else if( j == 18)
            fileIn.open("the_death_of_a_government_clerk.txt");
        else if( j == 19)
            fileIn.open("fat_and_thin.txt");
        else if( j == 20)
            fileIn.open("the_aged_mother.txt");
        while( !fileIn.eof())
        {
            getline( fileIn, lineRead, '.');
            for( int i = 0; i < lineRead.length(); i++ )
            {
                //scroll through the letters in the string
                for( int k = 0; k < 26; k++ )
                {
                    //identify that characters value as an alpha character

                    if( i == 0 )
                    {
                        if( lineRead[i] == alpha[k] || lineRead[i] == alphaUp[k])
                        {
                            for( int l = 0; l < 26; l++)
                            {
                                if( lineRead[i+1] == alpha[l] || lineRead[i+1] == alphaUp[l] )
                                    alphaNeighbor[k][l] = alphaNeighbor[k][l] + 1;
                            }
                        }
                    }
                    else if( i >= 1 && i < lineRead.length() - 1 )
                    {
                        if( lineRead[i] == alpha[k] || lineRead[i] == alphaUp[k] )
                        {
                            for( int l = 0; l < 26; l++)
                            {
                                if( lineRead[i+1] == alpha[l] || lineRead[i+1] == alphaUp[l] )
                                    alphaNeighbor[k][l] = alphaNeighbor[k][l] + 1;
                                if( lineRead[i-1] == alpha[l] || lineRead[i-1] == alphaUp[l] )
                                    alphaNeighborLeft[k][l] = alphaNeighborLeft[k][l] + 1;
                            }
                        }
                        
                    }
                    else if( i == (lineRead.length() - 1) )
                    {
                        for( int l = 0; l < 26; l++ )
                        {
                            if( lineRead[i] == alpha[l] || lineRead[i] == alphaUp[l] )
                                alphaNeighborLeft[k][l] = alphaNeighborLeft[k][l] + 1;
                        }
                    }
                }
            }
        }
        fileIn.close();
    }
    cout << "Train complete. There were " << totalChar << " total characters counted\n";
    for( int i = 0; i < 25; i++ )
        cout << '-';
    cout << endl;
    for( int i = 0; i < 26; i++ )
        cout << alpha[i] << ": " << alphaLowOccur[i] << " lower, " << alphaUpOccur[i] << " upper, and " << alphaOccur[i] << " total occurences.\n";
    for( int i = 0; i < 25; i++ )
        cout << '-';
    cout << "\nThe probability of occurence.\n";
    for( int i = 0; i < 26; i++ )
         cout << alphaUp[i] << " | " << alphaProb[i] << "%\n";
    for( int i = 0; i < 25; i++ )
        cout << '-';
    cout << endl;
    for( int i = 0; i < 16; i++ )
        cout << punct[i] << " : " << punctOccur[i] << " total occurences.\n";
    for( int i = 0; i < 25; i++ )
        cout << '-';
    cout << endl;
    for( int i = 0; i < 10; i++ )
        cout << numeric[i] << ": " << numOccur[i] << " total occurences.\n";
    for( int i = 0; i < 25; i++ )
        cout << '-';
    cout << endl << '\t';
    cout << "\nAlpha right hand neighbor occurences.\n\t";

    for( int i = 0; i < 26; i++ )
        cout << alphaUp[i] << '\t';
    cout << endl;
    for( int i = 0; i < 26; i++)
    {
        cout << alphaUp[i] << "|\t";
        for( int j = 0; j < 26; j++ )
        {
            cout << alphaNeighbor[i][j] << '\t';
        }
        cout << endl;
    }
    cout << "\nAlpha left hand neighbor occurences.\n\t";
    for( int i = 0; i < 26; i++ )
        cout << alphaUp[i] << '\t';
    cout << endl;
    for( int i = 0; i < 26; i++)
    {
        cout << alphaUp[i] << "|\t";
        for( int j = 0; j < 26; j++ )
        {
            cout << alphaNeighborLeft[i][j] << '\t';
        }
        cout << endl;
    }
    
    /*
     * file code identification
    */
    
    //track the number of each alpha characters occurences, initialized
    int alphaCryptOccur[26], alphaUpCryptOccur[26],alphaLowCryptOccur[26];
    double alphaCryptProb[26];
    for( int i=0; i < 26; i++ )
    {
        alphaCryptOccur[i] = 0;
        alphaUpCryptOccur[i] = 0;
        alphaLowCryptOccur[i] = 0;
    }
    //alpha character neighbor tracking
    int alphaCryptNeighbor[26][26], alphaCryptNeighborLeft[26][26];
    for( int i = 0; i < 26; i++ )
    {
        for( int j = 0; j < 26; j++ )
        {
            alphaCryptNeighbor[i][j] = 0;
            alphaCryptNeighborLeft[i][j] = 0;
        }
    }
    
    //numeric digits 0-1 and their occurences
    int numCryptOccur[10];
    for( int i=0; i < 10; i++ )
        numCryptOccur[i] = 0;
    
    //punctuation characters and their occurences
    int punctCryptOccur[16];
    for( int i=0; i < 16; i++ )
        punctCryptOccur[i] = 0;
    
    //track the total alphanumeric and punctuation character count
    double totalCryptChar = 0;
    
    string fileName;
    ifstream cryptFileIn;
    char ans;
    cout << "\nWould you like to decode a file? (y or n): ";
    cin >> ans;
    if( ans == 'y' || ans == 'Y')
    {
        cout << "Name of the file to open: ";
        cin >> fileName;
        cryptFileIn.open(fileName);
        while( !cryptFileIn.eof())
        {
            //check alphas
            if( isalpha(cryptFileIn.peek()) )
            {
                if( isupper(cryptFileIn.peek()) || islower(cryptFileIn.peek()) )
                {
                    for( int i = 0; i < 26; i++ )
                    {
                        //collectively count upper and lower for simplicity purposes
                        if( cryptFileIn.peek() == alpha[i] || cryptFileIn.peek() == alphaUp[i] )
                            alphaCryptOccur[i] = alphaCryptOccur[i] + 1;
                        if( cryptFileIn.peek() == alpha[i] )
                            alphaLowCryptOccur[i] = alphaLowCryptOccur[i] + 1;
                        if( cryptFileIn.peek() == alphaUp[i] )
                            alphaUpCryptOccur[i] = alphaUpCryptOccur[i] + 1;
                    }
                }
                totalCryptChar = totalCryptChar + 1;
            }
            else if( isdigit(cryptFileIn.peek()) )
            {
                //check numerics
                for( int i = 0; i < 10; i++ )
                {
                    if( cryptFileIn.peek() == numeric[i] )
                        numCryptOccur[i] = numCryptOccur[i] + 1;
                }
                totalCryptChar = totalCryptChar + 1;
            }
            else if(ispunct(cryptFileIn.peek()))
            {
                //check punctuations
                for(int i = 0; i < 16; i++)
                {
                    if( cryptFileIn.peek() == punct[i] )
                        punctCryptOccur[i] = punctCryptOccur[i] + 1;
                }
                totalCryptChar = totalCryptChar + 1;
            }
            cryptFileIn.ignore(1);
        }
        cryptFileIn.close();
        
        ///////////////////////
        cryptFileIn.open(fileName);
        while( !cryptFileIn.eof())
        {
            getline( cryptFileIn, lineRead, '.');
            for( int i = 0; i < lineRead.length(); i++ )
            {
                //scroll through the letters in the string
                for( int k = 0; k < 26; k++ )
                {
                    //identify that characters value as an alpha character
                    
                    if( i == 0 )
                    {
                        if( lineRead[i] == alpha[k] || lineRead[i] == alphaUp[k])
                        {
                            for( int l = 0; l < 26; l++)
                            {
                                if( lineRead[i+1] == alpha[l] || lineRead[i+1] == alphaUp[l] )
                                    alphaCryptNeighbor[k][l] = alphaCryptNeighbor[k][l] + 1;
                            }
                        }
                    }
                    else if( i >= 1 && i < lineRead.length() - 1 )
                    {
                        if( lineRead[i] == alpha[k] || lineRead[i] == alphaUp[k] )
                        {
                            for( int l = 0; l < 26; l++)
                            {
                                if( lineRead[i+1] == alpha[l] || lineRead[i+1] == alphaUp[l] )
                                    alphaCryptNeighbor[k][l] = alphaCryptNeighbor[k][l] + 1;
                                if( lineRead[i-1] == alpha[l] || lineRead[i-1] == alphaUp[l] )
                                    alphaCryptNeighborLeft[k][l] = alphaCryptNeighborLeft[k][l] + 1;
                            }
                        }
                        
                    }
                    else if( i == (lineRead.length() - 1) )
                    {
                        for( int l = 0; l < 26; l++ )
                        {
                            if( lineRead[i] == alpha[l] || lineRead[i] == alphaUp[l] )
                                alphaCryptNeighborLeft[k][l] = alphaCryptNeighborLeft[k][l] + 1;
                        }
                    }
                }
            }
        }
        cryptFileIn.close();
        
        ////////////////////
        
        
        //find the probability of each letter in a charactor libary of the input files size
        for( int i = 0; i < 26; i++)
        {
            alphaCryptProb[i] = (alphaCryptOccur[i] / totalCryptChar) * 100;
        }
        double alphaCryptProbOrder[26];
        char alphaCryptOrder[26];
        for(int i = 0; i < 26; i++)
        {
            alphaCryptProbOrder[i] = alphaCryptProb[i];
            alphaCryptOrder[i] = alpha[i];
        }
        for( int i = 0; i < 25; ++i )
        {
            for( int j = 0; j < 25; ++j)
            {
                if( alphaCryptProbOrder[j] > alphaCryptProbOrder[j+1] )
                {
                    temp = alphaCryptProbOrder[j+1];
                    alphaCryptProbOrder[j+1] = alphaCryptProbOrder[j];
                    alphaCryptProbOrder[j] = temp;
         
                    alphaTemp = alphaCryptOrder[j+1];
                    alphaCryptOrder[j+1] = alphaCryptOrder[j];
                    alphaCryptOrder[j] = alphaTemp;
                }
            }
        }
        
         cout << endl << "Probabilities greatest to least:\n";
         for(int i = 0;i < 26; i++)
         {
             cout << alphaCryptProbOrder[i] << " | " << alphaCryptOrder[i] << endl;
         }
        for( int i = 0; i < 25; i++ )
            cout << '-';
        cout << endl;
        for( int i = 0; i < 26; i++ )
            cout << alpha[i] << ": " << alphaLowCryptOccur[i] << " lower, " << alphaUpCryptOccur[i] << " upper, and " << alphaCryptOccur[i] << " total occurences.\n";
        for( int i = 0; i < 25; i++ )
            cout << '-';
        cout << "\nThe probability of occurence.\n";
        for( int i = 0; i < 26; i++ )
            cout << alphaUp[i] << " | " << alphaCryptProb[i] << "%\n";
        for( int i = 0; i < 25; i++ )
            cout << '-';
        cout << endl;
        for( int i = 0; i < 16; i++ )
            cout << punct[i] << " : " << punctCryptOccur[i] << " total occurences.\n";
        for( int i = 0; i < 25; i++ )
            cout << '-';
        cout << endl;
        for( int i = 0; i < 10; i++ )
            cout << numeric[i] << ": " << numCryptOccur[i] << " total occurences.\n";
        for( int i = 0; i < 25; i++ )
            cout << '-';
        cout << endl << '\t';
        
        cout << "Comparing the encrypted file to a text base the cipher is:\n";
        for(int i = 0; i < 26; i++)
        {
            cout << alphaOrder[i] << " | " << alphaCryptOrder[i] << endl;
        }
        cout << endl << '\t';
        cout << "\nAlpha right hand neighbor occurences.\n\t";
        
        for( int i = 0; i < 26; i++ )
            cout << alphaUp[i] << '\t';
        cout << endl;
        for( int i = 0; i < 26; i++)
        {
            cout << alphaUp[i] << "|\t";
            for( int j = 0; j < 26; j++ )
            {
                cout << alphaCryptNeighbor[i][j] << '\t';
            }
            cout << endl;
        }
        cout << "\nAlpha left hand neighbor occurences.\n\t";
        for( int i = 0; i < 26; i++ )
            cout << alphaUp[i] << '\t';
        cout << endl;
        for( int i = 0; i < 26; i++)
        {
            cout << alphaUp[i] << "|\t";
            for( int j = 0; j < 26; j++ )
            {
                cout << alphaCryptNeighborLeft[i][j] << '\t';
            }
            cout << endl;
        }
    }
    else
        cout << "Ending.\n";

    return 0;
}



