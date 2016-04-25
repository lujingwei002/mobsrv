// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: mail.proto

#define INTERNAL_SUPPRESS_PROTOBUF_FIELD_DEPRECATION
#include "mail.pb.h"

#include <algorithm>

#include <google/protobuf/stubs/common.h>
#include <google/protobuf/stubs/once.h>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/wire_format_lite_inl.h>
#include <google/protobuf/descriptor.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/reflection_ops.h>
#include <google/protobuf/wire_format.h>
// @@protoc_insertion_point(includes)

namespace dbproto {

namespace {

const ::google::protobuf::Descriptor* Mail_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  Mail_reflection_ = NULL;
const ::google::protobuf::Descriptor* MailList_descriptor_ = NULL;
const ::google::protobuf::internal::GeneratedMessageReflection*
  MailList_reflection_ = NULL;

}  // namespace


void protobuf_AssignDesc_mail_2eproto() {
  protobuf_AddDesc_mail_2eproto();
  const ::google::protobuf::FileDescriptor* file =
    ::google::protobuf::DescriptorPool::generated_pool()->FindFileByName(
      "mail.proto");
  GOOGLE_CHECK(file != NULL);
  Mail_descriptor_ = file->message_type(0);
  static const int Mail_offsets_[8] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Mail, id_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Mail, uid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Mail, uname_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Mail, uptimetime_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Mail, title_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Mail, text_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Mail, senderuid_),
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Mail, senderuname_),
  };
  Mail_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      Mail_descriptor_,
      Mail::default_instance_,
      Mail_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Mail, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(Mail, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(Mail));
  MailList_descriptor_ = file->message_type(1);
  static const int MailList_offsets_[1] = {
    GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MailList, mails_),
  };
  MailList_reflection_ =
    new ::google::protobuf::internal::GeneratedMessageReflection(
      MailList_descriptor_,
      MailList::default_instance_,
      MailList_offsets_,
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MailList, _has_bits_[0]),
      GOOGLE_PROTOBUF_GENERATED_MESSAGE_FIELD_OFFSET(MailList, _unknown_fields_),
      -1,
      ::google::protobuf::DescriptorPool::generated_pool(),
      ::google::protobuf::MessageFactory::generated_factory(),
      sizeof(MailList));
}

namespace {

GOOGLE_PROTOBUF_DECLARE_ONCE(protobuf_AssignDescriptors_once_);
inline void protobuf_AssignDescriptorsOnce() {
  ::google::protobuf::GoogleOnceInit(&protobuf_AssignDescriptors_once_,
                 &protobuf_AssignDesc_mail_2eproto);
}

void protobuf_RegisterTypes(const ::std::string&) {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    Mail_descriptor_, &Mail::default_instance());
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedMessage(
    MailList_descriptor_, &MailList::default_instance());
}

}  // namespace

void protobuf_ShutdownFile_mail_2eproto() {
  delete Mail::default_instance_;
  delete Mail_reflection_;
  delete MailList::default_instance_;
  delete MailList_reflection_;
}

void protobuf_AddDesc_mail_2eproto() {
  static bool already_here = false;
  if (already_here) return;
  already_here = true;
  GOOGLE_PROTOBUF_VERIFY_VERSION;

  ::google::protobuf::DescriptorPool::InternalAddGeneratedFile(
    "\n\nmail.proto\022\007dbproto\"\233\001\n\004Mail\022\r\n\002id\030\001 \001"
    "(\005:\0010\022\016\n\003uid\030\002 \001(\005:\0010\022\017\n\005uname\030\003 \001(\t:\000\022\025"
    "\n\nuptimetime\030\004 \001(\005:\0010\022\017\n\005title\030\005 \001(\t:\000\022\016"
    "\n\004text\030\006 \001(\t:\000\022\024\n\tsenderuid\030\007 \001(\005:\0010\022\025\n\013"
    "senderuname\030\010 \001(\t:\000\"(\n\010MailList\022\034\n\005mails"
    "\030\001 \003(\0132\r.dbproto.Mail", 221);
  ::google::protobuf::MessageFactory::InternalRegisterGeneratedFile(
    "mail.proto", &protobuf_RegisterTypes);
  Mail::default_instance_ = new Mail();
  MailList::default_instance_ = new MailList();
  Mail::default_instance_->InitAsDefaultInstance();
  MailList::default_instance_->InitAsDefaultInstance();
  ::google::protobuf::internal::OnShutdown(&protobuf_ShutdownFile_mail_2eproto);
}

