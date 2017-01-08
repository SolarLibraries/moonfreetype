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

/********************************************************************************
 * internal common header                                                       *
 ********************************************************************************/

#ifndef internalDEFINED
#define internalDEFINED

#include <string.h>
#include <stdlib.h>
#include "moonfreetype.h"
#include FT_ADVANCES_H
#include FT_MODULE_H
#include FT_GLYPH_H
#include FT_STROKER_H
#include "tree.h"
#include "udata.h"

/* Note: all the dynamic symbols of this library (should) start with 'moonfreetype_' .
 * The only exception is the luaopen_moonfreetype() function, which is searched for
 * with that name by Lua.
 * MoonFreeType's string references on the Lua registry also start with 'moonfreetype_'.
 */

extern lua_State *moonfreetype_L; /* the global Lua state */

/* Objects' metatabe names */
#define LIBRARY_MT "moonfreetype_library"
#define FACE_MT "moonfreetype_face"
#define GLYPH_MT "moonfreetype_glyph"
#define SIZE_MT "moonfreetype_size"
#define BITMAP_MT "moonfreetype_bitmap"
#define OUTLINE_MT "moonfreetype_outline"
#define STROKER_MT "moonfreetype_stroker"

/* Userdata memory */
#define ud_t moonfreetype_ud_t
typedef struct {
    void *obj; /* the object bound to this userdata */
    FT_Library library; /* the library it belongs to */
    FT_Face face; /* the face it belongs to */
    int allocated;
} moonfreetype_ud_t;

#define newuserdata moonfreetype_newuserdata
ud_t *newuserdata(lua_State *L, void *ptr, const char *mt);
#define freeuserdata moonfreetype_freeuserdata
int freeuserdata(lua_State *L, void *ptr);
#define userdata(ptr) (ud_t*)udata_mem(ptr)
#define userdata_unref(L, ptr) udata_unref((L),(ptr))

#if 0
/* .c */
#define  moonfreetype_
#endif

/* utils.c */
#define noprintf moonfreetype_noprintf
int noprintf(const char *fmt, ...);
#define notavailable moonfreetype_notavailable
int notavailable(lua_State *L, ...);
#define Malloc moonfreetype_Malloc
void *Malloc(lua_State *L, size_t size);
#define Free moonfreetype_Free
void Free(lua_State *L, void *ptr);
#define checkboolean moonfreetype_checkboolean
int checkboolean(lua_State *L, int arg);
#define optboolean moonfreetype_optboolean
int optboolean(lua_State *L, int arg, int d);
#define checkindex moonfreetype_checkindex
int checkindex(lua_State *L, int arg);
#define optindex moonfreetype_optindex
int optindex(lua_State *L, int arg, int optval /* 0-based */);
#define pushindex moonfreetype_pushindex
void pushindex(lua_State *L, int val);
#define checkcharcode moonfreetype_checkcharcode
FT_ULong checkcharcode(lua_State *L, int arg);
#define checkglyphformat moonfreetype_checkglyphformat
unsigned int checkglyphformat(lua_State *L, int arg);
#define pushglyphformat moonfreetype_pushglyphformat
int pushglyphformat(lua_State *L, unsigned int value);
#define pushglyphslot moonfreetype_pushglyphslot
int pushglyphslot(lua_State *L, FT_GlyphSlot glyph);
#define pushglyphmetrics moonfreetype_pushglyphmetrics
int pushglyphmetrics(lua_State *L, FT_Glyph_Metrics metrics);
#define checkvector moonfreetype_checkvector
int checkvector(lua_State *L, int arg, FT_Vector *dst);
#define pushvector moonfreetype_pushvector
int pushvector(lua_State *L, FT_Vector vector);
#define checkmatrix moonfreetype_checkmatrix
int checkmatrix(lua_State *L, int arg, FT_Matrix *dst);
#define pushmatrix moonfreetype_pushmatrix
int pushmatrix(lua_State *L, FT_Matrix matrix);
#define pushbbox moonfreetype_pushbbox
int pushbbox(lua_State *L, FT_BBox bbox);
#define pushsizemetrics moonfreetype_pushsizemetrics
int pushsizemetrics(lua_State *L, FT_Size size);
#define pushbitmapsize moonfreetype_pushbitmapsize
int pushbitmapsize(lua_State *L, FT_Bitmap_Size size);

/* errors.c */
#define nil_fterror moonfreetype_nil_fterror
int nil_fterror(lua_State *L, FT_Error ec);
#define fterrorstring moonfreetype_fterrorstring
const char* fterrorstring(FT_Error ec);

#define CheckError(L, ec) do {                              \
    if(ec) return luaL_error((L), fterrorstring((ec)));     \
} while(0)

