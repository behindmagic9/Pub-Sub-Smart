#pragma once
#include<string>
#include<iostream>

enum class Topic { Animal, Birds };

struct Event {
    Topic topic;
    std::string data;
};

inline std::ostream& operator<<(std::ostream& os, const Topic& type) {
    switch (type) {
        case Topic::Animal: return os << " Animal";
        case Topic::Birds : return os << "Birds";
        default:  return os << "Unkonwn ";
    }
}

struct Topichash {
    std::size_t operator()(Topic t) const noexcept {
        return static_cast<std::size_t>(t);
    }
};