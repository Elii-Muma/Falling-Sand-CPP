#include "FallingSand.hpp"

void Game::initVar(){
    
    this->window = NULL;
    this->mouseClicked = false;

}

void Game::initWindow(){

    this->vMode.height = height;
    this->vMode.width = width;

    this->window = new sf::RenderWindow(vMode, "First Game", sf::Style::Titlebar | sf::Style::Close);
    this->window->setFramerateLimit(60);
}

Game::Game(){ 

    initVar();
    initWindow();


    for (int i=0; i<row; i++) {
        for (int j=0; j<col; j++) {
            cGrid[i][j] = 0;
            nGrid[i][j] = 0;

            if(ind%50){
                R = rand()%255;
                G = rand()%255;
                B = rand()%255;
            }

            sf::RectangleShape r;
            r.setSize(sf::Vector2f(res, res));
            r.setFillColor(sf::Color::White);

            rects.push_back(r);
            ind++;

        }
    }

}

Game::~Game(){
    delete window;
}

bool Game::getWinIsOpen(){
    return window->isOpen();
}


void Game::update(){

    //loop

    //poll events

    while(window->pollEvent(ev)){        
        if(ev.type == ev.Closed){
            window->close();
        }

        switch(ev.type){
            case sf::Event::MouseButtonPressed:
                    switch (ev.mouseButton.button)    
                    {
                    case sf::Mouse::Left:
                        mouseClicked = true;
                        std::cout<<"clicked\n";
                        break;
                    case sf::Mouse::Right:
                        rightClicked = true;
                        break;
                    default:
                        break;
                    }
                break;
            case sf::Event::MouseButtonReleased:
                if(ev.mouseButton.button == sf::Mouse::Left){
                    mouseClicked = false;
                    std::cout<<"released\n";
                }
                if(ev.mouseButton.button == sf::Mouse::Right){
                    rightClicked = false;
                }
            default:
                break;
        }
    }

    if(mouseClicked){


        int r = sf::Mouse::getPosition(*window).x/res;
        int c = sf::Mouse::getPosition(*window).y/res;
        if(r >= 0 && r < row && c < col && c >= 0){
            cGrid[r][c] = 1;
        }
    }

    check();

}

void Game::resetNext(){
    for(int i=0; i<row - 1; i++){
        for(int j=0; j<col - 1; j++){
            nGrid[i][j] = 0;        
        }
    }
}

void Game::setNext(){
    for(int i=0; i<row - 1; i++){
        for(int j=0; j<col - 1; j++){
            cGrid[i][j] = nGrid[i][j];        
        }
    }
}


void Game::check(){

    //reset the next grid to have all 0's
    resetNext();

    //check the position of current block and see where it can move
    for(int i=0; i<row - 1; i++){
        for(int j=0; j<col - 1; j++){
            if(cGrid[i][j] == 1){
                int below = (j+1 < col-1) ? cGrid[i][j+1] : -1;

                int belowR = (below == 1 && i+1 < row-1) ? cGrid[i+1][j+1] : -1;
                int belowL = (below == 1 && i > 0) ? cGrid[i-1][j+1] : -1;

                if(below == 0){
                    nGrid[i][j+1] = cGrid[i][j];
                    int index = i*col + j;
                    rects[index].setFillColor(sf::Color(R, G, B));
                }else if(belowR == 0 && belowL == 0){
                    int r = rand()%2;

                    if(r == 1){
                        nGrid[i+1][j+1] = cGrid[i][j];

                    }else{
                        nGrid[i-1][j+1] = cGrid[i][j];

                    }

                }else if(belowR == 0){
                    nGrid[i+1][j+1] = cGrid[i][j];
                }else if(belowL == 0){
                    nGrid[i-1][j+1] = cGrid[i][j];
                }else{
                    nGrid[i][j] = cGrid[i][j];
                }

            }


        }
    }

    //we update the current grid to the updated next grid
    setNext();

}

void Game::render(){

    //clear
    window->clear(sf::Color(0, 0, 0));

    //draw
    for(int i=0; i<row; i++){
        for(int j=0; j<col; j++){
            //currentRow*numOfCols + currentCol
            int index = i*col + j;

            if(rightClicked){
                printf("changing color");
                R = rand()%255;
                G = rand()%255;
                B = rand()%255;
                rightClicked = false;
            }
            
            if(cGrid[i][j] > 0){
                // sf::RectangleShape rect;
                // rect.setSize(sf::Vector2f(res, res));
                // rect.setPosition(sf::Vector2f(i*res, j*res));
                // rect.setFillColor(sf::Color(sf::Color::White));

                rects[index].setPosition(i*res, j*res);
                window->draw(rects[index]);
            }
            
            //cGrid[i][j] = nGrid[i][j];

        }
    }

    //display
    window->display();
    }