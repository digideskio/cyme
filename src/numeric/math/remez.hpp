/*
 * CoreBluron, License
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

#ifndef COREBLURON_REMEZ_HPP
#define COREBLURON_REMEZ_HPP


namespace numeric{
    // T is a vector/basic type so the value_type will fail for basic type (float/double). I need a trait class.
    template <class T>
    struct remez_trait{
        typedef typename T::value_type value_type;
    };
 
    template<>
    struct remez_trait<double>{
        typedef double value_type;
    };
    
    template<>
    struct remez_trait<float>{
        typedef float value_type;
    };

    //just encapsulate the number of coeff
    struct coeff_remez_number{
        static const std::size_t value = 20;
    };


    // no C++ 11, so no constexpr into structure for double/float, ^.^ just partial specialization
    template<class T, std::size_t n>
    struct coeff_remez;
    
    template<class T>
    struct coeff_remez<T,0>{
        const static inline typename remez_trait<T>::value_type coeff() {return 1.000000953288283335452191461655224410237;}
    };
    
    template<class T>
    struct coeff_remez<T,1>{
        const static inline typename remez_trait<T>::value_type coeff() {return 9.999987386107006669941961264349482393695e-1;}
    };
    
    template<class T>
    struct coeff_remez<T,2>{
        const static inline typename remez_trait<T>::value_type coeff() {return 4.999958838139845502002270787636339014924e-1;}
    };
    
    template<class T>
    struct coeff_remez<T,3>{
        const static inline typename remez_trait<T>::value_type coeff() {return 1.666686904005461957579197011816065192715e-1;}
    };

    template<class T>
    struct coeff_remez<T,4>{
        const static inline typename remez_trait<T>::value_type coeff() {return 4.166950043813903108603707567016329683468e-2;}
    };

    template<class T>
    struct coeff_remez<T,5>{
        const static inline typename remez_trait<T>::value_type coeff() {return 8.332279835011092412371558098627564052965e-3;}
    };
    
    template<class T>
    struct coeff_remez<T,6>{
        const static inline typename remez_trait<T>::value_type coeff() {return 1.388174402760494398109623056452802191184e-3;}
    };
    
    template<class T>
    struct coeff_remez<T,7>{
        const static inline typename remez_trait<T>::value_type coeff() {return 1.986723355158949957796384995837872477569e-4;}
    };
    
    template<class T>
    struct coeff_remez<T,8>{
        const static inline typename remez_trait<T>::value_type coeff() {return 2.488281528091228796914932062104412021000e-5;}
    };
    
    template<class T>
    struct coeff_remez<T,9>{
        const static inline typename remez_trait<T>::value_type coeff() {return 2.721444948692314358199963677469028805934e-6;}
    };
    
    template<class T>
    struct coeff_remez<T,10>{
        const static inline typename remez_trait<T>::value_type coeff() {return 2.717140499194528339405001244995537746744e-7;}
    };
    
    template<class T>
    struct coeff_remez<T,11>{
        const static inline typename remez_trait<T>::value_type coeff() {return 2.756733556244288109757183650072746680348e-8;}
    };
    
    template<class T>
    struct coeff_remez<T,12>{
        const static inline typename remez_trait<T>::value_type coeff() {return 2.070417462579269627749603630995991796024e-9;}
    };
    
    template<class T>
    struct coeff_remez<T,13>{
        const static inline typename remez_trait<T>::value_type coeff() {return 6.184288350463214213567547267865497876970e-11;}
    };
    
    template<class T>
    struct coeff_remez<T,14>{
        const static inline typename remez_trait<T>::value_type coeff() {return 2.046160013036850218452969327668798874891e-11;}
    };

    template<class T>
    struct coeff_remez<T,15>{
        const static inline typename remez_trait<T>::value_type coeff() {return 2.446352603577699100102834867635630630022e-12;}
    };

    template<class T>
    struct coeff_remez<T,16>{
        const static inline typename remez_trait<T>::value_type coeff() {return 2.718484761673811998575811326820787730345e-13;}
    };
    
    template<class T>
    struct coeff_remez<T,17>{
        const static inline typename remez_trait<T>::value_type coeff() {return 5.429682151023236105458123297693967405137e-15;}
    };
    
    template<class T>
    struct coeff_remez<T,18>{
        const static inline typename remez_trait<T>::value_type coeff() {return -3.473328569109608198516933463416425515192e-15;}
    };
    
    template<class T>
    struct coeff_remez<T,19>{
        const static inline typename remez_trait<T>::value_type coeff() {return -2.986053770607522240220173985268369196403e-16;}
    };

    template<class T>
    struct coeff_remez<T,20>{
        const static inline typename remez_trait<T>::value_type coeff() {return 9.972590824455150104899742103044752031096e-18;}
    };
} //end namespace 

#endif 
