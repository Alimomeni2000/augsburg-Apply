#include <iostream>
#include "conio.h"
#include <stdio.h>
#include <cmath>
#include "termcolor.hpp"

using namespace std;

//introducing functions
void add_remove();

void addnew_word();

void playgame();

void remove_w_s();

char statusword(int);

void start_esay_game();

void start_medium_game();

void start_hard_game();

void gameover(int);

int fault1(char);

int input;
int Gem = 3;
int fault = 0;
char new_word_array1[19][14];
char sentence[19][100];
int num = 0;

void lenght(char string[15]);


int main() {
    while (1) {
        system("clear");
        cout << termcolor::italic;
        cout << "1-Add/Remove word and sentence." << endl;
        cout << "2-Play game." << endl;
        cout << "0-Exit Program" << endl;
        cout << "Enter a number =>";
        cout << termcolor::reset;
        cin >> input;
        //switch function main
        switch (input) {
            case 1:
                add_remove();
                break;
            case 2:
                playgame();
                break;
            case 0: return 0;
                break;

        }
    }
    //end switch function main
}//end main

// function  add and remove word and sentence
void add_remove() {
    while (1) {
        system("clear");
        cout << termcolor::italic;
        cout << "1-add new word" << endl;
        cout << "2-Remove word and sentence" << endl;
        cout << "0-Return menu" << endl;
        cout << "Enter your Choice Number =>";
        cout << termcolor::reset;
        cin >> input;
        //switch function add_remove
        switch (input) {
            case 1:
                addnew_word();
                break;
            case 2:
                remove_w_s();
                break;
            case 0:
                main();
                return;
        }//end switch function add_remove
    }
}//end function add_remove

