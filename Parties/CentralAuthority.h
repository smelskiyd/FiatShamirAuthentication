//
// Created by Danya Smelskiy on 30.05.2022.
//

#pragma once

#include <string>
#include <map>
#include <optional>

class CentralAuthority {
  public:
    CentralAuthority();

    std::optional<long long> getUserPublicKey(const std::string& user_id) const;

    long long getModule() const;

    void registerUser(const std::string& user_id, long long public_key);

  private:
    long long n_;
    std::map<std::string, long long> key_by_user_id_;
};
