#pragma once
/*
The Class of Option Datas
*/

#ifndef OPTIONDATA_HPP
#define OPTIONDATA_HPP

class opData
{
public:
	double K;		// Strike price
	double sig;		// Volatility
	double r;		// Interest rate
	double b;		// Cost of carry

public:
	opData();
	opData(const opData& opd);
	opData(double opK, double opsig, double opr);
	opData(double opK, double opsig, double opr, double opb);
	~opData();

	opData& operator= (const opData& opd);

private:
	void init();
	void copy(const opData& opd);
};

#endif // !OPTIONDATA_HPP