// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: sys.proto

#ifndef PROTOBUF_sys_2eproto__INCLUDED
#define PROTOBUF_sys_2eproto__INCLUDED

#include <string>

#include <google/protobuf/stubs/common.h>

#if GOOGLE_PROTOBUF_VERSION < 2006000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please update
#error your headers.
#endif
#if 2006000 < GOOGLE_PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers.  Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>
#include <google/protobuf/extension_set.h>
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)

namespace sys {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_sys_2eproto();
void protobuf_AssignDesc_sys_2eproto();
void protobuf_ShutdownFile_sys_2eproto();

class PING;
class TEST;
class GM;

// ===================================================================

class PING : public ::google::protobuf::Message {
 public:
  PING();
  virtual ~PING();

  PING(const PING& from);

  inline PING& operator=(const PING& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const PING& default_instance();

  void Swap(PING* other);

  // implements Message ----------------------------------------------

  PING* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const PING& from);
  void MergeFrom(const PING& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional int32 st = 1 [default = 0];
  inline bool has_st() const;
  inline void clear_st();
  static const int kStFieldNumber = 1;
  inline ::google::protobuf::int32 st() const;
  inline void set_st(::google::protobuf::int32 value);

  // @@protoc_insertion_point(class_scope:sys.PING)
 private:
  inline void set_has_st();
  inline void clear_has_st();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::int32 st_;
  friend void  protobuf_AddDesc_sys_2eproto();
  friend void protobuf_AssignDesc_sys_2eproto();
  friend void protobuf_ShutdownFile_sys_2eproto();

  void InitAsDefaultInstance();
  static PING* default_instance_;
};
// -------------------------------------------------------------------

class TEST : public ::google::protobuf::Message {
 public:
  TEST();
  virtual ~TEST();

  TEST(const TEST& from);

  inline TEST& operator=(const TEST& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const TEST& default_instance();

  void Swap(TEST* other);

  // implements Message ----------------------------------------------

  TEST* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const TEST& from);
  void MergeFrom(const TEST& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string str = 1 [default = ""];
  inline bool has_str() const;
  inline void clear_str();
  static const int kStrFieldNumber = 1;
  inline const ::std::string& str() const;
  inline void set_str(const ::std::string& value);
  inline void set_str(const char* value);
  inline void set_str(const char* value, size_t size);
  inline ::std::string* mutable_str();
  inline ::std::string* release_str();
  inline void set_allocated_str(::std::string* str);

  // @@protoc_insertion_point(class_scope:sys.TEST)
 private:
  inline void set_has_str();
  inline void clear_has_str();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* str_;
  friend void  protobuf_AddDesc_sys_2eproto();
  friend void protobuf_AssignDesc_sys_2eproto();
  friend void protobuf_ShutdownFile_sys_2eproto();

  void InitAsDefaultInstance();
  static TEST* default_instance_;
};
// -------------------------------------------------------------------

class GM : public ::google::protobuf::Message {
 public:
  GM();
  virtual ~GM();

  GM(const GM& from);

  inline GM& operator=(const GM& from) {
    CopyFrom(from);
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const {
    return _unknown_fields_;
  }

  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields() {
    return &_unknown_fields_;
  }

  static const ::google::protobuf::Descriptor* descriptor();
  static const GM& default_instance();

  void Swap(GM* other);

  // implements Message ----------------------------------------------

  GM* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const GM& from);
  void MergeFrom(const GM& from);
  void Clear();
  bool IsInitialized() const;

  int ByteSize() const;
  bool MergePartialFromCodedStream(
      ::google::protobuf::io::CodedInputStream* input);
  void SerializeWithCachedSizes(
      ::google::protobuf::io::CodedOutputStream* output) const;
  ::google::protobuf::uint8* SerializeWithCachedSizesToArray(::google::protobuf::uint8* output) const;
  int GetCachedSize() const { return _cached_size_; }
  private:
  void SharedCtor();
  void SharedDtor();
  void SetCachedSize(int size) const;
  public:
  ::google::protobuf::Metadata GetMetadata() const;

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  // optional string str = 1 [default = ""];
  inline bool has_str() const;
  inline void clear_str();
  static const int kStrFieldNumber = 1;
  inline const ::std::string& str() const;
  inline void set_str(const ::std::string& value);
  inline void set_str(const char* value);
  inline void set_str(const char* value, size_t size);
  inline ::std::string* mutable_str();
  inline ::std::string* release_str();
  inline void set_allocated_str(::std::string* str);

