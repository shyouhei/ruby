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
 * @brief      Defines #ASSUME / #RB_LIKELY / #UNREACHABLE
 */

/* likely */
#if __GNUC__ >= 3
#define RB_LIKELY(x)   (__builtin_expect(!!(x), 1))
#define RB_UNLIKELY(x) (__builtin_expect(!!(x), 0))
#else /* __GNUC__ >= 3 */
#define RB_LIKELY(x)   (x)
#define RB_UNLIKELY(x) (x)
#endif /* __GNUC__ >= 3 */

#ifndef ASSUME
# ifdef UNREACHABLE
#   define ASSUME(x) (RB_LIKELY(!!(x)) ? (void)0 : UNREACHABLE)
# else
#   define ASSUME(x) ((void)(x))
# endif
#endif
#ifndef UNREACHABLE_RETURN
# ifdef UNREACHABLE
#  define UNREACHABLE_RETURN(val) UNREACHABLE
# else
#  define UNREACHABLE_RETURN(val) return (val)
# endif
#endif
#ifndef UNREACHABLE
# define UNREACHABLE ((void)0)  /* unreachable */
#endif
