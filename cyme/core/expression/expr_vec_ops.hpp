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

#ifndef CYME_EXPR_VEC_OPS_HPP
#define CYME_EXPR_VEC_OPS_HPP

namespace numeric{
/** \cond I do not need this part in the doc */

    /* parser for the exp */
    template<class T, memory::simd O, int N, class R1>
    vec<T,O,N,vec_exp<T,O,N,R1> >
    forceinline exp(vec<T,O,N,R1> const& a){
        return vec<T,O,N,vec_exp<T,O,N,R1> >(vec_exp<T,O,N,R1>(a.rep()));
    }

    /* parser for the log */
    template<class T, memory::simd O, int N, class R1>
    vec<T,O,N,vec_log<T,O,N,R1> >
    forceinline log(vec<T,O,N,R1> const& a){
        return vec<T,O,N,vec_log<T,O,N,R1> >(vec_log<T,O,N,R1>(a.rep()));
    }

    /* parser for neg */
    template<class T, memory::simd O, int N, class R1>
    vec<T,O,N,vec_neg<T,O,N,R1> >
    forceinline operator-(vec<T,O,N,R1> const& a){
        return vec<T,O,N,vec_neg<T,O,N,R1> >(vec_neg<T,O,N,R1>(a.rep()));
    }

    /* this is the key of parser, describe every possibilities */
    //addition of two vectors v+w
    template<class T, memory::simd O, int N, class R1, class R2>
    vec<T,O, N,vec_add<T,O,N,R1,R2> >
    forceinline operator +(vec<T,O,N,R1> const& a, vec<T,O,N,R2> const& b){
        return vec<T,O,N,vec_add<T,O,N,R1,R2> >(vec_add<T,O,N,R1,R2>(a.rep(),b.rep()));
    }

    //subtraction of two vectors v-w
    template<class T, memory::simd O, int N, class R1, class R2>
    vec<T,O,N,vec_sub<T,O,N,R1,R2> >
    forceinline operator -(vec<T,O,N,R1> const& a, vec<T,O,N,R2> const& b){
        return vec<T,O,N,vec_sub<T,O,N,R1,R2> >(vec_sub<T,O,N,R1,R2>(a.rep(),b.rep()));
    }

    //division of two vectors v/w
    template<class T, memory::simd O, int N, class R1, class R2>
    vec<T,O,N, vec_div<T,O,N,R1,R2> >
    forceinline operator /(vec<T,O,N,R1> const& a, vec<T,O,N,R2> const& b){
        return vec<T,O,N,vec_div<T,O,N,R1,R2> >(vec_div<T,O,N,R1,R2>(a.rep(),b.rep()));
    }

    //multiplication of two vectors v*w
    template<class T, memory::simd O, int N, class R1, class R2>
    vec<T,O,N, vec_mul<T,O,N,R1,R2> >
    forceinline operator *(vec<T,O,N,R1> const& a, vec<T,O,N,R2> const& b){
        return vec<T,O,N,vec_mul<T,O,N,R1,R2> >(vec_mul<T,O,N,R1,R2>(a.rep(),b.rep()));
    }

    /* OK I give the type because the compiler makes me partial specialization*/
    /* C - TIM TO DO, PLEASE FIND A SOLUTION DUPLICATION IS EVIL */

    //addition of scalar/vector, lambda+v for double, partial specialization are impossible on a single function
    template<class T, memory::simd O, int N, class R2>
    forceinline vec<T,O,N, vec_add<T,O,N,vec_scalar<T,O,N>,R2> >
    operator +(double const& s, vec<T,O,N,R2> const& b){
        return vec<T,O,N, vec_add<T,O,N, vec_scalar<T,O,N>, R2> >(vec_add<T,O,N,vec_scalar<T,O,N>,R2>(vec_scalar<T,O,N>(s),b.rep()));
    }

    //addition of scalar/vector, lambda+v for int
    template<class T, memory::simd O, int N, class R2>
    forceinline vec<T,O,N, vec_add<T,O,N,vec_scalar<T,O,N>,R2> >
    operator +(int const& s, vec<T,O,N,R2> const& b){
        return operator+(static_cast<T>(s),b);// CHECK IF NO COPY
    }

    //v + lambda(double)
    template<class T, memory::simd O, int N, class R2>
    forceinline vec<T,O,N, vec_add<T,O,N,vec_scalar<T,O,N>,R2> >
    operator +(vec<T,O,N,R2> const& b, double const& s){
        return operator+(s,b);// CHECK IF NO COPY
    }

    //v + lambda(int)
    template<class T, memory::simd O, int N, class R2>
    forceinline vec<T,O,N, vec_add<T,O,N,vec_scalar<T,O,N>,R2> >
    operator +(vec<T,O,N,R2> const& b, int const& s){
        return operator+(static_cast<T>(s),b);
    }

