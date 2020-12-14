#include "User.h"


void User::workWithUsersData(List <User>& users) {

    char ans;
    User user;
    while (true) {
        cout << "\n----------Режим работы с учётными записями----------------------------\n";
        cout << " 1 - Просмотр пользователей\n 2 - Удаление пользователя \n 3 - Изменение статуса пользователя\n 0 - Выход в меню\n";
        cout << "\t -> ";
        cin >> ans;
        switch (ans) {
        case '0': return;
        case '1': users.show(); break;
        case '2': deleteUsers(users); break;
        case '3': changeRole(users); break;
        default: cout << "Ошибка. Пункта меню не существует.\n";
        }
    }
}

void User::changeRole(List <User>& users) {
    int number;
    User user;
    cout << "Введите номер пользователя: ";
    cin >> number;
    user = users[number];
    user.role = (user.role + 1) % 2;
    users.replace(user, number);
    if (user.role == 1)
        cout << "Присвоен статус администратора. ";
    else
        cout << "Присвоен статус пользователя. ";
}

void User::deleteUsers(List <User>& users) {
    int number;
    User user;
    cout << "Введите номер пользователя: ";
    cin >> number;
    user = users[number];
    user.role = (user.role + 1) % 2;
    users.replace(user, number);
    if (user.role == 1)
        cout << "Ошибка! Вы не можете удалить аккаунт администратора.\n";
    else {
        users.clear(number);
        cout << "Удаление выполнено успешно.\n";
    }
}

void User::header() {
    cout << "----------------------------------------------\n";
    cout << "||" << setw(42) << "         Учетные записи              " << "||\n";
    cout << "----------------------------------------------\n";
    cout << "||" << setw(5) << " №  " << "||" << setw(15) << "    Логин    " << "||" << setw(18) << " Статус     " << "||\n";
    cout << "----------------------------------------------\n";
}

istream& operator >> (istream& in, User& user)
{
    string login, password;
    cout << "Введите логин: ";
    in >> user.login;
    cout << "Введите пароль: ";
    password = User::stars();
    user.salt = User::passwordsalt();
    user.hash_password = User::myhash(password + user.salt);
    user.role = 0;
    return in;
}

ostream& operator << (ostream& out, const User user)
{
    out << "||";
    out << setw(15) << user.login;
    out << "||";
    out << setw(18) << arrayOfRoles[user.role];
    out << "||\n";
    cout << "----------------------------------------------\n"; 
    return out;
}

bool User::operator == (const string other) {
    if (this->login == other)
        return true;
    else
        return false;
}

void User::signUp(List <User>& users) {
	string login, password, password2;
    User newUser;
    while(true) {
        cin >> newUser;
        if (users.exist(newUser.login) != -1) {
            cout << "Выбранный логин уже существует. Попробуйте еще раз.\n";
        }
        else {
            cout << "Повторите пароль: ";
            password2 = stars();
            if (newUser.hash_password != myhash(password2 + newUser.salt))
                cout << "Ошибка! Пароли не совпадают. Попробуйте еще раз.\n";
            else
                break;
        }
    } 
	users.push(newUser);
	cout << "Регистрация выполнена.\n";
}

int User::signIn(List <User>& users) {
	string login, password;
	char ans;
    int number;
    User user;
	while (true) {
		cout << "Введите логин: ";
		cin >> login;
        number = users.exist(login);
        if (number != -1) {
            user = users[number];
            cout << "Введите пароль: ";
            password = stars();
            if (myhash(password + user.salt) == user.hash_password) {
                cout << "Вход выполнен успешно.\n";
                return user.role;
            }
            else {
                cout << "Неверный пароль (1 - Попробовать еще раз\n 2 - Выход) -> ";
                cin >> ans;
                if (ans == '2')
                    return -1;
            }
        }
        else {
            cout << "Неверный логин (1 - Попробовать еще раз\n 2 - Выход) ->";
            cin >> ans;
            if (ans == '2')
                return -1;
        }
	}
}

void User::readUsers(List <User>& users) {
    int vecsize;
    User user;
    ifstream fin(FILE_OF_USERDATA, ios::in);
    if (!fin.is_open()) {
        user.login = "admin";
        user.salt = passwordsalt();
        user.hash_password = myhash("admin" + user.salt);
        user.role = 1;
        users.push(user);
    }
    else {
        fin >> vecsize;
        for (int i = 0; i < vecsize; i++) {
            fin >> user.login >> user.salt >> user.hash_password >> user.role;
            users.push(user);
        }
    }
    fin.close();
}

void User::rewriteUsers(List <User>& users) {
	ofstream fout(FILE_OF_USERDATA, ios::out);
	fout << users.getSize() << '\n';
	for (int i = 0; i < users.getSize(); i++)
		fout << users[i].login << ' ' << users[i].salt << ' ' << users[i].hash_password << ' ' << users[i].role << '\n';
	fout.close();
}

string User::stars()
{
    string password;
    char symbol;
    while (true) {
        symbol = _getch();
        if (symbol == 13) break;
        if (symbol == 8 && !password.empty())
        {
            cout << symbol;
            password.pop_back();
        }
        if (isalnum((char)symbol))
        {
            cout << '*';
            password += symbol;
        }
    }
    cout << endl;
    return password;
}

string User::passwordsalt()
{
    string Salt;
    int n, temp;
    n = rand() % (25 - 15 + 1) + 15; //salt length
    for (int i = 0; i < n; i++)
    {
        temp = rand() % 3;
        switch (temp) {
        case 1: Salt += rand() % ('Z' - 'A' + 1) + 'A'; //uppercase letters
            break;
        case 2: Salt += rand() % ('z' - 'a' + 1) + 'a'; //lowercase letters
            break;
        case 0: Salt += rand() % ('9' - '0' + 1) + '0'; //numbers
        }
    }
    return Salt;
}

string User:: myhash(string s)
{
    hash <string> hash_s;
    size_t hash = hash_s(s);
    return to_string(hash);
}
