/*
 * opencog/atomspace/types.h
 *
 * Copyright (C) 2002-2007 Novamente LLC
 * All Rights Reserved
 *
 * Written by Thiago Maia <thiago@vettatech.com>
 *            Andre Senna <senna@vettalabs.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Affero General Public License v3 as
 * published by the Free Software Foundation and including the exceptions
 * at http://opencog.org/wiki/Licenses
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Affero General Public License
 * along with this program; if not, write to:
 * Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

/**
 * basic type definitions.
 */

#ifndef _OPENCOG_TYPES_H
#define _OPENCOG_TYPES_H

#include <boost/variant.hpp>

#include <opencog/atomspace/Handle.h>

namespace opencog
{
/** \addtogroup grp_atomspace
 *  @{
 */

class Atom;

//! type of Atoms, represented as short integer (16 bits)
typedef unsigned short Type;
//! arity of Atoms, represented as short integer (16 bits)
typedef unsigned short Arity;
//! stimulus
typedef short stim_t;

typedef boost::variant<Handle, Type, int, unsigned int, float, bool,
                       unsigned char, char, short int> Vertex;

typedef std::vector<Vertex> VertexSeq;

class HandlePredicate {
public:
    inline bool operator()(const Handle& h) { return this->test(h); }
    virtual bool test(const Handle& h) { return true; }
};
class AtomPredicate {
public:
    inline bool operator()(const Atom& a) { return this->test(a); }
    virtual bool test(const Atom&) { return true; }
};
class AtomComparator {
public:
    inline bool operator()(const Atom& a,const Atom& b) { return this->test(a,b); }
    virtual bool test(const Atom&,const Atom&) { return true; }
};


/** @}*/
} // namespace opencog

#endif // _OPENCOG_TYPES_H
