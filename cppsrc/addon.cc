#include <napi.h>
#include "ciphers.h"

Napi::Object InitAll(Napi::Env env, Napi::Object exports)
{
    return ciphers::Init(env, exports);
}

NODE_API_MODULE(cipher, InitAll)
