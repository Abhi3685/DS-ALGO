#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void slidingWindowMaximum(vector<int> &arr, int n, int k) {
    vector<int> nge(n);
    stack<int> st;
    st.push(n - 1);
    nge[n - 1] = n;

    for(int i = n - 2; i >= 0; i--){
      while(!st.empty() && arr[i] >= arr[st.top()]){
        st.pop();
      }

      if(st.empty()){
        nge[i] = n;
      } else {
        nge[i] = st.top();
      }

      st.push(i);
    }

    for(int i = 0; i <= n - k; i++){
      int j = i;
      while(nge[j] < i + k){
        j = nge[j];
      }
      cout << arr[j] << endl;
    }
}

void infixConversion(string exp){
    stack<string> postfix, prefix;
    stack<char> operators;

    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];

        if (ch == '(') {
            operators.push(ch);
        } else if ((ch >='0' && ch <= '9') || (ch >='a' && ch <= 'z') || (ch >='A' && ch <= 'Z'))  {
            postfix.push(to_string(ch));
            prefix.push(to_string(ch));
        } else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (operators.size() > 0 && operators.top() != '(' && precedence(ch) <= precedence(operators.top())) {
                char op = operators.pop();

                String postval2 = postfix.pop();
                String postval1 = postfix.pop();
                postfix.push(postval1 + postval2 + op);

                String preval2 = prefix.pop();
                String preval1 = prefix.pop();
                prefix.push(op + preval1 + preval2);
            }

            operators.push(ch);
        } else if (ch == ')') {
            while (operators.size() > 0 && operators.top() != '(') {
                char op = operators.pop();

                String postval2 = postfix.pop();
                String postval1 = postfix.pop();
                postfix.push(postval1 + postval2 + op);

                String preval2 = prefix.pop();
                String preval1 = prefix.pop();
                prefix.push(op + preval1 + preval2);
            }

            if (operators.size() > 0) {
                operators.pop();
            }
        }
    }

    while (operators.size() > 0) {
        char op = operators.pop();

        String postval2 = postfix.pop();
        String postval1 = postfix.pop();
        postfix.push(postval1 + postval2 + op);

        String preval2 = prefix.pop();
        String preval1 = prefix.pop();
        prefix.push(op + preval1 + preval2);
    }

    cout << postfix.top() << endl;
    cout << prefix.top() << endl;
}

int precedence(char op) {
    if (op == '+') {
        return 1;
    } else if (op == '-') {
        return 1;
    } else if (op == '*') {
        return 2;
    } else {
        return 2;
    }
}

int main(){
    vector<int> arr = { 2, 9, 3, 8, 1, 7, 12, 6, 14, 4, 32, 0, 7, 19, 8, 12, 6 };
    slidingWindowMaximum(arr, arr.size(), 4);

    infixConversion("a*(b-c+d)/e");

    return 0;
}