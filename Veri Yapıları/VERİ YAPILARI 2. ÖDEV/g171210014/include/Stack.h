#ifndef  Stack_H
#define Stack_H
class Stack
{
private:
	int top = 0;
	int Dizi[50];
public:
	Stack();
	void StackElemanEkle(int);
	void StackYazdir();
};
#endif
