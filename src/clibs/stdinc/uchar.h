/* Software License Agreement
 *
 *     Copyright(C) 1994-2020 David Lindauer, (LADSoft)
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
 *     As a special exception, if other files instantiate templates or
 *     use macros or inline functions from this file, or you compile
 *     this file and link it with other works to produce a work based
 *     on this file, this file does not by itself cause the resulting
 *     work to be covered by the GNU General Public License. However
 *     the source code for this file must still be made available in
 *     accordance with section (3) of the GNU General Public License.
 *
 *     This exception does not invalidate any other reasons why a work
 *     based on this file might be covered by the GNU General Public
 *     License.
 *
 *     contact information:
 *         email: TouchStone222@runbox.com <David Lindauer>
 *
 */

#ifndef _UCHAR_H_
#define _UCHAR_H_

#pragma pack(1)

#ifndef __STDDEF_H
#    include <stddef.h>
#endif

#ifdef __cplusplus
extern "C"
{
#endif

#ifndef _MBSTATE_T_DEFINED
#    define _MBSTATE_T_DEFINED
    typedef struct __mbstate_t
    {
        size_t left;
        wint_t value;
    } mbstate_t;
#endif

#ifndef __cplusplus
    typedef __char16_t char16_t;
    typedef __char32_t char32_t;
#endif

    size_t _RTL_FUNC _IMPORT mbrtoc16(char16_t* restrict pc16, const char* ZSTR restrict s, size_t n, mbstate_t* restrict ps);

    size_t _RTL_FUNC _IMPORT c16rtomb(char* ZSTR restrict s, char16_t c16, mbstate_t* restrict ps);
    size_t _RTL_FUNC _IMPORT mbrtoc32(char32_t* restrict pc32, const char* ZSTR restrict s, size_t n, mbstate_t* restrict ps);

    size_t _RTL_FUNC _IMPORT c32rtomb(char* ZSTR restrict s, char32_t c32, mbstate_t* restrict ps);

#ifdef __cplusplus
}
#endif

#pragma pack()

#endif /* _UTIME_H_ */
