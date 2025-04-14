#include <iostream>
#include<fstream>
#include <string>
#include <ctime>
#include "termcolor.hpp"
#include "md5.cpp"

using namespace std;
struct propertys {
    string name[100];
    bool value[100]{};
};
struct birth {
    int year[100];
    int moon[100];
    int day[100];
};
struct personnel {
    long int ID[100];
    string name[100];
    string family[100];
    birth date_birth;
    string job[100];
    long int pay[100];
};
struct resident {
    long int ID;
    string name;
    string famliy;
};
struct rooms {
    propertys property;
    int number_room[100]{};
    string number_bed[100];
    string description[100];
    bool staus[100]{};
    long int rent[100]{};
    resident residents;
};
struct hotel {
    string name;
    long int phonenumber{};
    string address;
    personnel personnels;
    rooms room;
};
string id_personneluser;
string increases;

//===========================================================================================
void menu();

void information_hotel();

void personnel_information();

void room_information();


void ordinaryuser();


void login_user();


void checkout();



//=================== super user ====================


void superuser();

void change_information_superuser();

void change_informatin_superuser();

void See_rooms_information_superuser();

void See_personnel_information_superuser();

void delete_room();

void See_list_citizens();

void change_information_hotel();

void rent_increases();

//================================ personnel user =========================
void personneluser();

void see_room_information();

void see_status_room_information();

void room_reservation_requests();

void reservation_room_guests();

void change_informatin_personnel();

void change_information();

void change_username_password();

//====================================ordinaryuser===================================
void reservations_room();

void room_tracking();

//====================== function main==========================================================
int main() {
    menu();
    return 0;
}

//===========================================================================================
void menu() {
    while (1) {
        system("clear");

        int number;
        cout << "1->login system .\n";
        cout << "2-> Ordinary user .\n";
        cout << "3->Quit \n";
        cout << "**************************************\n";
        cout << "Enter your Choice number : \n";
        cin >> number;
        switch (number) {
            case 1: {
                system("clear");
                login_user();
                break;
            }
            case 2: {
                system("clear");
                ordinaryuser();
                break;
            }
            case 3: {
                exit(1);
            }
            default:
                cout << "Pelase Enter rigth word.\n";
        }
    }
}

//===========================================================================================
void login_user() {
    while (1) {
        id_personneluser = "";
        char u_p;
        ofstream login_out;
        ifstream login_in;
        ofstream superuser_information_out;
        string username, user[1000], password, IDsuperuser, newname, newfamily, user1[20];

        login_in.open("login.dat", ios::in);
        if (!login_in.fail()) {

            for (int i = 0; i < 1000; i++) {
                login_in >> user[i];
            }
            if (user[0] == "" || user[1] == "") {
                while (1) {
                    login_out.open("login.dat", ios::out);
                    cout << "username = 1\npassword = 1\n";
                    cout << "Enter username : \n";
                    cin >> username;
                    cout << "Enter password : \n";
                    cin >> password;
                    if (username == "1" && password == "1")
                        break;
                }
                password = md5(md5(password));
                login_out << username << "\n" << password;
                login_out.close();
                cout << "are you change information ?[y/n].\n";
                cin >> u_p;
                while (true) {
                    if (u_p == 'y' || u_p == 'Y') {
                        superuser_information_out.open("superuser.dat", ios::app);
                        cout << "Enter new ID. \n";
                        getline(cin, IDsuperuser);
                        getline(cin, IDsuperuser);
                        cout << "Enter new name .\n";
                        getline(cin, newname);
                        cout << "Enter new family .\n";
                        getline(cin, newfamily);
                        superuser_information_out << IDsuperuser << "\n" << newname << "\n" << newfamily;
                        superuser_information_out.close();
                        login_out.open("login.dat", ios::out);
                        cout << "Enter new username :\n";
                        getline(cin, username);
                        cout << "Enter new password :\n";
                        getline(cin, password);
                        password = md5(md5(password));
                        login_out << username << "\n" << password;
                        login_out.close();
                        system("clear");
                        superuser();
                        break;
                    } else if (u_p == 'n' || u_p == 'N') {
                        break;
                    } else {
                        cout << "Enter the correct option!" << endl;
                        continue;
                    }
                }
            } else if (user1[0] != " " || user1[1] != " ") {
                bool ok = true;

                while (ok) {

                    cout << "Enter username : ";
                    getline(cin, username);
                    getline(cin, username);

                    cout << "Enter password  : ";
                    getline(cin, password);
                    password = md5(md5(password));
                    if (user1[0].empty()) {
                        if (user[0] == username && user[1] == password) { ;

                            break;
                        } else {
                            for (int j = 2; j < 1000; j += 2) {
                                if (user[j + 1] == password && user[j] == username) {
                                    id_personneluser = username;
                                    ok = false;
                                    break;

                                }
                            }
                        }
                    } else {
                        cout << "The username or password is incorrect. Please try again.\n";
                        continue;
                    }
                }
            }
        } else
            cout << "can not open file\n";
        break;
    }
    system("clear");
    if (id_personneluser.empty())
        superuser();
    else
        personneluser();
}

void superuser() {
    system("clear");
    int number;
    cout << "1-> Add hotel information \n";
    cout << "2-> Add rooms information\n";
    cout << "3-> Add personnel_information\n";
    cout << "4-> change password and username \n";
    cout << "5-> See resident information hotel .\n";
    cout << "6-> Room reservation requests .\n";
    cout << "7-> reservation room for guests .\n";
    cout << "8-> checkout .\n";
    cout << "9-> See list citizens\n";
    cout << "10-> See rentincreases\n";
    cout << "11->logout .\n";

    cout << "**************************************\n";
    cout << "Enter your Choice number : \n";
    cin >> number;
    switch (number) {
        case 1: {
            system("clear");
            information_hotel();
            break;
        }
        case 2: {
            system("clear");
            room_information();
            break;
        }
        case 3: {
            system("clear");
            personnel_information();
            break;
        }
        case 4: {
            system("clear");
            change_informatin_superuser();
            break;
        }
        case 5: {
            system("clear");
            see_status_room_information();
            break;
        }
        case 6: {
            system("clear");
            room_reservation_requests();
            break;
        }
        case 7: {
            system("clear");
            reservation_room_guests();
            break;
        }
        case 8: {
            system("clear");
            checkout();
            break;
        }
        case 9: {
            system("clear");
            See_list_citizens();
            break;
        }

        case 10: {
            system("clear");
            rent_increases();
            break;
        }
        case 11: {
            system("clear");
            menu();
            break;
        }
        default:
            cout << "Pelase Enter rigth number.\n";

    }
}


