#include "OptionData.hpp"

opData::opData()
{
	init();
}

opData::opData(const opData & opd)
{
	copy(opd);
}

opData::opData(double opK, double opsig, double opr)
{
	K = opK;
	sig = opsig;
	r = opr;
	b = opr;
}

opData::opData(double opK, double opsig, double opr, double opb)
{
	K = opK;
	sig = opsig;
	r = opr;
	b = opb;
}

opData::~opData()
{
}

opData & opData::operator=(const opData & opd)
{
	// TODO: 在此处插入 return 语句
	this->K = opd.K;
	this->sig = opd.sig;
	this->r = opd.r;
	this->b = opd.b;
	return *this;
}

void opData::init()
{
	// Initialise all default values

	// Default values
	r = 0.08;
	sig = 0.3;

	K = 65.0;

	b = r;			// Black and Scholes stock option model (1973)
}

void opData::copy(const opData & opd)
{
	K = opd.K;
	sig = opd.sig;
	r = opd.r;
	b = opd.b;
}
