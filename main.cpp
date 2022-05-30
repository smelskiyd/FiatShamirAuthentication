//
// Created by Danya Smelskiy on 29.05.2022.
//

#include <iostream>
#include <random>

#include "CentralAuthority.h"
#include "User.h"

#include "crypto_algorithms.h"


const char* kAliceUserId = "Alice";

constexpr uint32_t kNumberOfTests = 30;


bool VerifyUser(const CentralAuthority& ca, User& user, const std::string user_id) {
    const auto& user_public_key = ca.getUserPublicKey(user_id);

    if (!user_public_key.has_value()) {
        std::cerr << "User doesn't exist." << std::endl;
        return false;
    }

    for (uint32_t i = 0; i < kNumberOfTests; ++i) {
        BigInteger x = user.initAuthentication();

        bool e = (rand() & 1);
        const auto& y = user.processChallenge(e);

        if (!y.has_value()) {
            return false;
        }

        BigInteger expected_value = e ? (x * user_public_key.value()) % ca.getModule()
                                      : x;

        if (expected_value != (y.value() * y.value()) % ca.getModule()) {
            return false;
        }
    }

    printf("User '%s' passed t=%d tests and has successfully authorized.\n", user_id.c_str(), kNumberOfTests);

    return true;
}

int main() {
    Crypto::RandomSeedInitialization();

    CentralAuthority ca;

    printf("Module N = %s\n", ca.getModule().ToString().c_str());

    User alice(kAliceUserId, ca.getModule());
    ca.registerUser(kAliceUserId, alice.getPublicKey());

    if (!VerifyUser(ca, alice, kAliceUserId)) {
        printf("Failed to successfully authorize user '%s'.\n", kAliceUserId);
    }

    return 0;
}
