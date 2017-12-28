#ifndef AMERICANOPTION_CPP
#define AMERICANOPTION_CPP

#include "AmericanOption.hpp"

AmericanOption::AmericanOption()
{
}

AmericanOption::AmericanOption(const AmericanOption& o2)
{ // Copy constructor

	copy(o2);
}

AmericanOption::AmericanOption(const std::string& optionType)
{	// Create option type

	optType = optionType;

	if (optType == "c")
		optType = "C";

}

AmericanOption::~AmericanOption()
{
}

// Functions that calculate option price and sensitivities
double AmericanOption::Price(double U) const
{


	if (optType == "C")
	{
		//cout << "calling call" << endl;
		return CallPrice(U);
	}
	else
	{
		//cout << "calling put" << endl;
		return PutPrice(U);
	}
}


double AmericanOption::CallPrice(double S) const
{ // Dividend q = r - b

	double sig2 = opd.sig*opd.sig;
	double fac = opd.b / sig2 - 0.5; fac *= fac;
	double y1 = 0.5 - opd.b / sig2 + sqrt(fac + 2.0*opd.r / sig2);


	if (1.0 == y1)
		return S;

	double fac2 = ((y1 - 1.0)*S) / (y1 * opd.K);
	double c = opd.K * pow(fac2, y1) / (y1 - 1.0);

	return c;
}

double AmericanOption::PutPrice(double S) const
{

	double sig2 = opd.sig*opd.sig;
	double fac = opd.b / sig2 - 0.5; fac *= fac;
	double y2 = 0.5 - opd.b / sig2 - sqrt(fac + 2.0*opd.r / sig2);

	if (0.0 == y2)
		return S;

	double fac2 = ((y2 - 1.0)*S) / (y2 * opd.K);
	double p = opd.K * pow(fac2, y2) / (1.0 - y2);

	return p;
}

#endif // !AMERICANOPTION_CPP
