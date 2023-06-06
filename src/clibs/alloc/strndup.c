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

/*
 * strdup.c
 */

#include <stdlib.h>
#include <string.h>

char* _RTL_FUNC strndup(const char* string, size_t count)
{
    int n;
    for (n=0; n < count; n++)
        if (!string[n])
            break;  
    char* rv = malloc(n + 1);
    if (rv)
    {
        strncpy(rv, string, n);
        rv[n] = 0;
    }
    return rv;
}

char* _RTL_FUNC _strndup(const char* string, size_t count) { return strndup(string, count); }