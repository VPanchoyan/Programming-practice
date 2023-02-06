#include <iostream>

unsigned char power_of_two(unsigned char);

class Bitset {
public:
    Bitset(int lenght);
    void set_bit(int index);
    void reset_bit(int index);
    void set_size(int size);
    int get_size() const {  return m_size;  };
    bool valid_index(int index);
    ~Bitset();
private:
    int m_size;
    double* m_arr;
};

unsigned char power_of_two(unsigned char power) {
    if(power >= 0) {
        return 1 << power;
    }
    return 0;
}

Bitset::Bitset(int size) {
    set_size(size);
    m_arr = new double[m_size / sizeof(double) + 1] {};
}

Bitset::~Bitset() {
    delete[] m_arr;
}

void Bitset::set_size(int size) {
    if(size > 0) {
        m_size = size;
    } 
    else {
        m_size = 0;
    }
}

bool Bitset::valid_index(int index) {
    if (index < 0 || index > m_size) {
        return false;
    }
    return true;
}

void Bitset::set_bit(int index) {
    if (!valid_index(index)) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    unsigned char relative_index = index % sizeof(char);
    int byte_index = index / sizeof(char);
    unsigned char* p_to_byte = (unsigned char*) m_arr;
    p_to_byte += byte_index;
    unsigned char bit = power_of_two(relative_index);
    if(*(p_to_byte) ^ bit > *(p_to_byte)) {
        *(p_to_byte) ^= bit;
    }
}

void Bitset::reset_bit(int index) {
    if (!valid_index(index)) {
        std::cout << "Invalid index!" << std::endl;
        return;
    }
    unsigned char relative_index = index % sizeof(char);
    int byte_index = index / sizeof(char);
    unsigned char* p_to_byte = (unsigned char*) m_arr;
    p_to_byte += byte_index;
    unsigned char bit = power_of_two(relative_index);
    if(*(p_to_byte) ^ bit < *(p_to_byte)) {
        *(p_to_byte) ^= bit;
    }
}

int main() {
    Bitset b(100);
    b.set_bit(18);
    b.reset_bit(18);
}