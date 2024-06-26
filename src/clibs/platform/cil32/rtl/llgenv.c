/*
    Software License Agreement (BSD License)
    
    Copyright (c) 1997-2008, David Lindauer, (LADSoft).
    All rights reserved.
    
    Redistribution and use of this software in source and binary forms, with or without modification, are
    permitted provided that the following conditions are met:
    
    * Redistributions of source code must retain the above
      copyright notice, this list of conditions and the
      following disclaimer.
    
    * Redistributions in binary form must reproduce the above
      copyright notice, this list of conditions and the
      following disclaimer in the documentation and/or other
      materials provided with the distribution.
    
    * Neither the name of LADSoft nor the names of its
      contributors may be used to endorse or promote products
      derived from this software without specific prior
      written permission of LADSoft.
    
    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
    WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
    PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR
    ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
    LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
    INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR
    TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF
    ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <time.h>

using namespace System;
using namespace System::Collections;
using namespace System::Text;
using namespace System::Runtime::InteropServices;

static Object[] keys;
static Object[] values;

int __ll_getenvsize(int id)
{
    if (id >= keys.Length)
        return 0;
    return keys[id].ToString().Length + values[id].ToString().Length + 1;
}
int __ll_getenv(char *buf, int id)
{
    int count = 0 ;
    int rv ;
    IDictionary x = Environment::GetEnvironmentVariables();
    Object[x.Keys.Count] k1;
    Object[x.Values.Count] v1;
    keys = k1;
    values = v1;
    x.Keys.CopyTo(keys, 0);
    x.Values.CopyTo(values, 0);
    if (buf) {
        if (id >= x.Count)
             return 0;
        unsigned char[] key = Encoding::ASCII.GetBytes(keys[id].ToString());
        unsigned char[] value = Encoding::ASCII.GetBytes(values[id].ToString());
	    Marshal::Copy(key, 0, (IntPtr)buf, key.Length);
        buf[key.Length] = '=';
        Marshal::Copy(value, 0, (IntPtr)(buf + key.Length + 1), value.Length);
        buf[key.Length + 1 + value.Length] = 0;
        return 1;
    } else {
        return x.Count ;
    }
}	