//function add new word
void addnew_word() {

    while (1) {
        cout << termcolor::italic;
        cout << "Do you add a new word? [y/n]" << endl;
        char inputchar;
        cin >> inputchar;
        if (inputchar == 'y') {
            system("clear");
            for (int i = 0; i < 20; i++) {
                if (new_word_array1[i][0] == NULL || new_word_array1[i][0] == ' ')
                    continue;
                if (sentence[i][0] == ' ' || sentence[i][0] == NULL)
                    continue;
                cout << i + 1 << "-" << endl;
                cout << "word " << " : " << new_word_array1[i] << endl;
                cout << "description : " << sentence[i] << endl;
                cout << "status : ";
                int status = statusword(i);
                if (status > 0 && status <= 10) {
                    cout << termcolor::cyan << "esay\n" << termcolor::reset;

                } else if (status <= 20 && status > 10) {
                    cout << termcolor::yellow << "medium\n" << termcolor::reset;
                } else if (status > 20) {
                    cout << termcolor::red << "hard\n" << termcolor::reset;
                }
            }
            cout << "To add a new word, select one of the numbers between 1 and 20";
            cout << "\nPress < 0 > to return to the previous menu" << endl;
            cout << "Enter your Choice Number =>";
            int tekrar = 0;
            cin >> input;
            int ali = 0;
//switch function addnew_word
            switch (input) {
                case 1:
                    cout << "Enter the word you want '1' " << endl;
                    cin.getline(new_word_array1[0], sizeof(new_word_array1[0]));
                    cin.getline(new_word_array1[0], sizeof(new_word_array1[0]));
                    cout << "Enter the sentence '1' you want" << endl;
                    cin.getline(sentence[0], sizeof(sentence[0]));
                    addnew_word();
                    break;
                case 2:
                    cout << "Enter the word you want '2'" << endl;
                    cin.getline(new_word_array1[1], sizeof(new_word_array1[1]));
                    cin.getline(new_word_array1[1], sizeof(new_word_array1[1]));
                    cout << "Enter the sentence '2' you want" << endl;
                    cin.getline(sentence[1], sizeof(sentence[1]));
                    addnew_word();
                    break;
                case 3:
                    cout << "Enter the word you want '3'" << endl;
                    cin.getline(new_word_array1[2], sizeof(new_word_array1[2]));
                    cin.getline(new_word_array1[2], sizeof(new_word_array1[2]));

                    cout << "Enter the sentence '3' you want" << endl;
                    cin.getline(sentence[2], sizeof(sentence[2]));
                    addnew_word();
                    break;
                case 4:
                    cout << "Enter the word you want '4'" << endl;
                    cin.getline(new_word_array1[3], sizeof(new_word_array1[3]));
                    cin.getline(new_word_array1[3], sizeof(new_word_array1[3]));

                    cout << "Enter the sentence '4' you want" << endl;
                    cin.getline(sentence[3], sizeof(sentence[3]));
                    addnew_word();
                    break;
                case 5:
                    cout << "Enter the word you want '5'" << endl;
                    cin.getline(new_word_array1[4], sizeof(new_word_array1[4]));
                    cin.getline(new_word_array1[4], sizeof(new_word_array1[4]));

                    cout << "Enter the sentence '5' you want" << endl;
                    cin.getline(sentence[4], sizeof(sentence[4]));
                    addnew_word();
                    break;
                case 6:
                    cout << "Enter the word you want '6'" << endl;
                    cin.getline(new_word_array1[5], sizeof(new_word_array1[5]));
                    cin.getline(new_word_array1[5], sizeof(new_word_array1[5]));
                    cout << "Enter the sentence '6' you want" << endl;
                    cin.getline(sentence[5], sizeof(sentence[5]));
                    addnew_word();
                    break;
                case 7:
                    cout << "Enter the word you want '7'" << endl;
                    cin.getline(new_word_array1[6], sizeof(new_word_array1[6]));
                    cin.getline(new_word_array1[6], sizeof(new_word_array1[6]));
                    cout << "Enter the sentence '7' you want" << endl;
                    cin.getline(sentence[6], sizeof(sentence[6]));
                    addnew_word();
                    break;
                case 8:
                    cout << "Enter the word you want '8'" << endl;
                    cin.getline(new_word_array1[7], sizeof(new_word_array1[7]));
                    cin.getline(new_word_array1[7], sizeof(new_word_array1[7]));
                    cout << "Enter the sentence '8' you want" << endl;
                    cin.getline(sentence[7], sizeof(sentence[7]));
                    addnew_word();
                    break;
                case 9:
                    cout << "Enter the word you want '9'" << endl;
                    cin.getline(new_word_array1[8], sizeof(new_word_array1[8]));
                    cin.getline(new_word_array1[8], sizeof(new_word_array1[8]));
                    cout << "Enter the sentence '9' you want" << endl;
                    cin.getline(sentence[8], sizeof(sentence[8]));
                    addnew_word();
                    break;
                case 10:
                    cout << "Enter the word you want '10'" << endl;
                    cin.getline(new_word_array1[9], sizeof(new_word_array1[9]));
                    cin.getline(new_word_array1[9], sizeof(new_word_array1[9]));
                    cout << "Enter the sentence '10' you want" << endl;
                    cin.getline(sentence[9], sizeof(sentence[9]));
                    addnew_word();
                    break;
                case 11:
                    cout << "Enter the word you want '11'" << endl;
                    cin.getline(new_word_array1[10], sizeof(new_word_array1[1]));
                    cin.getline(new_word_array1[10], sizeof(new_word_array1[1]));
                    cout << "Enter the sentence '11' you want" << endl;
                    cin.getline(sentence[10], sizeof(sentence[1]));
                    addnew_word();
                    break;
                case 12:
                    cout << "Enter the word you want '12'" << endl;
                    cin.getline(new_word_array1[11], sizeof(new_word_array1[11]));
                    cin.getline(new_word_array1[11], sizeof(new_word_array1[11]));
                    cout << "Enter the sentence '12' you want" << endl;
                    cin.getline(sentence[11], sizeof(sentence[11]));
                    addnew_word();
                    break;
                case 13:
                    cout << "Enter the word you want '13'" << endl;
                    cin.getline(new_word_array1[12], sizeof(new_word_array1[12]));
                    cin.getline(new_word_array1[12], sizeof(new_word_array1[12]));
                    cout << "Enter the sentence '13' you want" << endl;
                    cin.getline(sentence[12], sizeof(sentence[12]));
                    addnew_word();
                    break;
                case 14:
                    cout << "Enter the word you want '14'" << endl;
                    cin.getline(new_word_array1[13], sizeof(new_word_array1[13]));
                    cin.getline(new_word_array1[13], sizeof(new_word_array1[13]));
                    cout << "Enter the sentence '14' you want" << endl;
                    cin.getline(sentence[13], sizeof(sentence[13]));
                    addnew_word();
                    break;
                case 15:
                    cout << "Enter the word you want '15'" << endl;
                    cin.getline(new_word_array1[14], sizeof(new_word_array1[14]));
                    cin.getline(new_word_array1[14], sizeof(new_word_array1[14]));
                    cout << "Enter the sentence '15' you want" << endl;
                    cin.getline(sentence[14], sizeof(sentence[14]));
                    addnew_word();
                    break;
                case 16:
                    cout << "Enter the word you want '16'" << endl;
                    cin.getline(new_word_array1[15], sizeof(new_word_array1[15]));
                    cin.getline(new_word_array1[15], sizeof(new_word_array1[15]));
                    cout << "Enter the sentence '16' you want" << endl;
                    cin.getline(sentence[15], sizeof(sentence[15]));
                    addnew_word();
                    break;
                case 17:
                    cout << "Enter the word you want '17'" << endl;
                    cin.getline(new_word_array1[16], sizeof(new_word_array1[16]));
                    cin.getline(new_word_array1[16], sizeof(new_word_array1[16]));
                    cout << "Enter the sentence '17' you want" << endl;
                    cin.getline(sentence[16], sizeof(sentence[16]));
                    addnew_word();
                    break;
                case 18:
                    cout << "Enter the word you want '18'" << endl;
                    cin.getline(new_word_array1[17], sizeof(new_word_array1[17]));
                    cin.getline(new_word_array1[17], sizeof(new_word_array1[17]));
                    cout << "Enter the sentence '18' you want" << endl;
                    cin.getline(sentence[17], sizeof(sentence[17]));
                    addnew_word();
                    break;
                case 19:
                    cout << "Enter the word you want '19'" << endl;
                    cin.getline(new_word_array1[18], sizeof(new_word_array1[18]));
                    cin.getline(new_word_array1[18], sizeof(new_word_array1[18]));
                    cout << "Enter the sentence '19' you want" << endl;
                    cin.getline(sentence[18], sizeof(sentence[18]));
                    addnew_word();
                    break;
                case 20:
                    cout << "Enter the word you want '20'" << endl;
                    cin.getline(new_word_array1[19], sizeof(new_word_array1[19]));
                    cin.getline(new_word_array1[19], sizeof(new_word_array1[19]));
                    cout << "Enter the sentence '20' you want" << endl;
                    cin.getline(sentence[19], sizeof(sentence[19]));
                    addnew_word();
                    break;
                case 0:
                    return;
            }
            cout << termcolor::reset;
            //end switch function addnew_word
            add_remove();
        } else if (inputchar == 'n')
            main();
        else
            cout << termcolor::italic;
        cout << "Enter the correct option!" << endl;
        cout << termcolor::reset;
    }
}//end function addnew_word