void information_hotel() {

    ofstream hotel_information_file_out;
    ifstream hotel_information_file_in;
    ifstream personnel_file;
    ifstream room_information_file_in;
    hotel hotel_information;
//    ==================================
    string name, address, personnels_list[100];
    long int phonenumber;
    room_information_file_in.open("room_information_file.dat", ios::app);

//    ==================================
    hotel_information_file_in.open("hotel_information_file.dat", ios::in);
    if (!hotel_information_file_in.fail()) {
        hotel_information_file_in >> name >> phonenumber >> address;
        hotel hotles;
        hotles.address = address;
        hotles.name = name;
        hotles.phonenumber = phonenumber;
        cout << " Name hotel : " << hotles.name << "\n";
        cout << " Address hotel : " << hotles.address << "\n";
        cout << " Phonenumber hotel : " << hotles.phonenumber << "\n";
        cout << "**********************************\n\n";
        cout << "1->See rooms information .\n";
        cout << "2->See personnel information .\n";
        cout << "3->change information hotel.\n";
        cout << "4->menu superuser.\n";
    }

    char numbers;
    cin >> numbers;
    switch (numbers) {
        case '1': {
            system("clear");
            See_rooms_information_superuser();
            break;
        }
        case '2': {
            system("clear");
            See_personnel_information_superuser();
            break;
        }
        case '3': {
            system("clear");
            change_information_hotel();
            break;
        }
        case '4': {
            system("clear");
            superuser();
            break;
        }
    }


}

void rent_increases() {
    while (1) {
        ifstream personnel_user_in;
        ofstream personnel_user_out;
        long int newrent;
        string personnel[1000];
        personnel_user_in.open("personnel.dat", ios::in);

        for (int i = 0; i < 1000; i++) {
            personnel_user_in >> personnel[i];
        }
        int m = 0;
        for (int i = 0; i < 1000; i++) {
            m = i;
            if (increases == personnel[i]) {
                cout << "Enter the amount of salary increase :\n";

                cin >> newrent;
                break;
            }
        }
        personnel[m + 6] = newrent;
        personnel_user_out.open("personnel.dat", ios::out);
        for (int i = 0; i < 1000; i++) {
            personnel_user_out << personnel[i] << "\n";
            if (personnel[i].empty())
                break;
        }
        break;
    }
    system("clear");
    superuser();
}

// function view rooms information by super user
void See_rooms_information_superuser() {
    while (1) {
        ifstream rooms_information_in;
        rooms_information_in.open("room_information_file.dat", ios::in);
        ofstream rooms_information_out;
        string room_information[1000], boolroom, value, bednumber;
        for (int i = 0; i < 1000; i++) {
            rooms_information_in >> room_information[i];
        }
        rooms_information_in.close();
        cout << "+-----------+-----------+----------------------------------+------------+---------+--------+\n";
        cout << "|number room| bed number|  description                     |  property  | p.value |  rent  |\n";
        cout << "+-----------+-----------+----------------------------------+------------+---------+--------+\n";
        for (int i = 0; i < 1000; i += 7) {

            if (room_information[i].empty())
                break;
            if ("1" == room_information[i + 1]) {
                boolroom = "not empty";
            } else if ("0" == room_information[i + 1])
                boolroom = "empty";

            if ("1" == room_information[i + 5]) {
                value = "on";
            } else if ("0" == room_information[i + 5])
                value = "off";

            if ("bednumber:double" == room_information[i + 3]) {
                bednumber = "double";
            } else if ("bednumber:single" == room_information[i + 3]) {
                bednumber = "single";
            } else if ("bednumber:triad" == room_information[i + 3])
                bednumber = "triad";

            if (boolroom == "empty") {

                cout << "|   " << room_information[i] << "     |  " << bednumber << "   | "
                     << room_information[i + 6]
                     << "|"
                     << room_information[i + 4] << "  |" << value << " | " << room_information[i + 2]
                     << "|\n";
                cout
                        << "+-----------+-----------+----------------------------------+------------+---------+--------+\n";
            }

        }
        cout << "\n\n";
        cout << "are you change information room?[y/n]\n";
        cout << "for delete room.[d]\n";
        char ch;
        int m = 0;
        int room_number;
        string description_room, name_property, bed_number;
        string bed_number_string;
        long int rent_room;
        bool property;
        bool ok = true;
        while (ok) {
            cin >> ch;
            if (ch == 'y' || ch == 'Y') {
                string number;
                cout << "enter room number\n";
                cin >> number;
                for (int i = 0; i < 1000; i += 8) {
                    m = i;
                    if (number == room_information[i]) {

                        cout << "enter new number room\n";
                        cin >> room_number;
                        cout << "enter new bednumber.\n";
                        while (1) {
                            cin >> bed_number;
                            if (bed_number == "1") {
                                bed_number = "single";
                                break;
                            } else if (bed_number == "2") {
                                bed_number = "double";
                                break;
                            } else if (bed_number == "3") {
                                bed_number = "triad";
                                break;
                            } else {
                                cout << "Enter number 1-3 \n";
                                continue;
                            }
                        }
                        cout << "enter rent room.\n";
                        cin >> rent_room;
                        cout << "enter property. \n";
                        getline(cin, name_property);
                        getline(cin, name_property);
                        cout << "property room " << room_number << " [on/off] .\n";

                        while (true) {
                            string pro;
                            cin >> pro;
                            if (pro == "on") {
                                property = true;
                                break;
                            } else if (pro == "off") {
                                property = false;
                                break;
                            } else
                                cout << "Enter true word .[on/off]\n";
                        }
                        cout << "enter description room .\n";
                        getline(cin, description_room);
                        getline(cin, description_room);

                    }
                }
                room_information[m] = room_number;
                room_information[m + 2] = rent_room;
                room_information[m + 3] = bed_number;
                room_information[m + 4] = name_property;
                room_information[m + 5] = property;
                room_information[m + 6] = description_room;

                ok = false;
            } else if (ch == 'n' || ch == 'N') {
                ok = false;
            } else if (ch == 'd') {
                delete_room();
                break;
            } else {
                continue;
                cout << "enter true word. \n";
            }
        }
        rooms_information_out.open("room_information_file.dat", ios::out);
        for (int j = 0; j < 1000; j++) {
            if (room_information[j].empty())
                break;
            rooms_information_out << room_information[j] << endl;
        }
        rooms_information_out.close();

        break;
    }
    system("clear");
    information_hotel();

}

//end  function view rooms information by super user
void delete_room() {
    while (1) {
        ifstream rooms_information_in;

        rooms_information_in.open("room_information_file.dat", ios::in);
        ofstream rooms_information_out;
        string room_information[1000], boolroom, value, bednumber;
        for (int i = 0; i < 1000; i++) {
            rooms_information_in >> room_information[i];
        }
        rooms_information_in.close();
        string number;
        cout << "enter room number\n";
        cin >> number;
        for (int k = 0; k < 1000; k += 7) {
            if (room_information[k] == number) {
                for (int h = 0; h < 1000; h++) {
                    room_information[h] = room_information[h + 7];
                    if (room_information[h + 7].empty())
                        break;

                }
            }
        }
        rooms_information_out.open("room_information_file.dat", ios::out);
        for (int i = 0; i < 1000; i++) {
            rooms_information_out << room_information[i] << "\n";
            if (room_information[i + 1].empty())
                break;
        }
        rooms_information_out.close();
        system("clear");
        if (id_personneluser.empty()) {
            superuser();
            break;
        } else {
            personneluser();
            break;
        }
    }
}

