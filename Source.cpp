// author А.С. Гадиатулин group CPLUS-1006 block Base constructions of C++ module Result
#include <iostream>
#include "Utilites.h"
#include <string>
#include "Message.h"
#include <cstdlib>
#include <map>
#include <vector>

using namespace std;

int main() {
	setlocale(LC_ALL, "Russian");

	User currentUser = Handler1();

	map<string, string> containers;
	map<string, string> allContainers;

	cout << " main " << currentUser << endl;
	int counter = 0;
	while (true) {
		cout << "Menu2: \n"
			 << "1-write text to user\n"
			 << "2-go previous menu\n"
			 << "3-show local chat\n"
			 << "4-show all chat\n"
			 << "5-exit\n";
		cin >> counter;
		if (counter == 1) {
			// write message
			cout << "Input login from write message: \n";
			string loginSource;
			cin >> loginSource;
			cout << "Input login to write message: \n";
			string loginTarget;
			cin >> loginTarget;
			string flag;
			cout << "Input word for 'local' or 'all' create message: \n";
			cin >> flag;
			cout << "Write your message, and input @: \n";
			string str1;
			getline(cin, str1, '@');
			Message message1(loginSource, loginTarget, str1);
			if (flag == "local") {
				cout << "[" << loginTarget << "]: " << message1.getText() << endl;
				containers.insert(make_pair(loginTarget, message1.getText()));
			}
			else if (flag == "all") {
				for (auto& item : users) {
					allContainers.insert(make_pair(item.getUserLogin(), message1.getText()));
				}
				containers.insert(make_pair(loginTarget, message1.getText()));
			}
		}
		if (counter == 2) {
			// go to previous menu
			Handler1();
		}
		if (counter == 3) {
			// show local chat
			cout << "--------LocalChat------------" << endl;
			for (auto& item : containers) {
				cout << "login: " << item.first
					 << "\nmessage: " << item.second << endl;
			}
			cout << "--------------" << endl;
		}
		if (counter == 4) {
			// show for all chat
			cout << "--------AllChat------------" << endl;
			for (auto& item : allContainers) {
				cout << "login: " << item.first
					<< "\nmessage: " << item.second << endl;
			}
			cout << "--------------" << endl;
		}
		if (counter == 5) {
			break;
		}
		counter++;
	}

	std::cout << "Game over" << std::endl;
	return 0;
}