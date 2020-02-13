/**                                                     \noop-*-C++-*-vi:ft=cpp
 * @file
 * @author     Ruby developers <ruby-core@ruby-lang.org>
 * @copyright  This  file  is   a  part  of  the   programming  language  Ruby.
 *             Permission  is hereby  granted,  to  either redistribute  and/or
 *             modify this file, provided that  the conditions mentioned in the
 *             file COPYING are met.  Consult the file for details.
 * @warning    Symbols   prefixed   with   either  `RUBY3`   or   `ruby3`   are
 *             implementation details.   Don't take  them as canon.  They could
 *             rapidly appear then vanish.  The name (path) of this header file
 *             is also an  implementation detail.  Do not expect  it to persist
 *             at the place it is now.  Developers are free to move it anywhere
 *             anytime at will.
 * @note       To  ruby-core:  remember  that   this  header  can  be  possibly
 *             recursively included  from extension  libraries written  in C++.
 *             Do not  expect for  instance `__VA_ARGS__` is  always available.
 *             We assume C99  for ruby itself but we don't  assume languages of
 *             extension libraries. They could be written in C++98.
 * @brief      Defines #RUBY_ALIGNAS / #RUBY_ALIGNOF
 */
#include "ruby/3/config.h"

#ifndef RUBY_ALIGNAS
#define RUBY_ALIGNAS(x) /* x */
#endif

#ifdef RUBY_ALIGNOF
/* OK, take that definition */
#elif defined(__cplusplus) && (__cplusplus >= 201103L)
#define RUBY_ALIGNOF alignof
#elif defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L)
#define RUBY_ALIGNOF _Alignof
#else
#define RUBY_ALIGNOF(type) ((size_t)offsetof(struct { char f1; type f2; }, f2))
#endif