// function for delete personnel by superuser
void delete_personnel() {
    while (1) {
        ifstream personnel_user_in;
        ofstream personnel_user_out;
        string personnel[1000];
        personnel_user_in.open("personnel.dat", ios::in);
        for (int i = 0; i < 1000; i++) {
            personnel_user_in >> personnel[i];
        }
        string number;
        cout << "enter personnel id .\n";
        cin >> number;
        for (int i = 0; i < 1000; i += 7) {
            if (personnel[i] == number) {
                for (int j = 0; j < 1000; j++) {
                    personnel[j] = personnel[j + 7];
                }
            }
        }
        personnel_user_out.open("personnel.dat", ios::out);
        for (int i = 0; i < 1000; i++) {
            personnel_user_out << personnel[i] << "\n";
            if (personnel[i + 1].empty())
                break;
        }
        personnel_user_out.close();
        system("clear");
        information_hotel();
        break;
    }
}
//end function for delete personnel by superuser

//function for see  infomation personnel by superuser
void See_personnel_information_superuser() {
    while (1) {
        ifstream personnel_user_in;
        ofstream personnel_user_out;

        string personnel[1000];
        personnel_user_in.open("personnel.dat", ios::in);
        for (int i = 0; i < 1000; i++) {
            personnel_user_in >> personnel[i];
        }
        cout << "+-------+--------------+--------------+------------+----------+--------+\n";
        cout << "|  id   |     name     |  date_birth  | job title  | rent     | reward |\n";
        cout << "+-------+--------------+--------------+------------+----------+--------+\n";
        for (int i = 0; i < 1000; i += 7) {
            time_t now = time(0);
            tm *ltm = localtime(&now);
            int b = atoi(personnel[i + 3].c_str());
            int w = atoi(personnel[i + 6].c_str());
            int personnel_rent = 0;
            personnel_rent = atoi(personnel[i + 6].c_str());
            if (b == 1 + ltm->tm_mon) {
                personnel_rent = atoi(personnel[i + 6].c_str());
                personnel_rent = personnel_rent + personnel_rent / 2;
            }
            cout << "|  " << personnel[i] << "  |  " << personnel[i + 1] << " | " << personnel[i + 2] << "/"
                 << personnel[i + 3] << "/" << personnel[i + 4] << " | " << personnel[i + 5] << " | " << personnel_rent
                 << " |";
            if (w < personnel_rent) {
                cout << personnel_rent - w << " | \n";
            } else cout << 0 << " |\n";
            cout << "+-------+--------------+--------------+------------+----------+--------+\n";
            if (personnel[i + 7].empty())
                break;
        }
        cout << "\n\n";
        cout << "are you change information personnel?[y/n]\n";
        cout << "for delete personnel.[d]\n";
        char ch;
        bool ok = true;
        int q, m = 0;
        string id, Id[100];
        string name, family, job;
        int year, moon, day, pay;
        while (ok) {
            cin >> ch;
            if (ch == 'y' || ch == 'Y') {
                cout << "Enter  id number:\n";
                cin >> id;
                for (int i = 0; i < 1000; i++) {
                    m = i;
                    if (id == personnel[i])

                        cout << "Enter id personnel : ";
                    cin >> id;
                    cout << "Enter name personnel : ";
                    getline(cin, name);
                    getline(cin, name);
                    cout << "Enter family personnel : ";
                    getline(cin, family);

                    cout << "Enter Year of Birth : ";
                    cin >> year;

                    cout << "Enter Moon of Birth : ";
                    while (true) {
                        cin >> moon;
                        if (moon > 12 || moon < 1)
                            cout << "Enter true moon .[1 up to 12]\n";
                        else
                            break;
                    }

                    cout << "Enter Day of Birth : ";
                    cin >> day;
                    cout << "Enter the job title : ";
                    getline(cin, job);
                    getline(cin, job);
                    cout << "Enter the monthly pay : ";
                    cin >> pay;
                    personnel[m] = id;
                    personnel[m + 1] = name + family;
                    personnel[m + 2] = year;
                    personnel[m + 3] = moon;
                    personnel[m + 4] = day;
                    personnel[m + 5] = job;
                    personnel[m + 6] = pay;
                }

                personnel_user_out.open("personnel.dat", ios::out);
                for (int h = 0; h < 1000; h++) {
                    personnel_user_out << personnel[h] << "\n";
                    if (personnel[h + 1].empty())
                        break;
                }
                personnel_user_out.close();
            } else if (ch == 'n' || ch == 'N') {
                system("clear");
                superuser();
            } else if (ch == 'd' || ch == 'D') {
                system("clear");
                delete_personnel();
                break;

            } else {
                cout << "enter true word  \n";
                continue;
            }
        }
        break;
        break;
    }
    system("clear");
    information_hotel();

}
//end function for see  infomation personnel by superuser

//function for change information hotel by superuser
void change_information_hotel() {
    while (1) {
        ofstream hotel_information_file_out;
        hotel hotel_information;
        string name, address;
        long int phonenumber;
        cout << "Enter new name hotel :\n";
        getline(cin, name);
        getline(cin, name);
        hotel_information.name = name;
        cout << "Enter new phonenumber hotel :\n";
        hotel_information.address = address;
        cin >> phonenumber;
        hotel_information.phonenumber = phonenumber;
        cout << "Enter new address hotel :\n";
        getline(cin, address);
        getline(cin, address);
        hotel_information.address = address;
        hotel_information_file_out.open("hotel_information_file.dat", ios::out);
        if (!hotel_information_file_out.fail()) {
            hotel_information_file_out << hotel_information.name << "\n" << hotel_information.phonenumber << "\n"
                                       << hotel_information.address << "\n";
        }

        hotel_information_file_out.close();

        break;
    }
    system("clear");
    information_hotel();


}
//end function for change information hotel by superuser