// Force AddDescriptors() to be called at static initialization time.
struct StaticDescriptorInitializer_mail_2eproto {
  StaticDescriptorInitializer_mail_2eproto() {
    protobuf_AddDesc_mail_2eproto();
  }
} static_descriptor_initializer_mail_2eproto_;

// ===================================================================

#ifndef _MSC_VER
const int Mail::kIdFieldNumber;
const int Mail::kUidFieldNumber;
const int Mail::kUnameFieldNumber;
const int Mail::kUptimetimeFieldNumber;
const int Mail::kTitleFieldNumber;
const int Mail::kTextFieldNumber;
const int Mail::kSenderuidFieldNumber;
const int Mail::kSenderunameFieldNumber;
#endif  // !_MSC_VER

Mail::Mail()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:dbproto.Mail)
}

void Mail::InitAsDefaultInstance() {
}

Mail::Mail(const Mail& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:dbproto.Mail)
}

void Mail::SharedCtor() {
  ::google::protobuf::internal::GetEmptyString();
  _cached_size_ = 0;
  id_ = 0;
  uid_ = 0;
  uname_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  uptimetime_ = 0;
  title_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  text_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  senderuid_ = 0;
  senderuname_ = const_cast< ::std::string*>(&::google::protobuf::internal::GetEmptyStringAlreadyInited());
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

Mail::~Mail() {
  // @@protoc_insertion_point(destructor:dbproto.Mail)
  SharedDtor();
}

void Mail::SharedDtor() {
  if (uname_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete uname_;
  }
  if (title_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete title_;
  }
  if (text_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete text_;
  }
  if (senderuname_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
    delete senderuname_;
  }
  if (this != default_instance_) {
  }
}

void Mail::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* Mail::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return Mail_descriptor_;
}

const Mail& Mail::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_mail_2eproto();
  return *default_instance_;
}

Mail* Mail::default_instance_ = NULL;

Mail* Mail::New() const {
  return new Mail;
}

void Mail::Clear() {
#define OFFSET_OF_FIELD_(f) (reinterpret_cast<char*>(      \
  &reinterpret_cast<Mail*>(16)->f) - \
   reinterpret_cast<char*>(16))

#define ZR_(first, last) do {                              \
    size_t f = OFFSET_OF_FIELD_(first);                    \
    size_t n = OFFSET_OF_FIELD_(last) - f + sizeof(last);  \
    ::memset(&first, 0, n);                                \
  } while (0)

  if (_has_bits_[0 / 32] & 255) {
    ZR_(id_, uid_);
    ZR_(uptimetime_, senderuid_);
    if (has_uname()) {
      if (uname_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        uname_->clear();
      }
    }
    if (has_title()) {
      if (title_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        title_->clear();
      }
    }
    if (has_text()) {
      if (text_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        text_->clear();
      }
    }
    if (has_senderuname()) {
      if (senderuname_ != &::google::protobuf::internal::GetEmptyStringAlreadyInited()) {
        senderuname_->clear();
      }
    }
  }

#undef OFFSET_OF_FIELD_
#undef ZR_

  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool Mail::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:dbproto.Mail)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // optional int32 id = 1 [default = 0];
      case 1: {
        if (tag == 8) {
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &id_)));
          set_has_id();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(16)) goto parse_uid;
        break;
      }

      // optional int32 uid = 2 [default = 0];
      case 2: {
        if (tag == 16) {
         parse_uid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &uid_)));
          set_has_uid();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(26)) goto parse_uname;
        break;
      }

      // optional string uname = 3 [default = ""];
      case 3: {
        if (tag == 26) {
         parse_uname:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_uname()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->uname().data(), this->uname().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "uname");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(32)) goto parse_uptimetime;
        break;
      }

      // optional int32 uptimetime = 4 [default = 0];
      case 4: {
        if (tag == 32) {
         parse_uptimetime:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &uptimetime_)));
          set_has_uptimetime();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(42)) goto parse_title;
        break;
      }

      // optional string title = 5 [default = ""];
      case 5: {
        if (tag == 42) {
         parse_title:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_title()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->title().data(), this->title().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "title");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(50)) goto parse_text;
        break;
      }

      // optional string text = 6 [default = ""];
      case 6: {
        if (tag == 50) {
         parse_text:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_text()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->text().data(), this->text().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "text");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(56)) goto parse_senderuid;
        break;
      }

      // optional int32 senderuid = 7 [default = 0];
      case 7: {
        if (tag == 56) {
         parse_senderuid:
          DO_((::google::protobuf::internal::WireFormatLite::ReadPrimitive<
                   ::google::protobuf::int32, ::google::protobuf::internal::WireFormatLite::TYPE_INT32>(
                 input, &senderuid_)));
          set_has_senderuid();
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(66)) goto parse_senderuname;
        break;
      }

      // optional string senderuname = 8 [default = ""];
      case 8: {
        if (tag == 66) {
         parse_senderuname:
          DO_(::google::protobuf::internal::WireFormatLite::ReadString(
                input, this->mutable_senderuname()));
          ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
            this->senderuname().data(), this->senderuname().length(),
            ::google::protobuf::internal::WireFormat::PARSE,
            "senderuname");
        } else {
          goto handle_unusual;
        }
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:dbproto.Mail)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:dbproto.Mail)
  return false;
