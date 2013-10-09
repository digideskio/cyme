/*
 * CYME, License
 * 
 * Timothee Ewart - Swiss Federal Institute of technology in Lausanne 
 * 
 * Permission is hereby granted, free of charge, to any person or organization
 * obtaining a copy of the software and accompanying documentation covered by
 * this license (the "Software") to use, reproduce, display, distribute,
 * execute, and transmit the Software, and to prepare derivative works of the
 * Software, and to permit third-parties to whom the Software is furnished to
 * do so, all subject to the following:
 * 
 * The copyright notices in the Software and this entire statement, including
 * the above license grant, this restriction and the following disclaimer,
 * must be included in all copies of the Software, in whole or in part, and
 * all derivative works of the Software, unless such copies or derivative
 * works are solely in the form of machine-executable object code generated by
 * a source language processor.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
 * SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
 * FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
 * ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
 * DEALINGS IN THE SOFTWARE.
 */

#ifndef CYME_SIMD_WRAPPER_MIC_HPP
#define CYME_SIMD_WRAPPER_MIC_HPP

namespace numeric{
    /*  -------------------------------------------------------------------------------------------------------------------- double */
    template<>
    inline typename simd_trait<double,memory::mic>::register_type _mm_load1<double,memory::mic>(typename simd_trait<double,memory::mic>::register_type xmm0, typename simd_trait<double,memory::mic>::value_type a){
        __m128d a_vec = _mm_load_pd(a);
        __mmask8 k = 0xff; // mask to 1 the value is broadcast everywhere in the register
        return (xmm0 = _mm512_maskz_broadcastsd_pd(k,a_vec));
    }
   
    template<>
    inline typename simd_trait<double,memory::mic>::register_type _mm_load<double,memory::mic>(typename simd_trait<double,memory::mic>::register_type xmm0, typename simd_trait<double,memory::mic>::const_pointer a){
        return (xmm0 = _mm512_load_pd(a)); 
    }

    template<>
    void _mm_store<double,memory::mic>(typename simd_trait<double,memory::mic>::register_type xmm0, typename simd_trait<double,memory::mic>::pointer a){
        _mm512_store_pd(a,xmm0); 
    }
   
    template<>
    inline typename simd_trait<double,memory::mic>::register_type _mm_mul<double,memory::mic>(typename simd_trait<double,memory::mic>::register_type xmm0, typename simd_trait<double,memory::mic>::register_type xmm1){
        return (xmm0 = _mm512_mul_pd(xmm0, xmm1));
    };
   
    template<>
    inline typename simd_trait<double,memory::mic>::register_type _mm_div<double,memory::mic>(typename simd_trait<double,memory::mic>::register_type xmm0, typename simd_trait<double,memory::mic>::register_type xmm1){
        return (xmm0 = _mm512_div_pd(xmm0, xmm1));
    };
   
    template<>
    inline typename simd_trait<double,memory::mic>::register_type _mm_add<double,memory::mic>(typename simd_trait<double,memory::mic>::register_type xmm0, typename simd_trait<double,memory::mic>::register_type xmm1){
        return (xmm0 = _mm512_add_pd(xmm0, xmm1));
    };

    template<>
    inline typename simd_trait<double,memory::mic>::register_type _mm_sub<double,memory::mic>(typename simd_trait<double,memory::mic>::register_type xmm0, typename simd_trait<double,memory::mic>::register_type xmm1){
        return (xmm0 = _mm512_sub_pd(xmm0, xmm1));
    };

    template<>
    inline typename simd_trait<double,memory::mic>::register_type _mm_exp<double,memory::mic>(typename simd_trait<double,memory::mic>::register_type xmm0){
        return (xmm0 = _mm512_exp_pd(xmm0));
    };

   template<>
    inline typename simd_trait<double,memory::mic>::register_type _mm_fma<double,memory::mic>(typename simd_trait<double,memory::mic>::register_type xmm0, typename simd_trait<double,memory::mic>::register_type xmm1, typename simd_trait<double,memory::mic>::register_type xmm2){
        return (xmm0 = _mm512_fmadd_pd(xmm0, xmm1, xmm2));
    };

