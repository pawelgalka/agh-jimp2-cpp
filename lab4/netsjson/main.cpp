//
// Created by pawel on 24.03.18.
//

#include "SimpleJson.h"
using namespace nets;

int main(){
    JsonValue j{R"("abc")"s};
    cout << j.ToString();
    return 0;
}