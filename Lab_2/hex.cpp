
#include "hex.hpp"
#include <stdexcept>
#include <iomanip>

Hex::Hex() {
    data.push_back(0);
}

Hex::Hex(const std::string& hex_string) {
    if (hex_string.empty()) {
        data.push_back(0);
        return;
    }

    for (char c : hex_string) {
        if (!isxdigit(c)) {
            throw std::invalid_argument("Invalid hex string");
        }
    }

    for (size_t i = 0; i < hex_string.length(); i += 2) {
        std::string byteStr = hex_string.substr(i, 2);
        unsigned char byte = static_cast<unsigned char>(std::stoi(byteStr, nullptr, 16));
        data.push_back(byte);
    }
}

Hex::Hex(const Hex& other) : data(other.data) {}

Hex& Hex::operator=(const Hex& other) {
    if (this != &other) {
        data = other.data;
    }
    return *this;
}

Hex Hex::operator+(const Hex& other) const {
    Hex result;
    result.data.resize(std::max(data.size(), other.data.size()), 0);
    unsigned char carry = 0;

    for (size_t i = 0; i < result.data.size(); ++i) {
        unsigned char a = i < data.size() ? data[i] : 0;
        unsigned char b = i < other.data.size() ? other.data[i] : 0;
        unsigned char sum = a + b + carry;
        carry = sum >> 8;
        result.data[i] = sum & 0xFF;
    }

    if (carry > 0) {
        result.data.push_back(carry);
    }

    return result;
}

Hex Hex::operator-(const Hex& other) const {
    Hex result;
    result.data.resize(data.size(), 0);
    unsigned char borrow = 0;

    for (size_t i = 0; i < data.size(); ++i) {
        unsigned char a = data[i];
        unsigned char b = i < other.data.size() ? other.data[i] : 0;
        if (a < b + borrow) {
            result.data[i] = 256 + a - b - borrow;
            borrow = 1;
        } else {
            result.data[i] = a - b - borrow;
            borrow = 0;
        }
    }

    return result;
}

Hex& Hex::operator+=(const Hex& other) {
    *this = *this + other;
    return *this;
}

Hex& Hex::operator-=(const Hex& other) {
    *this = *this - other;
    return *this;
}

bool Hex::operator==(const Hex& other) const {
    return data == other.data;
}

bool Hex::operator!=(const Hex& other) const {
    return !(*this == other);
}

bool Hex::operator<(const Hex& other) const {
    if (data.size() < other.data.size()) {
        return true;
    } else if (data.size() > other.data.size()) {
        return false;
    }

    for (int i = data.size() - 1; i >= 0; --i) {
        if (data[i] < other.data[i]) {
            return true;
        } else if (data[i] > other.data[i]) {
            return false;
        }
    }

    return false;
}

bool Hex::operator>(const Hex& other) const {
    return !(*this <= other);
}

bool Hex::operator<=(const Hex& other) const {
    return *this < other || *this == other;
}

bool Hex::operator>=(const Hex& other) const {
    return !(*this < other);
}

void Hex::normalize() {
    while (data.size() > 1 && data.back() == 0) {
        data.pop_back();
    }
}

std::ostream& operator<<(std::ostream& os, const Hex& hex) {
    for (size_t i = hex.data.size(); i-- > 0;) {
        os << std::hex << std::uppercase << std::setw(2) << std::setfill('0') << static_cast<unsigned>(hex.data[i]);
    }
    return os;
}
