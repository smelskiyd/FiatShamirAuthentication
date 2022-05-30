//
// Created by Danya Smelskiy on 30.05.2022.
//

#pragma once

#include <string>
#include <optional>

#include "big_integer.h"

class User {
  public:
    User(const std::string& user_id, const BigInteger& n);

    const BigInteger& getPublicKey() const;

    const std::string& getUserId() const;

    BigInteger initAuthentication();

    std::optional<BigInteger> processChallenge(bool e);

  private:
    BigInteger n_;

    std::string user_id_;
    BigInteger public_key_;
    BigInteger private_key_;

    // Authentication
    std::optional<BigInteger> r_;
};
