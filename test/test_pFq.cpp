//  (C) Copyright John Maddock 2006.
//  Use, modification and distribution are subject to the
//  Boost Software License, Version 1.0. (See accompanying file
//  LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include "test_pFq.hpp"

#include <boost/multiprecision/cpp_bin_float.hpp>

BOOST_AUTO_TEST_CASE( test_main )
{
#if !defined(TEST) || (TEST == 2)
   test_spots(0.0F, "float");
#endif
#if !defined(TEST) || (TEST == 3)
   test_spots(0.0, "double");
#endif
#ifndef BOOST_MATH_NO_LONG_DOUBLE_MATH_FUNCTIONS
#if (!defined(TEST) || (TEST == 4)) && (DBL_MAX_EXP != LDBL_MAX_EXP)
   test_spots(0.0L, "long double");
#endif
#ifndef BOOST_MATH_NO_REAL_CONCEPT_TESTS
#if !defined(TEST) || (TEST == 5)
   test_spots(boost::math::concepts::real_concept(0.1), "real_concept");
#endif
#endif
#endif
#if (!defined(TEST) || (TEST == 4)) && (DBL_MAX_EXP == LDBL_MAX_EXP)
   test_spots(boost::multiprecision::cpp_bin_float_double_extended(), "cpp_bin_float_double_extended");
#endif
#if !defined(TEST) || (TEST == 6)
   test_spots(boost::multiprecision::cpp_bin_float_quad(), "cpp_bin_float_quad");
#endif
#if !defined(TEST) || (TEST == 7)
   typedef boost::multiprecision::number<boost::multiprecision::cpp_bin_float<40> > dec_40;
   test_spots(dec_40(), "dec_40");
#endif
}

