#ifndef EUROPEANOPTION_CPP
#define EUROPEANOPTION_CPP

#include "EuropeanOption.hpp"
#include <cmath>
#include <iostream>
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions.hpp>

using namespace boost::math;
using std::cout;
using std::endl;

EuropeanOption::EuropeanOption()
{
	T = 0.25;
}

EuropeanOption::EuropeanOption(const EuropeanOption& o2)
{ // Copy constructor

	copy(o2); 
}

EuropeanOption::EuropeanOption(const std::string& optionType)
{	// Create option type

	T = 0.25;
	optType = optionType;

	if (optType == "c")
		optType = "C";

}

EuropeanOption::~EuropeanOption()
{
}

EuropeanOption& EuropeanOption::operator = (const EuropeanOption& option2)
{

	if (this == &option2) return *this;

	copy(option2);
	T = option2.T;

	return *this;
}

// Functions that calculate option price and sensitivities
double EuropeanOption::Price(double U) const
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

double EuropeanOption::tPrice(double U) const
{


	if (optType == "C")
	{
		//cout << "test calling call" << endl;
		return tCallPrice(U);
	}
	else
	{
		//cout << "test calling put" << endl;
		return tPutPrice(U);
	}
}

double EuropeanOption::Delta(double U) const
{
	if (optType == "C")
		return CallDelta(U);
	else
		return PutDelta(U);

}

double EuropeanOption::Gamma(double U) const
{
	if (optType == "C")
		return CallGamma(U);
	else
		return PutGamma(U);

}

double EuropeanOption::Vega(double U) const
{
	if (optType == "C")
		return CallVega(U);
	else
		return PutVega(U);

}

double EuropeanOption::Theta(double U) const
{
	if (optType == "C")
		return CallTheta(U);
	else
		return PutTheta(U);

}

void EuropeanOption::PriceMatrix(double S, std::string ch)
{
	std::vector<std::vector<double>> copts;
	std::vector<std::vector<double>> popts;
	for (int j = 0; j < 10; j++)
	{
		std::vector<double> coptions;
		std::vector<double> poptions;
		for (int k = 0; k < 10; k++)
		{
			coptions.push_back(Price(S + k));
			// Now change over to a call on the option
			toggle();
			poptions.push_back(Price(S + k));
			toggle();
		}
		copts.push_back(coptions);
		popts.push_back(poptions);

		// choose one
		if (ch == "T")
			T += 1;
		else if (ch == "K")
			opd.K += 1;
		else if (ch == "sig")
			opd.sig += 1;
		else
			opd.r += 1;
	}
	cout << "Call options" << endl;
	// output format
	cout << std::setiosflags(std::ios::fixed) << std::setprecision(3);
	for (std::vector<std::vector<double>>::iterator its = copts.begin(); its != copts.end(); ++its)
	{
		for (std::vector<double>::iterator it = its->begin(); it != its->end(); ++it)
		{
			cout << *it << "\t";
		}
		cout << endl;
	}

	cout << endl << "Put options" << endl;
	for (std::vector<std::vector<double>>::iterator its = popts.begin(); its != popts.end(); ++its)
	{
		for (std::vector<double>::iterator it = its->begin(); it != its->end(); ++it)
		{
			cout << *it << "\t";
		}
		cout << endl;
	}
}

