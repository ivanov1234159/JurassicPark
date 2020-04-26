//
// Created by toi on 25/03/2020.
//

#ifndef JURASSICPARK_CAGE_HPP
#define JURASSICPARK_CAGE_HPP

#include "Dinosaur.hpp"
#include <fstream>
//for: ifstream, ofstream

/*enum class CageClimate {
    UNKNOWN = -1,
    MEDITERRANEAN,
    SUBTROPICAL,
    OCEANIC,
    CONTINENTAL
};

enum class CageSize {
    SMALL, // size for 1
    MEDIUM, // size for 3
    LARGE // size for 10
};*/

class Cage {
    char* m_climate;
    unsigned m_size;// list limit
    char* m_era;// if any dinosaur; all dinosaurs MUST be (and are) from one era
    Dinosaur* m_list;
    unsigned m_list_count;// list count
public:
    static unsigned getCageSize(char const* size);
    static const unsigned DEFAULT_CAGE_SIZE = 0;// MUST be different from the other cage sizes

    Cage(char const* climate = nullptr, char const* size = nullptr);
    Cage(const Cage& other);
    Cage& operator=(const Cage& other);
    ~Cage();

    bool empty() const;// true if empty
    bool full() const;// true if full
    unsigned free() const;// returns the free left space

    bool canHandle(const Dinosaur& dinosaur);
    bool add(const Dinosaur& dinosaur);
    bool remove(const char* dinosaur_name);
    Dinosaur* find(const char* dinosaur_name) const;
    bool serialize(std::ofstream& ofs) const;
    bool unserialize(std::ifstream& ifs);

private:
    void clear();
    void copy(const Cage &other);
    void copy(char const* climate, const unsigned size, char const* era,
            const Dinosaur* list, const unsigned list_count);
};

#endif //JURASSICPARK_CAGE_HPP