#undef DO_
}

void Mail::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:dbproto.Mail)
  // optional int32 id = 1 [default = 0];
  if (has_id()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(1, this->id(), output);
  }

  // optional int32 uid = 2 [default = 0];
  if (has_uid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(2, this->uid(), output);
  }

  // optional string uname = 3 [default = ""];
  if (has_uname()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->uname().data(), this->uname().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "uname");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      3, this->uname(), output);
  }

  // optional int32 uptimetime = 4 [default = 0];
  if (has_uptimetime()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(4, this->uptimetime(), output);
  }

  // optional string title = 5 [default = ""];
  if (has_title()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->title().data(), this->title().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "title");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      5, this->title(), output);
  }

  // optional string text = 6 [default = ""];
  if (has_text()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->text().data(), this->text().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "text");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      6, this->text(), output);
  }

  // optional int32 senderuid = 7 [default = 0];
  if (has_senderuid()) {
    ::google::protobuf::internal::WireFormatLite::WriteInt32(7, this->senderuid(), output);
  }

  // optional string senderuname = 8 [default = ""];
  if (has_senderuname()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->senderuname().data(), this->senderuname().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "senderuname");
    ::google::protobuf::internal::WireFormatLite::WriteStringMaybeAliased(
      8, this->senderuname(), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:dbproto.Mail)
}

::google::protobuf::uint8* Mail::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:dbproto.Mail)
  // optional int32 id = 1 [default = 0];
  if (has_id()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(1, this->id(), target);
  }

  // optional int32 uid = 2 [default = 0];
  if (has_uid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(2, this->uid(), target);
  }

  // optional string uname = 3 [default = ""];
  if (has_uname()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->uname().data(), this->uname().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "uname");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        3, this->uname(), target);
  }

  // optional int32 uptimetime = 4 [default = 0];
  if (has_uptimetime()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(4, this->uptimetime(), target);
  }

  // optional string title = 5 [default = ""];
  if (has_title()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->title().data(), this->title().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "title");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        5, this->title(), target);
  }

  // optional string text = 6 [default = ""];
  if (has_text()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->text().data(), this->text().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "text");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        6, this->text(), target);
  }

  // optional int32 senderuid = 7 [default = 0];
  if (has_senderuid()) {
    target = ::google::protobuf::internal::WireFormatLite::WriteInt32ToArray(7, this->senderuid(), target);
  }

  // optional string senderuname = 8 [default = ""];
  if (has_senderuname()) {
    ::google::protobuf::internal::WireFormat::VerifyUTF8StringNamedField(
      this->senderuname().data(), this->senderuname().length(),
      ::google::protobuf::internal::WireFormat::SERIALIZE,
      "senderuname");
    target =
      ::google::protobuf::internal::WireFormatLite::WriteStringToArray(
        8, this->senderuname(), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:dbproto.Mail)
  return target;
}