//function remove_w_s

void remove_w_s() {
    while (1) {
        cout << termcolor::italic ;
        for (int i = 0; i < 20; i++) {
            if (new_word_array1[i][0] == NULL || new_word_array1[i][0] == ' ')
                continue;
            if (sentence[i][0] == ' ' || sentence[i][0] == NULL)
                continue;
            cout << i + 1 << "-" << endl;
            cout << "word " << " : " << new_word_array1[i] << endl;
            cout << "description : " << sentence[i] << endl;
            cout << "status : ";
            int status = statusword(i);
            if (status > 0 && status <= 10) {
                cout << termcolor::cyan << "esay\n" << termcolor::reset;

            } else if (status <= 20 && status > 10) {
                cout << termcolor::yellow << "medium\n" << termcolor::reset;
            } else if (status > 20) {
                cout << termcolor::red << "hard\n" << termcolor::reset;
            }
        }

        cout << termcolor::reset;
        cout << termcolor::blue << "For remove word enter your Choice number " << termcolor::reset;;
        cin >> input;
        //switch function remove_w_s
        switch (input) {
            case 1:
                for (int i = 0; i < sizeof(new_word_array1[0]) != NULL; i++) {
                    new_word_array1[0][i] = ' ';
                }
                for (int i = 0; i < 20; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (new_word_array1[i + 1] == NULL)
                            break;
                        new_word_array1[i][j] = new_word_array1[i + 1][j];
                    }
                    for (int j = 0; j < 100; j++) {
                        if (sentence[i + 1] == NULL)
                            break;
                        sentence[i][j] = sentence[i + 1][j];
                    }
                }
                break;
            case 2:
                for (int i = 0; i < sizeof(new_word_array1[1]) != NULL; i++)
                    new_word_array1[1][i] = ' ';
                for (int i = 1; i < 20; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (new_word_array1[i + 1] == NULL)
                            break;
                        new_word_array1[i][j] = new_word_array1[i + 1][j];
                    }
                    for (int j = 0; j < 100; j++) {
                        if (sentence[i + 1] == NULL)
                            break;
                        sentence[i][j] = sentence[i + 1][j];
                    }
                }
                break;
            case 3:
                for (int i = 0; i < sizeof(new_word_array1[2]) != NULL; i++)
                    new_word_array1[2][i] = ' ';
                for (int i = 2; i < 20; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (new_word_array1[i + 1] == NULL)
                            break;
                        new_word_array1[i][j] = new_word_array1[i + 1][j];
                    }
                    for (int j = 0; j < 100; j++) {
                        if (sentence[i + 1] == NULL)
                            break;
                        sentence[i][j] = sentence[i + 1][j];
                    }
                }
                break;
            case 4:
                for (int i = 0; i < sizeof(new_word_array1[3]) != NULL; i++)
                    new_word_array1[3][i] = ' ';
                for (int i = 3; i < 20; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (new_word_array1[i + 1] == NULL)
                            break;
                        new_word_array1[i][j] = new_word_array1[i + 1][j];
                    }
                    for (int j = 0; j < 100; j++) {
                        if (sentence[i + 1] == NULL)
                            break;
                        sentence[i][j] = sentence[i + 1][j];
                    }
                }
                break;
            case 5:
                for (int i = 0; i < sizeof(new_word_array1[4]) != NULL; i++)
                    new_word_array1[4][i] = ' ';
                for (int i = 4; i < 20; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (new_word_array1[i + 1] == NULL)
                            break;
                        new_word_array1[i][j] = new_word_array1[i + 1][j];
                    }
                    for (int j = 0; j < 100; j++) {
                        if (sentence[i + 1] == NULL)
                            break;
                        sentence[i][j] = sentence[i + 1][j];
                    }
                }
                break;
            case 6:
                for (int i = 0; i < sizeof(new_word_array1[5]) != NULL; i++)
                    new_word_array1[5][i] = ' ';
                for (int i = 5; i < 20; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (new_word_array1[i + 1] == NULL)
                            break;
                        new_word_array1[i][j] = new_word_array1[i + 1][j];
                    }
                    for (int j = 0; j < 100; j++) {
                        if (sentence[i + 1] == NULL)
                            break;
                        sentence[i][j] = sentence[i + 1][j];
                    }
                }
                break;
            case 7:
                for (int i = 0; i < sizeof(new_word_array1[6]) != NULL; i++)
                    new_word_array1[6][i] = ' ';
                for (int i = 6; i < 20; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (new_word_array1[i + 1] == NULL)
                            break;
                        new_word_array1[i][j] = new_word_array1[i + 1][j];
                    }
                    for (int j = 0; j < 100; j++) {
                        if (sentence[i + 1] == NULL)
                            break;
                        sentence[i][j] = sentence[i + 1][j];
                    }
                }
                break;
            case 8:
                for (int i = 0; i < sizeof(new_word_array1[7]) != NULL; i++)
                    new_word_array1[7][i] = ' ';
                for (int i = 7; i < 20; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (new_word_array1[i + 1] == NULL)
                            break;
                        new_word_array1[i][j] = new_word_array1[i + 1][j];
                    }
                    for (int j = 0; j < 100; j++) {
                        if (sentence[i + 1] == NULL)
                            break;
                        sentence[i][j] = sentence[i + 1][j];
                    }
                }
                break;
            case 9:
                for (int i = 0; i < sizeof(new_word_array1[8]) != NULL; i++)
                    new_word_array1[8][i] = ' ';
                for (int i = 8; i < 20; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (new_word_array1[i + 1] == NULL)
                            break;
                        new_word_array1[i][j] = new_word_array1[i + 1][j];
                    }
                    for (int j = 0; j < 100; j++) {
                        if (sentence[i + 1] == NULL)
                            break;
                        sentence[i][j] = sentence[i + 1][j];
                    }
                }
                break;
            case 10:
                for (int i = 0; i < sizeof(new_word_array1[9]) != NULL; i++)
                    new_word_array1[9][i] = ' ';
                for (int i = 9; i < 20; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (new_word_array1[i + 1] == NULL)
                            break;
                        new_word_array1[i][j] = new_word_array1[i + 1][j];
                    }
                    for (int j = 0; j < 100; j++) {
                        if (sentence[i + 1] == NULL)
                            break;
                        sentence[i][j] = sentence[i + 1][j];
                    }
                }
                break;
            case 11:
                for (int i = 0; i < sizeof(new_word_array1[10]) != NULL; i++)
                    new_word_array1[10][i] = ' ';
                for (int i = 10; i < 20; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (new_word_array1[i + 1] == NULL)
                            break;
                        new_word_array1[i][j] = new_word_array1[i + 1][j];
                    }
                    for (int j = 0; j < 100; j++) {
                        if (sentence[i + 1] == NULL)
                            break;
                        sentence[i][j] = sentence[i + 1][j];
                    }
                }
                break;
            case 12:
                for (int i = 0; i < sizeof(new_word_array1[11]) != NULL; i++)
                    new_word_array1[11][i] = ' ';
                for (int i = 11; i < 20; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (new_word_array1[i + 1] == NULL)
                            break;
                        new_word_array1[i][j] = new_word_array1[i + 1][j];
                    }
                    for (int j = 0; j < 100; j++) {
                        if (sentence[i + 1] == NULL)
                            break;
                        sentence[i][j] = sentence[i + 1][j];
                    }
                }
                break;
            case 13:
                for (int i = 0; i < sizeof(new_word_array1[12]) != NULL; i++)
                    new_word_array1[12][i] = ' ';
                for (int i = 12; i < 20; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (new_word_array1[i + 1] == NULL)
                            break;
                        new_word_array1[i][j] = new_word_array1[i + 1][j];
                    }
                    for (int j = 0; j < 100; j++) {
                        if (sentence[i + 1] == NULL)
                            break;
                        sentence[i][j] = sentence[i + 1][j];
                    }
                }
                break;
            case 14:
                for (int i = 0; i < sizeof(new_word_array1[13]) != NULL; i++)
                    new_word_array1[13][i] = ' ';
                for (int i = 13; i < 20; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (new_word_array1[i + 1] == NULL)
                            break;
                        new_word_array1[i][j] = new_word_array1[i + 1][j];
                    }
                    for (int j = 0; j < 100; j++) {
                        if (sentence[i + 1] == NULL)
                            break;
                        sentence[i][j] = sentence[i + 1][j];
                    }
                }
                break;
            case 15:
                for (int i = 0; i < sizeof(new_word_array1[14]) != NULL; i++)
                    new_word_array1[14][i] = ' ';
                for (int i = 14; i < 20; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (new_word_array1[i + 1] == NULL)
                            break;
                        new_word_array1[i][j] = new_word_array1[i + 1][j];
                    }
                    for (int j = 0; j < 100; j++) {
                        if (sentence[i + 1] == NULL)
                            break;
                        sentence[i][j] = sentence[i + 1][j];
                    }
                }
                break;
            case 16:
                for (int i = 0; i < sizeof(new_word_array1[15]) != NULL; i++)
                    new_word_array1[15][i] = ' ';
                for (int i = 15; i < 20; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (new_word_array1[i + 1] == NULL)
                            break;
                        new_word_array1[i][j] = new_word_array1[i + 1][j];
                    }
                    for (int j = 0; j < 100; j++) {
                        if (sentence[i + 1] == NULL)
                            break;
                        sentence[i][j] = sentence[i + 1][j];
                    }
                }
                break;
            case 17:
                for (int i = 0; i < sizeof(new_word_array1[16]) != NULL; i++)
                    new_word_array1[16][i] = ' ';
                for (int i = 16; i < 20; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (new_word_array1[i + 1] == NULL)
                            break;
                        new_word_array1[i][j] = new_word_array1[i + 1][j];
                    }
                    for (int j = 0; j < 100; j++) {
                        if (sentence[i + 1] == NULL)
                            break;
                        sentence[i][j] = sentence[i + 1][j];
                    }
                }
                break;
            case 18:
                for (int i = 0; i < sizeof(new_word_array1[17]) != NULL; i++)
                    new_word_array1[17][i] = ' ';
                for (int i = 17; i < 20; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (new_word_array1[i + 1] == NULL)
                            break;
                        new_word_array1[i][j] = new_word_array1[i + 1][j];
                    }
                    for (int j = 0; j < 100; j++) {
                        if (sentence[i + 1] == NULL)
                            break;
                        sentence[i][j] = sentence[i + 1][j];
                    }
                }
                break;
            case 19:
                for (int i = 0; i < sizeof(new_word_array1[18]) != NULL; i++)
                    new_word_array1[18][i] = ' ';
                for (int i = 18; i < 20; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (new_word_array1[i + 1] == NULL)
                            break;
                        new_word_array1[i][j] = new_word_array1[i + 1][j];
                    }
                    for (int j = 0; j < 100; j++) {
                        if (sentence[i + 1] == NULL)
                            break;
                        sentence[i][j] = sentence[i + 1][j];
                    }
                }
                break;
            case 20:
                for (int i = 0; i < sizeof(new_word_array1[19]) != NULL; i++)
                    new_word_array1[19][i] = ' ';
                for (int i = 19; i < 20; i++) {
                    for (int j = 0; j < 15; j++) {
                        if (new_word_array1[i + 1] == NULL)
                            break;
                        new_word_array1[i][j] = new_word_array1[i + 1][j];
                    }
                    for (int j = 0; j < 100; j++) {
                        if (sentence[i + 1] == NULL)
                            break;
                        sentence[i][j] = sentence[i + 1][j];
                    }
                }
            case 0:
                return;
        }//switch function remove_w_s
    }
}

