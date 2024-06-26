#ifndef TLWE_HPP
#define TLWE_HPP

#include <common.hpp>
#include <generator.hpp>
#include <tgsw.hpp>

class TLWESample{
private:
    std::vector<t32> a;
    std::vector<int> gadget_decomp;
    bool is_encrypted;
    s_int secret_key_num;

    TLWESample(TLWESample* s);

public:

    TLWESample(const Bitmap& s, s_int sk_num);

    void encrypt(t32 mu);
    void gadget_decomposition();
    void mult_by_gadget_matrix();

    // operations
    TLWESample operator+(TLWESample const& m);
    TLWESample operator*(int k);
    TLWESample operator*(TGSWSample C);

    t32 operator[](int i) const;
    t32& operator[](int i);
};

class ModdedTLWESample{
private:
    std::vector<t32> a;
    std::vector<uint32_t> overflows;
    bool is_encrypted;
    s_int secret_key_num;
    int p;

    ModdedTLWESample(ModdedTLWESample* s);
public:
    ModdedTLWESample(const Bitmap& s, s_int sk_num);

    void encrypt(t32 mu, int p);

    ModdedTLWESample operator+(ModdedTLWESample const& c);
    t32 operator[](int i) const;
    t32& operator[](int i);
    uint32_t get_overflows(int i);
    int get_p();

};

#endif // !TLWE_HPP
