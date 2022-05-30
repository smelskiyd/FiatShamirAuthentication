//
// Created by Danya Smelskiy on 30.05.2022.
//

#pragma once

#include <string>
#include <map>
#include <optional>

#include "big_integer.h"

class CentralAuthority {
  public:
    CentralAuthority();

    std::optional<BigInteger> getUserPublicKey(const std::string& user_id) const;

    const BigInteger& getModule() const;

    void registerUser(const std::string& user_id, const BigInteger& public_key);

  private:
    BigInteger n_;
    std::map<std::string, BigInteger> key_by_user_id_;
};
