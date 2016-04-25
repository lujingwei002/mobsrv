// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: friend.proto

#ifndef PROTOBUF_friend_2eproto__INCLUDED
#define PROTOBUF_friend_2eproto__INCLUDED

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

namespace dbproto {

// Internal implementation detail -- do not call these.
void  protobuf_AddDesc_friend_2eproto();
void protobuf_AssignDesc_friend_2eproto();
void protobuf_ShutdownFile_friend_2eproto();

class Friend;
class FriendData;

// ===================================================================

class Friend : public ::google::protobuf::Message {
 public:
  Friend();
  virtual ~Friend();

  Friend(const Friend& from);

  inline Friend& operator=(const Friend& from) {
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
  static const Friend& default_instance();

  void Swap(Friend* other);

  // implements Message ----------------------------------------------

  Friend* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const Friend& from);
  void MergeFrom(const Friend& from);
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

  // optional int32 uid = 1 [default = 0];
  inline bool has_uid() const;
  inline void clear_uid();
  static const int kUidFieldNumber = 1;
  inline ::google::protobuf::int32 uid() const;
  inline void set_uid(::google::protobuf::int32 value);

  // optional string uname = 2 [default = ""];
  inline bool has_uname() const;
  inline void clear_uname();
  static const int kUnameFieldNumber = 2;
  inline const ::std::string& uname() const;
  inline void set_uname(const ::std::string& value);
  inline void set_uname(const char* value);
  inline void set_uname(const char* value, size_t size);
  inline ::std::string* mutable_uname();
  inline ::std::string* release_uname();
  inline void set_allocated_uname(::std::string* uname);

  // @@protoc_insertion_point(class_scope:dbproto.Friend)
 private:
  inline void set_has_uid();
  inline void clear_has_uid();
  inline void set_has_uname();
  inline void clear_has_uname();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::std::string* uname_;
  ::google::protobuf::int32 uid_;
  friend void  protobuf_AddDesc_friend_2eproto();
  friend void protobuf_AssignDesc_friend_2eproto();
  friend void protobuf_ShutdownFile_friend_2eproto();

  void InitAsDefaultInstance();
  static Friend* default_instance_;
};
// -------------------------------------------------------------------

class FriendData : public ::google::protobuf::Message {
 public:
  FriendData();
  virtual ~FriendData();

  FriendData(const FriendData& from);

