#ifndef HEX_HPP
#define HEX_HPP

#include <iostream>
#include <vector>

class Hex {
public:
    Hex();
    Hex(const std::string& hex_string);
    Hex(const Hex& other);
    Hex& operator=(const Hex& other);
    Hex operator+(const Hex& other) const;
    Hex operator-(const Hex& other) const;
    Hex& operator+=(const Hex& other);
    Hex& operator-=(const Hex& other);
    bool operator==(const Hex& other) const;
    bool operator!=(const Hex& other) const;
    bool operator<(const Hex& other) const;
    bool operator>(const Hex& other) const;
    bool operator<=(const Hex& other) const;
    bool operator>=(const Hex& other) const;
    friend std::ostream& operator<<(std::ostream& os, const Hex& hex);

private:
    std::vector<unsigned char> data;

    void normalize();
};

#endif 