/* bitmap.c */
#define freebitmap moonfreetype_freebitmap
int freebitmap(lua_State *L, FT_Bitmap *bitmap);
#define checkbitmap moonfreetype_checkbitmap
FT_Bitmap* checkbitmap(lua_State *L, int arg);
#define pushbitmap moonfreetype_pushbitmap
int pushbitmap(lua_State *L, FT_Bitmap *bitmap, FT_Library library);
#define pushbitmapdata moonfreetype_pushbitmapdata
int pushbitmapdata(lua_State *L, FT_Bitmap bitmap, FT_Int left, FT_Int top, int leftandtop);

/* outline.c */
#define freeoutline moonfreetype_freeoutline
int freeoutline(lua_State *L, FT_Outline *outline);
#define pushoutlinedata moonfreetype_pushoutlinedata
int pushoutlinedata(lua_State *L, FT_Outline outline);
#define checkoutline moonfreetype_checkoutline
FT_Outline* checkoutline(lua_State *L, int arg);
#define pushoutline moonfreetype_pushoutline
int pushoutline(lua_State *L, FT_Outline *outline, FT_Library library);

/* charmap.c */
#define pushcharmap moonfreetype_pushcharmap
int pushcharmap(lua_State *L, FT_CharMap map);
#define platformstring moonfreetype_platformstring
const char* platformstring(unsigned int id);
#define encodingstring moonfreetype_encodingstring
const char* encodingstring(unsigned int platform_id, unsigned int id);

/* library.c */
#define testlibrary moonfreetype_testlibrary
FT_Library* testlibrary(lua_State *L, int arg);
#define checklibrary moonfreetype_checklibrary
FT_Library* checklibrary(lua_State *L, int arg);

/* face.c */
#define newface moonfreetype_newface
int newface(lua_State *L);
#define testface moonfreetype_testface
FT_Face* testface(lua_State *L, int arg);
#define checkface moonfreetype_checkface
FT_Face* checkface(lua_State *L, int arg);
#define freeface moonfreetype_freeface
int freeface(lua_State *L, FT_Face *face);


/* glyph.c */
#define freeglyph moonfreetype_freeglyph
int freeglyph(lua_State *L, FT_Glyph *glyph);

/* stroker.c */
#define checkstroker moonfreetype_checkstroker
FT_Stroker* checkstroker(lua_State *L, int arg);
#define freestroker moonfreetype_freestroker
int freestroker(lua_State *L, FT_Stroker *stroker);

/* size.c */
#define freesize moonfreetype_freesize
int freesize(lua_State *L, FT_Size *size);

/* main.c */
int luaopen_moonfreetype(lua_State *L);
void moonfreetype_open_additional(lua_State *L);
void moonfreetype_open_computations(lua_State *L);
void moonfreetype_open_library(lua_State *L);
void moonfreetype_open_face(lua_State *L);
void moonfreetype_open_glyph(lua_State *L);
void moonfreetype_open_size(lua_State *L);
void moonfreetype_open_variants(lua_State *L);
void moonfreetype_open_advance(lua_State *L);
void moonfreetype_open_pfr(lua_State *L);
void moonfreetype_open_bitmap(lua_State *L);
void moonfreetype_open_outline(lua_State *L);
void moonfreetype_open_stroker(lua_State *L);

/*------------------------------------------------------------------------------*
 | Bitfields and enums                                                          |
 *------------------------------------------------------------------------------*/

#if 0
#define  moonfreetype_
#endif

