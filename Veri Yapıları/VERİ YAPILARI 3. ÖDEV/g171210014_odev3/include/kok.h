#ifndef kok_HPP
#define kok_HPP
#include <iostream>
class kok
{
private:
	int veri;
	kok *sag = NULL;
	kok *sol = NULL;
public:
	kok(int);
	kok* sagGet();
	kok** sagGet2Pointer();
	kok* solGet();
	kok** solGet2Pointer();
	int veriGet();
	void sagSet(kok*ptr);
	void solSet(kok*ptr);

};

#endif