#pragma once
/* Software License Agreement
 * 
 *     Copyright(C) 1994-2023 David Lindauer, (LADSoft)
 * 
 *     This file is part of the Orange C Compiler package.
 * 
 *     The Orange C Compiler package is free software: you can redistribute it and/or modify
 *     it under the terms of the GNU General Public License as published by
 *     the Free Software Foundation, either version 3 of the License, or
 *     (at your option) any later version.
 * 
 *     The Orange C Compiler package is distributed in the hope that it will be useful,
 *     but WITHOUT ANY WARRANTY; without even the implied warranty of
 *     MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *     GNU General Public License for more details.
 * 
 *     You should have received a copy of the GNU General Public License
 *     along with Orange C.  If not, see <http://www.gnu.org/licenses/>.
 * 
 *     contact information:
 *         email: TouchStone222@runbox.com <David Lindauer>
 * 
 */
#include <set>

namespace Optimizer
{

typedef std::set<unsigned> IntSet;

struct BriggsSet
{
    unsigned* indexes;
    unsigned* data;
    int size;
    int top;
};

extern BITINT bittab[BITINTBITS];
//#define TESTBITS
inline BITINT* AllocBit(void*Allocator(int), unsigned size)
{
#ifdef TESTBITS
    auto rv = (BITINT*)Allocator(((size + BITINTBITS) + (BITINTBITS - 1)) / BITINTBITS * sizeof(BITINT));
    *rv++ = ((size + 31) / 32) * 32;
#else
    auto rv = (BITINT*)Allocator(((size) + (BITINTBITS - 1)) / BITINTBITS * sizeof(BITINT));
#endif
    return rv;
}
#    define allocbit(size) AllocBit(oAlloc, size)
#    define lallocbit(size) AllocBit(Alloc, size)
#    define tallocbit(size) AllocBit(tAlloc, size)
#    define sallocbit(size) AllocBit(sAlloc, size)
#    define aallocbit(size) AllocBit(aAlloc, size)
#    define callocbit(size) AllocBit(cAlloc, size)

int isset(BITINT* array, unsigned bit);
void setbit(BITINT* array, unsigned bit);
void clearbit(BITINT* array, unsigned bit);
void bitarrayClear(BITINT* array, unsigned size);

void BitInit(void);
BriggsSet* briggsAlloc(unsigned size);
BriggsSet* briggsAlloct(unsigned size);
BriggsSet* briggsAllocc(unsigned size);
BriggsSet* briggsAllocs(unsigned size);
void briggsFree();
void briggsFreet();
void briggsFreec();
void briggsFrees();
void briggsClear(BriggsSet* p);
int briggsSet(BriggsSet* p, unsigned index);
int briggsReset(BriggsSet* p, unsigned index);
int briggsTest(BriggsSet* p, unsigned index);
int briggsUnion(BriggsSet* s1, BriggsSet* s2);
}  // namespace Optimizer