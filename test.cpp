#include "AmericanOption.hpp"
#include "EuropeanOption.hpp"
#include <iostream>

int main()
{
	opData batch(100.0, 0.2, 0.0);
	EuropeanOption erpOp;
	std::cout << erpOp.Price(60) << std::endl;
	std::cout << erpOp.tPrice(60) << std::endl;
	erpOp.toggle();
	std::cout << erpOp.Price(60) << std::endl;
	std::cout << erpOp.tPrice(60) << std::endl << std::endl;
	std::cout << erpOp.Delta(60) << std::endl;
	std::cout << erpOp.Gamma(60) << std::endl;
	std::cout << erpOp.Vega(60) << std::endl;
	std::cout << erpOp.Theta(60) << std::endl;
	std::cout << erpOp.NumDelta(60) << std::endl;
	std::cout << erpOp.NumGamma(60) << std::endl;
	erpOp.PriceVector(60);
	erpOp.PriceVector(60, 12);
	erpOp.PriceVector(60, 12.0);

	erpOp.PriceMatrix(60, "T");
	erpOp.T = 1.0;
	erpOp.opd = batch;
	std::cout << erpOp.Price(100) << std::endl;
	std::cout << erpOp.tPrice(100) << std::endl;
	std::cout << erpOp.Delta(100) << std::endl;
	std::cout << erpOp.Gamma(100) << std::endl;
	std::cout << erpOp.Vega(100) << std::endl;
	std::cout << erpOp.Theta(100) << std::endl;
	std::cout << erpOp.NumDelta(100) << std::endl;
	std::cout << erpOp.NumGamma(100) << std::endl;
	erpOp.PriceVector(100.0);
	erpOp.PriceMatrix(100.0, "T");

	AmericanOption usOp;
	usOp.opd.K = 100.0;
	usOp.opd.sig = 0.1;
	usOp.opd.r = 0.1;
	usOp.opd.b = 0.02;
	std::cout << usOp.NumDelta(100) << std::endl;
	std::cout << usOp.NumGamma(100) << std::endl;
	usOp.PriceVector(110.0);
	usOp.PriceMatrix(110.0, "K");

	std::cin.get();

	return 0;
}