// class_Screen.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "Screen.h"





int main()
{
	Screen myscreen(5, 5, 'b');
	Window_mgr a;
	myscreen.move(1, 0).set('#').display(cout);
	cout << "\n";
	cout << myscreen.get() << endl;
	cout << myscreen.get(2, 1) << endl;
	myscreen.set(2, 1, 'a').display(cout);
	//	myscreen.display(cout);
	cout << "\n";
	cout << myscreen.size() << endl;
	a.get(0).set(3, 0, 'c').display(cout);
	cout << "\n";

	a.clear(0);
	a.get(0).display(cout);
	cout << "\n";
	return 0;
}