//function  Receive room information by superuser
void room_information() {
    while (1) {
        ofstream room_information_file_out;
        room_information_file_out.open("room_information_file.dat", ios::app);
        rooms room;
        int room_number[100], l;
        int bed_number[100];
        string description_room[100], name_property[100];
        string bed_number_string[100];
        char q;
        long int rent_room[100];
        bool ok = true;
        while (ok) {
            for (int i = 0; i < 100; i++) {

                cout << "Enter number room :\n";
                cin >> room_number[i];

                for (int j = 0; j < 100; j++) {
                    l = 0;
                    if (room.number_room[i - 1] == room_number[i]) {
                        l++;
                    }
                    if (l > 0) {
                        cout << "This room has already been Entered, please Enter a new room.\n";
                        cin >> room_number[i];
                    }
                }

                room.number_room[i] = room_number[i];
                while (1) {
                    cout << "Enter bed number :\n";
                    cin >> bed_number[i];
                    if (bed_number[i] == 1) {
                        bed_number_string[i] = "single";
                        break;
                    } else if (bed_number[i] == 2) {
                        bed_number_string[i] = "double";
                        break;
                    } else if (bed_number[i] == 3) {
                        bed_number_string[i] = "triad";
                        break;
                    } else {
                        cout << "Enter number 1-3 \n";
                        continue;
                    }
                }
                room.number_bed[i] = bed_number_string[i];
                cout << "Enter property room\n";
                getline(cin, room.property.name[i]);
                getline(cin, room.property.name[i]);
                name_property[i] = room.property.name[i];
                cout << name_property[i] << " [on or off] .\n";
                bool property1[100];
                while (true) {
                    string pro;
                    cin >> pro;
                    if (pro == "on") {
                        room.property.value[i] = true;
                        break;
                    } else if (pro == "off") {
                        room.property.value[i] = false;
                        break;
                    } else
                        cout << "Enter true word .[on/off]\n";
                }
                property1[i] = room.property.value[i];
                cout << "Enter description room :\n";
                getline(cin, description_room[i]);
                getline(cin, description_room[i]);

                room.description[i] = description_room[i];
                room.staus[i] = 0;
                cout << "Enter rent room :" << room.number_room[i] << "\n";
                cin >> rent_room[i];
                room.rent[i] = rent_room[i];
                cout << "Do you add a new room? [y/n]";
                cin >> q;
                if (q == 'y') {
                    system("clear");
                    continue;
                } else if (q == 'n') {
                    for (int j = 0; j < 100; j++) {
                        if (name_property[j].empty())
                            break;
                        room_information_file_out << room_number[j] << "\n" << room.staus[j] << "\n" << rent_room[j]
                                                  << "\nbednumber:"
                                                  << bed_number_string[j] << "\n" << name_property[j] << "\n"
                                                  << *property1
                                                  << "\n" << description_room[j] << "\n";
                    }
                    room_information_file_out.close();
                    ok = false;
                    break;
                } else
                    cout << "Enter the correct option!" << endl;
            }

        }
        break;
    }
    system("clear");
    superuser();

}
//end function  Receive room information by superuser

//function Receive personnel information by superuser
void personnel_information() {
    while (1) {
        ofstream personnel_file;
        ifstream personnle_file;
        ifstream hotel_file_superuser_in;
        ofstream hotel_file_superuser_out;
        string name[100], family[100], job[100];
        personnel personnels;
        long int id[100], pay[100];
        char q, we;
        int year[100], day[100], moon[100];
        personnel_file.open("personnel.dat", ios::out);
        if (!personnel_file.fail()) {
            bool ok = true;
            while (ok) {
                for (int i = 0; i < 100; i++) {
                    cout << "Enter  id number:\n";
                    cin >> id[i];
                    personnels.ID[i] = id[i];

                    for (int j = 0; j < 100; j++) {
                        q = 0;
                        personnle_file.open("personnel.dat", ios::in);
                        personnle_file >> personnels.ID[i - 1];
                        if (personnels.ID[i - 1] == id[i]) {
                            q++;
                        }
                        if (q > 0) {
                            cout << "This id has already been choice, please Enter a new id.\n";
                            cin >> id[i];
                        }
                    }
                    personnle_file.close();
                    cout << "Enter name personnel : ";
                    getline(cin, name[i]);
                    getline(cin, name[i]);
                    personnels.name[i] = name[i];

                    cout << "Enter family personnel : ";
                    getline(cin, family[i]);
                    personnels.family[i] = family[i];
                    {
                        cout << "Enter Year of Birth : ";
                        cin >> year[i];
                        personnels.date_birth.year[i] = year[i];
                        cout << "Enter Moon of Birth : ";
                        while (true) {
                            cin >> moon[i];
                            if (moon[i] > 12 || moon[i] < 1)
                                cout << "Enter true moon .[1 up to 12]\n";
                            else
                                break;
                        }
                        personnels.date_birth.moon[i] = moon[i];
                        cout << "Enter Day of Birth : ";
                        cin >> day[i];
                        personnels.date_birth.day[i] = day[i];
                        cout << "Enter the job title : ";
                        getline(cin, job[i]);
                        getline(cin, job[i]);
                        personnels.job[i] = job[i];
                        cout << "Enter the monthly pay : ";
                        cin >> pay[i];
                        personnels.pay[i] = pay[i];


                        cout << "Do you add a new perssonal ? [y/n]";
                        cin >> we;
                        if (we == 'y') {
                            continue;
                        } else if (we == 'n') {
                            for (int j = 0; j < 100; j++) {
                                if (name[j].empty()) {
                                    break;
                                }
                                personnel_file << id[j] << "\n" << name[j] << family[j] << "\n" << year[j] << "\n"
                                               << moon[j] << "\n" << day[j]
                                               << "\n"
                                               << job[j] << "\n" << pay[j] << endl;
                                name[j] = md5(md5(name[j]));
                                hotel_file_superuser_out.open("login.dat", ios::app);
                                hotel_file_superuser_out << "\n" << id[j] << "\n" << name[j];
                                hotel_file_superuser_out.close();
                            }


                            personnel_file.close();
                            ok = false;
                            break;
                        } else {
                            cout << "Enter the correct option!" << endl;
                            continue;
                        }
                    }
                }
            }
        } else {
            cout << "\ncan not find file";
        }
        break;

    }
    system("clear");
    superuser();
}
//end function Receive personnel information by superuser

//====================================================================================

void personneluser() {
    while (1) {
        system("clear");
        int number;
        string information_personnel[1000];
        ifstream personnel_information_in;
        personnel_information_in.open("personnel.dat", ios::in);
        for (int i = 0; i < 1000; i++) {
            personnel_information_in >> information_personnel[i];
        }
        personnel_information_in.close();
        cout << "+----------------------------------------------------+\n";
        for (int j = 0; j < 1000; j += 5) {
            if (information_personnel[j] == id_personneluser) {
                cout << "| your login by NAME " << information_personnel[j + 1] << " and ID "
                     << information_personnel[j]
                     << " |\n";
                break;
            }
        }
        cout << "+----------------------------------------------------+\n\n";

        cout << "1->See room information .\n";
        cout << "2->See resident information hotel .\n";
        cout << "3->Room reservation requests .\n";
        cout << "4->reservation room for guests .\n";
        cout << "5->change information \n";
        cout << "6-> See list citizens\n";
        cout << "7-> checkout\n";
        cout << "8->logout .\n";
        cout << "*********************************\n";
        cout << "Enter your Choice number : \n";
        cin >> number;
        switch (number) {
            case 1: {
                see_room_information();
                break;
            }
            case 2: {
                system("clear");
                see_status_room_information();
                break;
            }
            case 3: {
                system("clear");
                room_reservation_requests();
                break;
            }
            case 4: {
                system("clear");
                reservation_room_guests();
                break;
            }
            case 5: {
                system("clear");
                change_informatin_personnel();
                break;
            }
            case 6: {
                system("clear");
                See_list_citizens();
                break;
            }
            case 7: {
                system("clear");
                checkout();
                break;
            }
            case 8: {
                system("clear");
                menu();
                break;
            }
            default:
                cout << "Pelase Enter rigth number.";
        }
    }
}