    template<>
    inline typename simd_trait<double,memory::mic>::register_type _mm_fms<double,memory::mic>(typename simd_trait<double,memory::mic>::register_type xmm0, typename simd_trait<double,memory::mic>::register_type xmm1, typename simd_trait<double,memory::mic>::register_type xmm2){
        return (xmm0 = _mm512_fmsub_pd(xmm0, xmm1, xmm2));
    };
    
    /*  -------------------------------------------------------------------------------------------------------------------- float */
    template<>
    typename simd_trait<float,memory::mic>::register_type _mm_load1<float,memory::mic>(typename simd_trait<float,memory::mic>::register_type xmm0, typename simd_trait<float,memory::mic>::value_type a){
        __m128 a_vec = _mm_load_ps(a);
        __mmask16 k = 0xffff; // mask to 1 (or -1 ^_^) the value is broadcast everywhere in the register
        return (xmm0 = _mm512_maskz_broadcastsd_pd(k,a_vec));
        return (xmm0 = _mm512_broadcast_ss(&a)); 
    }
   
    template<>
    typename simd_trait<float,memory::mic>::register_type _mm_load<float,memory::mic>(typename simd_trait<float,memory::mic>::register_type xmm0, typename simd_trait<float,memory::mic>    ::const_pointer a){
        return (xmm0 = _mm512_load_ps(a)); 
    }

    template<>
    void _mm_store<float,memory::mic>(typename simd_trait<float,memory::mic>::register_type xmm0, typename simd_trait<float,memory::mic>::pointer a){
        _mm512_store_ps(a,xmm0); 
    }
   
    template<>
    inline typename simd_trait<float,memory::mic>::register_type _mm_mul<float,memory::mic>(typename simd_trait<float,memory::mic>::register_type xmm0, typename simd_trait<float,memory::mic>::register_type xmm1){
        return (xmm0 = _mm512_mul_ps(xmm0, xmm1));
    }
   
    template<>
    inline typename simd_trait<float,memory::mic>::register_type _mm_div<float,memory::mic>(typename simd_trait<float,memory::mic>::register_type xmm0, typename simd_trait<float,memory::mic>::register_type xmm1){
        return (xmm0 = _mm512_div_ps(xmm0, xmm1));
    };
   
    template<>
    inline typename simd_trait<float,memory::mic>::register_type _mm_add<float,memory::mic>(typename simd_trait<float,memory::mic>::register_type xmm0, typename simd_trait<float,memory::mic>::register_type xmm1){
        return (xmm0 = _mm512_add_ps(xmm0, xmm1));
    };

    template<>
    inline typename simd_trait<float,memory::mic>::register_type _mm_sub<float,memory::mic>(typename simd_trait<float,memory::mic>::register_type xmm0, typename simd_trait<float,memory::mic>::register_type xmm1){
        return (xmm0 = _mm512_sub_ps(xmm0, xmm1));
    };

    template<>
    inline typename simd_trait<float,memory::mic>::register_type _mm_exp<float,memory::mic>(typename simd_trait<float,memory::mic>::register_type xmm0){
        return (xmm0 = _mm512_exp_ps(xmm0));
    };
    
    template<>
    inline typename simd_trait<float,memory::mic>::register_type _mm_fma<float,memory::mic>(typename simd_trait<float,memory::mic>::register_type xmm0, typename simd_trait<float,memory::mic>::register_type xmm1, typename simd_trait<float,memory::mic>::register_type xmm2){
        return (xmm0 = _mm512_fmadd_ps(xmm0, xmm1, xmm2));
    };

    template<>
    inline typename simd_trait<float,memory::mic>::register_type _mm_fms<float,memory::mic>(typename simd_trait<float,memory::mic>::register_type xmm0, typename simd_trait<float,memory::mic>::register_type xmm1, typename simd_trait<float,memory::mic>::register_type xmm2){
        return (xmm0 = _mm512_fmsub_ps(xmm0, xmm1, xmm2));
    };
} //end namespace 

#endif 
