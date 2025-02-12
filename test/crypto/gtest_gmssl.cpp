#include "ypc/corecommon/crypto/gmssl/sm2_ecc.h"
#include "ypc/corecommon/crypto/gmssl/sm3_hash.h"
#include "ypc/corecommon/crypto/gmssl/sm4_aes.h"
#include "ypc/stbox/stx_status.h"
#include "ypc/core/byte.h"
#include <gmssl/sm2.h>
#include <gmssl/sm4.h>
#include <gtest/gtest.h>

void show_hex(uint8_t *data, size_t size) {
  for (int i = 0; i < size; i++) {
    printf("%02x", *(data + i));
  }
  std::cout << std::endl;
}

TEST(test_sm3_hash, hash_256) {
  ypc::bytes msg = ypc::hex_bytes(
          "4413bf3c7fcdc585adac2098ea5db205e32d0f41e02e0962a5ca1f34df6b99c2a114bb37c857cd863fecb9b4ccd58356acfa03cf89e896fd135b35f07225e6ad")
          .as<ypc::bytes>();
  uint8_t hash[32];
  uint32_t ret = ypc::crypto::sm3_hash::hash_256(msg.data(), msg.size(), hash);
  EXPECT_EQ(ret, 0);
  ypc::bytes expect_hash =
      ypc::hex_bytes(
          "5e234972d849bb60ed52f3425aa7ed456c636ea251a6f0acb72f263b45930724")
          .as<ypc::bytes>();
  EXPECT_TRUE(memcmp(hash, expect_hash.data(), 32) == 0);

  printf("3\n");

  ypc::bytes msg_4 = ypc::hex_bytes(
          "42b0333c3ebac579cd15ddff3a5087b5e81844811c54bc57798939265940f9f7f83884492deb4200ff5c13a59e45d39a192c0d80fa7823787c74ed663c2f5d09")
          .as<ypc::bytes>();
  uint8_t hash_4[32];
  uint32_t ret_4 =
      ypc::crypto::sm3_hash::hash_256(msg_4.data(), msg_4.size(), hash_4);
  EXPECT_EQ(ret_4, 0);
  ypc::bytes expect_hash_4 =
      ypc::hex_bytes(
          "55de388c1a323a0d1aa0daea79910a1205b07d08ac7e58cf559e47c34996d956")
          .as<ypc::bytes>();
  EXPECT_TRUE(memcmp(hash_4, expect_hash_4.data(), 32) == 0);

  printf("4\n");

  ypc::bytes msg_5 = ypc::hex_bytes(
          "7c84edc37c73bc42b0dcc1349c493fc4ee4dea15548f125c26d66c84612c21338377e52a4efdbe7e672c70a041a1c35ac844a465642f449100c1f0f44cea061b")
          .as<ypc::bytes>();
  uint8_t hash_5[32];
  uint32_t ret_5 =
      ypc::crypto::sm3_hash::hash_256(msg_5.data(), msg_5.size(), hash_5);
  EXPECT_EQ(ret_5, 0);
  ypc::bytes expect_hash_5 =
      ypc::hex_bytes(
          "e734278009fd70e445d8473ae3d25c2c67f90b1c51683155c9ea8de10da31026")
          .as<ypc::bytes>();
  EXPECT_TRUE(memcmp(hash_5, expect_hash_5.data(), 32) == 0);

  printf("5\n");

    ypc::bytes msg_6 = ypc::hex_bytes(
          "95dab3553a3163dfea00acef231116f5efda38c361f87937216716235398df81f64b32bb83e94f386c9991ca7420eafd07b0614a70c980f5ebac2fa01037a88e")
          .as<ypc::bytes>();
  uint8_t hash_6[32];
  uint32_t ret_6 =
      ypc::crypto::sm3_hash::hash_256(msg_6.data(), msg_6.size(), hash_6);
  EXPECT_EQ(ret_6, 0);
  ypc::bytes expect_hash_6 =
      ypc::hex_bytes(
          "fe6da9c7d5e068d62518f3201b8429fbbbe90e49494845b8bd4b0b5d87cd25df")
          .as<ypc::bytes>();
  EXPECT_TRUE(memcmp(hash_6, expect_hash_6.data(), 32) == 0);

  printf("6\n");

    ypc::bytes msg_7 = ypc::hex_bytes(
          "44e04be5231a650cfe6ac892a1d2dc8cc0a49ec3e9d1d18afb648059021c02d2135054acd8b3c8a94c5c546691b33f2814faacad6fc1ef9f681d556a8c95e359")
          .as<ypc::bytes>();
  uint8_t hash_7[32];
  uint32_t ret_7 =
      ypc::crypto::sm3_hash::hash_256(msg_7.data(), msg_7.size(), hash_7);
  EXPECT_EQ(ret, 0);
  ypc::bytes expect_hash_7 =
      ypc::hex_bytes(
          "60872ef88c3084698f681f5646138de69a76955afd9a7d2d672b6714c2051826")
          .as<ypc::bytes>();
  EXPECT_TRUE(memcmp(hash_7, expect_hash_7.data(), 32) == 0);

  printf("7\n");

    ypc::bytes msg_8 = ypc::hex_bytes(
          "f9169975246ef06a1cc4f123641714bdf83335727eb9cba0564f443e6905f4d06dd3c721077d89cf81cd45e61677ec8725d252da04ada8a03d882e479bb5b8e4")
          .as<ypc::bytes>();
  uint8_t hash_8[32];
  uint32_t ret_8 =
      ypc::crypto::sm3_hash::hash_256(msg_8.data(), msg_8.size(), hash_8);
  EXPECT_EQ(ret_8, 0);
  ypc::bytes expect_hash_8 =
      ypc::hex_bytes(
          "7d00368f1b00eeb6119a75fc71048b73b023a58f76e0e3d8bfaba4e0bbb1744a")
          .as<ypc::bytes>();
  EXPECT_TRUE(memcmp(hash_8, expect_hash_8.data(), 32) == 0);

  printf("8\n");

  ypc::bytes msg_9 = ypc::hex_bytes(
          "2068d3eceaeacf438c93f9890dd081bb2875963a2b9d7854d46f314f35a898db3cc93900e75b26a16c5d91466cbad0bf36d56e9affad8c20cf1dbdc2c8a2b65b")
          .as<ypc::bytes>();
  uint8_t hash_9[32];
  uint32_t ret_9 =
      ypc::crypto::sm3_hash::hash_256(msg_9.data(), msg_9.size(), hash_9);
  EXPECT_EQ(ret_9, 0);
  ypc::bytes expect_hash_9 =
      ypc::hex_bytes(
          "d8b782817b51dcd017a4814ba0ec4c7fa243fc4d6f85efeeb8ebe0cb5b81d586")
          .as<ypc::bytes>();
  EXPECT_TRUE(memcmp(hash_9, expect_hash_9.data(), 32) == 0);

  printf("9\n");

    ypc::bytes msg_10 = ypc::hex_bytes(
          "e6b7c0709ad15426b7adc566c0a556636751636d30d2b56362edb59313e70ce5f3f59231f95a0213380694838bad66e853452c1c88b14ba50023b48d88e15f6e")
          .as<ypc::bytes>();
  uint8_t hash_10[32];
  uint32_t ret_10 =
      ypc::crypto::sm3_hash::hash_256(msg_10.data(), msg_10.size(), hash_10);
  EXPECT_EQ(ret_10, 0);
  ypc::bytes expect_hash_10 =
      ypc::hex_bytes(
          "9145d30c68cba3368fb81e145b4985a70ff5cb2b24c882f5b5d193b514b0333e")
          .as<ypc::bytes>();
  EXPECT_TRUE(memcmp(hash_10, expect_hash_10.data(), 32) == 0);

  printf("10\n");
}