//function for checkout citizens
void checkout() {
    while (1) {
        ifstream checkout;
        ofstream checkout_out;
        ifstream checkout_room;
        ofstream checkout_room_out;
        checkout.open("reservations_room.dat", ios::in);
        checkout_room.open("room_information_file.dat", ios::in);
        string checkouting[1000];
        string checkouting_room[1000];
        for (int i = 0; i < 1000; i++) {
            checkout >> checkouting[i];
            checkout_room >> checkouting_room[i];
        }
        string id_for_checkout;
        char ch;
        cout << "are you checout in list[y/n]\n";

        while (true) {
            cin >> ch;
            if (ch == 'y' || ch == 'Y') {
                cout << "enter code reservtion for checout\n";
                cin >> id_for_checkout;
                int m = 0;
                for (int i = 0; i < 1000; i += 7) {
                    for (int j = 0; j < 1000; j += 6) {
                        if (checkouting_room[i] == checkouting[j + 4]) {
                            checkouting_room[i + 1] = "0";
                        }
                    }
                }
                for (int i = 0; i < 1000; i += 6) {
                    m = i;
                    if (checkouting[i] == id_for_checkout) {
                        for (int j = i; j < 1000; j++) {
                            checkouting[j] = checkouting[j + 6];
                        }
                    }
                }

                checkout_out.open("reservations_room.dat", ios::out);
                checkout_room_out.open("room_information_file.dat", ios::out);
                for (int i = 0; i < 1000; i++) {
                    checkout_room_out << checkouting_room[i] << "\n";
                    if (checkouting_room[i + 1].empty())
                        break;
                }
                for (int i = 0; i < 1000; i++) {
                    checkout_out << checkouting[i] << "\n";
                    if (checkouting[i + 1].empty())
                        break;
                }
                checkout_room_out.close();
                checkout_out.close();
                break;
            } else if (ch == 'n' || ch == 'N') {
                break;
            } else {
                cout << "enter true word .\n";
                continue;
            }
        }
    }
    system("clear");
    if (id_personneluser.empty()) {
        superuser();
    } else {
        personneluser();
    }

}
//end function for checkout citizens

//function change information superuser
void change_informatin_superuser() {
    while (1) {
        string information_personnel[100];
        ifstream personnel_information_in;
        personnel_information_in.open("superuser.dat", ios::in);
        for (int i = 0; i < 1000; i++) {
            personnel_information_in >> information_personnel[i];
        }
        cout << "+----------------------------------------------------+\n";
        for (int j = 0; j < 1000; j += 5) {
            if (information_personnel[j] == id_personneluser) {
                cout << "| your login by NAME " << information_personnel[j + 1] << " and ID "
                     << information_personnel[j]
                     << " |\n";
                break;
            }
        }
        cout << "+----------------------------------------------------+\n\n";
        cout << "1->change_information.\n";
        cout << "2->change_username_password .\n";
        cout << "3->logout .\n";

        cout << "Enter your Choice number : \n";
        int number;
        cin >> number;
        switch (number) {
            case 1: {
                system("clear");
                change_information_superuser();
                break;
            }
            case 2: {
                system("clear");
                change_username_password();
                break;
            }
            case 3: {
                system("clear");
                menu();
                break;
            }
        }
        break;
    }


}

//end function change information superuser
//function change information personnel
void change_informatin_personnel() {
    while (1) {
        string information_personnel[100];
        ifstream personnel_information_in;
        personnel_information_in.open("personnel.dat", ios::in);
        for (int i = 0; i < 1000; i++) {
            personnel_information_in >> information_personnel[i];
        }
        cout << "+----------------------------------------------------+\n";
        for (int j = 0; j < 1000; j += 5) {
            if (information_personnel[j] == id_personneluser) {
                cout << "| your login by NAME " << information_personnel[j + 1] << " and ID "
                     << information_personnel[j]
                     << " |\n";
                break;
            }
        }
        cout << "+----------------------------------------------------+\n\n";
        cout << "1->change_information.\n";
        cout << "2->change_username_password .\n";
        cout << "3->logout .\n";

        cout << "Enter your Choice number : \n";
        int number;
        cin >> number;
        switch (number) {
            case 1: {
                system("clear");
                change_information();
                break;
            }
            case 2: {
                system("clear");
                change_username_password();
                break;
            }
            case 3: {
                system("clear");
                menu();
                break;
            }
        }
        break;
    }
}
//end function change information personnel

//function for change infortamion personnel user by superuser
void change_information() {
    while (1) {
        string information_personnel[1000];
        ifstream personnel_information_in;
        ofstream personnel_information_out;
        personnel_information_in.open("personnel.dat", ios::in);
        for (int i = 0; i < 1000; i++) {
            personnel_information_in >> information_personnel[i];
        }
        string ID, newname, newfamily;

        int m = 0;
        while (1) {
            cout << "Enter your ID .\n";
            cin >> ID;
            for (int i = 0; i < 1000; i += 5) {
                if (ID == information_personnel[i]) {
                    cout << "Enter new name .\n";
                    cin >> newname;
                    cout << "Enter new family .\n";
                    cin >> newfamily;
                    information_personnel[m + 1] = newname + newfamily;
                    break;
                }
            }
            break;
        }
        personnel_information_out.open("personnel.dat", ios::out);
        for (int i = 0; i < 1000; i++) {
            personnel_information_out << information_personnel[i] << endl;
            if (information_personnel[i + 1].empty())
                break;
        }
        break;
    }
    system("clear");
    personneluser();
}
//end function for change infortamion personnel user by superuser

//function for change infortamion superuser
void change_information_superuser() {
    while (1) {
        string information_superuser[100];
        ifstream information_superuser_in;
        ofstream information_superuser_out;
        information_superuser_in.open("superuser.dat", ios::in);
        for (int i = 0; i < 10; i++) {
            information_superuser_in >> information_superuser[i];
        }
        string ID, newname, newfamily;

        int m = 0;
        while (1) {
            cout << "Enter your ID .\n";
            cin >> ID;
            if (ID == information_superuser[0]) {
                cout << "Enter new name .\n";
                cin >> newname;
                cout << "Enter new family .\n";
                cin >> newfamily;
                information_superuser[1] = newname;
                information_superuser[2] = newfamily;
                break;
            }
        }
        information_superuser_out.open("superuser.dat", ios::out);
        for (int i = 0; i < 5; i++) {
            information_superuser_out << information_superuser[i] << endl;
            if (information_superuser[i + 1].empty())
                break;
        }
        information_superuser_out.close();

        break;
    }
    system("clear");
    superuser();
}
//end function for change infortamion superuser

