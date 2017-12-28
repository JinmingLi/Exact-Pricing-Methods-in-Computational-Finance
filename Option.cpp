/*
Function Definitions of The Base Class
*/
#ifndef OPTION_CPP
#define OPTION_CPP

#include <vector>
#include <iostream>
#include <iomanip>
#include "Option.hpp"

using std::cin;
using std::endl;
using std::cout;

Option::Option()
{
	init();
}

Option::Option(const Option & o)
{
}

Option::Option(const std::string & opt)
{
	optType = opt;
}

Option::~Option()
{
}

double Option::CallNumDelta(double S) const
{
	double h = 0.01;

	return (CallPrice(S + h) - CallPrice(S - h)) / (2 * h);
}

double Option::PutNumDelta(double S) const
{
	double h = 0.01;

	return (PutPrice(S + h) - PutPrice(S - h)) / (2 * h);
}

double Option::CallNumGamma(double S) const
{
	double h = 0.01;

	return (CallPrice(S + h) - 2 * CallPrice(S) + CallPrice(S - h)) / (h * h);
}

double Option::PutNumGamma(double S) const
{
	double h = 0.01;

	return (PutPrice(S + h) - 2 * PutPrice(S) + PutPrice(S - h)) / (h * h);
}

double Option::NumDelta(double S) const
{
	if (optType == "C")
		return CallNumDelta(S);
	else
		return PutNumDelta(S);

}

double Option::NumGamma(double S) const
{
	if (optType == "C")
		return CallNumGamma(S);
	else
		return PutNumGamma(S);

}

void Option::PriceVector(double S)
{
	std::vector<double> coptions;
	std::vector<double> poptions;
	for (int j = 0; j < 10; j++)
	{
		coptions.push_back(Price(S + j));
		// Now change over to a call on the option
		toggle();
		poptions.push_back(Price(S + j));
		toggle();
	}
	cout << "Call options" << endl;
	int i = 0;
	for (std::vector<double>::iterator it = coptions.begin(); it != coptions.end(); ++it, ++i)
	{
		cout << i << ": " << *it << endl;
	}

	cout << endl << "Put options" << endl;
	i = 0;
	for (std::vector<double>::iterator it = poptions.begin(); it != poptions.end(); ++it, ++i)
	{
		cout << i << ": " << *it << endl;
	}
	cout << endl;
}

void Option::PriceVector(double S, double interval)
{
	std::vector<double> coptions;
	std::vector<double> poptions;
	for (int j = 0; j < 10; j++)
	{
		coptions.push_back(Price(S + j * interval));
		// Now change over to a call on the option
		toggle();
		poptions.push_back(Price(S + j * interval));
		toggle();
	}
	cout << "Call options" << endl;
	int i = 0;
	for (std::vector<double>::iterator it = coptions.begin(); it != coptions.end(); ++it, ++i)
	{
		cout << i << ": " << *it << endl;
	}

	cout << endl << "Put options" << endl;
	i = 0;
	for (std::vector<double>::iterator it = poptions.begin(); it != poptions.end(); ++it, ++i)
	{
		cout << i << ": " << *it << endl;
	}
	cout << endl;
}

void Option::PriceVector(double S, int num)
{
	std::vector<double> coptions;
	std::vector<double> poptions;
	for (int j = 0; j < num; j++)
	{
		coptions.push_back(Price(S + j));
		// Now change over to a call on the option
		toggle();
		poptions.push_back(Price(S + j));
		toggle();
	}
	cout << "Call options" << endl;
	int i = 0;
	for (std::vector<double>::iterator it = coptions.begin(); it != coptions.end(); ++it, ++i)
	{
		cout << i << ": " << *it << endl;
	}

	cout << endl << "Put options" << endl;
	i = 0;
	for (std::vector<double>::iterator it = poptions.begin(); it != poptions.end(); ++it, ++i)
	{
		cout << i << ": " << *it << endl;
	}
	cout << endl;
}

void Option::PriceVector(double S, double interval, int num)
{
	std::vector<double> coptions;
	std::vector<double> poptions;
	for (int j = 0; j < num; j++)
	{
		coptions.push_back(Price(S + j * interval));
		// Now change over to a call on the option
		toggle();
		poptions.push_back(Price(S + j * interval));
		toggle();
	}
	cout << "Call options" << endl;
	int i = 0;
	for (std::vector<double>::iterator it = coptions.begin(); it != coptions.end(); ++it, ++i)
	{
		cout << i << ": " << *it << endl;
	}

	cout << endl << "Put options" << endl;
	i = 0;
	for (std::vector<double>::iterator it = poptions.begin(); it != poptions.end(); ++it, ++i)
	{
		cout << i << ": " << *it << endl;
	}
	cout << endl;
}

void Option::PriceVector(std::vector<double> S)
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
	cout << "Call options" << endl;
	int i = 0;
	for (std::vector<double>::iterator it = coptions.begin(); it != coptions.end(); ++it, ++i)
	{
		cout << i << ": " << *it << endl;
	}

	cout << endl << "Put options" << endl;
	i = 0;
	for (std::vector<double>::iterator it = poptions.begin(); it != poptions.end(); ++it, ++i)
	{
		cout << i << ": " << *it << endl;
	}
	cout << endl;
}

void Option::PriceMatrix(double S, std::string ch)
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
		if (ch == "K")
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

void Option::PriceMatrix(double S, double interval, std::string ch)
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
		if (ch == "K")
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

void Option::PriceMatrix(double S, int num, std::string ch)
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
		if (ch == "K")
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

void Option::PriceMatrix(double S, double interval, int num, std::string ch)
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
		if (ch == "K")
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

void Option::PriceMatrix(double S, double sint, int snum, double oint, int onum, std::string ch)
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
		if (ch == "K")
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

void Option::PriceMatrix(std::vector<double> S, std::vector<double> P, std::string ch)
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
		if (ch == "K")
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


// Modifier functions
void Option::toggle()
{ // Change option type (C/P, P/C)

	if (optType == "C")
		optType = "P";
	else
		optType = "C";
}


void Option::init()
{
	// Initialise all default value

	optType = "C";		// European Call Option (this is the default type)
}

void Option::copy(const Option & o)
{
	opd = o.opd;

	optType = o.optType;
}

#endif // !OPTION_CPP
