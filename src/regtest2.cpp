// regtest2.cpp - originally written and placed in the public domain by Wei Dai
//                regtest.cpp split into 3 files due to OOM kills by JW
//                in April 2017. A second split occured in July 2018.

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1

#include "Crypto++/bench.h"
#include "Crypto++/cpu.h"
#include "Crypto++/cryptlib.h"
#include "Crypto++/factory.h"

// For MAC's
#include "Crypto++/cmac.h"
#include "Crypto++/dmac.h"
#include "Crypto++/hmac.h"
#include "Crypto++/ttmac.h"
#include "Crypto++/vmac.h"

// Ciphers
#include "Crypto++/blake2.h"
#include "Crypto++/chacha.h"
#include "Crypto++/keccak.h"
#include "Crypto++/md5.h"
#include "Crypto++/panama.h"
#include "Crypto++/poly1305.h"
#include "Crypto++/ripemd.h"
#include "Crypto++/sha.h"
#include "Crypto++/sha3.h"
#include "Crypto++/siphash.h"

// Stream ciphers
#include "Crypto++/arc4.h"
#include "Crypto++/chacha.h"
#include "Crypto++/hc128.h"
#include "Crypto++/hc256.h"
#include "Crypto++/panama.h"
#include "Crypto++/rabbit.h"
#include "Crypto++/salsa.h"
#include "Crypto++/seal.h"
#include "Crypto++/sosemanuk.h"
#include "Crypto++/wake.h"

// Block for CMAC
#include "Crypto++/aes.h"
#include "Crypto++/des.h"

// Aggressive stack checking with VS2005 SP1 and above.
#if (_MSC_FULL_VER >= 140050727)
# pragma strict_gs_check (on)
#endif

#if CRYPTOPP_MSC_VERSION
# pragma warning(disable: 4505 4355)
#endif

USING_NAMESPACE(CryptoPP)

// MAC ciphers
void RegisterFactories2()
{
	RegisterDefaultFactoryFor<MessageAuthenticationCode, HMAC<Weak::MD5> >();
	RegisterDefaultFactoryFor<MessageAuthenticationCode, HMAC<RIPEMD160> >();
	RegisterDefaultFactoryFor<MessageAuthenticationCode, HMAC<SHA1> >();
	RegisterDefaultFactoryFor<MessageAuthenticationCode, HMAC<SHA224> >();
	RegisterDefaultFactoryFor<MessageAuthenticationCode, HMAC<SHA256> >();
	RegisterDefaultFactoryFor<MessageAuthenticationCode, HMAC<SHA384> >();
	RegisterDefaultFactoryFor<MessageAuthenticationCode, HMAC<SHA512> >();
	RegisterDefaultFactoryFor<MessageAuthenticationCode, TTMAC>();
	RegisterDefaultFactoryFor<MessageAuthenticationCode, VMAC<AES> >();
	RegisterDefaultFactoryFor<MessageAuthenticationCode, VMAC<AES, 64> >();
	RegisterDefaultFactoryFor<MessageAuthenticationCode, Weak::PanamaMAC<LittleEndian> >();
	RegisterDefaultFactoryFor<MessageAuthenticationCode, Weak::PanamaMAC<BigEndian> >();
	RegisterDefaultFactoryFor<MessageAuthenticationCode, CMAC<AES> >();
	RegisterDefaultFactoryFor<MessageAuthenticationCode, DMAC<AES> >();
	RegisterDefaultFactoryFor<MessageAuthenticationCode, Poly1305<AES> >();
	RegisterDefaultFactoryFor<MessageAuthenticationCode, Poly1305TLS>();
	RegisterDefaultFactoryFor<MessageAuthenticationCode, CMAC<DES_EDE3> >();
	RegisterDefaultFactoryFor<MessageAuthenticationCode, BLAKE2s>();
	RegisterDefaultFactoryFor<MessageAuthenticationCode, BLAKE2b>();
	RegisterDefaultFactoryFor<MessageAuthenticationCode, SipHash<2,4> >();
	RegisterDefaultFactoryFor<MessageAuthenticationCode, SipHash<4,8> >();
}

// Stream ciphers
void RegisterFactories3()
{
	RegisterSymmetricCipherDefaultFactories<Weak::MARC4>();
	RegisterSymmetricCipherDefaultFactories<SEAL<> >();
	RegisterSymmetricCipherDefaultFactories<SEAL<LittleEndian> >();
	RegisterSymmetricCipherDefaultFactories<WAKE_OFB<LittleEndian> >();
	RegisterSymmetricCipherDefaultFactories<WAKE_OFB<BigEndian> >();
	RegisterSymmetricCipherDefaultFactories<PanamaCipher<LittleEndian> >();
	RegisterSymmetricCipherDefaultFactories<PanamaCipher<BigEndian> >();

	RegisterSymmetricCipherDefaultFactories<Salsa20>();
	RegisterSymmetricCipherDefaultFactories<XSalsa20>();
	RegisterSymmetricCipherDefaultFactories<ChaCha>();
	RegisterSymmetricCipherDefaultFactories<ChaChaTLS>();
	RegisterSymmetricCipherDefaultFactories<XChaCha20>();
	RegisterSymmetricCipherDefaultFactories<Sosemanuk>();
	RegisterSymmetricCipherDefaultFactories<Rabbit>();
	RegisterSymmetricCipherDefaultFactories<RabbitWithIV>();
	RegisterSymmetricCipherDefaultFactories<HC128>();
	RegisterSymmetricCipherDefaultFactories<HC256>();
}
