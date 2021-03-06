/*
* Cyme - simd_wrapper_avx.ipp, Copyright (c), 2014,
* Timothee Ewart - Swiss Federal Institute of technology in Lausanne,
* timothee.ewart@epfl.ch,
* All rights reserved.
* This file is part of Cyme <https://github.com/BlueBrain/cyme>
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

/**
 * @file cyme/core/simd_vector/detail/x86/simd_wrapper_avx.ipp
 * Final specialisation for math functions and avx technology
 */

#ifndef CYME_SIMD_WRAPPER_AVX_IPP
#define CYME_SIMD_WRAPPER_AVX_IPP
namespace cyme{

    /**
      Rounds xmm0 up to the next even integer.
      Specialisation int, cyme::avx, 1 reg
    */
    template<>
    forceinline simd_trait<int,cyme::avx,1>::register_type
    _mm_round_up_even<cyme::avx,1>( simd_trait<int,cyme::avx,1>::register_type xmm0){
        __m128i lo = _mm256_extractf128_si256(xmm0,0);
        __m128i hi = _mm256_extractf128_si256(xmm0,1);

        hi = _mm_round_up_even<cyme::sse,1>(hi);
        lo = _mm_round_up_even<cyme::sse,1>(lo);
        xmm0 =  _mm256_insertf128_si256(xmm0, lo, 0);
        xmm0 =  _mm256_insertf128_si256(xmm0, hi, 1);
	return xmm0;
    }

    /**
      Rounds xmm0 up to the next even integer.
      Specialisation int, cyme::avx, 2 reg
    */
    template<>
    forceinline simd_trait<int,cyme::avx,2>::register_type
    _mm_round_up_even<cyme::avx,2>( simd_trait<int,cyme::avx,2>::register_type xmm0){
        __m128i lo0 = _mm256_extractf128_si256(xmm0.r0,0);
        __m128i hi0 = _mm256_extractf128_si256(xmm0.r0,1);
        __m128i lo1 = _mm256_extractf128_si256(xmm0.r1,0);
        __m128i hi1 = _mm256_extractf128_si256(xmm0.r1,1);

        hi0 = _mm_round_up_even<cyme::sse,1>(hi0);
        lo0 = _mm_round_up_even<cyme::sse,1>(lo0);
        hi1 = _mm_round_up_even<cyme::sse,1>(hi1);
        lo1 = _mm_round_up_even<cyme::sse,1>(lo1);

        xmm0.r0 =  _mm256_insertf128_si256(xmm0.r0, lo0, 0);
        xmm0.r0 =  _mm256_insertf128_si256(xmm0.r0, hi0, 1);
        xmm0.r1 =  _mm256_insertf128_si256(xmm0.r1, lo1, 0);
        xmm0.r1 =  _mm256_insertf128_si256(xmm0.r1, hi1, 1);
        return simd_trait<int,cyme::avx,2>::register_type(xmm0.r0,xmm0.r1);
    }

    /**
      Rounds xmm0 up to the next even integer.
      Specialisation int, cyme::avx, 4 reg
    */
    template<>
    forceinline simd_trait<int,cyme::avx,4>::register_type
    _mm_round_up_even<cyme::avx,4>( simd_trait<int,cyme::avx,4>::register_type xmm0){
	/* elem 0 */
        __m128i lo0 = _mm256_extractf128_si256(xmm0.r0,0);
        __m128i hi0 = _mm256_extractf128_si256(xmm0.r0,1);
        __m128i lo1 = _mm256_extractf128_si256(xmm0.r1,0);
        __m128i hi1 = _mm256_extractf128_si256(xmm0.r1,1);
        __m128i lo2 = _mm256_extractf128_si256(xmm0.r2,0);
        __m128i hi2 = _mm256_extractf128_si256(xmm0.r2,1);
        __m128i lo3 = _mm256_extractf128_si256(xmm0.r3,0);
        __m128i hi3 = _mm256_extractf128_si256(xmm0.r3,1);

        hi0 = _mm_round_up_even<cyme::sse,1>(hi0);
        lo0 = _mm_round_up_even<cyme::sse,1>(lo0);
        hi1 = _mm_round_up_even<cyme::sse,1>(hi1);
        lo1 = _mm_round_up_even<cyme::sse,1>(lo1);
        hi2 = _mm_round_up_even<cyme::sse,1>(hi2);
        lo2 = _mm_round_up_even<cyme::sse,1>(lo2);
        hi3 = _mm_round_up_even<cyme::sse,1>(hi3);
        lo3 = _mm_round_up_even<cyme::sse,1>(lo3);

        xmm0.r0 =  _mm256_insertf128_si256(xmm0.r0, lo0, 0);
        xmm0.r0 =  _mm256_insertf128_si256(xmm0.r0, hi0, 1);
        xmm0.r1 =  _mm256_insertf128_si256(xmm0.r1, lo1, 0);
        xmm0.r1 =  _mm256_insertf128_si256(xmm0.r1, hi1, 1);
        xmm0.r2 =  _mm256_insertf128_si256(xmm0.r2, lo2, 0);
        xmm0.r2 =  _mm256_insertf128_si256(xmm0.r2, hi2, 1);
        xmm0.r3 =  _mm256_insertf128_si256(xmm0.r3, lo3, 0);
        xmm0.r3 =  _mm256_insertf128_si256(xmm0.r3, hi3, 1);
        return simd_trait<int,cyme::avx,4>::register_type(xmm0.r0,xmm0.r1,
							  xmm0.r2,xmm0.r3);
    }

   /**
      Broadcast a double-precision (64-bit) floating-point element from cyme to all elements of dst.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_load1<double,cyme::avx,1>(const simd_trait<double,cyme::avx,1>::value_type& a){
    // _mm256_broadcast_sd causes me a severe issue of perf into the e^y of the exp with clang
        return _mm256_set1_pd(a);
    }

    /**
      Broadcast a double-precision (64-bit) floating-point element from cyme to all elements of dst.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_load1<double,cyme::avx,2>(const simd_trait<double,cyme::avx,2>::value_type& a){
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_set1_pd(a),_mm256_set1_pd(a));
    }

    /**
      Broadcast a double-precision (64-bit) floating-point element from cyme to all elements of dst.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_load1<double,cyme::avx,4>(const simd_trait<double,cyme::avx,4>::value_type& a){
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_set1_pd(a),_mm256_set1_pd(a),
                                                             _mm256_set1_pd(a),_mm256_set1_pd(a));
    }

    /**
      Load 256-bits (composed of 4 packed double-precision (64-bit) floating-point elements) from cyme into dst.
            mem_addr must be aligned on a 32-byte boundary or a general-protection exception will be generated.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_load<double,cyme::avx,1>(simd_trait<double,cyme::avx,1>::const_pointer a){
        return _mm256_load_pd(a);
    }

    /**
      Load 256-bits (composed of 4 packed double-precision (64-bit) floating-point elements) from cyme into dst.
            mem_addr must be aligned on a 32-byte boundary or a general-protection exception will be generated.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_load<double,cyme::avx,2>(simd_trait<double,cyme::avx,2>::const_pointer a){
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_load_pd(a),_mm256_load_pd(a+4));
    }

    /**
      Load 256-bits (composed of 4 packed double-precision (64-bit) floating-point elements) from cyme into dst.
            mem_addr must be aligned on a 32-byte boundary or a general-protection exception will be generated.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_load<double,cyme::avx,4>(simd_trait<double,cyme::avx,4>::const_pointer a){
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_load_pd(a),_mm256_load_pd(a+4),
                                                             _mm256_load_pd(a+8),_mm256_load_pd(a+12));
    }

     /**
       Load 256-bits (composed of 4 packed double-precision (64-bit) floating-point elements) from cyme into dst.
       using gather operations specialisation double,cyme::avx, 1 regs
     */
     template<>
     forceinline simd_trait<double,cyme::avx,1>::register_type
     _mm_gather<double,cyme::avx,1>(const double* src, const int *ind, const int  __attribute__((unused)) range){
        return _mm256_setr_pd(src[ind[0]],src[ind[1]],src[ind[2]],src[ind[3]]);
     }

     /**
       Load 256-bits (composed of 8 packed double-precision (64-bit) floating-point elements) from cyme into dst.
       using gather operations specialisation double,cyme::avx, 2 regs
     */
     template<>
     forceinline simd_trait<double,cyme::avx,2>::register_type
     _mm_gather<double,cyme::avx,2>(const double* src, const int *ind, const int  __attribute__((unused)) range){
        return simd_trait<double,cyme::avx,2>::register_type(
            _mm256_setr_pd(src[ind[0]],src[ind[1]],src[ind[2]],src[ind[3]]),
            _mm256_setr_pd(src[ind[4]],src[ind[5]],src[ind[6]],src[ind[7]])
        );
     }

     /**
       Load 256-bits (composed of 16 packed double-precision (64-bit) floating-point elements) from cyme into dst.
       using gather operations specialisation double,cyme::avx, 4 regs
     */
     template<>
     forceinline simd_trait<double,cyme::avx,4>::register_type
     _mm_gather<double,cyme::avx,4>(const double* src, const int *ind, const int  __attribute__((unused)) range){
        return simd_trait<double,cyme::avx,4>::register_type(
            _mm256_setr_pd(src[ind[0]],src[ind[1]],src[ind[2]],src[ind[3]]),
            _mm256_setr_pd(src[ind[4]],src[ind[5]],src[ind[6]],src[ind[7]]),
            _mm256_setr_pd(src[ind[8]],src[ind[9]],src[ind[10]],src[ind[11]]),
            _mm256_setr_pd(src[ind[12]],src[ind[13]],src[ind[14]],src[ind[15]])
        );
     }

