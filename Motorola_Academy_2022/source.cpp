#include <bits/stdc++.h>
using namespace std;

const int MAX_DIGITS_OF_ENTRY = 6;

bool whetherToRun() {
	string s;
	cin >> s;
	if(s=="RUN") {
		return true;
	}
	else {
		return false;
	}
}

bool checkNonNagativeInteger(string s) {
	for(auto c : s) {
		if(!isdigit(c))
			return false;
	}
	return true;
}

bool checkNumberOfDigits(string s) {
	if(s.size() <= MAX_DIGITS_OF_ENTRY) {
		return true;
	}
	else {
		return false;
	}
}


int main() {
	ios_base::sync_with_stdio(0);

	cout << "Type \"RUN\" to start" << '\n';
	while(!whetherToRun()) {
		cout << "Type \"RUN\" to start" << '\n';
	}

	cout << "Specify how many meters of fence is available" << '\n';
	long long availableFence = 0;
	string s = "";
	do {
		cin >> s;
		if(!checkNonNagativeInteger(s)) {
			cout << "Incorrect input. Enter a non-negative integer." << '\n';
		}
		else if(!checkNumberOfDigits(s)) {
			cout << "Incorrect input. Your number is too large. Please enter a smaller number." << '\n';
		}
		else {
			availableFence = stoll(s);
		}
	}while( !checkNonNagativeInteger(s) || !checkNumberOfDigits(s));

	if(availableFence<=2) {
		cout << "The amount of fence is too small to build all 3 segments." << '\n';
	}
	else {
		long long a = 0;
		long long b = 0;
		long long optimalArea = 0;
		for ( long long newA = 1; newA <= availableFence; newA++) {
			for(long long newB = 1; newB <= availableFence; newB++) {
				if(newA*2LL+newB<=availableFence && newA*newB>optimalArea) {
					a = newA;
					b = newB;
					optimalArea = newA * newB;
				} 
			}
		}
		cout << "Results" << '\n';
		cout << "a: " << a << '\n';
		cout << "b: " << b << '\n';
		cout << "the farm are: " << optimalArea << '\n';
	}






	return 0;
}