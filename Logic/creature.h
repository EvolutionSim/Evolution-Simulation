
enum foodChoice{
    Herbivore = 0;
    Carnivore = 1;
    Omnivore = 3;
};


struct Creature{
    public:
    
    int size_;
    int speed_;
    int vision_;
    int health_;
    int damage_;
    float aggresive_;
    float cooperative_;
    float cowardly_;
    foodChoice eats_;

    Creature(int size = 0, int speed = 0; int vision = 0, int health = 0; int damage = 0, float aggresive = 0.0; float cooperative = 0.0, float cowardly = 0.0, char eats = 'H'){
        size_ = size;
        speed_ = speed;
        vision_ = vision;
        health_ = health;
        damage_ = damage;
        aggresive_ = aggresive;
        cooperative_ = cooperative;
        cowardly_ = cowardly;
        if (eats == 'H'){eats_ = Herbivore;}
        else if (eats == 'C'){eats_ = Carnivore;}
        else{eats_ = Omnivore;}
    }
}



