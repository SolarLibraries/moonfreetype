/* The MIT License (MIT)
 *
 * Copyright (c) 2017 Stefano Trettel
 *
 * Software repository: MoonFreeType, https://github.com/stetre/moonfreetype
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */


#ifdef __cplusplus
extern "C" {
#endif

#include "lua.h"
#include "lauxlib.h"

#define udata_t  moonfreetype_udata_t
#define udata_s  moonfreetype_udata_s
#define moonfreetype_udata_t struct moonfreetype_udata_s

#define udata_new moonfreetype_udata_new
void *udata_new(lua_State*, size_t, const void*, const char*);
#define udata_unref moonfreetype_udata_unref
int udata_unref(lua_State *L, const void *ptr);
#define udata_free moonfreetype_udata_free
int udata_free(lua_State*, const void*);
#define udata_mem moonfreetype_udata_mem
void *udata_mem(const void*);
#define udata_push moonfreetype_udata_push
int udata_push(lua_State*, const void*);
#define udata_free_all moonfreetype_udata_free_all
void udata_free_all(void);
#define udata_scan moonfreetype_udata_scan
void udata_scan(lua_State *L, const char *mt, void *info, int (*func)(lua_State *L, const void *ptr, const void *info));

#define udata_define moonfreetype_udata_define
int udata_define(lua_State*, const char*, const luaL_Reg*, const luaL_Reg*);
#define udata_inherit moonfreetype_udata_inherit
int udata_inherit(lua_State*, const char*, const char*);
#define udata_test moonfreetype_udata_test
void *udata_test(lua_State*, int, const char*);
#define udata_addmethods moonfreetype_udata_addmethods
int udata_addmethods(lua_State*, const char*, const luaL_Reg*);

#ifdef __cplusplus
}
#endif