  // @@protoc_insertion_point(class_scope:sys.GM)
 private:
  inline void set_has_str();
  inline void clear_has_str();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* str_;
  friend void  protobuf_AddDesc_sys_2eproto();
  friend void protobuf_AssignDesc_sys_2eproto();
  friend void protobuf_ShutdownFile_sys_2eproto();

  void InitAsDefaultInstance();
  static GM* default_instance_;
};
// ===================================================================


// ===================================================================

// PING

// optional int32 st = 1 [default = 0];
inline bool PING::has_st() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void PING::set_has_st() {
  _has_bits_[0] |= 0x00000001u;
}
inline void PING::clear_has_st() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void PING::clear_st() {
  st_ = 0;
  clear_has_st();
}
inline ::google::protobuf::int32 PING::st() const {
  // @@protoc_insertion_point(field_get:sys.PING.st)
  return st_;
}
inline void PING::set_st(::google::protobuf::int32 value) {
  set_has_st();
  st_ = value;
  // @@protoc_insertion_point(field_set:sys.PING.st)
}

// -------------------------------------------------------------------

// TEST

// optional string str = 1 [default = ""];
inline bool TEST::has_str() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void TEST::set_has_str() {
  _has_bits_[0] |= 0x00000001u;
}
inline void TEST::clear_has_str() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void TEST::clear_str() {
  if (str_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    str_->clear();
  }
  clear_has_str();
}
inline const ::std::string& TEST::str() const {
  // @@protoc_insertion_point(field_get:sys.TEST.str)
  return *str_;
}
inline void TEST::set_str(const ::std::string& value) {
  set_has_str();
  if (str_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    str_ = new ::std::string;
  }
  str_->assign(value);
  // @@protoc_insertion_point(field_set:sys.TEST.str)
}
inline void TEST::set_str(const char* value) {
  set_has_str();
  if (str_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    str_ = new ::std::string;
  }
  str_->assign(value);
  // @@protoc_insertion_point(field_set_char:sys.TEST.str)
}
inline void TEST::set_str(const char* value, size_t size) {
  set_has_str();
  if (str_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    str_ = new ::std::string;
  }
  str_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:sys.TEST.str)
}
inline ::std::string* TEST::mutable_str() {
  set_has_str();
  if (str_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    str_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:sys.TEST.str)
  return str_;
}
inline ::std::string* TEST::release_str() {
  clear_has_str();
  if (str_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = str_;
    str_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void TEST::set_allocated_str(::std::string* str) {
  if (str_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete str_;
  }
  if (str) {
    set_has_str();
    str_ = str;
  } else {
    clear_has_str();
    str_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:sys.TEST.str)
}

// -------------------------------------------------------------------

// GM

// optional string str = 1 [default = ""];
inline bool GM::has_str() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void GM::set_has_str() {
  _has_bits_[0] |= 0x00000001u;
}
inline void GM::clear_has_str() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void GM::clear_str() {
  if (str_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    str_->clear();
  }
  clear_has_str();
}
inline const ::std::string& GM::str() const {
  // @@protoc_insertion_point(field_get:sys.GM.str)
  return *str_;
}
inline void GM::set_str(const ::std::string& value) {
  set_has_str();
  if (str_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    str_ = new ::std::string;
  }
  str_->assign(value);
  // @@protoc_insertion_point(field_set:sys.GM.str)
}
inline void GM::set_str(const char* value) {
  set_has_str();
  if (str_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    str_ = new ::std::string;
  }
  str_->assign(value);
  // @@protoc_insertion_point(field_set_char:sys.GM.str)
}
inline void GM::set_str(const char* value, size_t size) {
  set_has_str();
  if (str_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    str_ = new ::std::string;
  }
  str_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:sys.GM.str)
}
inline ::std::string* GM::mutable_str() {
  set_has_str();
  if (str_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    str_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:sys.GM.str)
  return str_;
}
inline ::std::string* GM::release_str() {
  clear_has_str();
  if (str_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = str_;
    str_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void GM::set_allocated_str(::std::string* str) {
  if (str_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete str_;
  }
  if (str) {
    set_has_str();
    str_ = str;
  } else {
    clear_has_str();
    str_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:sys.GM.str)
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace sys

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_sys_2eproto__INCLUDED