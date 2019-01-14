#include "UnweightedGraph.h"
#define BOOST_TEST_MODULE "Unweighted graphs test"
//#define BOOST_TEST_DYN_LINK
#include <boost/test/unit_test.hpp>
//#include <boost/test/included/unit_test.hpp>

BOOST_AUTO_TEST_CASE(first_test)
{
    UnweightedGraph<int> g;
//    BOOST_TEST(g.adjacency_list.size() == 0);
    int i = 0;
    BOOST_TEST(i == 0);
}