//end function remove_w_s

//function statusword
char statusword(int u) {
    double numbr = 0, m = 0, g = 0, r = 0, p;
    for (int i = 1; i <= sizeof(new_word_array1[u]); i++) {
        g += i;
        new_word_array1[u][i];
        if (new_word_array1[u][i] <= 'o' && new_word_array1[u][i] >= 'a')
            m = 1;
        else if (new_word_array1[u][i] <= 'z' && new_word_array1[u][i] >= 'p')
            m = 2;
        p += m * i;
        numbr++;
        r++;
        if (new_word_array1[u][i] == NULL)
            break;
    }
    for (int i = 0; i < new_word_array1[u][i] != NULL; i++) {
        for (int j = 0; j < new_word_array1[0][i] != NULL; j++)
            if (new_word_array1[u][i] == new_word_array1[u][j] && i > j)
                r--;
    }
    double f = r / 26;
    double status = pow(numbr, 2) * (p / g) * f;
    return status;
}//end function statusword

// function play game
void playgame() {
    while (1) {
        cout << termcolor::italic ;
        cout << "1-Start esay game" << endl;
        cout << "2-Start medium game" << endl;
        cout << "1-Start hard game" << endl;
        cout << "0-Return menu" << endl;
        cout << "Enter your Choice Number =>";
        cout << termcolor::reset;
        cin >> input;
        //switch function play game
        switch (input) {
            case 1:
                start_esay_game();
                break;
            case 2:
                start_medium_game();
                break;
            case 3:
                start_hard_game();
                break;
            case 0:
                return;
        }//end switch function play game
    }

}
//end function play gmae

