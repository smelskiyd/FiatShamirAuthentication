//
// Created by Danya Smelskiy on 30.05.2022.
//

#pragma once

#include <string>
#include <optional>

class User {
  public:
    User(const std::string& user_id, const long long& n);

    const long long& getPublicKey() const;

    const std::string& getUserId() const;

    long long initAuthentication();

    std::optional<long long> processChallenge(bool e);

  private:
    long long n_;

    std::string user_id_;
    long long public_key_;
    long long private_key_;

    // Authentication
    std::optional<long long> r_;
};
