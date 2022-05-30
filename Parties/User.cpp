//
// Created by Danya Smelskiy on 30.05.2022.
//

#include "User.h"

#include "crypto_algorithms.h"


User::User(const std::string& user_id, const BigInteger& n) {
    n_ = n;

    user_id_ = user_id;

    while (true) {
        BigInteger current_number = Crypto::GetRandomPrimeNumbers(1, n_ - 1, 1)[0];

        if (BigInteger::gcd(n_, current_number) == 1) {
            private_key_ = current_number;
            break;
        }
    }

    public_key_ = (private_key_ * private_key_) % n;
}

const BigInteger& User::getPublicKey() const {
    return public_key_;
}

const std::string& User::getUserId() const {
    return user_id_;
}

BigInteger User::initAuthentication() {
    r_ = Crypto::GetRandomNumber(1, n_ - 1);

    return (r_.value() * r_.value()) % n_;
}

std::optional<BigInteger> User::processChallenge(bool e) {
    if (!r_.has_value()) {
        return std::nullopt;
    }

    BigInteger result = e ? (r_.value() * private_key_) % n_
                          : r_.value();

    r_.reset();

    return result;
}