//function fault
int fault1(char inputchar) {
    int j = 0;
    char io[0][14];
    for (int i = 0; i < 20; i++) {
        for (int m = 0; m < num; m++) {

            if (inputchar != new_word_array1[i][m]) {
                io[0][m] = inputchar;
            }
        }
        for (int m = 0; m < num; m++) {
            if (io[0][m] == NULL)
                break;
            j++;
        }
    }
    if (inputchar == '*' || inputchar == '?')
        j--;
    return j - num + 1;
}//end function fault

//function game over
void gameover(int i) {
    for (i; i >= 0; i--) {
        for (int j = 0; j < 15; j++) {
            new_word_array1[i][j] = ' ';
        }
        for (int j = 0; j < 100; j++) {
            sentence[i][j] = ' ';
        }
    }

    cout << termcolor::reset;
    main();
}
//function game over

//function start_esay_game
void start_esay_game() {
    cout << termcolor::italic ;
    char charinput, input23[0][14];
    int num = 0, Gem = 3;
    for (int i = 0; i < 20; i++) {
        fault = 0, num = 0;
        if (new_word_array1[i][0] == NULL) {
            cout << termcolor::red << termcolor::blink << "No word!!! \n" << termcolor::reset;
            addnew_word();
            break;
        }
        for (int j = 0; j < 15; j++) {
            if (new_word_array1[i][j] == NULL)
                break;
            num++;
        }
        char inuput3[0][num];
        for (int j = 0; j < num; j++) {
            inuput3[0][j] = '-';
        }
        int number2 = num;
        int k = 0;
        cout << new_word_array1[i - 1];
        while (number2 > 0) {
            cout << termcolor::italic ;
            cout << num << endl;
//            system("clear");
            cout << termcolor::yellow << "GEM : " << Gem << "     " << termcolor::red << "Fault : " << fault
                 << " of ";
            int status = statusword(i);
            if (status > 0 && status <= 10) {
                cout << "4";
            } else if (status <= 20 && status > 10) {
                cout << "6";
            } else if (status > 20) {
                cout << "8";
            }
            if (status > 0 && status <= 10) {
                if (fault > 4) {
                    cout << termcolor::italic ;
                    cout << termcolor::blink << "\nGame over\n" << termcolor::reset;
                    gameover(i);
                }
            } else if (status < 20 && status > 10) {
                if (fault > 6) {
                    cout << termcolor::italic ;
                    cout << termcolor::blink << "\nGame over\n" << termcolor::reset;
                    gameover(i);
                }
            } else if (status > 20) {
                if (fault > 8) {
                    cout << termcolor::italic ;
                    cout << termcolor::blink << "\nGame over\n" << termcolor::reset;
                    gameover(i);
                }
            }
            cout << termcolor::reset;
            cout << termcolor::italic ;
            cout << "\nDescription : " << sentence[i] << endl;
            cout << "Guess : ";
            for (int p = 0; p < num; p++) {
                cout << inuput3[0][p];
            }
            cout << endl;
            for (int j = 0; j < k; j++) {
                if (input23[0][j] == new_word_array1[i][0] || input23[0][j] == new_word_array1[i][1] ||
                    input23[0][j] == new_word_array1[i][2] ||
                    input23[0][j] == new_word_array1[i][3] || input23[0][j] == new_word_array1[i][4] ||
                    input23[0][j] == new_word_array1[i][5] ||
                    input23[0][j] == new_word_array1[i][6] || input23[0][j] == new_word_array1[i][7] ||
                    input23[0][j] == new_word_array1[i][8] ||
                    input23[0][j] == new_word_array1[i][9] || input23[0][j] == new_word_array1[i][10] ||
                    input23[0][j] == new_word_array1[i][11] ||
                    input23[0][j] == new_word_array1[i][12] || input23[0][j] == new_word_array1[i][13] ||
                    input23[0][j] == new_word_array1[i][15] ||
                    input23[0][j] == new_word_array1[i][15] || input23[0][j] == new_word_array1[i][16] ||
                    input23[0][j] == new_word_array1[i][17] ||
                    input23[0][j] == new_word_array1[i][18] || input23[0][j] == new_word_array1[i][19]) {
                    cout << termcolor::blue << input23[0][j] << termcolor::reset << " ";

                } else if (input23[0][j] != new_word_array1[i][j])
                    cout << termcolor::red << input23[0][j] << termcolor::reset << " ";
            }
            cout << endl;
            cout << termcolor::italic ;
            cout << "whats your guess : ";
            input23[0][k];
            if (inuput3[0] == new_word_array1[i])
                cout << " you win";
            cin >> charinput;
            input23[0][k] = charinput;
            k++;
            if (charinput == '?') {
                if (Gem < 2) {
                    cout << termcolor::red << termcolor::blink << "No word!!! \n" << termcolor::reset;
                } else {
                    Gem -= 2;
                    for (int j = 0; j < num; j++) {
                        if (inuput3[0][j] == '-') {
                            inuput3[0][j] = new_word_array1[i][j];
                            break;
                        } else
                            continue;
                    }
                }
            }
            for (int m = 0; m < num; m++) {
                if ('*' == charinput) {
                    for (int j = 0; j < num; j++)
                        if (new_word_array1[i][m] == ' ')
                            inuput3[0][m] = ' ';
                }
                if (new_word_array1[i][m] == charinput) {
                    inuput3[0][m] = charinput;
                    number2--;
                    if (fault >= 0)
                        fault--;
                }
            }

            int y = fault1(charinput);
            fault += y;
        }
        Gem += 6;
    }
}
//end function start_esay_game

