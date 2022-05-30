//
// Created by Danya Smelskiy on 30.05.2022.
//

#include "CentralAuthority.h"

#include <iostream>

#include "crypto_algorithms.h"

CentralAuthority::CentralAuthority() {
    BigInteger p = Crypto::GetRandomPrimeNumbersWithSomeBitness(32)[0];
    BigInteger q = Crypto::GetRandomPrimeNumbersWithSomeBitness(32)[0];

    n_ = p * q;
}

std::optional<BigInteger> CentralAuthority::getUserPublicKey(const std::string& user_id) const {
    const auto& user_it = key_by_user_id_.find(user_id);

    if (user_it == key_by_user_id_.end()) {
        return std::nullopt;
    }

    return user_it->second;
}

const BigInteger& CentralAuthority::getModule() const {
    return n_;
}

void CentralAuthority::registerUser(const std::string& user_id, const BigInteger& public_key) {
    if (key_by_user_id_.find(user_id) == key_by_user_id_.end()) {
        std::cout << "New user '" << user_id << "' with public key '"
                  << public_key << "' was registered." << std::endl;
        key_by_user_id_[user_id] = public_key;
    } else {
        std::cerr << "Error: User '" << user_id << "' is already registered." << std::endl;
    }
}
