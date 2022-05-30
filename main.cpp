//
// Created by Danya Smelskiy on 29.05.2022.
//

#include <iostream>

#include "CentralAuthority.h"
#include "User.h"

const char* kAliceUserId = "Alice";

int main() {
    CentralAuthority ca;

    std::cout << "Module N = " << ca.getModule() << std::endl;

    User alice(kAliceUserId, ca.getModule());
    ca.registerUser(kAliceUserId, alice.getPublicKey());
}