//function start medium game
void start_medium_game() {
    cout << termcolor::italic ;
    char charinput, input23[0][14];
    int num = 0, Gem = 4;
    for (int i = 0; i < 20; i++) {
        fault = 0, num = 0;
        if (new_word_array1[i][0] == NULL) {
            cout << termcolor::italic ;
            cout << termcolor::red << termcolor::blink << "No word!!! \n" << termcolor::reset;
            addnew_word();
            break;
        }
        for (int j = 0; j < 15; j++) {
            if (new_word_array1[i][j] == NULL)
                break;
            num++;
        }
        char inuput3[0][num];
        for (int j = 0; j < num; j++) {
            inuput3[0][j] = '-';
        }
        int number2 = num;
        int k = 0;
        while (number2 > 0) {
            cout << num << endl;
            system("clear");
            cout << termcolor::italic ;
            cout << termcolor::yellow << "GEM : " << Gem << "     " << termcolor::red << "Fault : " << fault
                 << " of ";
            int status = statusword(i);
            if (status > 0 && status <= 10) {
                cout << "3";
            } else if (status < 20 && status > 10) {
                cout << "5";
            } else if (status > 20) {
                cout << "7";
            }
            if (status > 0 && status <= 10) {
                if (fault > 3) {
                    cout << termcolor::italic ;
                    cout << "\nGame over\n";cout << termcolor::reset;
                    gameover(i);
                }
            } else if (status <= 20 && status > 10) {
                if (fault > 5) { cout << termcolor::italic ;
                    cout << "\nGame over\n";cout << termcolor::reset ;
                    gameover(i);
                }
            } else if (status > 20) {
                if (fault > 7) { cout << termcolor::italic ;
                    cout << "\nGame over\n";
                    cout << termcolor::reset;
                    gameover(i);
                }
            }
            cout << termcolor::reset;
            cout << termcolor::italic ; ;
            cout << "\nDescription : " << sentence[i] << endl;
            cout << "Guess : ";
            for (int p = 0; p < num; p++) {
                cout << inuput3[0][p];
            }
            cout << endl;
            for (int j = 0; j < k; j++) {
                if (input23[0][j] == new_word_array1[i][0] || input23[0][j] == new_word_array1[i][1] ||
                    input23[0][j] == new_word_array1[i][2] ||
                    input23[0][j] == new_word_array1[i][3] || input23[0][j] == new_word_array1[i][4] ||
                    input23[0][j] == new_word_array1[i][5] ||
                    input23[0][j] == new_word_array1[i][6] || input23[0][j] == new_word_array1[i][7] ||
                    input23[0][j] == new_word_array1[i][8] ||
                    input23[0][j] == new_word_array1[i][9] || input23[0][j] == new_word_array1[i][10] ||
                    input23[0][j] == new_word_array1[i][11] ||
                    input23[0][j] == new_word_array1[i][12] || input23[0][j] == new_word_array1[i][13] ||
                    input23[0][j] == new_word_array1[i][15] ||
                    input23[0][j] == new_word_array1[i][15] || input23[0][j] == new_word_array1[i][16] ||
                    input23[0][j] == new_word_array1[i][17] ||
                    input23[0][j] == new_word_array1[i][18] || input23[0][j] == new_word_array1[i][19]) {
                    cout << termcolor::blue << input23[0][j] << termcolor::reset << " ";

                } else if (input23[0][j] != new_word_array1[i][j])
                    cout << termcolor::red << input23[0][j] << termcolor::reset << " ";
            }
            cout << endl;
            cout << termcolor::italic ;
            cout << "whats your guess : ";
            input23[0][k];
            if (inuput3[0] == new_word_array1[i])
                cout << " you win";
            cin >> charinput;
            input23[0][k] = charinput;
            k++;cout << termcolor::reset;
            if (charinput == '?') {
                if (Gem < 3) { cout << termcolor::italic ;
                    cout << termcolor::red << "No Gem!" << termcolor::reset << endl;
                } else {
                    Gem -= 3;
                    for (int j = 0; j < num; j++) {
                        if (inuput3[0][j] == '-') {
                            inuput3[0][j] = new_word_array1[i][j];
                            break;
                        } else
                            continue;
                    }
                }
            }
            for (int m = 0; m < num; m++) {
                if ('*' == charinput) {
                    for (int j = 0; j < num; j++)
                        if (new_word_array1[i][m] == ' ')
                            inuput3[0][m] = ' ';
                }
                if (new_word_array1[i][m] == charinput) {
                    inuput3[0][m] = charinput;
                    number2--;
                    if (fault >= 0)
                        fault--;
                }
            }

            int y = fault1(charinput);
            fault += y;
        }
        Gem += 5;
    }
}
//end function start medium game

