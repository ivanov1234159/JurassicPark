//
// Created by toi on 27/03/2020.
//

#include <cstring>
//for: strcmp()
#include "Dinosaur.hpp"
#include "MySpace.hpp"

char const* Dinosaur::era[] = { "triassic", "cretaceous", "jurassic", nullptr };
char const* Dinosaur::type[] = { "carnivorous", "herbivorous", "aqueous", "flying", nullptr };
char const* Dinosaur::species[] = {
        //for next: https://www.activewild.com/list-of-dinosaurs-names-with-pictures/
        "abelisaurus",      // cretaceous period,           carnivorous ?   (meat) ?
        "albertosaurus",    // cretaceous period,           carnivorous     (meat)
        "allosaurus",       // jurassic period,             carnivorous     (meat)
        "ankylosaurus",     // cretaceous period,           herbivorous     (grass)
        "apatosaurus",      // jurassic period,             herbivorous     (grass)
        "archaeopteryx",    // jurassic period,             flying          (meat; insects, worms, lizards and mammals)
        "baryonyx",         // cretaceous period,           carnivorous     (fish)
        "giganotosaurus",   // cretaceous period,           carnivorous     (meat)
        "iguanodon",        // cretaceous period,           herbivorous     (grass)
        "megalosaurus",     // jurassic period,             carnivorous     (meat)
        "minmi",            // cretaceous period,           herbivorous     (grass)
        "protoceratops",    // cretaceous period,           herbivorous     (grass)
        "stegosaurus",      // jurassic period,             herbivorous     (grass)
        "triceratops",      // cretaceous period,           herbivorous     (grass)
        "tyrannosaurus",    // cretaceous period,           carnivorous     (meat)
        "velociraptor",     // cretaceous period,           carnivorous     (meat)
        //for next: https://en.wikipedia.org/wiki/List_of_pterosaur_genera
        "aerodactylus",     // jurassic period,             flying          (fish) ?
        "aerotitan",        // cretaceous period,           flying          (fish) ?
        "allkaruen",        // jurassic period,             flying          (fish) ?
        "arcticodactylus",  // triassic period,             flying          (fish) ?
        "austriadraco",     // triassic period,             flying          (fish) ?
        "bakonydraco",      // cretaceous period,           flying          (fish) ?
        //for next: https://www.activewild.com/triassic-dinosaurs/
        "alwalkeria",       // triassic period,             carnivorous     (meat) ?
        "asylosaurus",      // triassic period,             herbivorous     (grass)
        "gojirasaurus",     // triassic period,             carnivorous     (meat); whose name means ‘Godzilla Lizard’
        //for next: https://www.enchantedlearning.com/subjects/dinosaurs/questions/faq/Swimming.shtml
        "plesiosaurs",      // triassic / jurassic period,  aqueous         (fish) ?
        "nothosaurs",       // triassic period,             aqueous         (fish)
        //for next (only): https://www.enchantedlearning.com/subjects/dinosaurs/dinos/Kronosaurus.shtml
        "kronosaurus",      // cretaceous period,           aqueous         (meat)
        nullptr };
char const* Dinosaur::food[] = { "grass", "meat", "fish", nullptr };

Dinosaur::Dinosaur()
        : m_name(nullptr), m_gender(nullptr), m_era(nullptr)
        , m_type(nullptr), m_species(nullptr), m_food(nullptr) {}

/*Dinosaur::Dinosaur(char const *name, char const *gender, char const *era,
           char const *type, char const *species, char const *food)
        : m_name(nullptr), m_gender(nullptr), m_era(nullptr)
        , m_type(nullptr), m_species(nullptr), m_food(nullptr) {
    copy(name, gender, era, type, species, food);
}*/

Dinosaur::Dinosaur(Dinosaur const &other) {
    copy(other);
}

Dinosaur &Dinosaur::operator=(Dinosaur const &other) {
    if (this != &other) {
        //clear();
        copy(other);
    }
    return *this;
}

Dinosaur::~Dinosaur() {
    clear();
}

bool Dinosaur::setName(char const *name) {
    MySpace::mem_copy(m_name, name);
    return true;
}

bool Dinosaur::setGender(char const *gender) {
    if(gender != nullptr && !Dinosaur::validGender(gender)){
        return false;
    }
    MySpace::mem_copy(m_gender, gender);
    return true;
}

bool Dinosaur::setEra(char const *era) {
    if(era != nullptr && !Dinosaur::validEra(era)){
        return false;
    }
    MySpace::mem_copy(m_era, era);
    return true;
}

bool Dinosaur::setType(char const *type) {
    if(type != nullptr && !Dinosaur::validType(type)){
        return false;
    }
    MySpace::mem_copy(m_type, type);
    return true;
}

bool Dinosaur::setSpecies(char const *species) {
    if(species != nullptr && !Dinosaur::validSpecies(species)){
        return false;
    }
    MySpace::mem_copy(m_species, species);
    return true;
}

bool Dinosaur::setFood(char const *food) {
    if(food != nullptr && !Dinosaur::validFood(food)){
        return false;
    }
    MySpace::mem_copy(m_food, food);
    return true;
}

char const* Dinosaur::getName() const { return m_name; }
char const* Dinosaur::getGender() const { return m_gender; }
char const* Dinosaur::getEra() const { return m_era; }
char const* Dinosaur::getType() const { return m_type; }
char const* Dinosaur::getSpecies() const { return m_species; }
char const* Dinosaur::getFood() const { return m_food; }

bool Dinosaur::serialize(std::ofstream &ofs) const {
    return MySpace::serialize(ofs, m_name) && MySpace::serialize(ofs, m_gender) && MySpace::serialize(ofs, m_era)
        && MySpace::serialize(ofs, m_type) && MySpace::serialize(ofs, m_species) && MySpace::serialize(ofs, m_food);
}

void Dinosaur::clear(){
    setName(nullptr);
    setGender(nullptr);
    setEra(nullptr);
    setType(nullptr);
    setSpecies(nullptr);
    setFood(nullptr);
}

void Dinosaur::copy(Dinosaur const& other){
    copy(other.m_name, other.m_gender, other.m_era, other.m_type, other.m_species, other.m_food);
}

void Dinosaur::copy(char const* name, char const* gender, char const* era,
          char const* type, char const* species, char const* food){
    setName(name);
    setGender(gender);
    setEra(era);
    setType(type);
    setSpecies(species);
    setFood(food);
}

bool Dinosaur::validGender(char const* gender) {
    return std::strcmp(gender, "male") == 0 || std::strcmp(gender, "female") == 0;
}

bool Dinosaur::validEra(char const* _era) {
    return MySpace::array_find_str(Dinosaur::era, _era);
}

bool Dinosaur::validType(char const* _type) {
    return MySpace::array_find_str(Dinosaur::type, _type);
}

bool Dinosaur::validSpecies(char const* _species) {
    return MySpace::array_find_str(Dinosaur::species, _species);
}

bool Dinosaur::validFood(char const* _food) {
    return MySpace::array_find_str(Dinosaur::food, _food);
}
