#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <random>
#include <ctime>

class Game{
    private:

        sf::RenderWindow *window;
        sf::VideoMode vMode;
        sf::Event ev;

        static const int height = 800, width = 800;
        static const int res = 10;
        static const int col = height/res, row = width/res;;

        std::vector<sf::RectangleShape> rects;

        int ind = 0;
        int R = 255, G = 255, B = 255;

        int cGrid[row][col];
        int nGrid[row][col];

        sf::Vector2i mPos;
        sf::Vector2f mPosView;
        bool mouseClicked, rightClicked;

        //private functions
        void initVar();
        void initWindow();
        void initRect();

    public:
        //CONTRUCTOR AND DESTRUCTOR
        Game();
        virtual ~Game();

        //Fuctions
        bool getWinIsOpen();
        void update();
        void resetNext();
        void setNext();
        void check();
        void render();
};