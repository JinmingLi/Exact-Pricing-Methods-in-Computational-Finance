#pragma once
/*
Plain (European) equity options (with zero dividends) and their Sensitivities
*/
#ifndef EUROPEANOPTION_HPP
#define EUROPEANOPTION_HPP

#include "Option.hpp"

class EuropeanOption : public Option
{
public:
	EuropeanOption();							// Default call option
	EuropeanOption(const EuropeanOption& option2);	// Copy constructor
	EuropeanOption(const std::string& optionType);	// Create option type
	virtual ~EuropeanOption();

	EuropeanOption& operator = (const EuropeanOption& option2);

	// Functions that calculate option price and sensitivities
	virtual double Price(double U) const;
	double tPrice(double U) const;
	double Delta(double U) const;
	double Gamma(double U) const;
	double Vega(double U) const;
	double Theta(double U) const;

	virtual void PriceMatrix(double S, std::string ch);
	virtual void PriceMatrix(double S, double interval, std::string ch);
	virtual void PriceMatrix(double S, int num, std::string ch);
	virtual void PriceMatrix(double S, double interval, int num, std::string ch);
	virtual void PriceMatrix(double S, double sint, int snum, double oint, int onum, std::string ch);
	virtual void PriceMatrix(std::vector<double> S, std::vector<double> P, std::string ch);

private:
	// 'Kernel' functions for option calculations
	virtual double CallPrice(double U) const;
	virtual double PutPrice(double U) const;

	double tCallPrice(double U) const;
	double tPutPrice(double U) const;

	double CallDelta(double U) const;
	double PutDelta(double U) const;

	double CallGamma(double U) const;
	double PutGamma(double U) const;

	double CallVega(double U) const;
	double PutVega(double U) const;

	double CallTheta(double U) const;
	double PutTheta(double U) const;

public:
	double T;
};

#endif // !EUROPEANOPTION_HPP