TEST(test_sm3_hash, get_msg_hash_size) {
  EXPECT_EQ(ypc::crypto::sm3_hash::get_msg_hash_size(), 32);
}


TEST(test_sm3_hash, msg_hash) {

  std::string raw_msg = "10d06755ac11c2976e46502bc59fca6fc462d5fc50d5b6efbb558215769a523fe5ffbaff305fcd681fb0566b1a23a0dd67684b6bedf2a3a5b10b62d4302714b6";
  uint8_t hash[32];

  uint32_t ret = ypc::crypto::sm3_hash::msg_hash((const uint8_t *)&raw_msg[0],
                                                 raw_msg.size(), hash, 32);

  show_hex(hash, 32);
  EXPECT_EQ(ret, 0);
  ypc::bytes expect_hash =
      ypc::hex_bytes(
          "c651e1a40dad9f2392223e7a5ea0b120992bbfe9d74d926c87064d34e37bdb7d")
          .as<ypc::bytes>();
  //"becbbfaae6548b8bf0cfcad5a27183cd1be6093b1cceccc303d9c61d0a645268"
  EXPECT_TRUE(memcmp(hash, expect_hash.data(), 32) == 0);
}

TEST(test_sm2_ecc, get_private_key_size) {
  EXPECT_EQ(ypc::crypto::sm2_ecc::get_private_key_size(), 32);
}