  inline FriendData& operator=(const FriendData& from) {
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
  static const FriendData& default_instance();

  void Swap(FriendData* other);

  // implements Message ----------------------------------------------

  FriendData* New() const;
  void CopyFrom(const ::google::protobuf::Message& from);
  void MergeFrom(const ::google::protobuf::Message& from);
  void CopyFrom(const FriendData& from);
  void MergeFrom(const FriendData& from);
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

  // optional int32 uid = 1 [default = 0];
  inline bool has_uid() const;
  inline void clear_uid();
  static const int kUidFieldNumber = 1;
  inline ::google::protobuf::int32 uid() const;
  inline void set_uid(::google::protobuf::int32 value);

  // repeated .dbproto.Friend friends = 2;
  inline int friends_size() const;
  inline void clear_friends();
  static const int kFriendsFieldNumber = 2;
  inline const ::dbproto::Friend& friends(int index) const;
  inline ::dbproto::Friend* mutable_friends(int index);
  inline ::dbproto::Friend* add_friends();
  inline const ::google::protobuf::RepeatedPtrField< ::dbproto::Friend >&
      friends() const;
  inline ::google::protobuf::RepeatedPtrField< ::dbproto::Friend >*
      mutable_friends();

  // @@protoc_insertion_point(class_scope:dbproto.FriendData)
 private:
  inline void set_has_uid();
  inline void clear_has_uid();

  ::google::protobuf::UnknownFieldSet _unknown_fields_;

  ::google::protobuf::uint32 _has_bits_[1];
  mutable int _cached_size_;
  ::google::protobuf::RepeatedPtrField< ::dbproto::Friend > friends_;
  ::google::protobuf::int32 uid_;
  friend void  protobuf_AddDesc_friend_2eproto();
  friend void protobuf_AssignDesc_friend_2eproto();
  friend void protobuf_ShutdownFile_friend_2eproto();

  void InitAsDefaultInstance();
  static FriendData* default_instance_;
};
// ===================================================================


// ===================================================================

// Friend

// optional int32 uid = 1 [default = 0];
inline bool Friend::has_uid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void Friend::set_has_uid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void Friend::clear_has_uid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void Friend::clear_uid() {
  uid_ = 0;
  clear_has_uid();
}
inline ::google::protobuf::int32 Friend::uid() const {
  // @@protoc_insertion_point(field_get:dbproto.Friend.uid)
  return uid_;
}
inline void Friend::set_uid(::google::protobuf::int32 value) {
  set_has_uid();
  uid_ = value;
  // @@protoc_insertion_point(field_set:dbproto.Friend.uid)
}

// optional string uname = 2 [default = ""];
inline bool Friend::has_uname() const {
  return (_has_bits_[0] & 0x00000002u) != 0;
}
inline void Friend::set_has_uname() {
  _has_bits_[0] |= 0x00000002u;
}
inline void Friend::clear_has_uname() {
  _has_bits_[0] &= ~0x00000002u;
}
inline void Friend::clear_uname() {
  if (uname_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    uname_->clear();
  }
  clear_has_uname();
}
inline const ::std::string& Friend::uname() const {
  // @@protoc_insertion_point(field_get:dbproto.Friend.uname)
  return *uname_;
}
inline void Friend::set_uname(const ::std::string& value) {
  set_has_uname();
  if (uname_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    uname_ = new ::std::string;
  }
  uname_->assign(value);
  // @@protoc_insertion_point(field_set:dbproto.Friend.uname)
}
inline void Friend::set_uname(const char* value) {
  set_has_uname();
  if (uname_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    uname_ = new ::std::string;
  }
  uname_->assign(value);
  // @@protoc_insertion_point(field_set_char:dbproto.Friend.uname)
}
inline void Friend::set_uname(const char* value, size_t size) {
  set_has_uname();
  if (uname_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    uname_ = new ::std::string;
  }
  uname_->assign(reinterpret_cast<const char*>(value), size);
  // @@protoc_insertion_point(field_set_pointer:dbproto.Friend.uname)
}
inline ::std::string* Friend::mutable_uname() {
  set_has_uname();
  if (uname_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    uname_ = new ::std::string;
  }
  // @@protoc_insertion_point(field_mutable:dbproto.Friend.uname)
  return uname_;
}
inline ::std::string* Friend::release_uname() {
  clear_has_uname();
  if (uname_ == &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    return NULL;
  } else {
    ::std::string* temp = uname_;
    uname_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
    return temp;
  }
}
inline void Friend::set_allocated_uname(::std::string* uname) {
  if (uname_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete uname_;
  }
  if (uname) {
    set_has_uname();
    uname_ = uname;
  } else {
    clear_has_uname();
    uname_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  }
  // @@protoc_insertion_point(field_set_allocated:dbproto.Friend.uname)
}

// -------------------------------------------------------------------

// FriendData

// optional int32 uid = 1 [default = 0];
inline bool FriendData::has_uid() const {
  return (_has_bits_[0] & 0x00000001u) != 0;
}
inline void FriendData::set_has_uid() {
  _has_bits_[0] |= 0x00000001u;
}
inline void FriendData::clear_has_uid() {
  _has_bits_[0] &= ~0x00000001u;
}
inline void FriendData::clear_uid() {
  uid_ = 0;
  clear_has_uid();
}
inline ::google::protobuf::int32 FriendData::uid() const {
  // @@protoc_insertion_point(field_get:dbproto.FriendData.uid)
  return uid_;
}
inline void FriendData::set_uid(::google::protobuf::int32 value) {
  set_has_uid();
  uid_ = value;
  // @@protoc_insertion_point(field_set:dbproto.FriendData.uid)
}

// repeated .dbproto.Friend friends = 2;
inline int FriendData::friends_size() const {
  return friends_.size();
}
inline void FriendData::clear_friends() {
  friends_.Clear();
}
inline const ::dbproto::Friend& FriendData::friends(int index) const {
  // @@protoc_insertion_point(field_get:dbproto.FriendData.friends)
  return friends_.Get(index);
}
inline ::dbproto::Friend* FriendData::mutable_friends(int index) {
  // @@protoc_insertion_point(field_mutable:dbproto.FriendData.friends)
  return friends_.Mutable(index);
}
inline ::dbproto::Friend* FriendData::add_friends() {
  // @@protoc_insertion_point(field_add:dbproto.FriendData.friends)
  return friends_.Add();
}
inline const ::google::protobuf::RepeatedPtrField< ::dbproto::Friend >&
FriendData::friends() const {
  // @@protoc_insertion_point(field_list:dbproto.FriendData.friends)
  return friends_;
}
inline ::google::protobuf::RepeatedPtrField< ::dbproto::Friend >*
FriendData::mutable_friends() {
  // @@protoc_insertion_point(field_mutable_list:dbproto.FriendData.friends)
  return &friends_;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace dbproto

#ifndef SWIG
namespace google {
namespace protobuf {


}  // namespace google
}  // namespace protobuf
#endif  // SWIG

// @@protoc_insertion_point(global_scope)

#endif  // PROTOBUF_friend_2eproto__INCLUDED
