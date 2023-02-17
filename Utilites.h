#pragma once
#include <iostream>
#include <vector>
#include "User.h"

using namespace std;

vector<User> users;
static vector<User> allUsers;

User Handler1() {
	bool isExit = true;
	char myChoice;
	while (isExit) {
		cout << "\nMenu:"
			 << "\n1-Registrations Users"
			 << "\n2-Create message by login"
			 << "\n4-ShowAllUsers"
			 << "\n5-exit\n";
		cin >> myChoice;
		//cout << "your select " << myChoice << endl;
		if (myChoice == '5') {
			break;
		}
		if (myChoice == '1') {
			// registration user
			cout << "Create you login: \n";
			string myLogin;
			cin >> myLogin;
			cout << "Create you password: \n";
			string myPassword;
			cin >> myPassword;
			cout << "Enter your name: \n";
			string myName;
			cin >> myName;
			User user(myLogin, myPassword, myName);
			users.push_back(user);
			allUsers.push_back(user);
			user.show();
		}
		if (myChoice == '2') {
			cout << "Input index user(0): \n";
			int index = 0;
			cin >> index;
			//cout << "You choose user by login: " << users[index] << endl;
			static User currentUser = users[index];
			cout << "new current user selected " << currentUser;
			cout << "\nAuthorization user \n";
			cout << "Input your login: \n";
			string login;
			cin >> login;
			cout << "Input your password: \n";
			string password;
			cin >> password;
			if (login == currentUser.getUserLogin() && password == currentUser.getUserPassword()) {
				cout << "well done" << endl;
			}
			return currentUser;
		}
		if (myChoice == '4') {
			for (auto item : users) {
				cout << "login: " << item.getUserLogin() 
					 << " password: " << item.getUserPassword() 
					 << " name: " << item.getUserName() << endl;
			}
		}
	}
}