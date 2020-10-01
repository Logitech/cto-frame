// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: Uniform.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_Uniform_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_Uniform_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3013000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3013000 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
#include "Math.pb.h"
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_Uniform_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_Uniform_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxiliaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_Uniform_2eproto;
namespace frame {
namespace proto {
class Uniform;
class UniformDefaultTypeInternal;
extern UniformDefaultTypeInternal _Uniform_default_instance_;
}  // namespace proto
}  // namespace frame
PROTOBUF_NAMESPACE_OPEN
template<> ::frame::proto::Uniform* Arena::CreateMaybeMessage<::frame::proto::Uniform>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace frame {
namespace proto {

// ===================================================================

class Uniform PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:frame.proto.Uniform) */ {
 public:
  inline Uniform() : Uniform(nullptr) {}
  virtual ~Uniform();

  Uniform(const Uniform& from);
  Uniform(Uniform&& from) noexcept
    : Uniform() {
    *this = ::std::move(from);
  }

  inline Uniform& operator=(const Uniform& from) {
    CopyFrom(from);
    return *this;
  }
  inline Uniform& operator=(Uniform&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Uniform& default_instance();

  enum ValueCase {
    kInteger = 2,
    kBoolean = 3,
    kReal = 4,
    kVector = 5,
    VALUE_NOT_SET = 0,
  };

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Uniform* internal_default_instance() {
    return reinterpret_cast<const Uniform*>(
               &_Uniform_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Uniform& a, Uniform& b) {
    a.Swap(&b);
  }
  inline void Swap(Uniform* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Uniform* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Uniform* New() const final {
    return CreateMaybeMessage<Uniform>(nullptr);
  }

  Uniform* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Uniform>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Uniform& from);
  void MergeFrom(const Uniform& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Uniform* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "frame.proto.Uniform";
  }
  protected:
  explicit Uniform(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_Uniform_2eproto);
    return ::descriptor_table_Uniform_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNameFieldNumber = 1,
    kIntegerFieldNumber = 2,
    kBooleanFieldNumber = 3,
    kRealFieldNumber = 4,
    kVectorFieldNumber = 5,
  };
  // string name = 1;
  void clear_name();
  const std::string& name() const;
  void set_name(const std::string& value);
  void set_name(std::string&& value);
  void set_name(const char* value);
  void set_name(const char* value, size_t size);
  std::string* mutable_name();
  std::string* release_name();
  void set_allocated_name(std::string* name);
  private:
  const std::string& _internal_name() const;
  void _internal_set_name(const std::string& value);
  std::string* _internal_mutable_name();
  public:

  // int32 integer = 2;
  private:
  bool _internal_has_integer() const;
  public:
  void clear_integer();
  ::PROTOBUF_NAMESPACE_ID::int32 integer() const;
  void set_integer(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_integer() const;
  void _internal_set_integer(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // bool boolean = 3;
  private:
  bool _internal_has_boolean() const;
  public:
  void clear_boolean();
  bool boolean() const;
  void set_boolean(bool value);
  private:
  bool _internal_boolean() const;
  void _internal_set_boolean(bool value);
  public:

  // float real = 4;
  private:
  bool _internal_has_real() const;
  public:
  void clear_real();
  float real() const;
  void set_real(float value);
  private:
  float _internal_real() const;
  void _internal_set_real(float value);
  public:

  // .frame.proto.Vector vector = 5;
  bool has_vector() const;
  private:
  bool _internal_has_vector() const;
  public:
  void clear_vector();
  const ::frame::proto::Vector& vector() const;
  ::frame::proto::Vector* release_vector();
  ::frame::proto::Vector* mutable_vector();
  void set_allocated_vector(::frame::proto::Vector* vector);
  private:
  const ::frame::proto::Vector& _internal_vector() const;
  ::frame::proto::Vector* _internal_mutable_vector();
  public:
  void unsafe_arena_set_allocated_vector(
      ::frame::proto::Vector* vector);
  ::frame::proto::Vector* unsafe_arena_release_vector();

  void clear_value();
  ValueCase value_case() const;
  // @@protoc_insertion_point(class_scope:frame.proto.Uniform)
 private:
  class _Internal;
  void set_has_integer();
  void set_has_boolean();
  void set_has_real();
  void set_has_vector();

  inline bool has_value() const;
  inline void clear_has_value();

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr name_;
  union ValueUnion {
    ValueUnion() {}
    ::PROTOBUF_NAMESPACE_ID::int32 integer_;
    bool boolean_;
    float real_;
    ::frame::proto::Vector* vector_;
  } value_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::uint32 _oneof_case_[1];

  friend struct ::TableStruct_Uniform_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Uniform

// string name = 1;
inline void Uniform::clear_name() {
  name_.ClearToEmpty(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline const std::string& Uniform::name() const {
  // @@protoc_insertion_point(field_get:frame.proto.Uniform.name)
  return _internal_name();
}
inline void Uniform::set_name(const std::string& value) {
  _internal_set_name(value);
  // @@protoc_insertion_point(field_set:frame.proto.Uniform.name)
}
inline std::string* Uniform::mutable_name() {
  // @@protoc_insertion_point(field_mutable:frame.proto.Uniform.name)
  return _internal_mutable_name();
}
inline const std::string& Uniform::_internal_name() const {
  return name_.Get();
}
inline void Uniform::_internal_set_name(const std::string& value) {
  
  name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value, GetArena());
}
inline void Uniform::set_name(std::string&& value) {
  
  name_.Set(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value), GetArena());
  // @@protoc_insertion_point(field_set_rvalue:frame.proto.Uniform.name)
}
inline void Uniform::set_name(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  
  name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value),
              GetArena());
  // @@protoc_insertion_point(field_set_char:frame.proto.Uniform.name)
}
inline void Uniform::set_name(const char* value,
    size_t size) {
  
  name_.Set(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(
      reinterpret_cast<const char*>(value), size), GetArena());
  // @@protoc_insertion_point(field_set_pointer:frame.proto.Uniform.name)
}
inline std::string* Uniform::_internal_mutable_name() {
  
  return name_.Mutable(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline std::string* Uniform::release_name() {
  // @@protoc_insertion_point(field_release:frame.proto.Uniform.name)
  return name_.Release(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), GetArena());
}
inline void Uniform::set_allocated_name(std::string* name) {
  if (name != nullptr) {
    
  } else {
    
  }
  name_.SetAllocated(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), name,
      GetArena());
  // @@protoc_insertion_point(field_set_allocated:frame.proto.Uniform.name)
}

// int32 integer = 2;
inline bool Uniform::_internal_has_integer() const {
  return value_case() == kInteger;
}
inline void Uniform::set_has_integer() {
  _oneof_case_[0] = kInteger;
}
inline void Uniform::clear_integer() {
  if (_internal_has_integer()) {
    value_.integer_ = 0;
    clear_has_value();
  }
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Uniform::_internal_integer() const {
  if (_internal_has_integer()) {
    return value_.integer_;
  }
  return 0;
}
inline void Uniform::_internal_set_integer(::PROTOBUF_NAMESPACE_ID::int32 value) {
  if (!_internal_has_integer()) {
    clear_value();
    set_has_integer();
  }
  value_.integer_ = value;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Uniform::integer() const {
  // @@protoc_insertion_point(field_get:frame.proto.Uniform.integer)
  return _internal_integer();
}
inline void Uniform::set_integer(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_integer(value);
  // @@protoc_insertion_point(field_set:frame.proto.Uniform.integer)
}

// bool boolean = 3;
inline bool Uniform::_internal_has_boolean() const {
  return value_case() == kBoolean;
}
inline void Uniform::set_has_boolean() {
  _oneof_case_[0] = kBoolean;
}
inline void Uniform::clear_boolean() {
  if (_internal_has_boolean()) {
    value_.boolean_ = false;
    clear_has_value();
  }
}
inline bool Uniform::_internal_boolean() const {
  if (_internal_has_boolean()) {
    return value_.boolean_;
  }
  return false;
}
inline void Uniform::_internal_set_boolean(bool value) {
  if (!_internal_has_boolean()) {
    clear_value();
    set_has_boolean();
  }
  value_.boolean_ = value;
}
inline bool Uniform::boolean() const {
  // @@protoc_insertion_point(field_get:frame.proto.Uniform.boolean)
  return _internal_boolean();
}
inline void Uniform::set_boolean(bool value) {
  _internal_set_boolean(value);
  // @@protoc_insertion_point(field_set:frame.proto.Uniform.boolean)
}

// float real = 4;
inline bool Uniform::_internal_has_real() const {
  return value_case() == kReal;
}
inline void Uniform::set_has_real() {
  _oneof_case_[0] = kReal;
}
inline void Uniform::clear_real() {
  if (_internal_has_real()) {
    value_.real_ = 0;
    clear_has_value();
  }
}
inline float Uniform::_internal_real() const {
  if (_internal_has_real()) {
    return value_.real_;
  }
  return 0;
}
inline void Uniform::_internal_set_real(float value) {
  if (!_internal_has_real()) {
    clear_value();
    set_has_real();
  }
  value_.real_ = value;
}
inline float Uniform::real() const {
  // @@protoc_insertion_point(field_get:frame.proto.Uniform.real)
  return _internal_real();
}
inline void Uniform::set_real(float value) {
  _internal_set_real(value);
  // @@protoc_insertion_point(field_set:frame.proto.Uniform.real)
}

// .frame.proto.Vector vector = 5;
inline bool Uniform::_internal_has_vector() const {
  return value_case() == kVector;
}
inline bool Uniform::has_vector() const {
  return _internal_has_vector();
}
inline void Uniform::set_has_vector() {
  _oneof_case_[0] = kVector;
}
inline ::frame::proto::Vector* Uniform::release_vector() {
  // @@protoc_insertion_point(field_release:frame.proto.Uniform.vector)
  if (_internal_has_vector()) {
    clear_has_value();
      ::frame::proto::Vector* temp = value_.vector_;
    if (GetArena() != nullptr) {
      temp = ::PROTOBUF_NAMESPACE_ID::internal::DuplicateIfNonNull(temp);
    }
    value_.vector_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline const ::frame::proto::Vector& Uniform::_internal_vector() const {
  return _internal_has_vector()
      ? *value_.vector_
      : *reinterpret_cast< ::frame::proto::Vector*>(&::frame::proto::_Vector_default_instance_);
}
inline const ::frame::proto::Vector& Uniform::vector() const {
  // @@protoc_insertion_point(field_get:frame.proto.Uniform.vector)
  return _internal_vector();
}
inline ::frame::proto::Vector* Uniform::unsafe_arena_release_vector() {
  // @@protoc_insertion_point(field_unsafe_arena_release:frame.proto.Uniform.vector)
  if (_internal_has_vector()) {
    clear_has_value();
    ::frame::proto::Vector* temp = value_.vector_;
    value_.vector_ = nullptr;
    return temp;
  } else {
    return nullptr;
  }
}
inline void Uniform::unsafe_arena_set_allocated_vector(::frame::proto::Vector* vector) {
  clear_value();
  if (vector) {
    set_has_vector();
    value_.vector_ = vector;
  }
  // @@protoc_insertion_point(field_unsafe_arena_set_allocated:frame.proto.Uniform.vector)
}
inline ::frame::proto::Vector* Uniform::_internal_mutable_vector() {
  if (!_internal_has_vector()) {
    clear_value();
    set_has_vector();
    value_.vector_ = CreateMaybeMessage< ::frame::proto::Vector >(GetArena());
  }
  return value_.vector_;
}
inline ::frame::proto::Vector* Uniform::mutable_vector() {
  // @@protoc_insertion_point(field_mutable:frame.proto.Uniform.vector)
  return _internal_mutable_vector();
}

inline bool Uniform::has_value() const {
  return value_case() != VALUE_NOT_SET;
}
inline void Uniform::clear_has_value() {
  _oneof_case_[0] = VALUE_NOT_SET;
}
inline Uniform::ValueCase Uniform::value_case() const {
  return Uniform::ValueCase(_oneof_case_[0]);
}
#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace proto
}  // namespace frame

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_Uniform_2eproto