    /**
      Store 256-bits (composed of 4 packed double-precision (64-bit) floating-point elements) from a into cyme.
      mem_addr must be aligned on a 32-byte boundary or a general-protection exception will be generated.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline void
    _mm_store<double,cyme::avx,1>(simd_trait<double,cyme::avx,1>::register_type xmm0,
                                  simd_trait<double,cyme::avx,1>::pointer a){
        _mm256_store_pd(a,xmm0);
    }

    /**
      Store 256-bits (composed of 4 packed double-precision (64-bit) floating-point elements) from a into cyme.
      mem_addr must be aligned on a 32-byte boundary or a general-protection exception will be generated.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline void
    _mm_store<double,cyme::avx,2>(simd_trait<double,cyme::avx,2>::register_type xmm0,
                                  simd_trait<double,cyme::avx,2>::pointer a){
        _mm256_store_pd(a,xmm0.r0);
        _mm256_store_pd(a+4,xmm0.r1);
    }

    /**
      Store 256-bits (composed of 4 packed double-precision (64-bit) floating-point elements) from a into cyme.
      mem_addr must be aligned on a 32-byte boundary or a general-protection exception will be generated.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline void
    _mm_store<double,cyme::avx,4>(simd_trait<double,cyme::avx,4>::register_type xmm0,
                                  simd_trait<double,cyme::avx,4>::pointer a){
        _mm256_store_pd(a,xmm0.r0);
        _mm256_store_pd(a+4,xmm0.r1);
        _mm256_store_pd(a+8,xmm0.r2);
        _mm256_store_pd(a+12,xmm0.r3);
    }

    /**
      Multiply packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
     and store the results in dst.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_mul<double,cyme::avx,1>(simd_trait<double,cyme::avx,1>::register_type xmm0,
                                simd_trait<double,cyme::avx,1>::register_type xmm1){
        return _mm256_mul_pd(xmm0, xmm1);
    }

    /**
      Multiply packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
     and store the results in dst.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_mul<double,cyme::avx,2>(simd_trait<double,cyme::avx,2>::register_type xmm0,
                                simd_trait<double,cyme::avx,2>::register_type xmm1){
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_mul_pd(xmm0.r0, xmm1.r0),
                                                             _mm256_mul_pd(xmm0.r1, xmm1.r1));
    }

    /**
      Multiply packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
     and store the results in dst.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_mul<double,cyme::avx,4>(simd_trait<double,cyme::avx,4>::register_type xmm0,
                                  simd_trait<double,cyme::avx,4>::register_type xmm1){
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_mul_pd(xmm0.r0, xmm1.r0),
                                                             _mm256_mul_pd(xmm0.r1, xmm1.r1),
                                                             _mm256_mul_pd(xmm0.r2, xmm1.r2),
                                                             _mm256_mul_pd(xmm0.r3, xmm1.r3));
    }

    /**
      Divide packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
      and store the results in dst.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_div<double,cyme::avx,1>(simd_trait<double,cyme::avx,1>::register_type xmm0,
                                simd_trait<double,cyme::avx,1>::register_type xmm1){
        return _mm256_div_pd(xmm0, xmm1);
    }

    /**
      Divide packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
      and store the results in dst.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_div<double,cyme::avx,2>(simd_trait<double,cyme::avx,2>::register_type xmm0,
                                simd_trait<double,cyme::avx,2>::register_type xmm1){
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_div_pd(xmm0.r0, xmm1.r0),
                                                             _mm256_div_pd(xmm0.r1, xmm1.r1));
    }

    /**
      Divide packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
      and store the results in dst.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_div<double,cyme::avx,4>(simd_trait<double,cyme::avx,4>::register_type xmm0,
                                simd_trait<double,cyme::avx,4>::register_type xmm1){
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_div_pd(xmm0.r0, xmm1.r0),
                                                             _mm256_div_pd(xmm0.r1, xmm1.r1),
                                                             _mm256_div_pd(xmm0.r2, xmm1.r2),
                                                             _mm256_div_pd(xmm0.r3, xmm1.r3));
    }

    /**
      Add packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
     and store the results in dst.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_add<double,cyme::avx,1>(simd_trait<double,cyme::avx,1>::register_type xmm0,
                                simd_trait<double,cyme::avx,1>::register_type xmm1){
        return _mm256_add_pd(xmm0, xmm1);
    }

    /**
      Add packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
     and store the results in dst.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_add<double,cyme::avx,2>(simd_trait<double,cyme::avx,2>::register_type xmm0,
                                simd_trait<double,cyme::avx,2>::register_type xmm1){
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_add_pd(xmm0.r0, xmm1.r0),
                                                             _mm256_add_pd(xmm0.r1, xmm1.r1));
    }

    /**
      Add packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
     and store the results in dst.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_add<double,cyme::avx,4>(simd_trait<double,cyme::avx,4>::register_type xmm0,
                                simd_trait<double,cyme::avx,4>::register_type xmm1){
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_add_pd(xmm0.r0, xmm1.r0),
                                                             _mm256_add_pd(xmm0.r1, xmm1.r1),
                                                             _mm256_add_pd(xmm0.r2, xmm1.r2),
                                                             _mm256_add_pd(xmm0.r3, xmm1.r3));
    }

    /**
      Subtract packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
     and store the results in dst.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_sub<double,cyme::avx,1>(simd_trait<double,cyme::avx,1>::register_type xmm0,
                                simd_trait<double,cyme::avx,1>::register_type xmm1){
        return _mm256_sub_pd(xmm0, xmm1);
    }

    /**
      Subtract packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
     and store the results in dst.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_sub<double,cyme::avx,2>(simd_trait<double,cyme::avx,2>::register_type xmm0,
                                simd_trait<double,cyme::avx,2>::register_type xmm1){
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_sub_pd(xmm0.r0, xmm1.r0),
                                                             _mm256_sub_pd(xmm0.r1, xmm1.r1));
    }

    /**
      Subtract packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
     and store the results in dst.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_sub<double,cyme::avx,4>(simd_trait<double,cyme::avx,4>::register_type xmm0,
                                simd_trait<double,cyme::avx,4>::register_type xmm1){
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_sub_pd(xmm0.r0, xmm1.r0),
                                                             _mm256_sub_pd(xmm0.r1, xmm1.r1),
                                                             _mm256_sub_pd(xmm0.r2, xmm1.r2),
                                                             _mm256_sub_pd(xmm0.r3, xmm1.r3));
    }

    /**
      Convert packed double-precision (64-bit) floating-point elements in xmm0
     to packed double-precision (64-bit) floating-point elements, and store the results in dst.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_rec<double,cyme::avx,1>(simd_trait<double,cyme::avx,1>::register_type xmm0){
        return _mm256_cvtps_pd(_mm_rcp_ps(_mm256_cvtpd_ps(xmm0))); // 256d --(cast)--> 128s --(cast)--> 256d
    }

    /**
      Convert packed double-precision (64-bit) floating-point elements in xmm0
     to packed double-precision (64-bit) floating-point elements, and store the results in dst.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_rec<double,cyme::avx,2>(simd_trait<double,cyme::avx,2>::register_type xmm0){
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_cvtps_pd(_mm_rcp_ps(_mm256_cvtpd_ps(xmm0.r0))),
                                                             _mm256_cvtps_pd(_mm_rcp_ps(_mm256_cvtpd_ps(xmm0.r1))));
    }

    /**
      Convert packed double-precision (64-bit) floating-point elements in xmm0
     to packed double-precision (64-bit) floating-point elements, and store the results in dst.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_rec<double,cyme::avx,4>( simd_trait<double,cyme::avx,4>::register_type xmm0){
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_cvtps_pd(_mm_rcp_ps(_mm256_cvtpd_ps(xmm0.r0))),
                                                             _mm256_cvtps_pd(_mm_rcp_ps(_mm256_cvtpd_ps(xmm0.r1))),
                                                             _mm256_cvtps_pd(_mm_rcp_ps(_mm256_cvtpd_ps(xmm0.r2))),
                                                             _mm256_cvtps_pd(_mm_rcp_ps(_mm256_cvtpd_ps(xmm0.r3))));
    }

    /**
      Negate packed double-precision (64-bit) floating-point elements in xmm0 to packed double-precision (64-bit)
     floating-point elements, and store the results in dst.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_neg<double,cyme::avx,1>(simd_trait<double,cyme::avx,1>::register_type xmm0){
        simd_trait<double,cyme::avx,1>::register_type mask(_mm256_castsi256_pd(_mm256_set1_epi64x(0x8000000000000000)));
        return _mm256_xor_pd(xmm0, mask);
    }

    /**
      Negate packed double-precision (64-bit) floating-point elements in xmm0 to packed double-precision (64-bit)
     floating-point elements, and store the results in dst.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_neg<double,cyme::avx,2>(simd_trait<double,cyme::avx,2>::register_type xmm0){
        simd_trait<double,cyme::avx,1>::register_type mask(_mm256_castsi256_pd(_mm256_set1_epi64x(0x8000000000000000)));
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_xor_pd(xmm0.r0, mask),
                                                             _mm256_xor_pd(xmm0.r1, mask));
    }

    /**
      Negate packed double-precision (64-bit) floating-point elements in xmm0 to packed double-precision (64-bit)
     floating-point elements, and store the results in dst.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_neg<double,cyme::avx,4>(simd_trait<double,cyme::avx,4>::register_type xmm0){
        simd_trait<double,cyme::avx,1>::register_type mask(_mm256_castsi256_pd(_mm256_set1_epi64x(0x8000000000000000)));
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_xor_pd(xmm0.r0, mask),
                                                             _mm256_xor_pd(xmm0.r1, mask),
                                                             _mm256_xor_pd(xmm0.r2, mask),
                                                             _mm256_xor_pd(xmm0.r3, mask));
    }

    /**
      Round the packed double-precision (64-bit) floating-point elements in xmm0 down to an integer value,
     and store the results as packed single-precision integer-point elements in dst.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<int,cyme::avx,1>::register_type
    _mm_floor<double,cyme::avx,1>(simd_trait<double,cyme::avx,1>::register_type xmm0){
        return _mm256_castsi128_si256(_mm256_cvttpd_epi32(_mm256_floor_pd(xmm0)));
    }

    /**
      Round the packed double-precision (64-bit) floating-point elements in xmm0 down to an integer value,
     and store the results as packed single-precision integer-point elements in dst.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<int,cyme::avx,2>::register_type
    _mm_floor<double,cyme::avx,2>(simd_trait<double,cyme::avx,2>::register_type xmm0){
        return simd_trait<int,cyme::avx,2>::register_type(_mm256_castsi128_si256(_mm256_cvttpd_epi32(_mm256_floor_pd(xmm0.r0))),
                                                          _mm256_castsi128_si256(_mm256_cvttpd_epi32(_mm256_floor_pd(xmm0.r1))));
    }

    /**
      Round the packed double-precision (64-bit) floating-point elements in xmm0 down to an integer value,
     and store the results as packed single-precision integer-point elements in dst.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<int,cyme::avx,4>::register_type
    _mm_floor<double,cyme::avx,4>(simd_trait<double,cyme::avx,4>::register_type xmm0){
        return simd_trait<int,cyme::avx,4>::register_type(_mm256_castsi128_si256(_mm256_cvttpd_epi32(_mm256_floor_pd(xmm0.r0))),
                                                          _mm256_castsi128_si256(_mm256_cvttpd_epi32(_mm256_floor_pd(xmm0.r1))),
                                                          _mm256_castsi128_si256(_mm256_cvttpd_epi32(_mm256_floor_pd(xmm0.r2))),
                                                          _mm256_castsi128_si256(_mm256_cvttpd_epi32(_mm256_floor_pd(xmm0.r3))));
    }

    /**
      Convert packed 64-bit integers in xmm0 to packed double-precision (64-bit) floating-point elements,
      and store the results in dst.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_cast<double,cyme::avx,1>(simd_trait<int,cyme::avx,1>::register_type xmm0){
        return _mm256_cvtepi32_pd(_mm256_castsi256_si128(xmm0));
    }

    /**
      Convert packed 64-bit integers in xmm0 to packed double-precision (64-bit) floating-point elements,
      and store the results in dst.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_cast<double,cyme::avx,2>(simd_trait<int,cyme::avx,2>::register_type xmm0){
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_cvtepi32_pd(_mm256_castsi256_si128(xmm0.r0)),
                                                             _mm256_cvtepi32_pd(_mm256_castsi256_si128(xmm0.r1)));
    }

    /**
      Convert packed 64-bit integers in xmm0 to packed double-precision (64-bit) floating-point elements,
      and store the results in dst.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_cast<double,cyme::avx,4>(simd_trait<int,cyme::avx,4>::register_type xmm0){
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_cvtepi32_pd(_mm256_castsi256_si128(xmm0.r0)),
                                                             _mm256_cvtepi32_pd(_mm256_castsi256_si128(xmm0.r1)),
                                                             _mm256_cvtepi32_pd(_mm256_castsi256_si128(xmm0.r2)),
                                                             _mm256_cvtepi32_pd(_mm256_castsi256_si128(xmm0.r3)));
    }

    /**
      Compute 2^k packed integer (64-bit) elements in xmm0 to packed double-precision (64-bit)
     floating-point elements, and store the results in dst.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_twok<double,cyme::avx,1>(simd_trait<int,cyme::avx,1>::register_type xmm0){
        // ORIGINAL
        // ((int + 127) << 23) <=> int to float
        __m128i imm0 = _mm_shuffle_epi32(_mm_slli_epi32(_mm_add_epi32(_mm256_castsi256_si128(xmm0),_mm_set1_epi32(1023)),20),
                                         _MM_SHUFFLE(1,3,0,2));
        __m128i imm1 =  _mm_slli_epi64(imm0,32);
        imm0 =  _mm_srli_epi64(imm0,32); //mask will be slower because mov + broadcast + and, I need to mask 6 instructions
        imm0 =  _mm_slli_epi64(imm0,32);
        xmm0 =   _mm256_insertf128_si256(xmm0, imm0,0);
        xmm0 =   _mm256_insertf128_si256(xmm0, imm1,1);
        return  _mm256_castsi256_pd(xmm0);
        // TUNE VERSION, ok if |x| < 89
        // return _mm256_cvtps_pd(_mm_castsi128_ps(_mm_shuffle_epi32(_mm_slli_epi32(
        //          _mm_add_epi32(_mm256_castsi256_si128(xmm0), _mm_set1_epi32(127)), 23), _MM_SHUFFLE(1,3,0,2))));
    }

    /**
      Compute 2^k packed integer (64-bit) elements in xmm0 to packed double-precision (64-bit)
     floating-point elements, and store the results in dst.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_twok<double,cyme::avx,2>(simd_trait<int,cyme::avx,2>::register_type xmm0){
        __m128i imm0_r0 = _mm_add_epi32(_mm256_castsi256_si128(xmm0.r0), _mm_set1_epi32(1023));
        __m128i imm0_r1 = _mm_add_epi32(_mm256_castsi256_si128(xmm0.r1), _mm_set1_epi32(1023));

        imm0_r0 = _mm_slli_epi32(imm0_r0,20);
        imm0_r1 = _mm_slli_epi32(imm0_r1,20);

        imm0_r0 = _mm_shuffle_epi32(imm0_r0,_MM_SHUFFLE(1,3,0,2));
        imm0_r1 = _mm_shuffle_epi32(imm0_r1,_MM_SHUFFLE(1,3,0,2));

        __m128i imm1_r0 =  _mm_slli_epi64(imm0_r0,32);
        __m128i imm1_r1 =  _mm_slli_epi64(imm0_r1,32);

        imm0_r0 =  _mm_srli_epi64(imm0_r0,32);
        imm0_r0 =  _mm_slli_epi64(imm0_r0,32);
        imm0_r1 =  _mm_srli_epi64(imm0_r1,32);
        imm0_r1 =  _mm_slli_epi64(imm0_r1,32);

        xmm0.r0 =   _mm256_insertf128_si256(xmm0.r0,imm0_r0,0);
        xmm0.r1 =   _mm256_insertf128_si256(xmm0.r1,imm0_r1,0);

        xmm0.r0 =   _mm256_insertf128_si256(xmm0.r0,imm1_r0,1);
        xmm0.r1 =   _mm256_insertf128_si256(xmm0.r1,imm1_r1,1);

        return simd_trait<double,cyme::avx,2>::register_type(_mm256_castsi256_pd(xmm0.r0),
                                                             _mm256_castsi256_pd(xmm0.r1));
    }

    /**
      Compute 2^k packed integer (64-bit) elements in xmm0 to packed double-precision (64-bit)
     floating-point elements, and store the results in dst.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_twok<double,cyme::avx,4>(simd_trait<int,cyme::avx,4>::register_type xmm0){
        __m128i imm0_r0 = _mm_add_epi32(_mm256_castsi256_si128(xmm0.r0),_mm_set1_epi32(1023));
        __m128i imm0_r1 = _mm_add_epi32(_mm256_castsi256_si128(xmm0.r1),_mm_set1_epi32(1023));
        __m128i imm0_r2 = _mm_add_epi32(_mm256_castsi256_si128(xmm0.r2),_mm_set1_epi32(1023));
        __m128i imm0_r3 = _mm_add_epi32(_mm256_castsi256_si128(xmm0.r3),_mm_set1_epi32(1023));

        imm0_r0 = _mm_slli_epi32(imm0_r0,20);
        imm0_r1 = _mm_slli_epi32(imm0_r1,20);
        imm0_r2 = _mm_slli_epi32(imm0_r2,20);
        imm0_r3 = _mm_slli_epi32(imm0_r3,20);

        imm0_r0 = _mm_shuffle_epi32(imm0_r0,_MM_SHUFFLE(1,3,0,2));
        imm0_r1 = _mm_shuffle_epi32(imm0_r1,_MM_SHUFFLE(1,3,0,2));
        imm0_r2 = _mm_shuffle_epi32(imm0_r2,_MM_SHUFFLE(1,3,0,2));
        imm0_r3 = _mm_shuffle_epi32(imm0_r3,_MM_SHUFFLE(1,3,0,2));

        __m128i imm1_r0 =  _mm_slli_epi64(imm0_r0,32);
        __m128i imm1_r1 =  _mm_slli_epi64(imm0_r1,32);
        __m128i imm1_r2 =  _mm_slli_epi64(imm0_r2,32);
        __m128i imm1_r3 =  _mm_slli_epi64(imm0_r3,32);

        imm0_r0 =  _mm_srli_epi64(imm0_r0,32);
        imm0_r0 =  _mm_slli_epi64(imm0_r0,32);
        imm0_r1 =  _mm_srli_epi64(imm0_r1,32);
        imm0_r1 =  _mm_slli_epi64(imm0_r1,32);
        imm0_r2 =  _mm_srli_epi64(imm0_r2,32);
        imm0_r2 =  _mm_slli_epi64(imm0_r2,32);
        imm0_r3 =  _mm_srli_epi64(imm0_r3,32);
        imm0_r3 =  _mm_slli_epi64(imm0_r3,32);

        xmm0.r0 =   _mm256_insertf128_si256(xmm0.r0,imm0_r0,0);
        xmm0.r1 =   _mm256_insertf128_si256(xmm0.r1,imm0_r1,0);
        xmm0.r2 =   _mm256_insertf128_si256(xmm0.r2,imm0_r2,0);
        xmm0.r3 =   _mm256_insertf128_si256(xmm0.r3,imm0_r3,0);

        xmm0.r0 =   _mm256_insertf128_si256(xmm0.r0,imm1_r0,1);
        xmm0.r1 =   _mm256_insertf128_si256(xmm0.r1,imm1_r1,1);
        xmm0.r2 =   _mm256_insertf128_si256(xmm0.r2,imm1_r2,1);
        xmm0.r3 =   _mm256_insertf128_si256(xmm0.r3,imm1_r3,1);

        return simd_trait<double,cyme::avx,4>::register_type(_mm256_castsi256_pd(xmm0.r0),
                                                             _mm256_castsi256_pd(xmm0.r1),
                                                             _mm256_castsi256_pd(xmm0.r2),
                                                             _mm256_castsi256_pd(xmm0.r3));
    }

    /**
      Extract the exponent of floating-point exponent (64-bit) elements and store the results in dst.
     arithmetic are very badly supported with AVX, I am presently glue I so do the compuation in SSE;
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_ge<double,cyme::avx,1>(simd_trait<double,cyme::avx,1>::register_type xmm0){
        __m128d lo = _mm256_extractf128_pd(xmm0,0);
        __m128d hi = _mm256_extractf128_pd(xmm0,1);
        hi = _mm_ge<double,cyme::sse,1>(hi);
        lo = _mm_ge<double,cyme::sse,1>(lo);

        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wuninitialized"
        __m256d r(_mm256_insertf128_pd(r,lo,0));
        #pragma GCC diagnostic pop
        r =  _mm256_insertf128_pd(r,hi,1);
        return r;
    }

    /**
      Extract the exponent of floating-point exponent (64-bit) elements and store the results in dst.
     arithmetic are very badly supported with AVX, I am presently glue I so do the compuation in SSE;
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_ge<double,cyme::avx,2>(simd_trait<double,cyme::avx,2>::register_type xmm0){
        __m128d lo0 = _mm256_extractf128_pd(xmm0.r0,0);
        __m128d hi0 = _mm256_extractf128_pd(xmm0.r0,1);
        __m128d lo1 = _mm256_extractf128_pd(xmm0.r1,0);
        __m128d hi1 = _mm256_extractf128_pd(xmm0.r1,1);

        hi0 = _mm_ge<double,cyme::sse,1>(hi0);
        lo0 = _mm_ge<double,cyme::sse,1>(lo0);
        hi1 = _mm_ge<double,cyme::sse,1>(hi1);
        lo1 = _mm_ge<double,cyme::sse,1>(lo1);

        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wuninitialized"
        __m256d r0(_mm256_insertf128_pd(r0,lo0,0));
        __m256d r1(_mm256_insertf128_pd(r1,lo1,0));
        #pragma GCC diagnostic pop

        r0 =  _mm256_insertf128_pd(r0,hi0,1);
        r1 =  _mm256_insertf128_pd(r1,hi1,1);

        return simd_trait<double,cyme::avx,2>::register_type(r0,r1);
    }

    /**
      Extract the exponent of floating-point exponent (64-bit) elements and store the results in dst.
     arithmetic are very badly supported with AVX, I am presently glue I so do the compuation in SSE;
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline  simd_trait<double,cyme::avx,4>::register_type
    _mm_ge<double,cyme::avx,4>(simd_trait<double,cyme::avx,4>::register_type xmm0){
        __m128d lo0 = _mm256_extractf128_pd(xmm0.r0,0);
        __m128d hi0 = _mm256_extractf128_pd(xmm0.r0,1);
        __m128d lo1 = _mm256_extractf128_pd(xmm0.r1,0);
        __m128d hi1 = _mm256_extractf128_pd(xmm0.r1,1);
        __m128d lo2 = _mm256_extractf128_pd(xmm0.r2,0);
        __m128d hi2 = _mm256_extractf128_pd(xmm0.r2,1);
        __m128d lo3 = _mm256_extractf128_pd(xmm0.r3,0);
        __m128d hi3 = _mm256_extractf128_pd(xmm0.r3,1);

        hi0 = _mm_ge<double,cyme::sse,1>(hi0);
        lo0 = _mm_ge<double,cyme::sse,1>(lo0);
        hi1 = _mm_ge<double,cyme::sse,1>(hi1);
        lo1 = _mm_ge<double,cyme::sse,1>(lo1);
        hi2 = _mm_ge<double,cyme::sse,1>(hi2);
        lo2 = _mm_ge<double,cyme::sse,1>(lo2);
        hi3 = _mm_ge<double,cyme::sse,1>(hi3);
        lo3 = _mm_ge<double,cyme::sse,1>(lo3);

        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wuninitialized"
        __m256d r0(_mm256_insertf128_pd(r0,lo0,0));
        __m256d r1(_mm256_insertf128_pd(r1,lo1,0));
        __m256d r2(_mm256_insertf128_pd(r1,lo2,0));
        __m256d r3(_mm256_insertf128_pd(r1,lo3,0));
        #pragma GCC diagnostic pop

        r0 =  _mm256_insertf128_pd(r0,hi0,1);
        r1 =  _mm256_insertf128_pd(r1,hi1,1);
        r2 =  _mm256_insertf128_pd(r2,hi2,1);
        r3 =  _mm256_insertf128_pd(r3,hi3,1);

        return simd_trait<double,cyme::avx,4>::register_type(r0,r1,r2,r3);
    }


    /**
      Extract the fraction of floating-point exponent (64-bit) elements and store the results in dst.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_gf<double,cyme::avx,1>(simd_trait<double,cyme::avx,1>::register_type xmm0){
        __m256i TMP =  _mm256_castpd_si256(xmm0);
        __m128i tmp0 =  _mm256_extractf128_si256(TMP,0);
        tmp0 = _mm_and_si128(tmp0,_mm_set1_epi64x(0xfffffffffffff));
        tmp0 = _mm_add_epi64(tmp0,_mm_set1_epi64x(0x3ff0000000000000));
        __m128i tmp1 =  _mm256_extractf128_si256(TMP,1);
        tmp1 = _mm_and_si128(tmp1,_mm_set1_epi64x(0xfffffffffffff));
        tmp1 = _mm_add_epi64(tmp1,_mm_set1_epi64x(0x3ff0000000000000));
        TMP =   _mm256_insertf128_si256(TMP, tmp0,0);
        TMP =   _mm256_insertf128_si256(TMP, tmp1,1);
        return _mm256_castsi256_pd(TMP);
    }

    /**
      Extract the fraction of floating-point exponent (64-bit) elements and store the results in dst.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_gf<double,cyme::avx,2>(simd_trait<double,cyme::avx,2>::register_type xmm0){
        __m256i TMP0 =  _mm256_castpd_si256(xmm0.r0);
        __m256i TMP1 =  _mm256_castpd_si256(xmm0.r1);

        __m128i tmp0 =  _mm256_extractf128_si256(TMP0,0);
        __m128i tmp1 =  _mm256_extractf128_si256(TMP1,0);

        tmp0 = _mm_and_si128(tmp0,_mm_set1_epi64x(0xfffffffffffff));
        tmp1 = _mm_and_si128(tmp1,_mm_set1_epi64x(0xfffffffffffff));

        tmp0 = _mm_add_epi64(tmp0,_mm_set1_epi64x(0x3ff0000000000000));
        tmp1 = _mm_add_epi64(tmp1,_mm_set1_epi64x(0x3ff0000000000000));

        __m128i tmp01 =  _mm256_extractf128_si256(TMP0,1);
        __m128i tmp11 =  _mm256_extractf128_si256(TMP1,1);

        tmp01 = _mm_and_si128(tmp01,_mm_set1_epi64x(0xfffffffffffff));
        tmp11 = _mm_and_si128(tmp11,_mm_set1_epi64x(0xfffffffffffff));

        tmp01 = _mm_add_epi64(tmp01,_mm_set1_epi64x(0x3ff0000000000000));
        tmp11 = _mm_add_epi64(tmp11,_mm_set1_epi64x(0x3ff0000000000000));

        TMP0 =   _mm256_insertf128_si256(TMP0, tmp0,0);
        TMP0 =   _mm256_insertf128_si256(TMP0, tmp01,1);

        TMP1 =   _mm256_insertf128_si256(TMP1, tmp1,0);
        TMP1 =   _mm256_insertf128_si256(TMP1, tmp11,1);

        return simd_trait<double,cyme::avx,2>::register_type(_mm256_castsi256_pd(TMP0),_mm256_castsi256_pd(TMP1));
    }

    /**
      Extract the fraction of floating-point exponent (64-bit) elements and store the results in dst.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_gf<double,cyme::avx,4>(simd_trait<double,cyme::avx,4>::register_type xmm0){
        __m256i TMP0 =  _mm256_castpd_si256(xmm0.r0);
        __m256i TMP1 =  _mm256_castpd_si256(xmm0.r1);
        __m256i TMP2 =  _mm256_castpd_si256(xmm0.r2);
        __m256i TMP3 =  _mm256_castpd_si256(xmm0.r3);


        __m128i tmp0 =  _mm256_extractf128_si256(TMP0,0);
        __m128i tmp1 =  _mm256_extractf128_si256(TMP1,0);
        __m128i tmp2 =  _mm256_extractf128_si256(TMP2,0);
        __m128i tmp3 =  _mm256_extractf128_si256(TMP3,0);

        tmp0 = _mm_and_si128(tmp0,_mm_set1_epi64x(0xfffffffffffff));
        tmp1 = _mm_and_si128(tmp1,_mm_set1_epi64x(0xfffffffffffff));
        tmp2 = _mm_and_si128(tmp2,_mm_set1_epi64x(0xfffffffffffff));
        tmp3 = _mm_and_si128(tmp3,_mm_set1_epi64x(0xfffffffffffff));

        tmp0 = _mm_add_epi64(tmp0,_mm_set1_epi64x(0x3ff0000000000000));
        tmp1 = _mm_add_epi64(tmp1,_mm_set1_epi64x(0x3ff0000000000000));
        tmp2 = _mm_add_epi64(tmp2,_mm_set1_epi64x(0x3ff0000000000000));
        tmp3 = _mm_add_epi64(tmp3,_mm_set1_epi64x(0x3ff0000000000000));

        __m128i tmp01 =  _mm256_extractf128_si256(TMP0,1);
        __m128i tmp11 =  _mm256_extractf128_si256(TMP1,1);
        __m128i tmp21 =  _mm256_extractf128_si256(TMP2,1);
        __m128i tmp31 =  _mm256_extractf128_si256(TMP3,1);

        tmp01 = _mm_and_si128(tmp01,_mm_set1_epi64x(0xfffffffffffff));
        tmp11 = _mm_and_si128(tmp11,_mm_set1_epi64x(0xfffffffffffff));
        tmp21 = _mm_and_si128(tmp21,_mm_set1_epi64x(0xfffffffffffff));
        tmp31 = _mm_and_si128(tmp31,_mm_set1_epi64x(0xfffffffffffff));

        tmp01 = _mm_add_epi64(tmp01,_mm_set1_epi64x(0x3ff0000000000000));
        tmp11 = _mm_add_epi64(tmp11,_mm_set1_epi64x(0x3ff0000000000000));
        tmp21 = _mm_add_epi64(tmp21,_mm_set1_epi64x(0x3ff0000000000000));
        tmp31 = _mm_add_epi64(tmp31,_mm_set1_epi64x(0x3ff0000000000000));

        TMP0 =   _mm256_insertf128_si256(TMP0, tmp0,0);
        TMP0 =   _mm256_insertf128_si256(TMP0, tmp01,1);

        TMP1 =   _mm256_insertf128_si256(TMP1, tmp1,0);
        TMP1 =   _mm256_insertf128_si256(TMP1, tmp11,1);

        TMP2 =   _mm256_insertf128_si256(TMP2, tmp2,0);
        TMP2 =   _mm256_insertf128_si256(TMP2, tmp21,1);

        TMP3 =   _mm256_insertf128_si256(TMP3, tmp3,0);
        TMP3 =   _mm256_insertf128_si256(TMP3, tmp31,1);

        return simd_trait<double,cyme::avx,4>::register_type(_mm256_castsi256_pd(TMP0),_mm256_castsi256_pd(TMP1),
                                                             _mm256_castsi256_pd(TMP2),_mm256_castsi256_pd(TMP3));
    }

    /**
      Compute sqrt (64-bit) floating point elements in xmm0 to packed double-precision (64-bit)
     floating-point elements, and store the results in dst.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_sqrt<double,cyme::avx,1>( simd_trait<double,cyme::avx,1>::register_type xmm0){
        return _mm256_sqrt_pd(xmm0);
    }

    /**
      Compute sqrt (64-bit) floating point elements in xmm0 to packed double-precision (64-bit)
     floating-point elements, and store the results in dst.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_sqrt<double,cyme::avx,2>( simd_trait<double,cyme::avx,2>::register_type xmm0){
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_sqrt_pd(xmm0.r0),
                                                             _mm256_sqrt_pd(xmm0.r1));
    }

    /**
      Compute sqrt (64-bit) floating point elements in xmm0 to packed double-precision (64-bit)
     floating-point elements, and store the results in dst.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_sqrt<double,cyme::avx,4>( simd_trait<double,cyme::avx,4>::register_type xmm0){
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_sqrt_pd(xmm0.r0),
                                                             _mm256_sqrt_pd(xmm0.r1),
                                                             _mm256_sqrt_pd(xmm0.r2),
                                                             _mm256_sqrt_pd(xmm0.r3));
    }

    /**
      Compute 1/recsqrt (64-bit) floating point elements in xmm0 to packed double-precision (64-bit)
      floating-point elements, and store the results in dst. precision 12 bits
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_rsqrt<double,cyme::avx,1>(simd_trait<double,cyme::avx,1>::register_type xmm0){
        return _mm256_cvtps_pd(_mm_rsqrt_ps(_mm256_cvtpd_ps(xmm0)));
    }

    /**
      Compute 1/recsqrt (64-bit) floating point elements in xmm0 to packed double-precision (64-bit)
      floating-point elements, and store the results in dst. precision 12 bits
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_rsqrt<double,cyme::avx,2>(simd_trait<double,cyme::avx,2>::register_type xmm0){
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_cvtps_pd(_mm_rsqrt_ps(_mm256_cvtpd_ps(xmm0.r0))),
                                                             _mm256_cvtps_pd(_mm_rsqrt_ps(_mm256_cvtpd_ps(xmm0.r1))));
    }

    /**
      Compute 1/recsqrt (64-bit) floating point elements in xmm0 to packed double-precision (64-bit)
      floating-point elements, and store the results in dst. precision 12 bits
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_rsqrt<double,cyme::avx,4>(simd_trait<double,cyme::avx,4>::register_type xmm0){
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_cvtps_pd(_mm_rsqrt_ps(_mm256_cvtpd_ps(xmm0.r0))),
                                                             _mm256_cvtps_pd(_mm_rsqrt_ps(_mm256_cvtpd_ps(xmm0.r1))),
                                                             _mm256_cvtps_pd(_mm_rsqrt_ps(_mm256_cvtpd_ps(xmm0.r2))),
                                                             _mm256_cvtps_pd(_mm_rsqrt_ps(_mm256_cvtpd_ps(xmm0.r3))));
    }

    /**
      Computes the absolute value for double-precision (64-bit) floating point elements and stores
      the result in dst.
      specialisation double,cyme::avx, 1 reg
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_fabs<double,cyme::avx,1>( simd_trait<double,cyme::avx,1>::register_type xmm0){
        simd_trait<double,cyme::avx,1>::register_type mask(_mm256_castsi256_pd(_mm256_set1_epi64x(0x7fffffffffffffff)));
	return _mm256_and_pd(xmm0, mask);
    }

    /**
      Computes the absolute value for single-precision (32-bit) floating point elements and stores
      the result in dst.
      specialisation double,cyme::avx, 2 reg
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_fabs<double,cyme::avx,2>( simd_trait<double,cyme::avx,2>::register_type xmm0){
        simd_trait<double,cyme::avx,1>::register_type mask(_mm256_castsi256_pd(_mm256_set1_epi64x(0x7fffffffffffffff)));
	return simd_trait<double,cyme::avx,2>::register_type(_mm256_and_pd(xmm0.r0, mask),
							     _mm256_and_pd(xmm0.r1, mask));
    }

    /**
      Computes the absolute value for single-precision (32-bit) floating point elements and stores
      the result in dst.
      specialisation double,cyme::avx, 4 reg
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_fabs<double,cyme::avx,4>( simd_trait<double,cyme::avx,4>::register_type xmm0){
        simd_trait<double,cyme::avx,1>::register_type mask(_mm256_castsi256_pd(_mm256_set1_epi64x(0x7fffffffffffffff)));
	return simd_trait<double,cyme::avx,4>::register_type(_mm256_and_pd(xmm0.r0, mask),
							     _mm256_and_pd(xmm0.r1, mask),
							     _mm256_and_pd(xmm0.r2, mask),
							     _mm256_and_pd(xmm0.r3, mask));
    }

    /**
      Selects the polynomial for sin function. Inputs are:
	- Selector int
	- Option one
	- Option two
      specialisation double,cyme::avx, 1 reg
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_select_poly<double,cyme::avx,1>( simd_trait<int,cyme::avx,1>::register_type sel,
                                         simd_trait<double,cyme::avx,1>::register_type xmm0,
                                         simd_trait<double,cyme::avx,1>::register_type xmm1){
 	__m128i mask = _mm_set1_epi32(2);
 	__m128i zero = _mm_set1_epi32(0);

        __m128i imm0 = _mm_shuffle_epi32(_mm_cmpeq_epi32(_mm_and_si128(_mm256_castsi256_si128(sel),mask),zero),
                                         _MM_SHUFFLE(1,3,0,2));
        __m128i imm1 =  _mm_slli_epi64(imm0,32);
        imm0 =  _mm_srli_epi64(imm0,32); //mask will be slower because mov + broadcast + and, I need to mask 6 instructions
        imm0 =  _mm_slli_epi64(imm0,32);
        sel = _mm256_insertf128_si256(sel, imm0, 0);
        sel = _mm256_insertf128_si256(sel, imm1, 1);

 	xmm0 = _mm256_andnot_pd(_mm256_castsi256_pd(sel), xmm0);
 	xmm1 = _mm256_and_pd(_mm256_castsi256_pd(sel), xmm1);
 	return _mm256_add_pd(xmm0,xmm1);
	//return _mm256_cvtepi32_pd(imm1);
    }

    /**
      Selects the polynomial for sin function. Inputs are:
	- Selector int
	- Option one
	- Option two
      specialisation double,cyme::avx, 2 reg
     */
   template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_select_poly<double,cyme::avx,2>( simd_trait<int,cyme::avx,2>::register_type sel,
                                         simd_trait<double,cyme::avx,2>::register_type xmm0,
                                         simd_trait<double,cyme::avx,2>::register_type xmm1){
 	__m128i mask = _mm_set1_epi32(2);
 	__m128i zero = _mm_set1_epi32(0);

        __m128i imm0_0 = _mm_shuffle_epi32(_mm_cmpeq_epi32(_mm_and_si128(_mm256_castsi256_si128(sel.r0),mask),zero),
                                         _MM_SHUFFLE(1,3,0,2));
        __m128i imm0_1 = _mm_shuffle_epi32(_mm_cmpeq_epi32(_mm_and_si128(_mm256_castsi256_si128(sel.r1),mask),zero),
                                         _MM_SHUFFLE(1,3,0,2));
        __m128i imm1_0 =  _mm_slli_epi64(imm0_0,32);
        __m128i imm1_1 =  _mm_slli_epi64(imm0_1,32);
        imm0_0 =  _mm_srli_epi64(imm0_0,32);
        imm0_1 =  _mm_srli_epi64(imm0_1,32);
        imm0_0 =  _mm_slli_epi64(imm0_0,32);
        imm0_1 =  _mm_slli_epi64(imm0_1,32);
        sel.r0 = _mm256_insertf128_si256(sel.r0, imm0_0, 0);
        sel.r1 = _mm256_insertf128_si256(sel.r1, imm0_1, 0);
        sel.r0 = _mm256_insertf128_si256(sel.r0, imm1_0, 1);
        sel.r1 = _mm256_insertf128_si256(sel.r1, imm1_1, 1);

 	xmm0.r0 = _mm256_andnot_pd(_mm256_castsi256_pd(sel.r0), xmm0.r0);
 	xmm0.r1 = _mm256_andnot_pd(_mm256_castsi256_pd(sel.r1), xmm0.r1);
 	xmm1.r0 = _mm256_and_pd(_mm256_castsi256_pd(sel.r0), xmm1.r0);
 	xmm1.r1 = _mm256_and_pd(_mm256_castsi256_pd(sel.r1), xmm1.r1);
 	return simd_trait<double,cyme::avx,2>::register_type(_mm256_add_pd(xmm0.r0,xmm1.r0),
							     _mm256_add_pd(xmm0.r1,xmm1.r1));
    }

