dnl Process this file with autoconf to produce a configure script.

AC_PREREQ(2.50)

AC_INIT(swath,
        m4_esyscmd([build-aux/git-version-gen]),
        thai-linux-foss-devel@googlegroups.com)
AC_CONFIG_SRCDIR([src/wordseg.cpp])
AC_CONFIG_MACRO_DIR([m4])

AM_INIT_AUTOMAKE(dist-xz no-dist-gzip)

dnl Checks for programs.
AC_PROG_CXX
AC_PROG_INSTALL
AC_PROG_LN_S
AC_PROG_MAKE_SET
AM_PROG_LIBTOOL
dnl ** to use midatrie **
dnl AC_PATH_PROG(PKG_CONFIG, pkg-config, no)

dnl Checks for libraries.

dnl ** to use midatrie **
dnl dnl midatrie
dnl if test x$PKG_CONFIG != xno; then
dnl   AC_MSG_CHECKING(for midatrie >= 0.3.3)
dnl   if $PKG_CONFIG --exists 'midatrie >= 0.3.3'; then
dnl     AC_MSG_RESULT(yes (`$PKG_CONFIG --modversion midatrie`))
dnl     MIDATRIE_CFLAGS=`$PKG_CONFIG --cflags midatrie`
dnl     MIDATRIE_LIBS=`$PKG_CONFIG --libs midatrie`
dnl   else
dnl     AC_MSG_RESULT(no)
dnl     AC_MSG_ERROR([midatrie >= 0.3.3 missing (maybe, PKG_CONFIG_PATH setting?)])
dnl   fi
dnl fi
dnl AC_SUBST(MIDATRIE_CFLAGS)
dnl AC_SUBST(MIDATRIE_LIBS)

dnl Checks for header files.
AC_HEADER_STDC
AC_CHECK_HEADERS(limits.h malloc.h)

dnl Checks for typedefs, structures, and compiler characteristics.
AC_C_CONST
AC_TYPE_SIZE_T

dnl Checks for library functions.
AC_CHECK_FUNCS(strstr)

dnl Check commandline options
AC_ARG_ENABLE(debug,
              [AC_HELP_STRING([--enable-debug],
                              [enable assertion checks])],
              , enable_debug="no")
if test "x$enable_debug" = "xno"; then
  CPPFLAGS="$CPPFLAGS -DNDEBUG"
fi

AC_ARG_ENABLE(catthai,
              [AC_HELP_STRING([--enable-catthai],
                              [enable catenation of Thai lines])],
              , enable_catthai="no")
if test "x$enable_catthai" = "xyes"; then
  CPPFLAGS="$CPPFLAGS -DCAT_THAI_LINES"
fi

dnl dictionary data generation
AC_ARG_ENABLE(dict,
              [AC_HELP_STRING([--disable-dict],
                              [disable dictionary data generation])],
              , enable_dict="yes")

if test "x$enable_dict" = "xyes"; then
  AC_CHECK_PROGS(TRIETOOL,[trietool-0.2 trietool],no)
  if test "x$TRIETOOL" = "xno"; then
    AC_MSG_ERROR([You need trietool[[-0.2]] (from libdatrie package) to generate dict, or just use --disable-dict to skip])
  fi
fi

AM_CONDITIONAL(ENABLE_DICT,test "x$enable_dict" = "xyes")

dnl Checks for libraries.
PKG_CHECK_MODULES(DATRIE,datrie-0.2)

AC_OUTPUT(
  Makefile
  conv/Makefile
  src/Makefile
  data/Makefile
  tests/Makefile)