void EuropeanOption::PriceMatrix(double S, double interval, std::string ch)
{
	std::vector<std::vector<double>> copts;
	std::vector<std::vector<double>> popts;
	for (int j = 0; j < 10; j++)
	{
		std::vector<double> coptions;
		std::vector<double> poptions;
		for (int k = 0; k < 10; k++)
		{
			coptions.push_back(Price(S + k * interval));
			// Now change over to a call on the option
			toggle();
			poptions.push_back(Price(S + k * interval));
			toggle();
		}
		copts.push_back(coptions);
		popts.push_back(poptions);

		// choose one
		if (ch == "T")
			T += 1;
		else if (ch == "K")
			opd.K += 1;
		else if (ch == "sig")
			opd.sig += 1;
		else
			opd.r += 1;
	}
	cout << "Call options" << endl;
	// output format
	cout << std::setiosflags(std::ios::fixed) << std::setprecision(3);
	for (std::vector<std::vector<double>>::iterator its = copts.begin(); its != copts.end(); ++its)
	{
		for (std::vector<double>::iterator it = its->begin(); it != its->end(); ++it)
		{
			cout << *it << "\t";
		}
		cout << endl;
	}

	cout << endl << "Put options" << endl;
	for (std::vector<std::vector<double>>::iterator its = popts.begin(); its != popts.end(); ++its)
	{
		for (std::vector<double>::iterator it = its->begin(); it != its->end(); ++it)
		{
			cout << *it << "\t";
		}
		cout << endl;
	}
}

void EuropeanOption::PriceMatrix(double S, int num, std::string ch)
{
	std::vector<std::vector<double>> copts;
	std::vector<std::vector<double>> popts;
	for (int j = 0; j < 10; j++)
	{
		std::vector<double> coptions;
		std::vector<double> poptions;
		for (int k = 0; k < num; k++)
		{
			coptions.push_back(Price(S + k));
			// Now change over to a call on the option
			toggle();
			poptions.push_back(Price(S + k));
			toggle();
		}
		copts.push_back(coptions);
		popts.push_back(poptions);

		// choose one
		if (ch == "T")
			T += 1;
		else if (ch == "K")
			opd.K += 1;
		else if (ch == "sig")
			opd.sig += 1;
		else
			opd.r += 1;
	}
	cout << "Call options" << endl;
	// output format
	cout << std::setiosflags(std::ios::fixed) << std::setprecision(3);
	for (std::vector<std::vector<double>>::iterator its = copts.begin(); its != copts.end(); ++its)
	{
		for (std::vector<double>::iterator it = its->begin(); it != its->end(); ++it)
		{
			cout << *it << "\t";
		}
		cout << endl;
	}

	cout << endl << "Put options" << endl;
	for (std::vector<std::vector<double>>::iterator its = popts.begin(); its != popts.end(); ++its)
	{
		for (std::vector<double>::iterator it = its->begin(); it != its->end(); ++it)
		{
			cout << *it << "\t";
		}
		cout << endl;
	}
}

void EuropeanOption::PriceMatrix(double S, double interval, int num, std::string ch)
{
	std::vector<std::vector<double>> copts;
	std::vector<std::vector<double>> popts;
	for (int j = 0; j < 10; j++)
	{
		std::vector<double> coptions;
		std::vector<double> poptions;
		for (int k = 0; k < num; k++)
		{
			coptions.push_back(Price(S + k * interval));
			// Now change over to a call on the option
			toggle();
			poptions.push_back(Price(S + k * interval));
			toggle();
		}
		copts.push_back(coptions);
		popts.push_back(poptions);

		// choose one
		if (ch == "T")
			T += 1;
		else if (ch == "K")
			opd.K += 1;
		else if (ch == "sig")
			opd.sig += 1;
		else
			opd.r += 1;
	}
	cout << "Call options" << endl;
	// output format
	cout << std::setiosflags(std::ios::fixed) << std::setprecision(3);
	for (std::vector<std::vector<double>>::iterator its = copts.begin(); its != copts.end(); ++its)
	{
		for (std::vector<double>::iterator it = its->begin(); it != its->end(); ++it)
		{
			cout << *it << "\t";
		}
		cout << endl;
	}

	cout << endl << "Put options" << endl;
	for (std::vector<std::vector<double>>::iterator its = popts.begin(); its != popts.end(); ++its)
	{
		for (std::vector<double>::iterator it = its->begin(); it != its->end(); ++it)
		{
			cout << *it << "\t";
		}
		cout << endl;
	}
}

