#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <cctype>
#include <time.h>
#include <conio.h>
#include <fstream>
#include <iomanip>
#include "List.h"

using namespace std;


const string FILE_OF_USERDATA = "userdata.txt"; //internal file for users accounts
const string arrayOfRoles[3] = { "Пользователь", "Администратор"};

class User
{
private:
	string login;
	string salt;
	string hash_password;
	int role; // 1 - admin, 0 - user;
public:
	User() { login = ""; salt = ""; hash_password = ""; role = 0; }
	~User(){}
	static void workWithUsersData(List <User>& users); //admin's work with users accounts
	static void deleteUsers(List <User>& users);
	static void changeRole(List <User>& users);

	static void readUsers(List <User>& users); //reading accounts from the file
	static void rewriteUsers(List <User>& users); //update user list

	static void signUp(List <User>& users); //user registration
	static int signIn(List <User>& users); //sign into account
	static string stars(); //output stars instead password
	static string myhash(string str);
	static string passwordsalt();

	friend ostream& operator <<(ostream&, const User);
	friend istream& operator >> (istream&, User&);
	bool operator == (const string other);
	void header();
};

