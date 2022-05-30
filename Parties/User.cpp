//
// Created by Danya Smelskiy on 30.05.2022.
//

#include "User.h"

User::User(const std::string& user_id, const long long& n) {
    n_ = n;

    user_id_ = user_id;

    private_key_ = 7;
    public_key_ = (private_key_ * private_key_) % n;
}

const long long& User::getPublicKey() const {
    return public_key_;
}

const std::string& User::getUserId() const {
    return user_id_;
}

long long User::initAuthentication() {
    r_ = 16;

    return (r_.value() * r_.value()) % n_;
}

std::optional<long long> User::processChallenge(bool e) {
    if (!r_.has_value()) {
        return std::nullopt;
    }

    long long result = e ? (r_.value() * private_key_) % n_
                         : r_.value();

    r_.reset();

    return result;
}
