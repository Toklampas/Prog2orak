#pragma once
 

//elvarom a default konstr es az op= meglétét a T tipustól
template <class T>
class Stack {
private:
	T* pFirst;
	T* pCurrent;
	int size;
public:
	void push(T n);
	T pop();
	Stack(int sizepar);
	Stack(const Stack<T>&s);
	const Stack<T>& operator=(const Stack<T>& s);
	~Stack() { delete[] pFirst; }
};
 
template <class T>
Stack<T>::Stack(int sizepar) {
	size = sizepar;
	pFirst = new T[sizepar]; //default konstruktor
	pCurrent = pFirst;
	

}
 
template <class T>
Stack<T>::Stack(const Stack<T> &s) {
	size = s.size;
	pFirst = new T[s.size];
	pCurrent = s.pCurrent;
	for (int i = 0; i<s.size; i++)
		pFirst[i] = s.pFirst[i];
}
 
template <class T>
void Stack<T>::push(T n) { // régi változatlan
	if (pCurrent - pFirst >= size) //tele
		exit(1);
	else
		*pCurrent++ = n;
}
 
template <class T>
T Stack<T>::pop() { // régi változatlan
	if (pCurrent == pFirst) //üres
		exit(1);
	else
		return *--pCurrent;
}
 
template <class T>
const Stack<T>& Stack<T>::operator=(const Stack<T>& s)
{
	if (size != s.size) {
		delete[] pFirst;
		size = s.size;
		pFirst = new T[s.size];
	}
 
	pCurrent = s.pCurrent;
	for (int i = 0; i<s.size; i++)
		pFirst[i] = s.pFirst[i]; //operator=
 
	return *this;
}


