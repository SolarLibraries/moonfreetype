package = "moonfreetype"
version = "dev-1"
source = {
    url = "git+https://github.com/SolarLibraries/moonfreetype.git"
}
description = {
    detailed = [[
MoonFreeType is a Lua binding library for the 
[FreeType library](https://www.freetype.org/).]],
    homepage = "https://github.com/SolarLibraries/moonfreetype",
    license = "MIT/X11"
}
dependencies = {
    "lua >= 5.1, < 5.5"
}
external_dependencies = {
    FREETYPE = {
        header = "freetype2/ft2build.h",
        library = "freetype"
    }
}
build = {
    type = "builtin",
    modules = {
        moonfreetype = {
            sources = {
                "src/advance.c",
                "src/bitmap.c",
                "src/charmap.c",
                "src/compat-5.3.c",
                "src/computations.c",
                "src/enums.c",
                "src/errors.c",
                "src/face.c",
                "src/flags.c",
                "src/glyph.c",
                "src/library.c",
                "src/main.c",
                "src/outline.c",
                "src/pfr.c",
                "src/size.c",
                "src/stroker.c",
                "src/udata.c",
                "src/utils.c",
                "src/variants.c",
            },

            incdirs = {
                "src/",
                "$(FREETYPE_INCDIR)/freetype2"
            },
            libdirs = {
                "$(FREETYPE_LIBDIR)"
            },
            libraries = {
                "freetype"
            }
        },
    },
    copy_directories = {
        "doc", "examples"
    }
}
