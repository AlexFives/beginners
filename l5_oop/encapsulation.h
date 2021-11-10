#pragma once

class Hero {
    // these are private attributes
    float hp, max_hp;

public:
    Hero(float max_hp) : max_hp(max_hp) {
        hp = max_hp;
    }

    // encapsulation:
    float getMaxHP() { return max_hp; } // getter: this method returns some hidden attribute
    float getHP() { return hp; } // this is getter too

    void setMaxHP(float set_to) {
        // setter: this method sets a value for a hidden attribute
        // we can give some rules for it
        if (set_to < 0) set_to = 0; // the 1st rule
        // we can do something else: now we are implementing proportional ratio hp and max_hp
        float hp_percent = hp / max_hp;
        max_hp = set_to;
        hp = max_hp * hp_percent;
    }
};