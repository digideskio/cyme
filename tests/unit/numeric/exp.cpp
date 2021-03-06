/*
 * Cyme - exp.cpp, Copyright (c), 2014,
 * Timothee Ewart - Swiss Federal Institute of technology in Lausanne,
 * timothee.ewart@epfl.ch,
 * All rights reserved.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 3.0 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library.
 */

#include <limits>
#include <tests/unit/test_header.hpp>
#include "cyme/math/math.h"

using namespace cyme::test;

#define TYPE typename T::value_type
#define SIZE T::size
#define MAX 1000

#define NN cyme::unroll_factor::N*cyme::trait_register<TYPE,cyme::__GETSIMD__()>::size/sizeof(TYPE)

BOOST_AUTO_TEST_CASE_TEMPLATE(std_exp_comparison, T, floating_point_test_types) {
    TYPE a[NN] __attribute__((aligned(64)));
    TYPE b[NN] __attribute__((aligned(64)));
    TYPE res[NN] __attribute__((aligned(64)));
    for(size_t k=0; k<100; ++k){
        for(size_t i=0; i<NN; ++i){
            a[i] = GetRandom<TYPE>();
            b[i] = GetRandom<TYPE>();
        }

        cyme::vec_simd<TYPE,cyme::__GETSIMD__(),cyme::unroll_factor::N> va(a);
        cyme::vec_simd<TYPE,cyme::__GETSIMD__(),cyme::unroll_factor::N> vb(b);

        for(size_t i=0; i<NN; ++i)
            a[i] = exp(b[i]);

        va = exp(vb);
        va.store(res);

        for(size_t i=0; i<NN; ++i)
          BOOST_REQUIRE_CLOSE( a[i], res[i], 0.001);
    }
}

BOOST_AUTO_TEST_CASE_TEMPLATE(std_exp_comparison_serial, T, floating_point_test_types) {
    TYPE a[NN] __attribute__((aligned(64)));
    TYPE b[NN] __attribute__((aligned(64)));

    TYPE sa[NN] __attribute__((aligned(64)));
    TYPE sb[NN] __attribute__((aligned(64)));

    for(size_t k=0; k<100; ++k){
        for(size_t i=0; i<NN; ++i){
            sa[i] = a[i] = GetRandom<TYPE>();
            sb[i] = b[i] = GetRandom<TYPE>();
        }


        for(size_t i=0; i<NN; ++i){
            a[i] = exp(b[i]);
            sa[i] = cyme::sexp(sb[i]);
        }

        for(size_t i=0; i<NN; ++i)
          BOOST_REQUIRE_CLOSE( a[i], sa[i], 0.001);
    }
}

BOOST_AUTO_TEST_CASE_TEMPLATE(std_boundary, T, floating_point_test_types) {
    TYPE b[NN] __attribute__((aligned(64)));
    TYPE res[NN] __attribute__((aligned(64)));

    {

        for(size_t i=0; i<NN; ++i)
            b[i] = std::numeric_limits<TYPE>::signaling_NaN();

        cyme::vec_simd<TYPE,cyme::__GETSIMD__(),cyme::unroll_factor::N> va;
        cyme::vec_simd<TYPE,cyme::__GETSIMD__(),cyme::unroll_factor::N> vb(b);

        va = exp(vb);
        va.store(res);

        for(size_t i=0; i<NN; ++i)
            BOOST_CHECK( std::isnan(res[i]));

        for(size_t i=0; i<NN; ++i){
            b[i] = 0;
        }
    }

    {
        for(size_t i=0; i<NN; ++i)
            b[i] = 0;

        cyme::vec_simd<TYPE,cyme::__GETSIMD__(),cyme::unroll_factor::N> va;
        cyme::vec_simd<TYPE,cyme::__GETSIMD__(),cyme::unroll_factor::N> vb(b);

        va = exp(vb);
        va.store(res);

        for(size_t i=0; i<NN; ++i)
            BOOST_CHECK(res[i] == 1);
    }

    {
        for(size_t i=0; i<NN; ++i)
            b[i] = std::numeric_limits<TYPE>::infinity();

        cyme::vec_simd<TYPE,cyme::__GETSIMD__(),cyme::unroll_factor::N> va;
        cyme::vec_simd<TYPE,cyme::__GETSIMD__(),cyme::unroll_factor::N> vb(b);

        va = exp(vb);
        va.store(res);

        for(size_t i=0; i<NN; ++i)
            BOOST_CHECK_EQUAL(res[i], std::numeric_limits<TYPE>::infinity());
    }

    {
        for(size_t i=0; i<NN; ++i)
            b[i] = -std::numeric_limits<TYPE>::infinity();

        cyme::vec_simd<TYPE,cyme::__GETSIMD__(),cyme::unroll_factor::N> va;
        cyme::vec_simd<TYPE,cyme::__GETSIMD__(),cyme::unroll_factor::N> vb(b);

        va = exp(vb);
        va.store(res);

        for(size_t i=0; i<NN; ++i)
            BOOST_CHECK_EQUAL(res[i], 0);
    }


    {
        for(size_t i=0; i<NN; ++i)
            b[i] = -1000;

        cyme::vec_simd<TYPE,cyme::__GETSIMD__(),cyme::unroll_factor::N> va;
        cyme::vec_simd<TYPE,cyme::__GETSIMD__(),cyme::unroll_factor::N> vb(b);

        va = exp(vb);
        va.store(res);

        for(size_t i=0; i<NN; ++i)
            BOOST_CHECK_EQUAL(res[i], 0);
    }

    {
        for(size_t i=0; i<NN; ++i)
            b[i] = 1000;

        cyme::vec_simd<TYPE,cyme::__GETSIMD__(),cyme::unroll_factor::N> va;
        cyme::vec_simd<TYPE,cyme::__GETSIMD__(),cyme::unroll_factor::N> vb(b);

        va = exp(vb);
        va.store(res);

        for(size_t i=0; i<NN; ++i)
            BOOST_CHECK_EQUAL(res[i], std::numeric_limits<TYPE>::infinity());
    }

}



#undef NN
#undef TYPE
#undef MAX
#undef SIZE