/* enum.c */
#define checkorientation moonfreetype_checkorientation
unsigned int checkorientation(lua_State *L, int arg);
#define pushorientation moonfreetype_pushorientation
int pushorientation(lua_State *L, unsigned int value);
#define checkstrokerborder moonfreetype_checkstrokerborder
unsigned int checkstrokerborder(lua_State *L, int arg);
#define pushstrokerborder moonfreetype_pushstrokerborder
int pushstrokerborder(lua_State *L, unsigned int value);
#define checkstrokerlinejoin moonfreetype_checkstrokerlinejoin
unsigned int checkstrokerlinejoin(lua_State *L, int arg);
#define pushstrokerlinejoin moonfreetype_pushstrokerlinejoin
int pushstrokerlinejoin(lua_State *L, unsigned int value);
#define checkstrokerlinecap moonfreetype_checkstrokerlinecap
unsigned int checkstrokerlinecap(lua_State *L, int arg);
#define pushstrokerlinecap moonfreetype_pushstrokerlinecap
int pushstrokerlinecap(lua_State *L, unsigned int value);
#define checkglyphbboxmode moonfreetype_checkglyphbboxmode
unsigned int checkglyphbboxmode(lua_State *L, int arg);
#define pushbglyphboxmode moonfreetype_pushbglyphboxmode
int pushbglyphboxmode(lua_State *L, unsigned int value);
#define checktruetypeenginetype moonfreetype_checktruetypeenginetype
unsigned int checktruetypeenginetype(lua_State *L, int arg);
#define pushtruetypeenginetype moonfreetype_pushtruetypeenginetype
int pushtruetypeenginetype(lua_State *L, unsigned int value);
#define checksizerequesttype moonfreetype_checksizerequesttype
unsigned int checksizerequesttype(lua_State *L, int arg);
#define pushsizerequesttype moonfreetype_pushsizerequesttype
int pushsizerequesttype(lua_State *L, unsigned int value);
#define checkkerningmode moonfreetype_checkkerningmode
unsigned int checkkerningmode(lua_State *L, int arg);
#define pushkerningmode moonfreetype_pushkerningmode
int pushkerningmode(lua_State *L, unsigned int value);
#define checkrendermode moonfreetype_checkrendermode
unsigned int checkrendermode(lua_State *L, int arg);
#define pushrendermode moonfreetype_pushrendermode
int pushrendermode(lua_State *L, unsigned int value);
#define checkencoding moonfreetype_checkencoding
unsigned int checkencoding(lua_State *L, int arg);
#define pushencoding moonfreetype_pushencoding
int pushencoding(lua_State *L, unsigned int value);
#define checkpixelmode moonfreetype_checkpixelmode
unsigned int checkpixelmode(lua_State *L, int arg);
#define pushpixelmode moonfreetype_pushpixelmode
int pushpixelmode(lua_State *L, unsigned int value);

/* bitfield.c */
#define checkfstypeflags moonfreetype_checkfstypeflags
unsigned int checkfstypeflags(lua_State *L, int arg);
#define pushfstypeflags moonfreetype_pushfstypeflags
int pushfstypeflags(lua_State *L, unsigned int flags, int pushcode);
#define checksubglyphflags moonfreetype_checksubglyphflags
int checksubglyphflags(lua_State *L, int arg); 
#define pushsubglyphflags moonfreetype_pushsubglyphflags
int pushsubglyphflags(lua_State *L, int flags, int pushcode);
#define checkoutlineflags moonfreetype_checkoutlineflags
int checkoutlineflags(lua_State *L, int arg); 
#define pushoutlineflags moonfreetype_pushoutlineflags
int pushoutlineflags(lua_State *L, int flags, int pushcode);
#define checkloadflags moonfreetype_checkloadflags
FT_Int32 checkloadflags(lua_State *L, int arg);
#define pushloadflags moonfreetype_pushloadflags
int pushloadflags(lua_State *L, FT_Int32 flags, int pushcode);

/*------------------------------------------------------------------------------*
 | Debug and other utilities                                                    |
 *------------------------------------------------------------------------------*/


#define checkoption luaL_checkoption

/* If this is printed, it denotes a suspect bug: */
#define UNEXPECTED_ERROR "unexpected error (%s, %d)", __FILE__, __LINE__
#define unexpected(L) luaL_error((L), UNEXPECTED_ERROR)
#define NOT_AVAILABLE do { return luaL_error(L, "function not available"); } while(0)

#define badvalue(L,s)   lua_pushfstring((L), "invalid value '%s'", (s))

#define NOT_IMPLEMENTED(func)               \
static int func(lua_State *L)               \
    {                                       \
    luaL_error(L, "function "#func" is not implemented");   \
    return 0;                           \
    }

#define NOT_SUPPORTED(func)                 \
static int func(lua_State *L)               \
    {                                       \
    luaL_error(L, "function "#func" is not supported"); \
    return 0;                           \
    }

#if defined(DEBUG)

#define DBG printf

#define TR() do {                                           \
    printf("trace %s %d\n",__FILE__,__LINE__);              \
} while(0)

#define BK() do {                                           \
    printf("break %s %d\n",__FILE__,__LINE__);              \
    getchar();                                              \
} while(0)

#else 

#define DBG noprintf
#define TR()
#define BK()

#endif /* DEBUG */

/*------------------------------------------------------------------------------*
 | Code generators                                                              |
 *------------------------------------------------------------------------------*/

#define CALLBACK_UNREF(cb) do { \
        if((cb) != LUA_NOREF)   { \
            luaL_unref(moonfreetype_L, LUA_REGISTRYINDEX, (cb));    \
            (cb) = LUA_NOREF;   } \
} while(0)

#define VOID_FUNC(func) \
    static int func(lua_State *L) { (void)L; freetype##func(); return 0; }


#endif /* internalDEFINED */
