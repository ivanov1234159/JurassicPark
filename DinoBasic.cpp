//
// Created by toi on 13/05/2020.
//

#include "DinoBasic.hpp"
#include "MySpace.hpp"

char const* DinoBasic::era[] = { "triassic", "cretaceous", "jurassic", nullptr };
char const* DinoBasic::species[] = {
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

bool DinoBasic::setEra(String const &era){
    if(!DinoBasic::validEra(era)){
        return false;
    }
    m_era = era;
    return true;
}

bool DinoBasic::setSpecies(String const &species){
    if(!DinoBasic::validSpecies(species)){
        return false;
    }
    m_species == species;
    return true;
}

String const& DinoBasic::getEra() const {
    return m_era;
}

String const& DinoBasic::getSpecies() const {
    return m_species;
}

bool DinoBasic::validEra(String const& _era) {
    return MySpace::array_find_str(DinoBasic::era, _era.get());
}

bool DinoBasic::validSpecies(String const& _species) {
    return MySpace::array_find_str(DinoBasic::species, _species.get());
}