    /**
      Selects the polynomial for sin function. Inputs are:
	- Selector int
	- Option one
	- Option two
      specialisation double,cyme::avx, 4 reg
     */
   template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_select_poly<double,cyme::avx,4>( simd_trait<int,cyme::avx,4>::register_type sel,
                                         simd_trait<double,cyme::avx,4>::register_type  xmm0,
                                         simd_trait<double,cyme::avx,4>::register_type xmm1){
 	__m128i mask = _mm_set1_epi32(2);
 	__m128i zero = _mm_set1_epi32(0);

        __m128i imm0_0 = _mm_shuffle_epi32(_mm_cmpeq_epi32(_mm_and_si128(_mm256_castsi256_si128(sel.r0),mask),zero),
                                         _MM_SHUFFLE(1,3,0,2));
        __m128i imm0_1 = _mm_shuffle_epi32(_mm_cmpeq_epi32(_mm_and_si128(_mm256_castsi256_si128(sel.r1),mask),zero),
                                         _MM_SHUFFLE(1,3,0,2));
        __m128i imm0_2 = _mm_shuffle_epi32(_mm_cmpeq_epi32(_mm_and_si128(_mm256_castsi256_si128(sel.r2),mask),zero),
                                         _MM_SHUFFLE(1,3,0,2));
        __m128i imm0_3 = _mm_shuffle_epi32(_mm_cmpeq_epi32(_mm_and_si128(_mm256_castsi256_si128(sel.r3),mask),zero),
                                         _MM_SHUFFLE(1,3,0,2));
        __m128i imm1_0 =  _mm_slli_epi64(imm0_0,32);
        __m128i imm1_1 =  _mm_slli_epi64(imm0_1,32);
        __m128i imm1_2 =  _mm_slli_epi64(imm0_2,32);
        __m128i imm1_3 =  _mm_slli_epi64(imm0_3,32);
        imm0_0 =  _mm_srli_epi64(imm0_0,32);
        imm0_1 =  _mm_srli_epi64(imm0_1,32);
        imm0_2 =  _mm_srli_epi64(imm0_2,32);
        imm0_3 =  _mm_srli_epi64(imm0_3,32);
        imm0_0 =  _mm_slli_epi64(imm0_0,32);
        imm0_1 =  _mm_slli_epi64(imm0_1,32);
        imm0_2 =  _mm_slli_epi64(imm0_2,32);
        imm0_3 =  _mm_slli_epi64(imm0_3,32);
        sel.r0 = _mm256_insertf128_si256(sel.r0, imm0_0, 0);
        sel.r1 = _mm256_insertf128_si256(sel.r1, imm0_1, 0);
        sel.r2 = _mm256_insertf128_si256(sel.r2, imm0_2, 0);
        sel.r3 = _mm256_insertf128_si256(sel.r3, imm0_3, 0);
        sel.r0 = _mm256_insertf128_si256(sel.r0, imm1_0, 1);
        sel.r1 = _mm256_insertf128_si256(sel.r1, imm1_1, 1);
        sel.r2 = _mm256_insertf128_si256(sel.r2, imm1_2, 1);
        sel.r3 = _mm256_insertf128_si256(sel.r3, imm1_3, 1);

 	xmm0.r0 = _mm256_andnot_pd(_mm256_castsi256_pd(sel.r0), xmm0.r0);
 	xmm0.r1 = _mm256_andnot_pd(_mm256_castsi256_pd(sel.r1), xmm0.r1);
 	xmm0.r2 = _mm256_andnot_pd(_mm256_castsi256_pd(sel.r2), xmm0.r2);
 	xmm0.r3 = _mm256_andnot_pd(_mm256_castsi256_pd(sel.r3), xmm0.r3);
 	xmm1.r0 = _mm256_and_pd(_mm256_castsi256_pd(sel.r0), xmm1.r0);
 	xmm1.r1 = _mm256_and_pd(_mm256_castsi256_pd(sel.r1), xmm1.r1);
 	xmm1.r2 = _mm256_and_pd(_mm256_castsi256_pd(sel.r2), xmm1.r2);
 	xmm1.r3 = _mm256_and_pd(_mm256_castsi256_pd(sel.r3), xmm1.r3);
 	return simd_trait<double,cyme::avx,4>::register_type(_mm256_add_pd(xmm0.r0,xmm1.r0),
							     _mm256_add_pd(xmm0.r1,xmm1.r1),
							     _mm256_add_pd(xmm0.r2,xmm1.r2),
							     _mm256_add_pd(xmm0.r3,xmm1.r3));
    }

    /**
      Selects the sign (+/-) for sin function. Inputs are:
	- swap int
	- Original input
	- Final calculated sin value
      specialisation double,cyme::avx, 1 reg
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_select_sign_sin<double,cyme::avx,1>( simd_trait<int,cyme::avx,1>::register_type swap,
                                             simd_trait<double,cyme::avx,1>::register_type xmm0,
                                             simd_trait<double,cyme::avx,1>::register_type xmm1){
        __m256d mask = _mm256_castsi256_pd(_mm256_set1_epi32(0x80000000));
        __m128i four = _mm_set1_epi32(4);
	/* extract the sign bit (upper one) from original val */
	xmm0 = _mm256_and_pd(xmm0, mask);

	/* get the swap sign flag */
        __m128i imm0 = _mm_shuffle_epi32(_mm_slli_epi32(_mm_and_si128(_mm256_castsi256_si128(swap),four),29),
                                         _MM_SHUFFLE(1,3,0,2));
        __m128i imm1 =  _mm_slli_epi64(imm0,32);
        imm0 =  _mm_srli_epi64(imm0,32); //mask will be slower because mov + broadcast + and, I need to mask 6 instructions
        imm0 =  _mm_slli_epi64(imm0,32);
        swap = _mm256_insertf128_si256(swap, imm0, 0);
        swap = _mm256_insertf128_si256(swap, imm1, 1);

