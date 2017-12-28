# Exact-Pricing-Methods-in-Computational-Finance
This project includes the code that I wrote to use exact solutions for the option pricing problems.

There are two options that can apply the exact solutions to calculate their prices: plain (European) equity options (with zero dividends) and Perpetual American Options. 

I programmed the exact solution using the generalized Black–Scholes formula to calculate the price of the above two call/put option on underlying asset and then programmed two methods to calculate option sensitivities(aka the Greeks): 1)exact formulae for the greeks and 2)divided differences to numerically approximate option sensitivities.
