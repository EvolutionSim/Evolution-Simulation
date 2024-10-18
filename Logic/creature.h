

enum foodChoice{
    Herbivore = 0;
    Carnivore = 1;
    Omnivore = 3;
};


class Creature{
    public:
    
    int size;
    int speed;
    int vision;
    int health;
    int damage;
    float aggresive;
    float cooperative;
    float cowardly;
    foodChoice eats;

    Creature(int size_ = 0, int speed_ = 0; int vision_ = 0, int health_ = 0; int damage_ = 0, float aggresive_ = 0.0; float cooperative_ = 0.0, float cowardly_ = 0.0, char eats_ = 'H'){
        size = size_;
        speed = speed_;
        vision = vision_;
        health = health_;
        damage = damage_;
        aggresive = aggresive_;
        cooperative = cooperative_;
        cowardly = cowardly_;
        if (eats_ == 'H'){eats = Herbivore;}
        else if (eats == 'C'){eats = Carnivore;}
        else{eats = Omnivore;}
    }
}