//function for change username and password by personnel user
void change_username_password() {
    int m = 0;
    while (1) {
        string change_user_pass[1000];
        ifstream change_user_pass_in;
        ofstream change_user_pass_out;
        change_user_pass_in.open("login.dat", ios::in);
        for (int i = 0; i < 1000; i++) {
            change_user_pass_in >> change_user_pass[i];
        }
        change_user_pass_in.close();

        string username, password, newpassword1, newpassword2;

        cout << "Enter your username .\n";
        cin >> username;
        cout << "Enter your password .\n";
        cin >> password;
        password = md5(md5(password));

        for (int i = 0; i < 1000; i += 2) {
            m = i;
            if (username == change_user_pass[i] && password == change_user_pass[i + 1]) {
                while (1) {
                    cout << "Enter new password .\n";
                    cin >> newpassword1;
                    newpassword1 = md5(md5(newpassword1));
                    cout << "Enter new password again.\n";
                    cin >> newpassword2;
                    newpassword2 = md5(md5(newpassword2));
                    if (newpassword1 == newpassword2) {
                        change_user_pass[m + 1] = newpassword1;
                        break;
                    } else {
                        continue;
                    }
                }

            }

        }
        change_user_pass_out.open("login.dat", ios::out);
        for (int k = 0; k < 1000; k++) {
            if (change_user_pass[k].empty())
                break;
            change_user_pass_out << change_user_pass[k] << "\n";
        }
        change_user_pass_out.close();

        break;
    }

    system("clear");
    if (m == 0) {
        superuser();
    } else if (m >= 2) {
        personneluser();
    }
}
//end function for change username and password by personnel user

//================================ functions for personneluser ===========================================

//function for rooms empty or not empty
void see_room_information() {
    while (1) {
        string room_information_file[100], room_information_filea[100];
        string boolroom, bednumber;
        rooms room;
        ifstream room_information_file_in;
        room_information_file_in.open("room_information_file.dat", ios::in);
        if (!room_information_file_in.fail()) {
            for (int i = 0; i < 100; i++) {
                room_information_file_in >> room_information_filea[i];
                room_information_file[i] = room_information_filea[i];
            }
        } else
            cout << "can not opne file.\n ";
        room_information_file_in.close();
        cout << "+-------------+-------------+------------++\n";
        cout << "| number room | status room | bed number |\n";
        cout << "+-------------+-------------+------------+\n";

        for (int i = 0; i < 1000; i += 7) {
            if (room_information_file[i] == "")
                break;
            if ("1" == room_information_file[i + 1]) {
                boolroom = "not empty";
            } else if ("0" == room_information_file[i + 1])
                boolroom = "empty";

            if ("bednumber:double" == room_information_file[i + 3]) {
                bednumber = "double";
            } else if ("bednumber:single" == room_information_file[i + 3]) {
                bednumber = "single";
            } else if ("bednumber:triad" == room_information_file[i + 3])
                bednumber = "triad";

            int room[1000];
            int bed[1000];
            room[i] = room_information_file[i].length();
            bed[i] = room_information_file[i + 3].length();
            if (room[i] == 3) {
                if (boolroom == "empty") {
                    cout << "|    " << room_information_file[i] << "      |    " << boolroom << "    |    " << bednumber
                         << "  |\n";
                    cout << "+-------------+-------------+------------+\n";
                } else {
                    cout << "|    " << room_information_file[i] << "      |  " << boolroom << "  |    " << bednumber
                         << "   |\n";
                    cout << "+-------------+-------------+------------+\n";
                }
            } else if (room[i] == 4) {
                if (boolroom == "empty") {
                    cout << "|    " << room_information_file[i] << "     |    " << boolroom << "    |    " << bednumber
                         << "   |\n";
                    cout << "+-------------+-------------+------------+\n";
                } else {
                    cout << "|    " << room_information_file[i] << "     |  " << boolroom << "  |    " << bednumber
                         << "   |\n";
                    cout << "+-------------+-------------+------------+\n";
                }
            }
        }
        break;
    }
    system("clear");
    personneluser();
}
// end function for rooms empty or not empty

// function for see list citizens
void See_list_citizens() {
    while (1) {
        string citizens[1000];
        ifstream See_list_citizens_in;
        See_list_citizens_in.open("reservations_room.dat", ios::in);
        for (int j = 0; j < 1000; j++) {
            See_list_citizens_in >> citizens[j];
        }
        cout << "+---------------+-----------+-----------+\n";
        cout << "|  number room  +    name   | ID number |\n";
        cout << "+---------------+-----------+-----------+\n";
        for (int i = 0; i < 1000; i++) {
            if (citizens[i + 5] == "1") {
                cout << citizens[5] << " | " << citizens[1] + citizens[2] << " | " << citizens[i] << " | \n";
            }
        }
        break;
    }
    system("clear");
    if (id_personneluser.empty())
        superuser();
    else personneluser();
}
// end function for see list citizens

// function for  see resident information by personnel user
void see_status_room_information() {
    while (1) {
        string room_information_file[100], room_information_filea[100];
        string boolroom;
        rooms room;
        ifstream room_information_file_in;
        room_information_file_in.open("room_information_file.dat", ios::in);
        if (!room_information_file_in.fail()) {
            for (int i = 0; i < 100; i++) {
                room_information_file_in >> room_information_filea[i];
                room_information_file[i] = room_information_filea[i];
            }
        } else
            cout << "can not open file .\n";
        room_information_file_in.close();
        cout << "+-------------+-------------+\n";
        cout << "| number room | status room |\n";
        cout << "+-------------+-------------+\n";

        for (int i = 0; i < 1000; i += 7) {
            if (room_information_file[i] == "")
                break;
            if ("1" == room_information_file[i + 1]) {
                boolroom = "not empty";
            } else if ("0" == room_information_file[i + 1])
                boolroom = "empty";
            int room[1000];
            room[i] = room_information_file[i].length();
            if (room[i] == 3) {
                if (boolroom == "empty") {

                    cout << "|    " << room_information_file[i] << "      |    " << boolroom << "    |\n";
                    cout << "+-------------+-------------+\n";
                } else {
                    cout << "|    " << room_information_file[i] << "      |  " << boolroom << "  |\n";
                    cout << "+-------------+-------------+\n";
                }
            } else if (room[i] == 4) {
                if (boolroom == "empty") {

                    cout << "|    " << room_information_file[i] << "     |    " << boolroom << "    |\n";
                    cout << "+-------------+-------------+\n";
                } else {
                    cout << "|    " << room_information_file[i] << "     |  " << boolroom << "  |\n";
                    cout << "+-------------+-------------+\n";
                }
            }
        }
        break;
    }
    system("clear");
    if (id_personneluser.empty())
        superuser();
    else personneluser();
}
// end function for see resident information by personnel user