void EuropeanOption::PriceMatrix(double S, double sint, int snum, double oint, int onum, std::string ch)
{
	std::vector<std::vector<double>> copts;
	std::vector<std::vector<double>> popts;
	for (int j = 0; j < onum; j++)
	{
		std::vector<double> coptions;
		std::vector<double> poptions;
		for (int k = 0; k < snum; k++)
		{
			coptions.push_back(Price(S + k * sint));
			// Now change over to a call on the option
			toggle();
			poptions.push_back(Price(S + k * sint));
			toggle();
		}
		copts.push_back(coptions);
		popts.push_back(poptions);

		// choose one
		if (ch == "T")
			T += 1;
		else if (ch == "K")
			opd.K += oint;
		else if (ch == "sig")
			opd.sig += oint;
		else
			opd.r += oint;
	}
	cout << "Call options" << endl;
	// output format
	cout << std::setiosflags(std::ios::fixed) << std::setprecision(3);
	for (std::vector<std::vector<double>>::iterator its = copts.begin(); its != copts.end(); ++its)
	{
		for (std::vector<double>::iterator it = its->begin(); it != its->end(); ++it)
		{
			cout << *it << "\t";
		}
		cout << endl;
	}

	cout << endl << "Put options" << endl;
	for (std::vector<std::vector<double>>::iterator its = popts.begin(); its != popts.end(); ++its)
	{
		for (std::vector<double>::iterator it = its->begin(); it != its->end(); ++it)
		{
			cout << *it << "\t";
		}
		cout << endl;
	}
}

void EuropeanOption::PriceMatrix(std::vector<double> S, std::vector<double> P, std::string ch)
{
	std::vector<std::vector<double>> copts;
	std::vector<std::vector<double>> popts;
	for (std::vector<double>::iterator its = P.begin(); its != P.end(); ++its)
	{
		std::vector<double> coptions;
		std::vector<double> poptions;
		for (std::vector<double>::iterator it = S.begin(); it != S.end(); ++it)
		{
			coptions.push_back(Price(*it));
			// Now change over to a call on the option
			toggle();
			poptions.push_back(Price(*it));
			toggle();
		}
		cout << endl;
		copts.push_back(coptions);
		popts.push_back(poptions);

		// choose one
		if (ch == "T")
			T = *its;
		else if (ch == "K")
			opd.K = *its;
		else if (ch == "sig")
			opd.sig = *its;
		else
			opd.r = *its;
	}
	cout << "Call options" << endl;
	// output format
	cout << std::setiosflags(std::ios::fixed) << std::setprecision(3);
	for (std::vector<std::vector<double>>::iterator its = copts.begin(); its != copts.end(); ++its)
	{
		for (std::vector<double>::iterator it = its->begin(); it != its->end(); ++it)
		{
			cout << *it << "\t";
		}
		cout << endl;
	}

	cout << endl << "Put options" << endl;
	for (std::vector<std::vector<double>>::iterator its = popts.begin(); its != popts.end(); ++its)
	{
		for (std::vector<double>::iterator it = its->begin(); it != its->end(); ++it)
		{
			cout << *it << "\t";
		}
		cout << endl;
	}
}

// Kernel Functions (Haug)
double EuropeanOption::CallPrice(double U) const
{
	normal stdnormal(0.0, 1.0);
	double tmp = opd.sig * sqrt(T);

	double d1 = (log(U / opd.K) + (opd.b + (opd.sig*opd.sig)*0.5) * T) / tmp;
	double d2 = d1 - tmp;


	return (U * exp((opd.b - opd.r)*T) * cdf(stdnormal, d1)) - (opd.K * exp(-opd.r * T)* cdf(stdnormal, d2));

}

