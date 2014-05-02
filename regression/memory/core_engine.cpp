#include <regression/test_header.hpp>

using namespace cyme::test;

#define TYPE typename T::value_type
#define N T::n
#define ORDER T::order 
#define MAX 1000 

    template<class T, int M>
    struct synapse{
       typedef T value_type;
       static const int value_size = M;
    };

BOOST_AUTO_TEST_CASE_TEMPLATE(core_operator_plus, T, floating_point_block_types) {
    cyme::vector<synapse<TYPE,N>,memory::AoS> block_a(1024);
    cyme::vector<synapse<TYPE,N>,memory::AoSoA> block_b(1024);
    
    init(block_a, block_b);

    typename cyme::vector<synapse<TYPE,N>,memory::AoS>::iterator it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[1]+(*it_AoS)[1];

    typename cyme::vector<synapse<TYPE,N>,memory::AoSoA>::iterator it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[1]+(*it_AoSoA)[1];

    check(block_a, block_b);

    it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[1]+(*it_AoS)[2];

    it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[1]+(*it_AoSoA)[2];

    check(block_a, block_b);

    it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[1]+(*it_AoS)[2]+(*it_AoS)[3];

    it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[1]+(*it_AoSoA)[2]+(*it_AoSoA)[3];

    check(block_a, block_b);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(core_operator_sub, T, floating_point_block_types) {
    cyme::vector<synapse<TYPE,N>,memory::AoS> block_a(1024);
    cyme::vector<synapse<TYPE,N>,memory::AoSoA> block_b(1024);

    init(block_a, block_b);

    typename cyme::vector<synapse<TYPE,N>,memory::AoS>::iterator it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[1]-(*it_AoS)[1];

    typename cyme::vector<synapse<TYPE,N>,memory::AoSoA>::iterator it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[1]-(*it_AoSoA)[1];

    check(block_a, block_b);

    it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[1]-(*it_AoS)[2];

    it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[1]-(*it_AoSoA)[2];

    check(block_a, block_b);

    it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[1]-(*it_AoS)[2]+(*it_AoS)[3];

    it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[1]-(*it_AoSoA)[2]+(*it_AoSoA)[3];
    
    check(block_a, block_b);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(core_operator_mul, T, floating_point_block_types) {
    cyme::vector<synapse<TYPE,N>,memory::AoS> block_a(1024);
    cyme::vector<synapse<TYPE,N>,memory::AoSoA> block_b(1024);

    init(block_a, block_b);

    typename cyme::vector<synapse<TYPE,N>,memory::AoS>::iterator it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[1]*(*it_AoS)[1];

    typename cyme::vector<synapse<TYPE,N>,memory::AoSoA>::iterator it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[1]*(*it_AoSoA)[1];

    check(block_a, block_b);

    it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[1]*(*it_AoS)[2];

    it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[1]*(*it_AoSoA)[2];

    check(block_a, block_b);

    it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[1]*(*it_AoS)[2]*(*it_AoS)[3];

    it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[1]*(*it_AoSoA)[2]*(*it_AoSoA)[3];
    
    check(block_a, block_b);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(core_operator_div, T, floating_point_block_types) {
    cyme::vector<synapse<TYPE,N>,memory::AoS> block_a(1024);
    cyme::vector<synapse<TYPE,N>,memory::AoSoA> block_b(1024);

    init(block_a, block_b);

    typename cyme::vector<synapse<TYPE,N>,memory::AoS>::iterator it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[1]/(*it_AoS)[1];

    typename cyme::vector<synapse<TYPE,N>,memory::AoSoA>::iterator it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[1]/(*it_AoSoA)[1];

    check(block_a, block_b);

    it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[1]/(*it_AoS)[2];

    it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[1]/(*it_AoSoA)[2];

    check(block_a, block_b);

    it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[1]/(*it_AoS)[2]/(*it_AoS)[3];

    it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[1]/(*it_AoSoA)[2]/(*it_AoSoA)[3];
    
    check(block_a, block_b);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(core_operator_add_mul_min_div, T, floating_point_block_types) {
    cyme::vector<synapse<TYPE,N>,memory::AoS> block_a(1024);
    cyme::vector<synapse<TYPE,N>,memory::AoSoA> block_b(1024);

    init(block_a, block_b);

    typename cyme::vector<synapse<TYPE,N>,memory::AoS>::iterator it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[1]+(*it_AoS)[2]*(*it_AoS)[3]-(*it_AoS)[4]/(*it_AoS)[5];

    typename cyme::vector<synapse<TYPE,N>,memory::AoSoA>::iterator it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[1]+(*it_AoSoA)[2]*(*it_AoSoA)[3]-(*it_AoSoA)[4]/(*it_AoSoA)[5];

    check(block_a, block_b);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(core_operator_add_mul_div_min, T, floating_point_block_types) {
    cyme::vector<synapse<TYPE,N>,memory::AoS> block_a(1024);
    cyme::vector<synapse<TYPE,N>,memory::AoSoA> block_b(1024);

    init(block_a, block_b);

    typename cyme::vector<synapse<TYPE,N>,memory::AoS>::iterator it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[1]+(*it_AoS)[2]*(*it_AoS)[3]/(*it_AoS)[4]-(*it_AoS)[5];

    typename cyme::vector<synapse<TYPE,N>,memory::AoSoA>::iterator it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[1]+(*it_AoSoA)[2]*(*it_AoSoA)[3]/(*it_AoSoA)[4]-(*it_AoSoA)[5];

    check(block_a, block_b);
}


BOOST_AUTO_TEST_CASE_TEMPLATE(core_operator_fma_a_mul_b_plus_c, T, floating_point_block_types) {
    cyme::vector<synapse<TYPE,N>,memory::AoS> block_a(1024);
    cyme::vector<synapse<TYPE,N>,memory::AoSoA> block_b(1024);

    init(block_a, block_b);

    typename cyme::vector<synapse<TYPE,N>,memory::AoS>::iterator it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[1]*(*it_AoS)[2]+(*it_AoS)[3];


    typename cyme::vector<synapse<TYPE,N>,memory::AoSoA>::iterator it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[1]*(*it_AoSoA)[2]+(*it_AoSoA)[3];

    check(block_a, block_b);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(core_operator_fma_c_plus_a_mul_b, T, floating_point_block_types) {
    cyme::vector<synapse<TYPE,N>,memory::AoS> block_a(1024);
    cyme::vector<synapse<TYPE,N>,memory::AoSoA> block_b(1024);
    
    init(block_a, block_b);

    typename cyme::vector<synapse<TYPE,N>,memory::AoS>::iterator it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[1]+(*it_AoS)[2]*(*it_AoS)[3];

    typename cyme::vector<synapse<TYPE,N>,memory::AoSoA>::iterator it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[1]+(*it_AoSoA)[2]*(*it_AoSoA)[3];

    check(block_a, block_b);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(core_operator_fma_a_mul_b_plus_c_mul_d, T, floating_point_block_types) {
    cyme::vector<synapse<TYPE,N>,memory::AoS> block_a(1024);
    cyme::vector<synapse<TYPE,N>,memory::AoSoA> block_b(1024);

    init(block_a, block_b);

    typename cyme::vector<synapse<TYPE,N>,memory::AoS>::iterator it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[1]*(*it_AoS)[4]+(*it_AoS)[2]*(*it_AoS)[3];

    typename cyme::vector<synapse<TYPE,N>,memory::AoSoA>::iterator it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[1]*(*it_AoSoA)[4]+(*it_AoSoA)[2]*(*it_AoSoA)[3];

    check(block_a, block_b);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(core_operator_fms_a_mul_b_minus_c, T, floating_point_block_types) {
    cyme::vector<synapse<TYPE,N>,memory::AoS> block_a(1024);
    cyme::vector<synapse<TYPE,N>,memory::AoSoA> block_b(1024);

    init(block_a, block_b);

    typename cyme::vector<synapse<TYPE,N>,memory::AoS>::iterator it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[1]*(*it_AoS)[2]-(*it_AoS)[3];

    typename cyme::vector<synapse<TYPE,N>,memory::AoSoA>::iterator it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[1]*(*it_AoSoA)[2]-(*it_AoSoA)[3];

    check(block_a, block_b);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(core_operator_fms_a_minus_b_mul_c, T, floating_point_block_types) {
    cyme::vector<synapse<TYPE,N>,memory::AoS> block_a(1024);
    cyme::vector<synapse<TYPE,N>,memory::AoSoA> block_b(1024);
    
    init(block_a, block_b);

    typename cyme::vector<synapse<TYPE,N>,memory::AoS>::iterator it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[1]-(*it_AoS)[2]*(*it_AoS)[3];

    typename cyme::vector<synapse<TYPE,N>,memory::AoSoA>::iterator it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[1]-(*it_AoSoA)[2]*(*it_AoSoA)[3];

    check(block_a, block_b);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(core_operator_fms_a_mul_b_minus_c_mul_d, T, floating_point_block_types) {
    cyme::vector<synapse<TYPE,N>,memory::AoS> block_a(1024);
    cyme::vector<synapse<TYPE,N>,memory::AoSoA> block_b(1024);
    
    init(block_a, block_b);

    typename cyme::vector<synapse<TYPE,N>,memory::AoS>::iterator it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[4]*(*it_AoS)[1]-(*it_AoS)[2]*(*it_AoS)[3];

    typename cyme::vector<synapse<TYPE,N>,memory::AoSoA>::iterator it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[4]*(*it_AoSoA)[1]-(*it_AoSoA)[2]*(*it_AoSoA)[3];

    check(block_a, block_b);
}

BOOST_AUTO_TEST_CASE_TEMPLATE(core_operator_bracket_torture, T, floating_point_block_types) {
    cyme::vector<synapse<TYPE,N>,memory::AoS> block_a(1024);
    cyme::vector<synapse<TYPE,N>,memory::AoSoA> block_b(1024);

    init(block_a, block_b);

    typename cyme::vector<synapse<TYPE,N>,memory::AoS>::iterator it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0]   = (((((*it_AoS)[1]+(*it_AoS)[2])+(*it_AoS)[3])+(*it_AoS)[4])+(*it_AoS)[5]);

    typename cyme::vector<synapse<TYPE,N>,memory::AoSoA>::iterator it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (((((*it_AoSoA)[1]+(*it_AoSoA)[2])+(*it_AoSoA)[3])+(*it_AoSoA)[4])+(*it_AoSoA)[5]);

    check(block_a, block_b);

    it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0]   = (((((*it_AoS)[1]-(*it_AoS)[2])-(*it_AoS)[3])-(*it_AoS)[4])-(*it_AoS)[5]);

    it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (((((*it_AoSoA)[1]-(*it_AoSoA)[2])-(*it_AoSoA)[3])-(*it_AoSoA)[4])-(*it_AoSoA)[5]);

    check(block_a, block_b);

    it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0]   = (((((*it_AoS)[1]*(*it_AoS)[2])*(*it_AoS)[3])*(*it_AoS)[4])*(*it_AoS)[5]);

    it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (((((*it_AoSoA)[1]*(*it_AoSoA)[2])*(*it_AoSoA)[3])*(*it_AoSoA)[4])*(*it_AoSoA)[5]);

    check(block_a, block_b);

    it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0]   = (((((*it_AoS)[1]  /(*it_AoS)[2])/(*it_AoS)[3])/(*it_AoS)[4])/(*it_AoS)[5]);

    it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (((((*it_AoSoA)[1]/(*it_AoSoA)[2])/(*it_AoSoA)[3])/(*it_AoSoA)[4])/(*it_AoSoA)[5]);

    check(block_a, block_b);


    it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0]   = (((((*it_AoS)[1]  +(*it_AoS)[2])*(*it_AoS)[3])-(*it_AoS)[4])/(*it_AoS)[5]);

    it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (((((*it_AoSoA)[1]+(*it_AoSoA)[2])*(*it_AoSoA)[3])-(*it_AoSoA)[4])/(*it_AoSoA)[5]);

    check(block_a, block_b);

    it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0]   = ((*it_AoS)[1]  +(*it_AoS)[2])*(*it_AoS)[3]-((*it_AoS)[4]/(*it_AoS)[5]);

    it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = ((*it_AoSoA)[1]+(*it_AoSoA)[2])*(*it_AoSoA)[3]-((*it_AoSoA)[4]/(*it_AoSoA)[5]);

    check(block_a, block_b);
}


BOOST_AUTO_TEST_CASE_TEMPLATE(core_operator_fma_c_plus_a_mul_b_scalar, T, floating_point_block_types) {
    cyme::vector<synapse<TYPE,N>,memory::AoS> block_a(1024);
    cyme::vector<synapse<TYPE,N>,memory::AoSoA> block_b(1024);
    
    init(block_a, block_b);

    typename cyme::vector<synapse<TYPE,N>,memory::AoS>::iterator it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = 1.1+(*it_AoS)[2]*2.2;

    typename cyme::vector<synapse<TYPE,N>,memory::AoSoA>::iterator it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = 1.1+(*it_AoSoA)[2]*2.2;

    check(block_a, block_b);
    
    it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = 1.1+2.2*(*it_AoS)[2];

    it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = 1.1+ 2.2*(*it_AoSoA)[2];

    check(block_a, block_b);
    
    
    it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = 1+(*it_AoS)[2]*2;

    it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = 1+(*it_AoSoA)[2]*2;

    check(block_a, block_b);
    
    it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[2]*2 - 1;

    it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[2]*2 - 1;

    check(block_a, block_b);
    
    it_AoS = block_a.begin();
    for(; it_AoS != block_a.end(); ++it_AoS)
        (*it_AoS)[0] = (*it_AoS)[2]*2.1 - 1.1;

    it_AoSoA = block_b.begin();
    for(; it_AoSoA != block_b.end(); ++it_AoSoA)
        (*it_AoSoA)[0] = (*it_AoSoA)[2]*2.1 - 1.1;

    check(block_a, block_b);
    
}

#undef TYPE
#undef N
#undef MAX
#undef SIZE
