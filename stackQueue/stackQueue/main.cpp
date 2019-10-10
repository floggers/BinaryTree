#include <stack>
#include <queue>
#include <iostream>
using namespace std;
class stackQueue
{
	stack<int> m_sk1;
	stack<int> m_sk2;
public:
	stackQueue(){

	}

	void push(int x){
		while (m_sk2.size() > 0) {
			int data = m_sk2.top();
			m_sk2.pop();
			m_sk1.push(data);
		}
		m_sk1.push(x);
	}

	void pop(){
		while (m_sk1.size() > 0){
				int data = m_sk1.top();
				m_sk1.pop();
				m_sk2.push(data);
		}
		m_sk2.pop();
	}

	int peek(){
		while (m_sk1.size() > 0) {
			int data = m_sk1.top();
			m_sk1.pop();
			m_sk2.push(data);
		}
		return m_sk2.top();
	}

	bool empty() {
		return m_sk1.size() && m_sk2.size();
	}
};

int main() {
	stackQueue sq;

	sq.push(1);
	sq.push(2);
	sq.push(3);
	sq.push(4);
//	cout << sq.peek() << endl;
	cout << sq.peek() << endl;
	sq.pop();
	cout << sq.peek() << endl;
	cout << sq.peek() << endl;
	sq.pop();
	cout << sq.peek() << endl;
	sq.pop();
	cout << sq.peek() << endl;
	sq.pop();
	system("pause");
	return 0;
}