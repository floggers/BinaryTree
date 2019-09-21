#include<iostream>
using namespace std;

template <typename T>
class Vector {
	int m_size;
	int m_capacity;
	T*p;
public:
	Vector() {};
	Vector(int size, T data) {
		this->m_capacity = 20+size;
		this->m_size = size;
		this->p = new T[m_capacity];
		for (int i = 0;i < this->m_size;i++) {
			this->p[i] = data;
		}
	}
	~Vector(){
		if (p!=NULL){
			delete[] p;
		}
	}
	Vector(const Vector& v) {
		this->m_capacity = v.m_capacity;
		this->m_size = v.m_size;
		this->p = new T[this->m_capacity];
		memcpy(this->p, v.p, this->m_size * sizeof(T));
	}
	void push_back(T data)	{
		if (this->p == NULL)	{
			this->m_capacity = 20;
			this->m_size = 0;
			T *p = new T[m_capacity];
		}
		if (this->m_size == this->m_capacity){
			T *new_p = new T[this->m_capacity * 2];
			memcpy(new_p, p, this->m_size * sizeof(T));
			this->m_capacity *= 2;
			delete[] p;
			p = new_p;
		}
		this->p[this->m_size] = data;
		this->m_size++;
	}
	void pop_back()
	{
		if (this->m_size > 1)
		{
			this->p[this->m_size - 1] = 0;
			this->m_size--;
		}
	}
	void insert(int pos, T data) {
			if (pos >= 0 && pos <= this->m_size){
				if (this->m_size == this->m_capacity){
					T *new_p = new T[this->m_capacity * 2];
					memcpy(new_p, p, this->m_size * sizeof(T));
					this->m_capacity *= 2;
					delete[] p;
					p = new_p;
				}
				for (int i = this->m_size;i > pos;i--){
					this->p[i] = this->p[i - 1];
				}
				this->p[pos] = data;
				this->m_size++;
			}
	}
	void erase(int pos) {
		if (pos < 0 || pos >= this->m_size) {
			return ;
		}
			for (int i = pos;i <this->m_size;i++) {
				this->p[i] = this->p[i+1];
			}
			this->m_size--;
	}
	T& operator[](int index)
	{
		if (index >= 0 && index <= this->m_size)
		{
			return this->p[index];
		}
	}
};

int main() {
	Vector<int> v(10,3);
	for (int i = 0;i < 10;i++) {
		v.push_back(i);
}
	v.insert(10, 25);
	for (int i = 0;i < 21;i++) {
		cout << v[i] << ' ';
	}
	cout << endl;
	v.erase(5);
	for (int i = 0;i < 20;i++) {
		cout << v[i] << ' ';
	}
	cout << endl;
	system("pause");
	return 0;
}