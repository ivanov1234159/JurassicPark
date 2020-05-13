//
// Created by toi on 13/05/2020.
//

#include "DinoFoodType.hpp"
#include "MySpace.hpp"

char const* DinoFoodType::type[] = { "carnivorous", "herbivorous", "aqueous", "flying", nullptr };
char const* DinoFoodType::food[] = { "grass", "meat", "fish", nullptr };

bool DinoFoodType::setType(String const &type) {
    if(!DinoFoodType::validType(type)){
        return false;
    }
    m_type = type;
    return true;
}

bool DinoFoodType::setFood(String const &food) {
    if(!DinoFoodType::validFood(food)){
        return false;
    }
    m_food == food;
    return true;
}

String const& DinoFoodType::getType() const {
    return m_type;
}

String const& DinoFoodType::getFood() const {
    return m_food;
}

bool DinoFoodType::validType(String const& _type) {
    return MySpace::array_find_str(DinoFoodType::type, _type.get());
}

bool DinoFoodType::validFood(String const& _food) {
    return MySpace::array_find_str(DinoFoodType::food, _food.get());
}