    // Tim to Tim FYI A-B != B-A
    //subtraction of scalar/vector, lambda-v for double, partial specialization are impossible on a single function
    template<class T, memory::simd O, int N, class R2>
    forceinline vec<T,O,N, vec_sub<T,O,N, vec_scalar<T,O,N>,R2> >
    operator -(double const& s, vec<T,O,N,R2> const& b){
        return vec<T,O,N, vec_sub<T,O,N, vec_scalar<T,O,N>, R2> >(vec_sub<T,O,N, vec_scalar<T,O,N>,R2>(vec_scalar<T,O,N>(s),b.rep()));
    }

    template<class T, memory::simd O, int N, class R2>
    forceinline vec<T,O,N, vec_sub<T,O,N,R2, vec_scalar<T,O,N> > >
    operator -(vec<T,O,N,R2> const& b,double const& s){
        return vec<T,O,N, vec_sub<T,O,N,R2,vec_scalar<T,O,N> > >(vec_sub<T,O,N,R2,vec_scalar<T,O,N> >(b.rep(),vec_scalar<T,O,N>(s)));
    }

    //subtraction of scalar/vector, lambda-v for int
    template<class T, memory::simd O, int N, class R2>
    forceinline vec<T,O,N, vec_sub<T,O,N, vec_scalar<T,O,N>,R2> >
    operator -(int const& s, vec<T,O,N,R2> const& b){
        return operator-(static_cast<T>(s),b);// CHECK IF NO COPY
    }

    //v - lambda(int)
    template<class T, memory::simd O, int N, class R2>
    forceinline vec<T,O,N, vec_sub<T,O,N,R2,vec_scalar<T,O,N> > >
    operator -(vec<T,O,N,R2> const& b, int const& s){
        return operator-(b,static_cast<T>(s));
    }

    //multiplication of scalar/vector, lambda*v for double, partial specialization are impossible on a single function
    template<class T, memory::simd O, int N, class R2>
    forceinline vec<T,O,N, vec_mul<T,O,N,vec_scalar<T,O,N>,R2> >
    operator *(double const& s, vec<T,O,N,R2> const& b){
        return vec<T,O,N, vec_mul<T,O,N,vec_scalar<T,O,N>, R2> >(vec_mul<T,O,N,vec_scalar<T,O,N>,R2>(vec_scalar<T,O,N>(s),b.rep()));
    }

    //multiplication of scalar/vector, lambda*v for int
    template<class T, memory::simd O, int N, class R2>
    forceinline vec<T,O,N, vec_mul<T,O,N,vec_scalar<T,O,N>,R2> >
    operator *(int const& s, vec<T,O,N,R2> const& b){
        return operator*(static_cast<T>(s),b); 
    }
    
    //v * lambda(double)
    template<class T, memory::simd O, int N, class R2>
    forceinline vec<T,O,N, vec_mul<T,O,N,vec_scalar<T,O,N>,R2> >
    operator *(vec<T,O,N,R2> const& b, double const& s){
        return operator*(s,b);
    }

    //v * lambda(int)
    template<class T, memory::simd O, int N, class R2>
    forceinline vec<T,O,N, vec_mul<T,O,N,vec_scalar<T,O,N>,R2> >
    operator *(vec<T,O,N,R2> const& b, int const& s){
        return operator*(static_cast<T>(s),b);
    }

    // Tim to Tim FYI A/B != B/A
    //division of scalar/vector, lambda*v for double, partial specialization are impossible on a single function
    template<class T, memory::simd O, int N, class R2>
    forceinline vec<T,O,N, vec_div<T,O,N, vec_scalar<T,O,N>,R2> >
    operator /(double const& s, vec<T,O,N,R2> const& b){
        return vec<T,O,N, vec_div<T,O,N,vec_scalar<T,O,N>, R2> >(vec_div<T,O,N,vec_scalar<T,O,N>,R2>(vec_scalar<T,O,N>(s),b.rep()));
    }

    //division of scalar/vector, lambda/v for int
    template<class T, memory::simd O, int N, class R2>
    forceinline vec<T,O,N, vec_div<T,O,N,vec_scalar<T,O,N>,R2> >
    operator /(int const& s, vec<T,O,N,R2> const& b){
        return operator/(static_cast<T>(s),b); 
    }
    
    //v / lambda(double)
    template<class T, memory::simd O, int N, class R2>
    forceinline vec<T,O,N, vec_div<T,O,N, R2,vec_scalar<T,O,N> > >
    operator /(vec<T,O,N, R2> const& b, double const& s){
        return  vec<T,O,N,vec_div<T,O,N,R2,vec_scalar<T,O,N> > >(vec_div<T,O,N,R2,vec_scalar<T,O,N> >(b.rep(),vec_scalar<T,O,N>(s)));
    }

    //v / lambda(int)
    template<class T, memory::simd O, int N, class R2>
    forceinline vec<T,O,N, vec_div<T,O,N,vec_scalar<T,O,N>,R2> >
    operator /(vec<T,O,N,R2> const& b, int const& s){
        return operator/(b,static_cast<T>(s));
    }
/** \endcond I do not need this part in the doc */
}
    
#endif
