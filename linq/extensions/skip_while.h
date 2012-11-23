/*=============================================================================
    Copyright (c) 2012 Paul Fultz II
    skip_while.h
    Distributed under the Boost Software License, Version 1.0. (See accompanying
    file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)
==============================================================================*/

#ifndef LINQ_GUARD_EXTENSIONS_SKIP_WHILE_H
#define LINQ_GUARD_EXTENSIONS_SKIP_WHILE_H

#include <linq/extensions/extension.h>
#include <boost/range.hpp>
#include <boost/range/algorithm/find_if.hpp>

namespace linq { 
namespace detail {
struct skip_while_t
{
    template<class Range, class Predicate>
    auto operator()(Range && r, Predicate p) LINQ_RETURNS(boost::make_reverse_iterator(boost::find_if(r, p). boost::end(r)));
};
}
namespace {
range_extension<detail::skip_while_t> skip_while = {};
}

}

#endif