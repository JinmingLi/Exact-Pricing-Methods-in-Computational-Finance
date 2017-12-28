/*
Base Class Head
With common parts of European and American Options
*/

#ifndef OPTION_HPP
#define OPTION_HPP

#include <string>
#include <vector>
#include "OptionData.hpp"

class Option
{
public:
	Option();							// Default call option
	Option(const Option& o);			// Copy constructor
	Option(const std::string& opt);		// Create option type
	virtual ~Option();

	// 'Kernel' functions for option calculations
	virtual double CallPrice(double S) const = 0;
	virtual double PutPrice(double S) const = 0;

	double CallNumDelta(double S) const;
	double PutNumDelta(double S) const;

	double CallNumGamma(double S) const;
	double PutNumGamma(double S) const;

	// Functions that calculate option price and sensitivities
	virtual double Price(double S) const = 0;
	double NumDelta(double S) const;
	double NumGamma(double S) const;

	// Output functions
	void PriceVector(double S);
	void PriceVector(double S, double interval);
	void PriceVector(double S, int num);
	void PriceVector(double S, double interval, int num);
	void PriceVector(std::vector<double> S);

	virtual void PriceMatrix(double S, std::string ch);
	virtual void PriceMatrix(double S, double interval, std::string ch);
	virtual void PriceMatrix(double S, int num, std::string ch);
	virtual void PriceMatrix(double S, double interval, int num, std::string ch);
	virtual void PriceMatrix(double S, double sint, int snum, double oint, int onum, std::string ch);
	virtual void PriceMatrix(std::vector<double> S, std::vector<double> P, std::string ch);

	// Modifier functions
	void toggle();		// Change option type (C/P, P/C)

	void copy(const Option& o);
private:
	void init();

public:
	std::string optType;	// Option name (call, put)
	opData opd;
};

#endif // !OPTION_HPP
