/* ioext */
/* Copyright 2020- Hiroshi Hatake*/
/* */
/* Licensed under the Apache License, Version 2.0 (the "License"); */
/* you may not use this file except in compliance with the License. */
/* You may obtain a copy of the License at */
/*     http://www.apache.org/licenses/LICENSE-2.0 */
/* Unless required by applicable law or agreed to in writing, software */
/* distributed under the License is distributed on an "AS IS" BASIS, */
/* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. */
/* See the License for the specific language governing permissions and */
/* limitations under the License. */

#include <ioext.h>

struct IOExt {};

static void ioext_free(void* ioext);

static const rb_data_type_t rb_win_ioext_type = {
  "ioext/c_runtime",
  {
    0,
    ioext_free,
    0,
  },
  NULL,
  NULL,
  RUBY_TYPED_FREE_IMMEDIATELY
};

static void
ioext_free(void* ptr)
{
  xfree(ptr);
}

static VALUE
rb_win_ioext_alloc(VALUE klass)
{
  VALUE obj;
  struct IOExt* ioext;
  obj = TypedData_Make_Struct(
    klass, struct IOExt, &rb_win_ioext_type, ioext);
  return obj;
}

static VALUE
rb_win_ioext_initialize(VALUE self)
{
  return Qnil;
}

static VALUE
rb_win_ioext_getmaxstdio(VALUE self)
{
  return INT2NUM(_getmaxstdio());
}

static VALUE
rb_win_ioext_setmaxstdio(VALUE self, VALUE newmaxfd)
{
  DWORD ret = 0;
  const int fdlimit = 2048;

  ret = _setmaxstdio(min(NUM2INT(newmaxfd), fdlimit));

  return INT2NUM(ret);
}

void
Init_ioext(void)
{
  rb_cIOExt = rb_define_class("IOExt", rb_cObject);
  rb_define_alloc_func(rb_cIOExt, rb_win_ioext_alloc);

  rb_define_const(rb_cIOExt, "IOB_ENTRIES", LONG2NUM(_IOB_ENTRIES));

  rb_define_method(rb_cIOExt, "initialize", rb_win_ioext_initialize, 0);
  rb_define_method(rb_cIOExt, "maxstdio", rb_win_ioext_getmaxstdio, 0);
  rb_define_method(rb_cIOExt, "maxstdio=", rb_win_ioext_setmaxstdio, 1);
  rb_define_method(rb_cIOExt, "setmaxstdio", rb_win_ioext_setmaxstdio, 1);
}
