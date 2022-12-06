// Copyright (c) 2009-2010 Satoshi Nakamoto
// Copyright (c) 2009-2016 The Bitcoin Core developers
// Copyright (c) 2017-2019 The Raven Core developers
// Copyright (c) 2020 The VibofChain Core developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef VIBOFCHAIN_VIBOFCHAINCONSENSUS_H
#define VIBOFCHAIN_VIBOFCHAINCONSENSUS_H

#include <stdint.h>

#if defined(BUILD_VIBOFCHAIN_INTERNAL) && defined(HAVE_CONFIG_H)
#include "config/vibofchain-config.h"
  #if defined(_WIN32)
    #if defined(DLL_EXPORT)
      #if defined(HAVE_FUNC_ATTRIBUTE_DLLEXPORT)
        #define EXPORT_SYMBOL __declspec(dllexport)
      #else
        #define EXPORT_SYMBOL
      #endif
    #endif
  #elif defined(HAVE_FUNC_ATTRIBUTE_VISIBILITY)
    #define EXPORT_SYMBOL __attribute__ ((visibility ("default")))
  #endif
#elif defined(MSC_VER) && !defined(STATIC_LIBVIBOFCHAINCONSENSUS)
  #define EXPORT_SYMBOL __declspec(dllimport)
#endif

#ifndef EXPORT_SYMBOL
  #define EXPORT_SYMBOL
#endif

#ifdef __cplusplus
extern "C" {
#endif

#define VIBOFCHAINCONSENSUS_API_VER 1

typedef enum vibofchainconsensus_error_t
{
    vibofchainconsensus_ERR_OK = 0,
    vibofchainconsensus_ERR_TX_INDEX,
    vibofchainconsensus_ERR_TX_SIZE_MISMATCH,
    vibofchainconsensus_ERR_TX_DESERIALIZE,
    vibofchainconsensus_ERR_AMOUNT_REQUIRED,
    vibofchainconsensus_ERR_INVALID_FLAGS,
} vibofchainconsensus_error;

/** Script verification flags */
enum
{
    vibofchainconsensus_SCRIPT_FLAGS_VERIFY_NONE                = 0,
    vibofchainconsensus_SCRIPT_FLAGS_VERIFY_P2SH                = (1U << 0), // evaluate P2SH (BIP16) subscripts
    vibofchainconsensus_SCRIPT_FLAGS_VERIFY_DERSIG              = (1U << 2), // enforce strict DER (BIP66) compliance
    vibofchainconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY           = (1U << 4), // enforce NULLDUMMY (BIP147)
    vibofchainconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY = (1U << 9), // enable CHECKLOCKTIMEVERIFY (BIP65)
    vibofchainconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY = (1U << 10), // enable CHECKSEQUENCEVERIFY (BIP112)
    vibofchainconsensus_SCRIPT_FLAGS_VERIFY_WITNESS             = (1U << 11), // enable WITNESS (BIP141)
    vibofchainconsensus_SCRIPT_FLAGS_VERIFY_ALL                 = vibofchainconsensus_SCRIPT_FLAGS_VERIFY_P2SH | vibofchainconsensus_SCRIPT_FLAGS_VERIFY_DERSIG |
                                                               vibofchainconsensus_SCRIPT_FLAGS_VERIFY_NULLDUMMY | vibofchainconsensus_SCRIPT_FLAGS_VERIFY_CHECKLOCKTIMEVERIFY |
                                                               vibofchainconsensus_SCRIPT_FLAGS_VERIFY_CHECKSEQUENCEVERIFY | vibofchainconsensus_SCRIPT_FLAGS_VERIFY_WITNESS
};

/// Returns 1 if the input nIn of the serialized transaction pointed to by
/// txTo correctly spends the scriptPubKey pointed to by scriptPubKey under
/// the additional constraints specified by flags.
/// If not nullptr, err will contain an error/success code for the operation
EXPORT_SYMBOL int vibofchainconsensus_verify_script(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen,
                                                 const unsigned char *txTo        , unsigned int txToLen,
                                                 unsigned int nIn, unsigned int flags, vibofchainconsensus_error* err);

EXPORT_SYMBOL int vibofchainconsensus_verify_script_with_amount(const unsigned char *scriptPubKey, unsigned int scriptPubKeyLen, int64_t amount,
                                    const unsigned char *txTo        , unsigned int txToLen,
                                    unsigned int nIn, unsigned int flags, vibofchainconsensus_error* err);

EXPORT_SYMBOL unsigned int vibofchainconsensus_version();

#ifdef __cplusplus
} // extern "C"
#endif

#undef EXPORT_SYMBOL

#endif // VIBOFCHAIN_VIBOFCHAINCONSENSUS_H
