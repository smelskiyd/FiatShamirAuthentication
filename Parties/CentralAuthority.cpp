//
// Created by Danya Smelskiy on 30.05.2022.
//

#include "CentralAuthority.h"

#include <iostream>

CentralAuthority::CentralAuthority() {
    Dodecahedron::Bigint p = 13;
    Dodecahedron::Bigint q = 19;

    n_ = p * q;
}

std::optional<Dodecahedron::Bigint> CentralAuthority::getUserPublicKey(const std::string& user_id) const {
    const auto& user_it = key_by_user_id_.find(user_id);

    if (user_it == key_by_user_id_.end()) {
        return std::nullopt;
    }

    return user_it->second;
}

const Dodecahedron::Bigint& CentralAuthority::getModule() const {
    return n_;
}

void CentralAuthority::registerUser(const std::string& user_id, const Dodecahedron::Bigint& public_key) {
    if (key_by_user_id_.find(user_id) != key_by_user_id_.end()) {
        key_by_user_id_[user_id] = public_key;
    } else {
        std::cerr << "Error: User '" << user_id << "' is already registered." << std::endl;
    }
}