//function start hard game
void start_hard_game() {
    char charinput, input23[0][14];
    int num = 0, Gem = 4;
    for (int i = 0; i < 20; i++) {
        fault = 0, num = 0;
        if (new_word_array1[i][0] == NULL) {
            cout << termcolor::italic ;
            cout << termcolor::red << "No word! \n" << termcolor::reset;
            addnew_word();
            break;
        }
        for (int j = 0; j < 15; j++) {
            if (new_word_array1[i][j] == NULL)
                break;
            num++;
        }
        char inuput3[0][num];
        for (int j = 0; j < num; j++) {
            inuput3[0][j] = '-';
        }
        int number2 = num;
        int k = 0;
        while (number2 > 0) {
            cout << num << endl;
            system("clear");
            cout << termcolor::italic ;
            cout << termcolor::yellow << "GEM : " << Gem << "     " << termcolor::red << "Fault : " << fault
                 << " of ";
            int status = statusword(i);
            if (status > 0 && status <= 10) {
                cout << "2";
            } else if (status <= 20 && status > 10) {
                cout << "4";
            } else if (status > 20) {
                cout << "6";
            }
            if (status > 0 && status <= 10) {
                if (fault > 2) {

                    cout << "\nGame over\n";
                     cout << termcolor::reset ;
                    gameover(i);
                }
            } else if (status < 20 && status > 10) {
                if (fault > 4) {
                    cout << "\nGame over\n";
                     cout << termcolor::reset ;
                    gameover(i);
                }
            } else if (status > 20) {
                if (fault > 6) {
                    cout << "\nGame over\n";
                    cout << termcolor::reset ;
                    gameover(i);
                }
            }
            cout << termcolor::reset;
            cout << termcolor::italic ;
            cout << "\nDescription : " << sentence[i] << endl;
            cout << "Guess : ";
            for (int p = 0; p < num; p++) {
                cout << inuput3[0][p];
            }
            cout << endl;
            for (int j = 0; j < k; j++) {
                if (input23[0][j] == new_word_array1[i][0] || input23[0][j] == new_word_array1[i][1] ||
                    input23[0][j] == new_word_array1[i][2] ||
                    input23[0][j] == new_word_array1[i][3] || input23[0][j] == new_word_array1[i][4] ||
                    input23[0][j] == new_word_array1[i][5] ||
                    input23[0][j] == new_word_array1[i][6] || input23[0][j] == new_word_array1[i][7] ||
                    input23[0][j] == new_word_array1[i][8] ||
                    input23[0][j] == new_word_array1[i][9] || input23[0][j] == new_word_array1[i][10] ||
                    input23[0][j] == new_word_array1[i][11] ||
                    input23[0][j] == new_word_array1[i][12] || input23[0][j] == new_word_array1[i][13] ||
                    input23[0][j] == new_word_array1[i][15] ||
                    input23[0][j] == new_word_array1[i][15] || input23[0][j] == new_word_array1[i][16] ||
                    input23[0][j] == new_word_array1[i][17] ||
                    input23[0][j] == new_word_array1[i][18] || input23[0][j] == new_word_array1[i][19]) {
                    cout << termcolor::blue << input23[0][j] << termcolor::reset << " ";

                } else if (input23[0][j] != new_word_array1[i][j])
                    cout << termcolor::red << input23[0][j] << termcolor::reset << " ";
            }
            cout << endl;
            cout << termcolor::italic ;
            cout << "whats your guess : ";
            input23[0][k];
            cin >> charinput;
            input23[0][k] = charinput;
            k++;

            if (charinput == '?') {
                if (Gem < 3) {
                    cout << termcolor::italic ;
                    cout << termcolor::red << "No Gems!!!" << termcolor::reset << endl;
                } else {
                    Gem -= 3;
                    for (int j = 0; j < num; j++) {
                        if (inuput3[0][j] == '-') {
                            inuput3[0][j] = new_word_array1[i][j];
                            break;
                        } else
                            continue;
                    }
                }
            }
            for (int m = 0; m < num; m++) {
                if ('*' == charinput) {
                    for (int j = 0; j < num; j++)
                        if (new_word_array1[i][m] == ' ')
                            inuput3[0][m] = ' ';
                }
                if (new_word_array1[i][m] == charinput) {
                    inuput3[0][m] = charinput;
                    number2--;
                    if (fault >= 0)
                        fault--;
                }
            }

            int y = fault1(charinput);
            fault += y;
        }
        Gem += 3;
    }
}
//end function start hard game



