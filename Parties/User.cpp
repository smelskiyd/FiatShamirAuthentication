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