TEST(test_sm2_ecc, get_public_key_size) {
  EXPECT_EQ(ypc::crypto::sm2_ecc::get_public_key_size(), 64);
}

TEST(test_sm2_ecc, gen_private_key) {
  uint8_t skey[32];
  uint32_t ret = ypc::crypto::sm2_ecc::gen_private_key(32, skey);
  EXPECT_EQ(ret, 0);
}

void get_expected_pkey(const ypc::bytes &skey, ypc::bytes &pkey) {
  SM2_KEY tmp;
  sm2_key_set_private_key(&tmp, skey.data());
  memcpy(pkey.data(), &tmp, 64);
  /*
  for (int i = 0; i < 64; i++) {
    printf("%02x", *(pkey.data() + i));
  }
  std::cout << std::endl;
  */
}

TEST(test_sm2_ecc, generate_pkey_from_skey) {
  ypc::hex_bytes skey_hex(
      "4f16ab84f1d146f036332f30cc00d76c6b598c01887d88d935e728d221f4506e");
  ypc::bytes skey = skey_hex.as<ypc::bytes>();
  uint8_t pkey[64];
  uint32_t ret = ypc::crypto::sm2_ecc::generate_pkey_from_skey(
      skey.data(), skey.size(), pkey, 64);
  EXPECT_EQ(ret, 0);
  ypc::bytes expect_pkey(64);
  get_expected_pkey(skey, expect_pkey);
  EXPECT_TRUE(memcmp(pkey, expect_pkey.data(), 64) == 0);
}

TEST(test_sm2_ecc, get_signature_size) {
  EXPECT_EQ(ypc::crypto::sm2_ecc::get_signature_size(), 64);
}

TEST(test_sm2_ecc, sign) {
  ypc::hex_bytes skey_hex(
      "d05fae562edcf8a854e37383b393c9c09067a96df8643644c32901a50b25e382");
  ypc::bytes skey = skey_hex.as<ypc::bytes>();
  std::string data = "f3cb5fcdb1266ed474011d547e87bc1adb0372117aa33dcca6ab3f04b91d283eecf710e1e9a2748b131f15ababd6e2a37675288bd1dae78cb51f3cdfbda55417";
  uint8_t hash[32];
  uint32_t ret = ypc::crypto::sm3_hash::msg_hash((const uint8_t *)&data[0],
                                                 data.size(), hash, 32);
  uint8_t sig[64];
  ret = ypc::crypto::sm2_ecc::sign_message(skey.data(), skey.size(), hash, 32,
                                           sig, 64);
  ypc::bytes expect_pkey(64);
  get_expected_pkey(skey, expect_pkey);
  ret = ypc::crypto::sm2_ecc::verify_signature(hash, 32, sig, 64,
                                               expect_pkey.data(), 64);

  for (int i = 0; i < 64; i++) {
    printf("%02x", *(sig + i));
  }
  std::cout << std::endl;
  EXPECT_EQ(ret, 0);

  printf("1\n");

   ypc::bytes false_sig =
      ypc::hex_bytes(
          "bcebe54da5082467e5946b9c7bce8ca64bb3025574a0e0ed4eaeec5a7099d81b9ae496e0d4d8ef1b03d2ce5abc5a64806fad321c44a3f987e899491c6782d786")
          .as<ypc::bytes>();
  //bcebe54da5082467e5946b9c7bce8ca64bb3025574a0e0ed4eaeec5a7099d81b9ae496e0d4d8ef1b03d2ce5abc5a64806fad321c44a3f987e899491c6782d787

  uint32_t fail_res = ypc::crypto::sm2_ecc::verify_signature(hash, 32, false_sig.data(), 64,
                                               expect_pkey.data(), 64);

  EXPECT_EQ(fail_res, stbox::stx_status::sm2_get_false_sign);
}


TEST(test_sm2_ecc, ecdh_shared_key) {
  ypc::hex_bytes skey_hex_a(
      "4f16ab84f1d146f036332f30cc00d76c6b598c01887d88d935e728d221f4506e");
  ypc::bytes skey_a = skey_hex_a.as<ypc::bytes>();
  ypc::bytes expect_pkey_a(64);
  get_expected_pkey(skey_a, expect_pkey_a);
  uint8_t shared_key_a[16], shared_key_b[16];

  ypc::hex_bytes skey_hex_b(
      "70c39e6e85f850193a623178b8bd4c798a36e62e71bb5ca106768246c2cb8baf");
  ypc::bytes skey_b = skey_hex_b.as<ypc::bytes>();
  ypc::bytes expect_pkey_b(64);
  get_expected_pkey(skey_b, expect_pkey_b);

  uint32_t ret = ypc::crypto::sm2_ecc::ecdh_shared_key(skey_a.data(), 32,
                                                expect_pkey_b.data(), 64,
                                                shared_key_a, 16);

  ret = ypc::crypto::sm2_ecc::ecdh_shared_key(skey_b.data(), 32,
                                                expect_pkey_a.data(), 64,
                                                shared_key_b, 16);
  EXPECT_TRUE(memcmp(shared_key_a, shared_key_b, 16) == 0);
  EXPECT_EQ(ret, 0);
}

