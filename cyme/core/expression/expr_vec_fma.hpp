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

#ifndef CYME_EXPR_VEC_FMA_HPP
#define CYME_EXPR_VEC_FMA_HPP

namespace numeric{
/** \cond I do not need this part in the doc */
   //mul add a*b + c
    template<class T, memory::simd O, int N, class R1, class R2, class R3>
    vec<T,O,N, vec_muladd<T,O,N,R1,R2,R3> >
    inline operator +(vec<T,O,N,vec_mul<T,O,N,R1,R2> >const& a, vec<T,O,N,R3> const& b){
        return  vec<T,O,N,vec_muladd<T,O,N,R1,R2,R3> >(vec_muladd<T,O,N,R1,R2,R3>(a.rep(),b.rep()));
    }

    //mul add a + b*c
    template<class T, memory::simd O, int N, class R1, class R2, class R3>
    vec<T,O,N, vec_muladd<T,O,N,R1,R2,R3> >
    inline operator +(vec<T,O,N,R3> const& b, vec<T,O,N,vec_mul<T,O,N,R1,R2> >const& a){
        return operator+(a,b); //take previous one ^_^, as the addition is commutative 
    }

    //mul add a*b + c*d, I introduce this new case, because the compiler can't distinguish a*b + c*d (ambiguous fma(a,b,c*d) or fma(c,d,a*b)), with the two previous wrappers
    template<class T, memory::simd O, int N, class R1, class R2, class R3, class R4>
    vec<T,O,N, vec_mul_add_mul<T,O,N,R1,R2,R3,R4> >
    inline operator +(vec<T,O,N,vec_mul<T,O,N,R1,R2> >const& a, vec<T,O,N,vec_mul<T,O,N,R3,R4> >const& b){
        return  vec<T,O,N, vec_mul_add_mul<T,O,N,R1,R2,R3,R4> >(vec_mul_add_mul<T,O,N,R1,R2,R3,R4>(a.rep(),b.rep()));
    }

    //mul sub a*b - c
    template<class T, memory::simd O, int N,class R1, class R2, class R3>
    vec<T,O,N, vec_mulsub<T,O,N,R1,R2,R3> >
    inline operator -(vec<T,O,N,vec_mul<T,O,N,R1,R2> >const& a, vec<T,O,N,R3> const& b){
        return  vec<T,O,N, vec_mulsub<T,O,N,R1,R2,R3> >(vec_mulsub<T,O,N,R1,R2,R3>(a.rep(),b.rep()));
    }

    //mul sub a - b*c
    template<class T, memory::simd O, int N, class R1, class R2, class R3>
    vec<T,O,N, vec_negate_muladd<T,O,N,R1,R2,R3> >
    inline operator -(vec<T,O,N,R3> const& a, vec<T,O,N,vec_mul<T,O,N,R1,R2> >const& b){
        return  vec<T,O,N, vec_negate_muladd<T,O,N,R1,R2,R3> >(vec_negate_muladd<T,O,N,R1,R2,R3>(b.rep(),a.rep()));
    }

    //mul add a*b - c*d, I introduce this new case, because the compiler can't distinguish a*b - c*d (ambiguous fms(a,b,c*d) or fms(c,d,a*b)), with the two previous wrappers
    template<class T, memory::simd O, int N,class R1, class R2, class R3, class R4>
    vec<T,O,N, vec_mul_sub_mul<T,O,N,R1,R2,R3,R4> >
    inline operator -(vec<T,O,N,vec_mul<T,O,N,R1,R2> >const& a, vec<T,O,N,vec_mul<T,O,N,R3,R4> >const& b){
        return  vec<T,O,N, vec_mul_sub_mul<T,O,N,R1,R2,R3,R4> >(vec_mul_sub_mul<T,O,N,R1,R2,R3,R4>(a.rep(),b.rep()));
    }
}
#endif
