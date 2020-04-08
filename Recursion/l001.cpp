#include <iostream> 
#include <vector> 
using namespace std; 

void printIncreasing(int a, int b) {
	if(a > b) return;
	cout<<a<<" ";
	printIncreasing(a+1, b);
}

void printDecreasing(int a, int b) {
	if(a > b) return;
	printDecreasing(a+1, b);
	cout<<a<<" ";
}

void printIncDec(int a, int b) {
	if(a > b) return;
	if(a%2 != 0) cout<<a<<endl;
	printIncDec(a+1, b);
	if(a%2 == 0) cout<<a<<endl;
}

int power(int x, int y) {
    if(y == 0) return 1;
    return x * power(x, y - 1);
}

void printVector(vector<int> &v, int idx) {
    if(idx == v.size()) return;
    cout << v[idx] << " ";
    printVector(v, idx + 1);
}

int findMax(vector<int> &v, int idx) {
    if(idx == v.size() - 1) return v[idx];
    int recAns = findMax(v, idx + 1);
    int max = recAns > v[idx] ? recAns : v[idx];
    return max;
}

int findMin(vector<int> &v, int idx) {
    if(idx == v.size() - 1) return v[idx];
    int recAns = findMin(v, idx + 1);
    int min = recAns < v[idx] ? recAns : v[idx];
    return min;
}

int findFirst(vector<int> &v, int index, int data) {
	if(index == v.size()) return -1;
	if(v[index] == data) return index;
	return findFirst(v, index + 1, data);
}

int findLast(vector<int> &v, int index, int data) {
	if(index == v.size()) return -1;
	int recAns = findLast(v, index + 1, data);
	if(recAns == -1 && v[index] == data) return index;
	else return recAns;
}

vector<int> findAll(vector<int> &v, int index, int data, int count = 0) {
	if(index == v.size()) {
		vector<int> base(count, 0);
		return base;
	}
	if(v[index] == data) count++;
	vector<int> recAns = findAll(v, index + 1, data, count);
	if(v[index] == data) recAns[count-1] = index;
	return recAns;
}

void subsequence(string s, string ans = "") {
	if(s.size() == 0) {
		cout<<ans<<endl;
		return;
	}
	subsequence(s.substr(1), ans);
	subsequence(s.substr(1), ans+s[0]);
}

vector<string> words = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
vector<string> keypad(string s) {
	if(s.size() == 0) {
		vector<string> base;
		base.push_back("");
		return base;
	}
	int idx = s[0]-'0';
	string word = words[idx];
	vector<string> recAns = keypad(s.substr(1));
	vector<string> myAns;
	for(string ans: recAns) {
		for(int i=0; i<word.size(); i++) {
			myAns.push_back(word[i] + ans);
		}
	}
	return myAns;
}

void solve() {
	// int a = 1, b = 10, n = 4;
	// printIncreasing(a, b);
	// printDecreasing(a, b);
	// printIncDec(a, b);
	// int fact = printFact(n);
	// int pow = power(5, 3);

	// vector<int> v = { 10,12,13,12,5 };
	// printVector(v, 0);
	// cout<<findMax(v, 0)<<endl;
	// cout<<findMin(v, 0)<<endl;
	// cout<<findFirst(v, 0, 12)<<endl;
	// cout<<findLast(v, 0, 12)<<endl;
	// vector<int> ans = findAll(v, 0, 12);
	// for(int n: ans) cout<<n<<" ";

	// string s = "ABC";
	// subsequence(s);
	// vector<string> ans = keypad("456");
	// for(string s: ans) cout<<s<<endl;
}

int main() { 
	solve();
	return 0; 
} 