TEST(test_sm4_aes, get_cipher_size) {
  std::string data = "hello";
  uint32_t data_size = data.size();
  EXPECT_EQ(ypc::crypto::sm4_aes::get_cipher_size(data_size), data_size + 12);
}

TEST(test_sm4_aes, encrypt_and_decrypt_with_prefix) {
  ypc::bytes key("k3Men*p/2.3j4abB");
  std::string data = "this|is|a|test|message";
  uint32_t data_size = data.size();
  uint32_t prefix = 0x1;
  uint32_t cipher_size = ypc::crypto::sm4_aes::get_cipher_size(data_size);
  uint8_t cipher[cipher_size] = {0};
  uint8_t out_mac[16] = {0};

  uint32_t ret = ypc::crypto::sm4_aes::encrypt_with_prefix(
      key.data(), key.size(), (const uint8_t *)&data[0], data_size, prefix,
      cipher, cipher_size, out_mac);
  EXPECT_EQ(ret, 0);

  std::string decrypted_data(data.size(), '0');
  ret = ypc::crypto::sm4_aes::decrypt_with_prefix(
      key.data(), key.size(), cipher, cipher_size, prefix,
      (uint8_t *)&decrypted_data[0], data_size, out_mac);
  EXPECT_EQ(ret, 0);
  EXPECT_EQ(data, decrypted_data);
}

TEST(test_sm4_aes, gcm_encrypt_decrypt) {
  ypc::bytes skey(32);
  ypc::crypto::sm2_ecc::gen_private_key(skey.size(), skey.data());
  ypc::bytes key(skey.data(), 16);

  std::string data = "this|is|a|test|message";
  std::string msg(data.size(), '0');
  // uint32_t cipher_size = ypc::crypto::sm4_aes::get_cipher_size(data.size());
  // std::cout << "data size: " << data.size() << ", cipher size: " <<
  // cipher_size
  //<< std::endl;
  // uint8_t cipher[cipher_size] = {0};
  uint8_t cipher[data.size()] = {0};
  uint8_t tag[16] = {0};
  // encrypt
  SM4_KEY sm4_key;
  sm4_set_encrypt_key(&sm4_key, key.data());
  // size_t sm4_key_size = sizeof(SM4_KEY);
  // uint8_t encrypt_key[sm4_key_size];
  // memcpy(encrypt_key, &sm4_key, sm4_key_size);
  // show_hex(encrypt_key, sm4_key_size);
  char aad[64] = {0};
  // uint8_t *p_iv_text = cipher + data.size();
  uint8_t p_iv_text[12] = {0};
  int ret =
      sm4_gcm_encrypt(&sm4_key, p_iv_text, 12, (const uint8_t *)aad, 64,
                      (const uint8_t *)&data[0], data.size(), cipher, 16, tag);
  std::cout << "sm4_gcm_encrypt return: " << ret << std::endl;

  // decrypt
  sm4_set_encrypt_key(&sm4_key, key.data());
  // uint8_t decrypt_key[sm4_key_size];
  // memcpy(decrypt_key, &sm4_key, sm4_key_size);
  // show_hex(decrypt_key, sm4_key_size);
  ret = sm4_gcm_decrypt(&sm4_key, p_iv_text, 12, (const uint8_t *)aad, 64,
                        cipher, data.size(), tag, 16, (uint8_t *)&msg[0]);
  std::cout << "sm4_gcm_decrypt return: " << ret << std::endl;
  std::cout << "msg: " << msg << std::endl;
}

TEST(test_sm4_aes, get_data_size) {
  ypc::bytes cipher =
      ypc::hex_bytes(
          "943fac246391f0653d32a92c9820e36c3e66d6672a83e2a93d18451caae0b2c1dba8")
          .as<ypc::bytes>();
  uint32_t cipher_size = cipher.size();
  EXPECT_EQ(ypc::crypto::sm4_aes::get_data_size(cipher_size), cipher_size - 12);
}
