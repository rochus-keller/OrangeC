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

#include <time.h>
#include <wchar.h>
#include <locale.h>
#include "libp.h"

struct tm* _RTL_FUNC _localtime64(const __time_t_64* time)
{
    struct tm* t;
    __time_t_64 t1 = *time;
    tzset();
    t1 -= _timezone;
    // the *2 is because gmtime adjusts for DST...
    t1 += _daylight * 60 * 60 * 2;
    t = _gmtime64(&t1);
    t->tm_isdst = _daylight;
    return t;
}
struct tm* _RTL_FUNC _localtime32(const __time_t_32* time)
{
    if (*time & 0x80000000)
        return NULL;
    __time_t_64 t = *time;
    return _localtime64(&t);
}