	/* update the sign of the final value*/
	xmm1 = _mm256_xor_pd(xmm1, _mm256_castsi256_pd(swap));
	xmm1 = _mm256_xor_pd(xmm1, xmm0);
	return xmm1;
    }

    /**
      Selects the sign (+/-) for sin function. Inputs are:
	- swap int
	- Original input
	- Final calculated sin value
      specialisation double ,cyme::avx, 2 reg
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_select_sign_sin<double,cyme::avx,2>( simd_trait<int,cyme::avx,2>::register_type swap,
                                             simd_trait<double,cyme::avx,2>::register_type  xmm0,
                                             simd_trait<double,cyme::avx,2>::register_type xmm1){
        __m256d mask = _mm256_castsi256_pd(_mm256_set1_epi32(0x80000000));
        __m128i four = _mm_set1_epi32(4);
	/* extract the sign bit (upper one) from original val */
	xmm0.r0 = _mm256_and_pd(xmm0.r0, mask);
	xmm0.r1 = _mm256_and_pd(xmm0.r1, mask);

	/* get the swap sign flag */
        __m128i imm0_0 = _mm_shuffle_epi32(_mm_slli_epi32(_mm_and_si128(_mm256_castsi256_si128(swap.r0),four),29),
                                         _MM_SHUFFLE(1,3,0,2));
        __m128i imm0_1 = _mm_shuffle_epi32(_mm_slli_epi32(_mm_and_si128(_mm256_castsi256_si128(swap.r1),four),29),
                                         _MM_SHUFFLE(1,3,0,2));
        __m128i imm1_0 =  _mm_slli_epi64(imm0_0,32);
        __m128i imm1_1 =  _mm_slli_epi64(imm0_1,32);
        imm0_0 =  _mm_srli_epi64(imm0_0,32);
        imm0_1 =  _mm_srli_epi64(imm0_1,32);
        imm0_0 =  _mm_slli_epi64(imm0_0,32);
        imm0_1 =  _mm_slli_epi64(imm0_1,32);
        swap.r0 = _mm256_insertf128_si256(swap.r0, imm0_0, 0);
        swap.r1 = _mm256_insertf128_si256(swap.r1, imm0_1, 0);
        swap.r0 = _mm256_insertf128_si256(swap.r0, imm1_0, 1);
        swap.r1 = _mm256_insertf128_si256(swap.r1, imm1_1, 1);

	/* update the sign of the final value*/
	xmm1.r0 = _mm256_xor_pd(xmm1.r0, _mm256_castsi256_pd(swap.r0));
	xmm1.r1 = _mm256_xor_pd(xmm1.r1, _mm256_castsi256_pd(swap.r1));
	xmm1.r0 = _mm256_xor_pd(xmm1.r0, xmm0.r0);
	xmm1.r1 = _mm256_xor_pd(xmm1.r1, xmm0.r1);
	return simd_trait<double,cyme::avx,2>::register_type(xmm1.r0,xmm1.r1);
    }

    /**
      Selects the sign (+/-) for sin function. Inputs are:
	- swap int
	- Original input
	- Final calculated sin value
      specialisation double ,cyme::avx, 4 reg
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_select_sign_sin<double,cyme::avx,4>( simd_trait<int,cyme::avx,4>::register_type swap,
                                         simd_trait<double,cyme::avx,4>::register_type  xmm0,
                                         simd_trait<double,cyme::avx,4>::register_type xmm1){
        __m256d mask = _mm256_castsi256_pd(_mm256_set1_epi32(0x80000000));
        __m128i four = _mm_set1_epi32(4);
	/* extract the sign bit (upper one) from original val */
	xmm0.r0 = _mm256_and_pd(xmm0.r0, mask);
	xmm0.r1 = _mm256_and_pd(xmm0.r1, mask);
	xmm0.r2 = _mm256_and_pd(xmm0.r2, mask);
	xmm0.r3 = _mm256_and_pd(xmm0.r3, mask);

	/* get the swap sign flag */
        __m128i imm0_0 = _mm_shuffle_epi32(_mm_slli_epi32(_mm_and_si128(_mm256_castsi256_si128(swap.r0),four),29),
                                         _MM_SHUFFLE(1,3,0,2));
        __m128i imm0_1 = _mm_shuffle_epi32(_mm_slli_epi32(_mm_and_si128(_mm256_castsi256_si128(swap.r1),four),29),
                                         _MM_SHUFFLE(1,3,0,2));
        __m128i imm0_2 = _mm_shuffle_epi32(_mm_slli_epi32(_mm_and_si128(_mm256_castsi256_si128(swap.r2),four),29),
                                         _MM_SHUFFLE(1,3,0,2));
        __m128i imm0_3 = _mm_shuffle_epi32(_mm_slli_epi32(_mm_and_si128(_mm256_castsi256_si128(swap.r3),four),29),
                                         _MM_SHUFFLE(1,3,0,2));
        __m128i imm1_0 =  _mm_slli_epi64(imm0_0,32);
        __m128i imm1_1 =  _mm_slli_epi64(imm0_1,32);
        __m128i imm1_2 =  _mm_slli_epi64(imm0_2,32);
        __m128i imm1_3 =  _mm_slli_epi64(imm0_3,32);
        imm0_0 =  _mm_srli_epi64(imm0_0,32);
        imm0_1 =  _mm_srli_epi64(imm0_1,32);
        imm0_2 =  _mm_srli_epi64(imm0_2,32);
        imm0_3 =  _mm_srli_epi64(imm0_3,32);
        imm0_0 =  _mm_slli_epi64(imm0_0,32);
        imm0_1 =  _mm_slli_epi64(imm0_1,32);
        imm0_2 =  _mm_slli_epi64(imm0_2,32);
        imm0_3 =  _mm_slli_epi64(imm0_3,32);
        swap.r0 = _mm256_insertf128_si256(swap.r0, imm0_0, 0);
        swap.r1 = _mm256_insertf128_si256(swap.r1, imm0_1, 0);
        swap.r2 = _mm256_insertf128_si256(swap.r2, imm0_2, 0);
        swap.r3 = _mm256_insertf128_si256(swap.r3, imm0_3, 0);
        swap.r0 = _mm256_insertf128_si256(swap.r0, imm1_0, 1);
        swap.r1 = _mm256_insertf128_si256(swap.r1, imm1_1, 1);
        swap.r2 = _mm256_insertf128_si256(swap.r2, imm1_2, 1);
        swap.r3 = _mm256_insertf128_si256(swap.r3, imm1_3, 1);

	/* update the sign of the final value*/
	xmm1.r0 = _mm256_xor_pd(xmm1.r0, _mm256_castsi256_pd(swap.r0));
	xmm1.r1 = _mm256_xor_pd(xmm1.r1, _mm256_castsi256_pd(swap.r1));
	xmm1.r2 = _mm256_xor_pd(xmm1.r2, _mm256_castsi256_pd(swap.r2));
	xmm1.r3 = _mm256_xor_pd(xmm1.r3, _mm256_castsi256_pd(swap.r3));
	xmm1.r0 = _mm256_xor_pd(xmm1.r0, xmm0.r0);
	xmm1.r1 = _mm256_xor_pd(xmm1.r1, xmm0.r1);
	xmm1.r2 = _mm256_xor_pd(xmm1.r2, xmm0.r2);
	xmm1.r3 = _mm256_xor_pd(xmm1.r3, xmm0.r3);
	return simd_trait<double,cyme::avx,4>::register_type(xmm1.r0,xmm1.r1,
							     xmm1.r2,xmm1.r3);
    }

    /**
      Selects the sign (+/-) for cos function. Inputs are:
	- swap int
	- Final calculated cos value
      specialisation double,cyme::avx, 1 reg
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_select_sign_cos<double,cyme::avx,1>( simd_trait<int,cyme::avx,1>::register_type swap,
                                             simd_trait<double,cyme::avx,1>::register_type xmm0){
        __m128i four = _mm_set1_epi32(4);
	/* get the swap sign flag */
        __m128i imm0 = _mm_shuffle_epi32(_mm_slli_epi32(_mm_andnot_si128(_mm256_castsi256_si128(swap),four),29),
                                         _MM_SHUFFLE(1,3,0,2));
        __m128i imm1 =  _mm_slli_epi64(imm0,32);
        imm0 =  _mm_srli_epi64(imm0,32); //mask will be slower because mov + broadcast + and, I need to mask 6 instructions
        imm0 =  _mm_slli_epi64(imm0,32);
        swap = _mm256_insertf128_si256(swap, imm0, 0);
        swap = _mm256_insertf128_si256(swap, imm1, 1);

	/* update the sign of the final value*/
	xmm0 = _mm256_xor_pd(xmm0, _mm256_castsi256_pd(swap));
	return xmm0;
    }

    /**
      Selects the sign (+/-) for cos function. Inputs are:
	- swap int
	- Final calculated cos value
      specialisation double,cyme::avx, 2 reg
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_select_sign_cos<double,cyme::avx,2>( simd_trait<int,cyme::avx,2>::register_type swap,
                                             simd_trait<double,cyme::avx,2>::register_type xmm0){
        __m128i four = _mm_set1_epi32(4);
	/* get the swap sign flag */
        __m128i imm0_0 = _mm_shuffle_epi32(_mm_slli_epi32(_mm_andnot_si128(_mm256_castsi256_si128(swap.r0),four),29),
                                         _MM_SHUFFLE(1,3,0,2));
        __m128i imm0_1 = _mm_shuffle_epi32(_mm_slli_epi32(_mm_andnot_si128(_mm256_castsi256_si128(swap.r1),four),29),
                                         _MM_SHUFFLE(1,3,0,2));
        __m128i imm1_0 =  _mm_slli_epi64(imm0_0,32);
        __m128i imm1_1 =  _mm_slli_epi64(imm0_1,32);
        imm0_0 =  _mm_srli_epi64(imm0_0,32);
        imm0_1 =  _mm_srli_epi64(imm0_1,32);
        imm0_0 =  _mm_slli_epi64(imm0_0,32);
        imm0_1 =  _mm_slli_epi64(imm0_1,32);
        swap.r0 = _mm256_insertf128_si256(swap.r0, imm0_0, 0);
        swap.r1 = _mm256_insertf128_si256(swap.r1, imm0_1, 0);
        swap.r0 = _mm256_insertf128_si256(swap.r0, imm1_0, 1);
        swap.r1 = _mm256_insertf128_si256(swap.r1, imm1_1, 1);

	/* update the sign of the final value*/
	xmm0.r0 = _mm256_xor_pd(xmm0.r0, _mm256_castsi256_pd(swap.r0));
	xmm0.r1 = _mm256_xor_pd(xmm0.r1, _mm256_castsi256_pd(swap.r1));
	return simd_trait<double,cyme::avx,2>::register_type(xmm0.r0,xmm0.r1);
    }

    /**
      Selects the sign (+/-) for cos function. Inputs are:
	- swap int
	- Final calculated cos value
      specialisation double,cyme::avx, 4 reg
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_select_sign_cos<double,cyme::avx,4>( simd_trait<int,cyme::avx,4>::register_type swap,
                                             simd_trait<double,cyme::avx,4>::register_type xmm0){
	simd_trait<double,cyme::avx,1>::register_type r0 = _mm_select_sign_cos<double,cyme::avx,1>(swap.r0,xmm0.r0);
	simd_trait<double,cyme::avx,1>::register_type r1 = _mm_select_sign_cos<double,cyme::avx,1>(swap.r1,xmm0.r1);
	simd_trait<double,cyme::avx,1>::register_type r2 = _mm_select_sign_cos<double,cyme::avx,1>(swap.r2,xmm0.r2);
	simd_trait<double,cyme::avx,1>::register_type r3 = _mm_select_sign_cos<double,cyme::avx,1>(swap.r3,xmm0.r3);
	return simd_trait<double,cyme::avx,4>::register_type(r0,r1,r2,r3);
    }

     /**
      Evaluate the the < operator, return if true return 0xffffffffffffffff (true) else 0 (false)
      specialisation double,cyme::avx,1 regs
     */
     template<>
     forceinline simd_trait<double,cyme::avx,1>::register_type
     _mm_lt<double,cyme::avx,1> (simd_trait<double,cyme::avx,1>::register_type xmm0,
                                 simd_trait<double,cyme::avx,1>::register_type xmm1){
        return   (_mm256_cmp_pd(xmm0, xmm1,_CMP_LT_OS));
     }

     /**
      Evaluate the the < operator, return if true return 0xffffffffffffffff (true) else 0 (false)
      specialisation double,cyme::avx,2 regs
     */
     template<>
     forceinline simd_trait<double,cyme::avx,2>::register_type
     _mm_lt<double,cyme::avx,2> (simd_trait<double,cyme::avx,2>::register_type xmm0,
                                 simd_trait<double,cyme::avx,2>::register_type xmm1){
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_cmp_pd(xmm0.r0, xmm1.r0,_CMP_LT_OS),
                                                             _mm256_cmp_pd(xmm0.r1, xmm1.r1,_CMP_LT_OS));
     }

     /**
      Evaluate the the < operator, return if true return 0xffffffffffffffff (true) else 0 (false)
      specialisation double,cyme::avx,4 regs
     */
     template<>
     forceinline simd_trait<double,cyme::avx,4>::register_type
     _mm_lt<double,cyme::avx,4> (simd_trait<double,cyme::avx,4>::register_type xmm0,
                                 simd_trait<double,cyme::avx,4>::register_type xmm1){
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_cmp_pd(xmm0.r0, xmm1.r0,_CMP_LT_OS),
                                                             _mm256_cmp_pd(xmm0.r1, xmm1.r1,_CMP_LT_OS),
                                                             _mm256_cmp_pd(xmm0.r2, xmm1.r2,_CMP_LT_OS),
                                                             _mm256_cmp_pd(xmm0.r3, xmm1.r3,_CMP_LT_OS));
     }

    /**
     Evaluate the the > operator, return if true return 0xffffffffffffffff (true) else 0 (false)
     specialisation double,cyme::avx,1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_gt<double,cyme::avx,1> (simd_trait<double,cyme::avx,1>::register_type xmm0,
                                simd_trait<double,cyme::avx,1>::register_type xmm1){
        return   (_mm256_cmp_pd(xmm0, xmm1,_CMP_GT_OS));
    }

    /**
     Evaluate the the > operator, return if true return 0xffffffffffffffff (true) else 0 (false)
     specialisation double,cyme::avx,2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_gt<double,cyme::avx,2> (simd_trait<double,cyme::avx,2>::register_type xmm0,
                                simd_trait<double,cyme::avx,2>::register_type xmm1){
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_cmp_pd(xmm0.r0, xmm1.r0,_CMP_GT_OS),
                                                             _mm256_cmp_pd(xmm0.r1, xmm1.r1,_CMP_GT_OS));
    }

    /**
     Evaluate the the > operator, return if true return 0xffffffffffffffff (true) else 0 (false)
     specialisation double,cyme::avx,4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_gt<double,cyme::avx,4> (simd_trait<double,cyme::avx,4>::register_type xmm0,
                                simd_trait<double,cyme::avx,4>::register_type xmm1){
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_cmp_pd(xmm0.r0, xmm1.r0,_CMP_GT_OS),
                                                             _mm256_cmp_pd(xmm0.r1, xmm1.r1,_CMP_GT_OS),
                                                             _mm256_cmp_pd(xmm0.r2, xmm1.r2,_CMP_GT_OS),
                                                             _mm256_cmp_pd(xmm0.r3, xmm1.r3,_CMP_GT_OS));
    }

    /**
     Evaluate the the == operator, return if true return 0xffffffffffffffff (true) else 0 (false)
     specialisation double,cyme::avx,1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_eq<double,cyme::avx,1> (simd_trait<double,cyme::avx,1>::register_type xmm0,
                                simd_trait<double,cyme::avx,1>::register_type xmm1){
        return   (_mm256_cmp_pd(xmm0, xmm1,_CMP_EQ_OS));
    }

    /**
     Evaluate the the == operator, return if true return 0xffffffffffffffff (true) else 0 (false)
     specialisation double,cyme::avx,2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_eq<double,cyme::avx,2> (simd_trait<double,cyme::avx,2>::register_type xmm0,
                                simd_trait<double,cyme::avx,2>::register_type xmm1){
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_cmp_pd(xmm0.r0, xmm1.r0,_CMP_EQ_OS),
                                                             _mm256_cmp_pd(xmm0.r1, xmm1.r1,_CMP_EQ_OS));
    }

    /**
     Evaluate the the == operator, return if true return 0xffffffffffffffff (true) else 0 (false)
     specialisation double,cyme::avx,4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_eq<double,cyme::avx,4> (simd_trait<double,cyme::avx,4>::register_type xmm0,
                                simd_trait<double,cyme::avx,4>::register_type xmm1){
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_cmp_pd(xmm0.r0, xmm1.r0,_CMP_EQ_OS),
                                                             _mm256_cmp_pd(xmm0.r1, xmm1.r1,_CMP_EQ_OS),
                                                             _mm256_cmp_pd(xmm0.r2, xmm1.r2,_CMP_EQ_OS),
                                                             _mm256_cmp_pd(xmm0.r3, xmm1.r3,_CMP_EQ_OS));
    }

    /**
     Evaluate the  & operator between two registers
     specialisation double,cyme::avx,1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_and<double,cyme::avx,1> (simd_trait<double,cyme::avx,1>::register_type xmm0,
                                 simd_trait<double,cyme::avx,1>::register_type xmm1){
        return _mm256_and_pd(xmm0,xmm1);
    }

    /**
     Evaluate the  & operator between two registers
     specialisation double,cyme::avx,2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_and<double,cyme::avx,2> (simd_trait<double,cyme::avx,2>::register_type xmm0,
                                 simd_trait<double,cyme::avx,2>::register_type xmm1){
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_and_pd(xmm0.r0,xmm1.r0),
                                                             _mm256_and_pd(xmm0.r1,xmm1.r1));
    }

    /**
     Evaluate the  & operator between two registers
     specialisation double,cyme::avx,4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_and<double,cyme::avx,4> (simd_trait<double,cyme::avx,4>::register_type xmm0,
                              simd_trait<double,cyme::avx,4>::register_type xmm1){
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_and_pd(xmm0.r0,xmm1.r0),
                                                             _mm256_and_pd(xmm0.r1,xmm1.r1),
                                                             _mm256_and_pd(xmm0.r2,xmm1.r2),
                                                             _mm256_and_pd(xmm0.r3,xmm1.r3));
    }

    /**
     Evaluate the  | operator between two registers
     specialisation double,cyme::avx,1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_or<double,cyme::avx,1> (simd_trait<double,cyme::avx,1>::register_type xmm0,
                                simd_trait<double,cyme::avx,1>::register_type xmm1){
        return _mm256_or_pd(xmm0,xmm1);
    }

    /**
     Evaluate the  | operator between two registers
     specialisation double,cyme::avx,2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_or<double,cyme::avx,2> (simd_trait<double,cyme::avx,2>::register_type xmm0,
                                simd_trait<double,cyme::avx,2>::register_type xmm1){
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_or_pd(xmm0.r0,xmm1.r0),
                                                             _mm256_or_pd(xmm0.r1,xmm1.r1));
    }

    /**
     Evaluate the  | operator between two registers
     specialisation double,cyme::avx,4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_or<double,cyme::avx,4> (simd_trait<double,cyme::avx,4>::register_type xmm0,
                                simd_trait<double,cyme::avx,4>::register_type xmm1){
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_or_pd(xmm0.r0,xmm1.r0),
                                                             _mm256_or_pd(xmm0.r1,xmm1.r1),
                                                             _mm256_or_pd(xmm0.r2,xmm1.r2),
                                                             _mm256_or_pd(xmm0.r3,xmm1.r3));
    }

    /**
     Evaluate the andnot operator between two registers
     specialisation double,cyme::avx,1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_andnot<double,cyme::avx,1> (simd_trait<double,cyme::avx,1>::register_type xmm0){
        __m256d mask = _mm256_castsi256_pd(_mm256_set1_epi64x(0xffffffffffffffff));
        return _mm256_andnot_pd(xmm0,mask);
    }

    /**
     Evaluate the andnot operator between two registers
     specialisation double,cyme::avx,2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_andnot<double,cyme::avx,2> (simd_trait<double,cyme::avx,2>::register_type xmm0){
        __m256d mask = _mm256_castsi256_pd(_mm256_set1_epi64x(0xffffffffffffffff));
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_andnot_pd(xmm0.r0,mask),
                                                             _mm256_andnot_pd(xmm0.r1,mask));
    }

    /**
     Evaluate the andnot operator between two registers
     specialisation double,cyme::avx,4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_andnot<double,cyme::avx,4> (simd_trait<double,cyme::avx,4>::register_type xmm0){
        __m256d mask = _mm256_castsi256_pd(_mm256_set1_epi64x(0xffffffffffffffff));
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_andnot_pd(xmm0.r0,mask),
                                                             _mm256_andnot_pd(xmm0.r1,mask),
                                                             _mm256_andnot_pd(xmm0.r2,mask),
                                                             _mm256_andnot_pd(xmm0.r3,mask));
    }


#ifdef __INTEL_COMPILER
    /**
      Compute the exponential value of e raised to the power of packed double-precision (64-bit)
     floating-point elements in xmm0, and store the results in dst.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_exp<double,cyme::avx,1>(simd_trait<double,cyme::avx,1>::register_type xmm0){
        return __svml_exp4(xmm0);
    }

    /**
      Compute the exponential value of e raised to the power of packed double-precision (64-bit)
     floating-point elements in xmm0, and store the results in dst.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_exp<double,cyme::avx,2>(simd_trait<double,cyme::avx,2>::register_type xmm0){
        return simd_trait<double,cyme::avx,2>::register_type(__svml_exp4(xmm0.r0),
                                                             __svml_exp4(xmm0.r1));
    }

    /**
      Compute the exponential value of e raised to the power of packed double-precision (64-bit)
     floating-point elements in xmm0, and store the results in dst.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_exp<double,cyme::avx,4>(simd_trait<double,cyme::avx,4>::register_type xmm0){
        return simd_trait<double,cyme::avx,4>::register_type(__svml_exp4(xmm0.r0),
                                                             __svml_exp4(xmm0.r1),
                                                             __svml_exp4(xmm0.r2),
                                                             __svml_exp4(xmm0.r3));
    }

    /**
      Compute the natural logarithm of packed double-precision (64-bit) floating-point elements in xmm0,
     and store the results in dst.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_log<double,cyme::avx,1>(simd_trait<double,cyme::avx,1>::register_type xmm0){
        return __svml_log4(xmm0);
    }

    /**
      Compute the natural logarithm of packed double-precision (64-bit) floating-point elements in xmm0,
     and store the results in dst.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_log<double,cyme::avx,2>(simd_trait<double,cyme::avx,2>::register_type xmm0){
        return simd_trait<double,cyme::avx,2>::register_type(__svml_log4(xmm0.r0),
                                                             __svml_log4(xmm0.r1));
    }

    /**
      Compute the natural logarithm of packed double-precision (64-bit) floating-point elements in xmm0,
     and store the results in dst.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_log<double,cyme::avx,4>(simd_trait<double,cyme::avx,4>::register_type xmm0){
        return simd_trait<double,cyme::avx,4>::register_type(__svml_log4(xmm0.r0),
                                                             __svml_log4(xmm0.r1),
                                                             __svml_log4(xmm0.r2),
                                                             __svml_log4(xmm0.r3));
    }
#endif

#ifdef __FMA__
    /**
      Multiply packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
      add the intermediate result to packed elements in xmm2, and store the results in dst.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_fma<double,cyme::avx,1>(simd_trait<double,cyme::avx,1>::register_type xmm0,
                                simd_trait<double,cyme::avx,1>::register_type xmm1,
                                simd_trait<double,cyme::avx,1>::register_type xmm2){
        return _mm256_fmadd_pd(xmm0, xmm1, xmm2);
    }

    /**
      Multiply packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
      add the intermediate result to packed elements in xmm2, and store the results in dst.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_fma<double,cyme::avx,2>(simd_trait<double,cyme::avx,2>::register_type xmm0,
                                simd_trait<double,cyme::avx,2>::register_type xmm1,
                                simd_trait<double,cyme::avx,2>::register_type xmm2){
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_fmadd_pd(xmm0.r0, xmm1.r0, xmm2.r0),
                                                             _mm256_fmadd_pd(xmm0.r1, xmm1.r1, xmm2.r1));
    }

    /**
      Multiply packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
      add the intermediate result to packed elements in xmm2, and store the results in dst.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_fma<double,cyme::avx,4>(simd_trait<double,cyme::avx,4>::register_type xmm0,
                                  simd_trait<double,cyme::avx,4>::register_type xmm1,
                                  simd_trait<double,cyme::avx,4>::register_type xmm2){
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_fmadd_pd(xmm0.r0, xmm1.r0, xmm2.r0),
                                                             _mm256_fmadd_pd(xmm0.r1, xmm1.r1, xmm2.r1),
                                                             _mm256_fmadd_pd(xmm0.r2, xmm1.r2, xmm2.r2),
                                                             _mm256_fmadd_pd(xmm0.r3, xmm1.r3, xmm2.r3));
    }

    /**
      Multiply packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
     add the negated intermediate result to packed elements in xmm2, and store the results in dst.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_nfma<double,cyme::avx,1>(simd_trait<double,cyme::avx,1>::register_type xmm0,
                                 simd_trait<double,cyme::avx,1>::register_type xmm1,
                                 simd_trait<double,cyme::avx,1>::register_type xmm2){
        return _mm256_fnmadd_pd(xmm0, xmm1, xmm2);
    }

    /**
      Multiply packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
     add the negated intermediate result to packed elements in xmm2, and store the results in dst.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_nfma<double,cyme::avx,2>(simd_trait<double,cyme::avx,2>::register_type xmm0,
                                 simd_trait<double,cyme::avx,2>::register_type xmm1,
                                 simd_trait<double,cyme::avx,2>::register_type xmm2){
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_fnmadd_pd(xmm0.r0, xmm1.r0, xmm2.r0),
                                                             _mm256_fnmadd_pd(xmm0.r1, xmm1.r1, xmm2.r1));
    }

    /**
      Multiply packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
     add the negated intermediate result to packed elements in xmm2, and store the results in dst.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_nfma<double,cyme::avx,4>(simd_trait<double,cyme::avx,4>::register_type xmm0,
                                  simd_trait<double,cyme::avx,4>::register_type xmm1,
                                  simd_trait<double,cyme::avx,4>::register_type xmm2){
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_fnmadd_pd(xmm0.r0, xmm1.r0, xmm2.r0),
                                                             _mm256_fnmadd_pd(xmm0.r1, xmm1.r1, xmm2.r1),
                                                             _mm256_fnmadd_pd(xmm0.r2, xmm1.r2, xmm2.r2),
                                                             _mm256_fnmadd_pd(xmm0.r3, xmm1.r3, xmm2.r3));
    }

    /**
      Multiply packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
     subtract packed elements in xmm2 from the intermediate result, and store the results in dst.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline  simd_trait<double,cyme::avx,1>::register_type
    _mm_fms<double,cyme::avx,1>(simd_trait<double,cyme::avx,1>::register_type xmm0,
                                simd_trait<double,cyme::avx,1>::register_type xmm1,
                                simd_trait<double,cyme::avx,1>::register_type xmm2){
        return _mm256_fmsub_pd(xmm0, xmm1, xmm2);
    }

    /**
      Multiply packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
     subtract packed elements in xmm2 from the intermediate result, and store the results in dst.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,2>::register_type
    _mm_fms<double,cyme::avx,2>(simd_trait<double,cyme::avx,2>::register_type xmm0,
                                simd_trait<double,cyme::avx,2>::register_type xmm1,
                                simd_trait<double,cyme::avx,2>::register_type xmm2){
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_fmsub_pd(xmm0.r0, xmm1.r0, xmm2.r0),
                                                             _mm256_fmsub_pd(xmm0.r1, xmm1.r1, xmm2.r1));
    }

    /**
      Multiply packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
     subtract packed elements in xmm2 from the intermediate result, and store the results in dst.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,4>::register_type
    _mm_fms<double,cyme::avx,4>(simd_trait<double,cyme::avx,4>::register_type xmm0,
                                simd_trait<double,cyme::avx,4>::register_type xmm1,
                                simd_trait<double,cyme::avx,4>::register_type xmm2){
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_fmsub_pd(xmm0.r0, xmm1.r0, xmm2.r0),
                                                             _mm256_fmsub_pd(xmm0.r1, xmm1.r1, xmm2.r1),
                                                             _mm256_fmsub_pd(xmm0.r2, xmm1.r2, xmm2.r2),
                                                             _mm256_fmsub_pd(xmm0.r3, xmm1.r3, xmm2.r3));
    }

    /**
      Multiply packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
      subtract packed elements in xmm2 from the negated intermediate result, and store the results in dst.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<double,cyme::avx,1>::register_type
    _mm_nfms<double,cyme::avx,1>(simd_trait<double,cyme::avx,1>::register_type xmm0,
                                 simd_trait<double,cyme::avx,1>::register_type xmm1,
                                 simd_trait<double,cyme::avx,1>::register_type xmm2){
        return _mm256_fnmsub_pd(xmm0, xmm1, xmm2);
    }

    /**
      Multiply packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
      subtract packed elements in xmm2 from the negated intermediate result, and store the results in dst.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline  simd_trait<double,cyme::avx,2>::register_type
    _mm_nfms<double,cyme::avx,2>(simd_trait<double,cyme::avx,2>::register_type xmm0,
                                 simd_trait<double,cyme::avx,2>::register_type xmm1,
                                 simd_trait<double,cyme::avx,2>::register_type xmm2){
        return simd_trait<double,cyme::avx,2>::register_type(_mm256_fnmsub_pd(xmm0.r0, xmm1.r0, xmm2.r0),
                                                             _mm256_fnmsub_pd(xmm0.r1, xmm1.r1, xmm2.r1));
    }

    /**
      Multiply packed double-precision (64-bit) floating-point elements in xmm0 and xmm1,
      subtract packed elements in xmm2 from the negated intermediate result, and store the results in dst.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline  simd_trait<double,cyme::avx,4>::register_type
    _mm_nfms<double,cyme::avx,4>(simd_trait<double,cyme::avx,4>::register_type xmm0,
                                 simd_trait<double,cyme::avx,4>::register_type xmm1,
                                 simd_trait<double,cyme::avx,4>::register_type xmm2){
        return simd_trait<double,cyme::avx,4>::register_type(_mm256_fnmsub_pd(xmm0.r0, xmm1.r0, xmm2.r0),
                                                             _mm256_fnmsub_pd(xmm0.r1, xmm1.r1, xmm2.r1),
                                                             _mm256_fnmsub_pd(xmm0.r2, xmm1.r2, xmm2.r2),
                                                             _mm256_fnmsub_pd(xmm0.r3, xmm1.r3, xmm2.r3));
    }
#endif //end FMA

    /**
      Broadcast a single-precision (32-bit) floating-point element from cyme to all elements of dst.
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    simd_trait<float,cyme::avx,1>::register_type
    forceinline _mm_load1<float,cyme::avx,1>(const simd_trait<float,cyme::avx,1>::value_type& a){
        return _mm256_set1_ps(a);
    }

    /**
      Broadcast a single-precision (32-bit) floating-point element from cyme to all elements of dst.
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_load1<float,cyme::avx,2>(const simd_trait<float,cyme::avx,2>::value_type& a){
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_set1_ps(a),_mm256_set1_ps(a));
    }

    /**
      Broadcast a single-precision (32-bit) floating-point element from cyme to all elements of dst.
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_load1<float,cyme::avx,4>(const simd_trait<float,cyme::avx,4>::value_type& a){
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_set1_ps(a),_mm256_set1_ps(a),
                                                            _mm256_set1_ps(a),_mm256_set1_ps(a));
    }

    /**
      Load 256-bits (composed of 8 packed single-precision (32-bit) floating-point elements) from cyme into dst.
     mem_addr must be aligned on a 32-byte boundary or a general-protection exception will be generated.
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_load<float,cyme::avx,1>(simd_trait<float,cyme::avx,1>::const_pointer a){
        return _mm256_load_ps(a);
    }

    /**
      Load 256-bits (composed of 8 packed single-precision (32-bit) floating-point elements) from cyme into dst.
     mem_addr must be aligned on a 32-byte boundary or a general-protection exception will be generated.
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_load<float,cyme::avx,2>(simd_trait<float,cyme::avx,2>::const_pointer a){
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_load_ps(a),_mm256_load_ps(a+8));
    }

    /**
      Load 256-bits (composed of 8 packed single-precision (32-bit) floating-point elements) from cyme into dst.
     mem_addr must be aligned on a 32-byte boundary or a general-protection exception will be generated.
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_load<float,cyme::avx,4>(simd_trait<float,cyme::avx,4>::const_pointer a){
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_load_ps(a),_mm256_load_ps(a+8),
                                                            _mm256_load_ps(a+16),_mm256_load_ps(a+24));
    }

     /**
       Load 256-bits (composed of 4 packed double-precision (64-bit) floating-point elements) from cyme into dst.
       using gather operations specialisation double,cyme::avx, 1 regs
     */
     template<>
     forceinline simd_trait<float,cyme::avx,1>::register_type
     _mm_gather<float,cyme::avx,1>(const float* src, const int *ind, const int  __attribute__((unused)) range){
        return _mm256_setr_ps(src[ind[0]],src[ind[1]],src[ind[2]],src[ind[3]],
                             src[ind[4]],src[ind[5]],src[ind[6]],src[ind[7]]);
     }

     /**
       Load 256-bits (composed of 8 packed double-precision (64-bit) floating-point elements) from cyme into dst.
       using gather operations specialisation double,cyme::avx, 2 regs
     */
     template<>
     forceinline simd_trait<float,cyme::avx,2>::register_type
     _mm_gather<float,cyme::avx,2>(const float* src, const int *ind, const int  __attribute__((unused)) range){
        return simd_trait<float,cyme::avx,2>::register_type(
            _mm256_setr_ps(src[ind[0]],src[ind[1]],src[ind[2]],src[ind[3]],
                          src[ind[4]],src[ind[5]],src[ind[6]],src[ind[7]]),
            _mm256_setr_ps(src[ind[8]],src[ind[9]],src[ind[10]],src[ind[11]],
                          src[ind[12]],src[ind[13]],src[ind[14]],src[ind[15]]));
     }

     /**
       Load 256-bits (composed of 16 packed double-precision (64-bit) floating-point elements) from cyme into dst.
       using gather operations specialisation double,cyme::avx, 4 regs
     */
     template<>
     forceinline simd_trait<float,cyme::avx,4>::register_type
     _mm_gather<float,cyme::avx,4>(const float* src, const int *ind, const int  __attribute__((unused)) range){
        return simd_trait<float,cyme::avx,4>::register_type(
            _mm256_setr_ps(src[ind[0]],src[ind[1]],src[ind[2]],src[ind[3]],
                          src[ind[4]],src[ind[5]],src[ind[6]],src[ind[7]]),
            _mm256_setr_ps(src[ind[8]],src[ind[9]],src[ind[10]],src[ind[11]],
                          src[ind[12]],src[ind[13]],src[ind[14]],src[ind[15]]),
            _mm256_setr_ps(src[ind[16]],src[ind[17]],src[ind[18]],src[ind[19]],
                          src[ind[20]],src[ind[21]],src[ind[22]],src[ind[23]]),
            _mm256_setr_ps(src[ind[24]],src[ind[25]],src[ind[26]],src[ind[27]],
                          src[ind[28]],src[ind[29]],src[ind[30]],src[ind[31]]));
     }

    /**
      Store 256-bits (composed of 8 packed single-precision (32-bit) floating-point elements) from a into cyme.
     mem_addr must be aligned on a 32-byte boundary or a general-protection exception will be generated.
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline void _mm_store<float,cyme::avx,1>(simd_trait<float,cyme::avx,1>::register_type xmm0,
                                                  simd_trait<float,cyme::avx,1>::pointer a){
        _mm256_store_ps(a,xmm0);
    }

    /**
      Store 256-bits (composed of 8 packed single-precision (32-bit) floating-point elements) from a into cyme.
     mem_addr must be aligned on a 32-byte boundary or a general-protection exception will be generated.
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline void _mm_store<float,cyme::avx,2>(simd_trait<float,cyme::avx,2>::register_type xmm0,
                                                  simd_trait<float,cyme::avx,2>::pointer a){
        _mm256_store_ps(a,xmm0.r0);
        _mm256_store_ps(a+8,xmm0.r1);
    }

    /**
      Store 256-bits (composed of 8 packed single-precision (32-bit) floating-point elements) from a into cyme.
     mem_addr must be aligned on a 32-byte boundary or a general-protection exception will be generated.
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline void _mm_store<float,cyme::avx,4>(simd_trait<float,cyme::avx,4>::register_type xmm0,
                                                  simd_trait<float,cyme::avx,4>::pointer a){
        _mm256_store_ps(a,xmm0.r0);
        _mm256_store_ps(a+8,xmm0.r1);
        _mm256_store_ps(a+16,xmm0.r2);
        _mm256_store_ps(a+24,xmm0.r3);
    }

    /**
      Multiply packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
     and store the results in dst.
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_mul<float,cyme::avx,1>(simd_trait<float,cyme::avx,1>::register_type xmm0,
                                 simd_trait<float,cyme::avx,1>::register_type xmm1){
        return _mm256_mul_ps(xmm0, xmm1);
    }

    /**
      Multiply packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
     and store the results in dst.
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_mul<float,cyme::avx,2>(simd_trait<float,cyme::avx,2>::register_type xmm0,
                                 simd_trait<float,cyme::avx,2>::register_type xmm1){
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_mul_ps(xmm0.r0, xmm1.r0),
                                                            _mm256_mul_ps(xmm0.r1, xmm1.r1));
    }

    /**
      Multiply packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
     and store the results in dst.
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_mul<float,cyme::avx,4>(simd_trait<float,cyme::avx,4>::register_type xmm0,
                                 simd_trait<float,cyme::avx,4>::register_type xmm1){
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_mul_ps(xmm0.r0, xmm1.r0),
                                                            _mm256_mul_ps(xmm0.r1, xmm1.r1),
                                                            _mm256_mul_ps(xmm0.r2, xmm1.r2),
                                                            _mm256_mul_ps(xmm0.r3, xmm1.r3));
    }

    /**
      Multiply packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
      and store the results in dst.
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_div<float,cyme::avx,1>(simd_trait<float,cyme::avx,1>::register_type xmm0,
                               simd_trait<float,cyme::avx,1>::register_type xmm1){
        return _mm256_div_ps(xmm0, xmm1);
    }

    /**
      Multiply packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
      and store the results in dst.
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_div<float,cyme::avx,2>(simd_trait<float,cyme::avx,2>::register_type xmm0,
                               simd_trait<float,cyme::avx,2>::register_type xmm1){
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_div_ps(xmm0.r0, xmm1.r0),
                                                            _mm256_div_ps(xmm0.r1, xmm1.r1));
    }

    /**
      Multiply packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
      and store the results in dst.
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_div<float,cyme::avx,4>(simd_trait<float,cyme::avx,4>::register_type xmm0,
                                 simd_trait<float,cyme::avx,4>::register_type xmm1){
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_div_ps(xmm0.r0, xmm1.r0),
                                                            _mm256_div_ps(xmm0.r1, xmm1.r1),
                                                            _mm256_div_ps(xmm0.r2, xmm1.r2),
                                                            _mm256_div_ps(xmm0.r3, xmm1.r3));
    }

    /**
      Add packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
      and store the results in dst.
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_add<float,cyme::avx,1>(simd_trait<float,cyme::avx,1>::register_type xmm0,
                               simd_trait<float,cyme::avx,1>::register_type xmm1){
        return _mm256_add_ps(xmm0, xmm1);
    }

    /**
      Add packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
      and store the results in dst.
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_add<float,cyme::avx,2>(simd_trait<float,cyme::avx,2>::register_type xmm0,
                               simd_trait<float,cyme::avx,2>::register_type xmm1){
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_add_ps(xmm0.r0, xmm1.r0),
                                                            _mm256_add_ps(xmm0.r1, xmm1.r1));
    }

    /**
      Add packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
      and store the results in dst.
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_add<float,cyme::avx,4>(simd_trait<float,cyme::avx,4>::register_type xmm0,
                               simd_trait<float,cyme::avx,4>::register_type xmm1){
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_add_ps(xmm0.r0, xmm1.r0),
                                                            _mm256_add_ps(xmm0.r1, xmm1.r1),
                                                            _mm256_add_ps(xmm0.r2, xmm1.r2),
                                                            _mm256_add_ps(xmm0.r3, xmm1.r3));
    }

    /**
      Subtract packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
      and store the results in dst.
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_sub<float,cyme::avx,1>(simd_trait<float,cyme::avx,1>::register_type xmm0,
                               simd_trait<float,cyme::avx,1>::register_type xmm1){
        return _mm256_sub_ps(xmm0, xmm1);
    }

    /**
      Subtract packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
      and store the results in dst.
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_sub<float,cyme::avx,2>(simd_trait<float,cyme::avx,2>::register_type xmm0,
                               simd_trait<float,cyme::avx,2>::register_type xmm1){
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_sub_ps(xmm0.r0, xmm1.r0),
                                                            _mm256_sub_ps(xmm0.r1, xmm1.r1));
    }

    /**
      Subtract packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
      and store the results in dst.
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_sub<float,cyme::avx,4>(simd_trait<float,cyme::avx,4>::register_type xmm0,
                               simd_trait<float,cyme::avx,4>::register_type xmm1){
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_sub_ps(xmm0.r0, xmm1.r0),
                                                            _mm256_sub_ps(xmm0.r1, xmm1.r1),
                                                            _mm256_sub_ps(xmm0.r2, xmm1.r2),
                                                            _mm256_sub_ps(xmm0.r3, xmm1.r3));
    }

    /**
      Compute the approximate reciprocal of packed single-precision (32-bit) floating-point elements in xmm0,
      and store the results in dst. The maximum relative error for this approximation is less than 1.5*2^-12.
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_rec<float,cyme::avx,1>(simd_trait<float,cyme::avx,1>::register_type xmm0){
        return _mm256_rcp_ps(xmm0);
    }

    /**
      Compute the approximate reciprocal of packed single-precision (32-bit) floating-point elements in xmm0,
      and store the results in dst. The maximum relative error for this approximation is less than 1.5*2^-12.
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_rec<float,cyme::avx,2>( simd_trait<float,cyme::avx,2>::register_type xmm0){
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_rcp_ps(xmm0.r0),
                                                            _mm256_rcp_ps(xmm0.r1));
    }

    /**
      Compute the approximate reciprocal of packed single-precision (32-bit) floating-point elements in xmm0,
      and store the results in dst. The maximum relative error for this approximation is less than 1.5*2^-12.
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_rec<float,cyme::avx,4>( simd_trait<float,cyme::avx,4>::register_type xmm0){
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_rcp_ps(xmm0.r0),
                                                            _mm256_rcp_ps(xmm0.r1),
                                                            _mm256_rcp_ps(xmm0.r2),
                                                            _mm256_rcp_ps(xmm0.r3));
    }

    /**
      Negate packed single-precision (32-bit) floating-point elements in xmm0 to packed double-precision (64-bit)
      floating-point elements, and store the results in dst.
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_neg<float,cyme::avx,1>(simd_trait<float,cyme::avx,1>::register_type xmm0){
        simd_trait<float,cyme::avx,1>::register_type mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x80000000));
        return _mm256_xor_ps(xmm0, mask);
    }

    /**
      Negate packed single-precision (32-bit) floating-point elements in xmm0 to packed double-precision (64-bit)
      floating-point elements, and store the results in dst.
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline  simd_trait<float,cyme::avx,2>::register_type
    _mm_neg<float,cyme::avx,2>(simd_trait<float,cyme::avx,2>::register_type xmm0){
        simd_trait<float,cyme::avx,1>::register_type mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x80000000));
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_xor_ps(xmm0.r0, mask),
                                                            _mm256_xor_ps(xmm0.r1, mask));
    }

    /**
      Negate packed single-precision (32-bit) floating-point elements in xmm0 to packed double-precision (64-bit)
      floating-point elements, and store the results in dst.
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_neg<float,cyme::avx,4>(simd_trait<float,cyme::avx,4>::register_type xmm0){
        simd_trait<float,cyme::avx,1>::register_type mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x80000000));
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_xor_ps(xmm0.r0, mask),
                                                            _mm256_xor_ps(xmm0.r1, mask),
                                                            _mm256_xor_ps(xmm0.r2, mask),
                                                            _mm256_xor_ps(xmm0.r3, mask));
    }

    /**
      Round the packed single-precision (32-bit) floating-point elements in xmm0 down to an integer value,
     and store the results as packed single-precision integer-point elements in dst.
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<int,cyme::avx,1>::register_type
    _mm_floor<float,cyme::avx,1>(simd_trait<float,cyme::avx,1>::register_type xmm0){
        return _mm256_cvttps_epi32(_mm256_floor_ps(xmm0));
    }

    /**
      Round the packed single-precision (32-bit) floating-point elements in xmm0 down to an integer value,
     and store the results as packed single-precision integer-point elements in dst.
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<int,cyme::avx,2>::register_type
    _mm_floor<float,cyme::avx,2>( simd_trait<float,cyme::avx,2>::register_type xmm0){
        return simd_trait<int,cyme::avx,2>::register_type(_mm256_cvttps_epi32(_mm256_floor_ps(xmm0.r0)),
                                                          _mm256_cvttps_epi32(_mm256_floor_ps(xmm0.r1)));
    }

    /**
      Round the packed single-precision (32-bit) floating-point elements in xmm0 down to an integer value,
     and store the results as packed single-precision integer-point elements in dst.
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<int,cyme::avx,4>::register_type
    _mm_floor<float,cyme::avx,4>( simd_trait<float,cyme::avx,4>::register_type xmm0){
        return simd_trait<int,cyme::avx,4>::register_type(_mm256_cvttps_epi32(_mm256_floor_ps(xmm0.r0)),
                                                          _mm256_cvttps_epi32(_mm256_floor_ps(xmm0.r1)),
                                                          _mm256_cvttps_epi32(_mm256_floor_ps(xmm0.r2)),
                                                          _mm256_cvttps_epi32(_mm256_floor_ps(xmm0.r3)));
    }

    /**
      Convert packed 32-bit integers in xmm0 to packed single-precision (32-bit) floating-point elements,
     and store the results in dst.
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_cast<float,cyme::avx,1>(simd_trait<int,cyme::avx,1>::register_type xmm0){
        return  _mm256_cvtepi32_ps(xmm0);
    }

    /**
      Convert packed 32-bit integers in xmm0 to packed single-precision (32-bit) floating-point elements,
     and store the results in dst.
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_cast<float,cyme::avx,2>(simd_trait<int,cyme::avx,2>::register_type xmm0){
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_cvtepi32_ps(xmm0.r0),
                                                            _mm256_cvtepi32_ps(xmm0.r1));
    }

    /**
      Convert packed 32-bit integers in xmm0 to packed single-precision (32-bit) floating-point elements,
     and store the results in dst.
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_cast<float,cyme::avx,4>(simd_trait<int,cyme::avx,4>::register_type xmm0){
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_cvtepi32_ps(xmm0.r0),
                                                            _mm256_cvtepi32_ps(xmm0.r1),
                                                            _mm256_cvtepi32_ps(xmm0.r2),
                                                            _mm256_cvtepi32_ps(xmm0.r3));
    }

    /**
      Compute 2^k packed integer (32-bit) elements in xmm0 to packed single-precision (32-bit)
      floating-point elements, and store the results in dst.
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_twok<float,cyme::avx,1>(simd_trait<int,cyme::avx,1>::register_type xmm0){
        // ((int + 127) << 23) <=> int to float
        /* AVX2, return _mm256_castsi256_ps(_mm256_slli_epi32(_mm256_add_epi32(xmm0, _mm256_set1_epi32(127)), 23)); */
        xmm0 = _mm256_insertf128_si256(xmm0, _mm_slli_epi32(_mm_add_epi32(_mm256_extractf128_si256(xmm0,0),
                                                            _mm_set1_epi32(127)), 23),0);
        xmm0 = _mm256_insertf128_si256(xmm0, _mm_slli_epi32(_mm_add_epi32(_mm256_extractf128_si256(xmm0,1),
                                                            _mm_set1_epi32(127)), 23),1);
        return  _mm256_castsi256_ps(xmm0);
    }


    /**
      Compute 2^k packed integer (32-bit) elements in xmm0 to packed single-precision (32-bit)
      floating-point elements, and store the results in dst.
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_twok<float,cyme::avx,2>(simd_trait<int,cyme::avx,2>::register_type xmm0){
        xmm0.r0 = _mm256_insertf128_si256(xmm0.r0, _mm_slli_epi32(_mm_add_epi32(_mm256_extractf128_si256(xmm0.r0,0),
                                                                  _mm_set1_epi32(127)), 23),0);
        xmm0.r1 = _mm256_insertf128_si256(xmm0.r1, _mm_slli_epi32(_mm_add_epi32(_mm256_extractf128_si256(xmm0.r1,0),
                                                                  _mm_set1_epi32(127)), 23),0);
        xmm0.r0 = _mm256_insertf128_si256(xmm0.r0, _mm_slli_epi32(_mm_add_epi32(_mm256_extractf128_si256(xmm0.r0,1),
                                                                  _mm_set1_epi32(127)), 23),1);
        xmm0.r1 = _mm256_insertf128_si256(xmm0.r1, _mm_slli_epi32(_mm_add_epi32(_mm256_extractf128_si256(xmm0.r1,1),
                                                                  _mm_set1_epi32(127)), 23),1);
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_castsi256_ps(xmm0.r0),
                                                            _mm256_castsi256_ps(xmm0.r1));
    }

    /**
      Compute 2^k packed integer (32-bit) elements in xmm0 to packed single-precision (32-bit)
      floating-point elements, and store the results in dst.
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_twok<float,cyme::avx,4>(simd_trait<int,cyme::avx,4>::register_type xmm0){
        xmm0.r0 = _mm256_insertf128_si256(xmm0.r0, _mm_slli_epi32(_mm_add_epi32(_mm256_extractf128_si256(xmm0.r0,0),
                                                                  _mm_set1_epi32(127)), 23),0);
        xmm0.r1 = _mm256_insertf128_si256(xmm0.r1, _mm_slli_epi32(_mm_add_epi32(_mm256_extractf128_si256(xmm0.r1,0),
                                                                  _mm_set1_epi32(127)), 23),0);
        xmm0.r2 = _mm256_insertf128_si256(xmm0.r2, _mm_slli_epi32(_mm_add_epi32(_mm256_extractf128_si256(xmm0.r2,0),
                                                                  _mm_set1_epi32(127)), 23),0);
        xmm0.r3 = _mm256_insertf128_si256(xmm0.r3, _mm_slli_epi32(_mm_add_epi32(_mm256_extractf128_si256(xmm0.r3,0),
                                                                  _mm_set1_epi32(127)), 23),0);
        xmm0.r0 = _mm256_insertf128_si256(xmm0.r0, _mm_slli_epi32(_mm_add_epi32(_mm256_extractf128_si256(xmm0.r0,1),
                                                                  _mm_set1_epi32(127)), 23),1);
        xmm0.r1 = _mm256_insertf128_si256(xmm0.r1, _mm_slli_epi32(_mm_add_epi32(_mm256_extractf128_si256(xmm0.r1,1),
                                                                  _mm_set1_epi32(127)), 23),1);
        xmm0.r2 = _mm256_insertf128_si256(xmm0.r2, _mm_slli_epi32(_mm_add_epi32(_mm256_extractf128_si256(xmm0.r2,1),
                                                                  _mm_set1_epi32(127)), 23),1);
        xmm0.r3 = _mm256_insertf128_si256(xmm0.r3, _mm_slli_epi32(_mm_add_epi32(_mm256_extractf128_si256(xmm0.r3,1),
                                                                  _mm_set1_epi32(127)), 23),1);
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_castsi256_ps(xmm0.r0),
                                                            _mm256_castsi256_ps(xmm0.r1),
                                                            _mm256_castsi256_ps(xmm0.r2),
                                                            _mm256_castsi256_ps(xmm0.r3));
    }

    /**
      Extract the exponent of floating-point exponent (64-bit) elements and store the results in dst.
     arithmetic are very badly supported with AVX, I am presently glue I so do the compuation in SSE;
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_ge<float,cyme::avx,1>(simd_trait<float,cyme::avx,1>::register_type xmm0){
        __m128 lo = _mm256_extractf128_ps(xmm0,0);
        __m128 hi = _mm256_extractf128_ps(xmm0,1);
        hi = _mm_ge<float,cyme::sse,1>(hi);
        lo = _mm_ge<float,cyme::sse,1>(lo);
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wuninitialized"
        __m256 r(_mm256_insertf128_ps(r,lo,0));
        #pragma GCC diagnostic pop
        r =  _mm256_insertf128_ps(r,hi,1);
        return r;
    }

    /**
      Extract the exponent of floating-point exponent (64-bit) elements and store the results in dst.
     arithmetic are very badly supported with AVX, I am presently glue I so do the compuation in SSE;
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_ge<float,cyme::avx,2>(simd_trait<float,cyme::avx,2>::register_type xmm0){
        __m128 lo0 = _mm256_extractf128_ps(xmm0.r0,0);
        __m128 hi0 = _mm256_extractf128_ps(xmm0.r0,1);
        __m128 lo1 = _mm256_extractf128_ps(xmm0.r1,0);
        __m128 hi1 = _mm256_extractf128_ps(xmm0.r1,1);

        hi0 = _mm_ge<float,cyme::sse,1>(hi0);
        lo0 = _mm_ge<float,cyme::sse,1>(lo0);
        hi1 = _mm_ge<float,cyme::sse,1>(hi1);
        lo1 = _mm_ge<float,cyme::sse,1>(lo1);

        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wuninitialized"
        __m256 r0(_mm256_insertf128_ps(r0,lo0,0));
        __m256 r1(_mm256_insertf128_ps(r1,lo1,0));
        #pragma GCC diagnostic pop

        r0 =  _mm256_insertf128_ps(r0,hi0,1);
        r1 =  _mm256_insertf128_ps(r1,hi1,1);

        return simd_trait<float,cyme::avx,2>::register_type(r0,r1);
    }

    /**
      Extract the exponent of floating-point exponent (64-bit) elements and store the results in dst.
     arithmetic are very badly supported with AVX, I am presently glue I so do the compuation in SSE;
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_ge<float,cyme::avx,4>(simd_trait<float,cyme::avx,4>::register_type xmm0){
        __m128 lo0 = _mm256_extractf128_ps(xmm0.r0,0);
        __m128 hi0 = _mm256_extractf128_ps(xmm0.r0,1);
        __m128 lo1 = _mm256_extractf128_ps(xmm0.r1,0);
        __m128 hi1 = _mm256_extractf128_ps(xmm0.r1,1);
        __m128 lo2 = _mm256_extractf128_ps(xmm0.r2,0);
        __m128 hi2 = _mm256_extractf128_ps(xmm0.r2,1);
        __m128 lo3 = _mm256_extractf128_ps(xmm0.r3,0);
        __m128 hi3 = _mm256_extractf128_ps(xmm0.r3,1);

        hi0 = _mm_ge<float,cyme::sse,1>(hi0);
        lo0 = _mm_ge<float,cyme::sse,1>(lo0);
        hi1 = _mm_ge<float,cyme::sse,1>(hi1);
        lo1 = _mm_ge<float,cyme::sse,1>(lo1);
        hi2 = _mm_ge<float,cyme::sse,1>(hi2);
        lo2 = _mm_ge<float,cyme::sse,1>(lo2);
        hi3 = _mm_ge<float,cyme::sse,1>(hi3);
        lo3 = _mm_ge<float,cyme::sse,1>(lo3);

        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wuninitialized"
        __m256 r0(_mm256_insertf128_ps(r0,lo0,0));
        __m256 r1(_mm256_insertf128_ps(r1,lo1,0));
        __m256 r2(_mm256_insertf128_ps(r1,lo2,0));
        __m256 r3(_mm256_insertf128_ps(r1,lo3,0));
        #pragma GCC diagnostic pop

        r0 =  _mm256_insertf128_ps(r0,hi0,1);
        r1 =  _mm256_insertf128_ps(r1,hi1,1);
        r2 =  _mm256_insertf128_ps(r2,hi2,1);
        r3 =  _mm256_insertf128_ps(r3,hi3,1);

        return simd_trait<float,cyme::avx,4>::register_type(r0,r1,r2,r3);
    }

    /**
      Extract the fraction of floating-point exponent (64-bit) elements and store the results in dst.
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_gf<float,cyme::avx,1>(simd_trait<float,cyme::avx,1>::register_type xmm0){
        __m256i TMP =  _mm256_castps_si256(xmm0);
        __m128i tmp0 =  _mm256_extractf128_si256(TMP,0);
        tmp0 = _mm_and_si128(tmp0,_mm_set1_epi32(0x7fffff));
        tmp0 = _mm_add_epi32(tmp0,_mm_set1_epi32(0x3f800000));
        __m128i tmp1 =  _mm256_extractf128_si256(TMP,1);
        tmp1 = _mm_and_si128(tmp1,_mm_set1_epi32(0x7fffff));
        tmp1 = _mm_add_epi32(tmp1,_mm_set1_epi32(0x3f800000));
        TMP =   _mm256_insertf128_si256(TMP, tmp0,0);
        TMP =   _mm256_insertf128_si256(TMP, tmp1,1);
        return _mm256_castsi256_ps(TMP);
    }

    /**
      Extract the fraction of floating-point exponent (64-bit) elements and store the results in dst.
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_gf<float,cyme::avx,2>(simd_trait<float,cyme::avx,2>::register_type xmm0){
        __m256i TMP0 =  _mm256_castps_si256(xmm0.r0);
        __m256i TMP1 =  _mm256_castps_si256(xmm0.r1);

        __m128i tmp0 =  _mm256_extractf128_si256(TMP0,0);
        __m128i tmp1 =  _mm256_extractf128_si256(TMP1,0);

        tmp0 = _mm_and_si128(tmp0,_mm_set1_epi32(0x7fffff));
        tmp1 = _mm_and_si128(tmp1,_mm_set1_epi32(0x7fffff));

        tmp0 = _mm_add_epi32(tmp0,_mm_set1_epi32(0x3f800000));
        tmp1 = _mm_add_epi32(tmp1,_mm_set1_epi32(0x3f800000));

        __m128i tmp01 =  _mm256_extractf128_si256(TMP0,1);
        __m128i tmp11 =  _mm256_extractf128_si256(TMP1,1);

        tmp01 = _mm_and_si128(tmp01,_mm_set1_epi32(0x7fffff));
        tmp11 = _mm_and_si128(tmp11,_mm_set1_epi32(0x7fffff));

        tmp01 = _mm_add_epi32(tmp01,_mm_set1_epi32(0x3f800000));
        tmp11 = _mm_add_epi32(tmp11,_mm_set1_epi32(0x3f800000));

        TMP0 =   _mm256_insertf128_si256(TMP0, tmp0,0);
        TMP0 =   _mm256_insertf128_si256(TMP0, tmp01,1);

        TMP1 =   _mm256_insertf128_si256(TMP1, tmp1,0);
        TMP1 =   _mm256_insertf128_si256(TMP1, tmp11,1);

        return simd_trait<float,cyme::avx,2>::register_type(_mm256_castsi256_ps(TMP0),_mm256_castsi256_ps(TMP1));
    }

    /**
      Extract the fraction of floating-point exponent (64-bit) elements and store the results in dst.
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_gf<float,cyme::avx,4>(simd_trait<float,cyme::avx,4>::register_type xmm0){
        __m256i TMP0 =  _mm256_castps_si256(xmm0.r0);
        __m256i TMP1 =  _mm256_castps_si256(xmm0.r1);
        __m256i TMP2 =  _mm256_castps_si256(xmm0.r2);
        __m256i TMP3 =  _mm256_castps_si256(xmm0.r3);


        __m128i tmp0 =  _mm256_extractf128_si256(TMP0,0);
        __m128i tmp1 =  _mm256_extractf128_si256(TMP1,0);
        __m128i tmp2 =  _mm256_extractf128_si256(TMP2,0);
        __m128i tmp3 =  _mm256_extractf128_si256(TMP3,0);

        tmp0 = _mm_and_si128(tmp0,_mm_set1_epi32(0x7fffff));
        tmp1 = _mm_and_si128(tmp1,_mm_set1_epi32(0x7fffff));
        tmp2 = _mm_and_si128(tmp2,_mm_set1_epi32(0x7fffff));
        tmp3 = _mm_and_si128(tmp3,_mm_set1_epi32(0x7fffff));

        tmp0 = _mm_add_epi32(tmp0,_mm_set1_epi32(0x3f800000));
        tmp1 = _mm_add_epi32(tmp1,_mm_set1_epi32(0x3f800000));
        tmp2 = _mm_add_epi32(tmp2,_mm_set1_epi32(0x3f800000));
        tmp3 = _mm_add_epi32(tmp3,_mm_set1_epi32(0x3f800000));

        __m128i tmp01 =  _mm256_extractf128_si256(TMP0,1);
        __m128i tmp11 =  _mm256_extractf128_si256(TMP1,1);
        __m128i tmp21 =  _mm256_extractf128_si256(TMP2,1);
        __m128i tmp31 =  _mm256_extractf128_si256(TMP3,1);

        tmp01 = _mm_and_si128(tmp01,_mm_set1_epi32(0x7fffff));
        tmp11 = _mm_and_si128(tmp11,_mm_set1_epi32(0x7fffff));
        tmp21 = _mm_and_si128(tmp21,_mm_set1_epi32(0x7fffff));
        tmp31 = _mm_and_si128(tmp31,_mm_set1_epi32(0x7fffff));

        tmp01 = _mm_add_epi32(tmp01,_mm_set1_epi32(0x3f800000));
        tmp11 = _mm_add_epi32(tmp11,_mm_set1_epi32(0x3f800000));
        tmp21 = _mm_add_epi32(tmp21,_mm_set1_epi32(0x3f800000));
        tmp31 = _mm_add_epi32(tmp31,_mm_set1_epi32(0x3f800000));

        TMP0 =   _mm256_insertf128_si256(TMP0, tmp0,0);
        TMP0 =   _mm256_insertf128_si256(TMP0, tmp01,1);

        TMP1 =   _mm256_insertf128_si256(TMP1, tmp1,0);
        TMP1 =   _mm256_insertf128_si256(TMP1, tmp11,1);

        TMP2 =   _mm256_insertf128_si256(TMP2, tmp2,0);
        TMP2 =   _mm256_insertf128_si256(TMP2, tmp21,1);

        TMP3 =   _mm256_insertf128_si256(TMP3, tmp3,0);
        TMP3 =   _mm256_insertf128_si256(TMP3, tmp31,1);

        return simd_trait<float,cyme::avx,4>::register_type(_mm256_castsi256_ps(TMP0),_mm256_castsi256_ps(TMP1),
                                                            _mm256_castsi256_ps(TMP2),_mm256_castsi256_ps(TMP3));
    }

    /**
      Compute sqrt (64-bit) floating point elements in xmm0 to packed double-precision (64-bit)
     floating-point elements, and store the results in dst.
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_sqrt<float,cyme::avx,1>( simd_trait<float,cyme::avx,1>::register_type xmm0){
        return _mm256_sqrt_ps(xmm0);
    }

    /**
      Compute sqrt (64-bit) floating point elements in xmm0 to packed double-precision (64-bit)
     floating-point elements, and store the results in dst.
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_sqrt<float,cyme::avx,2>( simd_trait<float,cyme::avx,2>::register_type xmm0){
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_sqrt_ps(xmm0.r0),
                                                            _mm256_sqrt_ps(xmm0.r1));
    }

    /**
      Compute sqrt (64-bit) floating point elements in xmm0 to packed double-precision (64-bit)
     floating-point elements, and store the results in dst.
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_sqrt<float,cyme::avx,4>( simd_trait<float,cyme::avx,4>::register_type xmm0){
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_sqrt_ps(xmm0.r0),
                                                            _mm256_sqrt_ps(xmm0.r1),
                                                            _mm256_sqrt_ps(xmm0.r2),
                                                            _mm256_sqrt_ps(xmm0.r3));
    }

    /**
      Compute 1/recsqrt (64-bit) floating point elements in xmm0 to packed double-precision (64-bit)
      floating-point elements, and store the results in dst. precision 12 bits
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_rsqrt<float,cyme::avx,1>(simd_trait<float,cyme::avx,1>::register_type xmm0){
        return _mm256_rsqrt_ps(xmm0);
    }

    /**
      Compute 1/recsqrt (64-bit) floating point elements in xmm0 to packed double-precision (64-bit)
      floating-point elements, and store the results in dst. precision 12 bits
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_rsqrt<float,cyme::avx,2>( simd_trait<float,cyme::avx,2>::register_type xmm0){
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_rsqrt_ps(xmm0.r0),
                                                            _mm256_rsqrt_ps(xmm0.r1));
    }

    /**
      Compute 1/recsqrt (64-bit) floating point elements in xmm0 to packed double-precision (64-bit)
      floating-point elements, and store the results in dst. precision 12 bits
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_rsqrt<float,cyme::avx,4>( simd_trait<float,cyme::avx,4>::register_type xmm0){
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_rsqrt_ps(xmm0.r0),
                                                            _mm256_rsqrt_ps(xmm0.r1),
                                                            _mm256_rsqrt_ps(xmm0.r2),
                                                            _mm256_rsqrt_ps(xmm0.r3));
    }

    /**
      Computes the absolute value for single-precision (32-bit) floating point elements and stores
      the result in dst.
      specialisation float,cyme::avx, 1 reg
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_fabs<float,cyme::avx,1>( simd_trait<float,cyme::avx,1>::register_type xmm0){
        simd_trait<float,cyme::avx,1>::register_type mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x7fffffff));
	return _mm256_and_ps(xmm0, mask);
    }

    /**
      Computes the absolute value for single-precision (32-bit) floating point elements and stores
      the result in dst.
      specialisation float,cyme::avx, 2 reg
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_fabs<float,cyme::avx,2>( simd_trait<float,cyme::avx,2>::register_type xmm0){
        simd_trait<float,cyme::avx,1>::register_type mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x7fffffff));
	return simd_trait<float,cyme::avx,2>::register_type(_mm256_and_ps(xmm0.r0, mask),
							    _mm256_and_ps(xmm0.r1, mask));
    }

    /**
      Computes the absolute value for single-precision (32-bit) floating point elements and stores
      the result in dst.
      specialisation float,cyme::avx, 4 reg
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_fabs<float,cyme::avx,4>( simd_trait<float,cyme::avx,4>::register_type xmm0){
        simd_trait<float,cyme::avx,1>::register_type mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x7fffffff));
	return simd_trait<float,cyme::avx,4>::register_type(_mm256_and_ps(xmm0.r0, mask),
							    _mm256_and_ps(xmm0.r1, mask),
							    _mm256_and_ps(xmm0.r2, mask),
							    _mm256_and_ps(xmm0.r3, mask));
    }

    /**
      Selects the polynomial for sin function. Inputs are:
	- Selector int
	- Option one
	- Option two
      specialisation float,cyme::avx, 1 reg
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_select_poly<float,cyme::avx,1>( simd_trait<int,cyme::avx,1>::register_type sel,
                                        simd_trait<float,cyme::avx,1>::register_type xmm0,
                                        simd_trait<float,cyme::avx,1>::register_type xmm1){
	__m128i mask = _mm_set1_epi32(2);
        __m128i tmp0 = _mm256_extractf128_si256(sel,0);
        tmp0 = _mm_and_si128(tmp0,mask);
	tmp0 = _mm_cmpeq_epi32(tmp0, _mm_set1_epi32(0));
        __m128i tmp1 = _mm256_extractf128_si256(sel,1);
        tmp1 = _mm_and_si128(tmp1,mask);
	tmp1 = _mm_cmpeq_epi32(tmp1, _mm_set1_epi32(0));
        sel = _mm256_insertf128_si256(sel, tmp0,0);
        sel = _mm256_insertf128_si256(sel, tmp1,1);

	xmm0 = _mm256_andnot_ps(_mm256_castsi256_ps(sel), xmm0);
	xmm1 = _mm256_and_ps(_mm256_castsi256_ps(sel), xmm1);
	return _mm256_add_ps(xmm0,xmm1);
    }

    /**
      Selects the polynomial for sin function. Inputs are:
	- Selector int
	- Option one
	- Option two
      specialisation float,cyme::avx, 2 reg
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_select_poly<float,cyme::avx,2>( simd_trait<int,cyme::avx,2>::register_type sel,
                                        simd_trait<float,cyme::avx,2>::register_type xmm0,
                                        simd_trait<float,cyme::avx,2>::register_type xmm1){
	__m128i mask = _mm_set1_epi32(2);
        __m128i tmp0_0 = _mm256_extractf128_si256(sel.r0,0);
        __m128i tmp0_1 = _mm256_extractf128_si256(sel.r1,0);
        tmp0_0 = _mm_and_si128(tmp0_0,mask);
        tmp0_1 = _mm_and_si128(tmp0_1,mask);
	tmp0_0 = _mm_cmpeq_epi32(tmp0_0, _mm_set1_epi32(0));
	tmp0_1 = _mm_cmpeq_epi32(tmp0_1, _mm_set1_epi32(0));
        __m128i tmp1_0 = _mm256_extractf128_si256(sel.r0,1);
        __m128i tmp1_1 = _mm256_extractf128_si256(sel.r1,1);
        tmp1_0 = _mm_and_si128(tmp1_0,mask);
        tmp1_1 = _mm_and_si128(tmp1_1,mask);
	tmp1_0 = _mm_cmpeq_epi32(tmp1_0, _mm_set1_epi32(0));
	tmp1_1 = _mm_cmpeq_epi32(tmp1_1, _mm_set1_epi32(0));
        sel.r0 = _mm256_insertf128_si256(sel.r0, tmp0_0, 0);
        sel.r1 = _mm256_insertf128_si256(sel.r1, tmp0_1, 0);
        sel.r0 = _mm256_insertf128_si256(sel.r0, tmp1_0, 1);
        sel.r1 = _mm256_insertf128_si256(sel.r1, tmp1_1, 1);

	xmm0.r0 = _mm256_andnot_ps(_mm256_castsi256_ps(sel.r0), xmm0.r0);
	xmm0.r1 = _mm256_andnot_ps(_mm256_castsi256_ps(sel.r1), xmm0.r1);
	xmm1.r0 = _mm256_and_ps(_mm256_castsi256_ps(sel.r0), xmm1.r0);
	xmm1.r1 = _mm256_and_ps(_mm256_castsi256_ps(sel.r1), xmm1.r1);
	return simd_trait<float,cyme::avx,2>::register_type(_mm256_add_ps(xmm0.r0,xmm1.r0),
							    _mm256_add_ps(xmm0.r1,xmm1.r1));
    }


    /**
      Selects the polynomial for sin function. Inputs are:
	- Selector int
	- Option one
	- Option two
      specialisation float,cyme::avx, 4 reg
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_select_poly<float,cyme::avx,4>( simd_trait<int,cyme::avx,4>::register_type sel,
                                        simd_trait<float,cyme::avx,4>::register_type xmm0,
                                        simd_trait<float,cyme::avx,4>::register_type xmm1){
	__m128i mask = _mm_set1_epi32(2);
        __m128i tmp0_0 = _mm256_extractf128_si256(sel.r0,0);
        __m128i tmp0_1 = _mm256_extractf128_si256(sel.r1,0);
        __m128i tmp0_2 = _mm256_extractf128_si256(sel.r2,0);
        __m128i tmp0_3 = _mm256_extractf128_si256(sel.r3,0);
        tmp0_0 = _mm_and_si128(tmp0_0,mask);
        tmp0_1 = _mm_and_si128(tmp0_1,mask);
        tmp0_2 = _mm_and_si128(tmp0_2,mask);
        tmp0_3 = _mm_and_si128(tmp0_3,mask);
	tmp0_0 = _mm_cmpeq_epi32(tmp0_0, _mm_set1_epi32(0));
	tmp0_1 = _mm_cmpeq_epi32(tmp0_1, _mm_set1_epi32(0));
	tmp0_2 = _mm_cmpeq_epi32(tmp0_2, _mm_set1_epi32(0));
	tmp0_3 = _mm_cmpeq_epi32(tmp0_3, _mm_set1_epi32(0));
        __m128i tmp1_0 = _mm256_extractf128_si256(sel.r0,1);
        __m128i tmp1_1 = _mm256_extractf128_si256(sel.r1,1);
        __m128i tmp1_2 = _mm256_extractf128_si256(sel.r2,1);
        __m128i tmp1_3 = _mm256_extractf128_si256(sel.r3,1);
        tmp1_0 = _mm_and_si128(tmp1_0,mask);
        tmp1_1 = _mm_and_si128(tmp1_1,mask);
        tmp1_2 = _mm_and_si128(tmp1_2,mask);
        tmp1_3 = _mm_and_si128(tmp1_3,mask);
	tmp1_0 = _mm_cmpeq_epi32(tmp1_0, _mm_set1_epi32(0));
	tmp1_1 = _mm_cmpeq_epi32(tmp1_1, _mm_set1_epi32(0));
	tmp1_2 = _mm_cmpeq_epi32(tmp1_2, _mm_set1_epi32(0));
	tmp1_3 = _mm_cmpeq_epi32(tmp1_3, _mm_set1_epi32(0));
        sel.r0 = _mm256_insertf128_si256(sel.r0, tmp0_0, 0);
        sel.r1 = _mm256_insertf128_si256(sel.r1, tmp0_1, 0);
        sel.r2 = _mm256_insertf128_si256(sel.r2, tmp0_2, 0);
        sel.r3 = _mm256_insertf128_si256(sel.r3, tmp0_3, 0);
        sel.r0 = _mm256_insertf128_si256(sel.r0, tmp1_0, 1);
        sel.r1 = _mm256_insertf128_si256(sel.r1, tmp1_1, 1);
        sel.r2 = _mm256_insertf128_si256(sel.r2, tmp1_2, 1);
        sel.r3 = _mm256_insertf128_si256(sel.r3, tmp1_3, 1);

	xmm0.r0 = _mm256_andnot_ps(_mm256_castsi256_ps(sel.r0), xmm0.r0);
	xmm0.r1 = _mm256_andnot_ps(_mm256_castsi256_ps(sel.r1), xmm0.r1);
	xmm0.r2 = _mm256_andnot_ps(_mm256_castsi256_ps(sel.r2), xmm0.r2);
	xmm0.r3 = _mm256_andnot_ps(_mm256_castsi256_ps(sel.r3), xmm0.r3);
	xmm1.r0 = _mm256_and_ps(_mm256_castsi256_ps(sel.r0), xmm1.r0);
	xmm1.r1 = _mm256_and_ps(_mm256_castsi256_ps(sel.r1), xmm1.r1);
	xmm1.r2 = _mm256_and_ps(_mm256_castsi256_ps(sel.r2), xmm1.r2);
	xmm1.r3 = _mm256_and_ps(_mm256_castsi256_ps(sel.r3), xmm1.r3);
	return simd_trait<float,cyme::avx,4>::register_type(_mm256_add_ps(xmm0.r0,xmm1.r0),
							    _mm256_add_ps(xmm0.r1,xmm1.r1),
							    _mm256_add_ps(xmm0.r2,xmm1.r2),
							    _mm256_add_ps(xmm0.r3,xmm1.r3));
    }

    /**
      Selects the sign (+/-) for sin function. Inputs are:
	- swap int
	- Original input
	- Final calculated sin value
      specialisation float ,cyme::avx, 1 reg
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_select_sign_sin<float,cyme::avx,1>( simd_trait<int,cyme::avx,1>::register_type swap,
                                            simd_trait<float,cyme::avx,1>::register_type  xmm0,
                                            simd_trait<float,cyme::avx,1>::register_type xmm1){
        simd_trait<float,cyme::avx,1>::register_type mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x80000000));
        __m128i four = _mm_set1_epi32(4);
	/* extract the sign bit (upper one) from original val */
	xmm0 = _mm256_and_ps(xmm0, mask);

	/* get the swap sign flag */
        __m128i tmp0 = _mm256_extractf128_si256(swap,0);
	tmp0 = _mm_and_si128(tmp0, four);
	tmp0 = _mm_slli_epi32(tmp0, 29);
        __m128i tmp1 = _mm256_extractf128_si256(swap,1);
	tmp1 = _mm_and_si128(tmp1, four);
	tmp1 = _mm_slli_epi32(tmp1, 29);
        swap = _mm256_insertf128_si256(swap, tmp0, 0);
        swap = _mm256_insertf128_si256(swap, tmp1, 1);

	/* update the sign of the final value*/
	xmm1 = _mm256_xor_ps(xmm1, _mm256_castsi256_ps(swap));
	xmm1 = _mm256_xor_ps(xmm1, xmm0);
	return xmm1;
    }

    /**
      Selects the sign (+/-) for sin function. Inputs are:
	- swap int
	- Original input
	- Final calculated sin value
      specialisation float ,cyme::avx, 2 reg
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_select_sign_sin<float,cyme::avx,2>( simd_trait<int,cyme::avx,2>::register_type swap,
                                            simd_trait<float,cyme::avx,2>::register_type xmm0,
                                            simd_trait<float,cyme::avx,2>::register_type xmm1){
        simd_trait<float,cyme::avx,1>::register_type mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x80000000));
        __m128i four = _mm_set1_epi32(4);
	/* extract the sign bit (upper one) from original val */
	xmm0.r0 = _mm256_and_ps(xmm0.r0, mask);
	xmm0.r1 = _mm256_and_ps(xmm0.r1, mask);

	/* get the swap sign flag */
        __m128i tmp0_0 = _mm256_extractf128_si256(swap.r0,0);
        __m128i tmp0_1 = _mm256_extractf128_si256(swap.r1,0);
	tmp0_0 = _mm_and_si128(tmp0_0, four);
	tmp0_1 = _mm_and_si128(tmp0_1, four);
	tmp0_0 = _mm_slli_epi32(tmp0_0, 29);
	tmp0_1 = _mm_slli_epi32(tmp0_1, 29);
        __m128i tmp1_0 = _mm256_extractf128_si256(swap.r0,1);
        __m128i tmp1_1 = _mm256_extractf128_si256(swap.r1,1);
	tmp1_0 = _mm_and_si128(tmp1_0, four);
	tmp1_1 = _mm_and_si128(tmp1_1, four);
	tmp1_0 = _mm_slli_epi32(tmp1_0, 29);
	tmp1_1 = _mm_slli_epi32(tmp1_1, 29);
        swap.r0 = _mm256_insertf128_si256(swap.r0, tmp0_0, 0);
        swap.r1 = _mm256_insertf128_si256(swap.r1, tmp0_1, 0);
        swap.r0 = _mm256_insertf128_si256(swap.r0, tmp1_0, 1);
        swap.r1 = _mm256_insertf128_si256(swap.r1, tmp1_1, 1);

	/* update the sign of the final value*/
	xmm1.r0 = _mm256_xor_ps(xmm1.r0, _mm256_castsi256_ps(swap.r0));
	xmm1.r1 = _mm256_xor_ps(xmm1.r1, _mm256_castsi256_ps(swap.r1));
	xmm1.r0 = _mm256_xor_ps(xmm1.r0, xmm0.r0);
	xmm1.r1 = _mm256_xor_ps(xmm1.r1, xmm0.r1);
	return simd_trait<float,cyme::avx,2>::register_type(xmm1.r0,xmm1.r1);
    }

    /**
      Selects the sign (+/-) for sin function. Inputs are:
	- swap int
	- Original input
	- Final calculated sin value
      specialisation float ,cyme::avx, 4 reg
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_select_sign_sin<float,cyme::avx,4>( simd_trait<int,cyme::avx,4>::register_type swap,
                                         simd_trait<float,cyme::avx,4>::register_type  xmm0,
                                         simd_trait<float,cyme::avx,4>::register_type xmm1){
        simd_trait<float,cyme::avx,1>::register_type mask = _mm256_castsi256_ps(_mm256_set1_epi32(0x80000000));
        __m128i four = _mm_set1_epi32(4);
	/* extract the sign bit (upper one) from original val */
	xmm0.r0 = _mm256_and_ps(xmm0.r0, mask);
	xmm0.r1 = _mm256_and_ps(xmm0.r1, mask);
	xmm0.r2 = _mm256_and_ps(xmm0.r2, mask);
	xmm0.r3 = _mm256_and_ps(xmm0.r3, mask);

	/* get the swap sign flag */
        __m128i tmp0_0 = _mm256_extractf128_si256(swap.r0,0);
        __m128i tmp0_1 = _mm256_extractf128_si256(swap.r1,0);
        __m128i tmp0_2 = _mm256_extractf128_si256(swap.r2,0);
        __m128i tmp0_3 = _mm256_extractf128_si256(swap.r3,0);
	tmp0_0 = _mm_and_si128(tmp0_0, four);
	tmp0_1 = _mm_and_si128(tmp0_1, four);
	tmp0_2 = _mm_and_si128(tmp0_2, four);
	tmp0_3 = _mm_and_si128(tmp0_3, four);
	tmp0_0 = _mm_slli_epi32(tmp0_0, 29);
	tmp0_1 = _mm_slli_epi32(tmp0_1, 29);
	tmp0_2 = _mm_slli_epi32(tmp0_2, 29);
	tmp0_3 = _mm_slli_epi32(tmp0_3, 29);
        __m128i tmp1_0 = _mm256_extractf128_si256(swap.r0,1);
        __m128i tmp1_1 = _mm256_extractf128_si256(swap.r1,1);
        __m128i tmp1_2 = _mm256_extractf128_si256(swap.r2,1);
        __m128i tmp1_3 = _mm256_extractf128_si256(swap.r3,1);
	tmp1_0 = _mm_and_si128(tmp1_0, four);
	tmp1_1 = _mm_and_si128(tmp1_1, four);
	tmp1_2 = _mm_and_si128(tmp1_2, four);
	tmp1_3 = _mm_and_si128(tmp1_3, four);
	tmp1_0 = _mm_slli_epi32(tmp1_0, 29);
	tmp1_1 = _mm_slli_epi32(tmp1_1, 29);
	tmp1_2 = _mm_slli_epi32(tmp1_2, 29);
	tmp1_3 = _mm_slli_epi32(tmp1_3, 29);
        swap.r0 = _mm256_insertf128_si256(swap.r0, tmp0_0, 0);
        swap.r1 = _mm256_insertf128_si256(swap.r1, tmp0_1, 0);
        swap.r2 = _mm256_insertf128_si256(swap.r2, tmp0_2, 0);
        swap.r3 = _mm256_insertf128_si256(swap.r3, tmp0_3, 0);
        swap.r0 = _mm256_insertf128_si256(swap.r0, tmp1_0, 1);
        swap.r1 = _mm256_insertf128_si256(swap.r1, tmp1_1, 1);
        swap.r2 = _mm256_insertf128_si256(swap.r2, tmp1_2, 1);
        swap.r3 = _mm256_insertf128_si256(swap.r3, tmp1_3, 1);

	/* update the sign of the final value*/
	xmm1.r0 = _mm256_xor_ps(xmm1.r0, _mm256_castsi256_ps(swap.r0));
	xmm1.r1 = _mm256_xor_ps(xmm1.r1, _mm256_castsi256_ps(swap.r1));
	xmm1.r2 = _mm256_xor_ps(xmm1.r2, _mm256_castsi256_ps(swap.r2));
	xmm1.r3 = _mm256_xor_ps(xmm1.r3, _mm256_castsi256_ps(swap.r3));
	xmm1.r0 = _mm256_xor_ps(xmm1.r0, xmm0.r0);
	xmm1.r1 = _mm256_xor_ps(xmm1.r1, xmm0.r1);
	xmm1.r2 = _mm256_xor_ps(xmm1.r2, xmm0.r2);
	xmm1.r3 = _mm256_xor_ps(xmm1.r3, xmm0.r3);
	return simd_trait<float,cyme::avx,4>::register_type(xmm1.r0,xmm1.r1,
							    xmm1.r2,xmm1.r3);
    }

    /**
      Selects the sign (+/-) for cos function. Inputs are:
	- swap int
	- Final calculated cos value
      specialisation float ,cyme::avx, 1 reg
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_select_sign_cos<float,cyme::avx,1>( simd_trait<int,cyme::avx,1>::register_type swap,
                                            simd_trait<float,cyme::avx,1>::register_type xmm0){
        __m128i four = _mm_set1_epi32(4);

	/* get the swap sign flag */
        __m128i tmp0 = _mm256_extractf128_si256(swap,0);
	tmp0 = _mm_andnot_si128(tmp0, four);
	tmp0 = _mm_slli_epi32(tmp0, 29);
        __m128i tmp1 = _mm256_extractf128_si256(swap,1);
	tmp1 = _mm_andnot_si128(tmp1, four);
	tmp1 = _mm_slli_epi32(tmp1, 29);
        swap = _mm256_insertf128_si256(swap, tmp0, 0);
        swap = _mm256_insertf128_si256(swap, tmp1, 1);

	/* update the sign of the final value*/
	xmm0 = _mm256_xor_ps(xmm0, _mm256_castsi256_ps(swap));
	return xmm0;
    }

    /**
      Selects the sign (+/-) for cos function. Inputs are:
	- swap int
	- Final calculated cos value
      specialisation float ,cyme::avx, 2 reg
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_select_sign_cos<float,cyme::avx,2>( simd_trait<int,cyme::avx,2>::register_type swap,
                                            simd_trait<float,cyme::avx,2>::register_type xmm0){
        __m128i four = _mm_set1_epi32(4);

	/* get the swap sign flag */
        __m128i tmp0_0 = _mm256_extractf128_si256(swap.r0,0);
        __m128i tmp0_1 = _mm256_extractf128_si256(swap.r1,0);
	tmp0_0 = _mm_andnot_si128(tmp0_0, four);
	tmp0_1 = _mm_andnot_si128(tmp0_1, four);
	tmp0_0 = _mm_slli_epi32(tmp0_0, 29);
	tmp0_1 = _mm_slli_epi32(tmp0_1, 29);
        __m128i tmp1_0 = _mm256_extractf128_si256(swap.r0,1);
        __m128i tmp1_1 = _mm256_extractf128_si256(swap.r1,1);
	tmp1_0 = _mm_andnot_si128(tmp1_0, four);
	tmp1_1 = _mm_andnot_si128(tmp1_1, four);
	tmp1_0 = _mm_slli_epi32(tmp1_0, 29);
	tmp1_1 = _mm_slli_epi32(tmp1_1, 29);
        swap.r0 = _mm256_insertf128_si256(swap.r0, tmp0_0, 0);
        swap.r1 = _mm256_insertf128_si256(swap.r1, tmp0_1, 0);
        swap.r0 = _mm256_insertf128_si256(swap.r0, tmp1_0, 1);
        swap.r1 = _mm256_insertf128_si256(swap.r1, tmp1_1, 1);

	/* update the sign of the final value*/
	xmm0.r0 = _mm256_xor_ps(xmm0.r0, _mm256_castsi256_ps(swap.r0));
	xmm0.r1 = _mm256_xor_ps(xmm0.r1, _mm256_castsi256_ps(swap.r1));
	return simd_trait<float,cyme::avx,2>::register_type(xmm0.r0,xmm0.r1);
    }

    /**
      Selects the sign (+/-) for cos function. Inputs are:
	- swap int
	- Final calculated cos value
      specialisation float ,cyme::avx, 4 reg
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_select_sign_cos<float,cyme::avx,4>( simd_trait<int,cyme::avx,4>::register_type swap,
                                            simd_trait<float,cyme::avx,4>::register_type xmm0){
        __m128i four = _mm_set1_epi32(4);

	/* get the swap sign flag */
        __m128i tmp0_0 = _mm256_extractf128_si256(swap.r0,0);
        __m128i tmp0_1 = _mm256_extractf128_si256(swap.r1,0);
        __m128i tmp0_2 = _mm256_extractf128_si256(swap.r2,0);
        __m128i tmp0_3 = _mm256_extractf128_si256(swap.r3,0);
	tmp0_0 = _mm_andnot_si128(tmp0_0, four);
	tmp0_1 = _mm_andnot_si128(tmp0_1, four);
	tmp0_2 = _mm_andnot_si128(tmp0_2, four);
	tmp0_3 = _mm_andnot_si128(tmp0_3, four);
	tmp0_0 = _mm_slli_epi32(tmp0_0, 29);
	tmp0_1 = _mm_slli_epi32(tmp0_1, 29);
	tmp0_2 = _mm_slli_epi32(tmp0_2, 29);
	tmp0_3 = _mm_slli_epi32(tmp0_3, 29);
        __m128i tmp1_0 = _mm256_extractf128_si256(swap.r0,1);
        __m128i tmp1_1 = _mm256_extractf128_si256(swap.r1,1);
        __m128i tmp1_2 = _mm256_extractf128_si256(swap.r2,1);
        __m128i tmp1_3 = _mm256_extractf128_si256(swap.r3,1);
	tmp1_0 = _mm_andnot_si128(tmp1_0, four);
	tmp1_1 = _mm_andnot_si128(tmp1_1, four);
	tmp1_2 = _mm_andnot_si128(tmp1_2, four);
	tmp1_3 = _mm_andnot_si128(tmp1_3, four);
	tmp1_0 = _mm_slli_epi32(tmp1_0, 29);
	tmp1_1 = _mm_slli_epi32(tmp1_1, 29);
	tmp1_2 = _mm_slli_epi32(tmp1_2, 29);
	tmp1_3 = _mm_slli_epi32(tmp1_3, 29);
        swap.r0 = _mm256_insertf128_si256(swap.r0, tmp0_0, 0);
        swap.r1 = _mm256_insertf128_si256(swap.r1, tmp0_1, 0);
        swap.r2 = _mm256_insertf128_si256(swap.r2, tmp0_2, 0);
        swap.r3 = _mm256_insertf128_si256(swap.r3, tmp0_3, 0);
        swap.r0 = _mm256_insertf128_si256(swap.r0, tmp1_0, 1);
        swap.r1 = _mm256_insertf128_si256(swap.r1, tmp1_1, 1);
        swap.r2 = _mm256_insertf128_si256(swap.r2, tmp1_2, 1);
        swap.r3 = _mm256_insertf128_si256(swap.r3, tmp1_3, 1);

	/* update the sign of the final value*/
	xmm0.r0 = _mm256_xor_ps(xmm0.r0, _mm256_castsi256_ps(swap.r0));
	xmm0.r1 = _mm256_xor_ps(xmm0.r1, _mm256_castsi256_ps(swap.r1));
	xmm0.r2 = _mm256_xor_ps(xmm0.r2, _mm256_castsi256_ps(swap.r2));
	xmm0.r3 = _mm256_xor_ps(xmm0.r3, _mm256_castsi256_ps(swap.r3));
	return simd_trait<float,cyme::avx,4>::register_type(xmm0.r0,xmm0.r1,
							                            xmm0.r2,xmm0.r3);
    }

    /**
      Evaluate the the < operator, return if true return 0xffffffffffffffff (true) else 0 (false)
      specialisation float,cyme::avx,1 regs
    */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_lt<float,cyme::avx,1> (simd_trait<float,cyme::avx,1>::register_type xmm0,
                               simd_trait<float,cyme::avx,1>::register_type xmm1){
        return _mm256_cmp_ps(xmm0, xmm1,_CMP_LT_OS);
    }

    /**
    Evaluate the the < operator, return if true return 0xffffffffffffffff (true) else 0 (false)
    specialisation float,cyme::avx,2 regs
    */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_lt<float,cyme::avx,2> (simd_trait<float,cyme::avx,2>::register_type xmm0,
                               simd_trait<float,cyme::avx,2>::register_type xmm1){
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_cmp_ps(xmm0.r0, xmm1.r0,_CMP_LT_OS),
                                                            _mm256_cmp_ps(xmm0.r1, xmm1.r1,_CMP_LT_OS));
    }

    /**
    Evaluate the the < operator, return if true return 0xffffffffffffffff (true) else 0 (false)
    specialisation float,cyme::avx,4 regs
    */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_lt<float,cyme::avx,4> (simd_trait<float,cyme::avx,4>::register_type xmm0,
                               simd_trait<float,cyme::avx,4>::register_type xmm1){
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_cmp_ps(xmm0.r0, xmm1.r0,_CMP_LT_OS),
                                                            _mm256_cmp_ps(xmm0.r1, xmm1.r1,_CMP_LT_OS),
                                                            _mm256_cmp_ps(xmm0.r2, xmm1.r2,_CMP_LT_OS),
                                                            _mm256_cmp_ps(xmm0.r3, xmm1.r3,_CMP_LT_OS));
    }


    /**
     Evaluate the the > operator, return if true return 0xffffffffffffffff (true) else 0 (false)
     specialisation float,cyme::avx,1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_gt<float,cyme::avx,1> (simd_trait<float,cyme::avx,1>::register_type xmm0,
                               simd_trait<float,cyme::avx,1>::register_type xmm1){
        return _mm256_cmp_ps(xmm0, xmm1,_CMP_GT_OS);
    }

    /**
     Evaluate the the > operator, return if true return 0xffffffffffffffff (true) else 0 (false)
     specialisation float,cyme::avx,2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_gt<float,cyme::avx,2> (simd_trait<float,cyme::avx,2>::register_type xmm0,
                               simd_trait<float,cyme::avx,2>::register_type xmm1){
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_cmp_ps(xmm0.r0, xmm1.r0,_CMP_GT_OS),
                                                            _mm256_cmp_ps(xmm0.r1, xmm1.r1,_CMP_GT_OS));
    }

    /**
     Evaluate the the > operator, return if true return 0xffffffffffffffff (true) else 0 (false)
     specialisation float,cyme::avx,4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_gt<float,cyme::avx,4> (simd_trait<float,cyme::avx,4>::register_type xmm0,
                               simd_trait<float,cyme::avx,4>::register_type xmm1){
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_cmp_ps(xmm0.r0, xmm1.r0,_CMP_GT_OS),
                                                            _mm256_cmp_ps(xmm0.r1, xmm1.r1,_CMP_GT_OS),
                                                            _mm256_cmp_ps(xmm0.r2, xmm1.r2,_CMP_GT_OS),
                                                            _mm256_cmp_ps(xmm0.r3, xmm1.r3,_CMP_GT_OS));
    }

    /**
     Evaluate the the == operator, return if true return 0xffffffffffffffff (true) else 0 (false)
     specialisation float,cyme::avx,1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_eq<float,cyme::avx,1> (simd_trait<float,cyme::avx,1>::register_type xmm0,
                               simd_trait<float,cyme::avx,1>::register_type xmm1){
        return _mm256_cmp_ps(xmm0, xmm1,_CMP_EQ_OS);
    }

    /**
     Evaluate the the == operator, return if true return 0xffffffffffffffff (true) else 0 (false)
     specialisation float,cyme::avx,2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_eq<float,cyme::avx,2> (simd_trait<float,cyme::avx,2>::register_type xmm0,
                               simd_trait<float,cyme::avx,2>::register_type xmm1){
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_cmp_ps(xmm0.r0, xmm1.r0,_CMP_EQ_OS),
                                                            _mm256_cmp_ps(xmm0.r1, xmm1.r1,_CMP_EQ_OS));
    }

    /**
     Evaluate the the == operator, return if true return 0xffffffffffffffff (true) else 0 (false)
     specialisation float,cyme::avx,4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_eq<float,cyme::avx,4> (simd_trait<float,cyme::avx,4>::register_type xmm0,
                               simd_trait<float,cyme::avx,4>::register_type xmm1){
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_cmp_ps(xmm0.r0, xmm1.r0,_CMP_EQ_OS),
                                                            _mm256_cmp_ps(xmm0.r1, xmm1.r1,_CMP_EQ_OS),
                                                            _mm256_cmp_ps(xmm0.r2, xmm1.r2,_CMP_EQ_OS),
                                                            _mm256_cmp_ps(xmm0.r3, xmm1.r3,_CMP_EQ_OS));
    }

    /**
     Evaluate the  & operator between two registers
     specialisation float,cyme::avx,1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_and<float,cyme::avx,1> (simd_trait<float,cyme::avx,1>::register_type xmm0,
                                simd_trait<float,cyme::avx,1>::register_type xmm1){
        return _mm256_and_ps(xmm0,xmm1);
    }

    /**
     Evaluate the  & operator between two registers
     specialisation float,cyme::avx,2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_and<float,cyme::avx,2> (simd_trait<float,cyme::avx,2>::register_type xmm0,
                                simd_trait<float,cyme::avx,2>::register_type xmm1){
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_and_ps(xmm0.r0,xmm1.r0),
                                                            _mm256_and_ps(xmm0.r1,xmm1.r1));
    }

    /**
     Evaluate the  & operator between two registers
     specialisation float,cyme::avx,4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_and<float,cyme::avx,4> (simd_trait<float,cyme::avx,4>::register_type xmm0,
                                simd_trait<float,cyme::avx,4>::register_type xmm1){
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_and_ps(xmm0.r0,xmm1.r0),
                                                            _mm256_and_ps(xmm0.r1,xmm1.r1),
                                                            _mm256_and_ps(xmm0.r2,xmm1.r2),
                                                            _mm256_and_ps(xmm0.r3,xmm1.r3));
    }

    /**
     Evaluate the  | operator between two registers
     specialisation float,cyme::avx,1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_or<float,cyme::avx,1> (simd_trait<float,cyme::avx,1>::register_type xmm0,
                               simd_trait<float,cyme::avx,1>::register_type xmm1){
        return _mm256_or_ps(xmm0,xmm1);
    }

    /**
     Evaluate the  | operator between two registers
     specialisation float,cyme::avx,2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_or<float,cyme::avx,2> (simd_trait<float,cyme::avx,2>::register_type xmm0,
                               simd_trait<float,cyme::avx,2>::register_type xmm1){
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_or_ps(xmm0.r0,xmm1.r0),
                                                            _mm256_or_ps(xmm0.r1,xmm1.r1));
    }

    /**
     Evaluate the  | operator between two registers
     specialisation float,cyme::avx,4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_or<float,cyme::avx,4> (simd_trait<float,cyme::avx,4>::register_type xmm0,
                               simd_trait<float,cyme::avx,4>::register_type xmm1){
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_or_ps(xmm0.r0,xmm1.r0),
                                                            _mm256_or_ps(xmm0.r1,xmm1.r1),
                                                            _mm256_or_ps(xmm0.r2,xmm1.r2),
                                                            _mm256_or_ps(xmm0.r3,xmm1.r3));
    }

    /**
     Evaluate the andnot  operator between two registers
     specialisation float,cyme::avx,1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_andnot<float,cyme::avx,1> (simd_trait<float,cyme::avx,1>::register_type xmm0){
        __m256 mask = _mm256_castsi256_ps(_mm256_set1_epi32(0xffffffff));
        return _mm256_andnot_ps(xmm0,mask);
    }

    /**
     Evaluate the  andnot operator between two registers
     specialisation float,cyme::avx,2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_andnot<float,cyme::avx,2> (simd_trait<float,cyme::avx,2>::register_type xmm0){
        __m256 mask = _mm256_castsi256_ps(_mm256_set1_epi32(0xffffffff));
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_andnot_ps(xmm0.r0,mask),
                                                            _mm256_andnot_ps(xmm0.r1,mask));
    }

    /**
     Evaluate the  andnot operator between two registers
     specialisation float,cyme::avx,4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_andnot<float,cyme::avx,4> (simd_trait<float,cyme::avx,4>::register_type xmm0){
        __m256 mask = _mm256_castsi256_ps(_mm256_set1_epi32(0xffffffff));
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_andnot_ps(xmm0.r0,mask),
                                                            _mm256_andnot_ps(xmm0.r1,mask),
                                                            _mm256_andnot_ps(xmm0.r2,mask),
                                                            _mm256_andnot_ps(xmm0.r3,mask));
    }

#ifdef  __INTEL_COMPILER
    /**
      Compute the exponential value of e raised to the power of packed single-precision (32-bit)
     floating-point elements in xmm0, and store the results in dst.
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_exp<float,cyme::avx,1>( simd_trait<float,cyme::avx,1>::register_type xmm0){
        return __svml_expf8(xmm0);
    }

    /**
      Compute the exponential value of e raised to the power of packed single-precision (32-bit)
     floating-point elements in xmm0, and store the results in dst.
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline  simd_trait<float,cyme::avx,2>::register_type
    _mm_exp<float,cyme::avx,2>( simd_trait<float,cyme::avx,2>::register_type xmm0){
        return simd_trait<float,cyme::avx,2>::register_type(__svml_expf8(xmm0.r0),
                                                            __svml_expf8(xmm0.r1));
    }

    /**
      Compute the exponential value of e raised to the power of packed single-precision (32-bit)
     floating-point elements in xmm0, and store the results in dst.
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline  simd_trait<float,cyme::avx,4>::register_type
    _mm_exp<float,cyme::avx,4>( simd_trait<float,cyme::avx,4>::register_type xmm0){
        return simd_trait<float,cyme::avx,4>::register_type(__svml_expf8(xmm0.r0),
                                                            __svml_expf8(xmm0.r1),
                                                            __svml_expf8(xmm0.r2),
                                                            __svml_expf8(xmm0.r3));
    }

    /**
      Compute the natural logarithm of packed single-precision (32-bit) floating-point elements in xmm0,
     and store the results in dst.
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_log<float,cyme::avx,1>(simd_trait<float,cyme::avx,1>::register_type xmm0){
        return __svml_logf8(xmm0);
    }

    /**
      Compute the natural logarithm of packed single-precision (32-bit) floating-point elements in xmm0,
     and store the results in dst.
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline  simd_trait<float,cyme::avx,2>::register_type
    _mm_log<float,cyme::avx,2>(simd_trait<float,cyme::avx,2>::register_type xmm0){
        return simd_trait<float,cyme::avx,2>::register_type(__svml_logf8(xmm0.r0),
                                                            __svml_logf8(xmm0.r1));
    }

    /**
      Compute the natural logarithm of packed single-precision (32-bit) floating-point elements in xmm0,
     and store the results in dst.
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline  simd_trait<float,cyme::avx,4>::register_type
    _mm_log<float,cyme::avx,4>(simd_trait<float,cyme::avx,4>::register_type xmm0){
        return simd_trait<float,cyme::avx,4>::register_type(__svml_logf8(xmm0.r0),
                                                            __svml_logf8(xmm0.r1),
                                                            __svml_logf8(xmm0.r2),
                                                            __svml_logf8(xmm0.r3));
    }
#endif

#ifdef __FMA__
    /**
      Multiply packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
     add the intermediate result to packed elements in xmm2, and store the results in dst.
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_fma<float,cyme::avx,1>(simd_trait<float,cyme::avx,1>::register_type xmm0,
                               simd_trait<float,cyme::avx,1>::register_type xmm1,
                               simd_trait<float,cyme::avx,1>::register_type xmm2){
        return _mm256_fmadd_ps(xmm0, xmm1, xmm2);
    }

    /**
      Multiply packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
     add the intermediate result to packed elements in xmm2, and store the results in dst.
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline  simd_trait<float,cyme::avx,2>::register_type
    _mm_fma<float,cyme::avx,2>(simd_trait<float,cyme::avx,2>::register_type xmm0,
                               simd_trait<float,cyme::avx,2>::register_type xmm1,
                               simd_trait<float,cyme::avx,2>::register_type xmm2){
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_fmadd_ps(xmm0.r0, xmm1.r0, xmm2.r0),
                                                            _mm256_fmadd_ps(xmm0.r1, xmm1.r1, xmm2.r1));
    }

    /**
      Multiply packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
     add the intermediate result to packed elements in xmm2, and store the results in dst.
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_fma<float,cyme::avx,4>(simd_trait<float,cyme::avx,4>::register_type xmm0,
                               simd_trait<float,cyme::avx,4>::register_type xmm1,
                               simd_trait<float,cyme::avx,4>::register_type xmm2){
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_fmadd_ps(xmm0.r0, xmm1.r0, xmm2.r0),
                                                            _mm256_fmadd_ps(xmm0.r1, xmm1.r1, xmm2.r1),
                                                            _mm256_fmadd_ps(xmm0.r2, xmm1.r2, xmm2.r2),
                                                            _mm256_fmadd_ps(xmm0.r3, xmm1.r3, xmm2.r3));
    }

    /**
      Multiply packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
     add the negated intermediate result to packed elements in xmm2, and store the results in dst.
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_nfma<float,cyme::avx,1>(simd_trait<float,cyme::avx,1>::register_type xmm0,
                                simd_trait<float,cyme::avx,1>::register_type xmm1,
                                simd_trait<float,cyme::avx,1>::register_type xmm2){
        return _mm256_fnmadd_ps(xmm0, xmm1, xmm2);
    }

    /**
      Multiply packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
     add the negated intermediate result to packed elements in xmm2, and store the results in dst.
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_nfma<float,cyme::avx,2>(simd_trait<float,cyme::avx,2>::register_type xmm0,
                                simd_trait<float,cyme::avx,2>::register_type xmm1,
                                simd_trait<float,cyme::avx,2>::register_type xmm2){
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_fnmadd_ps(xmm0.r0, xmm1.r0, xmm2.r0),
                                                            _mm256_fnmadd_ps(xmm0.r1, xmm1.r1, xmm2.r1));
    }

    /**
      Multiply packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
     add the negated intermediate result to packed elements in xmm2, and store the results in dst.
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_nfma<float,cyme::avx,4>(simd_trait<float,cyme::avx,4>::register_type xmm0,
                                simd_trait<float,cyme::avx,4>::register_type xmm1,
                                simd_trait<float,cyme::avx,4>::register_type xmm2){
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_fnmadd_ps(xmm0.r0, xmm1.r0, xmm2.r0),
                                                            _mm256_fnmadd_ps(xmm0.r1, xmm1.r1, xmm2.r1),
                                                            _mm256_fnmadd_ps(xmm0.r2, xmm1.r2, xmm2.r2),
                                                            _mm256_fnmadd_ps(xmm0.r3, xmm1.r3, xmm2.r3));
    }

    /**
      Multiply packed single-precision (32-bit) floating-point elements in xmm0 and xmm1, subtract
      packed elements in xmm2 from the intermediate result, and store the results in dst.
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_fms<float,cyme::avx,1>(simd_trait<float,cyme::avx,1>::register_type xmm0,
                               simd_trait<float,cyme::avx,1>::register_type xmm1,
                               simd_trait<float,cyme::avx,1>::register_type xmm2){
        return _mm256_fmsub_ps(xmm0, xmm1, xmm2);
    }

    /**
      Multiply packed single-precision (32-bit) floating-point elements in xmm0 and xmm1, subtract
      packed elements in xmm2 from the intermediate result, and store the results in dst.
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_fms<float,cyme::avx,2>(simd_trait<float,cyme::avx,2>::register_type xmm0,
                               simd_trait<float,cyme::avx,2>::register_type xmm1,
                               simd_trait<float,cyme::avx,2>::register_type xmm2){
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_fmsub_ps(xmm0.r0, xmm1.r0, xmm2.r0),
                                                            _mm256_fmsub_ps(xmm0.r1, xmm1.r1, xmm2.r1));
    }

    /**
      Multiply packed single-precision (32-bit) floating-point elements in xmm0 and xmm1, subtract
      packed elements in xmm2 from the intermediate result, and store the results in dst.
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_fms<float,cyme::avx,4>(simd_trait<float,cyme::avx,4>::register_type xmm0,
                               simd_trait<float,cyme::avx,4>::register_type xmm1,
                               simd_trait<float,cyme::avx,4>::register_type xmm2){
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_fmsub_ps(xmm0.r0, xmm1.r0, xmm2.r0),
                                                            _mm256_fmsub_ps(xmm0.r1, xmm1.r1, xmm2.r1),
                                                            _mm256_fmsub_ps(xmm0.r2, xmm1.r2, xmm2.r2),
                                                            _mm256_fmsub_ps(xmm0.r3, xmm1.r3, xmm2.r3));
    }

    /**
      Multiply packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
     subtract packed elements in xmm2 from the negated intermediate result, and store the results in dst.
      specialisation float,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,1>::register_type
    _mm_nfms<float,cyme::avx,1>(simd_trait<float,cyme::avx,1>::register_type xmm0,
                                simd_trait<float,cyme::avx,1>::register_type xmm1,
                                simd_trait<float,cyme::avx,1>::register_type xmm2){
        return _mm256_fnmsub_ps(xmm0, xmm1, xmm2);
    }

    /**
      Multiply packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
     subtract packed elements in xmm2 from the negated intermediate result, and store the results in dst.
      specialisation float,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,2>::register_type
    _mm_nfms<float,cyme::avx,2>(simd_trait<float,cyme::avx,2>::register_type xmm0,
                                simd_trait<float,cyme::avx,2>::register_type xmm1,
                                simd_trait<float,cyme::avx,2>::register_type xmm2){
        return simd_trait<float,cyme::avx,2>::register_type(_mm256_fnmsub_ps(xmm0.r0, xmm1.r0, xmm2.r0),
                                                            _mm256_fnmsub_ps(xmm0.r1, xmm1.r1, xmm2.r1));
    }

    /**
      Multiply packed single-precision (32-bit) floating-point elements in xmm0 and xmm1,
     subtract packed elements in xmm2 from the negated intermediate result, and store the results in dst.
      specialisation float,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<float,cyme::avx,4>::register_type
    _mm_nfms<float,cyme::avx,4>(simd_trait<float,cyme::avx,4>::register_type xmm0,
                                simd_trait<float,cyme::avx,4>::register_type xmm1,
                                simd_trait<float,cyme::avx,4>::register_type xmm2){
        return simd_trait<float,cyme::avx,4>::register_type(_mm256_fnmsub_ps(xmm0.r0, xmm1.r0, xmm2.r0),
                                                            _mm256_fnmsub_ps(xmm0.r1, xmm1.r1, xmm2.r1),
                                                            _mm256_fnmsub_ps(xmm0.r2, xmm1.r2, xmm2.r2),
                                                            _mm256_fnmsub_ps(xmm0.r3, xmm1.r3, xmm2.r3));
    }
#endif //end FMA

    /** limited support to 32bit integer */
    /**
      Load a single-precision (32-bit) integer element from cyme into all elements of dst.
       specialisation int,cyme::avx,1 regs
     */
    template<>
    forceinline simd_trait<int,cyme::avx,1>::register_type
    _mm_load1<int,cyme::avx,1>(const simd_trait<int,cyme::avx,1>::value_type& a){
        return  _mm256_set1_epi32(a);
    }

    /**
      Load a single-precision (32-bit) integer element from cyme into all elements of dst.
       specialisation int,cyme::avx,2 regs
     */
    template<>
    forceinline simd_trait<int,cyme::avx,2>::register_type
    _mm_load1<int,cyme::avx,2>(const simd_trait<int,cyme::avx,2>::value_type& a){
        return simd_trait<int,cyme::avx,2>::register_type( _mm256_set1_epi32(a), _mm256_set1_epi32(a));
    }

    /**
      Load a single-precision (32-bit) integer element from cyme into all elements of dst.
       specialisation int,cyme::avx,4 regs
     */
    template<>
    forceinline simd_trait<int,cyme::avx,4>::register_type
    _mm_load1<int,cyme::avx,4>(const simd_trait<int,cyme::avx,4>::value_type& a){
        return simd_trait<int,cyme::avx,4>::register_type( _mm256_set1_epi32(a), _mm256_set1_epi32(a),
                                                           _mm256_set1_epi32(a), _mm256_set1_epi32(a));
    }

    /**
      Load 256-bits (composed of 4 packed integer (32-bit)  from cyme
     into dst. mem_addr must be aligned on a 32-byte boundary or a general-protection exception will be generated.
     specialisation float,cyme::avx,1 regs
     */
    template<>
    forceinline simd_trait<int,cyme::avx,1>::register_type
    _mm_load<int,cyme::avx,1>(simd_trait<int,cyme::avx,1>::const_pointer a){
        return _mm256_load_si256((__m256i*)a);
    }

    /**
      Load 256-bits (composed of 4 packed integer (32-bit) ) from cyme
     into dst. mem_addr must be aligned on a 32-byte boundary or a general-protection exception will be generated.
     specialisation float,cyme::avx,2 regs
     */
    template<>
    forceinline simd_trait<int,cyme::avx,2>::register_type
    _mm_load<int,cyme::avx,2>(simd_trait<int,cyme::avx,2>::const_pointer a){
        return simd_trait<int,cyme::avx,2>::register_type(_mm256_load_si256((__m256i*)a),
                                                          _mm256_load_si256((__m256i*)(a+8)));
    }

    /**
      Load 256-bits (composed of 4 packed integer(32-bit)) from cyme
     into dst. mem_addr must be aligned on a 32-byte boundary or a general-protection exception will be generated.
     specialisation float,cyme::avx,4 regs
     */
    template<>
    forceinline simd_trait<int,cyme::avx,4>::register_type
    _mm_load<int,cyme::avx,4>(simd_trait<int,cyme::avx,4>::const_pointer a){
        return simd_trait<int,cyme::avx,4>::register_type(_mm256_load_si256((__m256i*)a),
                                                          _mm256_load_si256((__m256i*)(a+8)),
                                                          _mm256_load_si256((__m256i*)(a+16)),
                                                          _mm256_load_si256((__m256i*)(a+24)));
    }

    /**
       Store 256-bits (composed of 4 packed integer (32-bit)) from a into cyme.
     mem_addr must be aligned on a 16-byte boundary or a general-protection exception will be generated.
     specialisation int,cyme::avx,1 regs
     */
    template<>
    forceinline void _mm_store<int,cyme::avx,1>(simd_trait<int,cyme::avx,1>::register_type xmm0,
                                    simd_trait<int,cyme::avx,1>::pointer a){
        _mm256_store_si256((__m256i*)a,xmm0);
    }

    /**
       Store 256-bits (composed of 4 packed integer (32-bit) ) from a into cyme.
     mem_addr must be aligned on a 16-byte boundary or a general-protection exception will be generated.
     specialisation int,cyme::avx,2 regs
     */
    template<>
    forceinline void _mm_store<int,cyme::avx,2>(simd_trait<int,cyme::avx,2>::register_type xmm0,
                                    simd_trait<int,cyme::avx,2>::pointer a){
        _mm256_store_si256((__m256i*)a,xmm0.r0);
        _mm256_store_si256((__m256i*)(a+8),xmm0.r1);
    }

    /**
       Store 256-bits (composed of 4 packed integer (32-bit)) from a into cyme.
     mem_addr must be aligned on a 16-byte boundary or a general-protection exception will be generated.
     specialisation int,cyme::avx,4 regs
     */
    template<>
    forceinline void _mm_store<int,cyme::avx,4>(simd_trait<int,cyme::avx,4>::register_type xmm0,
                                    simd_trait<int,cyme::avx,4>::pointer a){
        _mm256_store_si256((__m256i*)a,xmm0.r0);
        _mm256_store_si256((__m256i*)(a+8),xmm0.r1);
        _mm256_store_si256((__m256i*)(a+16),xmm0.r2);
        _mm256_store_si256((__m256i*)(a+24),xmm0.r3);
    }

     /**
      Evaluate the the < operator, return if true return 0xffffffffffffffff (true) else 0 (false)
      specialisation int,cyme::avx,1 regs
     */
     template<>
     forceinline simd_trait<int,cyme::avx,1>::register_type
     _mm_lt<int,cyme::avx,1> (simd_trait<int,cyme::avx,1>::register_type xmm0,
                              simd_trait<int,cyme::avx,1>::register_type xmm1){
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wuninitialized"
        __m128i tmp0 = _mm_cmplt_epi32(_mm256_extractf128_si256(xmm0,0),_mm256_extractf128_si256(xmm1,0));
        __m128i tmp1 = _mm_cmplt_epi32(_mm256_extractf128_si256(xmm0,1),_mm256_extractf128_si256(xmm1,1));
        __m256i res = _mm256_insertf128_si256(res, tmp0,0);
                res = _mm256_insertf128_si256(res, tmp1,1);
        #pragma GCC diagnostic pop
        return res;
     }

     /**
      Evaluate the the < operator, return if true return 0xffffffffffffffff (true) else 0 (false)
      specialisation float,cyme::avx,2 regs
     */
     template<>
     forceinline simd_trait<int,cyme::avx,2>::register_type
     _mm_lt<int,cyme::avx,2> (simd_trait<int,cyme::avx,2>::register_type xmm0,
                              simd_trait<int,cyme::avx,2>::register_type xmm1){
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wuninitialized"
        __m128i tmp0 = _mm_cmplt_epi32(_mm256_extractf128_si256(xmm0.r0,0),_mm256_extractf128_si256(xmm1.r0,0));
        __m128i tmp1 = _mm_cmplt_epi32(_mm256_extractf128_si256(xmm0.r0,1),_mm256_extractf128_si256(xmm1.r0,1));
        __m128i tmp2 = _mm_cmplt_epi32(_mm256_extractf128_si256(xmm0.r1,0),_mm256_extractf128_si256(xmm1.r1,0));
        __m128i tmp3 = _mm_cmplt_epi32(_mm256_extractf128_si256(xmm0.r1,1),_mm256_extractf128_si256(xmm1.r1,1));
        __m256i res0 = _mm256_insertf128_si256(res0, tmp0,0);
                res0 = _mm256_insertf128_si256(res0, tmp1,1);
        __m256i res1 = _mm256_insertf128_si256(res1, tmp2,0);
                res1 = _mm256_insertf128_si256(res1, tmp3,1);
        #pragma GCC diagnostic pop
        return simd_trait<int,cyme::avx,2>::register_type(res0,res1);
     }

     /**
      Evaluate the the < operator, return if true return 0xffffffffffffffff (true) else 0 (false)
      specialisation int,cyme::avx,1 regs
     */
     template<>
     forceinline simd_trait<int,cyme::avx,4>::register_type
     _mm_lt<int,cyme::avx,4> (simd_trait<int,cyme::avx,4>::register_type xmm0,
                              simd_trait<int,cyme::avx,4>::register_type xmm1){
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wuninitialized"
        __m128i tmp0 = _mm_cmplt_epi32(_mm256_extractf128_si256(xmm0.r0,0),_mm256_extractf128_si256(xmm1.r0,0));
        __m128i tmp1 = _mm_cmplt_epi32(_mm256_extractf128_si256(xmm0.r0,1),_mm256_extractf128_si256(xmm1.r0,1));
        __m128i tmp2 = _mm_cmplt_epi32(_mm256_extractf128_si256(xmm0.r1,0),_mm256_extractf128_si256(xmm1.r1,0));
        __m128i tmp3 = _mm_cmplt_epi32(_mm256_extractf128_si256(xmm0.r1,1),_mm256_extractf128_si256(xmm1.r1,1));
        __m128i tmp4 = _mm_cmplt_epi32(_mm256_extractf128_si256(xmm0.r2,0),_mm256_extractf128_si256(xmm1.r2,0));
        __m128i tmp5 = _mm_cmplt_epi32(_mm256_extractf128_si256(xmm0.r2,1),_mm256_extractf128_si256(xmm1.r2,1));
        __m128i tmp6 = _mm_cmplt_epi32(_mm256_extractf128_si256(xmm0.r3,0),_mm256_extractf128_si256(xmm1.r3,0));
        __m128i tmp7 = _mm_cmplt_epi32(_mm256_extractf128_si256(xmm0.r3,1),_mm256_extractf128_si256(xmm1.r3,1));

        __m256i res0 = _mm256_insertf128_si256(res0, tmp0,0);
                res0 = _mm256_insertf128_si256(res0, tmp1,1);
        __m256i res1 = _mm256_insertf128_si256(res1, tmp2,0);
                res1 = _mm256_insertf128_si256(res1, tmp3,1);
        __m256i res2 = _mm256_insertf128_si256(res2, tmp4,0);
                res2 = _mm256_insertf128_si256(res2, tmp5,1);
        __m256i res3 = _mm256_insertf128_si256(res3, tmp6,0);
                res3 = _mm256_insertf128_si256(res3, tmp7,1);

        #pragma GCC diagnostic pop
        return simd_trait<int,cyme::avx,4>::register_type(res0,res1,res2,res3);
     }

    /**
      Add packed 32 bit integer (32-bit)  elements in xmm0 and xmm1,
     and store the results in dst.
      specialisation double,cyme::avx, 1 regs
     */
    template<>
    forceinline simd_trait<int,cyme::avx,1>::register_type
    _mm_add<int,cyme::avx,1>(simd_trait<int,cyme::avx,1>::register_type xmm0,
                             simd_trait<int,cyme::avx,1>::register_type xmm1){
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wuninitialized"
        __m128i tmp0 = _mm_add_epi32(_mm256_extractf128_si256(xmm0,0),_mm256_extractf128_si256(xmm1,0));
        __m128i tmp1 = _mm_add_epi32(_mm256_extractf128_si256(xmm0,1),_mm256_extractf128_si256(xmm1,1));
        __m256i res = _mm256_insertf128_si256(res, tmp0,0);
                res = _mm256_insertf128_si256(res, tmp1,1);
        #pragma GCC diagnostic pop
        return res;
    }

    /**
      Add packed 32 bit integer (32-bit)  elements in xmm0 and xmm1,
     and store the results in dst.
      specialisation double,cyme::avx, 2 regs
     */
    template<>
    forceinline simd_trait<int,cyme::avx,2>::register_type
    _mm_add<int,cyme::avx,2>(simd_trait<int,cyme::avx,2>::register_type xmm0,
                             simd_trait<int,cyme::avx,2>::register_type xmm1){
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wuninitialized"
        __m128i tmp0 = _mm_add_epi32(_mm256_extractf128_si256(xmm0.r0,0),_mm256_extractf128_si256(xmm1.r0,0));
        __m128i tmp1 = _mm_add_epi32(_mm256_extractf128_si256(xmm0.r0,1),_mm256_extractf128_si256(xmm1.r0,1));
        __m128i tmp2 = _mm_add_epi32(_mm256_extractf128_si256(xmm0.r1,0),_mm256_extractf128_si256(xmm1.r1,0));
        __m128i tmp3 = _mm_add_epi32(_mm256_extractf128_si256(xmm0.r1,1),_mm256_extractf128_si256(xmm1.r1,1));
        __m256i res0 = _mm256_insertf128_si256(res0, tmp0,0);
                res0 = _mm256_insertf128_si256(res0, tmp1,1);
        __m256i res1 = _mm256_insertf128_si256(res1, tmp2,0);
                res1 = _mm256_insertf128_si256(res1, tmp3,1);
        #pragma GCC diagnostic pop
        return simd_trait<int,cyme::avx,2>::register_type(res0,res1);
    }

    /**
      Add packed 32 bit integer (32-bit)  elements in xmm0 and xmm1,
     and store the results in dst.
      specialisation double,cyme::avx, 4 regs
     */
    template<>
    forceinline simd_trait<int,cyme::avx,4>::register_type
    _mm_add<int,cyme::avx,4>(simd_trait<int,cyme::avx,4>::register_type xmm0,
                             simd_trait<int,cyme::avx,4>::register_type xmm1){
        #pragma GCC diagnostic push
        #pragma GCC diagnostic ignored "-Wuninitialized"
        __m128i tmp0 = _mm_add_epi32(_mm256_extractf128_si256(xmm0.r0,0),_mm256_extractf128_si256(xmm1.r0,0));
        __m128i tmp1 = _mm_add_epi32(_mm256_extractf128_si256(xmm0.r0,1),_mm256_extractf128_si256(xmm1.r0,1));
        __m128i tmp2 = _mm_add_epi32(_mm256_extractf128_si256(xmm0.r1,0),_mm256_extractf128_si256(xmm1.r1,0));
        __m128i tmp3 = _mm_add_epi32(_mm256_extractf128_si256(xmm0.r1,1),_mm256_extractf128_si256(xmm1.r1,1));
        __m128i tmp4 = _mm_add_epi32(_mm256_extractf128_si256(xmm0.r2,0),_mm256_extractf128_si256(xmm1.r2,0));
        __m128i tmp5 = _mm_add_epi32(_mm256_extractf128_si256(xmm0.r2,1),_mm256_extractf128_si256(xmm1.r2,1));
        __m128i tmp6 = _mm_add_epi32(_mm256_extractf128_si256(xmm0.r3,0),_mm256_extractf128_si256(xmm1.r3,0));
        __m128i tmp7 = _mm_add_epi32(_mm256_extractf128_si256(xmm0.r3,1),_mm256_extractf128_si256(xmm1.r3,1));

        __m256i res0 = _mm256_insertf128_si256(res0, tmp0,0);
                res0 = _mm256_insertf128_si256(res0, tmp1,1);
        __m256i res1 = _mm256_insertf128_si256(res1, tmp2,0);
                res1 = _mm256_insertf128_si256(res1, tmp3,1);
        __m256i res2 = _mm256_insertf128_si256(res2, tmp4,0);
                res2 = _mm256_insertf128_si256(res2, tmp5,1);
        __m256i res3 = _mm256_insertf128_si256(res3, tmp6,0);
                res3 = _mm256_insertf128_si256(res3, tmp7,1);

        #pragma GCC diagnostic pop
        return simd_trait<int,cyme::avx,4>::register_type(res0,res1,res2,res3);
    }

    /**
     Evaluate the the & operator between two registers
     specialisation int,cyme::avx,1 regs
     */
    template<>
    forceinline simd_trait<int,cyme::avx,1>::register_type
    _mm_and<int,cyme::avx,1> (simd_trait<int,cyme::avx,1>::register_type xmm0,
                              simd_trait<int,cyme::avx,1>::register_type xmm1){
        return _mm256_castpd_si256(_mm256_and_pd(_mm256_castsi256_pd(xmm0),_mm256_castsi256_pd(xmm1)));
    }

    /**
     Evaluate the the & operator between two registers
     specialisation int,cyme::avx,2 regs
     */
    template<>
    forceinline simd_trait<int,cyme::avx,2>::register_type
    _mm_and<int,cyme::avx,2> (simd_trait<int,cyme::avx,2>::register_type xmm0,
                              simd_trait<int,cyme::avx,2>::register_type xmm1){
        return simd_trait<int,cyme::avx,2>::register_type(_mm256_castpd_si256(_mm256_and_pd(_mm256_castsi256_pd(xmm0.r0),
                                                                                            _mm256_castsi256_pd(xmm1.r0))),
                                                          _mm256_castpd_si256(_mm256_and_pd(_mm256_castsi256_pd(xmm0.r1),
                                                                                            _mm256_castsi256_pd(xmm1.r1))));
    }

    /**
     Evaluate the the & operator between two registers
     specialisation int,cyme::avx,4 regs
     */
    template<>
    forceinline simd_trait<int,cyme::avx,4>::register_type
    _mm_and<int,cyme::avx,4> (simd_trait<int,cyme::avx,4>::register_type xmm0,
                              simd_trait<int,cyme::avx,4>::register_type xmm1){
        return simd_trait<int,cyme::avx,4>::register_type(_mm256_castpd_si256(_mm256_and_pd(_mm256_castsi256_pd(xmm0.r0),
                                                                                            _mm256_castsi256_pd(xmm1.r0))),
                                                          _mm256_castpd_si256(_mm256_and_pd(_mm256_castsi256_pd(xmm0.r1),
                                                                                            _mm256_castsi256_pd(xmm1.r1))),
                                                          _mm256_castpd_si256(_mm256_and_pd(_mm256_castsi256_pd(xmm0.r2),
                                                                                            _mm256_castsi256_pd(xmm1.r2))),
                                                          _mm256_castpd_si256(_mm256_and_pd(_mm256_castsi256_pd(xmm0.r3),
                                                                                            _mm256_castsi256_pd(xmm1.r3))));
    }


} //end namespace

#endif
