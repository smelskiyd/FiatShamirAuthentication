//
// Created by Danya Smelskiy on 30.05.2022.
//

#pragma once

#include <string>
#include <map>
#include <optional>

#include "bigint.h"

class CentralAuthority {
  public:
    CentralAuthority();

    std::optional<Dodecahedron::Bigint> getUserPublicKey(const std::string& user_id) const;

    const Dodecahedron::Bigint& getModule() const;

    void registerUser(const std::string& user_id, const Dodecahedron::Bigint& public_key);

  private:
    Dodecahedron::Bigint n_;
    std::map<std::string, Dodecahedron::Bigint> key_by_user_id_;
};