//function for room reservation requests
void room_reservation_requests() {
    while (1) {
        string reservation_room[1000];
        ifstream reservations_room_in;
        ifstream room_information_file_in;
        ofstream room_information_file_out;
        reservations_room_in.open("reservations_room.dat", ios::in);

        room_information_file_in.open("room_information_file.dat", ios::in);

        for (int i = 0; i < 1000; i++) {
            reservations_room_in >> reservation_room[i];
        }
        string room_information[1000];
        for (int j = 0; j < 1000; j++) {
            room_information_file_in >> room_information[j];
        }

        string status;
        for (int i = 0; i < 1500; i += 6) {
            if (reservation_room[i + 5] == "0") {
                status = "checking";
                break;
            } else if (reservation_room[i + 5] == "1") {
                status = "confirm";
                break;
            }
        }
        if (reservation_room[0] != "") {
            cout << "new requests reservation !\n";
            cout << "+----------+------+-----------------+-------+---------+\n";
            cout << "|  code    | room | name & famliy   | days |  status |\n";
            cout << "+----------+------+-----------------+-------+---------+\n";
            for (int i = 0; i < 1000; i += 6) {

                if (reservation_room[i + 3] == " " || reservation_room[i + 3].empty())
                    break;
                if (reservation_room[i + 4].length() == 3) {
                    cout << "|  " << reservation_room[i] << "  |  " << reservation_room[4 + i] << " | "
                         << reservation_room[1 + i] << " " << reservation_room[2 + i] << " | "
                         << reservation_room[3 + i]
                         << " | " << status << " |\n";

                } else if (reservation_room[i + 4].length() == 4) {
                    cout << "|  " << reservation_room[i] << "  |  " << reservation_room[1 + i] << " "
                         << reservation_room[2 + i] << "  | "
                         << reservation_room[3 + i] << " | " << reservation_room[4 + i]
                         << "  | " << status << " |\n";
                }

                cout << "+----------+------+-----------------+-------+---------+\n";

            }

            char a;
            while (1) {
                cout << "Enter [y/n].\n";
                cin >> a;
                if (a == 'y' || a == 'Y') {
                    cout << "Enter room number \n";
                    string number_room;
                    cin >> number_room;
                    int m;
                    for (int i = 0; i < 1000; i += 7) {
                        m = i;
                        if (room_information[i] == number_room) {

                            room_information[m + 1] = "1";

                        } else
                            continue;
                    }
                    m = 0;
                    for (int i = 4; i < 1000; i += 6) {
                        m = i;
                        if (reservation_room[i] == number_room) {

                            reservation_room[m + 1] = "1";

                        } else
                            continue;
                    }
                    room_information_file_out.open("room_information_file.dat", ios::out);
                    for (int k = 0; k < 1000; k++) {
                        if (room_information[k].empty())
                            break;
                        room_information_file_out << room_information[k] << "\n";
                    }

                    room_information_file_out.close();
                    room_information_file_in.close();
                    ofstream reservations_room_out;
                    reservations_room_out.open("reservations_room.dat", ios::out);
                    if (!reservations_room_out.fail())
                        for (int k = 0; k < 1000; k++) {
                            if (reservation_room[k].empty())
                                break;
                            reservations_room_out << reservation_room[k] << "\n";
                        }

                    reservations_room_out.close();
                    system("clear");
                    personneluser();
                    break;


                } else if (a == 'n' || a == 'N') {
                    system("clear");
                    personneluser();
                    break;
                } else {
                    cout << "Enter true word .";
                    continue;

                }
            }
        } else {
            cout << "no new requests reservation .\n";
            system("clear");
            personneluser();
        }
        reservations_room_in.close();
        break;
    }
    system("clear");
    if (id_personneluser.empty())
        superuser();
    else personneluser();
}
//end function for room reservation requests

// function for reservation room guests  by personnel user
void reservation_room_guests() {
    while (1) {


        string room_information_file[100], room_information_filea[100];
        string boolroom, bednumber;
        rooms room;
        ifstream room_information_file_in;
        ofstream reservations_room_personnel;
        ifstream reservations_room_in;
        room_information_file_in.open("room_information_file.dat", ios::in);
        if (!room_information_file_in.fail()) {
            for (int i = 0; i < 100; i++) {
                room_information_file_in >> room_information_filea[i];
                room_information_file[i] = room_information_filea[i];
            }
        } else
            cout << "can not open file.\n";
        room_information_file_in.close();
        cout << "+-----------+----------+-----------------------------------+------------+----------+\n";
        cout << "|number room|bed number|  description                      |  property  |  rent    +\n";
        cout << "+-----------+----------+-----------------------------------+------------+----------+\n";

        for (int i = 0; i < 1000; i += 7) {

            if (room_information_file[i].empty())
                break;
            if ("1" == room_information_file[i + 1]) {
                boolroom = "not empty";
            } else if ("0" == room_information_file[i + 1])
                boolroom = "empty";

            if ("bednumber:double" == room_information_file[i + 3]) {
                bednumber = "double";
            } else if ("bednumber:single" == room_information_file[i + 3]) {
                bednumber = "single";
            } else if ("bednumber:triad" == room_information_file[i + 3])
                bednumber = "triad";

            if (boolroom == "empty") {
                if (bednumber.length() == 7) {
                    cout << "|    " << room_information_file[i] << "    |  " << bednumber << "  | "
                         << room_information_file[i + 5]
                         << "|"
                         << room_information_file[i + 4] << "  |" << room_information_file[i + 2] << "|\n";
                    cout << "+-----------+----------+------------+\n";
                } else if (bednumber.length() == 5) {
                    cout << "|    " << room_information_file[i] << "    |  " << bednumber << "   | "
                         << room_information_file[i + 5]
                         << "|"
                         << room_information_file[i + 4] << "  |" << room_information_file[i + 2] << "|\n";
                    cout << "+-----------+----------+------------+\n";
                }
            }

        }
        cout << "\n\n";
        string reservations[1000], room_information[1000];
        for (int i = 0; i < 1000; i++) {
            reservations_room_in >> reservations[i];
        }
        string number_room, days;
        cout << "Enter number room for reservations : \n";
        getline(cin, number_room);
        getline(cin, number_room);
        for (int i = 0; i < 1000; i += 7) {
            if (number_room == room_information_file[i] && "0" == room_information_file[i + 1])
                break;

        }
        cout << "Enter days egamat : \n";
        cin >> days;

        bool status_reservations = true;

        int m;
        for (int i = 0; i < 1000; i += 7) {
            m = i;
            if (room_information_file[i] == number_room) {

                room_information_file[m + 1] = "1";

            } else
                continue;
        }
        ofstream room_information_file_out;
        room_information_file_out.open("room_information_file.dat", ios::out);
        for (int k = 0; k < 1000; k++) {
            if (room_information_file[k].empty())
                break;
            room_information_file_out << room_information_file[k] << "\n";
        }
        room_information_file_out.close();
        room_information_file_in.close();
        personneluser();
        reservations_room_personnel.open("reservations_room_personnel.dat", ios::app);
        reservations_room_personnel << "\n" << days << "\n" << number_room << "\n" << status_reservations << "\n";
        reservations_room_personnel.close();
        break;
    }
    system("clear");
    ordinaryuser();
}
// end function for reservation room guests  by personnel user

