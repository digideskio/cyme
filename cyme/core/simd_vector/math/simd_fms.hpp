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

#ifndef CYME_SIMD_FMS_HPP
#define CYME_SIMD_FMS_HPP

namespace numeric{
    /**
    \brief free function FMS between 3 vectors, only a*b - c, - is not commutative
    */
    template<class T,memory::simd O, int N>
    forceinline vec_simd<T,O,N> mulsub(const vec_simd<T,O,N>& lhs, const vec_simd<T,O,N>& mhs, const vec_simd<T,O,N>& rhs){
        vec_simd<T,O,N> nrv(lhs);
        nrv.ms(mhs,rhs);
        return nrv;
    }

    /**
     \brief free function nFMA 
     */
    template<class T,memory::simd O, int N>
    forceinline vec_simd<T,O,N> negatemulsub(const vec_simd<T,O,N>& lhs, const vec_simd<T,O,N>& mhs, const vec_simd<T,O,N>& rhs){
        vec_simd<T,O,N> nrv(lhs);
        nrv.nms(mhs,rhs);
        return nrv;
    }
} //end namespace

#endif

