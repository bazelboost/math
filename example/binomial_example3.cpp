// Copyright Paul A. 2006
// Copyright John Maddock 2006
// Use, modification and distribution are subject to the
// Boost Software License, Version 1.0.
// (See accompanying file LICENSE_1_0.txt
// or copy at http://www.boost.org/LICENSE_1_0.txt)

// Simple example of computing probabilitiesfor a binomial random variable.
// Replication of source nag_binomial_dist (g01bjc).

// Shows how to replace NAG C library calls by Boost Math Toolkit C++ calls.

#ifdef _MSC_VER
#  pragma warning(disable: 4512) // assignment operator could not be generated.
#  pragma warning(disable: 4510) // default constructor could not be generated.
#  pragma warning(disable: 4610) // can never be instantiated - user defined constructor required.
#endif

#include <iostream>
using std::cout;
using std::endl;
using std::ios;
using std::showpoint;
#include <iomanip>
#include <boost/math/distributions/binomial.hpp>

int main()
{
  cout << "Example 3 of using the binomial distribution." << endl;
  using boost::math::binomial_distribution;

  // This replicates the computation of the examples of using nag-binomial_dist
  // using g01bjc in section g01 Somple Calculations on Statistical Data.
  // http://www.nag.co.uk/numeric/cl/manual/pdf/G01/g01bjc.pdf
  // Program results section 8.3 page 3.g01bjc.3
    //8.2. Program Data
    //g01bjc Example Program Data
    //4 0.50 2 : n, p, k
    //19 0.44 13
    //100 0.75 67
    //2000 0.33 700
    //8.3. Program Results
    //g01bjc Example Program Results
    //n p k plek pgtk peqk
    //4 0.500 2 0.68750 0.31250 0.37500
    //19 0.440 13 0.99138 0.00862 0.01939
    //100 0.750 67 0.04460 0.95540 0.01700
    //2000 0.330 700 0.97251 0.02749 0.00312

  cout.setf(ios::showpoint); // Trailing zeros to show significant decimal digits.
  cout.precision(5); // Should be able to calculate this?
  //  Binomial distribution.
  
  // Note  that  cdf(dist, k) is equivalent to NAG library plek probability of <= k
  // cdf(complement(dist, k)) is equivalent to NAG library pgtk probability of > k
  //             pdf(dist, k) is equivalent to NAG library plek probability of == k

  cout << " n       p      k    plek    pgtk    pegk " << endl;
  binomial_distribution<>one(4, 0.5);
  cout << one.trials() <<  " "  << one.success_fraction() << "   "<< 2 << " "
    << cdf(one, 2) << " " << cdf(complement(one, 2)) << " " << pdf(one, 2) << endl;
  binomial_distribution<>two(19, 0.440);
  cout << two.trials() <<  " "  << two.success_fraction() << "  " << 13 << " "
    << cdf(two, 13) << " " << cdf(complement(two, 13)) << " " << pdf(two, 13) << endl;
  binomial_distribution<>three(100, 0.750);
  cout << three.trials() <<  " "  << three.success_fraction() << "  " << 67 << " "
    << cdf(three, 67) << " " << cdf(complement(three, 67)) << " " << pdf(three, 67) << endl;
  binomial_distribution<>four(2000, 0.330);
  cout << four.trials() <<  " "  << four.success_fraction() << " " << 700 << " "
    << cdf(four, 700) << " " << cdf(complement(four, 700)) << " " << pdf(four, 700) << endl;

  return 0;
} // int main()

/*
Output is:

Autorun "i:\boost-06-05-03-1300\libs\math\test\Math_test\debug\binomial_example3.exe"
Example 3 of using the binomial distribution.
 n       p      k    plek    pgtk    pegk 
4.0000 0.50000   2 0.68750 0.31250 0.37500
19.000 0.44000  13 0.99138 0.0086244 0.019386
100.00 0.75000  67 0.044596 0.95540 0.017002
2000.0 0.33000 700 0.97251 0.027494 0.0031178


 */

