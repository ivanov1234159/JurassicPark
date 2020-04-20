//
// Created by toi on 25/03/2020.
//

#ifndef JURASSICPARK_DINOSAUROLD_HPP
#define JURASSICPARK_DINOSAUROLD_HPP

enum class DinosaurGender {
    MALE,
    FEMALE
};

enum class DinosaurEra {
    UNKNOWN = -1,
    TRIASSIC,
    CRETACEOUS,
    JURASSIC,
    _COUNT
};

enum class DinosaurType {
    UNKNOWN = -1,
    CARNIVOROUS,
    HERBIVOROUS,
    AQUEOUS,
    FLYING,
    _COUNT
};

//url: https://www.activewild.com/list-of-dinosaurs-names-with-pictures/
//and: https://en.wikipedia.org/wiki/List_of_pterosaur_genera (only for flying)
//and: https://www.activewild.com/triassic-dinosaurs/ (only for triassic period)
//and: https://www.enchantedlearning.com/subjects/dinosaurs/questions/faq/Swimming.shtml (only for swimming; NOT dinosaur)
enum class DinosaurSpecies {
    UNKNOWN = -1,
    Abelisaurus,    // CRETACEOUS Period,           CARNIVOROUS ?   (MEAT) ?
    Albertosaurus,  // CRETACEOUS Period,           CARNIVOROUS     (MEAT)
    Allosaurus,     // JURASSIC Period,             CARNIVOROUS     (MEAT)
    Ankylosaurus,   // CRETACEOUS Period,           HERBIVOROUS     (GRASS)
    Apatosaurus,    // JURASSIC Period,             HERBIVOROUS     (GRASS)
    Archaeopteryx,  // JURASSIC Period,             FLYING          (MEAT; insects, worms, lizards and mammals)
    Baryonyx,       // CRETACEOUS Period,           CARNIVOROUS     (FISH)
    Giganotosaurus, // CRETACEOUS Period,           CARNIVOROUS     (MEAT)
    Iguanodon,      // CRETACEOUS Period,           HERBIVOROUS     (GRASS)
    Megalosaurus,   // JURASSIC Period,             CARNIVOROUS     (MEAT)
    Minmi,          // CRETACEOUS Period,           HERBIVOROUS     (GRASS)
    Protoceratops,  // CRETACEOUS Period,           HERBIVOROUS     (GRASS)
    Stegosaurus,    // JURASSIC Period,             HERBIVOROUS     (GRASS)
    Triceratops,    // CRETACEOUS Period,           HERBIVOROUS     (GRASS)
    Tyrannosaurus,  // CRETACEOUS Period,           CARNIVOROUS     (MEAT)
    Velociraptor,   // CRETACEOUS Period,           CARNIVOROUS     (MEAT)

    Aerodactylus,   // JURASSIC Period,             FLYING          (FISH) ?
    Aerotitan,      // CRETACEOUS Period,           FLYING          (FISH) ?
    Allkaruen,      // JURASSIC Period,             FLYING          (FISH) ?
    Arcticodactylus,// TRIASSIC Period,             FLYING          (FISH) ?
    Austriadraco,   // TRIASSIC Period,             FLYING          (FISH) ?
    Bakonydraco,    // CRETACEOUS Period,           FLYING          (FISH) ?

    Alwalkeria,     // TRIASSIC Period,             CARNIVOROUS     (MEAT) ?
    Asylosaurus,    // TRIASSIC Period,             HERBIVOROUS     (GRASS)
    Gojirasaurus,   // TRIASSIC Period,             CARNIVOROUS     (MEAT); whose name means ‘Godzilla Lizard’

    Plesiosaurs,    // TRIASSIC / JURASSIC Period,  AQUEOUS         (FISH) ?
    Nothosaurs,     // TRIASSIC Period,             AQUEOUS         (FISH)
    Kronosaurus,    // CRETACEOUS Period,           AQUEOUS         (MEAT); https://www.enchantedlearning.com/subjects/dinosaurs/dinos/Kronosaurus.shtml
    _COUNT
};

enum class DinosaurFood {
    UNKNOWN = -1,
    GRASS,
    MEAT,
    FISH,
    _COUNT
};

class DinosaurOld {
    char *m_name;
    DinosaurGender m_gender;
    DinosaurEra m_era;
    DinosaurType m_type;
    DinosaurSpecies m_species;
    DinosaurFood m_food;
public:
    DinosaurOld(const char *name = "N/A", const DinosaurGender gender = DinosaurGender::MALE,
             const DinosaurEra era = DinosaurEra::UNKNOWN, const DinosaurType type = DinosaurType::UNKNOWN,
             const DinosaurSpecies species = DinosaurSpecies::UNKNOWN, const DinosaurFood food = DinosaurFood::UNKNOWN);
    DinosaurOld(const DinosaurOld &other);
    DinosaurOld& operator=(const DinosaurOld &other);
    ~DinosaurOld();

    void setGender(const DinosaurGender gender);
    void setEra(const DinosaurEra era);
    void setType(const DinosaurType type);
    void setSpecies(const DinosaurSpecies species);
    void setFood(const DinosaurFood food);

    void getName(char*& name) const;
    DinosaurEra getEra() const;
    DinosaurType getType() const;

private:
    void clear();
    void copy(const DinosaurOld &other);
    void copy(const char *name, const DinosaurGender gender, const DinosaurEra era,
              const DinosaurType type, const DinosaurSpecies species, const DinosaurFood food);
};

#endif //JURASSICPARK_DINOSAUROLD_HPP

//====================================== [ Cage.hpp ] ======================================
//
// Created by toi on 25/03/2020.
//

//#ifndef JURASSICPARK_CAGE_HPP
//#define JURASSICPARK_CAGE_HPP

//#include "Dinosaur.hpp"
/*
enum class CageClimate {
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
};

class Cage {
    CageClimate m_climate;
    CageSize m_size;// list limit
    DinosaurEra m_era;// if any dinosaur; all dinosaurs MUST be (and are) from one era
    Dinosaur* m_list;
    unsigned m_list_count;// list count

    static unsigned getCageSize(const CageSize size);
public:
    Cage(const CageClimate climate = CageClimate::UNKNOWN, const CageSize size = CageSize::SMALL);
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

private:
    void setEra(const DinosaurEra era);
    void clear();
    void copy(const Cage &other);
    void copy(const CageClimate climate, const CageSize size, const DinosaurEra era,
              const Dinosaur* list, const unsigned list_count);
};
*/
//#endif //JURASSICPARK_CAGE_HPP
