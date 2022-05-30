#include <iostream>
#include <string>
#include <exception>
using namespace std;

class Empty
{};

class Error
{
	string message;
public:
	Error(string message)
		: message(message)
	{}

	string What() { return message; }
};
class E : public exception
{
	string message;
public:
	E(string message)
		: message(message)
	{}

	string What() { return message; }
};

int wholePart1(int numerator, int denominator) {
	if (denominator == 0)
		throw 1;
	return numerator / denominator;
}

int wholePart2(int numerator, int denominator) throw() {
	if (denominator == 0)
		throw 1.0;
	return numerator / denominator;
}

int wholePart3(int numerator, int denominator) throw(char) {
	if (denominator == 0)
		throw '1';
	return numerator / denominator;
}

int wholePart4(int numerator, int denominator) throw(Empty) {
	if (denominator == 0)
		throw Empty();
	return numerator / denominator;
}

int wholePart5(int numerator, int denominator) throw(Error) {
	if (denominator == 0)
		throw Error("Denominator can not be equal to zero");
	return numerator / denominator;
}

int wholePart6(int numerator, int denominator) throw(int) {
	if (denominator == 0)
		throw E("Denominator can not be equal to zero");
	return numerator / denominator;
}

void FU() {
	cout << "unexpected error! - bad_exception" << endl;
	throw;
}
void FT() {
	cout << "unknown error! - terminate" << endl;
	abort();
}

int main() {
	set_unexpected(FU);

	int numerator;
	cout << "Enter numerator : "; cin >> numerator;

	int denominator;
	cout << "Enter denominator : "; cin >> denominator;

	try {
		//cout << wholePart1(numerator, denominator) << endl;
		//cout << wholePart2(numerator, denominator) << endl;
		//cout << wholePart3(numerator, denominator) << endl;
		//cout << wholePart4(numerator, denominator) << endl;
		//cout << wholePart5(numerator, denominator) << endl;
		cout << wholePart6(numerator, denominator) << endl;
	}
	catch (int) {
		cout << "catch(int) - wholePart1()" << endl;
	}
	catch (double) {
		cout << "catch(double) - wholePart2()" << endl;
	}
	catch (char) {
		cout << "catch(char) - wholePart3()" << endl;
	}
	catch (Empty) {
		cout << "catch(Empty) - wholePart4()" << endl;
	}
	catch (Error e) {
		cout << "catch(Error) - wholePart5() : " << endl;
		cout << e.What();
	}
	catch (bad_exception) {
		cout << "catch(bad_exception)";
	}
	catch (exception) {
		cout << " catch (exception) <= IsVysokosny6() :" << endl;
	}
	 catch (E e) {
		cout << " catch (E) <= IsVysokosny6() :" << endl;
		cout << e.What() << endl;
	 }


	system("pause");
	return 0;
}
