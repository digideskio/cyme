/*
 * Cyme - test_header.hpp, Copyright (c), 2014,
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

#ifndef CYME_TEST_HEADER_HPP
#define CYME_TEST_HEADER_HPP

#define BOOST_TEST_MODULE math

#include <boost/test/unit_test.hpp>

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cyme/cyme.h>
#include <boost/mpl/list.hpp>
#include <boost/cstdint.hpp>
#include <boost/test/unit_test.hpp>
#include <boost/test/test_case_template.hpp>
#include <boost/lexical_cast.hpp>
#include <boost/random/mersenne_twister.hpp>
#include <boost/random/uniform_int_distribution.hpp>
#include <boost/random/uniform_real_distribution.hpp>
#include <boost/test/floating_point_comparison.hpp>


template<class T>
T relative_error();

template<>
float relative_error(){return 0.1;}

template<>
double relative_error(){return 0.001;}

namespace cyme {
    namespace test {

    static boost::random::uniform_real_distribution<float>    Randomfloat  = boost::random::uniform_real_distribution<float>(-70,70);
    static boost::random::uniform_real_distribution<double>   Randomdouble = boost::random::uniform_real_distribution<double>(-700,700);
    static boost::random::mt19937    rng;

    template<class T>
    T GetRandom();

    template<>
    float GetRandom<float>(){
        return Randomfloat(rng);
    }

    template<>
    double GetRandom<double>(){
        return Randomdouble(rng);
    }

    template<class Ba, class Bb> // m and n are differents into the block that why I passe like argument
    void init(Ba& block_a, Bb& block_b){
        for(std::size_t i=0; i<block_a.size(); ++i)
            for(std::size_t j=0; j<block_a.size_block(); ++j){
                typename Ba::value_type random = GetRandom<typename Ba::value_type>();
                block_a(i,j) = random;
                block_b(i,j) = random;
            }
    }

    template<class Ba, class Bb>
    void check(Ba & block_a, Bb & block_b){
        for(std::size_t i=0; i<block_a.size(); ++i)
            for(std::size_t j=0; j<block_a.size_block(); ++j){
                typename Ba::value_type error =  relative_error<typename Ba::value_type>();
                BOOST_CHECK_CLOSE(block_a(i,j), block_b(i,j), error);
            }
    }

    template<class T, std::size_t m, memory::order o>
    struct data{
        typedef T value_type;
        static const std::size_t n = m;
        static const std::size_t size = 16/sizeof(T); // for SIMD SSE
        static const memory::order order = o;
    };

    template<class T, std::size_t M, std::size_t N, memory::order O>
    struct data_block{
        typedef T value_type;
        static const std::size_t m = M;
        static const std::size_t n = N;
        static const memory::order order = O;
    };

    typedef boost::mpl::list<float,double> full_test_types;

    typedef boost::mpl::list<
                                data<float,14,memory::AoS>,
                                data<float,14,memory::AoSoA>,
                                data<double,14,memory::AoS>,
                                data<double,14,memory::AoSoA>
                            > floating_point_test_types;
    //max 20 elements, because MPL must emulate variadic template
    typedef boost::mpl::list<
                                data_block<double,3,3,memory::AoS>,
                                data_block<float,4,3,memory::AoSoA>,
                                data_block<double,5,3,memory::AoSoA>,

                                data_block<double,3,4,memory::AoS>,
                                data_block<float,4,4,memory::AoSoA>,
                                data_block<double,5,4,memory::AoSoA>,

                                data_block<double,3,5,memory::AoS>,
                                data_block<float,4,5,memory::AoSoA>,
                                data_block<double,5,5,memory::AoSoA>,

                                data_block<double,3,6,memory::AoS>,
                                data_block<float,4,6,memory::AoSoA>,
                                data_block<double,5,6,memory::AoSoA>

                            > floating_point_torture_list;

    typedef boost::mpl::list<
                                data_block<float,6,15,memory::AoS>,
                                data_block<float,7,13,memory::AoSoA>,
                                data_block<float,8,11,memory::AoS>,
                                data_block<double,6,15,memory::AoS>,
                                data_block<double,7,13,memory::AoSoA>,
                                data_block<double,8,11,memory::AoS>
                            > floating_point_block_types;




    } // end namespace test
} // end namespace CYME

#endif // CYME_TEST_HEADER_HPP