double EuropeanOption::PutPrice(double U) const
{
	normal stdnormal(0.0, 1.0);
	double tmp = opd.sig * sqrt(T);
	double d1 = (log(U / opd.K) + (opd.b + (opd.sig*opd.sig)*0.5) * T) / tmp;
	double d2 = d1 - tmp;

	return (opd.K * exp(-opd.r * T)* cdf(stdnormal, -d2)) - (U * exp((opd.b - opd.r)*T) * cdf(stdnormal, -d1));

}

double EuropeanOption::tCallPrice(double U) const
{
	return PutPrice(U) + U - opd.K * exp(-opd.r * T);
}

double EuropeanOption::tPutPrice(double U) const
{
	return CallPrice(U) + opd.K * exp(-opd.r * T) - U;
}

double EuropeanOption::CallDelta(double U) const
{
	normal stdnormal(0.0, 1.0);
	double tmp = opd.sig * sqrt(T);

	double d1 = (log(U / opd.K) + (opd.b + (opd.sig*opd.sig)*0.5) * T) / tmp;


	return exp((opd.b - opd.r)*T) * cdf(stdnormal, d1);
}

double EuropeanOption::PutDelta(double U) const
{
	normal stdnormal(0.0, 1.0);
	double tmp = opd.sig * sqrt(T);

	double d1 = (log(U / opd.K) + (opd.b + (opd.sig*opd.sig)*0.5) * T) / tmp;

	return exp((opd.b - opd.r)*T) * (cdf(stdnormal, d1) - 1.0);
}

double EuropeanOption::CallGamma(double U) const
{
	normal stdnormal(0.0, 1.0);
	double tmp = opd.sig * sqrt(T);

	double d1 = (log(U / opd.K) + (opd.b + (opd.sig*opd.sig)*0.5) * T) / tmp;

	return exp((opd.b - opd.r)*T) * pdf(stdnormal, d1) / (U * opd.sig * sqrt(T));
}

double EuropeanOption::PutGamma(double U) const
{
	return CallGamma(U);
}

double EuropeanOption::CallVega(double U) const
{
	normal stdnormal(0.0, 1.0);
	double tmp = opd.sig * sqrt(T);

	double d1 = (log(U / opd.K) + (opd.b + (opd.sig*opd.sig)*0.5) * T) / tmp;


	return U * sqrt(T) * exp((opd.b - opd.r)*T) * pdf(stdnormal, d1);
}

double EuropeanOption::PutVega(double U) const
{
	return CallVega(U);
}

double EuropeanOption::CallTheta(double U) const
{
	normal stdnormal(0.0, 1.0);
	double tmp = opd.sig * sqrt(T);

	double d1 = (log(U / opd.K) + (opd.b + (opd.sig*opd.sig)*0.5) * T) / tmp;
	double d2 = d1 - tmp;

	double t1 = (U * exp((opd.b - opd.r)*T) * pdf(stdnormal, d1) * opd.sig * 0.5) / sqrt(T);
	double t2 = (opd.b - opd.r)*(U * exp((opd.b - opd.r)*T) * cdf(stdnormal, d1));
	double t3 = opd.r * opd.K * exp(-opd.r * T) * cdf(stdnormal, d2);

	return -(t1 + t2 + t3);
}

double EuropeanOption::PutTheta(double U) const
{
	normal stdnormal(0.0, 1.0);
	double tmp = opd.sig * sqrt(T);

	double d1 = (log(U / opd.K) + (opd.b + (opd.sig*opd.sig)*0.5) * T) / tmp;
	double d2 = d1 - tmp;

	double t1 = (U * exp((opd.b - opd.r) * T) * pdf(stdnormal, d1) * opd.sig * 0.5) / sqrt(T);
	double t2 = (opd.b - opd.r)*(U * exp((opd.b - opd.r)*T) * cdf(stdnormal, -d1));
	double t3 = opd.r * opd.K * exp(-opd.r * T) * cdf(stdnormal, -d2);

	return t2 + t3 - t1;
}

#endif // !EUROPEANOPTION_CPP