int Mail::ByteSize() const {
  int total_size = 0;

  if (_has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    // optional int32 id = 1 [default = 0];
    if (has_id()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->id());
    }

    // optional int32 uid = 2 [default = 0];
    if (has_uid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->uid());
    }

    // optional string uname = 3 [default = ""];
    if (has_uname()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->uname());
    }

    // optional int32 uptimetime = 4 [default = 0];
    if (has_uptimetime()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->uptimetime());
    }

    // optional string title = 5 [default = ""];
    if (has_title()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->title());
    }

    // optional string text = 6 [default = ""];
    if (has_text()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->text());
    }

    // optional int32 senderuid = 7 [default = 0];
    if (has_senderuid()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::Int32Size(
          this->senderuid());
    }

    // optional string senderuname = 8 [default = ""];
    if (has_senderuname()) {
      total_size += 1 +
        ::google::protobuf::internal::WireFormatLite::StringSize(
          this->senderuname());
    }

  }
  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void Mail::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const Mail* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const Mail*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void Mail::MergeFrom(const Mail& from) {
  GOOGLE_CHECK_NE(&from, this);
  if (from._has_bits_[0 / 32] & (0xffu << (0 % 32))) {
    if (from.has_id()) {
      set_id(from.id());
    }
    if (from.has_uid()) {
      set_uid(from.uid());
    }
    if (from.has_uname()) {
      set_uname(from.uname());
    }
    if (from.has_uptimetime()) {
      set_uptimetime(from.uptimetime());
    }
    if (from.has_title()) {
      set_title(from.title());
    }
    if (from.has_text()) {
      set_text(from.text());
    }
    if (from.has_senderuid()) {
      set_senderuid(from.senderuid());
    }
    if (from.has_senderuname()) {
      set_senderuname(from.senderuname());
    }
  }
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void Mail::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void Mail::CopyFrom(const Mail& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool Mail::IsInitialized() const {

  return true;
}

void Mail::Swap(Mail* other) {
  if (other != this) {
    std::swap(id_, other->id_);
    std::swap(uid_, other->uid_);
    std::swap(uname_, other->uname_);
    std::swap(uptimetime_, other->uptimetime_);
    std::swap(title_, other->title_);
    std::swap(text_, other->text_);
    std::swap(senderuid_, other->senderuid_);
    std::swap(senderuname_, other->senderuname_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata Mail::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = Mail_descriptor_;
  metadata.reflection = Mail_reflection_;
  return metadata;
}


// ===================================================================

#ifndef _MSC_VER
const int MailList::kMailsFieldNumber;
#endif  // !_MSC_VER

MailList::MailList()
  : ::google::protobuf::Message() {
  SharedCtor();
  // @@protoc_insertion_point(constructor:dbproto.MailList)
}

void MailList::InitAsDefaultInstance() {
}

MailList::MailList(const MailList& from)
  : ::google::protobuf::Message() {
  SharedCtor();
  MergeFrom(from);
  // @@protoc_insertion_point(copy_constructor:dbproto.MailList)
}

void MailList::SharedCtor() {
  _cached_size_ = 0;
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
}

MailList::~MailList() {
  // @@protoc_insertion_point(destructor:dbproto.MailList)
  SharedDtor();
}

void MailList::SharedDtor() {
  if (this != default_instance_) {
  }
}

void MailList::SetCachedSize(int size) const {
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
}
const ::google::protobuf::Descriptor* MailList::descriptor() {
  protobuf_AssignDescriptorsOnce();
  return MailList_descriptor_;
}

const MailList& MailList::default_instance() {
  if (default_instance_ == NULL) protobuf_AddDesc_mail_2eproto();
  return *default_instance_;
}

MailList* MailList::default_instance_ = NULL;

MailList* MailList::New() const {
  return new MailList;
}

void MailList::Clear() {
  mails_.Clear();
  ::memset(_has_bits_, 0, sizeof(_has_bits_));
  mutable_unknown_fields()->Clear();
}

bool MailList::MergePartialFromCodedStream(
    ::google::protobuf::io::CodedInputStream* input) {
#define DO_(EXPRESSION) if (!(EXPRESSION)) goto failure
  ::google::protobuf::uint32 tag;
  // @@protoc_insertion_point(parse_start:dbproto.MailList)
  for (;;) {
    ::std::pair< ::google::protobuf::uint32, bool> p = input->ReadTagWithCutoff(127);
    tag = p.first;
    if (!p.second) goto handle_unusual;
    switch (::google::protobuf::internal::WireFormatLite::GetTagFieldNumber(tag)) {
      // repeated .dbproto.Mail mails = 1;
      case 1: {
        if (tag == 10) {
         parse_mails:
          DO_(::google::protobuf::internal::WireFormatLite::ReadMessageNoVirtual(
                input, add_mails()));
        } else {
          goto handle_unusual;
        }
        if (input->ExpectTag(10)) goto parse_mails;
        if (input->ExpectAtEnd()) goto success;
        break;
      }

      default: {
      handle_unusual:
        if (tag == 0 ||
            ::google::protobuf::internal::WireFormatLite::GetTagWireType(tag) ==
            ::google::protobuf::internal::WireFormatLite::WIRETYPE_END_GROUP) {
          goto success;
        }
        DO_(::google::protobuf::internal::WireFormat::SkipField(
              input, tag, mutable_unknown_fields()));
        break;
      }
    }
  }
success:
  // @@protoc_insertion_point(parse_success:dbproto.MailList)
  return true;
failure:
  // @@protoc_insertion_point(parse_failure:dbproto.MailList)
  return false;
#undef DO_
}

void MailList::SerializeWithCachedSizes(
    ::google::protobuf::io::CodedOutputStream* output) const {
  // @@protoc_insertion_point(serialize_start:dbproto.MailList)
  // repeated .dbproto.Mail mails = 1;
  for (int i = 0; i < this->mails_size(); i++) {
    ::google::protobuf::internal::WireFormatLite::WriteMessageMaybeToArray(
      1, this->mails(i), output);
  }

  if (!unknown_fields().empty()) {
    ::google::protobuf::internal::WireFormat::SerializeUnknownFields(
        unknown_fields(), output);
  }
  // @@protoc_insertion_point(serialize_end:dbproto.MailList)
}

::google::protobuf::uint8* MailList::SerializeWithCachedSizesToArray(
    ::google::protobuf::uint8* target) const {
  // @@protoc_insertion_point(serialize_to_array_start:dbproto.MailList)
  // repeated .dbproto.Mail mails = 1;
  for (int i = 0; i < this->mails_size(); i++) {
    target = ::google::protobuf::internal::WireFormatLite::
      WriteMessageNoVirtualToArray(
        1, this->mails(i), target);
  }

  if (!unknown_fields().empty()) {
    target = ::google::protobuf::internal::WireFormat::SerializeUnknownFieldsToArray(
        unknown_fields(), target);
  }
  // @@protoc_insertion_point(serialize_to_array_end:dbproto.MailList)
  return target;
}

int MailList::ByteSize() const {
  int total_size = 0;

  // repeated .dbproto.Mail mails = 1;
  total_size += 1 * this->mails_size();
  for (int i = 0; i < this->mails_size(); i++) {
    total_size +=
      ::google::protobuf::internal::WireFormatLite::MessageSizeNoVirtual(
        this->mails(i));
  }

  if (!unknown_fields().empty()) {
    total_size +=
      ::google::protobuf::internal::WireFormat::ComputeUnknownFieldsSize(
        unknown_fields());
  }
  GOOGLE_SAFE_CONCURRENT_WRITES_BEGIN();
  _cached_size_ = total_size;
  GOOGLE_SAFE_CONCURRENT_WRITES_END();
  return total_size;
}

void MailList::MergeFrom(const ::google::protobuf::Message& from) {
  GOOGLE_CHECK_NE(&from, this);
  const MailList* source =
    ::google::protobuf::internal::dynamic_cast_if_available<const MailList*>(
      &from);
  if (source == NULL) {
    ::google::protobuf::internal::ReflectionOps::Merge(from, this);
  } else {
    MergeFrom(*source);
  }
}

void MailList::MergeFrom(const MailList& from) {
  GOOGLE_CHECK_NE(&from, this);
  mails_.MergeFrom(from.mails_);
  mutable_unknown_fields()->MergeFrom(from.unknown_fields());
}

void MailList::CopyFrom(const ::google::protobuf::Message& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

void MailList::CopyFrom(const MailList& from) {
  if (&from == this) return;
  Clear();
  MergeFrom(from);
}

bool MailList::IsInitialized() const {

  return true;
}

void MailList::Swap(MailList* other) {
  if (other != this) {
    mails_.Swap(&other->mails_);
    std::swap(_has_bits_[0], other->_has_bits_[0]);
    _unknown_fields_.Swap(&other->_unknown_fields_);
    std::swap(_cached_size_, other->_cached_size_);
  }
}

::google::protobuf::Metadata MailList::GetMetadata() const {
  protobuf_AssignDescriptorsOnce();
  ::google::protobuf::Metadata metadata;
  metadata.descriptor = MailList_descriptor_;
  metadata.reflection = MailList_reflection_;
  return metadata;
}


// @@protoc_insertion_point(namespace_scope)

}  // namespace dbproto

// @@protoc_insertion_point(global_scope)
