#include <napi.h>

namespace ciphers {

    Napi::String AffineEncryptWrapped(const Napi::CallbackInfo& info);
    Napi::Object Init(Napi::Env env, Napi::Object exports);

}
