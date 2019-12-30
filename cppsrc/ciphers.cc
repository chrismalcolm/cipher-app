#include "./cipher/affine.h"
#include "./cipher/caesar.h"
#include "./cipher/subsitution.h"
#include "./cipher/vigenere.h"
#include "ciphers.h"

namespace ciphers {

    Napi::String AffineEncryptWrapped(const Napi::CallbackInfo& info)
    {
        Napi::Env env = info.Env();

        const int length = info.Length();
        if (length != 3 ) {
            Napi::TypeError::New(env, "Expected 3 arguments. Given "\
            + std::to_string(length) + ".").ThrowAsJavaScriptException();
        }

        if (!info[0].IsString()) {
            Napi::TypeError::New(env, "Expected 'string' for first argument.")\
            .ThrowAsJavaScriptException();
        }

        if (!info[1].IsNumber()) {
            Napi::TypeError::New(env, "Second argument must be an integer.")\
            .ThrowAsJavaScriptException();
        }

        if (!info[2].IsNumber()) {
            Napi::TypeError::New(env, "Third argument must be an integer.")\
            .ThrowAsJavaScriptException();
        }

        Napi::String plaintext = info[0].As<Napi::String>();
        Napi::Number a = info[1].As<Napi::Number>();
        Napi::Number b = info[2].As<Napi::Number>();

        std::string error = affine::verifyArguments(a, b);
        if (error != "") {
            Napi::TypeError::New(env, error).ThrowAsJavaScriptException();
        }

        std::string returnValue = affine::encrypt(plaintext, a, b);

        return Napi::String::New(env, returnValue);
    }

    Napi::String AffineDecryptWrapped(const Napi::CallbackInfo& info)
    {
        Napi::Env env = info.Env();

        const int length = info.Length();
        if (length != 3 ) {
            Napi::TypeError::New(env, "Expected 3 arguments. Given "\
            + std::to_string(length) + ".").ThrowAsJavaScriptException();
        }

        if (!info[0].IsString()) {
            Napi::TypeError::New(env, "Expected 'string' for first argument.")\
            .ThrowAsJavaScriptException();
        }

        if (!info[1].IsNumber()) {
            Napi::TypeError::New(env, "Second argument must be an integer.")\
            .ThrowAsJavaScriptException();
        }

        if (!info[2].IsNumber()) {
            Napi::TypeError::New(env, "Third argument must be an integer.")\
            .ThrowAsJavaScriptException();
        }

        Napi::String ciphertext = info[0].As<Napi::String>();
        Napi::Number a = info[1].As<Napi::Number>();
        Napi::Number b = info[2].As<Napi::Number>();

        std::string error = affine::verifyArguments(a, b);
        if (error != "") {
            Napi::TypeError::New(env, error).ThrowAsJavaScriptException();
        }

        std::string returnValue = affine::decrypt(ciphertext, a, b);

        return Napi::String::New(env, returnValue);
    }

    Napi::String CaesarEncryptWrapped(const Napi::CallbackInfo& info)
    {
        Napi::Env env = info.Env();

        const int length = info.Length();
        if (length != 2 ) {
            Napi::TypeError::New(env, "Expected 2 arguments. Given "\
            + std::to_string(length) + ".").ThrowAsJavaScriptException();
        }

        if (!info[0].IsString()) {
            Napi::TypeError::New(env, "Expected 'string' for first argument.")\
            .ThrowAsJavaScriptException();
        }

        if (!info[1].IsNumber()) {
            Napi::TypeError::New(env, "Second argument must be an integer.")\
            .ThrowAsJavaScriptException();
        }

        Napi::String plaintext = info[0].As<Napi::String>();
        Napi::Number shift = info[1].As<Napi::Number>();

        std::string error = caesar::verifyArguments(shift);
        if (error != "") {
            Napi::TypeError::New(env, error).ThrowAsJavaScriptException();
        }

        std::string returnValue = caesar::encrypt(plaintext, shift);

        return Napi::String::New(env, returnValue);
    }

    Napi::String CaesarDecryptWrapped(const Napi::CallbackInfo& info)
    {
        Napi::Env env = info.Env();

        const int length = info.Length();
        if (length != 2 ) {
            Napi::TypeError::New(env, "Expected 2 arguments. Given "\
            + std::to_string(length) + ".").ThrowAsJavaScriptException();
        }

        if (!info[0].IsString()) {
            Napi::TypeError::New(env, "Expected 'string' for first argument.")\
            .ThrowAsJavaScriptException();
        }

        if (!info[1].IsNumber()) {
            Napi::TypeError::New(env, "Second argument must be an integer.")\
            .ThrowAsJavaScriptException();
        }

        Napi::String ciphertext = info[0].As<Napi::String>();
        Napi::Number shift = info[1].As<Napi::Number>();

        std::string error = caesar::verifyArguments(shift);
        if (error != "") {
            Napi::TypeError::New(env, error).ThrowAsJavaScriptException();
        }

        std::string returnValue = caesar::decrypt(ciphertext, shift);

        return Napi::String::New(env, returnValue);
    }