//================================ end functions for personneluser===========================================

//========================================= functions ordinaryuser =======================

void ordinaryuser() {
    int number;
    cout << "1-Reservations room \n";
    cout << "2->Room tracking\n";
    cout << "3->menu\n";
    cout << "**************************************\n";
    cout << "Enter your Choice number : \n";
    cin >> number;

    switch (number) {
        case 1: {
            system("clear");
            reservations_room();
            break;
        }
        case 2: {
            system("clear");
            room_tracking();
            break;
        }

        case 3: {
            system("clear");
            menu();
            break;
        }
    }
}

//function for reservations room by ordinary user
void reservations_room() {
    while (1) {
        string room_information_file[100], room_information_filea[100];
        string boolroom, bednumber, value;
        rooms room;
        string number_room, days;
        ifstream room_information_file_in, reservations_room_in;
        ofstream reservations_room_out;
        room_information_file_in.open("room_information_file.dat", ios::in);
        if (!room_information_file_in.fail()) {
            for (int i = 0; i < 100; i++) {
                room_information_file_in >> room_information_filea[i];
                room_information_file[i] = room_information_filea[i];
            }
        } else
            cout << "can not open file .\n";
        room_information_file_in.close();
        cout
                << "+-----------+-----------+---------------------------------------+------------+---------+--------+\n";
        cout
                << "|number room| bed number|  description                          |  property  | p.value |  rent  |\n";
        cout
                << "+-----------+-----------+---------------------------------------+------------+---------+--------+\n";
        for (int i = 0; i < 1000; i += 7) {

            if (room_information_file[i].empty())
                break;
            if ("1" == room_information_file[i + 1]) {
                boolroom = "not empty";
            } else if ("0" == room_information_file[i + 1])
                boolroom = "empty";

            if ("1" == room_information_file[i + 5]) {
                value = "on";
            } else if ("0" == room_information_file[i + 5])
                value = "off";

            if ("bednumber:double" == room_information_file[i + 3]) {
                bednumber = "double";
            } else if ("bednumber:single" == room_information_file[i + 3]) {
                bednumber = "single";
            } else if ("bednumber:triad" == room_information_file[i + 3])
                bednumber = "triad";

            if (boolroom == "empty") {

                cout << "|   " << room_information_file[i] << "     |  " << bednumber << "   | "
                     << room_information_file[i + 6]
                     << "|"
                     << room_information_file[i + 4] << "  |" << value << " | " << room_information_file[i + 2]
                     << "|\n";
                cout
                        << "+-----------+-----------+---------------------------------------+------------+---------+--------+\n";
            }

        }
        cout << "\n\n";
        string reservations[1000];
        for (int i = 0; i < 1000; i++) {
            reservations_room_in >> reservations[i];
        }

        cout << "Enter your name for reservation room : \n";
        getline(cin, room.residents.name);
        getline(cin, room.residents.name);
        cout << "Enter your family for reservation room : \n";
        getline(cin, room.residents.famliy);

        cout << "Enter number room for reservation : \n";
        getline(cin, number_room);

        for (int i = 0; i < 1000; i += 7) {
            if (number_room == room_information_file[i] && "0" == room_information_file[i + 1])
                break;

        }
        cout << "Enter days remain : \n";
        cin >> days;
        int a = 100000, b = 999999;
        bool oky = true;

        while (oky) {

            room.residents.ID = random() % (b - a) + a;

            for (int i = 0; i < 1000; i += 4) {
                int b = atoi(reservations[i].c_str());
                if (room.residents.ID != b) {
                    oky = false;
                } else
                    continue;
            }
        }
        cout << room.residents.ID << "\n";
        bool status_reservations = false;

        reservations_room_out.open("reservations_room.dat", ios::app);
        reservations_room_out << room.residents.ID << "\n" << room.residents.name << "\n" << room.residents.famliy
                              << "\n"
                              << days << "\n"
                              << number_room << "\n" << status_reservations << "\n";
        reservations_room_out.close();
        sleep(6);

        break;
    }
    system("clear");
    ordinaryuser();
}
//end function for reservations room by ordinary user

// function for room tracking and delete reseration by ordinary user
void room_tracking() {
    while (1) {
        ifstream reservations_room_in;
        ifstream room_information_file_in;
        ofstream reservations_room_out;
        room_information_file_in.open("room_information_file.dat", ios::in);
        reservations_room_in.open("reservations_room.dat", ios::in);
        string reservations_room[100], room_information[1000];
        for (int j = 0; j < 1000; j++) {
            room_information_file_in >> room_information[j];
        }
        for (int j = 0; j < 1000; j++) {
            reservations_room_in >> reservations_room[j];
        }
        string code;
        cout << "enter your code reservation : \n";
        bool oh = true;
        int m = 0;
        while (oh) {
            cin >> code;
            for (int i = 0; i < 1000; i += 6) {

                if (code == reservations_room[i]) {
                    for (int j = 0; j < 1000; j += 7) {
                        if (reservations_room[i + 4] == room_information[j]) {
                            m = j;
                            if (room_information[j + 1] == "0") {
                                cout << "Your request is being processed \n";
                                oh = false;
                            } else if (room_information[j + 1] == "1") {
                                cout << "Your request has been approved .\n";
                                oh = false;

                            }
                        }
                    }
                }
            }
        }
        sleep(3);
        if (room_information[m + 1] == "0") {
            cout << "are you delete reservation requests?[y/n]\n";
            bool oky = true;
            char re;
            while (oky) {
                cin >> re;
                if (re == 'y' || re == 'Y') {
                    reservations_room_out.open("reservations_room.dat", ios::out);
                    for (int k = 0; k < 1000; k += 6) {
                        if (reservations_room[k] == code) {
                            for (int h = 0; h < 1000; h++) {
                                reservations_room[h] = reservations_room[h + 6];
                                if (reservations_room[h + 7].empty())
                                    oky = false;
                            }
                        }
                    }
                    for (int g = 0; g < 1000; g++) {
                        if (reservations_room[g].empty())
                            break;
                        reservations_room_out << reservations_room[g] << "\n";
                    }
                    reservations_room_out.close();
                } else if (re == 'n' || re == 'N') {
                    oky = false;
                } else {
                    cout << "enter true word .";
                }
            }
        }

        room_information_file_in.close();

        reservations_room_in.close();

        break;
    }
    system("clear");
    ordinaryuser();
}
//end function for room tracking and delete reseration by ordinary user

//========================================= end functions ordinaryuser =======================

//end project yesssssssssssssssssssssssss!!!!!!!!!!!!!!!!
