#pragma once
#include <Windows.h>
#include <iostream>
#include "User.h"
#include "List.h"
#include "eBook.h"
#include "Science.h"
#include "Fiction.h"
#include "Book.h"
#include "Interface2.h"

using namespace std;

class Interface
{
public:
	static void Exit(List <User>& users, List <eBook>& ebooks, List <Science>& science, List <Fiction>& fiction); //exit from the program
	static void adminModule(List <User>& users, List <eBook>& ebooks, List <Science>& science,List <Fiction>& fiction); //main admin's menu
	static void userModule(List <eBook>& ebooks, List <Science>& science, List <Fiction>& fiction); //main user's menu
	static void mainMenu(); //authorization main menu
	
};