    Napi::String SubsitutionEncryptWrapped(const Napi::CallbackInfo& info)
    {
        Napi::Env env = info.Env();

        const int length = info.Length();
        if (length != 2 ) {
            Napi::TypeError::New(env, "Expected 2 arguments. Given "\
            + std::to_string(length) + ".").ThrowAsJavaScriptException();
        }

        if (!info[0].IsString()) {
            Napi::TypeError::New(env, "Expected 'string' for first argument.")\
            .ThrowAsJavaScriptException();
        }

        if (!info[1].IsString()) {
            Napi::TypeError::New(env, "Second argument must be a string.")\
            .ThrowAsJavaScriptException();
        }

        Napi::String plaintext = info[0].As<Napi::String>();
        Napi::String keys = info[1].As<Napi::String>();

        std::string error = subsitution::verifyArguments(keys);
        if (error != "") {
            Napi::TypeError::New(env, error).ThrowAsJavaScriptException();
        }

        std::string returnValue = subsitution::encrypt(plaintext, keys);

        return Napi::String::New(env, returnValue);
    }

    Napi::String SubsitutionDecryptWrapped(const Napi::CallbackInfo& info)
    {
        Napi::Env env = info.Env();

        const int length = info.Length();
        if (length != 2 ) {
            Napi::TypeError::New(env, "Expected 2 arguments. Given "\
            + std::to_string(length) + ".").ThrowAsJavaScriptException();
        }

        if (!info[0].IsString()) {
            Napi::TypeError::New(env, "Expected 'string' for first argument.")\
            .ThrowAsJavaScriptException();
        }

        if (!info[1].IsString()) {
            Napi::TypeError::New(env, "Second argument must be a string.")\
            .ThrowAsJavaScriptException();
        }

        Napi::String ciphertext = info[0].As<Napi::String>();
        Napi::String keys = info[1].As<Napi::String>();


        std::string error = subsitution::verifyArguments(keys);
        if (error != "") {
            Napi::TypeError::New(env, error).ThrowAsJavaScriptException();
        }

        std::string returnValue = subsitution::decrypt(ciphertext, keys);

        return Napi::String::New(env, returnValue);
    }

    Napi::String VigenereEncryptWrapped(const Napi::CallbackInfo& info)
    {
        Napi::Env env = info.Env();

        const int length = info.Length();
        if (length != 2 ) {
            Napi::TypeError::New(env, "Expected 2 arguments. Given "\
            + std::to_string(length) + ".").ThrowAsJavaScriptException();
        }

        if (!info[0].IsString()) {
            Napi::TypeError::New(env, "Expected 'string' for first argument.")\
            .ThrowAsJavaScriptException();
        }

        if (!info[1].IsString()) {
            Napi::TypeError::New(env, "Second argument must be a string.")\
            .ThrowAsJavaScriptException();
        }

        Napi::String plaintext = info[0].As<Napi::String>();
        Napi::String keyword = info[1].As<Napi::String>();

        std::string error = vigenere::verifyArguments(keyword);
        if (error != "") {
            Napi::TypeError::New(env, error).ThrowAsJavaScriptException();
        }

        std::string returnValue = vigenere::encrypt(plaintext, keyword);

        return Napi::String::New(env, returnValue);
    }

    Napi::String VigenereDecryptWrapped(const Napi::CallbackInfo& info)
    {
        Napi::Env env = info.Env();

        const int length = info.Length();
        if (length != 2 ) {
            Napi::TypeError::New(env, "Expected 2 arguments. Given "\
            + std::to_string(length) + ".").ThrowAsJavaScriptException();
        }

        if (!info[0].IsString()) {
            Napi::TypeError::New(env, "Expected 'string' for first argument.")\
            .ThrowAsJavaScriptException();
        }

        if (!info[1].IsString()) {
            Napi::TypeError::New(env, "Second argument must be a string.")\
            .ThrowAsJavaScriptException();
        }

        Napi::String ciphertext = info[0].As<Napi::String>();
        Napi::String keyword = info[1].As<Napi::String>();

        std::string error = vigenere::verifyArguments(keyword);
        if (error != "") {
            Napi::TypeError::New(env, error).ThrowAsJavaScriptException();
        }

        std::string returnValue = vigenere::decrypt(ciphertext, keyword);

        return Napi::String::New(env, returnValue);
    }

    Napi::Object Init(Napi::Env env, Napi::Object exports)
    {
        exports.Set("cipherAffineEncrpyt", Napi::Function::New(env, AffineEncryptWrapped));
        exports.Set("cipherAffineDecrpyt", Napi::Function::New(env, AffineDecryptWrapped));
        exports.Set("cipherCaesarEncrpyt", Napi::Function::New(env, CaesarEncryptWrapped));
        exports.Set("cipherCaesarDecrpyt", Napi::Function::New(env, CaesarDecryptWrapped));
        exports.Set("cipherSubsitutionEncrpyt", Napi::Function::New(env, SubsitutionEncryptWrapped));
        exports.Set("cipherSubsitutionDecrpyt", Napi::Function::New(env, SubsitutionDecryptWrapped));
        exports.Set("cipherVigenereEncrpyt", Napi::Function::New(env, VigenereEncryptWrapped));
        exports.Set("cipherVigenereDecrpyt", Napi::Function::New(env, VigenereDecryptWrapped));

        return exports;
    }

}
