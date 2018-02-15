/*
 * Copyright (c) 1997, 2016, Oracle and/or its affiliates. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 only, as
 * published by the Free Software Foundation.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * You should have received a copy of the GNU General Public License version
 * 2 along with this work; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA.
 *
 * Please contact Oracle, 500 Oracle Parkway, Redwood Shores, CA 94065 USA
 * or visit www.oracle.com if you need additional information or have any
 * questions.
 *
 */

#ifndef SHARE_VM_OOPS_TYPEARRAYOOP_INLINE_HPP
#define SHARE_VM_OOPS_TYPEARRAYOOP_INLINE_HPP

#include "oops/access.inline.hpp"
#include "oops/oop.inline.hpp"
#include "oops/typeArrayOop.hpp"

int typeArrayOopDesc::object_size() {
  TypeArrayKlass* tk = TypeArrayKlass::cast(klass());
  return object_size(tk->layout_helper(), length());
}

inline jbyte typeArrayOopDesc::byte_at(int which) const {
  ptrdiff_t offset = element_offset<jbyte>(T_BYTE, which);
  return HeapAccess<IN_HEAP_ARRAY>::load_at(as_oop(), offset);
}
inline void typeArrayOopDesc::byte_at_put(int which, jbyte contents) {
  ptrdiff_t offset = element_offset<jbyte>(T_BYTE, which);
  HeapAccess<IN_HEAP_ARRAY>::store_at(as_oop(), offset, contents);
}

inline jboolean typeArrayOopDesc::bool_at(int which) const {
  ptrdiff_t offset = element_offset<jboolean>(T_BOOLEAN, which);
  return HeapAccess<IN_HEAP_ARRAY>::load_at(as_oop(), offset);
}
inline void typeArrayOopDesc::bool_at_put(int which, jboolean contents) {
  ptrdiff_t offset = element_offset<jboolean>(T_BOOLEAN, which);
  HeapAccess<IN_HEAP_ARRAY>::store_at(as_oop(), offset, ((jint)contents) & 1);
}

inline jchar typeArrayOopDesc::char_at(int which) const {
  ptrdiff_t offset = element_offset<jchar>(T_CHAR, which);
  return HeapAccess<IN_HEAP_ARRAY>::load_at(as_oop(), offset);
}
inline void typeArrayOopDesc::char_at_put(int which, jchar contents) {
  ptrdiff_t offset = element_offset<jchar>(T_CHAR, which);
  HeapAccess<IN_HEAP_ARRAY>::store_at(as_oop(), offset, contents);
}

inline jint typeArrayOopDesc::int_at(int which) const {
  ptrdiff_t offset = element_offset<jint>(T_INT, which);
  return HeapAccess<IN_HEAP_ARRAY>::load_at(as_oop(), offset);
}
inline void typeArrayOopDesc::int_at_put(int which, jint contents) {
  ptrdiff_t offset = element_offset<jint>(T_INT, which);
  HeapAccess<IN_HEAP_ARRAY>::store_at(as_oop(), offset, contents);
}

inline jshort typeArrayOopDesc::short_at(int which) const {
  ptrdiff_t offset = element_offset<jshort>(T_SHORT, which);
  return HeapAccess<IN_HEAP_ARRAY>::load_at(as_oop(), offset);
}
inline void typeArrayOopDesc::short_at_put(int which, jshort contents) {
  ptrdiff_t offset = element_offset<jshort>(T_BOOLEAN, which);
  HeapAccess<IN_HEAP_ARRAY>::store_at(as_oop(), offset, contents);
}

inline jushort typeArrayOopDesc::ushort_at(int which) const {
  ptrdiff_t offset = element_offset<jushort>(T_SHORT, which);
  return HeapAccess<IN_HEAP_ARRAY>::load_at(as_oop(), offset);
}
inline void typeArrayOopDesc::ushort_at_put(int which, jushort contents) {
  ptrdiff_t offset = element_offset<jushort>(T_SHORT, which);
  HeapAccess<IN_HEAP_ARRAY>::store_at(as_oop(), offset, contents);
}

inline jlong typeArrayOopDesc::long_at(int which) const {
  ptrdiff_t offset = element_offset<jlong>(T_LONG, which);
  return HeapAccess<IN_HEAP_ARRAY>::load_at(as_oop(), offset);
}
inline void typeArrayOopDesc::long_at_put(int which, jlong contents) {
  ptrdiff_t offset = element_offset<jlong>(T_LONG, which);
  HeapAccess<IN_HEAP_ARRAY>::store_at(as_oop(), offset, contents);
}

inline jfloat typeArrayOopDesc::float_at(int which) const {
  ptrdiff_t offset = element_offset<jfloat>(T_FLOAT, which);
  return HeapAccess<IN_HEAP_ARRAY>::load_at(as_oop(), offset);
}
inline void typeArrayOopDesc::float_at_put(int which, jfloat contents) {
  ptrdiff_t offset = element_offset<jfloat>(T_FLOAT, which);
  HeapAccess<IN_HEAP_ARRAY>::store_at(as_oop(), offset, contents);
}

inline jdouble typeArrayOopDesc::double_at(int which) const {
  ptrdiff_t offset = element_offset<jdouble>(T_DOUBLE, which);
  return HeapAccess<IN_HEAP_ARRAY>::load_at(as_oop(), offset);
}
inline void typeArrayOopDesc::double_at_put(int which, jdouble contents) {
  ptrdiff_t offset = element_offset<jdouble>(T_DOUBLE, which);
  HeapAccess<IN_HEAP_ARRAY>::store_at(as_oop(), offset, contents);
}

inline jbyte typeArrayOopDesc::byte_at_acquire(int which) const {
  ptrdiff_t offset = element_offset<jbyte>(T_BYTE, which);
  return HeapAccess<MO_ACQUIRE | IN_HEAP_ARRAY>::load_at(as_oop(), offset);
}
inline void typeArrayOopDesc::release_byte_at_put(int which, jbyte contents) {
  ptrdiff_t offset = element_offset<jbyte>(T_BYTE, which);
  HeapAccess<MO_RELEASE | IN_HEAP_ARRAY>::store_at(as_oop(), offset, contents);
}

// Java thinks Symbol arrays are just arrays of either long or int, since
// there doesn't seem to be T_ADDRESS, so this is a bit of unfortunate
// casting
#ifdef _LP64
inline Symbol* typeArrayOopDesc::symbol_at(int which) const {
  ptrdiff_t offset = element_offset<jlong>(T_LONG, which);
  return (Symbol*)(jlong) HeapAccess<IN_HEAP_ARRAY>::load_at(as_oop(), offset);
}
inline void typeArrayOopDesc::symbol_at_put(int which, Symbol* contents) {
  ptrdiff_t offset = element_offset<jlong>(T_LONG, which);
  HeapAccess<IN_HEAP_ARRAY>::store_at(as_oop(), offset, (jlong)contents);
}
#else
inline Symbol* typeArrayOopDesc::symbol_at(int which) const {
  ptrdiff_t offset = element_offset<jint>(T_INT, which);
  return (Symbol*)(jint) HeapAccess<IN_HEAP_ARRAY>::load_at(as_oop(), offset);
}
inline void typeArrayOopDesc::symbol_at_put(int which, Symbol* contents) {
  ptrdiff_t offset = element_offset<jint>(T_INT, which);
  HeapAccess<IN_HEAP_ARRAY>::store_at(as_oop(), offset, (jint)contents);
}
#endif // _LP64


#endif // SHARE_VM_OOPS_TYPEARRAYOOP_INLINE_HPP
