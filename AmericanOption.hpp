#pragma once
#ifndef AMERICANOPTION_HPP
#define AMERICANOPTION_HPP

#include "Option.hpp"
class AmericanOption :
	public Option
{
public:
	AmericanOption();							// Default call option
	AmericanOption(const AmericanOption& option2);	// Copy constructor
	AmericanOption(const std::string& optionType);	// Create option type
	virtual ~AmericanOption();

	virtual double Price(double U) const;

private:
	// 'Kernel' functions for option calculations
	virtual double CallPrice(double S) const;
	virtual double PutPrice(double S) const;
};


#endif // !AMERICANOPTION_HPP

