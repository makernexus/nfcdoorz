// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_IPCCOMMON_NFCDOORZ_IPC_COMMON_H_
#define FLATBUFFERS_GENERATED_IPCCOMMON_NFCDOORZ_IPC_COMMON_H_

#include "flatbuffers/flatbuffers.h"

namespace nfcdoorz {
namespace ipc {
namespace common {

struct ConfigCall;
struct ConfigCallT;

struct ConfigReply;
struct ConfigReplyT;

inline const flatbuffers::TypeTable *ConfigCallTypeTable();

inline const flatbuffers::TypeTable *ConfigReplyTypeTable();

struct ConfigCallT : public flatbuffers::NativeTable {
  typedef ConfigCall TableType;
  static FLATBUFFERS_CONSTEXPR const char *GetFullyQualifiedName() {
    return "nfcdoorz.ipc.common.ConfigCallT";
  }
  ConfigCallT() {
  }
};

struct ConfigCall FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ConfigCallT NativeTableType;
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return ConfigCallTypeTable();
  }
  static FLATBUFFERS_CONSTEXPR const char *GetFullyQualifiedName() {
    return "nfcdoorz.ipc.common.ConfigCall";
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           verifier.EndTable();
  }
  ConfigCallT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(ConfigCallT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<ConfigCall> Pack(flatbuffers::FlatBufferBuilder &_fbb, const ConfigCallT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct ConfigCallBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  explicit ConfigCallBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ConfigCallBuilder &operator=(const ConfigCallBuilder &);
  flatbuffers::Offset<ConfigCall> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<ConfigCall>(end);
    return o;
  }
};

inline flatbuffers::Offset<ConfigCall> CreateConfigCall(
    flatbuffers::FlatBufferBuilder &_fbb) {
  ConfigCallBuilder builder_(_fbb);
  return builder_.Finish();
}

flatbuffers::Offset<ConfigCall> CreateConfigCall(flatbuffers::FlatBufferBuilder &_fbb, const ConfigCallT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

struct ConfigReplyT : public flatbuffers::NativeTable {
  typedef ConfigReply TableType;
  static FLATBUFFERS_CONSTEXPR const char *GetFullyQualifiedName() {
    return "nfcdoorz.ipc.common.ConfigReplyT";
  }
  std::string config;
  ConfigReplyT() {
  }
};

struct ConfigReply FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  typedef ConfigReplyT NativeTableType;
  static const flatbuffers::TypeTable *MiniReflectTypeTable() {
    return ConfigReplyTypeTable();
  }
  static FLATBUFFERS_CONSTEXPR const char *GetFullyQualifiedName() {
    return "nfcdoorz.ipc.common.ConfigReply";
  }
  enum {
    VT_CONFIG = 4
  };
  const flatbuffers::String *config() const {
    return GetPointer<const flatbuffers::String *>(VT_CONFIG);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_CONFIG) &&
           verifier.VerifyString(config()) &&
           verifier.EndTable();
  }
  ConfigReplyT *UnPack(const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  void UnPackTo(ConfigReplyT *_o, const flatbuffers::resolver_function_t *_resolver = nullptr) const;
  static flatbuffers::Offset<ConfigReply> Pack(flatbuffers::FlatBufferBuilder &_fbb, const ConfigReplyT* _o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);
};

struct ConfigReplyBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_config(flatbuffers::Offset<flatbuffers::String> config) {
    fbb_.AddOffset(ConfigReply::VT_CONFIG, config);
  }
  explicit ConfigReplyBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ConfigReplyBuilder &operator=(const ConfigReplyBuilder &);
  flatbuffers::Offset<ConfigReply> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<ConfigReply>(end);
    return o;
  }
};

inline flatbuffers::Offset<ConfigReply> CreateConfigReply(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> config = 0) {
  ConfigReplyBuilder builder_(_fbb);
  builder_.add_config(config);
  return builder_.Finish();
}

inline flatbuffers::Offset<ConfigReply> CreateConfigReplyDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *config = nullptr) {
  return nfcdoorz::ipc::common::CreateConfigReply(
      _fbb,
      config ? _fbb.CreateString(config) : 0);
}

flatbuffers::Offset<ConfigReply> CreateConfigReply(flatbuffers::FlatBufferBuilder &_fbb, const ConfigReplyT *_o, const flatbuffers::rehasher_function_t *_rehasher = nullptr);

inline ConfigCallT *ConfigCall::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = new ConfigCallT();
  UnPackTo(_o, _resolver);
  return _o;
}

inline void ConfigCall::UnPackTo(ConfigCallT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
}

inline flatbuffers::Offset<ConfigCall> ConfigCall::Pack(flatbuffers::FlatBufferBuilder &_fbb, const ConfigCallT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateConfigCall(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<ConfigCall> CreateConfigCall(flatbuffers::FlatBufferBuilder &_fbb, const ConfigCallT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const ConfigCallT* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  return nfcdoorz::ipc::common::CreateConfigCall(
      _fbb);
}

inline ConfigReplyT *ConfigReply::UnPack(const flatbuffers::resolver_function_t *_resolver) const {
  auto _o = new ConfigReplyT();
  UnPackTo(_o, _resolver);
  return _o;
}

inline void ConfigReply::UnPackTo(ConfigReplyT *_o, const flatbuffers::resolver_function_t *_resolver) const {
  (void)_o;
  (void)_resolver;
  { auto _e = config(); if (_e) _o->config = _e->str(); };
}

inline flatbuffers::Offset<ConfigReply> ConfigReply::Pack(flatbuffers::FlatBufferBuilder &_fbb, const ConfigReplyT* _o, const flatbuffers::rehasher_function_t *_rehasher) {
  return CreateConfigReply(_fbb, _o, _rehasher);
}

inline flatbuffers::Offset<ConfigReply> CreateConfigReply(flatbuffers::FlatBufferBuilder &_fbb, const ConfigReplyT *_o, const flatbuffers::rehasher_function_t *_rehasher) {
  (void)_rehasher;
  (void)_o;
  struct _VectorArgs { flatbuffers::FlatBufferBuilder *__fbb; const ConfigReplyT* __o; const flatbuffers::rehasher_function_t *__rehasher; } _va = { &_fbb, _o, _rehasher}; (void)_va;
  auto _config = _o->config.empty() ? 0 : _fbb.CreateString(_o->config);
  return nfcdoorz::ipc::common::CreateConfigReply(
      _fbb,
      _config);
}

inline const flatbuffers::TypeTable *ConfigCallTypeTable() {
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 0, nullptr, nullptr, nullptr, nullptr
  };
  return &tt;
}

inline const flatbuffers::TypeTable *ConfigReplyTypeTable() {
  static const flatbuffers::TypeCode type_codes[] = {
    { flatbuffers::ET_STRING, 0, -1 }
  };
  static const char * const names[] = {
    "config"
  };
  static const flatbuffers::TypeTable tt = {
    flatbuffers::ST_TABLE, 1, type_codes, nullptr, nullptr, names
  };
  return &tt;
}

}  // namespace common
}  // namespace ipc
}  // namespace nfcdoorz

#endif  // FLATBUFFERS_GENERATED_IPCCOMMON_NFCDOORZ_IPC_COMMON_H_
